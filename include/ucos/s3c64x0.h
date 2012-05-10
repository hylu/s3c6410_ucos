/*
 * (C) Copyright 2003
 * David Müller ELSOFT AG Switzerland. d.mueller@elsoft.ch
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/************************************************
 * NAME	    : S3C64XX.h
 * Version  : 31.3.2003
 *
 * common stuff for SAMSUNG S3C64XX SoC
 ************************************************/

#ifndef __S3C64XX_H__
#define __S3C64XX_H__

//@0x33FF_Fe20
#define pISR_EINT0	    (*(unsigned *)(_ISR_STARTADDRESS+0x20))
#define pISR_EINT1	    (*(unsigned *)(_ISR_STARTADDRESS+0x24))
#define pISR_RTC_TIC	(*(unsigned *)(_ISR_STARTADDRESS+0x28))
#define pISR_CAMIF_C	(*(unsigned *)(_ISR_STARTADDRESS+0x2c))
#define pISR_CAMIF_P	(*(unsigned *)(_ISR_STARTADDRESS+0x30))
#define pISR_I2C1	    (*(unsigned *)(_ISR_STARTADDRESS+0x34))
#define pISR_I2S	    (*(unsigned *)(_ISR_STARTADDRESS+0x38))
#define pISR_Reserved1	(*(unsigned *)(_ISR_STARTADDRESS+0x3c))
#define pISR_3D	        (*(unsigned *)(_ISR_STARTADDRESS+0x40))
#define pISR_Post0	    (*(unsigned *)(_ISR_STARTADDRESS+0x44))
#define pISR_ROTATOR	(*(unsigned *)(_ISR_STARTADDRESS+0x48))
#define pISR_2D	        (*(unsigned *)(_ISR_STARTADDRESS+0x4c))
#define pISR_TVENC	    (*(unsigned *)(_ISR_STARTADDRESS+0x50))
#define pISR_SCALER	    (*(unsigned *)(_ISR_STARTADDRESS+0x54))
#define pISR_BATF	    (*(unsigned *)(_ISR_STARTADDRESS+0x58))
#define pISR_JPEG	    (*(unsigned *)(_ISR_STARTADDRESS+0x5c))


//@0x33FF_Fe60

#define pISR_MFC	    (*(unsigned *)(_ISR_STARTADDRESS+0x60))
#define pISR_SDMA0	    (*(unsigned *)(_ISR_STARTADDRESS+0x64))
#define pISR_SDMA1	    (*(unsigned *)(_ISR_STARTADDRESS+0x68))
#define pISR_ARM_DMAERR	(*(unsigned *)(_ISR_STARTADDRESS+0x6c))
#define pISR_ARM_DMA	(*(unsigned *)(_ISR_STARTADDRESS+0x70))
#define pISR_ARM_DMAS	(*(unsigned *)(_ISR_STARTADDRESS+0x74))
#define pISR_KEYPAD	    (*(unsigned *)(_ISR_STARTADDRESS+0x78))
#define pISR_TIMER0	    (*(unsigned *)(_ISR_STARTADDRESS+0x7c))
#define pISR_TIMER1	    (*(unsigned *)(_ISR_STARTADDRESS+0x80))
#define pISR_TIMER2	    (*(unsigned *)(_ISR_STARTADDRESS+0x84))
#define pISR_WDT	    (*(unsigned *)(_ISR_STARTADDRESS+0x88))
#define pISR_TIMER3	    (*(unsigned *)(_ISR_STARTADDRESS+0x8c))
#define pISR_TIMER4	    (*(unsigned *)(_ISR_STARTADDRESS+0x90))
#define pISR_LCD0	    (*(unsigned *)(_ISR_STARTADDRESS+0x94))
#define pISR_LCD1	    (*(unsigned *)(_ISR_STARTADDRESS+0x98))
#define pISR_LCD2	    (*(unsigned *)(_ISR_STARTADDRESS+0x9c))

//@0x33FF_Fea0

#define pISR_EINT2	    (*(unsigned *)(_ISR_STARTADDRESS+0xa0))
#define pISR_EINT3	    (*(unsigned *)(_ISR_STARTADDRESS+0xa4))
#define pISR_PCM0	    (*(unsigned *)(_ISR_STARTADDRESS+0xa8))
#define pISR_PCM1	    (*(unsigned *)(_ISR_STARTADDRESS+0xac))
#define pISR_AC97	    (*(unsigned *)(_ISR_STARTADDRESS+0xb0))
#define pISR_UART0	    (*(unsigned *)(_ISR_STARTADDRESS+0xb4))
#define pISR_UART1	    (*(unsigned *)(_ISR_STARTADDRESS+0xb8))
#define pISR_UART2	    (*(unsigned *)(_ISR_STARTADDRESS+0xbc))
#define pISR_UART3	    (*(unsigned *)(_ISR_STARTADDRESS+0xc0))
#define pISR_DMA0	    (*(unsigned *)(_ISR_STARTADDRESS+0xc4))
#define pISR_DMA1	    (*(unsigned *)(_ISR_STARTADDRESS+0xc8))
#define pISR_ONENAND0	(*(unsigned *)(_ISR_STARTADDRESS+0xcc))
#define pISR_ONENAND1	(*(unsigned *)(_ISR_STARTADDRESS+0xd0))
#define pISR_NFC	    (*(unsigned *)(_ISR_STARTADDRESS+0xd4))
#define pISR_CFC	    (*(unsigned *)(_ISR_STARTADDRESS+0xd8))
#define pISR_UHOST	    (*(unsigned *)(_ISR_STARTADDRESS+0xdc))

//@0x33FF_Fee0

#define pISR_SPI0	        (*(unsigned *)(_ISR_STARTADDRESS+0xe0))
#define pISR_SPI1_HSMMC2	(*(unsigned *)(_ISR_STARTADDRESS+0xe4))
#define pISR_I2C0	        (*(unsigned *)(_ISR_STARTADDRESS+0xe8))
#define pISR_HSItx	        (*(unsigned *)(_ISR_STARTADDRESS+0xec))
#define pISR_HSIrx	        (*(unsigned *)(_ISR_STARTADDRESS+0xf0))
#define pISR_EINT4	        (*(unsigned *)(_ISR_STARTADDRESS+0xf4))
#define pISR_MSM	        (*(unsigned *)(_ISR_STARTADDRESS+0xf8))
#define pISR_HOSTIF	        (*(unsigned *)(_ISR_STARTADDRESS+0xfc))
#define pISR_HSMMC0	        (*(unsigned *)(_ISR_STARTADDRESS+0x100))
#define pISR_HSMMC1	        (*(unsigned *)(_ISR_STARTADDRESS+0x104))
#define pISR_OTG	        (*(unsigned *)(_ISR_STARTADDRESS+0x108))
#define pISR_IrDA	        (*(unsigned *)(_ISR_STARTADDRESS+0x10c))
#define pISR_RTC_ALARM	    (*(unsigned *)(_ISR_STARTADDRESS+0x110))
#define pISR_SEC	        (*(unsigned *)(_ISR_STARTADDRESS+0x114))
#define pISR_PENDNUP	    (*(unsigned *)(_ISR_STARTADDRESS+0x118))
#define pISR_ADC	        (*(unsigned *)(_ISR_STARTADDRESS+0x11c))


#define ELFIN_UART_BASE		0x7F005000

#define ELFIN_VIC0_BASE	    	0x71200000
#define ELFIN_VIC1_BASE	    	0x71300000

#define ELFIN_CLOCK_POWER_BASE	0x7e00f000
#define ELFIN_DMA_BASE		0x75000000
#define ELFIN_LCD_BASE		0x77100000
#define ELFIN_USB_HOST_BASE	0x74300000
#define ELFIN_I2C_BASE		0x7f004000
#define ELFIN_USB_DEVICE_BASE	0x7f007000

#define ELFIN_I2S_BASE		0x7f002000
#define ELFIN_ADC_BASE		0x7e00b000
#define ELFIN_SPI_BASE		0x7f00b000
#define ELFIN_HSMMC_0_BASE	0x7c200000
#define ELFIN_HSMMC_1_BASE	0x7c300000
#define ELFIN_HSMMC_2_BASE	0x7c400000

#define ELFIN_CLOCK_POWER_BASE	0x7e00f000

/* Clock & Power Controller for mDirac3*/
#define APLL_LOCK_OFFSET	0x00
#define MPLL_LOCK_OFFSET	0x04
#define EPLL_LOCK_OFFSET	0x08
#define APLL_CON_OFFSET		0x0C
#define MPLL_CON_OFFSET		0x10
#define EPLL_CON0_OFFSET	0x14
#define EPLL_CON1_OFFSET	0x18
#define CLK_SRC_OFFSET		0x1C
#define CLK_DIV0_OFFSET		0x20
#define CLK_DIV1_OFFSET		0x24
#define CLK_DIV2_OFFSET		0x28
#define CLK_OUT_OFFSET		0x2C
#define HCLK_GATE_OFFSET	0x30
#define PCLK_GATE_OFFSET	0x34
#define SCLK_GATE_OFFSET	0x38
#define AHB_CON0_OFFSET		0x100
#define AHB_CON1_OFFSET		0x104
#define AHB_CON2_OFFSET		0x108
#define SELECT_DMA_OFFSET	0x110
#define SW_RST_OFFSET		0x114
#define SYS_ID_OFFSET		0x118
#define MEM_SYS_CFG_OFFSET	0x120
#define QOS_OVERRIDE0_OFFSET	0x124
#define QOS_OVERRIDE1_OFFSET	0x128
#define MEM_CFG_STAT_OFFSET	0x12C
#define PWR_CFG_OFFSET		0x804
#define EINT_MASK_OFFSET	0x808
#define NOR_CFG_OFFSET		0x810
#define STOP_CFG_OFFSET		0x814
#define SLEEP_CFG_OFFSET	0x818
#define OSC_FREQ_OFFSET		0x820
#define OSC_STABLE_OFFSET	0x824
#define PWR_STABLE_OFFSET	0x828
#define FPC_STABLE_OFFSET	0x82C
#define MTC_STABLE_OFFSET	0x830
#define OTHERS_OFFSET		0x900
#define RST_STAT_OFFSET		0x904
#define WAKEUP_STAT_OFFSET	0x908
#define BLK_PWR_STAT_OFFSET	0x90C
#define INF_REG0_OFFSET		0xA00
#define INF_REG1_OFFSET		0xA04
#define INF_REG2_OFFSET		0xA08
#define INF_REG3_OFFSET		0xA0C
#define INF_REG4_OFFSET		0xA10
#define INF_REG5_OFFSET		0xA14
#define INF_REG6_OFFSET		0xA18
#define INF_REG7_OFFSET		0xA1C

#define OSC_CNT_VAL_OFFSET	0x824
#define PWR_CNT_VAL_OFFSET	0x828
#define FPC_CNT_VAL_OFFSET	0x82C
#define MTC_CNT_VAL_OFFSET	0x830

#define CLK_DIV0_REG		__REG(ELFIN_CLOCK_POWER_BASE+CLK_DIV0_OFFSET)
#define OTHERS_REG		__REG(ELFIN_CLOCK_POWER_BASE+OTHERS_OFFSET)

#define ELFIN_TIMER_BASE	0x7F006000

#define TCON_4_AUTO	    (1 << 22)       /* auto reload on/off for Timer 4 */
#define TCON_4_UPDATE	    (1 << 21)       /* manual Update TCNTB4 */
#define TCON_4_ONOFF	    (1 << 20)       /* 0: Stop, 1: start Timer 4 */
#define COUNT_4_ON	    (TCON_4_ONOFF*1)

#if 0





/* INTERRUPT (see manual chapter 14) */
typedef struct {
	S3C64XX_REG32	IRQSTATUS;
	S3C64XX_REG32	FIQSTATUS;
	S3C64XX_REG32	RAWINTR;
	S3C64XX_REG32	INTSELECT;
	S3C64XX_REG32	INTENABLE;
	S3C64XX_REG32	INTENCLEAR;
	S3C64XX_REG32	INTSOFTINT;
	S3C64XX_REG32	INTSOFTINTCLEAR;
	S3C64XX_REG32	PROTECTION;
	S3C64XX_REG32	SWPRIORITYMASK;
	S3C64XX_REG32	PRIORITYDAISY;
} /*__attribute__((__packed__))*/ S3C64XX_INTERRUPT;


/* NAND FLASH (see S3C2410 manual chapter 6) */
typedef struct {
	S3C64XX_REG32	NFCONF;
	S3C64XX_REG32	NFCMD;
	S3C64XX_REG32	NFADDR;
	S3C64XX_REG32	NFDATA;
	S3C64XX_REG32	NFSTAT;
	S3C64XX_REG32	NFECC;
} /*__attribute__((__packed__))*/ S3C2410_NAND;


/* UART (see manual chapter 11) */
typedef struct {
	S3C64XX_REG32	ULCON;
	S3C64XX_REG32	UCON;
	S3C64XX_REG32	UFCON;
	S3C64XX_REG32	UMCON;
	S3C64XX_REG32	UTRSTAT;
	S3C64XX_REG32	UERSTAT;
	S3C64XX_REG32	UFSTAT;
	S3C64XX_REG32	UMSTAT;
#ifdef __BIG_ENDIAN
	S3C64XX_REG8	res1[3];
	S3C64XX_REG8	UTXH;
	S3C64XX_REG8	res2[3];
	S3C64XX_REG8	URXH;
#else /* Little Endian */
	S3C64XX_REG8	UTXH;
	S3C64XX_REG8	res1[3];
	S3C64XX_REG8	URXH;
	S3C64XX_REG8	res2[3];
#endif
	S3C64XX_REG32	UBRDIV;
} /*__attribute__((__packed__))*/ S3C64XX_UART;


/* PWM TIMER (see manual chapter 10) */
typedef struct {
	S3C64XX_REG32	TCNTB;
	S3C64XX_REG32	TCMPB;
	S3C64XX_REG32	TCNTO;
} /*__attribute__((__packed__))*/ S3C64XX_TIMER;

typedef struct {
	S3C64XX_REG32	TCFG0;
	S3C64XX_REG32	TCFG1;
	S3C64XX_REG32	TCON;
	S3C64XX_TIMER	ch[4];
	S3C64XX_REG32	TCNTB4;
	S3C64XX_REG32	TCNTO4;
} /*__attribute__((__packed__))*/ S3C64XX_TIMERS;


/* USB DEVICE (see manual chapter 13) */
typedef struct {
#ifdef __BIG_ENDIAN
	S3C64XX_REG8	res[3];
	S3C64XX_REG8	EP_FIFO_REG;
#else /*  little endian */
	S3C64XX_REG8	EP_FIFO_REG;
	S3C64XX_REG8	res[3];
#endif
} /*__attribute__((__packed__))*/ S3C64XX_USB_DEV_FIFOS;

typedef struct {
#ifdef __BIG_ENDIAN
	S3C64XX_REG8	res1[3];
	S3C64XX_REG8	EP_DMA_CON;
	S3C64XX_REG8	res2[3];
	S3C64XX_REG8	EP_DMA_UNIT;
	S3C64XX_REG8	res3[3];
	S3C64XX_REG8	EP_DMA_FIFO;
	S3C64XX_REG8	res4[3];
	S3C64XX_REG8	EP_DMA_TTC_L;
	S3C64XX_REG8	res5[3];
	S3C64XX_REG8	EP_DMA_TTC_M;
	S3C64XX_REG8	res6[3];
	S3C64XX_REG8	EP_DMA_TTC_H;
#else /*  little endian */
	S3C64XX_REG8	EP_DMA_CON;
	S3C64XX_REG8	res1[3];
	S3C64XX_REG8	EP_DMA_UNIT;
	S3C64XX_REG8	res2[3];
	S3C64XX_REG8	EP_DMA_FIFO;
	S3C64XX_REG8	res3[3];
	S3C64XX_REG8	EP_DMA_TTC_L;
	S3C64XX_REG8	res4[3];
	S3C64XX_REG8	EP_DMA_TTC_M;
	S3C64XX_REG8	res5[3];
	S3C64XX_REG8	EP_DMA_TTC_H;
	S3C64XX_REG8	res6[3];
#endif
} /*__attribute__((__packed__))*/ S3C64XX_USB_DEV_DMAS;

typedef struct {
#ifdef __BIG_ENDIAN
	S3C64XX_REG8	res1[3];
	S3C64XX_REG8	FUNC_ADDR_REG;
	S3C64XX_REG8	res2[3];
	S3C64XX_REG8	PWR_REG;
	S3C64XX_REG8	res3[3];
	S3C64XX_REG8	EP_INT_REG;
	S3C64XX_REG8	res4[15];
	S3C64XX_REG8	USB_INT_REG;
	S3C64XX_REG8	res5[3];
	S3C64XX_REG8	EP_INT_EN_REG;
	S3C64XX_REG8	res6[15];
	S3C64XX_REG8	USB_INT_EN_REG;
	S3C64XX_REG8	res7[3];
	S3C64XX_REG8	FRAME_NUM1_REG;
	S3C64XX_REG8	res8[3];
	S3C64XX_REG8	FRAME_NUM2_REG;
	S3C64XX_REG8	res9[3];
	S3C64XX_REG8	INDEX_REG;
	S3C64XX_REG8	res10[7];
	S3C64XX_REG8	MAXP_REG;
	S3C64XX_REG8	res11[3];
	S3C64XX_REG8	EP0_CSR_IN_CSR1_REG;
	S3C64XX_REG8	res12[3];
	S3C64XX_REG8	IN_CSR2_REG;
	S3C64XX_REG8	res13[7];
	S3C64XX_REG8	OUT_CSR1_REG;
	S3C64XX_REG8	res14[3];
	S3C64XX_REG8	OUT_CSR2_REG;
	S3C64XX_REG8	res15[3];
	S3C64XX_REG8	OUT_FIFO_CNT1_REG;
	S3C64XX_REG8	res16[3];
	S3C64XX_REG8	OUT_FIFO_CNT2_REG;
#else /*  little endian */
	S3C64XX_REG8	FUNC_ADDR_REG;
	S3C64XX_REG8	res1[3];
	S3C64XX_REG8	PWR_REG;
	S3C64XX_REG8	res2[3];
	S3C64XX_REG8	EP_INT_REG;
	S3C64XX_REG8	res3[15];
	S3C64XX_REG8	USB_INT_REG;
	S3C64XX_REG8	res4[3];
	S3C64XX_REG8	EP_INT_EN_REG;
	S3C64XX_REG8	res5[15];
	S3C64XX_REG8	USB_INT_EN_REG;
	S3C64XX_REG8	res6[3];
	S3C64XX_REG8	FRAME_NUM1_REG;
	S3C64XX_REG8	res7[3];
	S3C64XX_REG8	FRAME_NUM2_REG;
	S3C64XX_REG8	res8[3];
	S3C64XX_REG8	INDEX_REG;
	S3C64XX_REG8	res9[7];
	S3C64XX_REG8	MAXP_REG;
	S3C64XX_REG8	res10[7];
	S3C64XX_REG8	EP0_CSR_IN_CSR1_REG;
	S3C64XX_REG8	res11[3];
	S3C64XX_REG8	IN_CSR2_REG;
	S3C64XX_REG8	res12[3];
	S3C64XX_REG8	OUT_CSR1_REG;
	S3C64XX_REG8	res13[7];
	S3C64XX_REG8	OUT_CSR2_REG;
	S3C64XX_REG8	res14[3];
	S3C64XX_REG8	OUT_FIFO_CNT1_REG;
	S3C64XX_REG8	res15[3];
	S3C64XX_REG8	OUT_FIFO_CNT2_REG;
	S3C64XX_REG8	res16[3];
#endif /*  __BIG_ENDIAN */
	S3C64XX_USB_DEV_FIFOS	fifo[5];
	S3C64XX_USB_DEV_DMAS	dma[5];
} /*__attribute__((__packed__))*/ S3C64XX_USB_DEVICE;








/* ADC (see manual chapter 16) */
typedef struct {
	S3C64XX_REG32	ADCCON;
	S3C64XX_REG32	ADCDAT;
} /*__attribute__((__packed__))*/ S3C2400_ADC;



/* MMC INTERFACE (see S3C2400 manual chapter 19) */
typedef struct {
#ifdef __BIG_ENDIAN
	S3C64XX_REG8	res1[3];
	S3C64XX_REG8	MMCON;
	S3C64XX_REG8	res2[3];
	S3C64XX_REG8	MMCRR;
	S3C64XX_REG8	res3[3];
	S3C64XX_REG8	MMFCON;
	S3C64XX_REG8	res4[3];
	S3C64XX_REG8	MMSTA;
	S3C64XX_REG16	res5;
	S3C64XX_REG16	MMFSTA;
	S3C64XX_REG8	res6[3];
	S3C64XX_REG8	MMPRE;
	S3C64XX_REG16	res7;
	S3C64XX_REG16	MMLEN;
	S3C64XX_REG8	res8[3];
	S3C64XX_REG8	MMCR7;
	S3C64XX_REG32	MMRSP[4];
	S3C64XX_REG8	res9[3];
	S3C64XX_REG8	MMCMD0;
	S3C64XX_REG32	MMCMD1;
	S3C64XX_REG16	res10;
	S3C64XX_REG16	MMCR16;
	S3C64XX_REG8	res11[3];
	S3C64XX_REG8	MMDAT;
#else
	S3C64XX_REG8	MMCON;
	S3C64XX_REG8	res1[3];
	S3C64XX_REG8	MMCRR;
	S3C64XX_REG8	res2[3];
	S3C64XX_REG8	MMFCON;
	S3C64XX_REG8	res3[3];
	S3C64XX_REG8	MMSTA;
	S3C64XX_REG8	res4[3];
	S3C64XX_REG16	MMFSTA;
	S3C64XX_REG16	res5;
	S3C64XX_REG8	MMPRE;
	S3C64XX_REG8	res6[3];
	S3C64XX_REG16	MMLEN;
	S3C64XX_REG16	res7;
	S3C64XX_REG8	MMCR7;
	S3C64XX_REG8	res8[3];
	S3C64XX_REG32	MMRSP[4];
	S3C64XX_REG8	MMCMD0;
	S3C64XX_REG8	res9[3];
	S3C64XX_REG32	MMCMD1;
	S3C64XX_REG16	MMCR16;
	S3C64XX_REG16	res10;
	S3C64XX_REG8	MMDAT;
	S3C64XX_REG8	res11[3];
#endif
} /*__attribute__((__packed__))*/ S3C2400_MMC;


/* SD INTERFACE (see S3C2410 manual chapter 19) */
typedef struct {
	S3C64XX_REG32	SDICON;
	S3C64XX_REG32	SDIPRE;
	S3C64XX_REG32	SDICARG;
	S3C64XX_REG32	SDICCON;
	S3C64XX_REG32	SDICSTA;
	S3C64XX_REG32	SDIRSP0;
	S3C64XX_REG32	SDIRSP1;
	S3C64XX_REG32	SDIRSP2;
	S3C64XX_REG32	SDIRSP3;
	S3C64XX_REG32	SDIDTIMER;
	S3C64XX_REG32	SDIBSIZE;
	S3C64XX_REG32	SDIDCON;
	S3C64XX_REG32	SDIDCNT;
	S3C64XX_REG32	SDIDSTA;
	S3C64XX_REG32	SDIFSTA;
#ifdef __BIG_ENDIAN
	S3C64XX_REG8	res[3];
	S3C64XX_REG8	SDIDAT;
#else
	S3C64XX_REG8	SDIDAT;
	S3C64XX_REG8	res[3];
#endif
	S3C64XX_REG32	SDIIMSK;
} /*__attribute__((__packed__))*/ S3C2410_SDI;


#if 0
/* Memory control */
#define rBWSCON	        (*(volatile unsigned *)0x48000000)
#define rBANKCON0	    (*(volatile unsigned *)0x48000004)
#define rBANKCON1	    (*(volatile unsigned *)0x48000008)
#define rBANKCON2	    (*(volatile unsigned *)0x4800000C)
#define rBANKCON3	    (*(volatile unsigned *)0x48000010)
#define rBANKCON4	    (*(volatile unsigned *)0x48000014)
#define rBANKCON5	    (*(volatile unsigned *)0x48000018)
#define rBANKCON6	    (*(volatile unsigned *)0x4800001C)
#define rBANKCON7	    (*(volatile unsigned *)0x48000020)
#define rREFRESH	    (*(volatile unsigned *)0x48000024)
#define rBANKSIZE	    (*(volatile unsigned *)0x48000028)
#define rMRSRB6	        (*(volatile unsigned *)0x4800002C)
#define rMRSRB7	        (*(volatile unsigned *)0x48000030)


/* USB HOST */
#define rHcRevision	    (*(volatile unsigned *)0x49000000)
#define rHcControl	    (*(volatile unsigned *)0x49000004)
#define rHcCommonStatus	    (*(volatile unsigned *)0x49000008)
#define rHcInterruptStatus	(*(volatile unsigned *)0x4900000C)
#define rHcInterruptEnable	(*(volatile unsigned *)0x49000010)
#define rHcInterruptDisable	(*(volatile unsigned *)0x49000014)
#define rHcHCCA	        (*(volatile unsigned *)0x49000018)
#define rHcPeriodCuttendED	(*(volatile unsigned *)0x4900001C)
#define rHcControlHeadED	(*(volatile unsigned *)0x49000020)
#define rHcControlCurrentED	(*(volatile unsigned *)0x49000024)
#define rHcBulkHeadED	    (*(volatile unsigned *)0x49000028)
#define rHcBuldCurrentED	(*(volatile unsigned *)0x4900002C)
#define rHcDoneHead	    (*(volatile unsigned *)0x49000030)
#define rHcRmInterval	    (*(volatile unsigned *)0x49000034)
#define rHcFmRemaining	    (*(volatile unsigned *)0x49000038)
#define rHcFmNumber	    (*(volatile unsigned *)0x4900003C)
#define rHcPeriodicStart	(*(volatile unsigned *)0x49000040)
#define rHcLSThreshold	    (*(volatile unsigned *)0x49000044)
#define rHcRhDescriptorA	(*(volatile unsigned *)0x49000048)
#define rHcRhDescriptorB	(*(volatile unsigned *)0x4900004C)
#define rHcRhStatus	    (*(volatile unsigned *)0x49000050)
#define rHcRhPortStatus1	(*(volatile unsigned *)0x49000054)
#define rHcRhPortStatus2	(*(volatile unsigned *)0x49000058)


/* INTERRUPT */
#define rSRCPND	        (*(volatile unsigned *)0x4A000000)
#define rINTMOD	        (*(volatile unsigned *)0x4A000004)
#define rINTMSK	        (*(volatile unsigned *)0x4A000008)
#define rPRIORITY	    (*(volatile unsigned *)0x4A00000C)
#define rINTPND	        (*(volatile unsigned *)0x4A000010)
#define rINTOFFSET	    (*(volatile unsigned *)0x4A000014)
#define rSUBSRCPND	    (*(volatile unsigned *)0x4A000018)
#define rINTSUBMSK	    (*(volatile unsigned *)0x4A00001C)


/* DMA */
#define rDISRC0	        (*(volatile unsigned *)0x4B000000)
#define rDISRCC0	    (*(volatile unsigned *)0x4B000004)
#define rDIDST0	        (*(volatile unsigned *)0x4B000008)
#define rDIDSTC0	    (*(volatile unsigned *)0x4B00000C)
#define rDCON0	        (*(volatile unsigned *)0x4B000010)
#define rDSTAT0	        (*(volatile unsigned *)0x4B000014)
#define rDCSRC0	        (*(volatile unsigned *)0x4B000018)
#define rDCDST0	        (*(volatile unsigned *)0x4B00001C)
#define rDMASKTRIG0	    (*(volatile unsigned *)0x4B000020)
#define rDISRC1	        (*(volatile unsigned *)0x4B000040)
#define rDISRCC1	    (*(volatile unsigned *)0x4B000044)
#define rDIDST1	        (*(volatile unsigned *)0x4B000048)
#define rDIDSTC1	    (*(volatile unsigned *)0x4B00004C)
#define rDCON1	        (*(volatile unsigned *)0x4B000050)
#define rDSTAT1	        (*(volatile unsigned *)0x4B000054)
#define rDCSRC1	        (*(volatile unsigned *)0x4B000058)
#define rDCDST1	        (*(volatile unsigned *)0x4B00005C)
#define rDMASKTRIG1	    (*(volatile unsigned *)0x4B000060)
#define rDISRC2	        (*(volatile unsigned *)0x4B000080)
#define rDISRCC2	    (*(volatile unsigned *)0x4B000084)
#define rDIDST2	        (*(volatile unsigned *)0x4B000088)
#define rDIDSTC2	    (*(volatile unsigned *)0x4B00008C)
#define rDCON2	        (*(volatile unsigned *)0x4B000090)
#define rDSTAT2	        (*(volatile unsigned *)0x4B000094)
#define rDCSRC2	        (*(volatile unsigned *)0x4B000098)
#define rDCDST2	        (*(volatile unsigned *)0x4B00009C)
#define rDMASKTRIG2	    (*(volatile unsigned *)0x4B0000A0)
#define rDISRC3	        (*(volatile unsigned *)0x4B0000C0)
#define rDISRCC3	    (*(volatile unsigned *)0x4B0000C4)
#define rDIDST3	        (*(volatile unsigned *)0x4B0000C8)
#define rDIDSTC3	    (*(volatile unsigned *)0x4B0000CC)
#define rDCON3	        (*(volatile unsigned *)0x4B0000D0)
#define rDSTAT3	        (*(volatile unsigned *)0x4B0000D4)
#define rDCSRC3	        (*(volatile unsigned *)0x4B0000D8)
#define rDCDST3	        (*(volatile unsigned *)0x4B0000DC)
#define rDMASKTRIG3	    (*(volatile unsigned *)0x4B0000E0)


/* CLOCK & POWER MANAGEMENT */
#define rLOCKTIME	    (*(volatile unsigned *)0x4C000000)
#define rMPLLCON	    (*(volatile unsigned *)0x4C000004)
#define rUPLLCON	    (*(volatile unsigned *)0x4C000008)
#define rCLKCON	        (*(volatile unsigned *)0x4C00000C)
#define rCLKSLOW	    (*(volatile unsigned *)0x4C000010)
#define rCLKDIVN	    (*(volatile unsigned *)0x4C000014)


/* LCD CONTROLLER */
#define rLCDCON1	    (*(volatile unsigned *)0x4D000000)
#define rLCDCON2	    (*(volatile unsigned *)0x4D000004)
#define rLCDCON3	    (*(volatile unsigned *)0x4D000008)
#define rLCDCON4	    (*(volatile unsigned *)0x4D00000C)
#define rLCDCON5	    (*(volatile unsigned *)0x4D000010)
#define rLCDSADDR1	    (*(volatile unsigned *)0x4D000014)
#define rLCDSADDR2	    (*(volatile unsigned *)0x4D000018)
#define rLCDSADDR3	    (*(volatile unsigned *)0x4D00001C)
#define rREDLUT	        (*(volatile unsigned *)0x4D000020)
#define rGREENLUT	    (*(volatile unsigned *)0x4D000024)
#define rBLUELUT	    (*(volatile unsigned *)0x4D000028)
#define rDITHMODE	    (*(volatile unsigned *)0x4D00004C)
#define rTPAL	        (*(volatile unsigned *)0x4D000050)
#define rLCDINTPND	    (*(volatile unsigned *)0x4D000054)
#define rLCDSRCPND	    (*(volatile unsigned *)0x4D000058)
#define rLCDINTMSK	    (*(volatile unsigned *)0x4D00005C)


/* NAND FLASH */
#define rNFCONF	        (*(volatile unsigned *)0x4E000000)
#define rNFCMD	        (*(volatile unsigned *)0x4E000004)
#define rNFADDR	        (*(volatile unsigned *)0x4E000008)
#define rNFDATA	        (*(volatile unsigned *)0x4E00000C)
#define rNFSTAT	        (*(volatile unsigned *)0x4E000010)
#define rNFECC	        (*(volatile unsigned *)0x4E000014)


/* UART */
#define rULCON0	        (*(volatile unsigned *)0x50000000)
#define rUCON0	        (*(volatile unsigned *)0x50000004)
#define rUFCON0	        (*(volatile unsigned *)0x50000008)
#define rUMCON0	        (*(volatile unsigned *)0x5000000C)
#define rUTRSTAT0	    (*(volatile unsigned *)0x50000010)
#define rUERSTAT0	    (*(volatile unsigned *)0x50000014)
#define rUFSTAT0	    (*(volatile unsigned *)0x50000018)
#define rUMSTAT0	    (*(volatile unsigned *)0x5000001C)
#define rUBRDIV0	    (*(volatile unsigned *)0x50000028)

#define rULCON1	        (*(volatile unsigned *)0x50004000)
#define rUCON1	        (*(volatile unsigned *)0x50004004)
#define rUFCON1	        (*(volatile unsigned *)0x50004008)
#define rUMCON1	        (*(volatile unsigned *)0x5000400C)
#define rUTRSTAT1	    (*(volatile unsigned *)0x50004010)
#define rUERSTAT1	    (*(volatile unsigned *)0x50004014)
#define rUFSTAT1	    (*(volatile unsigned *)0x50004018)
#define rUMSTAT1	    (*(volatile unsigned *)0x5000401C)
#define rUBRDIV1	    (*(volatile unsigned *)0x50004028)

#define rULCON2	        (*(volatile unsigned *)0x50008000)
#define rUCON2	        (*(volatile unsigned *)0x50008004)
#define rUFCON2	        (*(volatile unsigned *)0x50008008)
#define rUTRSTAT2	    (*(volatile unsigned *)0x50008010)
#define rUERSTAT2	    (*(volatile unsigned *)0x50008014)
#define rUFSTAT2	    (*(volatile unsigned *)0x50008018)
#define rUBRDIV2	    (*(volatile unsigned *)0x50008028)

#ifdef __BIG_ENDIAN
#define rUTXH0	        (*(volatile unsigned char *)0x50000023)
#define rURXH0	        (*(volatile unsigned char *)0x50000027)
#define rUTXH1	        (*(volatile unsigned char *)0x50004023)
#define rURXH1	        (*(volatile unsigned char *)0x50004027)
#define rUTXH2	        (*(volatile unsigned char *)0x50008023)
#define rURXH2	        (*(volatile unsigned char *)0x50008027)

#define WrUTXH0(ch)        (*(volatile unsigned char *)0x50000023)=(unsigned char)(ch)
#define RdURXH0()        (*(volatile unsigned char *)0x50000027)
#define WrUTXH1(ch)        (*(volatile unsigned char *)0x50004023)=(unsigned char)(ch)
#define RdURXH1()        (*(volatile unsigned char *)0x50004027)
#define WrUTXH2(ch)        (*(volatile unsigned char *)0x50008023)=(unsigned char)(ch)
#define RdURXH2()        (*(volatile unsigned char *)0x50008027)

#define UTXH0	        (0x50000020+3)  /* byte_access address by DMA */
#define URXH0	        (0x50000024+3)
#define UTXH1	        (0x50004020+3)
#define URXH1	        (0x50004024+3)
#define UTXH2	        (0x50008020+3)
#define URXH2	        (0x50008024+3)

#else /* Little Endian */
#define rUTXH0	        (*(volatile unsigned char *)0x50000020)
#define rURXH0	        (*(volatile unsigned char *)0x50000024)
#define rUTXH1	        (*(volatile unsigned char *)0x50004020)
#define rURXH1	        (*(volatile unsigned char *)0x50004024)
#define rUTXH2	        (*(volatile unsigned char *)0x50008020)
#define rURXH2	        (*(volatile unsigned char *)0x50008024)

#define WrUTXH0(ch)        (*(volatile unsigned char *)0x50000020)=(unsigned char)(ch)
#define RdURXH0()        (*(volatile unsigned char *)0x50000024)
#define WrUTXH1(ch)        (*(volatile unsigned char *)0x50004020)=(unsigned char)(ch)
#define RdURXH1()        (*(volatile unsigned char *)0x50004024)
#define WrUTXH2(ch)        (*(volatile unsigned char *)0x50008020)=(unsigned char)(ch)
#define RdURXH2()        (*(volatile unsigned char *)0x50008024)

#define UTXH0	        (0x50000020)    /* byte_access address by DMA */
#define URXH0	        (0x50000024)
#define UTXH1	        (0x50004020)
#define URXH1	        (0x50004024)
#define UTXH2	        (0x50008020)
#define URXH2	        (0x50008024)
#endif


/* PWM TIMER */
#define rTCFG0	        (*(volatile unsigned *)0x51000000)
#define rTCFG1	        (*(volatile unsigned *)0x51000004)
#define rTCON	        (*(volatile unsigned *)0x51000008)
#define rTCNTB0	        (*(volatile unsigned *)0x5100000C)
#define rTCMPB0	        (*(volatile unsigned *)0x51000010)
#define rTCNTO0	        (*(volatile unsigned *)0x51000014)
#define rTCNTB1	        (*(volatile unsigned *)0x51000018)
#define rTCMPB1	        (*(volatile unsigned *)0x5100001C)
#define rTCNTO1	        (*(volatile unsigned *)0x51000020)
#define rTCNTB2	        (*(volatile unsigned *)0x51000024)
#define rTCMPB2	        (*(volatile unsigned *)0x51000028)
#define rTCNTO2	        (*(volatile unsigned *)0x5100002C)
#define rTCNTB3	        (*(volatile unsigned *)0x51000030)
#define rTCMPB3	        (*(volatile unsigned *)0x51000034)
#define rTCNTO3	        (*(volatile unsigned *)0x51000038)
#define rTCNTB4	        (*(volatile unsigned *)0x5100003C)
#define rTCNTO4	        (*(volatile unsigned *)0x51000040)


/* USB DEVICE */
#ifdef __BIG_ENDIAN
#define rFUNC_ADDR_REG	    (*(volatile unsigned char *)0x52000143)
#define rPWR_REG	    (*(volatile unsigned char *)0x52000147)
#define rEP_INT_REG	    (*(volatile unsigned char *)0x5200014B)
#define rUSB_INT_REG	    (*(volatile unsigned char *)0x5200015B)
#define rEP_INT_EN_REG	    (*(volatile unsigned char *)0x5200015F)
#define rUSB_INT_EN_REG	    (*(volatile unsigned char *)0x5200016F)
#define rFRAME_NUM1_REG	    (*(volatile unsigned char *)0x52000173)
#define rFRAME_NUM2_REG	    (*(volatile unsigned char *)0x52000177)
#define rINDEX_REG	    (*(volatile unsigned char *)0x5200017B)
#define rMAXP_REG	    (*(volatile unsigned char *)0x52000183)
#define rEP0_CSR	    (*(volatile unsigned char *)0x52000187)
#define rIN_CSR1_REG	    (*(volatile unsigned char *)0x52000187)
#define rIN_CSR2_REG	    (*(volatile unsigned char *)0x5200018B)
#define rOUT_CSR1_REG	    (*(volatile unsigned char *)0x52000193)
#define rOUT_CSR2_REG	    (*(volatile unsigned char *)0x52000197)
#define rOUT_FIFO_CNT1_REG	(*(volatile unsigned char *)0x5200019B)
#define rOUT_FIFO_CNT2_REG	(*(volatile unsigned char *)0x5200019F)
#define rEP0_FIFO	    (*(volatile unsigned char *)0x520001C3)
#define rEP1_FIFO	    (*(volatile unsigned char *)0x520001C7)
#define rEP2_FIFO	    (*(volatile unsigned char *)0x520001CB)
#define rEP3_FIFO	    (*(volatile unsigned char *)0x520001CF)
#define rEP4_FIFO	    (*(volatile unsigned char *)0x520001D3)
#define rEP1_DMA_CON	    (*(volatile unsigned char *)0x52000203)
#define rEP1_DMA_UNIT	    (*(volatile unsigned char *)0x52000207)
#define rEP1_DMA_FIFO	    (*(volatile unsigned char *)0x5200020B)
#define rEP1_DMA_TX_LO	    (*(volatile unsigned char *)0x5200020F)
#define rEP1_DMA_TX_MD	    (*(volatile unsigned char *)0x52000213)
#define rEP1_DMA_TX_HI	    (*(volatile unsigned char *)0x52000217)
#define rEP2_DMA_CON	    (*(volatile unsigned char *)0x5200021B)
#define rEP2_DMA_UNIT	    (*(volatile unsigned char *)0x5200021F)
#define rEP2_DMA_FIFO	    (*(volatile unsigned char *)0x52000223)
#define rEP2_DMA_TX_LO	    (*(volatile unsigned char *)0x52000227)
#define rEP2_DMA_TX_MD	    (*(volatile unsigned char *)0x5200022B)
#define rEP2_DMA_TX_HI	    (*(volatile unsigned char *)0x5200022F)
#define rEP3_DMA_CON	    (*(volatile unsigned char *)0x52000243)
#define rEP3_DMA_UNIT	    (*(volatile unsigned char *)0x52000247)
#define rEP3_DMA_FIFO	    (*(volatile unsigned char *)0x5200024B)
#define rEP3_DMA_TX_LO	    (*(volatile unsigned char *)0x5200024F)
#define rEP3_DMA_TX_MD	    (*(volatile unsigned char *)0x52000253)
#define rEP3_DMA_TX_HI	    (*(volatile unsigned char *)0x52000257)
#define rEP4_DMA_CON	    (*(volatile unsigned char *)0x5200025B)
#define rEP4_DMA_UNIT	    (*(volatile unsigned char *)0x5200025F)
#define rEP4_DMA_FIFO	    (*(volatile unsigned char *)0x52000263)
#define rEP4_DMA_TX_LO	    (*(volatile unsigned char *)0x52000267)
#define rEP4_DMA_TX_MD	    (*(volatile unsigned char *)0x5200026B)
#define rEP4_DMA_TX_HI	    (*(volatile unsigned char *)0x5200026F)
#else /*  little endian */
#define rFUNC_ADDR_REG	    (*(volatile unsigned char *)0x52000140)
#define rPWR_REG	    (*(volatile unsigned char *)0x52000144)
#define rEP_INT_REG	    (*(volatile unsigned char *)0x52000148)
#define rUSB_INT_REG	    (*(volatile unsigned char *)0x52000158)
#define rEP_INT_EN_REG	    (*(volatile unsigned char *)0x5200015C)
#define rUSB_INT_EN_REG	    (*(volatile unsigned char *)0x5200016C)
#define rFRAME_NUM1_REG	    (*(volatile unsigned char *)0x52000170)
#define rFRAME_NUM2_REG	    (*(volatile unsigned char *)0x52000174)
#define rINDEX_REG	    (*(volatile unsigned char *)0x52000178)
#define rMAXP_REG	    (*(volatile unsigned char *)0x52000180)
#define rEP0_CSR	    (*(volatile unsigned char *)0x52000184)
#define rIN_CSR1_REG	    (*(volatile unsigned char *)0x52000184)
#define rIN_CSR2_REG	    (*(volatile unsigned char *)0x52000188)
#define rOUT_CSR1_REG	    (*(volatile unsigned char *)0x52000190)
#define rOUT_CSR2_REG	    (*(volatile unsigned char *)0x52000194)
#define rOUT_FIFO_CNT1_REG	(*(volatile unsigned char *)0x52000198)
#define rOUT_FIFO_CNT2_REG	(*(volatile unsigned char *)0x5200019C)
#define rEP0_FIFO	    (*(volatile unsigned char *)0x520001C0)
#define rEP1_FIFO	    (*(volatile unsigned char *)0x520001C4)
#define rEP2_FIFO	    (*(volatile unsigned char *)0x520001C8)
#define rEP3_FIFO	    (*(volatile unsigned char *)0x520001CC)
#define rEP4_FIFO	    (*(volatile unsigned char *)0x520001D0)
#define rEP1_DMA_CON	    (*(volatile unsigned char *)0x52000200)
#define rEP1_DMA_UNIT	    (*(volatile unsigned char *)0x52000204)
#define rEP1_DMA_FIFO	    (*(volatile unsigned char *)0x52000208)
#define rEP1_DMA_TX_LO	    (*(volatile unsigned char *)0x5200020C)
#define rEP1_DMA_TX_MD	    (*(volatile unsigned char *)0x52000210)
#define rEP1_DMA_TX_HI	    (*(volatile unsigned char *)0x52000214)
#define rEP2_DMA_CON	    (*(volatile unsigned char *)0x52000218)
#define rEP2_DMA_UNIT	    (*(volatile unsigned char *)0x5200021C)
#define rEP2_DMA_FIFO	    (*(volatile unsigned char *)0x52000220)
#define rEP2_DMA_TX_LO	    (*(volatile unsigned char *)0x52000224)
#define rEP2_DMA_TX_MD	    (*(volatile unsigned char *)0x52000228)
#define rEP2_DMA_TX_HI	    (*(volatile unsigned char *)0x5200022C)
#define rEP3_DMA_CON	    (*(volatile unsigned char *)0x52000240)
#define rEP3_DMA_UNIT	    (*(volatile unsigned char *)0x52000244)
#define rEP3_DMA_FIFO	    (*(volatile unsigned char *)0x52000248)
#define rEP3_DMA_TX_LO	    (*(volatile unsigned char *)0x5200024C)
#define rEP3_DMA_TX_MD	    (*(volatile unsigned char *)0x52000250)
#define rEP3_DMA_TX_HI	    (*(volatile unsigned char *)0x52000254)
#define rEP4_DMA_CON	    (*(volatile unsigned char *)0x52000258)
#define rEP4_DMA_UNIT	    (*(volatile unsigned char *)0x5200025C)
#define rEP4_DMA_FIFO	    (*(volatile unsigned char *)0x52000260)
#define rEP4_DMA_TX_LO	    (*(volatile unsigned char *)0x52000264)
#define rEP4_DMA_TX_MD	    (*(volatile unsigned char *)0x52000268)
#define rEP4_DMA_TX_HI	    (*(volatile unsigned char *)0x5200026C)
#endif /*  __BIG_ENDIAN */


/* WATCH DOG TIMER */
#define rWTCON	        (*(volatile unsigned *)0x53000000)
#define rWTDAT	        (*(volatile unsigned *)0x53000004)
#define rWTCNT	        (*(volatile unsigned *)0x53000008)


/* IIC */
#define rIICCON	        (*(volatile unsigned *)0x54000000)
#define rIICSTAT	    (*(volatile unsigned *)0x54000004)
#define rIICADD	        (*(volatile unsigned *)0x54000008)
#define rIICDS	        (*(volatile unsigned *)0x5400000C)


/* IIS */
#define rIISCON	        (*(volatile unsigned *)0x55000000)
#define rIISMOD	        (*(volatile unsigned *)0x55000004)
#define rIISPSR	        (*(volatile unsigned *)0x55000008)
#define rIISFCON	    (*(volatile unsigned *)0x5500000C)

#ifdef __BIG_ENDIAN
#define IISFIF	        ((volatile unsigned short *)0x55000012)
#else /*  little endian */
#define IISFIF	        ((volatile unsigned short *)0x55000010)
#endif


/* I/O PORT */
#define rGPACON	        (*(volatile unsigned *)0x56000000)
#define rGPADAT	        (*(volatile unsigned *)0x56000004)

#define rGPBCON	        (*(volatile unsigned *)0x56000010)
#define rGPBDAT	        (*(volatile unsigned *)0x56000014)
#define rGPBUP	        (*(volatile unsigned *)0x56000018)

#define rGPCCON	        (*(volatile unsigned *)0x56000020)
#define rGPCDAT	        (*(volatile unsigned *)0x56000024)
#define rGPCUP	        (*(volatile unsigned *)0x56000028)

#define rGPDCON	        (*(volatile unsigned *)0x56000030)
#define rGPDDAT	        (*(volatile unsigned *)0x56000034)
#define rGPDUP	        (*(volatile unsigned *)0x56000038)

#define rGPECON	        (*(volatile unsigned *)0x56000040)
#define rGPEDAT	        (*(volatile unsigned *)0x56000044)
#define rGPEUP	        (*(volatile unsigned *)0x56000048)

#define rGPFCON	        (*(volatile unsigned *)0x56000050)
#define rGPFDAT	        (*(volatile unsigned *)0x56000054)
#define rGPFUP	        (*(volatile unsigned *)0x56000058)

#define rGPGCON	        (*(volatile unsigned *)0x56000060)
#define rGPGDAT	        (*(volatile unsigned *)0x56000064)
#define rGPGUP	        (*(volatile unsigned *)0x56000068)

#define rGPHCON	        (*(volatile unsigned *)0x56000070)
#define rGPHDAT	        (*(volatile unsigned *)0x56000074)
#define rGPHUP	        (*(volatile unsigned *)0x56000078)

#define rMISCCR	        (*(volatile unsigned *)0x56000080)
#define rDCLKCON	    (*(volatile unsigned *)0x56000084)
#define rEXTINT0	    (*(volatile unsigned *)0x56000088)
#define rEXTINT1	    (*(volatile unsigned *)0x5600008C)
#define rEXTINT2	    (*(volatile unsigned *)0x56000090)
#define rEINTFLT0	    (*(volatile unsigned *)0x56000094)
#define rEINTFLT1	    (*(volatile unsigned *)0x56000098)
#define rEINTFLT2	    (*(volatile unsigned *)0x5600009C)
#define rEINTFLT3	    (*(volatile unsigned *)0x560000A0)
#define rEINTMASK	    (*(volatile unsigned *)0x560000A4)
#define rEINTPEND	    (*(volatile unsigned *)0x560000A8)
#define rGSTATUS0	    (*(volatile unsigned *)0x560000AC)
#define rGSTATUS1	    (*(volatile unsigned *)0x560000B0)


/* RTC */
#ifdef __BIG_ENDIAN
#define rRTCCON	        (*(volatile unsigned char *)0x57000043)
#define rTICNT	        (*(volatile unsigned char *)0x57000047)
#define rRTCALM	        (*(volatile unsigned char *)0x57000053)
#define rALMSEC	        (*(volatile unsigned char *)0x57000057)
#define rALMMIN	        (*(volatile unsigned char *)0x5700005B)
#define rALMHOUR	    (*(volatile unsigned char *)0x5700005F)
#define rALMDATE	    (*(volatile unsigned char *)0x57000063)
#define rALMMON	        (*(volatile unsigned char *)0x57000067)
#define rALMYEAR	    (*(volatile unsigned char *)0x5700006B)
#define rRTCRST	        (*(volatile unsigned char *)0x5700006F)
#define rBCDSEC	        (*(volatile unsigned char *)0x57000073)
#define rBCDMIN	        (*(volatile unsigned char *)0x57000077)
#define rBCDHOUR	    (*(volatile unsigned char *)0x5700007B)
#define rBCDDATE	    (*(volatile unsigned char *)0x5700007F)
#define rBCDDAY	        (*(volatile unsigned char *)0x57000083)
#define rBCDMON	        (*(volatile unsigned char *)0x57000087)
#define rBCDYEAR	    (*(volatile unsigned char *)0x5700008B)
#else /*  little endian */
#define rRTCCON	        (*(volatile unsigned char *)0x57000040)
#define rTICNT	        (*(volatile unsigned char *)0x57000044)
#define rRTCALM	        (*(volatile unsigned char *)0x57000050)
#define rALMSEC	        (*(volatile unsigned char *)0x57000054)
#define rALMMIN	        (*(volatile unsigned char *)0x57000058)
#define rALMHOUR	    (*(volatile unsigned char *)0x5700005C)
#define rALMDATE	    (*(volatile unsigned char *)0x57000060)
#define rALMMON	        (*(volatile unsigned char *)0x57000064)
#define rALMYEAR	    (*(volatile unsigned char *)0x57000068)
#define rRTCRST	        (*(volatile unsigned char *)0x5700006C)
#define rBCDSEC	        (*(volatile unsigned char *)0x57000070)
#define rBCDMIN	        (*(volatile unsigned char *)0x57000074)
#define rBCDHOUR	    (*(volatile unsigned char *)0x57000078)
#define rBCDDATE	    (*(volatile unsigned char *)0x5700007C)
#define rBCDDAY	        (*(volatile unsigned char *)0x57000080)
#define rBCDMON	        (*(volatile unsigned char *)0x57000084)
#define rBCDYEAR	    (*(volatile unsigned char *)0x57000088)
#endif


/* ADC */
#define rADCCON	        (*(volatile unsigned *)0x58000000)
#define rADCTSC	        (*(volatile unsigned *)0x58000004)
#define rADCDLY	        (*(volatile unsigned *)0x58000008)
#define rADCDAT0	    (*(volatile unsigned *)0x5800000C)
#define rADCDAT1	    (*(volatile unsigned *)0x58000010)


/* SPI */
#define rSPCON0	        (*(volatile unsigned *)0x59000000)
#define rSPSTA0	        (*(volatile unsigned *)0x59000004)
#define rSPPIN0	        (*(volatile unsigned *)0x59000008)
#define rSPPRE0	        (*(volatile unsigned *)0x5900000C)
#define rSPTDAT0	    (*(volatile unsigned *)0x59000010)
#define rSPRDAT0	    (*(volatile unsigned *)0x59000014)
#define rSPCON1	        (*(volatile unsigned *)0x59000020)
#define rSPSTA1	        (*(volatile unsigned *)0x59000024)
#define rSPPIN1	        (*(volatile unsigned *)0x59000028)
#define rSPPRE1	        (*(volatile unsigned *)0x5900002C)
#define rSPTDAT1	    (*(volatile unsigned *)0x59000030)
#define rSPRDAT1	    (*(volatile unsigned *)0x59000034)


/* SD INTERFACE */
#define rSDICON	        (*(volatile unsigned *)0x5A000000)
#define rSDIPRE	        (*(volatile unsigned *)0x5A000004)
#define rSDICmdArg	    (*(volatile unsigned *)0x5A000008)
#define rSDICmdCon	    (*(volatile unsigned *)0x5A00000C)
#define rSDICmdSta	    (*(volatile unsigned *)0x5A000010)
#define rSDIRSP0	    (*(volatile unsigned *)0x5A000014)
#define rSDIRSP1	    (*(volatile unsigned *)0x5A000018)
#define rSDIRSP2	    (*(volatile unsigned *)0x5A00001C)
#define rSDIRSP3	    (*(volatile unsigned *)0x5A000020)
#define rSDIDTimer	    (*(volatile unsigned *)0x5A000024)
#define rSDIBSize	    (*(volatile unsigned *)0x5A000028)
#define rSDIDatCon	    (*(volatile unsigned *)0x5A00002C)
#define rSDIDatCnt	    (*(volatile unsigned *)0x5A000030)
#define rSDIDatSta	    (*(volatile unsigned *)0x5A000034)
#define rSDIFSTA	    (*(volatile unsigned *)0x5A000038)
#ifdef __BIG_ENDIAN
#define rSDIDAT	        (*(volatile unsigned char *)0x5A00003F)
#else
#define rSDIDAT	        (*(volatile unsigned char *)0x5A00003C)
#endif
#define rSDIIntMsk	    (*(volatile unsigned *)0x5A000040)

#endif








#endif // #if 0


#endif /*__S3C64XX_H__*/
