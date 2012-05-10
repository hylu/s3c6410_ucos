#include <gpio.h>
#include "ucos_ii.h"
#include <common.h>
#include <ucos/s3c64x0.h>
#include <s3c6410.h>
#include <os_cpu.h>
//#include "gpio_key.h"

//=======================================
#include <ucos/app_cfg.h>
//#include <printf.h>
//=========================================
OS_STK  MainTaskStk[MainTaskStkLengh];
OS_STK	Task0Stk [Task0StkLengh];       // Define the Task0 stack 
OS_STK	Task1Stk [Task1StkLengh];       // Define the Task1 stack 
OS_STK	Task2Stk [Task2StkLengh];       // Define the Task1 stack 

//int rYear, rMonth,rDay,rDayOfWeek,rHour,rMinute,rSecond;


//void Rtc_Init(void);

//void Task_LCD(void *p);

//S_EVENT *Semp;                         //Creat semp
//U8 err;

extern char __ENTRY[];
extern unsigned long HandleIRQ;

void Remap(void)
{
    unsigned long *p_s,*p_d;
    unsigned long len=1024;
    int i;
    p_s = (unsigned long *)__ENTRY;
    p_d = (unsigned long *)0x0;
    for (i=0;i<len;i++)
    {
        p_d[i]	= p_s[i];
    }
}

int Main(int argc, char **argv)
{   
    SYSC_GetClkInform();

//    CalibrateDelay();
    GPIO_Init();
    OpenConsole();
    INTC_Init();

    Remap();    
    
    UART_Printf("Hello!!\n");
    OSInit ();
    OSTimeSet(0);
    OSTaskCreate (MainTask,(void *)0, &MainTaskStk[MainTaskStkLengh - 1], MainTaskPrio);
    OSStart ();
    return 0;     
}

#if 0
int Main(int argc, char **argv)
{
	int len, i;
    unsigned long *p_s,*p_d;
    
    
	timer_init();
    gpio_keys_init();
    //MMU_Init();

	len = 1024; // 2048
	p_s = (unsigned long *)__ENTRY;
	p_d = (unsigned long *)0x0;
    
	for (i = 0; i < len; i++)
    {
    	p_d[i] = p_s[i];
    }
	OSInit ();
	OSTimeSet(0);
	OSTaskCreate (MainTask,(void *)0, &MainTaskStk[MainTaskStkLengh - 1], MainTaskPrio);
	OSStart ();
	return 0;    
}
#endif


void MainTask(void *pdata) //Main Task create taks0 and task1
{
   
#if OS_CRITICAL_METHOD == 3                                /* Allocate storage for CPU status register */
    OS_CPU_SR  cpu_sr;
#endif
    OS_ENTER_CRITICAL();
    UART_Printf("Enter MainTask\n");
    //ISRInit();   //initial interrupt prio or enable or disable
    TIMER_OSREQUEST();
    OS_EXIT_CRITICAL();

    OSPrintfInit();//use task to print massage to Uart 

    OSStatInit();
    OSTaskCreate (Task0,(void *)0, &Task0Stk[Task0StkLengh - 1], Task0Prio);
    OSTaskCreate (Task1,(void *)0, &Task1Stk[Task1StkLengh - 1], Task1Prio);
    OSTaskCreate (Task2,(void *)0, &Task2Stk[Task2StkLengh - 1], Task2Prio);
    while(1)
    {
        //  GUI_DispString("hello word");
        OSPrintf("\nEnter Main Task\n");
        OSTimeDly(OS_TICKS_PER_SEC);
    }

}

void Task0(void *pdata)
{
    static int tsk0_i;
    tsk0_i = 0;
    while(1)
    {
        OSPrintf("this is from task0 %x\n", tsk0_i++);
        OSTimeDly(OS_TICKS_PER_SEC);
    }
}

void Task1(void *pdata)
{
    while(1)
    {
        OSPrintf("this is from task1\n");
        OSTimeDly(OS_TICKS_PER_SEC);
    }
}

void Task2(void *pdata)
{
    while(1)
    {
        OSPrintf("this is from task2\n");
        OSTimeDly(OS_TICKS_PER_SEC);
    }    
}


#if 0
void Task0	(void *pdata)//Init lwip and create task2
{
 
	char *s="msg";
	char i;
    
	while (1)
    {
        
       Lcd_N35_Init();

    }
}

void Task1	(void *pdata) //task for test
{
    
    
	U16 TestCnt=0;
	U16 Version;


	Version=OSVersion();    
    
            
	while (1)
    {
    
     TestCnt++;
     OSPrintf("********************************\n");
     OSPrintf("Enter Task1 Cnt=%d\n",TestCnt);    
     OSPrintf("Enter Task1\n");
     OSPrintf("uC/OS Version:V%4.2f\n",(float)Version*0.01);//ucos version 
     OSPrintf("********************************\n");
     
     //led 
     if(TestCnt%2)
     	rGPBDAT = 0x0000;
     else
    	rGPBDAT = 0x07fe;
        
     OSTimeDly(OS_TICKS_PER_SEC);

    }
}



#define RGB(r,g,b)   (unsigned int)( (r << 16) + (g << 8) + b )
#define FROM_BCD(n)        ((((n) >> 4) * 10) + ((n) & 0xf))
#define TO_BCD(n)        ((((n) / 10) << 4) | ((n) % 10))

void Task2(void *pdata)
{
    unsigned int i, x, m, n, k, y;
    int tmp,key;         

    int width = 10;
    int height = 100;
        
    OSPrintf("Task LCD Running...\r\n");


    //===========================
    // RTC初始化
    //===========================
    Rtc_Init();
    
    //LCD 初始化
    //Lcd_N35_Init();

    while(1)
    {
    
    	i++;
    	if(i>99)i=0;

    	if(rBCDYEAR==0x99)
        	rYear = 1999;
    	else
        	rYear    = (2000 + rBCDYEAR);
        	rMonth   = FROM_BCD(rBCDMON & 0x1f);
        	rDay	    = FROM_BCD(rBCDDAY & 0x03f);
        	rDayOfWeek = rBCDDATE-1;
        	rHour    = FROM_BCD(rBCDHOUR & 0x3f);
        	rMinute     = FROM_BCD(rBCDMIN & 0x7f);
        	rSecond     = FROM_BCD(rBCDSEC & 0x7f);

        
       OSTimeDly( 5 );
       OSPrintf("Task LCD.\n");
       //在LCD上打印时间
      // Lcd_printf(140,15,RGB( 0xFF,0xFF,0xFF),RGB( 0x00,0x00,0x00),0,"%02d:%02d:%02d\n", rHour, rMinute, rSecond);
       //在LCD上打印日期，星期
     //  Lcd_printf(40,15,RGB( 0xFF,0xFF,0xFF),RGB( 0x00,0x00,0x00),0,"%4d-%02d-%02d 星期%d \n",
      //            rYear, rMonth, rDay,rDayOfWeek);
       
       Lcd_printf(40,100,RGB( 0xFF,0xFF,0xFF),RGB( 0x00,0x00,0x00),0," 欢迎选购飞凌系列开发板！");
       OSTimeDly(OS_TICKS_PER_SEC);
       
       Lcd_printf(9,100,RGB( 0xFF,0xFF,0xFF),RGB( 0x00,0x00,0x00),0," 飞凌嵌入式以技术为中心，与客户共成长！");
        OSTimeDly(OS_TICKS_PER_SEC);
     //  mydelay(100);
    
    }
}

//************************[ Rtc_Init ]*********************************
void Rtc_Init(void)
{
	int wYear, wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond;

    wYear = 2008;
    wMonth = 9;
    wDay = 5;
    wDayOfWeek = 5;
    wHour= 9;
    wMinute = 41;
    wSecond = 30;
    
	rRTCCON = 1 ;        //RTC read and write enable

	rBCDYEAR = (unsigned char)TO_BCD(wYear%100);    //年
    rBCDMON  = (unsigned char)TO_BCD(wMonth);        //月
    rBCDDAY	 = (unsigned char)TO_BCD(wDay);            //日	
	rBCDDATE = wDayOfWeek+1;                        //星期
	rBCDHOUR = (unsigned char)TO_BCD(wHour);        //小时
	rBCDMIN  = (unsigned char)TO_BCD(wMinute);        //分
	rBCDSEC  = (unsigned char)TO_BCD(wSecond);        //秒
    
	rRTCCON &= ~1 ;        //RTC read and write disable
}

#endif
