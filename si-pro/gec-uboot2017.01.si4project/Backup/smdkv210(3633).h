/*
 * Copyright (C) 2009 Samsung Electronics
 * Minkyu Kang <mk7.kang@samsung.com>
 * Kyungmin Park <kyungmin.park@samsung.com>
 *
 * Configuation settings for the SAMSUNG Universal (s5pc100) board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* High Level Configuration Options */
#define CONFIG_SAMSUNG		1	/* in a SAMSUNG core */
#define CONFIG_S5P		1	/* which is in a S5P Family */
#define CONFIG_S5PC110		1	/* which is in a S5PC110 */
#define CONFIG_MACH_GONI	1	/* working with Goni */

#include <linux/sizes.h>
#include <asm/arch/cpu.h>		/* get chip and board defs */

#define CONFIG_ARCH_CPU_INIT

#define DEBUG

/* input clock of PLL: has 24MHz input clock at S5PC110 */
#define CONFIG_SYS_CLK_FREQ_C110	24000000

/* DRAM Base */
#define CONFIG_SYS_SDRAM_BASE		0x30000000

/* Text Base */
#define CONFIG_SYS_TEXT_BASE		0x34800000

#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_REVISION_TAG
#define CONFIG_INITRD_TAG
#define CONFIG_CMDLINE_EDITING

/* Size of malloc() pool before and after relocation */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (80 << 20))


/*#define BOOT_ONENAND		0x1*/
#define BOOT_NAND		0x2
#define BOOT_MMCSD		0x3
#define BOOT_NOR		0x4
#define BOOT_SEC_DEV		0x5
#define OMR_OFFSET			0x04
#define INF_REG3_OFFSET			0x0c
#define PRO_ID_BASE			0xE0000000
#define INF_REG_BASE			0xE010F000


#define CFG_PHY_UBOOT_BASE	CONFIG_SYS_TEXT_BASE
/* /#define CFG_PHY_KERNEL_BASE	MEMORY_BASE_ADDRESS + 0x8000
*/
#define CFG_ENV_OFFSET		0x0007C000

/* nand copy size from nand to DRAM.*/
#define	COPY_BL2_SIZE		0x80000

#define CONFIG_SYS_NAND_ECCSIZE           64
#define CONFIG_SYS_NAND_ECCBYTES     8

#ifdef CONFIG_CMD_NET
#define CONFIG_DRIVER_DM9000                  /* 使用dm9000驱动 */
#define CONFIG_ENV_SROM_BANK 1        /* 使用srom的bank1 */
 
#define CONFIG_DM9000_BASE  0x88000000        
#define DM9000_IO           CONFIG_DM9000_BASE
#define DM9000_DATA         (CONFIG_DM9000_BASE + 4)
#define CONFIG_DM9000_USE_16BIT  1
#endif


#define CONFIG_ETHADDR  00:19:D3:22:66:99




/* NAND configuration */
#define CFG_MAX_NAND_DEVICE     1
#define CFG_NAND_BASE           (0xE7200000)
#define NAND_MAX_CHIPS          1



/*
 * Nand flash controller
 */
#define ELFIN_NAND_BASE			0xB0E00000
#define ELFIN_NAND_ECC_BASE		0xB0E20000

#define NFCONF_OFFSET           	0x00
#define NFCONT_OFFSET           	0x04
#define NFCMMD_OFFSET           	0x08
#define NFADDR_OFFSET           	0x0c
#define NFDATA_OFFSET			0x10
#define NFMECCDATA0_OFFSET      	0x14
#define NFMECCDATA1_OFFSET      	0x18
#define NFSECCDATA0_OFFSET      	0x1c
#define NFSBLK_OFFSET           	0x20
#define NFEBLK_OFFSET           	0x24
#define NFSTAT_OFFSET           	0x28
#define NFESTAT0_OFFSET         	0x2c
#define NFESTAT1_OFFSET         	0x30
#define NFMECC0_OFFSET          	0x34
#define NFMECC1_OFFSET          	0x38
#define NFSECC_OFFSET           	0x3c
#define NFMLCBITPT_OFFSET       	0x40
#define NFECCCONF_OFFSET 		0x000 // R/W ECC configuration register 0x0000_0000
#define NFECCCONT_OFFSET 		0x020 // R/W ECC control register 0x0000_0000
#define NFECCSTAT_OFFSET 		0x030 // R ECC status register 0x0000_0000
#define NFECCSECSTAT_OFFSET 		0x040 // R ECC sector status register 0x0000_0000
#define NFECCPRGECC0_OFFSET 		0x090 // R ECC parity code0 register for page program 0x0000_0000
#define NFECCPRGECC1_OFFSET 		0x094 // R ECC parity code1 register for page program 0x0000_0000
#define NFECCPRGECC2_OFFSET 		0x098 // R ECC parity code2 register for page program 0x0000_0000
#define NFECCPRGECC3_OFFSET 		0x09C // R ECC parity code3 register for page program 0x0000_0000
#define NFECCPRGECC4_OFFSET 		0x0A0 // R ECC parity code4 register for page program 0x0000_0000
#define NFECCPRGECC5_OFFSET 		0x0A4 // R ECC parity code5 register for page program 0x0000_0000
#define NFECCPRGECC6_OFFSET 		0x0A8 // R ECC parity code6 register for page program 0x0000_0000
#define NFECCERL0_OFFSET		0x0C0 // R ECC error byte location0 register 0x0000_0000
#define NFECCERL1_OFFSET		0x0C4 // R ECC error byte location1 register 0x0000_0000
#define NFECCERL2_OFFSET		0x0C8 // R ECC error byte location2 register 0x0000_0000
#define NFECCERL3_OFFSET 		0x0CC // R ECC error byte location3 register 0x0000_0000
#define NFECCERL4_OFFSET 		0x0D0 // R ECC error byte location4 register 0x0000_0000
#define NFECCERL5_OFFSET 		0x0D4 // R ECC error byte location5 register 0x0000_0000
#define NFECCERL6_OFFSET 		0x0D8 // R ECC error byte location6 register 0x0000_0000
#define NFECCERL7_OFFSET 		0x0DC // R ECC error byte location7 register 0x0000_0000
#define NFECCERP0_OFFSET 		0x0F0 // R ECC error bit pattern0 register 0x0000_0000
#define NFECCERP1_OFFSET 		0x0F4 // R ECC error bit pattern1 register 0x0000_0000
#define NFECCERP2_OFFSET 		0x0F8 // R ECC error bit pattern2 register 0x0000_0000
#define NFECCERP3_OFFSET 		0x0FC // R ECC error bit pattern3 register 0x0000_0000
#define NFECCCONECC0_OFFSET 		0x110 // R/W ECC parity conversion code0 register 0x0000_0000
#define NFECCCONECC1_OFFSET 		0x114 // R/W ECC parity conversion code1 register 0x0000_0000
#define NFECCCONECC2_OFFSET 		0x118 // R/W ECC parity conversion code2 register 0x0000_0000
#define NFECCCONECC3_OFFSET 		0x11C // R/W ECC parity conversion code3 register 0x0000_0000
#define NFECCCONECC4_OFFSET 		0x120 // R/W ECC parity conversion code4 register 0x0000_0000
#define NFECCCONECC5_OFFSET 		0x124 // R/W ECC parity conversion code5 register 0x0000_0000
#define NFECCCONECC6_OFFSET		0x128 // R/W ECC parity conversion code6 register 0x0000_0000

#define NFCONF				(ELFIN_NAND_BASE+NFCONF_OFFSET)
#define NFCONT				(ELFIN_NAND_BASE+NFCONT_OFFSET)
#define NFCMMD				(ELFIN_NAND_BASE+NFCMMD_OFFSET)
#define NFADDR           		(ELFIN_NAND_BASE+NFADDR_OFFSET)
#define NFDATA          		(ELFIN_NAND_BASE+NFDATA_OFFSET)
#define NFMECCDATA0     		(ELFIN_NAND_BASE+NFMECCDATA0_OFFSET)
#define NFMECCDATA1     		(ELFIN_NAND_BASE+NFMECCDATA1_OFFSET)
#define NFSECCDATA0      		(ELFIN_NAND_BASE+NFSECCDATA0_OFFSET)
#define NFSBLK          		(ELFIN_NAND_BASE+NFSBLK_OFFSET)
#define NFEBLK           		(ELFIN_NAND_BASE+NFEBLK_OFFSET)
#define NFSTAT           		(ELFIN_NAND_BASE+NFSTAT_OFFSET)
#define NFESTAT0         		(ELFIN_NAND_BASE+NFESTAT0_OFFSET)
#define NFESTAT1         		(ELFIN_NAND_BASE+NFESTAT1_OFFSET)
#define NFMECC0          		(ELFIN_NAND_BASE+NFMECC0_OFFSET)
#define NFMECC1          		(ELFIN_NAND_BASE+NFMECC1_OFFSET)
#define NFSECC           		(ELFIN_NAND_BASE+NFSECC_OFFSET)
#define NFMLCBITPT           		(ELFIN_NAND_BASE+NFMLCBITPT_OFFSET)

#define NFECCCONF			(ELFIN_NAND_ECC_BASE+NFECCCONF_OFFSET)
#define NFECCCONT			(ELFIN_NAND_ECC_BASE+NFECCCONT_OFFSET)
#define NFECCSTAT			(ELFIN_NAND_ECC_BASE+NFECCSTAT_OFFSET)
#define NFECCSECSTAT			(ELFIN_NAND_ECC_BASE+NFECCSECSTAT_OFFSET)
#define NFECCPRGECC0			(ELFIN_NAND_ECC_BASE+NFECCPRGECC0_OFFSET)
#define NFECCPRGECC1			(ELFIN_NAND_ECC_BASE+NFECCPRGECC1_OFFSET)
#define NFECCPRGECC2			(ELFIN_NAND_ECC_BASE+NFECCPRGECC2_OFFSET)
#define NFECCPRGECC3			(ELFIN_NAND_ECC_BASE+NFECCPRGECC3_OFFSET)
#define NFECCPRGECC4			(ELFIN_NAND_ECC_BASE+NFECCPRGECC4_OFFSET)
#define NFECCPRGECC5			(ELFIN_NAND_ECC_BASE+NFECCPRGECC5_OFFSET)
#define NFECCPRGECC6			(ELFIN_NAND_ECC_BASE+NFECCPRGECC6_OFFSET)
#define NFECCERL0			(ELFIN_NAND_ECC_BASE+NFECCERL0_OFFSET)
#define NFECCERL1			(ELFIN_NAND_ECC_BASE+NFECCERL1_OFFSET)
#define NFECCERL2			(ELFIN_NAND_ECC_BASE+NFECCERL2_OFFSET)
#define NFECCERL3			(ELFIN_NAND_ECC_BASE+NFECCERL3_OFFSET)
#define NFECCERL4			(ELFIN_NAND_ECC_BASE+NFECCERL4_OFFSET)
#define NFECCERL5			(ELFIN_NAND_ECC_BASE+NFECCERL5_OFFSET)
#define NFECCERL6			(ELFIN_NAND_ECC_BASE+NFECCERL6_OFFSET)
#define NFECCERL7			(ELFIN_NAND_ECC_BASE+NFECCERL7_OFFSET)
#define NFECCERP0			(ELFIN_NAND_ECC_BASE+NFECCERP0_OFFSET)
#define NFECCERP1			(ELFIN_NAND_ECC_BASE+NFECCERP1_OFFSET)
#define NFECCERP2			(ELFIN_NAND_ECC_BASE+NFECCERP2_OFFSET)
#define NFECCERP3			(ELFIN_NAND_ECC_BASE+NFECCERP3_OFFSET)
#define NFECCCONECC0			(ELFIN_NAND_ECC_BASE+NFECCCONECC0_OFFSET)
#define NFECCCONECC1			(ELFIN_NAND_ECC_BASE+NFECCCONECC1_OFFSET)
#define NFECCCONECC2			(ELFIN_NAND_ECC_BASE+NFECCCONECC2_OFFSET)
#define NFECCCONECC3			(ELFIN_NAND_ECC_BASE+NFECCCONECC3_OFFSET)
#define NFECCCONECC4			(ELFIN_NAND_ECC_BASE+NFECCCONECC4_OFFSET)
#define NFECCCONECC5			(ELFIN_NAND_ECC_BASE+NFECCCONECC5_OFFSET)
#define NFECCCONECC6			(ELFIN_NAND_ECC_BASE+NFECCCONECC6_OFFSET)

#define __REG(x)	(*(volatile unsigned long *)(x))
#define __REGb(x)	(*(volatile unsigned char *)(x))
#define NFCONF_REG			__REG(ELFIN_NAND_BASE+NFCONF_OFFSET)
#define NFCONT_REG			__REG(ELFIN_NAND_BASE+NFCONT_OFFSET)
#define NFCMD_REG			__REG(ELFIN_NAND_BASE+NFCMMD_OFFSET)
#define NFADDR_REG           		__REG(ELFIN_NAND_BASE+NFADDR_OFFSET)
#define NFDATA_REG          		__REG(ELFIN_NAND_BASE+NFDATA_OFFSET)
#define NFDATA8_REG          		__REGb(ELFIN_NAND_BASE+NFDATA_OFFSET)
#define NFMECCDATA0_REG     		__REG(ELFIN_NAND_BASE+NFMECCDATA0_OFFSET)
#define NFMECCDATA1_REG     		__REG(ELFIN_NAND_BASE+NFMECCDATA1_OFFSET)
#define NFSECCDATA0_REG      		__REG(ELFIN_NAND_BASE+NFSECCDATA0_OFFSET)
#define NFSBLK_REG          		__REG(ELFIN_NAND_BASE+NFSBLK_OFFSET)
#define NFEBLK_REG           		__REG(ELFIN_NAND_BASE+NFEBLK_OFFSET)
#define NFSTAT_REG           		__REG(ELFIN_NAND_BASE+NFSTAT_OFFSET)
#define NFESTAT0_REG         		__REG(ELFIN_NAND_BASE+NFESTAT0_OFFSET)
#define NFESTAT1_REG         		__REG(ELFIN_NAND_BASE+NFESTAT1_OFFSET)
#define NFMECC0_REG          		__REG(ELFIN_NAND_BASE+NFMECC0_OFFSET)
#define NFMECC1_REG          		__REG(ELFIN_NAND_BASE+NFMECC1_OFFSET)
#define NFSECC_REG           		__REG(ELFIN_NAND_BASE+NFSECC_OFFSET)
#define NFMLCBITPT_REG         		__REG(ELFIN_NAND_BASE+NFMLCBITPT_OFFSET)

#define NFCONF_ECC_MLC			(1<<24)

#define NFCONF_ECC_1BIT			(0<<23)
#define NFCONF_ECC_4BIT			(2<<23)
#define NFCONF_ECC_8BIT			(1<<23)

#define NFCONT_ECC_ENC			(1<<18)
#define NFCONT_WP			(1<<16)
#define NFCONT_MECCLOCK			(1<<7)
#define NFCONT_SECCLOCK			(1<<6)
#define NFCONT_INITMECC			(1<<5)
#define NFCONT_INITSECC			(1<<4)
#define NFCONT_INITECC			(NFCONT_INITMECC | NFCONT_INITSECC)
#define NFCONT_CS			(1<<1)
#define NFSTAT_ECCENCDONE		(1<<25)
#define NFSTAT_ECCDECDONE		(1<<24)
#define NFSTAT_RnB			(1<<0)
#define NFESTAT0_ECCBUSY		(1<<31)


#define NFCONF_VAL	(7<<12)|(7<<8)|(7<<4)|(0<<3)|(1<<2)|(1<<1)|(0<<0)       
#define NFCONT_VAL	(0<<18)|(0<<17)|(0<<16)|(0<<10)|(0<<9)|(0<<8)|(0<<7)|(0<<6)|(0x3<<1)|(1<<0)
#define MP03CON_VAL	(1<<29)|(1<<25)|(1<<21)|(1<<17)|(1<<13)|(1<<9)|(1<<5)|(1<<1)




#define NAND_DISABLE_CE()	(NFCONT_REG |= (1 << 1))
#define NAND_ENABLE_CE()	(NFCONT_REG &= ~(1 << 1))
#define NF_TRANSRnB()		do { while(!(NFSTAT_REG & (1 << 0))); } while(0)

#define CFG_NAND_SKIP_BAD_DOT_I	1  /* ".i" read skips bad blocks   */
#define	CFG_NAND_WP		1
#define CFG_NAND_YAFFS_WRITE	1  /* support yaffs write */

#define CFG_NAND_HWECC
#define CFG_NAND_BL1_8BIT_ECC    //CONFIG_NAND_BL1_8BIT_ECC   config 不允许使用
#undef	CFG_NAND_FLASH_BBT





/*clock set*/
#define ELFIN_CLOCK_POWER_BASE		0xE0100000

/* Clock & Power Controller for s5pc110*/
#define APLL_LOCK_OFFSET		0x00
#define MPLL_LOCK_OFFSET		0x08
#define EPLL_LOCK_OFFSET		0x10
#define VPLL_LOCK_OFFSET		0x20
#define APLL_CON0_OFFSET		0x100
#define APLL_CON1_OFFSET		0x104
#define MPLL_CON_OFFSET			0x108
#define EPLL_CON_OFFSET			0x110
#define VPLL_CON_OFFSET			0x120

#define CLK_SRC0_OFFSET			0x200
#define CLK_SRC1_OFFSET			0x204
#define CLK_SRC2_OFFSET			0x208
#define CLK_SRC3_OFFSET			0x20c
#define CLK_SRC4_OFFSET			0x210
#define CLK_SRC5_OFFSET			0x214
#define CLK_SRC6_OFFSET			0x218
#define CLK_SRC_MASK0_OFFSET		0x280
#define CLK_SRC_MASK1_OFFSET		0x284

#define CLK_DIV0_OFFSET			0x300
#define CLK_DIV1_OFFSET			0x304
#define CLK_DIV2_OFFSET			0x308
#define CLK_DIV3_OFFSET			0x30c
#define CLK_DIV4_OFFSET			0x310
#define CLK_DIV5_OFFSET			0x314
#define CLK_DIV6_OFFSET			0x318
#define CLK_DIV7_OFFSET			0x31c

#define CLK_GATE_IP0_OFFSET		0x460
#define CLK_GATE_IP1_OFFSET		0x464
#define CLK_GATE_IP2_OFFSET		0x468
#define CLK_GATE_IP3_OFFSET		0x46c
#define CLK_GATE_IP4_OFFSET		0x470
#define CLK_GATE_BLOCK_OFFSET		0x480

#define CLK_OUT_OFFSET			0x500
#define CLK_DIV_STAT0_OFFSET		0x1000
#define CLK_DIV_STAT1_OFFSET		0x1004
#define CLK_MUX_STAT0_OFFSET		0x1100
#define CLK_MUX_STAT1_OFFSET		0x1104
#define SW_RST_OFFSET			0x2000




#define CLK_DIV0_MASK	0x7fffffff
#define CLK_DIV1_MASK	0xffffffff
#define CLK_DIV2_MASK	0x0fff
#define CLK_DIV3_MASK	0x7fffffff
#define CLK_DIV4_MASK	0xffffffff
#define CLK_DIV6_MASK	0xffffffff






#define APLL_MDIV       0x7d
#define APLL_PDIV       0x3
#define APLL_SDIV       0x1

#define MPLL_MDIV	0x29b
#define MPLL_PDIV	0xc
#define MPLL_SDIV	0x1


#define EPLL_MDIV	0x60
#define EPLL_PDIV	0x6
#define EPLL_SDIV	0x2

#define VPLL_MDIV	0x6c
#define VPLL_PDIV	0x6
#define VPLL_SDIV	0x3


#define set_pll(mdiv, pdiv, sdiv)	(1<<31 | mdiv<<16 | pdiv<<8 | sdiv)

#define APLL_VAL	set_pll(APLL_MDIV,APLL_PDIV,APLL_SDIV)
#define MPLL_VAL	set_pll(MPLL_MDIV,MPLL_PDIV,MPLL_SDIV)
#define EPLL_VAL	set_pll(EPLL_MDIV,EPLL_PDIV,EPLL_SDIV)
#define VPLL_VAL	set_pll(VPLL_MDIV,VPLL_PDIV,VPLL_SDIV)

#define AFC_ON		0x00000000
#define AFC_OFF		0x10000010


/* CLK_DIV0 */
#define APLL_RATIO	0
#define A2M_RATIO	4
#define HCLK_MSYS_RATIO	8
#define PCLK_MSYS_RATIO	12
#define HCLK_DSYS_RATIO	16
#define PCLK_DSYS_RATIO 20
#define HCLK_PSYS_RATIO	24
#define PCLK_PSYS_RATIO 28


#define CLK_DIV0_VAL    ((0<<APLL_RATIO)|(4<<A2M_RATIO)|(4<<HCLK_MSYS_RATIO)|(1<<PCLK_MSYS_RATIO)\
			|(3<<HCLK_DSYS_RATIO)|(1<<PCLK_DSYS_RATIO)|(4<<HCLK_PSYS_RATIO)|(1<<PCLK_PSYS_RATIO))

#define CLK_DIV1_VAL	((1<<16)|(1<<12)|(1<<8)|(1<<4))
#define CLK_DIV2_VAL	(1<<0)
#define CLK_DIV4_VAL	0x99990000
#define CLK_DIV6_VAL	0x71000

#define APLL_LOCKTIME_VAL	0xe10 
#define MPLL_LOCKTIME_VAL	0xe10 



/*
 * select serial console configuration
 */
#define CONFIG_SERIAL0			1	/* use SERIAL0    2-->0  2020-12-16*/
#define CONFIG_BAUDRATE			115200

/* MMC */
#define CONFIG_GENERIC_MMC
#define SDHCI_MAX_HOSTS		4

/* PWM */
#define CONFIG_PWM			1

#define CONFIG_SYS_NO_FLASH		1

#define CONFIG_CMD_REGINFO
/*#define CONFIG_CMD_ONENAND*/
#define CONFIG_CMD_GPT

/* USB Composite download gadget - g_dnl */
#define CONFIG_SYS_DFU_DATA_BUF_SIZE SZ_32M
#define DFU_DEFAULT_POLL_TIMEOUT 300

/* TIZEN THOR downloader support */
#define CONFIG_CMD_THOR_DOWNLOAD
#define CONFIG_USB_FUNCTION_THOR

/* USB Samsung's IDs */

#define CONFIG_G_DNL_THOR_VENDOR_NUM 0x04E8
#define CONFIG_G_DNL_THOR_PRODUCT_NUM 0x685D
#define CONFIG_G_DNL_UMS_VENDOR_NUM 0x0525
#define CONFIG_G_DNL_UMS_PRODUCT_NUM 0xA4A5

/* Actual modem binary size is 16MiB. Add 2MiB for bad block handling */
/*
#define MTDIDS_DEFAULT		"onenand0=samsung-onenand"
#define MTDPARTS_DEFAULT	"mtdparts=samsung-onenand:1m(bootloader)"\
				",256k(params)"\
				",2816k(config)"\
				",8m(csa)"\
				",7m(kernel)"\
				",1m(log)"\
				",12m(modem)"\
				",60m(qboot)\0"
*/


#if 0
/* partitions definitions */
#define PARTS_CSA			"csa-mmc"
#define PARTS_BOOTLOADER	"u-boot"
#define PARTS_BOOT			"boot"
#define PARTS_ROOT			"platform"
#define PARTS_DATA			"data"
#define PARTS_CSC			"csc"
#define PARTS_UMS			"ums"

#define CONFIG_DFU_ALT \
	"u-boot raw 0x80 0x400;" \
	"uImage ext4 0 2;" \
	"exynos3-goni.dtb ext4 0 2;" \
	""PARTS_ROOT" part 0 5\0"

#define PARTS_DEFAULT \
	"uuid_disk=${uuid_gpt_disk};" \
	"name="PARTS_CSA",size=8MiB,uuid=${uuid_gpt_"PARTS_CSA"};" \
	"name="PARTS_BOOTLOADER",size=60MiB," \
	"uuid=${uuid_gpt_"PARTS_BOOTLOADER"};" \
	"name="PARTS_BOOT",size=100MiB,uuid=${uuid_gpt_"PARTS_BOOT"};" \
	"name="PARTS_ROOT",size=1GiB,uuid=${uuid_gpt_"PARTS_ROOT"};" \
	"name="PARTS_DATA",size=3GiB,uuid=${uuid_gpt_"PARTS_DATA"};" \
	"name="PARTS_CSC",size=150MiB,uuid=${uuid_gpt_"PARTS_CSC"};" \
	"name="PARTS_UMS",size=-,uuid=${uuid_gpt_"PARTS_UMS"}\0" \

#define CONFIG_BOOTCOMMAND	"run mmcboot"

#define CONFIG_DEFAULT_CONSOLE	"console=ttySAC2,115200n8\0"

#define CONFIG_RAMDISK_BOOT	"root=/dev/ram0 rw rootfstype=ext4" \
		" ${console} ${meminfo}"

#define CONFIG_COMMON_BOOT	"${console} ${meminfo} ${mtdparts}"

#define CONFIG_BOOTARGS	"root=/dev/mtdblock8 rootfstype=ext4 " \
			CONFIG_COMMON_BOOT
/*
#define CONFIG_UPDATEB	"updateb=onenand erase 0x0 0x100000;" \
			" onenand write 0x32008000 0x0 0x100000\0"
*/
#else
#define CONFIG_BOOTARGS    	"root=/dev/mtdblock4 rootfstype=yaffs2 init=/init console=ttySAC0,115200"
/*#define CONFIG_ETHADDR		99:40:5c:26:3a:5b*/
#define CONFIG_NETMASK      255.255.0.0
#define CONFIG_IPADDR		192.168.1.88
#define CONFIG_SERVERIP		192.168.1.10
#define CONFIG_GATEWAYIP	192.168.1.1

#define CONFIG_BOOTCOMMAND "tftp 0x30008000 uImage ;bootm 0x30008000"

/*#define CONFIG_MTDPARTITION	"80000 400000 3000000"    //不知道有用没*/

#endif


#define CONFIG_SYS_MAX_NAND_DEVICE 1   //nand 支持的宏
#define CONFIG_SYS_NAND_BASE  (0xE7200000)



/*/#define CONFIG_SYS_NAND_REGS_BASE     (0xB0E00000)
//#define CONFIG_SYS_NAND_DATA_BASE    (0xE7200000)
//#define CONFIG_NAND_DENALI_ECC_SIZE 8*/


#define CONFIG_MISC_COMMON
#define CONFIG_MISC_INIT_R

#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_VARS_UBOOT_CONFIG
#define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
/*
#define CONFIG_EXTRA_ENV_SETTINGS					\
	CONFIG_UPDATEB \
	"updatek=" \
		"onenand erase 0xc00000 0x600000;" \
		"onenand write 0x31008000 0xc00000 0x600000\0" \
	"updateu=" \
		"onenand erase 0x01560000 0x1eaa0000;" \
		"onenand write 0x32000000 0x1260000 0x8C0000\0" \
	"bootk=" \
		"run loaduimage;" \
		"bootm 0x30007FC0\0" \
	"flashboot=" \
		"set bootargs root=/dev/mtdblock${bootblock} " \
		"rootfstype=${rootfstype} ${opts} " \
		"${lcdinfo} " CONFIG_COMMON_BOOT "; run bootk\0" \
	"ubifsboot=" \
		"set bootargs root=ubi0!rootfs rootfstype=ubifs " \
		"${opts} ${lcdinfo} " \
		CONFIG_COMMON_BOOT "; run bootk\0" \
	"tftpboot=" \
		"set bootargs root=ubi0!rootfs rootfstype=ubifs " \
		"${opts} ${lcdinfo} " CONFIG_COMMON_BOOT \
		"; tftp 0x30007FC0 uImage; bootm 0x30007FC0\0" \
	"ramboot=" \
		"set bootargs " CONFIG_RAMDISK_BOOT \
		"initrd=0x33000000,8M ramdisk=8192\0" \
	"mmcboot=" \
		"set bootargs root=/dev/mmcblk${mmcdev}p${mmcrootpart} " \
		"rootfstype=${rootfstype} ${opts} ${lcdinfo} " \
		CONFIG_COMMON_BOOT "; run bootk\0" \
	"boottrace=setenv opts initcall_debug; run bootcmd\0" \
	"bootchart=set opts init=/sbin/bootchartd; run bootcmd\0" \
	"verify=n\0" \
	"rootfstype=ext4\0" \
	"console=" CONFIG_DEFAULT_CONSOLE \
	"meminfo=mem=80M mem=256M@0x40000000 mem=128M@0x50000000\0" \
	"loaduimage=ext4load mmc ${mmcdev}:${mmcbootpart} 0x30007FC0 uImage\0" \
	"mmcdev=0\0" \
	"mmcbootpart=2\0" \
	"mmcrootpart=5\0" \
	"partitions=" PARTS_DEFAULT \
	"bootblock=9\0" \
	"ubiblock=8\0" \
	"ubi=enabled\0" \
	"opts=always_resume=1\0" \
	"dfu_alt_info=" CONFIG_DFU_ALT "\0"
*/
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_CBSIZE	256	/* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE	384	/* Print Buffer Size */
#define CONFIG_SYS_MAXARGS	16	/* max number of command args */
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
/* memtest works on */
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x5000000)
#define CONFIG_SYS_LOAD_ADDR		(CONFIG_SYS_SDRAM_BASE + 0x4000000)

/* Goni has 3 banks of DRAM, but swap the bank */
#if 0
#define CONFIG_NR_DRAM_BANKS	3
#define PHYS_SDRAM_1		CONFIG_SYS_SDRAM_BASE	/* OneDRAM Bank #0 */
#define PHYS_SDRAM_1_SIZE	(80 << 20)		/* 80 MB in Bank #0 */
#define PHYS_SDRAM_2		0x40000000		/* mDDR DMC1 Bank #1 */
#define PHYS_SDRAM_2_SIZE	(256 << 20)		/* 256 MB in Bank #1 */
#define PHYS_SDRAM_3		0x50000000		/* mDDR DMC2 Bank #2 */
#define PHYS_SDRAM_3_SIZE	(128 << 20)		/* 128 MB in Bank #2 */
#else
#define CONFIG_NR_DRAM_BANKS	2
#define PHYS_SDRAM_1		CONFIG_SYS_SDRAM_BASE	/* ddr2 Bank #0 */
#define PHYS_SDRAM_1_SIZE	(256 << 20)		/* 256 MB in Bank #0 */
#define PHYS_SDRAM_2		0x40000000		/* mDDR DMC1 Bank #1 */
#define PHYS_SDRAM_2_SIZE	(256 << 20)		/* 256 MB in Bank #1 */
#endif


#define CONFIG_SYS_MONITOR_BASE		0x00000000
#define CONFIG_SYS_MONITOR_LEN		(256 << 10)	/* 256 KiB */

/* FLASH and environment organization */
#define CONFIG_MMC_DEFAULT_DEV	0
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		CONFIG_MMC_DEFAULT_DEV
#define CONFIG_ENV_SIZE			4096
#define CONFIG_ENV_OFFSET		((32 - 4) << 10) /* 32KiB - 4KiB */
#define CONFIG_ENV_OVERWRITE

/*
#define CONFIG_USE_ONENAND_BOARD_INIT
#define CONFIG_SAMSUNG_ONENAND		1
#define CONFIG_SYS_ONENAND_BASE		0xB0000000
*/
#define CONFIG_DOS_PARTITION		1

/* write support for filesystems */
#define CONFIG_FAT_WRITE
#define CONFIG_EXT4_WRITE

/* GPT */
#define CONFIG_EFI_PARTITION
#define CONFIG_PARTITION_UUIDS

#define CONFIG_SYS_INIT_SP_ADDR	(CONFIG_SYS_LOAD_ADDR - 0x1000000)

#define CONFIG_USB_GADGET_DWC2_OTG_PHY
#define CONFIG_USB_FUNCTION_MASS_STORAGE

#endif	/* __CONFIG_H */
