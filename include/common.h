/*
 * (C) Copyright 2000-2004
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.     See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __COMMON_H_
#define __COMMON_H_    1

#undef    _LINUX_CONFIG_H
#define _LINUX_CONFIG_H 1    /* avoid reading Linux autoconf.h file    */

#define S3C64XX_UART_CHANNELS    3
#define S3C64XX_SPI_CHANNELS    2

typedef unsigned char        uchar;
typedef volatile unsigned long    vu_long;
typedef volatile unsigned short vu_short;
typedef volatile unsigned char    vu_char;

typedef volatile unsigned long    U32;

typedef vu_char        S3C64XX_REG8;
typedef vu_short    S3C64XX_REG16;
typedef vu_long        S3C64XX_REG32;


#define __REG(x)    (*(vu_long *)(x))


typedef enum {
    S3C64XX_UART0,
    S3C64XX_UART1,
    S3C64XX_UART2,
    S3C64XX_UART3,
} S3C64XX_UARTS_NR;


/* UART (see manual chapter 11) */
typedef struct {
    S3C64XX_REG32    ULCON;
    S3C64XX_REG32    UCON;
    S3C64XX_REG32    UFCON;
    S3C64XX_REG32    UMCON;
    S3C64XX_REG32    UTRSTAT;
    S3C64XX_REG32    UERSTAT;
    S3C64XX_REG32    UFSTAT;
    S3C64XX_REG32    UMSTAT;
#ifdef __BIG_ENDIAN
    S3C64XX_REG8    res1[3];
    S3C64XX_REG8    UTXH;
    S3C64XX_REG8    res2[3];
    S3C64XX_REG8    URXH;
#else /* Little Endian */
    S3C64XX_REG8    UTXH;
    S3C64XX_REG8    res1[3];
    S3C64XX_REG8    URXH;
    S3C64XX_REG8    res2[3];
#endif
    S3C64XX_REG32    UBRDIV;
} /*__attribute__((__packed__))*/ S3C64XX_UART;

typedef struct {
    S3C64XX_REG32    GPACON;
    S3C64XX_REG32    GPADAT;
    S3C64XX_REG32    GPAPUD;
    S3C64XX_REG32    GPACONSLP;
    S3C64XX_REG32    GPAPUDSLP;

} /*__attribute__((__packed__))*/ S3C64XX_GPA;

typedef struct {
    S3C64XX_REG32    GPBCON;
    S3C64XX_REG32    GPBDAT;
    S3C64XX_REG32    GPBPUD;
    S3C64XX_REG32    GPBCONSLP;
    S3C64XX_REG32    GPBPUDSLP;
} /*__attribute__((__packed__))*/ S3C64XX_GPB;    

typedef struct {
    S3C64XX_REG32    GPCCON;
    S3C64XX_REG32    GPCDAT;
    S3C64XX_REG32    GPCPUD;
    S3C64XX_REG32    GPCCONSLP;
    S3C64XX_REG32    GPCPUDSLP;

} /*__attribute__((__packed__))*/ S3C64XX_GPC;  
    
typedef struct {
    S3C64XX_REG32    GPDCON;
    S3C64XX_REG32    GPDDAT;
    S3C64XX_REG32    GPDPUD;
    S3C64XX_REG32    GPDCONSLP;
    S3C64XX_REG32    GPDPUDSLP;

} /*__attribute__((__packed__))*/ S3C64XX_GPD;  
    
typedef struct {
    S3C64XX_REG32    GPECON;
    S3C64XX_REG32    GPEDAT;
    S3C64XX_REG32    GPEPUD;
    S3C64XX_REG32    GPECONSLP;
    S3C64XX_REG32    GPEPUDSLP;
} /*__attribute__((__packed__))*/ S3C64XX_GPE;  
    
typedef struct {
    S3C64XX_REG32    GPFCON;
    S3C64XX_REG32    GPFDAT;
    S3C64XX_REG32    GPFPUD;
    S3C64XX_REG32    GPFCONSLP;
    S3C64XX_REG32    GPFPUDSLP;
} /*__attribute__((__packed__))*/ S3C64XX_GPF;  
    
typedef struct {
    S3C64XX_REG32    GPGCON;
    S3C64XX_REG32    GPGDAT;
    S3C64XX_REG32    GPGPUD;
    S3C64XX_REG32    GPGCONSLP;
    S3C64XX_REG32    GPGPUDSLP;
} /*__attribute__((__packed__))*/ S3C64XX_GPG;  
    
typedef struct {
    S3C64XX_REG32    GPHCON0;
    S3C64XX_REG32    GPHCON1;
    S3C64XX_REG32    GPHDAT;
    S3C64XX_REG32    GPHPUD;
    S3C64XX_REG32    GPHCONSLP;
    S3C64XX_REG32    GPHPUDSLP;
} /*__attribute__((__packed__))*/ S3C64XX_GPH;  
    
typedef struct {
    S3C64XX_REG32    GPICON;
    S3C64XX_REG32    GPIDAT;
    S3C64XX_REG32    GPIPUD;
    S3C64XX_REG32    GPICONSLP;
    S3C64XX_REG32    GPIPUDSLP;
} /*__attribute__((__packed__))*/ S3C64XX_GPI;  

typedef struct {
    S3C64XX_REG32    GPJCON;
    S3C64XX_REG32    GPJADAT;
    S3C64XX_REG32    GPJPUD;
    S3C64XX_REG32    GPJCONSLP;
    S3C64XX_REG32    GPJPUDSLP;
} /*__attribute__((__packed__))*/ S3C64XX_GPJ;  

typedef struct {
    S3C64XX_REG32    GPKCON0;
    S3C64XX_REG32    GPKCON1;
    S3C64XX_REG32    GPKDAT;
    S3C64XX_REG32    GPKPUD;
} /*__attribute__((__packed__))*/ S3C64XX_GPK;  
    
typedef struct {
    S3C64XX_REG32    GPLCON0;
    S3C64XX_REG32    GPLCON1;
    S3C64XX_REG32    GPLDAT;
    S3C64XX_REG32    GPLPUD;
} /*__attribute__((__packed__))*/ S3C64XX_GPL;  
    
typedef struct {
    S3C64XX_REG32    GPMCON;
    S3C64XX_REG32    GPMADAT;
    S3C64XX_REG32    GPMPUD;
} /*__attribute__((__packed__))*/ S3C64XX_GPM;  
    
typedef struct {
    S3C64XX_REG32    GPNCON;
    S3C64XX_REG32    GPNADAT;
    S3C64XX_REG32    GPNPUD;
} /*__attribute__((__packed__))*/ S3C64XX_GPN;  
    
typedef struct {
    S3C64XX_REG32    GPOCON;
    S3C64XX_REG32    GPOADAT;
    S3C64XX_REG32    GPOPUD;
    S3C64XX_REG32    GPOCONSLP;
    S3C64XX_REG32    GPOPUDSLP;
} /*__attribute__((__packed__))*/ S3C64XX_GPO;  
    
typedef struct {
    S3C64XX_REG32    GPPCON;
    S3C64XX_REG32    GPPDAT;
    S3C64XX_REG32    GPPPUD;
    S3C64XX_REG32    GPPCONSLP;
    S3C64XX_REG32    GPPPUDSLP;
} /*__attribute__((__packed__))*/ S3C64XX_GPP;  
    
 typedef struct {
    S3C64XX_REG32    GPQCON;
    S3C64XX_REG32    GPQDAT;
    S3C64XX_REG32    GPQPUD;
    S3C64XX_REG32    GPQCONSLP;
    S3C64XX_REG32    GPQPUDSLP;
} /*__attribute__((__packed__))*/ S3C64XX_GPQ;

 typedef struct {
    S3C64XX_REG32   CON0;
    S3C64XX_REG32   CON1;
    S3C64XX_REG32   reserv[2];
    S3C64XX_REG32   FLTCON0;
    S3C64XX_REG32   FLTCON1;
    S3C64XX_REG32   FLTCON2;
    S3C64XX_REG32   FLTCON3;
    S3C64XX_REG32   MASK;
    S3C64XX_REG32   PEND;
} /*__attribute__((__packed__))*/ S3C64XX_EINT0;

 typedef struct {
    S3C64XX_REG32   PRIORITY;
    S3C64XX_REG32   SERVICE;
    S3C64XX_REG32   SERVICEPEND;
} /*__attribute__((__packed__))*/ S3C64XX_EINTSRV;
 

/* PWM TIMER (see manual chapter 10) */
typedef struct {
    S3C64XX_REG32    TCNTB;
    S3C64XX_REG32    TCMPB;
    S3C64XX_REG32    TCNTO;
} /*__attribute__((__packed__))*/ S3C64XX_TIMER;

typedef struct {
    S3C64XX_REG32    TCFG0;
    S3C64XX_REG32    TCFG1;
    S3C64XX_REG32    TCON;
    S3C64XX_TIMER    ch[4];;        
    S3C64XX_REG32    TCNTB4;
    S3C64XX_REG32    TCNTO4;
    S3C64XX_REG32    CSTAT;
} /*__attribute__((__packed__))*/ S3C64XX_TIMERS;



#define APLL_CON_REG        __REG(ELFIN_CLOCK_POWER_BASE+APLL_CON_OFFSET)
#define MPLL_CON_REG        __REG(ELFIN_CLOCK_POWER_BASE+MPLL_CON_OFFSET)
#define EPLL_CON0_REG        __REG(ELFIN_CLOCK_POWER_BASE+EPLL_CON0_OFFSET)
#define EPLL_CON1_REG        __REG(ELFIN_CLOCK_POWER_BASE+EPLL_CON1_OFFSET)


/* INTERRUPT (see manual chapter 14) */
typedef struct {
    S3C64XX_REG32    IRQSTATUS;
    S3C64XX_REG32    FIQSTATUS;
    S3C64XX_REG32    RAWINTR;
    S3C64XX_REG32    INTSELECT;
    S3C64XX_REG32    INTENABLE;
    S3C64XX_REG32    INTENCLEAR;
    S3C64XX_REG32    INTSOFTINT;
    S3C64XX_REG32    INTSOFTINTCLEAR;
    S3C64XX_REG32    PROTECTION;
    S3C64XX_REG32    SWPRIORITYMASK;
    S3C64XX_REG32    PRIORITYDAISY;
} /*__attribute__((__packed__))*/ S3C64XX_INTERRUPT;

/* USB DEVICE (see manual chapter 13) */
typedef struct {
#ifdef __BIG_ENDIAN
    S3C64XX_REG8    res[3];
    S3C64XX_REG8    EP_FIFO_REG;
#else /*  little endian */
    S3C64XX_REG8    EP_FIFO_REG;
    S3C64XX_REG8    res[3];
#endif
} /*__attribute__((__packed__))*/ S3C64XX_USB_DEV_FIFOS;

typedef struct {
#ifdef __BIG_ENDIAN
    S3C64XX_REG8    res1[3];
    S3C64XX_REG8    EP_DMA_CON;
    S3C64XX_REG8    res2[3];
    S3C64XX_REG8    EP_DMA_UNIT;
    S3C64XX_REG8    res3[3];
    S3C64XX_REG8    EP_DMA_FIFO;
    S3C64XX_REG8    res4[3];
    S3C64XX_REG8    EP_DMA_TTC_L;
    S3C64XX_REG8    res5[3];
    S3C64XX_REG8    EP_DMA_TTC_M;
    S3C64XX_REG8    res6[3];
    S3C64XX_REG8    EP_DMA_TTC_H;
#else /*  little endian */
    S3C64XX_REG8    EP_DMA_CON;
    S3C64XX_REG8    res1[3];
    S3C64XX_REG8    EP_DMA_UNIT;
    S3C64XX_REG8    res2[3];
    S3C64XX_REG8    EP_DMA_FIFO;
    S3C64XX_REG8    res3[3];
    S3C64XX_REG8    EP_DMA_TTC_L;
    S3C64XX_REG8    res4[3];
    S3C64XX_REG8    EP_DMA_TTC_M;
    S3C64XX_REG8    res5[3];
    S3C64XX_REG8    EP_DMA_TTC_H;
    S3C64XX_REG8    res6[3];
#endif
} /*__attribute__((__packed__))*/ S3C64XX_USB_DEV_DMAS;

typedef struct {
#ifdef __BIG_ENDIAN
    S3C64XX_REG8    res1[3];
    S3C64XX_REG8    FUNC_ADDR_REG;
    S3C64XX_REG8    res2[3];
    S3C64XX_REG8    PWR_REG;
    S3C64XX_REG8    res3[3];
    S3C64XX_REG8    EP_INT_REG;
    S3C64XX_REG8    res4[15];
    S3C64XX_REG8    USB_INT_REG;
    S3C64XX_REG8    res5[3];
    S3C64XX_REG8    EP_INT_EN_REG;
    S3C64XX_REG8    res6[15];
    S3C64XX_REG8    USB_INT_EN_REG;
    S3C64XX_REG8    res7[3];
    S3C64XX_REG8    FRAME_NUM1_REG;
    S3C64XX_REG8    res8[3];
    S3C64XX_REG8    FRAME_NUM2_REG;
    S3C64XX_REG8    res9[3];
    S3C64XX_REG8    INDEX_REG;
    S3C64XX_REG8    res10[7];
    S3C64XX_REG8    MAXP_REG;
    S3C64XX_REG8    res11[3];
    S3C64XX_REG8    EP0_CSR_IN_CSR1_REG;
    S3C64XX_REG8    res12[3];
    S3C64XX_REG8    IN_CSR2_REG;
    S3C64XX_REG8    res13[7];
    S3C64XX_REG8    OUT_CSR1_REG;
    S3C64XX_REG8    res14[3];
    S3C64XX_REG8    OUT_CSR2_REG;
    S3C64XX_REG8    res15[3];
    S3C64XX_REG8    OUT_FIFO_CNT1_REG;
    S3C64XX_REG8    res16[3];
    S3C64XX_REG8    OUT_FIFO_CNT2_REG;
#else /*  little endian */
    S3C64XX_REG8    FUNC_ADDR_REG;
    S3C64XX_REG8    res1[3];
    S3C64XX_REG8    PWR_REG;
    S3C64XX_REG8    res2[3];
    S3C64XX_REG8    EP_INT_REG;
    S3C64XX_REG8    res3[15];
    S3C64XX_REG8    USB_INT_REG;
    S3C64XX_REG8    res4[3];
    S3C64XX_REG8    EP_INT_EN_REG;
    S3C64XX_REG8    res5[15];
    S3C64XX_REG8    USB_INT_EN_REG;
    S3C64XX_REG8    res6[3];
    S3C64XX_REG8    FRAME_NUM1_REG;
    S3C64XX_REG8    res7[3];
    S3C64XX_REG8    FRAME_NUM2_REG;
    S3C64XX_REG8    res8[3];
    S3C64XX_REG8    INDEX_REG;
    S3C64XX_REG8    res9[7];
    S3C64XX_REG8    MAXP_REG;
    S3C64XX_REG8    res10[7];
    S3C64XX_REG8    EP0_CSR_IN_CSR1_REG;
    S3C64XX_REG8    res11[3];
    S3C64XX_REG8    IN_CSR2_REG;
    S3C64XX_REG8    res12[3];
    S3C64XX_REG8    OUT_CSR1_REG;
    S3C64XX_REG8    res13[7];
    S3C64XX_REG8    OUT_CSR2_REG;
    S3C64XX_REG8    res14[3];
    S3C64XX_REG8    OUT_FIFO_CNT1_REG;
    S3C64XX_REG8    res15[3];
    S3C64XX_REG8    OUT_FIFO_CNT2_REG;
    S3C64XX_REG8    res16[3];
#endif /*  __BIG_ENDIAN */
    S3C64XX_USB_DEV_FIFOS    fifo[5];
    S3C64XX_USB_DEV_DMAS    dma[5];
} /*__attribute__((__packed__))*/ S3C64XX_USB_DEVICE;


/* Memory controller (see manual chapter 5) */
typedef struct {
    S3C64XX_REG32    BWSCON;
    S3C64XX_REG32    BANKCON[8];
    S3C64XX_REG32    REFRESH;
    S3C64XX_REG32    BANKSIZE;
    S3C64XX_REG32    MRSRB6;
    S3C64XX_REG32    MRSRB7;
} /*__attribute__((__packed__))*/ S3C64XX_MEMCTL;

/* USB HOST (see manual chapter 12) */
typedef struct {
    S3C64XX_REG32    HcRevision;
    S3C64XX_REG32    HcControl;
    S3C64XX_REG32    HcCommonStatus;
    S3C64XX_REG32    HcInterruptStatus;
    S3C64XX_REG32    HcInterruptEnable;
    S3C64XX_REG32    HcInterruptDisable;
    S3C64XX_REG32    HcHCCA;
    S3C64XX_REG32    HcPeriodCuttendED;
    S3C64XX_REG32    HcControlHeadED;
    S3C64XX_REG32    HcControlCurrentED;
    S3C64XX_REG32    HcBulkHeadED;
    S3C64XX_REG32    HcBuldCurrentED;
    S3C64XX_REG32    HcDoneHead;
    S3C64XX_REG32    HcRmInterval;
    S3C64XX_REG32    HcFmRemaining;
    S3C64XX_REG32    HcFmNumber;
    S3C64XX_REG32    HcPeriodicStart;
    S3C64XX_REG32    HcLSThreshold;
    S3C64XX_REG32    HcRhDescriptorA;
    S3C64XX_REG32    HcRhDescriptorB;
    S3C64XX_REG32    HcRhStatus;
    S3C64XX_REG32    HcRhPortStatus1;
    S3C64XX_REG32    HcRhPortStatus2;
} /*__attribute__((__packed__))*/ S3C64XX_USB_HOST;


/* DMAS (see manual chapter 8) */
typedef struct {
    S3C64XX_REG32    DISRC;
#ifdef CONFIG_S3C2410
    S3C64XX_REG32    DISRCC;
#endif
    S3C64XX_REG32    DIDST;
#ifdef CONFIG_S3C2410
    S3C64XX_REG32    DIDSTC;
#endif
    S3C64XX_REG32    DCON;
    S3C64XX_REG32    DSTAT;
    S3C64XX_REG32    DCSRC;
    S3C64XX_REG32    DCDST;
    S3C64XX_REG32    DMASKTRIG;
#ifdef CONFIG_S3C2400
    S3C64XX_REG32    res[1];
#endif
#ifdef CONFIG_S3C2410
    S3C64XX_REG32    res[7];
#endif
} /*__attribute__((__packed__))*/ S3C64XX_DMA;


typedef struct {
    S3C64XX_DMA    dma[4];
} /*__attribute__((__packed__))*/ S3C64XX_DMAS;

/* CLOCK & POWER MANAGEMENT (see S3C2400 manual chapter 6) */
/*                          (see S3C2410 manual chapter 7) */
typedef struct {
    S3C64XX_REG32    LOCKTIME;
#ifdef CONFIG_S3C24A0
    S3C64XX_REG32    reserved0;
    S3C64XX_REG32    reserved1;
    S3C64XX_REG32    reserved2;
#endif
    S3C64XX_REG32    MPLLCON;
    S3C64XX_REG32    UPLLCON;
#ifdef CONFIG_S3C24A0
    S3C64XX_REG32    reserved3;
    S3C64XX_REG32    reserved4;
#endif
    S3C64XX_REG32    CLKCON;
    S3C64XX_REG32    CLKSLOW;
    S3C64XX_REG32    CLKDIVN;
} /*__attribute__((__packed__))*/ S3C64XX_CLOCK_POWER;

/* LCD CONTROLLER (see manual chapter 15) */
typedef struct {
    S3C64XX_REG32    LCDCON1;
    S3C64XX_REG32    LCDCON2;
    S3C64XX_REG32    LCDCON3;
    S3C64XX_REG32    LCDCON4;
    S3C64XX_REG32    LCDCON5;
    S3C64XX_REG32    LCDSADDR1;
    S3C64XX_REG32    LCDSADDR2;
    S3C64XX_REG32    LCDSADDR3;
    S3C64XX_REG32    REDLUT;
    S3C64XX_REG32    GREENLUT;
    S3C64XX_REG32    BLUELUT;
    S3C64XX_REG32    res[8];
    S3C64XX_REG32    DITHMODE;
    S3C64XX_REG32    TPAL;
#ifdef CONFIG_S3C2410
    S3C64XX_REG32    LCDINTPND;
    S3C64XX_REG32    LCDSRCPND;
    S3C64XX_REG32    LCDINTMSK;
    S3C64XX_REG32    LPCSEL;
#endif
} /*__attribute__((__packed__))*/ S3C64XX_LCD;

/* WATCH DOG TIMER (see manual chapter 18) */
typedef struct {
    S3C64XX_REG32    WTCON;
    S3C64XX_REG32    WTDAT;
    S3C64XX_REG32    WTCNT;
} /*__attribute__((__packed__))*/ S3C64XX_WATCHDOG;


/* IIC (see manual chapter 20) */
typedef struct {
    S3C64XX_REG32    IICCON;
    S3C64XX_REG32    IICSTAT;
    S3C64XX_REG32    IICADD;
    S3C64XX_REG32    IICDS;
} /*__attribute__((__packed__))*/ S3C64XX_I2C;


/* IIS (see manual chapter 21) */
typedef struct {
#ifdef __BIG_ENDIAN
    S3C64XX_REG16    res1;
    S3C64XX_REG16    IISCON;
    S3C64XX_REG16    res2;
    S3C64XX_REG16    IISMOD;
    S3C64XX_REG16    res3;
    S3C64XX_REG16    IISPSR;
    S3C64XX_REG16    res4;
    S3C64XX_REG16    IISFCON;
    S3C64XX_REG16    res5;
    S3C64XX_REG16    IISFIFO;
#else /*  little endian */
    S3C64XX_REG16    IISCON;
    S3C64XX_REG16    res1;
    S3C64XX_REG16    IISMOD;
    S3C64XX_REG16    res2;
    S3C64XX_REG16    IISPSR;
    S3C64XX_REG16    res3;
    S3C64XX_REG16    IISFCON;
    S3C64XX_REG16    res4;
    S3C64XX_REG16    IISFIFO;
    S3C64XX_REG16    res5;
#endif
} /*__attribute__((__packed__))*/ S3C64XX_I2S;

/* RTC (see manual chapter 17) */
typedef struct {
#ifdef __BIG_ENDIAN
    S3C64XX_REG8    res1[67];
    S3C64XX_REG8    RTCCON;
    S3C64XX_REG8    res2[3];
    S3C64XX_REG8    TICNT;
    S3C64XX_REG8    res3[11];
    S3C64XX_REG8    RTCALM;
    S3C64XX_REG8    res4[3];
    S3C64XX_REG8    ALMSEC;
    S3C64XX_REG8    res5[3];
    S3C64XX_REG8    ALMMIN;
    S3C64XX_REG8    res6[3];
    S3C64XX_REG8    ALMHOUR;
    S3C64XX_REG8    res7[3];
    S3C64XX_REG8    ALMDATE;
    S3C64XX_REG8    res8[3];
    S3C64XX_REG8    ALMMON;
    S3C64XX_REG8    res9[3];
    S3C64XX_REG8    ALMYEAR;
    S3C64XX_REG8    res10[3];
    S3C64XX_REG8    RTCRST;
    S3C64XX_REG8    res11[3];
    S3C64XX_REG8    BCDSEC;
    S3C64XX_REG8    res12[3];
    S3C64XX_REG8    BCDMIN;
    S3C64XX_REG8    res13[3];
    S3C64XX_REG8    BCDHOUR;
    S3C64XX_REG8    res14[3];
    S3C64XX_REG8    BCDDATE;
    S3C64XX_REG8    res15[3];
    S3C64XX_REG8    BCDDAY;
    S3C64XX_REG8    res16[3];
    S3C64XX_REG8    BCDMON;
    S3C64XX_REG8    res17[3];
    S3C64XX_REG8    BCDYEAR;
#else /*  little endian */
    S3C64XX_REG8    res0[64];
    S3C64XX_REG8    RTCCON;
    S3C64XX_REG8    res1[3];
    S3C64XX_REG8    TICNT;
    S3C64XX_REG8    res2[11];
    S3C64XX_REG8    RTCALM;
    S3C64XX_REG8    res3[3];
    S3C64XX_REG8    ALMSEC;
    S3C64XX_REG8    res4[3];
    S3C64XX_REG8    ALMMIN;
    S3C64XX_REG8    res5[3];
    S3C64XX_REG8    ALMHOUR;
    S3C64XX_REG8    res6[3];
    S3C64XX_REG8    ALMDATE;
    S3C64XX_REG8    res7[3];
    S3C64XX_REG8    ALMMON;
    S3C64XX_REG8    res8[3];
    S3C64XX_REG8    ALMYEAR;
    S3C64XX_REG8    res9[3];
    S3C64XX_REG8    RTCRST;
    S3C64XX_REG8    res10[3];
    S3C64XX_REG8    BCDSEC;
    S3C64XX_REG8    res11[3];
    S3C64XX_REG8    BCDMIN;
    S3C64XX_REG8    res12[3];
    S3C64XX_REG8    BCDHOUR;
    S3C64XX_REG8    res13[3];
    S3C64XX_REG8    BCDDATE;
    S3C64XX_REG8    res14[3];
    S3C64XX_REG8    BCDDAY;
    S3C64XX_REG8    res15[3];
    S3C64XX_REG8    BCDMON;
    S3C64XX_REG8    res16[3];
    S3C64XX_REG8    BCDYEAR;
    S3C64XX_REG8    res17[3];
#endif
} /*__attribute__((__packed__))*/ S3C64XX_RTC;


/* SPI (see manual chapter 22) */
typedef struct {
    S3C64XX_REG32    SPCON;
    S3C64XX_REG32    SPSTA;
    S3C64XX_REG32    SPPIN;
    S3C64XX_REG32    SPPRE;
    S3C64XX_REG32    SPTDAT;
    S3C64XX_REG32    SPRDAT;
    S3C64XX_REG32    res[2];
} /*__attribute__((__packed__))*/ S3C64XX_SPI_CHANNEL;

typedef struct {
    S3C64XX_SPI_CHANNEL    ch[S3C64XX_SPI_CHANNELS];
} /*__attribute__((__packed__))*/ S3C64XX_SPI;



#include <config.h>
#include <linux/bitops.h>
#include <linux/types.h>
#include <linux/string.h>
#include <asm/ptrace.h>
#include <stdarg.h>
#if defined(CONFIG_PCI) && defined(CONFIG_440)
#include <pci.h>
#endif
#if defined(CONFIG_8xx)
#include <asm/8xx_immap.h>
#if defined(CONFIG_MPC852)    || defined(CONFIG_MPC852T)    || \
    defined(CONFIG_MPC859)    || defined(CONFIG_MPC859T)    || \
    defined(CONFIG_MPC859DSL)    || \
    defined(CONFIG_MPC866)    || defined(CONFIG_MPC866T)    || \
    defined(CONFIG_MPC866P)
# define CONFIG_MPC866_FAMILY 1
#elif defined(CONFIG_MPC870) \
   || defined(CONFIG_MPC875) \
   || defined(CONFIG_MPC880) \
   || defined(CONFIG_MPC885)
# define CONFIG_MPC885_FAMILY   1
#endif
#if   defined(CONFIG_MPC860)       \
   || defined(CONFIG_MPC860T)       \
   || defined(CONFIG_MPC866_FAMILY) \
   || defined(CONFIG_MPC885_FAMILY)
# define CONFIG_MPC86x 1
#endif
#elif defined(CONFIG_5xx)
#include <asm/5xx_immap.h>
#elif defined(CONFIG_MPC5xxx)
#include <mpc5xxx.h>
#elif defined(CONFIG_MPC8220)
#include <asm/immap_8220.h>
#elif defined(CONFIG_8260)
#if   defined(CONFIG_MPC8247) \
   || defined(CONFIG_MPC8248) \
   || defined(CONFIG_MPC8271) \
   || defined(CONFIG_MPC8272)
#define CONFIG_MPC8272_FAMILY    1
#endif
#if defined(CONFIG_MPC8272_FAMILY)
#define CONFIG_MPC8260    1
#endif
#include <asm/immap_8260.h>
#endif
#ifdef CONFIG_MPC86xx
#include <mpc86xx.h>
#include <asm/immap_86xx.h>
#endif
#ifdef CONFIG_MPC85xx
#include <mpc85xx.h>
#include <asm/immap_85xx.h>
#endif
#ifdef CONFIG_MPC83XX
#include <mpc83xx.h>
#include <asm/immap_83xx.h>
#endif
#ifdef    CONFIG_4xx
#include <ppc4xx.h>
#endif
#ifdef CONFIG_HYMOD
#include <board/hymod/hymod.h>
#endif
#ifdef CONFIG_ARM
#define asmlinkage    /* nothing */
#endif

#include <part.h>
#include <flash.h>
#include <image.h>

#ifdef    DEBUG
#define debug(fmt,args...)    printf (fmt ,##args)
#define debugX(level,fmt,args...) if (DEBUG>=level) printf(fmt,##args);
#else
#define debug(fmt,args...)
#define debugX(level,fmt,args...)
#endif    /* DEBUG */

#define BUG() do { \
    printf("BUG: failure at %s:%d/%s()!\n", __FILE__, __LINE__, __FUNCTION__); \
    panic("BUG!"); \
} while (0)
#define BUG_ON(condition) do { if (unlikely((condition)!=0)) BUG(); } while(0)

typedef void (interrupt_handler_t)(void *);

#include <asm/u-boot.h> /* boot information for Linux kernel */
#include <asm/global_data.h>    /* global data used for startup functions */

/*
 * enable common handling for all TQM8xxL/M boards:
 * - CONFIG_TQM8xxM will be defined for all TQM8xxM and TQM885D boards
 * - CONFIG_TQM8xxL will be defined for all TQM8xxL _and_ TQM8xxM boards
 */
#if defined(CONFIG_TQM823M) || defined(CONFIG_TQM850M) || \
    defined(CONFIG_TQM855M) || defined(CONFIG_TQM860M) || \
    defined(CONFIG_TQM862M) || defined(CONFIG_TQM866M) || \
    defined(CONFIG_TQM885D)
# ifndef CONFIG_TQM8xxM
#  define CONFIG_TQM8xxM
# endif
#endif
#if defined(CONFIG_TQM823L) || defined(CONFIG_TQM850L) || \
    defined(CONFIG_TQM855L) || defined(CONFIG_TQM860L) || \
    defined(CONFIG_TQM862L) || defined(CONFIG_TQM8xxM)
# ifndef CONFIG_TQM8xxL
#  define CONFIG_TQM8xxL
# endif
#endif

#ifndef CONFIG_SERIAL_MULTI

#if defined(CONFIG_8xx_CONS_SMC1) || defined(CONFIG_8xx_CONS_SMC2) \
 || defined(CONFIG_8xx_CONS_SCC1) || defined(CONFIG_8xx_CONS_SCC2) \
 || defined(CONFIG_8xx_CONS_SCC3) || defined(CONFIG_8xx_CONS_SCC4)

#define CONFIG_SERIAL_MULTI    1

#endif

#endif /* CONFIG_SERIAL_MULTI */

/*
 * General Purpose Utilities
 */
#define min(X, Y)                \
    ({ typeof (X) __x = (X), __y = (Y);    \
        (__x < __y) ? __x : __y; })

#define max(X, Y)                \
    ({ typeof (X) __x = (X), __y = (Y);    \
        (__x > __y) ? __x : __y; })


/*
 * Function Prototypes
 */

#ifdef CONFIG_SERIAL_SOFTWARE_FIFO
void    serial_buffered_init (void);
void    serial_buffered_putc (const char);
void    serial_buffered_puts (const char *);
int    serial_buffered_getc (void);
int    serial_buffered_tstc (void);
#endif /* CONFIG_SERIAL_SOFTWARE_FIFO */

void    hang        (void) __attribute__ ((noreturn));

/* */
long int initdram (int);
int    display_options (void);
void    print_size (ulong, const char *);

/* common/main.c */
void    main_loop    (void);
int    run_command    (const char *cmd, int flag);
int    readline    (const char *const prompt);
void    init_cmd_timeout(void);
void    reset_cmd_timeout(void);

/* lib_$(ARCH)/board.c */
void    board_init_f  (ulong);
void    board_init_r  (gd_t *, ulong);
int    checkboard    (void);
int    checkflash    (void);
int    checkdram     (void);
char *    strmhz(char *buf, long hz);
int    last_stage_init(void);
extern ulong monitor_flash_len;
#ifdef CFG_ID_EEPROM
int mac_read_from_eeprom(void);
#endif

/* common/flash.c */
void flash_perror (int);

/* common/cmd_autoscript.c */
int    autoscript (ulong addr);

/* common/cmd_bootm.c */
void    print_image_hdr (image_header_t *hdr);

extern ulong load_addr;        /* Default Load Address */

/* common/cmd_nvedit.c */
int    env_init     (void);
void    env_relocate (void);
char    *getenv         (char *);
int    getenv_r     (char *name, char *buf, unsigned len);
int    saveenv         (void);
#ifdef CONFIG_PPC        /* ARM version to be fixed! */
void inline setenv   (char *, char *);
#else
void    setenv         (char *, char *);
#endif /* CONFIG_PPC */
#ifdef CONFIG_ARM
# include <asm/mach-types.h>
# include <asm/setup.h>
# include <asm/u-boot-arm.h>    /* ARM version to be fixed! */
#endif /* CONFIG_ARM */
#ifdef CONFIG_I386        /* x86 version to be fixed! */
# include <asm/u-boot-i386.h>
#endif /* CONFIG_I386 */

#ifdef CONFIG_AUTO_COMPLETE
int env_complete(char *var, int maxv, char *cmdv[], int maxsz, char *buf);
#endif

void    pci_init      (void);
void    pci_init_board(void);
void    pciinfo          (int, int);

#if defined(CONFIG_PCI) && defined(CONFIG_440)
#   if defined(CFG_PCI_PRE_INIT)
    int       pci_pre_init           (struct pci_controller * );
#   endif
#   if defined(CFG_PCI_TARGET_INIT)
    void    pci_target_init         (struct pci_controller *);
#   endif
#   if defined(CFG_PCI_MASTER_INIT)
    void    pci_master_init         (struct pci_controller *);
#   endif
    int        is_pci_host        (struct pci_controller *);
#if defined(CONFIG_440SPE)
   void pcie_setup_hoses(void);
#endif
#endif

int    misc_init_f   (void);
int    misc_init_r   (void);

/* common/exports.c */
void    jumptable_init(void);

/* common/memsize.c */
long    get_ram_size  (volatile long *, long);

/* $(BOARD)/$(BOARD).c */
void    reset_phy     (void);
void    fdc_hw_init   (void);

/* $(BOARD)/eeprom.c */
void eeprom_init  (void);
#ifndef CONFIG_SPI
int  eeprom_probe (unsigned dev_addr, unsigned offset);
#endif
int  eeprom_read  (unsigned dev_addr, unsigned offset, uchar *buffer, unsigned cnt);
int  eeprom_write (unsigned dev_addr, unsigned offset, uchar *buffer, unsigned cnt);
#ifdef CONFIG_LWMON
extern uchar pic_read  (uchar reg);
extern void  pic_write (uchar reg, uchar val);
#endif

/*
 * Set this up regardless of board
 * type, to prevent errors.
 */
#if defined(CONFIG_SPI) || !defined(CFG_I2C_EEPROM_ADDR)
# define CFG_DEF_EEPROM_ADDR 0
#else
# define CFG_DEF_EEPROM_ADDR CFG_I2C_EEPROM_ADDR
#endif /* CONFIG_SPI || !defined(CFG_I2C_EEPROM_ADDR) */

#if defined(CONFIG_SPI)
extern void spi_init_f (void);
extern void spi_init_r (void);
extern ssize_t spi_read     (uchar *, int, uchar *, int);
extern ssize_t spi_write (uchar *, int, uchar *, int);
#endif

#ifdef CONFIG_RPXCLASSIC
void rpxclassic_init (void);
#endif

void rpxlite_init (void);

#ifdef CONFIG_MBX
/* $(BOARD)/mbx8xx.c */
void    mbx_init (void);
void    board_serial_init (void);
void    board_ether_init (void);
#endif

#if defined(CONFIG_RPXCLASSIC)    || defined(CONFIG_MBX) || \
    defined(CONFIG_IAD210)    || defined(CONFIG_XPEDITE1K) || \
    defined(CONFIG_METROBOX)    || defined(CONFIG_KAREF) || \
    defined(CONFIG_V38B)
void    board_get_enetaddr (uchar *addr);
#endif

#ifdef CONFIG_HERMES
/* $(BOARD)/hermes.c */
void hermes_start_lxt980 (int speed);
#endif

#ifdef CONFIG_EVB64260
void  evb64260_init(void);
void  debug_led(int, int);
void  display_mem_map(void);
void  perform_soft_reset(void);
#endif

void    load_sernum_ethaddr (void);

/* $(BOARD)/$(BOARD).c */
int board_early_init_f (void);
int board_late_init (void);
int board_postclk_init (void); /* after clocks/timebase, before env/serial */
int board_early_init_r (void);
void board_poweroff (void);

#if defined(CFG_DRAM_TEST)
int testdram(void);
#endif /* CFG_DRAM_TEST */

/* $(CPU)/start.S */
#if defined(CONFIG_5xx) || \
    defined(CONFIG_8xx)
uint    get_immr      (uint);
#endif
uint    get_pir          (void);
#if defined(CONFIG_MPC5xxx)
uint    get_svr       (void);
#endif
uint    get_pvr          (void);
uint    get_svr          (void);
uint    rd_ic_cst     (void);
void    wr_ic_cst     (uint);
void    wr_ic_adr     (uint);
uint    rd_dc_cst     (void);
void    wr_dc_cst     (uint);
void    wr_dc_adr     (uint);
int    icache_status (void);
void    icache_enable (void);
void    icache_disable(void);
int    dcache_status (void);
void    dcache_enable (void);
void    dcache_disable(void);
void    relocate_code (ulong, gd_t *, ulong);
ulong    get_endaddr   (void);
void    trap_init     (ulong);
#if defined (CONFIG_4xx)    || \
    defined (CONFIG_MPC5xxx)    || \
    defined (CONFIG_74xx_7xx)    || \
    defined (CONFIG_74x)    || \
    defined (CONFIG_75x)    || \
    defined (CONFIG_74xx)    || \
    defined (CONFIG_MPC8220)    || \
    defined (CONFIG_MPC85xx)    || \
    defined (CONFIG_MPC86xx)    || \
    defined (CONFIG_MPC83XX)
unsigned char    in8(unsigned int);
void        out8(unsigned int, unsigned char);
unsigned short    in16(unsigned int);
unsigned short    in16r(unsigned int);
void        out16(unsigned int, unsigned short value);
void        out16r(unsigned int, unsigned short value);
unsigned long    in32(unsigned int);
unsigned long    in32r(unsigned int);
void        out32(unsigned int, unsigned long value);
void        out32r(unsigned int, unsigned long value);
void        ppcDcbf(unsigned long value);
void        ppcDcbi(unsigned long value);
void        ppcSync(void);
void        ppcDcbz(unsigned long value);
#endif

#if defined (CONFIG_MPC83XX)
void        ppcDWload(unsigned int *addr, unsigned int *ret);
void        ppcDWstore(unsigned int *addr, unsigned int *value);
#endif

/* $(CPU)/cpu.c */
int    checkcpu      (void);
int    checkicache   (void);
int    checkdcache   (void);
void    upmconfig     (unsigned int, unsigned int *, unsigned int);
ulong    get_tbclk     (void);
void    reset_cpu     (ulong addr);

/* $(CPU)/serial.c */
int    serial_init   (void);
void    serial_addr   (unsigned int);
void    serial_setbrg (void);
void    serial_putc   (const char);
void    serial_putc_raw(const char);
int    serial_getc   (void);
int    serial_tstc   (void);

void    _serial_setbrg (const int);
void    _serial_putc   (const char, const int);
void    _serial_putc_raw(const char, const int);
void    _serial_puts   (const char *, const int);
int    _serial_getc   (const int);
int    _serial_tstc   (const int);

/* $(CPU)/speed.c */
int    get_clocks (void);
int    get_clocks_866 (void);
int    sdram_adjust_866 (void);
int    adjust_sdram_tbs_8xx (void);
#if defined(CONFIG_8260)
int    prt_8260_clks (void);
#elif defined(CONFIG_MPC83XX)
int print_clock_conf(void);
#elif defined(CONFIG_MPC5xxx)
int    prt_mpc5xxx_clks (void);
#endif
#if defined(CONFIG_MPC8220)
int    prt_mpc8220_clks (void);
#endif
#ifdef CONFIG_4xx
ulong    get_OPB_freq (void);
ulong    get_PCI_freq (void);
#endif
void uart_printf(const char *fmt,...);
void uart_putc(int  c);

#if defined(CONFIG_S3C2400) || defined(CONFIG_S3C2410) || defined(CONFIG_LH7A40X)
ulong    get_FCLK (void);
ulong    get_HCLK (void);
ulong    get_UCLK (void);
#endif
unsigned long    get_PCLK (void);

#if defined(CONFIG_LH7A40X)
ulong    get_PLLCLK (void);
#endif
#if defined CONFIG_INCA_IP
uint    incaip_get_cpuclk (void);
#endif
#if defined(CONFIG_IMX)
ulong get_systemPLLCLK(void);
ulong get_FCLK(void);
ulong get_HCLK(void);
ulong get_BCLK(void);
ulong get_PERCLK1(void);
ulong get_PERCLK2(void);
ulong get_PERCLK3(void);
#endif
ulong    get_bus_freq  (ulong);

#if defined(CONFIG_MPC85xx)
typedef MPC85xx_SYS_INFO sys_info_t;
void    get_sys_info  ( sys_info_t * );
#endif
#if defined(CONFIG_MPC86xx)
typedef MPC86xx_SYS_INFO sys_info_t;
void   get_sys_info  ( sys_info_t * );
#endif

#if defined(CONFIG_4xx) || defined(CONFIG_IOP480)
#  if defined(CONFIG_440)
    typedef PPC440_SYS_INFO sys_info_t;
#    if defined(CONFIG_440SPE)
     unsigned long determine_sysper(void);
     unsigned long determine_pci_clock_per(void);
     int ppc440spe_revB(void);
#    endif
#  else
    typedef PPC405_SYS_INFO sys_info_t;
#  endif
void    get_sys_info  ( sys_info_t * );
#endif

/* $(CPU)/cpu_init.c */
#if defined(CONFIG_8xx) || defined(CONFIG_8260)
void    cpu_init_f    (volatile immap_t *immr);
#endif
#if defined(CONFIG_4xx) || defined(CONFIG_MPC85xx) || defined(CONFIG_MCF52x2) ||defined(CONFIG_MPC86xx)
void    cpu_init_f    (void);
#endif

int    cpu_init_r    (void);
#if defined(CONFIG_8260)
int    prt_8260_rsr  (void);
#endif

/* $(CPU)/interrupts.c */
int    interrupt_init       (void);
void    timer_interrupt       (struct pt_regs *);
void    external_interrupt (struct pt_regs *);
void    irq_install_handler(int, interrupt_handler_t *, void *);
void    irq_free_handler   (int);
void    reset_timer       (void);
ulong    get_timer       (ulong base);
void    set_timer       (ulong t);
void    enable_interrupts  (void);
int    disable_interrupts (void);

/* $(CPU)/.../commproc.c */
int    dpram_init (void);
uint    dpram_base(void);
uint    dpram_base_align(uint align);
uint    dpram_alloc(uint size);
uint    dpram_alloc_align(uint size,uint align);
void    post_word_store (ulong);
ulong    post_word_load (void);
void    bootcount_store (ulong);
ulong    bootcount_load (void);
#define BOOTCOUNT_MAGIC        0xB001C041

/* $(CPU)/.../<eth> */
void mii_init (void);

/* $(CPU)/.../lcd.c */
ulong    lcd_setmem (ulong);

/* $(CPU)/.../vfd.c */
ulong    vfd_setmem (ulong);

/* $(CPU)/.../video.c */
ulong    video_setmem (ulong);

/* lib_$(ARCH)/cache.c */
void    flush_cache   (unsigned long, unsigned long);


/* lib_$(ARCH)/ticks.S */
unsigned long long get_ticks(void);
void    wait_ticks    (unsigned long);

/* lib_$(ARCH)/time.c */
ulong    usec2ticks    (unsigned long usec);
ulong    ticks2usec    (unsigned long ticks);
int    init_timebase (void);

/* lib_generic/vsprintf.c */
ulong    simple_strtoul(const char *cp,char **endp,unsigned int base);
#ifdef CFG_64BIT_VSPRINTF
unsigned long long    simple_strtoull(const char *cp,char **endp,unsigned int base);
#endif
long    simple_strtol(const char *cp,char **endp,unsigned int base);
void    panic(const char *fmt, ...);
int    sprintf(char * buf, const char *fmt, ...);
int    vsprintf(char *buf, const char *fmt, va_list args);

/* lib_generic/crc32.c */
ulong crc32 (ulong, const unsigned char *, uint);
ulong crc32_no_comp (ulong, const unsigned char *, uint);

/* common/console.c */
int    console_init_f(void);    /* Before relocation; uses the serial  stuff    */
int    console_init_r(void);    /* After  relocation; uses the console stuff    */
int    console_assign (int file, char *devname);    /* Assign the console    */
int    ctrlc (void);
int    had_ctrlc (void);    /* have we had a Control-C since last clear? */
void    clear_ctrlc (void);    /* clear the Control-C condition */
int    disable_ctrlc (int);    /* 1 to disable, 0 to enable Control-C detect */

/*
 * STDIO based functions (can always be used)
 */

/* serial stuff */
void    serial_printf (const char *fmt, ...);

/* stdin */
int    getc(void);
int    tstc(void);

/* stdout */
void    putc(const char c);
void    puts(const char *s);
void    printf(const char *fmt, ...);
void    vprintf(const char *fmt, va_list args);

/* stderr */
#define eputc(c)        fputc(stderr, c)
#define eputs(s)        fputs(stderr, s)
#define eprintf(fmt,args...)    fprintf(stderr,fmt ,##args)

/*
 * FILE based functions (can only be used AFTER relocation!)
 */

#define stdin        0
#define stdout        1
#define stderr        2
#define MAX_FILES    3

void    fprintf(int file, const char *fmt, ...);
void    fputs(int file, const char *s);
void    fputc(int file, const char c);
int    ftstc(int file);
int    fgetc(int file);

int    pcmcia_init (void);

#ifdef CONFIG_SHOW_BOOT_PROGRESS
void    show_boot_progress (int status);
#endif

#ifdef CONFIG_INIT_CRITICAL
#error CONFIG_INIT_CRITICAL is deprecated!
#error Read section CONFIG_SKIP_LOWLEVEL_INIT in README.
#endif

#endif    /* __COMMON_H_ */
