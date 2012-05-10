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
*	File Name : library.h
*  
*	File Description : This file defines the register access function
*						and declares prototypes of library funcions
*
*	Author : Haksoo,Kim
*	Dept. : AP Development Team
*	Created Date : 2006/11/08
*	Version : 0.1 
* 
*	History
*	- Created(Haksoo,Kim 2006/11/08)
*	- Added Pause() by OnPil, Shin on 2008/03/04
*  
**************************************************************************************/
#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "def.h"

#define Outp32(addr, data)	(*(volatile u32 *)(addr) = (data))
#define Outp8(addr, data)	(*(volatile u8 *)(addr) = (data))
#define Inp32(addr)			(*(volatile u32 *)(addr))
#define Inp8(addr)			(*(volatile u8 *)(addr))


void InitUartPort(u8 ch, u8 flowControl);
void InitLED(void);
void DisplayLED(u8 data);
void OpenConsole(void);
s32 GetIntNum(void);
void Delay(u32 usec);
u32 Pow(u32 x, u32 y);
void Copy(u32 sa, u32 da, u32 words);
void Copy8(u32 sa, u32 da, u32 bytes);
void Copy16(u32 sa, u32 da, u32 Hwords);
u8 Compare( u32 a0,  u32 a1,  u32 words);
void Dump32(u32 addr, u32 words);
void Dump16(u32 addr, u32 hwords);
void Dump8(u32 addr, u32 bytes);
void Stop(void);

void UART_Printf(const char *fmt,...);

void Pause(void);		// Added by SOP on 2008/03/04

#ifdef __cplusplus
}
#endif

#endif /*__LIBRARY_H__*/

