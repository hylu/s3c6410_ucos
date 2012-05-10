/**************************************************************************************
* 
*	Project Name : S3C6400 Validation
*
*	Copyright 2006 by Samsung Electronics, Inc.
*	All rights reserved.
*
*	Project Description :
*		This software is only for validating functions of the S3C6400.
*		Anybody can use this software without our permission.
*  
*--------------------------------------------------------------------------------------
* 
*	File Name : timer.c
*  
*	File Description : This file implements the API functons for Timer (PWM, WDT).
*
*	Author : Woojin.Kim
*	Dept. : AP Development Team
*	Created Date : 2006/12/27
*	Version : 0.1 
* 
*	History"
*	- Created(Woojin.Kim 2006/12/27)
*     - Added DelayfrTimer(Woojin.Kim 2007/02/12)
*     - Added Start, Stoptimer (Woojin,Kim 2007/02/15)
*	- Added CalibrateDelay(Haksoo,Kim 2007/02/17)
**************************************************************************************/

#include "option.h"
#include "library.h"
#include "sfr6410.h"
#include "system.h"
#include "timer.h"
#include "intc.h"
#include "sysc.h"
#include "gpio.h"

#include <common.h>

// Interrupt Handler Global valiable
   volatile u32 g_uIntCounterOS = 0;
   volatile u32 g_uIntCounter0 = 0;
   volatile u32 g_uIntCounter1 = 0;
   volatile u32 g_uIntCounter2 = 0;
   volatile u32 g_uIntCounter3 = 0;
   volatile u32 g_uIntCounter4 = 0;
   volatile u32 g_uIntCounterWT = 0;
   volatile u32 g_PWMDmaDone;


//////////
// Function Name : PWM_Select
// Function Description : This function set up Timers by function inputs
// Input :	uTimer [0~4]
//			uPrescaler [1~256]
//			uDivider [0:1/1	1:1/2	2:1/4	3:1/8	4:1/16	5:extCLK]
//			uTCNTB [1~2^31]
//			uTCMPB [1~2^31]
//			uEnDz, uEnDMA, uAutoreload, uEnInverter, uEnInt [0:Disable	1:Enbale]
//			uDzlen [0~255]
// Output : NONE
// Version : v0.1

void PWM_Select(u32 uTimer,u32 uPrescaler,u32 uDivider,u32 uTCNTB,u32 uTCMPB,u32 uEnDz,u32 uDzlen,u32 uEnDMA,u32 uAutoreload,u32 uEnInverter,u32 uEnInt)
{

	u32	uTemp0;
	u32	uTemp1;
	u32	uTemp2;
	u32  uTemp3;
	

		if(uEnDMA == 1)
			{
				uEnDMA = uTimer + 1;
			}
		

		uTemp0 = Inp32(rTCFG1);
		uTemp0 = (uTemp0 & (~(0xf<<4*uTimer))& (~(1<<20))) |(uEnDMA<<20)|(uDivider<<4*uTimer);
		Outp32(rTCFG1,uTemp0);

		uTemp0 = Inp32(rTINT_CSTAT);
		uTemp0 = (uTemp0 & (~(1<<uTimer)))|(uEnInt<<(uTimer));
		Outp32(rTINT_CSTAT,uTemp0);

		switch(uTimer)
			{
			case 0:													//Timer0
				uTemp0 = Inp32(rTCON);
				uTemp0 = uTemp0 & (0xfffffffe);
				Outp32(rTCON, uTemp0); 								// Timer0 stop

				uTemp0 = Inp32(rTCFG0);
				uTemp0 = (uTemp0 & (~(0xff00ff))) | ((uPrescaler-1)<<0) |(uDzlen<<16);
				Outp32(rTCFG0, uTemp0);
				
				Outp32(rTCNTB0, uTCNTB);
				Outp32(rTCMPB0, uTCMPB);


				uTemp1 = Inp32(rTCON);
				uTemp1 = (uTemp1 & (~(0x1f))) |(uEnDz<<4)|(uAutoreload<<3)|(uEnInverter<<2)|(1<<1)|(0<<0);
				Outp32(rTCON, uTemp1);									//timer0 manual update
				uTemp1 = (uTemp1 & (~(0x1f))) |(uEnDz<<4)|(uAutoreload<<3)|(uEnInverter<<2)|(0<<1)|(1<<0);				
				Outp32(rTCON, uTemp1);									// timer0 start

				break;
			case 1:													//Timer1
				uTemp0 = Inp32(rTCON);
				uTemp0 = uTemp0 & (0xfffffeff);
				Outp32(rTCON, uTemp0); 								// Timer1 stop

				uTemp0 = Inp32(rTCFG0);
				uTemp0 = (uTemp0 & (~(0xff00ff))) | ((uPrescaler-1)<<0) |(uDzlen<<16);
				Outp32(rTCFG0, uTemp0);
				
				Outp32(rTCNTB1, uTCNTB);
				Outp32(rTCMPB1, uTCMPB);

				uTemp1 = Inp32(rTCON);
				uTemp1 = (uTemp1 & (~(0xf00))) | (uAutoreload<<11)|(uEnInverter<<10)|(1<<9)|(0<<8);
				Outp32(rTCON,uTemp1); 									// timer1 manual update
				uTemp1 = (uTemp1 & (~(0xf00))) | (uAutoreload<<11)|(uEnInverter<<10)|(0<<9)|(1<<8);				
				Outp32(rTCON,uTemp1); 									// timer1 start


				break;
					
			case 2:													//Timer2
				uTemp0 = Inp32(rTCON);
				uTemp0 = uTemp0 & (0xffffefff);
				Outp32(rTCON, uTemp0); 								// Timer2 stop

				uTemp2 = Inp32(rTCFG0);
				uTemp2 = (uTemp2 & (~(0xffff00)))|((uPrescaler-1)<<8)|(uDzlen<<16);
				Outp32(rTCFG0, uTemp2);
				
				Outp32(rTCNTB2, uTCNTB);
				Outp32(rTCMPB2, uTCMPB);

				uTemp3 = Inp32(rTCON);
				uTemp3 = (uTemp3 & (~(0xf000)))|(uAutoreload<<15)|(uEnInverter<<14)|(1<<13)|(0<<12);
				Outp32(rTCON, uTemp3); 								// timer2 manual update

				uTemp3 = (uTemp3 & (~(0xf000)))|(uAutoreload<<15)|(uEnInverter<<14)|(0<<13)|(1<<12);
				Outp32(rTCON,uTemp3);									 // timer2 start

				break;
				
			case 3:														//Timer3
				uTemp0 = Inp32(rTCON);
				uTemp0 = uTemp0 & (0xfffeffff);
				Outp32(rTCON, uTemp0);									 // Timer3 stop

				uTemp2 = Inp32(rTCFG0);
				uTemp2 = (uTemp2 & (~(0xffff00)))|((uPrescaler-1)<<8)|(uDzlen<<16);
				Outp32(rTCFG0, uTemp2);
				
				Outp32(rTCNTB3, uTCNTB);
				Outp32(rTCMPB3, uTCMPB);

				uTemp3 = Inp32(rTCON);
				uTemp3 = (uTemp3 &(~(0xf0000)))|(uAutoreload<<19)|(uEnInverter<<18)|(1<<17)|(0<<16);
				Outp32(rTCON, uTemp3); 								// timer3 manual update
				uTemp3 = (uTemp3 &(~(0xf0000)))|(uAutoreload<<19)|(uEnInverter<<18)|(0<<17)|(1<<16);
				Outp32(rTCON,uTemp3); 									// timer3 start

				break;

			case 4:														//Timer4
				uTemp0 = Inp32(rTCON);
				uTemp0 = uTemp0 & (0xffefffff);
				Outp32(rTCON, uTemp0);									 // Timer4 stop
				
				uTemp2 = Inp32(rTCFG0);
				uTemp2 = (uTemp2 & (~(0xffff00)))|((uPrescaler-1)<<8)|(uDzlen<<16);
				Outp32(rTCFG0, uTemp2);
				
				Outp32(rTCNTB4, uTCNTB);

				uTemp3 = Inp32(rTCON);
				uTemp3 = (uTemp3 & (~(0xf00000)))|(uAutoreload<<22)|(1<<21)|(0<<20);
				Outp32(rTCON,uTemp3); 									// timer4 manual update

				uTemp3 = (uTemp3 & (~(0xf00000)))|(uAutoreload<<22)|(0<<21)|(1<<20);				
				Outp32(rTCON, uTemp3);									 // timer4 start

				break;

			}

#if 0					// Print out Timer Clock & Frequency for debugging


		//(1/(PCLK/(Prescaler+1)/divider) * count(Max 65535) = Timer clock (Frequency)

		UART_Printf("Timer = %d\n",uTimer);
		UART_Printf("nPCLK = %d , uPrescaler = %d, uDivider = %d dd= %d\n",g_PCLK,uPrescaler,uDivider,(1<<(uDivider)));
		fTimerclk = (1/(float)((float)g_PCLK/((float)uPrescaler)/(1<<(uDivider))))*uTCNTB*1000;
		fTimerfreq = 1/fTimerclk;

		UART_Printf("Timer Clock = %f msec , Timer Frequency = %f Khz\n\n",fTimerclk,fTimerfreq);

#endif		

}


//////////
// Function Name : PWM_stopAll
// Function Description : This function stops All timers
// Input : NONE
// Output : NONE
// Version : v0.1
void PWM_stopAll(void)
{
	Outp32(rTCON,0);
}


//////////
// Function Name : PWM_stop
// Function Description : This function stops timer individually
// Input : nNum [0:timer0   1:timer1   2:timer2   3:timer3]
// Output : NONE
// Version : v0.1
void PWM_stop(u32 uNum)
{
	u32 uTemp;

	uTemp = Inp32(rTCON);

	if(uNum == 0)
			uTemp &= ~(0x1);
	else
			uTemp &= ~((0x10)<<(uNum*4));
		
	Outp32(rTCON,uTemp);
}


//////////
// Function Name : PWM_ReadrTCMPB
// Function Description : This function read out rTCMPB value
// Input : nNum [0:timer0   1:timer1   2:timer2   3:timer3]
// Output : rTCMPB value
// Version : v0.1
u32 PWM_ReadrTCMPB(u32 uNum)
{
	u32 RegTmp;

	switch(uNum)
		{
		case 0:
			RegTmp = Inp32(rTCMPB0);
			break;
			
		case 1:
			RegTmp = Inp32(rTCMPB1);
			break;			
			
		case 2:
			RegTmp = Inp32(rTCMPB2);
			break;
			
		case 3:
			RegTmp = Inp32(rTCMPB3);	
			break;			
		}
	return RegTmp;
	
}


//////////
// Function Name : WDT_operate
// Function Description : This function operate Watchdog Timer by Input
// Input :	uEnReset, uEnInt, uEnWDT [0:Disable		1:Enbale]
//			uSelectCLK (clk division factor) [0:16		1:32		2:64		3:128]
//			uPrescaler [1~256]
//			uWTDAT [0~2^15]
//			uWTCNT [0~2^15]   
// Output : NONE
// Version : v0.1

void WDT_operate(u32 uEnReset, u32 uEnInt, u32 uSelectCLK, u32 uEnWDT, u32 uPrescaler,u32 uWTDAT, u32 uWTCNT)
{

	float fWDTclk;


	
	Outp32(rWTCON,0);
	Outp32(rWTDAT,0);
	Outp32(rWTCNT,0);
	Outp32(rWTDAT,uWTDAT);
	Outp32(rWTCNT,uWTCNT);
	Outp32(rWTCON,(uEnReset<<0)|(uEnInt<<2)|(uSelectCLK<<3)|(uEnWDT<<5)|((uPrescaler)<<8));

	fWDTclk = (1/(float)((float)g_PCLK/((float)uPrescaler+1)/(1<<(uSelectCLK+4))))*uWTDAT;
	UART_Printf("WDT_clk = %f sec\n",fWDTclk);


}



//////////
// Function Name : Isr_TIMEROS
// Function Description : This function is Interrupt Service Routine of PWM Timer0
// Input : NONE
// Output : NONE (increment of g_uIntCounter0 value)
// Version : v0.1

void Isr_TIMEROS(void)
{
	u32 uTmp;
	u32 uCnt;
	
	uTmp = Inp32(rTINT_CSTAT);

	for(uCnt = 0 ; uCnt <50 ; uCnt++)
	UART_Printf("#%d : rTINT_CSTAT = %x\n",uCnt,uTmp);

	
//	uTmp = (uTmp & 0x1f)| (1<<5);
	Outp32(rTINT_CSTAT,uTmp);       //  Timer0 Interrupt Clear register
    
	UART_Printf("Timer0\n");
	UART_Printf("IntCounter = %d \n ",g_uIntCounterOS);
	
	g_uIntCounterOS++;

	INTC_ClearVectAddr();

}


//////////
// Function Name : Isr_TIMER0
// Function Description : This function is Interrupt Service Routine of PWM Timer0
// Input : NONE
// Output : NONE (increment of g_uIntCounter0 value)
// Version : v0.1

void Isr_TIMER0(void)
{
	u32 uTmp;
	
	uTmp = Inp32(rTINT_CSTAT);
	uTmp = (uTmp & 0x1f)| (1<<5);
	Outp32(rTINT_CSTAT,uTmp);       //  Timer0 Interrupt Clear register
    
	UART_Printf("Timer0\n");
	g_uIntCounter0++;

	INTC_ClearVectAddr();
	OSTimeTick();
}


//////////
// Function Name : Isr_TIMER1
// Function Description : This function is Interrupt Service Routine of PWM Timer0
// Input : NONE
// Output : NONE (increment of g_uIntCounter0 value)
// Version : v0.1
void Isr_TIMER1(void)
{
 	u32 uTmp;
	
	uTmp = Inp32(rTINT_CSTAT);
	uTmp = (uTmp & 0x1f) | (1<<6);
	Outp32(rTINT_CSTAT,uTmp);      //  Timer1 Interrupt Clear register
    
	UART_Printf("Timer1\n");
	g_uIntCounter1++;
	
	INTC_ClearVectAddr();    

}


//////////
// Function Name : Isr_TIMER2
// Function Description : This function is Interrupt Service Routine of PWM Timer0
// Input : NONE
// Output : NONE (increment of g_uIntCounter0 value)
// Version : v0.1
void Isr_TIMER2(void)
{
	u32 uTmp;
	
	uTmp = Inp32(rTINT_CSTAT);
	uTmp = (uTmp & 0x1f) |(1<<7);
	Outp32(rTINT_CSTAT,uTmp);       //  Timer2 Interrupt Clear register

	UART_Printf("Timer2\n");
	 g_uIntCounter2++;

	INTC_ClearVectAddr();    

}


//////////
// Function Name : Isr_TIMER3
// Function Description : This function is Interrupt Service Routine of PWM Timer0
// Input : NONE
// Output : NONE (increment of g_uIntCounter0 value)
// Version : v0.1
void Isr_TIMER3(void)
{
	u32 uTmp;
	
	uTmp = Inp32(rTINT_CSTAT);
	uTmp = (uTmp & 0x1f) | (1<<8);
	Outp32(rTINT_CSTAT,uTmp);       //  Timer3 Interrupt Clear register
    
	UART_Printf("Timer3\n");
	g_uIntCounter3++;
	
	INTC_ClearVectAddr();    

}


//////////
// Function Name : Isr_TIMER4
// Function Description : This function is Interrupt Service Routine of PWM Timer0
// Input : NONE
// Output : NONE (increment of g_uIntCounter0 value)
// Version : v0.1
void Isr_TIMER4(void)
{
	u32 uTmp;
	
	uTmp = Inp32(rTINT_CSTAT);
	uTmp = (uTmp & 0x1f) | (1<<9);
	Outp32(rTINT_CSTAT,uTmp);       //  Timer4 Interrupt Clear register

	UART_Printf("Timer4\n");     
	g_uIntCounter4++;

    
	INTC_ClearVectAddr();    
	OSTimeTick();
}


//////////
// Function Name : Isr_WDT
// Function Description : This function is Interrupt Service Routine of WatchDog Timer
// Input : NONE
// Output : NONE (increment of g_uIntCounterWT value)
// Version : v0.1
void Isr_WDT(void)
{

	Outp32(rWTCLRINT ,1);    // Watchdog timer interrupt clear 	
	g_uIntCounterWT++;
	
	UART_Printf("%d ", g_uIntCounterWT);
	 
	INTC_ClearVectAddr();    
}



////////////////////////////////Optional Functions////////////////////////////////////

//////////
// Function Name : DelayfrTimer
// Function Description : This function make delay which is multiplex of uDnum * 1msec
//                                ex) DelayfrTimer(1) delay 1msec
//                                ex) DelayfrTimer(1000) delay 1sec

// Input : 			cMeasure [milli : milli sec,   micro: micro sec]
// 					uDnum [uDnum : 1 = 1msec, 10=10msec, 100 = 100msec when cMeasure = milli]
// Output : NONE
// Version : v0.1
void DelayfrTimer(eDelay_M cMeasure, u32 uDnum)
{
	u32 uCnt;
	
	PWM_stop(2);							// Using PWM timer #2


	if( cMeasure == micro )
		{
			uCnt = g_PCLK/1000000;
			
			PWM_Select(2,uCnt,0,0xffffffff,(u32)(0xffffffff/2),0,0,0,1,0,0); // Timer2,Divider =1/1, Prescaler = g_PCLK/1M

			while(1)
				{	
					if((0xffffffff-Inp32(rTCNTO2)) == uDnum)
						break;
				}	

		}

	else if( cMeasure == milli )
		{

			uCnt = g_PCLK/1000000;
			
			PWM_Select(2,uCnt,0,0xffffffff,(u32)(0xffffffff/2),0,0,0,1,0,0); // Timer2,Divider =1/1, Prescaler = g_PCLK/1M

//			while(!(Inp32(rTCNTO0)==0xffffffff))

			while(1)
				{	
					if((0xffffffff-Inp32(rTCNTO2)) == (uDnum*1000))
						break;
				}	
	

		}

		PWM_Select(2,uCnt,0,0xffffffff,(u32)(0xffffffff/2),0,0,0,1,0,0); // Timer2,Divider =1/1, Prescaler = g_PCLK/1M
//		PWM_stop(2);	
}


//////////
// Function Name : StartTimer
// Function Description : This function is counting time util StopTimer function operated by MICRO second measurement
// Input : uTsel [Timer0~2 that you want to use ] [Time3 is Using PWM_EXT]
// Output : NONE
// Version : v0.1

void StartTimer(u32 uTsel)
{
	u32 uCnt;

	uCnt = g_PCLK/1000000;

	if(uTsel == 3)
		PWM_Select(uTsel,uCnt,5,0xffffffff,(u32)(0xffffffff/2),0,0,0,1,0,0);	//timer0,prescaler=PCLK/1M,divider=1/1,autoreload

	else
		PWM_Select(uTsel,uCnt,0,0xffffffff,(u32)(0xffffffff/2),0,0,0,1,0,0);	//timer0,prescaler=PCLK/1M,divider=1/1,autoreload

}


//////////
// Function Name : StopTimer
// Function Description : This function returns Time count which's started by StartTimer function
// Input : uTsel [Timer0~3 that you want to use ]
// Output : Count value [uVal micro second]
// Version : v0.1

u32 StopTimer(u32 uTsel)
{
	u32 uVal;
	
	PWM_stop(uTsel);

	uVal = 0xffffffff - (Inp32(rTCNTO0+(uTsel*12)));

	return uVal;
}


//////////
// Function Name : CalibrateDelay
// Function Description : This function calibrates delayLoopCount as about 100us by using WDT
// Input : NONE 
// Output : NONE
// Version : 

extern u32 delayLoopCount;
void CalibrateDelay(void)
{
	u32 i, tmpDelay=100;
	u32 uPCLK_MHz=g_PCLK/1000000;
	
	delayLoopCount = 5000;
	
	Outp32(rWTCON, (uPCLK_MHz-1)<<8);
	Outp32(rWTDAT, 0xffff);						//for first update
	Outp32(rWTCNT, 0xffff);						//resolution=16us @any PCLK 
	Outp32(rWTCON, ((uPCLK_MHz-1)<<8)|(1<<5));	//Watch-dog timer start
	
	for(;tmpDelay>0;tmpDelay--)
		for(i=0;i<delayLoopCount;i++);
	
	Outp32(rWTCON, (uPCLK_MHz-1)<<8);   		//Watch-dog timer stop
	i = 0xffff - Inp32(rWTCNT);                 // 1count->16us, 100*5000 cycle runtime = 
	delayLoopCount = 50000000/(i*16);         	//100*5000:16*i[us]=1*x:100[us] -> x=50000000/(16*i)

}

extern char __ENTRY[];
void TIMER_OSREQUEST(void)
{
	int i;
	unsigned long *p;
	unsigned long tv;

	S3C64XX_INTERRUPT *const interrupt0 = (S3C64XX_INTERRUPT *)0x71200000;
	S3C64XX_INTERRUPT *const interrupt1 = (S3C64XX_INTERRUPT *)0x71300000;
	S3C64XX_TIMERS *const timers = (S3C64XX_TIMERS *)0x7F006000;
	S3C64XX_GPN *const gpn = (S3C64XX_GPN *)0x7f008830;
	S3C64XX_EINT0 *const eint0 = (S3C64XX_EINT0 *)0x7f008900;
#if 0    
	p = (unsigned long *)0x71200100;
	for(i=0;i<32;i++)    
	{
		*p = (unsigned long)(__ENTRY + 0x18);
		p++ ;
	}
	p = (unsigned long *)0x71300100;
	for(i=0;i<32;i++)    
	{
		*p = (unsigned long)(__ENTRY+0x18);    
		p++;
	}
   
	gpn->GPNCON = 0xaaa;
	gpn->GPNPUD = 0xaaa; /*0 1 2 3 up pull*/
	eint0->CON0 = 0x444;
	eint0->FLTCON0= 0xcfcfcfcf;
	eint0->MASK = 0xffffffc0;

	interrupt0->INTSELECT = 0x00000000;        
	interrupt1->INTSELECT = 0x00000000;
#endif
	
//	timers->TCFG0 = 0x0f00;
	//tv = get_PCLK() / (2 * 16 * 100);
	//timers->TCNTB4 = tv; //0x512d;


#define TCON_4_AUTO        (1 << 22) 
#define TCON_4_UPDATE	    (1 << 21) 
#define TCON_4_ONOFF	    (1 << 20) 
#define COUNT_4_ON        (TCON_4_ONOFF*1)
#define _ISR_STARTADDRESS	0xc7ff7e00
#define pISR_TIMER4	    (*(unsigned *)(_ISR_STARTADDRESS+0x90))

	
	/* auto load, manual update of Timer 4 */
//	timers->TCON = (timers->TCON & ~0x00700000) | TCON_4_AUTO  | TCON_4_UPDATE;
	/* auto load, start Timer 4 */
//	timers->TCON = (timers->TCON & ~0x00700000) | TCON_4_AUTO  | COUNT_4_ON;
//	pISR_TIMER4 = (unsigned)Isr_TIMER4;
	
	// 打开TIMER4中断允许
//	timers->CSTAT |= 0x10;    
//	interrupt0->INTENABLE |= (1<<28); // enable timer4 
//	interrupt0->INTENABLE |= (3 << 0); // enable vic0_int0 vic0_int1
//	g_uIntCounter4 = 0;    
#if 1    
	PWM_stopAll();	// stop timers

	g_uIntCounter4 = 0;
	
//	pISR_TIMER4 = (unsigned)Isr_TIMER4;	
	INTC_SetVectAddr(NUM_TIMER4,Isr_TIMER4);
	INTC_Enable(NUM_TIMER4);
	
	PWM_Select(4,255,0,30000,15000,0,0,0,1,0,1);
#endif
//	INTC_Disable(NUM_TIMER0);

}

