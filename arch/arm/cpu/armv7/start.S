/*
 * armboot - Startup Code for OMAP3530/ARM Cortex CPU-core
 *
 * Copyright (c) 2004	Texas Instruments <r-woodruff2@ti.com>
 *
 * Copyright (c) 2001	Marius Gröger <mag@sysgo.de>
 * Copyright (c) 2002	Alex Züpke <azu@sysgo.de>
 * Copyright (c) 2002	Gary Jennejohn <garyj@denx.de>
 * Copyright (c) 2003	Richard Woodruff <r-woodruff2@ti.com>
 * Copyright (c) 2003	Kshitij <kshitij@ti.com>
 * Copyright (c) 2006-2008 Syed Mohammed Khasim <x0khasim@ti.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm-offsets.h>
#include <config.h>
#include <asm/system.h>
#include <linux/linkage.h>
#include <asm/armv7.h>


/*************************************************************************
 *
 * Startup Code (reset vector)
 *
 * Do important init only if we don't start from memory!
 * Setup memory and board specific bits prior to relocation.
 * Relocate armboot to ram. Setup stack.
 *
 *************************************************************************/

	.globl	reset
	.globl	save_boot_params_ret
#ifdef CONFIG_ARMV7_LPAE
	.global	switch_to_hypervisor_ret
#endif

reset:

	/* Allow the board to save important registers */
    ldr sp, =0xd0036000
	b	save_boot_params
	
save_boot_params_ret:

	/*
	 * disable interrupts (FIQ and IRQ), also set the cpu to SVC32 mode,
	 * except if in HYP mode already
	 */
	mrs	r0, cpsr
	and	r1, r0, #0x1f		@ mask mode bits
	teq	r1, #0x1a		@ test for HYP mode
	bicne	r0, r0, #0x1f		@ clear all mode bits
	orrne	r0, r0, #0x13		@ set SVC mode
	orr	r0, r0, #0xc0		@ disable FIQ and IRQ
	msr	cpsr,r0






/*
 * Setup vector:
 * (OMAP4 spl TEXT_BASE is not 32 byte aligned.
 * Continue to use ROM code vector only in OMAP4 spl)
 */
#if !(defined(CONFIG_OMAP44XX) && defined(CONFIG_SPL_BUILD))
	/* Set V=0 in CP15 SCTLR register - for VBAR to point to vector */
	mrc	p15, 0, r0, c1, c0, 0	@ Read CP15 SCTLR Register
	bic	r0, #CR_V		@ V = 0
	mcr	p15, 0, r0, c1, c0, 0	@ Write CP15 SCTLR Register

	/* Set vector address in CP15 VBAR register */
	ldr	r0, =_start
	mcr	p15, 0, r0, c12, c0, 0	@Set VBAR
#endif

	/* the mask ROM code should have PLL and others stable */
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
	bl	cpu_init_cp15
#ifndef CONFIG_SKIP_LOWLEVEL_INIT_ONLY
	bl	cpu_init_crit     /*lowlevel_init 已经初始化了内存了*/
#endif
#endif


    /*
            因为要调用c语言，最好还是设置好堆栈
            堆栈设置在uboot代码段的起始位置，因为堆栈向下增长，所以不会影响uboot代码段
         */
    ldr sp, =CONFIG_SYS_TEXT_BASE   /* setup temp stack pointer */
    sub sp, sp, #0x2000
    mov fp, #0          /* no previous frame, so fp=0 */


led_init:    //led 初始化    2020-12-16
    ldr r0,=0xe0200280
    ldr r1,=0x1111
    str r1,[r0] 


	/*******************2020**************************************/
	/* Read booting information  获得启动信息，看是如何启动的 */
	ldr	r0, =PRO_ID_BASE
	ldr	r1, [r0,#OMR_OFFSET]
	bic	r2, r1, #0xffffffc1

	/* NAND BOOT */
	cmp	r2, #0x0		@ 512B 4-cycle
	moveq	r3, #BOOT_NAND

	cmp	r2, #0x2		@ 2KB 5-cycle
	moveq	r3, #BOOT_NAND

	cmp	r2, #0x4		@ 4KB 5-cycle	8-bit ECC
	moveq	r3, #BOOT_NAND

	cmp	r2, #0x6		@ 4KB 5-cycle	16-bit ECC
	moveq	r3, #BOOT_NAND

	/* SD/MMC BOOT */
	cmp     r2, #0xc
	moveq   r3, #BOOT_MMCSD	

	/* Uart BOOTONG failed */
	cmp     r2, #(0x1<<4)
	moveq   r3, #BOOT_SEC_DEV
	
	ldr	r0, =INF_REG_BASE
	str	r3, [r0, #INF_REG3_OFFSET]    /*把启动信息保存起来*/ 


	/* when we already run in ram, we don't need to relocate U-Boot.
	 * and actually, memory controller must be configured before U-Boot
	 * is running in ram.
	 */
	ldr	r0, =0xff000fff
	bic	r1, pc, r0		/* r0 <- current base addr of code */
	ldr	r2, =CONFIG_SYS_TEXT_BASE		/* r1 <- original base addr in ram */
	bic	r2, r2, r0		/* r0 <- current base addr of code */
	cmp     r1, r2                  /* compare r0, r1                  */
	beq     after_copy		/* r0 == r1 then skip flash copy   */



	/* @ldr	r0, =INF_REG_BASE
	 @ldr	r1, [r0, #INF_REG3_OFFSET]
	*/
	mov  r1,r3   @r3中保存着启动信息，直接判断吧
	cmp	r1, #BOOT_NAND		/* 0x0 => boot device is nand */
	beq	nand_boot

	cmp     r1, #BOOT_MMCSD
	beq     mmcsd_boot

	cmp     r1, #BOOT_SEC_DEV
	beq     mmcsd_boot

nand_boot:
	mov	r0, #0x1000
	bl	copy_from_nand

    ldr	pc, _start_armboot
    
mmcsd_boot:
	bl      mmc_relocate
    /* Print 'h' */
	ldr	r0, =0xe2900020
	ldr	r1, =0x4a                       //h
	strb r1, [r0]
	ldr	pc, _start_armboot

_start_armboot:
	.word after_copy




after_copy:     @//设置标志

	/*******************2020**************************************/
#if 0
	/* ABB disable */
	ldr	r0, =0xE010C300
	orr	r1, r1, #(0x1<<23)
	str	r1, [r0]
#endif
	/* Print 'K' */
	ldr	r0, =0xe2900020
	ldr	r1, =0x4b
	strb r1, [r0]


	bl	_main

/*------------------------------------------------------------------------------*/

ENTRY(c_runtime_cpu_setup)
/*
 * If I-cache is enabled invalidate it
 */
#ifndef CONFIG_SYS_ICACHE_OFF
	mcr	p15, 0, r0, c7, c5, 0	@ invalidate icache
	mcr     p15, 0, r0, c7, c10, 4	@ DSB
	mcr     p15, 0, r0, c7, c5, 4	@ ISB
#endif

	bx	lr

ENDPROC(c_runtime_cpu_setup)

/*************************************************************************
 *
 * void save_boot_params(u32 r0, u32 r1, u32 r2, u32 r3)
 *	__attribute__((weak));
 *
 * Stack pointer is not yet initialized at this moment
 * Don't save anything to stack even if compiled with -O0
 *
 *************************************************************************/
ENTRY(save_boot_params)
	b	save_boot_params_ret		@ back to my caller
ENDPROC(save_boot_params)
	.weak	save_boot_params

#ifdef CONFIG_ARMV7_LPAE
ENTRY(switch_to_hypervisor)
	b	switch_to_hypervisor_ret
ENDPROC(switch_to_hypervisor)
	.weak	switch_to_hypervisor
#endif

/*************************************************************************
 *
 * cpu_init_cp15
 *
 * Setup CP15 registers (cache, MMU, TLBs). The I-cache is turned on unless
 * CONFIG_SYS_ICACHE_OFF is defined.
 *
 *************************************************************************/
ENTRY(cpu_init_cp15)
	/*
	 * Invalidate L1 I/D
	 */
	mov	r0, #0			@ set up for MCR
	mcr	p15, 0, r0, c8, c7, 0	@ invalidate TLBs
	mcr	p15, 0, r0, c7, c5, 0	@ invalidate icache
	mcr	p15, 0, r0, c7, c5, 6	@ invalidate BP array
	mcr     p15, 0, r0, c7, c10, 4	@ DSB
	mcr     p15, 0, r0, c7, c5, 4	@ ISB

	/*
	 * disable MMU stuff and caches
	 */
	mrc	p15, 0, r0, c1, c0, 0
	bic	r0, r0, #0x00002000	@ clear bits 13 (--V-)
	bic	r0, r0, #0x00000007	@ clear bits 2:0 (-CAM)
	orr	r0, r0, #0x00000002	@ set bit 1 (--A-) Align
	orr	r0, r0, #0x00000800	@ set bit 11 (Z---) BTB
#ifdef CONFIG_SYS_ICACHE_OFF
//	bic	r0, r0, #0x00001000	@ clear bit 12 (I) I-cache
#else
	orr	r0, r0, #0x00001000	@ set bit 12 (I) I-cache
#endif
	mcr	p15, 0, r0, c1, c0, 0


	mov	r5, lr			@ Store my Caller
	mrc	p15, 0, r1, c0, c0, 0	@ r1 has Read Main ID Register (MIDR)
	mov	r3, r1, lsr #20		@ get variant field
	and	r3, r3, #0xf		@ r3 has CPU variant
	and	r4, r1, #0xf		@ r4 has CPU revision
	mov	r2, r3, lsl #4		@ shift variant field for combined value
	orr	r2, r4, r2		@ r2 has combined CPU variant + revision


	mov	pc, r5			@ back to my caller
ENDPROC(cpu_init_cp15)

#if !defined(CONFIG_SKIP_LOWLEVEL_INIT) && \
	!defined(CONFIG_SKIP_LOWLEVEL_INIT_ONLY)
/*************************************************************************
 *
 * CPU_init_critical registers
 *
 * setup important registers
 * setup memory timing
 *
 *************************************************************************/
ENTRY(cpu_init_crit)
	/*
	 * Jump to board specific initialization...
	 * The Mask ROM will have already initialized
	 * basic memory. Go here to bump up clock rate and handle
	 * wake up conditions.
	 */
	b	lowlevel_init		@ go setup pll,mux,memory
ENDPROC(cpu_init_crit)
#endif



/*
 * copy U-Boot to SDRAM and jump to ram (from NAND or OneNAND)
 * r0: size to be compared
 * Load 1'st 2blocks to RAM because U-boot's size is larger than 1block(128k) size
 */
	.globl copy_from_nand
copy_from_nand:
	push	{lr}		/* save return address */

	mov	r9, r0
    
	mov	r9, #0x100		/* Compare about 8KB */
    bl	copy_uboot_to_ram   
	tst 	r0, #0x0
	bne	copy_failed

    bl led1_off

	ldr	r0, =0xd0020000
	ldr	r1, =CONFIG_SYS_TEXT_BASE	/* 0x34800000 */

#if !defined(CONFIG_SECURE_BOOT)
1:	ldr	r3, [r0], #4
	ldr	r4, [r1], #4
	teq	r3, r4
	bne	compare_failed	/* not matched */
	subs	r9, r9, #4
	bne	1b
#endif
	pop	{pc}		/* all is OK */

copy_failed:
	nop			/* copy from nand failed */    
	b	copy_failed

compare_failed:    
	nop			/* compare failed */
	b	compare_failed




.global led1_on
led1_on:
    stmfd sp!,{r11,r12,lr}
    ldr r11,=0xe0200284
    ldrb r12,[r11]
    bic r12,#0x1
    strb r12,[r11]
    ldmfd sp!,{r11,r12,pc}
.global led1_off
led1_off:
    stmfd sp!,{r11,r12,lr}
    ldr r11,=0xe0200284
    ldrb r12,[r11]
    orr r12,#0x1
    strb r12,[r11]
    ldmfd sp!,{r11,r12,pc}
.global led2_off
.global led3_off
.global led4_off

led2_off:
    stmfd sp!,{r11,r12,lr}
    ldr r11,=0xe0200284
    ldrb r12,[r11]
    orr r12,#0x2
    strb r12,[r11]
    ldmfd sp!,{r11,r12,pc}



led3_off:
    stmfd sp!,{r11,r12,lr}
    ldr r11,=0xe0200284
    ldrb r12,[r11]
    orr r12,#0x4
    strb r12,[r11]
    ldmfd sp!,{r11,r12,pc}

led4_off:
    stmfd sp!,{r11,r12,lr}
    ldr r11,=0xe0200284
    ldrb r12,[r11]
    orr r12,#0x8
    strb r12,[r11]
    ldmfd sp!,{r11,r12,pc}


