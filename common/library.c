/**************************************************************************************
* 
*	Project Name : S3C6410 Validation
*
*	Copyright 2006~2008 by Samsung Electronics, Inc.
*	All rights reserved.
*
*	Project Description :
*		This software is only for validating functions of the S3C6410.
*		Anybody can use this software without our permission.
*  
*--------------------------------------------------------------------------------------
* 
*	File Name : library.c
*  
*	File Description : This file implements library functions.
*
*	Author : Haksoo,Kim
*	Dept. : AP Development Team
*	Created Date : 2006/11/08
*	Version : 0.1 
* 
*	History
*	- Created(Haksoo,Kim 2006/11/08)
*	- Added DownloadImageThruUsbOtg function (Haksoo,Kim 2007/01/24)
*	- Edited RPRINTF (OnPil,Shin (SOP) 2008/03/01)
*	- Added Pause() by OnPil, Shin (SOP) on 2008/03/04
*  
**************************************************************************************/

#include <linux/string.h>
#include <stdarg.h>

#include "library.h"
#include "gpio.h"
//////////
// Function Name : InitUartPort
// Function Description : This function initializes gpio for debugging uart ch.
// Input :  ch, uart ch number
//			flowControl, whether flow control or not
// Output : NONE
// Version :
void InitUartPort(u8 ch, u8 flowControl)
{
	switch (ch)
	{
		default:
		case 0:
			if(flowControl == TRUE)
			{
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_0, 2);
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_1, 2);
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_2, 2);
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_3, 2);
			}
			else
			{
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_0, 2);
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_1, 2);
			}
			break;
			
		case 1:
			if(flowControl == TRUE)
			{
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_4, 2);
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_5, 2);
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_6, 2);
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_7, 2);
			}
			else
			{
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_4, 2);
				GPIO_SetFunctionEach(eGPIO_A, eGPIO_5, 2);
			}
			break;
			
		case 2:
			GPIO_SetFunctionEach(eGPIO_B, eGPIO_0, 2);
			GPIO_SetFunctionEach(eGPIO_B, eGPIO_1, 2);
			break;
			
		case 3:
			GPIO_SetFunctionEach(eGPIO_B, eGPIO_2, 2);
			GPIO_SetFunctionEach(eGPIO_B, eGPIO_3, 2);
			break;		
	}
	
	return;	
}

//////////
// Function Name : InitLED
// Function Desctiption : This function initializes gpio for debugging LED
// Input : NONE
// Output : NONE
// Version :
void InitLED(void)
{
	GPIO_SetFunctionEach(eGPIO_N, eGPIO_12, 1);
	GPIO_SetFunctionEach(eGPIO_N, eGPIO_13, 1);
	GPIO_SetFunctionEach(eGPIO_N, eGPIO_14, 1);
	GPIO_SetFunctionEach(eGPIO_N, eGPIO_15, 1);	
	return;
}

//////////
// Function Name : DisplayLED
// Function Desctiption : This function controls debugging LED
// Input : data, LED value 
// Output : NONE
// Version :
void DisplayLED(u8 data)
{
	u32 temp;

	temp = GPIO_GetDataAll(eGPIO_N);
	temp = (temp & ~(0xf000))|((data&0xf)<<12);
	GPIO_SetDataAll(eGPIO_N, temp);

	return;
}


//////////
// Function Name : OpenConsole
// Function Description : This function opens uart and LED for debugging
// Input : NONE
// Output : NONE
// Version : 
void OpenConsole( void)
{	
	u8 ch=0;	//uart channel for debugging
	
	InitUartPort(ch, FALSE);
	UART_InitDebugCh(ch, 115200);
//	InitLED();

	return;
}


//////////
// Function Name : Delay
// Function Description : 
// Input : usec, time in 100us unit
// Output : NONE
// Version : 
u32 delayLoopCount;
void Delay(u32 usec)
{
	u32 i=0;
    
    for(;usec>0;usec--)
    {
    	for(i=0;i<delayLoopCount;i++);
    }
}

//////////
// Function Name : Pow
// Function Description : Calculates x raise to the power of y
// Input : x, y
// Output : uResult - result value
// Version : 
u32 Pow(u32 x, u32 y)
{
    u32 i, uResult = 1;
    
    for(i=0 ; i<y ; i++)
    {
    	uResult = uResult*x;
    }
    
    return uResult;
}  

//////////
// Function Name : Copy
// Function Description : Copy from src address to dst address by words count
// Input : sa, da, words
// Output : void
// Version : 
void Copy(u32 sa, u32 da, u32 words)
{
	u32 i;	
	for (i=0; i<words; i++)
		*(u32 *)(da+i*4) = *(u32 *)(sa+i*4);
}

//////////
// Function Name : Copy8
// Function Description : Copy from src address to dst address by bytes count
// Input : sa, da, bytes
// Output : void
// Version : 
void Copy8(u32 sa, u32 da, u32 bytes)
{
	u32 i;
	for (i=0; i<bytes; i++)
		*(u8 *)(da+i) = *(u8 *)(sa+i);
}

//////////
// Function Name : Copy16
// Function Description : Copy from src address to dst address by bytes count
// Input : sa, da, bytes
// Output : void
// Version : 
void Copy16(u32 sa, u32 da, u32 Hwords)
{
	u32 i;
	for (i=0; i<Hwords; i++)
		*(u16 *)(da+i*2) = *(u16 *)(sa+i*2);
}

//////////
// Function Name : Compare
// Function Description : compare data
// Input : a0, a1, words
// Output : ret
// Version : 
u8 Compare( u32 a0,  u32 a1,  u32 words)
{
	volatile u32 d0,d1;
	volatile u32 *pD0, *pD1;
	u8 ret = true;
	u32  ecnt = 0;
	u32 i;
	
	pD0 = (volatile u32 *)(a0);
	pD1 = (volatile u32 *)(a1);
	
	//UART_Printf("\n");	

	for (i=0; i<words; i++)
	{
		
		d0=*pD0;
		d1=*pD1;

		if (d0!= d1) 
		{
			ret = false;
			UART_Printf(" %08x=%08x <-> %08x=%08x\n", pD0, d0, pD1, d1);
			ecnt++;
		}
		pD0++;
		pD1++;
	}
/*
	if (ret == false)
	{
		Assert(0);		
		UART_Printf("\n");
	}
*/
	return ret;
}

//////////
// Function Name : Dump32
// Function Description : dump data
// Input : addr, words
// Output : ret
// Version : 
void Dump32(u32 addr, u32 words)
{
	int i, j;
	u32 *pMem;

	pMem = (u32 *)(addr/4*4);

	UART_Printf("\n");
	for(i=0; i<words; )
	{
		UART_Printf(" %04x: ", i);

		for(j=0; j<8; j++)
			UART_Printf("%08x ", *pMem++),
			i++;
		UART_Printf("\n");
	}
}

//////////
// Function Name : Dump16
// Function Description : dump data
// Input : addr, hwords
// Output : ret
// Version : 
void Dump16(u32 addr, u32 hwords)
{
	int i, j;
	u16 *pMem;

	pMem = (u16 *)(addr/2*2);

	UART_Printf("\n");
	for(i=0; i<hwords; )
	{
		UART_Printf(" %04x: ", i);

		for(j=0; j<16; j++)
			UART_Printf("%04x ", *pMem++),
			i++;
		UART_Printf("\n");
	}
}


//////////
// Function Name : Dump8
// Function Description : dump data
// Input : addr, bytes
// Output : ret
// Version :
void Dump8(u32 addr, u32 bytes)
{
	int i, j;
	u8 *pMem;

	pMem = (u8 *)addr;

	UART_Printf("\n");
	for(i=0; i<bytes; )
	{
		UART_Printf(" %04x: ", i);

		for(j=0; j<16; j++)
			UART_Printf("%02x ", *pMem++),
			i++;
		UART_Printf("\n");
	}
}

//////////
// Function Name : Stop
// Function Description : This function is called from "Assert"
// Version : 
void Stop(void) 
{ 
	while(1); 
}

//added by rb1004...2007.03.09
void UART_Printf(const char *fmt,...)
{
	va_list ap;
	char string[256];
	int i;

	va_start(ap, fmt);
	vsprintf(string, fmt, ap);
	for (i = 0; string[i]; i++) {
		UART_Putc(string[i]);
	}
	va_end(ap);
}

//////////
// Function Name : Pause
// Function Description : This function is Pause
// Input :  none
// Output : none
// Version : 0.1
void Pause(void)			// Added by SOP on 2008/03/04
{
	UART_Printf("\nPress any key continue ...\n");
	UART_Getc();
}
