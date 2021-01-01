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
#define BOOT_SEC_DEV	0x5
#define OMR_OFFSET		0x04
#define INF_REG3_OFFSET		0x0c
#define PRO_ID_BASE			0xE0000000
#define INF_REG_BASE		0xE010F000


#define CFG_PHY_UBOOT_BASE	CONFIG_SYS_TEXT_BASE
/* /#define CFG_PHY_KERNEL_BASE	MEMORY_BASE_ADDRESS + 0x8000
*/
#define CFG_ENV_OFFSET		0x0007C000

/* nand copy size from nand to DRAM.*/
#define	COPY_BL2_SIZE		0x80000



#ifdef CONFIG_CMD_NET
#define CONFIG_DRIVER_DM9000                  /* 使用dm9000驱动 */
#define CONFIG_ENV_SROM_BANK 1        /* 使用srom的bank1 */
 
#define CONFIG_DM9000_BASE  0x88000000        
#define DM9000_IO           CONFIG_DM9000_BASE
#define DM9000_DATA         (CONFIG_DM9000_BASE + 4)
#define CONFIG_DM9000_USE_16BIT  1
#endif


#define CONFIG_ETHADDR  00:19:D3:22:66:99



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
/*#define CONFIG_BOOTARGS    	"root=/dev/mtdblock4 rootfstype=yaffs2 init=/init console=ttySAC0,115200"
#define CONFIG_ETHADDR		99:40:5c:26:3a:5b*/

#define CONFIG_BOOTARGS "console=ttySAC0,115200n8 root=/dev/nfs nfsroot=192.168.1.10:/home/hqyj/hq6818/system/rootfs rw ip=192.168.1.50 rw root wait ignore_loglevel earlyprintk"
#define CONFIG_NETMASK      255.255.0.0
#define CONFIG_IPADDR		192.168.1.88
#define CONFIG_SERVERIP		192.168.1.10
#define CONFIG_GATEWAYIP	192.168.1.1

#define CONFIG_BOOTCOMMAND "tftp 0x30008000 uImage ;bootm 0x30008000"

/*#define CONFIG_MTDPARTITION	"80000 400000 3000000"    //不知道有用没*/

#endif




/*
 * NAND Contoller driver
 */
#ifdef CONFIG_CMD_NAND                  /* 2020-12-22 */
#define CONFIG_SYS_MAX_NAND_DEVICE      1
#define CONFIG_SYS_NAND_BASE            0xB0E00000

#define CONFIG_ENV_IS_IN_NAND          
#define CONFIG_ENV_ADDR     (512<<10)  /*512kB*/
#define CONFIG_ENV_SIZE     (256<<10)   /*256kB*/
#define CONFIG_ENV_OFFSET   (1<<20)      /*在存储器的偏移 1m*/


#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
 
#define MTDIDS_DEFAULT		"nand0=s5p-nand"
#define MTDPARTS_DEFAULT	"mtdparts=s5p-nand:1m(bootloader)"\
				",512k(params)"\
				",512k(dtb)"\
				",4m(kernel)"\
				",10m(ramdisk)"\
				",15m(cramfs)"\
				",40m(jffs2)"\
				",40m(yaffs2)"\
				",40m(ubifs)"\
				",-(data)"




#define CONFIG_SYS_NAND_ECCSIZE       512
#define CONFIG_SYS_NAND_ECCBYTES     13


/* modied by Sourcelink 

#define MTDIDS_DEFAULT          "nand0=s5p-nand"
#define MTDPARTS_DEFAULT        "mtdparts=s5p-nand:256k(bootloader)"\
                                ",128k@0x40000(params)"\
                                ",3m@0x60000(kernel)"\
                                ",-(rootfs)"
*/


#endif






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
/*#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		CONFIG_MMC_DEFAULT_DEV
#define CONFIG_ENV_SIZE			4096
#define CONFIG_ENV_OFFSET		((32 - 4) << 10) / * 32KiB - 4KiB * /
#define CONFIG_ENV_OVERWRITE */

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






/*  LCD   */

#define LCD_BPP			LCD_COLOR24






#endif	/* __CONFIG_H */
