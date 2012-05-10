

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
*	File Name : uart.c
*  
*	File Description : This file implements the API functon for UART.
*
*	Author : Woojin,Kim
*	Dept. : AP Development Team
*	Created Date : 2007/01/16
*	Version : 0.1 
* 
*	History
*	- Creat debug function (InitDebug,Putc,Getc,Getkey)(Haksoo,Kim 2006/11/08) 
*	- Creat Full function (Woojin,Kim 2007/01/16)
*  
**************************************************************************************/

#include "option.h"
#include "library.h"
#include "sfr6410.h"
#include "uart.h"
#include "sysc.h"
#include "gpio.h"

#define UART_OFFSET		0x400

#define UART0_BASE		(UART_REGS *)(UART_BASE)
#define UART1_BASE		(UART_REGS *)(UART_BASE+UART_OFFSET)
#define UART2_BASE		(UART_REGS *)(UART_BASE+UART_OFFSET*2)
#define UART3_BASE		(UART_REGS *)(UART_BASE+UART_OFFSET*3)


#define TX_FIFO_RESET		(1<<2)
#define RX_FIFO_RESET	(1<<1)
#define TX_INT_TYPE		(1<<9) // 0:pulse 1:level(6400 should be level)
#define RX_INT_TYPE		(1<<8) // 0:pulse 1:level(6400 should be level)

#define RX_TIMEOUT_EN	(1<<7) // 0:disable 1:enable, disable for FIFO test
#define RX_ERR_INT_EN	(1<<6) // 0:disable 1:enable
#define RTS_ACTIVE		(1) // In normal mode, nRTS signal  0:low, 1:High



/////////
// Global variables
static UART_CON	g_AUartCon[5] = {{115200,0,0,0,0,0,3,0,0,1,1,1,1,1,1}
				, {115200,0,0,0,0,0,3,0,0,1,1,1,1,1,1}
				, {115200,0,0,0,0,0,3,0,0,1,1,1,1,1,1}
				, {115200,0,0,0,0,0,3,0,0,1,1,1,1,1,1}
				, {115200,0,0,0,0,0,3,0,0,1,1,1,1,1,1}}; 
				// control property per each channel. 4th data is defualt value for initialize

		     		
volatile u32 g_uOpClock=0;

static UART_REGS *g_pUartDebugRegs;


//////////
// Function Name : UART_InitDebugCh
// Function Description : This function initializes a certain uart ch. for debugging console
// Input : NONE 
// Output : NONE
// Version : 
void UART_InitDebugCh(u8 ch, u32 uBaudRate)
{
	UART_SetConfig(ch,0,1,1,4,1,2,1,uBaudRate,1,1,1,1);
	UART_Open(ch);
	return;
}


//////////
// Function Name : UART_Putc
// Function Description : This function write character data to uart debugging ch
// Input : NONE 
// Output : NONE
// Version : 
void UART_Putc(char data)
{
	u32 temp;

	if(data=='\n')
	{
		while(1)
		{
			Delay(10);
			temp = Inp32(&g_pUartDebugRegs->rUtrStat);
			temp&=0x2;
			if(temp)
				break;
		}
//		Delay(10);
		Outp8(&g_pUartDebugRegs->rUtxh,'\r');
	}
	while(1)
	{
		Delay(5);
		temp = Inp32(&g_pUartDebugRegs->rUtrStat);
		temp&=0x02;
		if(temp)
			break;
	}
	//Delay(10);
	Outp8(&g_pUartDebugRegs->rUtxh,data);
	return;
}

void UART_Puts(char *s)
{
	while (*s) {
		UART_Putc(*s++);
	}
}

//////////
// Function Name : UART_Getc
// Function Description : This function read character data from uart debugging ch
// Input : NONE 
// Output : temp8, character data received through uart
// Version : 
s8 UART_Getc( void)
{
	u32 temp32;
	char temp8;
	while(1)
	{
		temp32 = Inp32(&g_pUartDebugRegs->rUtrStat);		
		temp32&=0x01;
		if(temp32)
			break;
	}
	temp8 = Inp8(&g_pUartDebugRegs->rUrxh);
	return temp8;
}


//////////
// Function Name : UART_Open
// Function Description : This function set up H/W(GPIO) and initialize SFR of UART for Debugging
// Input : ch [0~4 UART channel]
// Output : g_pUartRxStr[ch] [charater type received string]
// Version : v0.1

u8 UART_Open(u8 ch) // setting H/W & initializing regiter
{


	if(ch == 0)
		g_pUartDebugRegs = UART0_BASE;
	else if(ch == 1)
		g_pUartDebugRegs = UART1_BASE;
	else if(ch == 2)
		g_pUartDebugRegs = UART2_BASE;
	else if(ch == 3)
		g_pUartDebugRegs = UART3_BASE;	


//	return TRUE;
#if 1
	switch(ch)
	{
		case 0 :
			GPIO_SetFunctionEach(eGPIO_A, eGPIO_0, 2); //Uart0 RXD
			GPIO_SetFunctionEach(eGPIO_A, eGPIO_1, 2); //Uart0 TXD			
			GPIO_SetFunctionEach(eGPIO_A, eGPIO_2, 2); //Uart0 CTSn			
			GPIO_SetFunctionEach(eGPIO_A, eGPIO_3, 2); //Uart0 RTSn			
			
			if(UART_InitializeREG(UART0_BASE, &g_AUartCon[0])  == SENDBREAK)
				return SENDBREAK; // Initialize register set for Uart 0

			break;
		case 1 :
			GPIO_SetFunctionEach(eGPIO_A, eGPIO_4, 2); //Uart1 RXD
			GPIO_SetFunctionEach(eGPIO_A, eGPIO_5, 2); //Uart1 TXD			
			GPIO_SetFunctionEach(eGPIO_A, eGPIO_6, 2); //Uart1 CTSn			
			GPIO_SetFunctionEach(eGPIO_A, eGPIO_7, 2); //Uart1 RTSn		

			if(UART_InitializeREG(UART1_BASE, &g_AUartCon[1]) == SENDBREAK)
				return SENDBREAK;

			break;
		case 2 :
			GPIO_SetFunctionEach(eGPIO_B, eGPIO_0, 2); //Uart2 RXD
			GPIO_SetFunctionEach(eGPIO_B, eGPIO_1, 2); //Uart2 TXD			

			if(UART_InitializeREG(UART2_BASE, &g_AUartCon[2]) == SENDBREAK)
				return SENDBREAK;

			break;
		case 3 :
			GPIO_SetFunctionEach(eGPIO_B, eGPIO_2, 2); //Uart2 RXD
			GPIO_SetFunctionEach(eGPIO_B, eGPIO_3, 2); //Uart2 TXD			

			if(UART_InitializeREG(UART3_BASE, &g_AUartCon[3]) == SENDBREAK)
				return SENDBREAK;

			break;
		default :
			return FALSE;
	}
	return TRUE;
#endif
}



//////////
// Function Name : UART_InitializeREG
// Function Description : This function set up SFR by pre-defined value 
// Input : *pUartRegs [SFR value base address]
//		 *pUartCon [Pre-defined value's base address, UART_Config]
// Output : SENDBREAK [when sendbreak signal set up]
//		    0 [nomal mode (sendbreak signal disable)]
// Version : v0.1

u32 UART_InitializeREG( UART_REGS *pUartRegs, UART_CON *pUartCon) // Initialize register set with current control set
{


#if 0
	UART_CalcBaudrate(pUartRegs, pUartCon);

	Outp32(&pUartRegs->rUfCon , (pUartCon->cTxTrig<<6)|(pUartCon->cRxTrig<<4)|TX_FIFO_RESET|RX_FIFO_RESET
						|(pUartCon->cEnableFifo));
	
	Outp32(&pUartRegs->rUlCon , (pUartCon->cSelUartIrda<<6)|(pUartCon->cParityBit<<3)|(pUartCon->cStopBit<<2)
						|(pUartCon->cDataBit));
	Outp32(&pUartRegs->rUCon , (pUartCon->cOpClock<<10)|TX_INT_TYPE|RX_INT_TYPE|RX_ERR_INT_EN|RX_TIMEOUT_EN
						|(pUartCon->cLoopTest<<5)| (pUartCon->cSendBreakSignal<<4) |(pUartCon->cTxMode<<2)|(pUartCon->cRxMode));		
	if(pUartCon->cSendBreakSignal)
		return SENDBREAK;
//	Outp32(&pUartRegs->rUfCon , (pUartCon->cTxTrig<<6)|(pUartCon->cRxTrig<<4)|TX_FIFO_RESET|RX_FIFO_RESET
//						|(pUartCon->cEnableFifo));
	Outp32(&pUartRegs->rUmCon , (pUartCon->cRtsTrig<<5)|(pUartCon->cAfc<<4)|RTS_ACTIVE);	
	Outp32(&pUartRegs->rUintM , 0xf); // mask
	Outp32(&pUartRegs->rUintSp , 0xf); // source pending clear
	Outp32(&pUartRegs->rUintP , 0xf); // pending clear
#endif
	return 0;
	
}


//////////
// Function Name : UART_CalcBaudrate
// Function Description : This function defines UbrDiv and UdivSlot value depends on OpClock src
// Input : *pUartRegs [SFR value base address]
//		 *pUartCon [Pre-defined value's base address, UART_Config]
// Output : NONE
// Version : v0.1

void UART_CalcBaudrate( UART_REGS *pUartRegs, UART_CON *pUartCon)
{
	const u32 aSlotTable[16] = {0x0000, 0x0080, 0x0808, 0x0888, 0x2222, 0x4924, 0x4a52, 0x54aa,
				     		0x5555, 0xd555, 0xd5d5, 0xddd5, 0xdddd, 0xdfdd, 0xdfdf, 0xffdf};
	float tempDiv;
	u32 nOpClock;
	u32 nSlot;
	
	switch(pUartCon->cOpClock)
	{
		case 1 : 			
			nOpClock = g_uOpClock;
			break;// Uextclk
		case 3 :
			nOpClock = g_uOpClock;			
			break;// Epll
		case 0 :
		case 2 : // Pclk
		default : 			
			nOpClock = g_PCLK;			
			break;
	}

	tempDiv = (nOpClock/(16.*pUartCon->uBaudrate)) - 1;
	nSlot = (u32)((tempDiv - (int)tempDiv) * 16);
	Outp32(&pUartRegs->rUbrDiv , (u32)(tempDiv));
	Outp32(&pUartRegs->rUdivSlot , aSlotTable[nSlot]);	
	//UART_Printf(" div = %d, slot = 0x%x\n", (u32)(tempDiv), aSlotTable[nSlot]); 
	
}




//////////
// Function Name : UART_SetConfig
// Function Description : This function set up UART by pre-defined value (input)
// Input :
//		Channel(0~3)
//		Other Options 0. Nothing[D]  1.Send Break Signal  2. Loop Back Mode
//		Parity Mode 1. No parity[D] 2. Odd 3. Even 4. Forced as '1' 5. Forced as '0'
//		Number of Stop Bit 1. One stop bit per frame[D] 2. Two stop bit per frame
//		Word Length 1. 5bits 2. 6bits 3. 7bits 4. 8bits
//		Operating Clock 1. PCLK[D]	2. UEXTCLK	3. PLL
//            PLL selection  1.EPLL    2.MPLL
//		External Interface Type 1. UART[D]   2. IrDA mode
//		Baudrate (ex 9600, 115200[D], 921600)
//		Operating Mode 1. Interrupt[D]	2. DMA
//		FIFO Mode (Tx/Rx[byte]) 1. no FIFO[D]  2. Empty/1  3. 16/8   4. 32/16  5. 48/32
//		AFC Mode 1. Disable[D]	2. Enable
//		nRTS trigger level(byte) 1. 63[D]   2. 56   3. 48   4. 40   5. 32   6. 24   7. 16   8. 8
// Output : NONE
// Version : v0.1
// default UART channel setting is UART_SetConfig(0,0,1,1,4,1,2,1,115200,1,1,1,1)

u8 UART_SetConfig(u8 cCh, u32 uBreakorLoop,u32 uParity,u32 uNumStop,u32 uWordLength,u32 uOpCLK,u32 uSelPLL, 
				u32 uExtIFtype,u32 uBaudrate,u32 uSelOpmode,u32 uSelFIFO,u32 uSelAFC,u32 uRTSLvL)
{

	volatile UART_CON *pUartCon;

	pUartCon = &g_AUartCon[cCh];	

	
	//Set Other Options
//	UART_Printf("\nSelect Other Options\n 0. Nothing[D]  1.Send Break Signal  2. Loop Back Mode  \n Choose : ");
	switch(uBreakorLoop)
	{		
		default : 	
					pUartCon->cSendBreakSignal = 0x0;
					pUartCon->cLoopTest = 0x0;
					break;
					
		case 1 :		
					pUartCon->cSendBreakSignal = 1;	
					return cCh;
					
					
		case 2 :	 	
					pUartCon->cLoopTest = 1;		
					break;		
	}		
	
	
	//Set Parity mode
//	UART_Printf("\nSelect Parity Mode\n 1. No parity[D] 2. Odd 3. Even 4. Forced as '1' 5. Forced as '0' \n Choose : ");
	switch(uParity)
	{		
		default : 	
			pUartCon->cParityBit = 0;		
			break;
		case 2 : 		
			pUartCon->cParityBit = 4;
			break;
		case 3 :		
			pUartCon->cParityBit = 5;
			break;
		case 4 :		
			pUartCon->cParityBit = 6;
			break;
		case 5 :		
			pUartCon->cParityBit = 7;
			break;
	}
	//Set the number of stop bit	
//	UART_Printf("\n\nSelect Number of Stop Bit\n 1. One stop bit per frame[D] 2. Two stop bit per frame");
	switch(uNumStop)
	{
		default : 	
			pUartCon->cStopBit = 0;
			break;
			
		case 2 : 		
			pUartCon->cStopBit = 1;
			break;		
	}
	//Set Word Length	
//	UART_Printf("\n\nSelect Word Length\n 1. 5bits 2. 6bits 3. 7bits 4. 8bits[D] \n Choose : ");
	switch(uWordLength)
	{		
		case 1 :		
			pUartCon->cDataBit = 0;
			break;
		case 2 :		
			pUartCon->cDataBit = 1;
			break;
		case 3 :		
			pUartCon->cDataBit = 2;		
			break;	
		default :		
			pUartCon->cDataBit = 3;
			break;
	}
	
	
	// Set Operation clock
//	UART_Printf("\n\nSelect Operating Clock\n 1. PCLK[D]	2. UEXTCLK	3. EPLL \n Choose : ");
	switch (uOpCLK)
	{
	case 2 :
		pUartCon->cOpClock = 1;
//		g_uOpClock=12000000;
		GPIO_SetFunctionEach(eGPIO_F,eGPIO_13,2);		
		// connect CLKOUT and UEXTCLK
//		UART_Printf("\nInput PWM EXT_CLK by Pulse Generater\n");
		break;

	case 3 :
		pUartCon->cOpClock = 3;
//		UART_Printf("\nSelect Clock SRC\n 1.EPLL  2.MPLL \n Choose: ");
			switch(uSelPLL)
				{
					case 1:
//						SYSC_SetPLL(eEPLL,64,3,1,0);	//EPLL=128Mhz
						SYSC_SetPLL(eEPLL,32,1,1,0);   //EPLL=192Mhz
						SYSC_ClkSrc(eEPLL_FOUT);
						SYSC_ClkSrc(eUART_MOUTEPLL);
//						SYSC_CtrlCLKOUT(eCLKOUT_EPLLOUT,9);  						
						g_uOpClock = CalcEPLL(32,1,1,0);
//						UART_Printf("EPLL = %dMhz\n",(g_uOpClock/1000000));
						// use EPLL output clock
						//SetEPLL(42, 1, 2); // Epll output - 96MHz, pll input - 12MHz
						//CLK_SRC	UART_SEL[13]  0:EPLL
						//CLK_DIV2	UART_RATIO[19:16]
						break;
					case 2:							//MPLL
						SYSC_ClkSrc(eMPLL_FOUT);				
						SYSC_ClkSrc(eUART_DOUTMPLL);

						Delay(100);
						g_uOpClock = (u32)g_MPLL/2;
						
//						UART_Printf("MPLL = %dMhz\n",(g_uOpClock/1000000));
						// use MPLL output clock
						//CLK_SRC	UART_SEL[13]	  1:MPLL
						//CLK_DIV2	UART_RATIO[19:16]
						break;
					default:							//MPLL
						SYSC_ClkSrc(eMPLL_FOUT);		
						SYSC_ClkSrc(eUART_DOUTMPLL);
						Delay(100);
				
						g_uOpClock =(u32) g_MPLL/2;
						//SetEPLL(42, 1, 2); // Epll output - 96MHz, pll input - 12MHz
						//CLK_SRC	UART_SEL[13]  0:EPLL
						//CLK_DIV2	UART_RATIO[19:16]
						break;									
				}
		break;

	default :
		pUartCon->cOpClock = 0; // PCLK		
		break;
	}

	// Select UART or IrDA 1.0
//	UART_Printf("\n\nSelect External Interface Type\n 1. UART[D]   2. IrDA mode\n Choose : ");
	if (uExtIFtype==2)		
		pUartCon->cSelUartIrda = 1; // IrDA mode
	else					
		pUartCon->cSelUartIrda = 0; // IrDA mode

	// Set Baudrate
//	UART_Printf("\n\nType the baudrate and then change the same baudrate of host, too.\n");
//	UART_Printf(" Baudrate (ex 9600, 115200[D], 921600) : ");
	pUartCon->uBaudrate = uBaudrate;

//	if ((s32)pUartCon->uBaudrate == -1) 
//		pUartCon->uBaudrate = 115200;

	// Select UART operating mode
//	UART_Printf("\n\nSelect Operating Mode\n 1. Interrupt[D]	2. DMA\n Choose : ");
	if (uSelOpmode==2)
	{
		pUartCon->cTxMode = 2; // DMA0 mode
		pUartCon->cRxMode = 3; // DMA1 mode
	}
	else
	{	
		pUartCon->cTxMode = 1; // Int mode
		pUartCon->cRxMode = 1; // Int mode
	}

	// Select UART FIFO mode
//	UART_Printf("\n\nSelect FIFO Mode (Tx/Rx[byte])\n 1. no FIFO[D]  2. Empty/1  3. 16/8   4. 32/16  5. 48/32 \n Choose : ");

	if ( (uSelFIFO>1)&&(uSelFIFO<6) )
	{
		pUartCon->cEnableFifo = 1;
		pUartCon->cTxTrig = uSelFIFO -2;
		pUartCon->cRxTrig = uSelFIFO -2;
	}
	else 
	{
		pUartCon->cEnableFifo = 0;
	}

	// Select AFC mode enable/disable
//	UART_Printf("\n\nSelect AFC Mode\n 1. Disable[D]	2. Enable\n Choose : ");
	if (uSelAFC == 2)
	{
		pUartCon->cAfc = 1; // AFC mode enable
//		UART_Printf("Select nRTS trigger level(byte)\n 1. 63[D]   2. 56   3. 48   4. 40   5. 32   6. 24   7. 16   8. 8\n Choose : ");
		
		
		if ( (uRTSLvL>1)&&(uRTSLvL<9) )	
			pUartCon->cRtsTrig = uRTSLvL -1;

		else						
			pUartCon->cRtsTrig = 0; // default 63 byte
	}
	else
	{
		pUartCon->cAfc = 0; // AFC mode disable
	}

	return cCh;
}



//////////
// Function Name : CalcEPLL
// Function Description : This is Uart DMA request ISR which operates DMA request
// Input : NONE
// Output : NONE
// Version : v0.1

u32 CalcEPLL(u32 uMdiv,u32 uPdiv,u32 uSdiv,u32 uKdiv)
{
	float EPLL;

	EPLL=(((uMdiv+(uKdiv/(2<<16)))*FIN)/(uPdiv*(1<<uSdiv)));

	return (u32)EPLL;
}

