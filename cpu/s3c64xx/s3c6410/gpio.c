/**************************************************************************************
* 
*	Project Name : S3C6410 Validation
*
*	Copyright 2006 by Samsung Electronics, Inc.
*	All rights reserved.
*
*	Project Description :
*		This software is only for validating functions of the S3C6410.
*		Anybody can use this software without our permission.
*  
*--------------------------------------------------------------------------------------
* 
*	File Name : gpio.c
*  
*	File Description : This file implements the API functons for GPIO.
*
*	Author : Heemyung.Noh
*	Dept. : AP Development Team
*	Created Date : 2006/12/26
*	Version : 0.1 
* 
*	History
*	- Created(Heemyung.Noh 2006/12/26)
*  
**************************************************************************************/
#include "sfr6410.h"
#include "gpio.h"

#define GPIO 		( ( volatile oGPIO_REGS * ) (GPIO_pBase) )


typedef struct tag_GPIO_REGS
{
	u32 rGPIOACON;			//0x7F008000
	u32 rGPIOADAT;
	u32 rGPIOAPUD;
	u32 rGPIOACONSLP;
	u32 rGPIOAPUDSLP;
	u32 reserved1[3];
	
	u32 rGPIOBCON;			//0x7F008020
	u32 rGPIOBDAT;
	u32 rGPIOBPUD;
	u32 rGPIOBCONSLP;
	u32 rGPIOBPUDSLP;	
	u32 reserved2[3];
		
	u32 rGPIOCCON;			//0x7F008040
	u32 rGPIOCDAT;
	u32 rGPIOCPUD;
	u32 rGPIOCCONSLP;
	u32 rGPIOCPUDSLP;	
	u32 reserved3[3];
		
	u32 rGPIODCON;			//0x7F008060
	u32 rGPIODDAT;
	u32 rGPIODPUD;
	u32 rGPIODCONSLP;
	u32 rGPIODPUDSLP;	
	u32 reserved4[3];
		
	u32 rGPIOECON;			//0x7F008080
	u32 rGPIOEDAT;
	u32 rGPIOEPUD;
	u32 rGPIOECONSLP;
	u32 rGPIOEPUDSLP;	
	u32 reserved5[3];
		
	u32 rGPIOFCON;			//0x7F0080A0
	u32 rGPIOFDAT;
	u32 rGPIOFPUD;
	u32 rGPIOFCONSLP;
	u32 rGPIOFPUDSLP;	
	u32 reserved6[3];
		
	u32 rGPIOGCON;			//0x7F0080C0
	u32 rGPIOGDAT;
	u32 rGPIOGPUD;
	u32 rGPIOGCONSLP;
	u32 rGPIOGPUDSLP;	
	u32 reserved7[3];
	
	u32 rGPIOHCON0;			//0x7F0080E0
	u32 rGPIOHCON1;
	u32 rGPIOHDAT;
	u32 rGPIOHPUD;
	u32 rGPIOHCONSLP;
	u32 rGPIOHPUDSLP;	
	u32 reserved8[2];

	u32 rGPIOICON;			//0x7F008100
	u32 rGPIOIDAT;
	u32 rGPIOIPUD;
	u32 rGPIOICONSLP;
	u32 rGPIOIPUDSLP;	
	u32 reserved9[3];

	u32 rGPIOJCON;			//0x7F008120
	u32 rGPIOJDAT;
	u32 rGPIOJPUD;
	u32 rGPIOJCONSLP;
	u32 rGPIOJPUDSLP;	
	u32 reserved10[3];
	
	u32 rGPIOOCON;			//0x7F008140
	u32 rGPIOODAT;
	u32 rGPIOOPUD;
	u32 rGPIOOCONSLP;
	u32 rGPIOOPUDSLP;	
	u32 reserved11[3];	

	u32 rGPIOPCON;			//0x7F008160
	u32 rGPIOPDAT;
	u32 rGPIOPPUD;
	u32 rGPIOPCONSLP;
	u32 rGPIOPPUDSLP;	
	u32 reserved12[3];

	u32 rGPIOQCON;			//0x7F008180
	u32 rGPIOQDAT;
	u32 rGPIOQPUD;
	u32 rGPIOQCONSLP;
	u32 rGPIOQPUDSLP;	
	u32 reserved13[3];	

	u32 rSPCON;				//0x7F0081A0
	u32 reserved14[3];
	u32 rMEM0CONSTOP;		//0x7F0081B0
	u32 rMEM1CONSTOP;		//0x7F0081B4
	u32 reserved15[2];
	u32 rMEM0CONSLP0;		//0x7F0081C0
	u32 rMEM0CONSLP1;		//0x7F0081C4
	u32 rMEM1CONSLP;		//0x7F0081C8
	u32 reserved;
	u32 rMEM0DRVCON;		//0x7F0081D0
	u32 rMEM1DRVCON;		//0x7F0081D4
	u32 reserved16[10];

	u32 rEINT12CON;			//0x7f008200
	u32 rEINT34CON;			//0x7f008204
	u32 rEINT56CON;			//0x7f008208
	u32 rEINT78CON;			//0x7f00820C
	u32 rEINT9CON;			//0x7f008210
	u32 reserved17[3];

	u32 rEINT12FLTCON;		//0x7f008220
	u32 rEINT34FLTCON;		//0x7f008224
	u32 rEINT56FLTCON;		//0x7f008228
	u32 rEINT78FLTCON;		//0x7f00822C
	u32 rEINT9FLTCON;		//0x7f008230
	u32 reserved18[3];

	u32 rEINT12MASK;		//0x7f008240
	u32 rEINT34MASK;		//0x7f008244
	u32 rEINT56MASK;		//0x7f008248
	u32 rEINT78MASK;		//0x7f00824C
	u32 rEINT9MASK;			//0x7f008250
	u32 reserved19[3];	

	u32 rEINT12PEND;		//0x7f008260
	u32 rEINT34PEND;		//0x7f008264
	u32 rEINT56PEND;		//0x7f008268
	u32 rEINT78PEND;		//0x7f00826C
	u32 rEINT9PEND;			//0x7f008270
	u32 reserved20[3];			

	u32 rPRIORITY;			//0x7f008280
	u32 rSERVICE;			//0x7f008284
	u32 rSERVICEPEND;		//0x7f008288
	u32 reserved21;

	u32 reserved22[348];
	
	u32 rGPIOKCON0;			//0x7f008800
	u32 rGPIOKCON1;			//0x7f008804
	u32 rGPIOKDAT;			//0x7f008808
	u32 rGPIOKPUD;			//0x7f00880c

	u32 rGPIOLCON0;			//0x7f008810
	u32 rGPIOLCON1;			//0x7f008814
	u32 rGPIOLDAT;			//0x7f008818
	u32 rGPIOLPUD;			//0x7f00881c

	u32 rGPIOMCON;			//0x7f008820
	u32 rGPIOMDAT;			//0x7f008824
	u32 rGPIOMPUD;			//0x7f008828	
	u32 reserved23;

	u32 rGPIONCON;			//0x7f008830
	u32 rGPIONDAT;			//0x7f008834
	u32 rGPIONPUD;			//0x7f008838	
	u32 reserved24;

	u32 reserved25[16];

	u32 rSPCONSLP;			//0x7f008880

	u32 reserved26[31];		

	u32 rEINT0CON0;			//0x7f008900
	u32 rEINT0CON1;			//0x7f008904
	u32 reserved27[2];

	u32 rEINT0FLTCON0;		//0x7f008910
	u32 rEINT0FLTCON1;		//0x7f008914
	u32 rEINT0FLTCON2;		//0x7f008918
	u32 rEINT0FLTCON3;		//0x7f00891c
	u32 rEINT0MASK;			//0x7f008920
	u32 rEINT0PEND;			//0x7f008924
	u32 reserved28[2];
	u32 rSLPEN;				//0x7f008930

} 
oGPIO_REGS;

static void *GPIO_pBase;



//////////
// Function Name : GPIO_Init
// Function Desctiption : This function initializes gpio sfr base address
// Input : NONE
// Output : NONE
// Version :
//
// Version : v0.1
void GPIO_Init(void)
{
	GPIO_pBase = (void *)GPIO_BASE;
}


//////////
// Function Name : GPIO_SetFunctionEach
// Function Desctiption : This function set each GPIO function
// Input : 	Id : GPIO port
//			eBitPos : GPIO bit
//			uFunction : Select the function
// Output : NONE
//
// Version : v0.1
void GPIO_SetFunctionEach(GPIO_eId Id, GPIO_eBitPos eBitPos, u32 uFunction)
{
	volatile u32 *pGPIOx_Reg0, *pGPIOx_Reg1;
	volatile u32 *pGPIO_Base_Addr;
	u32 uMuxBit, uConRegNum, uOffset;
	u32 uConValue;

	uMuxBit = (Id&0xF000)>>12;
	uConRegNum = (Id&0x0F00)>>8;
	uOffset = Id&0x00FF;

	pGPIO_Base_Addr = &(GPIO->rGPIOACON);
	
	if(uMuxBit == 4)
	{
		if(uConRegNum == 1)
		{
			pGPIOx_Reg0 = pGPIO_Base_Addr + (uOffset*0x10)/4;
			uConValue = *pGPIOx_Reg0;
			uConValue = (uConValue & ~(0xF<<(uMuxBit*eBitPos))) | (uFunction<<(uMuxBit*eBitPos));
			*pGPIOx_Reg0 = uConValue;
		}
		else if(uConRegNum == 2)
		{
			if(eBitPos < eGPIO_8)
			{
				pGPIOx_Reg0 = pGPIO_Base_Addr + (uOffset*0x10)/4;
				uConValue = *pGPIOx_Reg0;
				uConValue = (uConValue & ~(0xF<<(uMuxBit*eBitPos))) | (uFunction<<(uMuxBit*eBitPos));
				*pGPIOx_Reg0 = uConValue;
			}
			else 	// eBitPos >= eGPIO_8
			{
				pGPIOx_Reg1 = pGPIO_Base_Addr + (uOffset*0x10)/4 + 1;
				uConValue = *pGPIOx_Reg1;
				uConValue = (uConValue & ~(0xF<<(uMuxBit*(eBitPos-8)))) | (uFunction<<(uMuxBit*(eBitPos-8)));
				*pGPIOx_Reg1 = uConValue;
			}			
		}
	}
	else if(uMuxBit == 2)
	{
		pGPIOx_Reg0 = pGPIO_Base_Addr + (uOffset*0x10)/4;
		uConValue = *pGPIOx_Reg0;
		uConValue = (uConValue & ~(0x3<<(uMuxBit*eBitPos))) | (uFunction<<(uMuxBit*eBitPos));
		*pGPIOx_Reg0 = uConValue;
	}
}



//////////
// Function Name : GPIO_SetDataAll
// Function Desctiption : This function set all GPIO data bit
// Input : 	Id : GPIO port
//			uValue : value
// Output : NONE
//
// Version : v0.1
void GPIO_SetDataAll(GPIO_eId Id, u32 uValue)
{
	volatile u32 *pGPIOx_DataReg;
	volatile u32 *pGPIO_Base_Addr;
	u32 uConRegNum, uOffset;

	uConRegNum = (Id&0x0F00)>>8;
	uOffset = Id&0x00FF;

	pGPIO_Base_Addr = &(GPIO->rGPIOACON);
	
	pGPIOx_DataReg = pGPIO_Base_Addr + (uOffset*0x10)/4 + uConRegNum;
	*pGPIOx_DataReg = uValue;
}


//////////
// Function Name : GPIO_GetDataAll
// Function Desctiption : This function get all GPIO data bit
// Input : 	Id : GPIO port
//			uValue : value
// Output : 	Data register value
//
// Version : v0.1
u32 GPIO_GetDataAll(GPIO_eId Id)
{
	volatile u32 *pGPIOx_DataReg;
	volatile u32 *pGPIO_Base_Addr;
	u32 uConRegNum, uOffset;

	uConRegNum = (Id&0x0F00)>>8;
	uOffset = Id&0x00FF;

	pGPIO_Base_Addr = &(GPIO->rGPIOACON);
	
	pGPIOx_DataReg = pGPIO_Base_Addr + (uOffset*0x10)/4 + uConRegNum;
	return (*pGPIOx_DataReg);
}


