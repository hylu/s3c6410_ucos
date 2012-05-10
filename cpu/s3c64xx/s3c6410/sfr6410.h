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
*	File Name : sfr6410.h
*  
*	File Description : This file defines SFR base addresses.
*
*	Author : Haksoo,Kim
*	Dept. : AP Development Team
*	Created Date : 2006/11/08
*	Version : 0.1 
* 
*	History
*	- Created(Haksoo,Kim 2006/11/08)
*	- Added - AHB_S  (wonjoon.jang 2007/1/2 ) 
*	- Added I2C0, I2C1 (OnPil, Shin (SOP) 2008/03/01)
*  
**************************************************************************************/


#ifndef __sfr6410_H__
#define __sfr6410_H__

#ifdef __cplusplus
extern "C" {
#endif


//VIC
#define VIC0_BASE				(0x71200000)
#define VIC1_BASE				(0x71300000)


//WDT
#define WDT_BASE				(0x7E004000)
#define SYSCON_BASE				(0x7E00F000)


//UART
#define UART_BASE				(0x7F005000)
//PWM TIMER
#define PWMTIMER_BASE			(0x7F006000)
//GPIO
#define GPIO_BASE				(0x7F008000)

#ifdef __cplusplus
}
#endif

#endif /*__sfr6410_H__*/
