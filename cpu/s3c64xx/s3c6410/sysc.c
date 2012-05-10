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
*	File Name : sysc.c
*  
*	File Description : This file implements the API functons for system controller.
*
*	Author : Haksoo,Kim
*	Dept. : AP Development Team
*	Created Date : 2006/11/08
*	Version : 0.1 
* 
*	History
*	- Created(Haksoo,Kim 2006/11/08)
*	- Added sfr (Wonjoon.Jang 2007/01/08)
*  
**************************************************************************************/

#include "option.h"
#include "library.h"
#include "sfr6410.h"
#include "sysc.h"
#define rAPLL_CON			(SYSCON_BASE+0x00c)
#define rMPLL_CON			(SYSCON_BASE+0x010)
#define rEPLL_CON0			(SYSCON_BASE+0x014)
#define rEPLL_CON1			(SYSCON_BASE+0x018)
#define rCLK_SRC			(SYSCON_BASE+0x01c)
#define rCLK_SRC2			(SYSCON_BASE+0x10c)
#define rCLK_DIV0			(SYSCON_BASE+0x020)
#define rCLK_DIV1			(SYSCON_BASE+0x024)
#define rCLK_DIV2			(SYSCON_BASE+0x028)

// 
#define rOTHERS				(SYSCON_BASE+0x900)


u8	g_System_Revision, g_System_Pass, g_SYNCACK;
u32	g_APLL, g_MPLL, g_ARMCLK, g_HCLKx2, g_HCLK, g_PCLK;

//////////
// Function Name : SYSC_GetClkInform
// Function Description : This function gets common clock information
// Input : NONE 
// Output : NONE
// Version : 
void SYSC_GetClkInform( void)
{
	u8 muxApll, muxMpll, muxSync;
	u8 divApll, divHclkx2, divHclk, divPclk;
	u16 pllM, pllP, pllS;
	u32 temp;
	
	////
	// clock division ratio	
	temp = Inp32(rCLK_DIV0);
	divApll = temp & 0xf;
	divHclkx2 = (temp>>9) & 0x7;
	divHclk = (temp>>8) & 0x1;
	divPclk = (temp>>12) & 0xf;

	////
	// Operating Mode
	temp = Inp32(rOTHERS);
	temp = (temp>>8)&0xf;
	if(temp)
	{
		g_SYNCACK = 1;
	}
	else
	{
		g_SYNCACK = 0;
	}
	
	////
	// ARMCLK
	muxApll = Inp32(rCLK_SRC) & 0x1;
	if(muxApll)	//FOUT
	{			
		temp = Inp32(rAPLL_CON);
		pllM = (temp>>16)&0x3ff;
		pllP = (temp>>8)&0x3f;
		pllS = (temp&0x7);

		g_APLL = ((FIN>>pllS)/pllP)*pllM;
	}
	else	//FIN
	{
		g_APLL = FIN;
	}
	
	g_ARMCLK = g_APLL/(divApll+1);
	
	////
	// HCLK
	muxSync = (Inp32(rOTHERS)>>7) & 0x1;
	if(muxSync)	//synchronous mode
	{
		g_HCLKx2 = g_APLL/(divHclkx2+1);
		
		temp = Inp32(rMPLL_CON);
		pllM = (temp>>16)&0x3ff;
		pllP = (temp>>8)&0x3f;
		pllS = (temp&0x7);

		g_MPLL = ((FIN>>pllS)/pllP)*pllM;
	}
	else
	{
		muxMpll = (Inp32(rCLK_SRC)>>1) & 0x1;
		if(muxMpll)	//FOUT
		{						
			temp = Inp32(rMPLL_CON);
			pllM = (temp>>16)&0x3ff;
			pllP = (temp>>8)&0x3f;
			pllS = (temp&0x7);

			g_MPLL = ((FIN>>pllS)/pllP)*pllM;
		}
		else	//FIN
		{
			g_MPLL = FIN;
		}
		g_HCLKx2 = g_MPLL/(divHclkx2+1);		
	}
	
	g_HCLK = g_HCLKx2/(divHclk+1);
	
	////
	// PCLK
	g_PCLK = g_HCLKx2/(divPclk+1);

	return;
	
}


//////////
// Function Name : SYSC_SetPLL
// Function Description : This function control PLL Output Frequency (APLL, MPLL:PLL9025X, EPLL:PLL9024X)
//				  Fout = (mdiv * Fin) / (pdiv x 2^sdiv),   Fout = ((mdiv+k/2^16) * Fin) / (pdiv x 2^sdiv)
// Input : 				ePLL  : APLL, MPLL, EPLL	
//						uMdiv : Mdiv Value ( 56 ~ 1023), ( 13 ~ 255)
//						uPdiv :  Pdiv Value ( 1~63)
//						uSdiv : Sdiv Value ( 0~5 )
//						uKdiv : PLL9025X (Not Used, 0), PLL9024X(0~65535)
// Output : NONE
// Version : 0.1 by boaz
void SYSC_SetPLL(PLL_eTYPE  ePLL, u32 uMdiv, u32 uPdiv, u32 uSdiv, u32 uKdiv)
{
	u32 temp, uRegValue;


	switch(ePLL)
	{
		case eAPLL: 
			// Check the Divider Value.
			if( uMdiv < 64 || uMdiv > 1023)
			{
				UART_Printf(" Wrong  Mdiv Value, Correct Value Range = (56 ~ 1023) (%d)\n", uMdiv);
			}
			if( uPdiv < 1 || uPdiv > 63)
			{
				UART_Printf(" Wrong  Pdiv Value, Correct Value Range = (1 ~ 63) (%d)\n", uPdiv);
			}
			if( uSdiv > 5)
			{
				UART_Printf(" Wrong  Sdiv Value, Correct Value Range = (0 ~ 5) (%d)\n", uSdiv);
			}
      			// Check the Fvco Range

      			temp = ((FIN/uPdiv)*uMdiv)/1000000;
			if( temp <800 || temp > 1600)
			{

				UART_Printf(" Please select the proper M,P,S divider value\n");
				UART_Printf(" Fvco Range = (800MHz ~ 1600MHz),  Current Value is (%d)MHz\n", temp);
			}

			uRegValue = (u32)(((u32)(0x1<<31))|(uMdiv<<16)|(uPdiv<<8)|(uSdiv<<0));
			Outp32(rAPLL_CON, uRegValue);
			break;

		case eMPLL: 
			// Check the Divider Value.
			if( uMdiv < 64 || uMdiv > 1023)
			{
				UART_Printf(" Wrong  Mdiv Value, Correct Value Range = (56 ~ 1023) (%d)\n", uMdiv);
			}
			if( uPdiv < 1 || uPdiv > 63)
			{
				UART_Printf(" Wrong  Pdiv Value, Correct Value Range = (1 ~ 63) (%d)\n", uPdiv);
			}
			if( uSdiv > 5)
			{
				UART_Printf(" Wrong  Sdiv Value, Correct Value Range = (0 ~ 5) (%d)\n", uSdiv);
			}
      			// Check the Fvco Range

      			temp = ((FIN/uPdiv)*uMdiv)/1000000;
			if( temp <800 || temp > 1600)
			{
				UART_Printf(" Please select the proper M,P,S divider value\n");
				UART_Printf(" Fvco Range = (800MHz ~ 1600MHz),  Current Value is (%d)MHz\n", temp);
			}

			uRegValue = (u32)(((u32)(0x1<<31))|(uMdiv<<16)|(uPdiv<<8)|(uSdiv<<0));
			Outp32(rMPLL_CON, uRegValue);	
			break;

		case eEPLL: 
			// Check the Divider Value.
			if( uMdiv < 16 || uMdiv > 255)
			{
				UART_Printf(" Wrong  Mdiv Value, Correct Value Range = (56 ~ 1023) (%d)\n", uMdiv);
			}
			if( uPdiv < 1 || uPdiv > 63)
			{
				UART_Printf(" Wrong  Pdiv Value, Correct Value Range = (1 ~ 63) (%d)\n", uPdiv);
			}
			if( uSdiv > 5)
			{
				UART_Printf(" Wrong  Sdiv Value, Correct Value Range = (0 ~ 5) (%d)\n", uSdiv);
			}
			if( uKdiv >65535)
			{
				UART_Printf(" Wrong  Kdiv Value, Correct Value Range = (0 ~ 65535) (%d)\n", uKdiv);
			}
		      // Check the Fvco Range

		       temp = (FIN/uPdiv)*(uMdiv+(uKdiv/(2^16)))/1000000;
			if( temp <300 || temp > 600)
			{
				UART_Printf(" Please select the proper M,P,S divider value\n");
				UART_Printf(" Fvco Range = (300MHz ~ 600MHz),  Current Value is (%d)MHz\n", temp);
			}

			Outp32(rEPLL_CON1, uKdiv);
			uRegValue = (u32)(((u32)(0x1<<31))|(uMdiv<<16)|(uPdiv<<8)|(uSdiv<<0));
			Outp32(rEPLL_CON0, uRegValue);
			break;
		}

	// Get Information
	SYSC_GetClkInform();
}

//boaz.kim
//////////
// Function Name : SYSC_ClkSrc
// Function Description : This function select Clock Source
//				 
// Input : 		  CLKSRC_eId
// Output : NONE
// Version : 
void SYSC_ClkSrc( CLKSRC_eId  eClkSrc)
{
	u32 uReg, uCtrl, uOffset, uFuct;
	u32 uRegValue;

	uReg = (eClkSrc&0x10000)>>16;
	uCtrl = (eClkSrc&0xF000)>>12;
	uOffset = (eClkSrc&0x0FF0)>>4;
	uFuct = eClkSrc&0x000F;

	if(uReg==0)
	{
		uRegValue = Inp32(rCLK_SRC);
		uRegValue = (uRegValue & ~(uCtrl<<(uOffset))) | (uFuct<<(uOffset));
		Outp32(rCLK_SRC, uRegValue);		
	}
	else if(uReg==1)
	{
		uRegValue = Inp32(rCLK_SRC2);
		uRegValue = (uRegValue & ~(uCtrl<<(uOffset))) | (uFuct<<(uOffset));
		Outp32(rCLK_SRC2, uRegValue);		
	}
	//else Assert(0);
		

}

