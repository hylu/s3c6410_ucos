/*
@=========================================
@ NAME: 2440INIT.S
@ DESC: C start up codes
@       Configure memory, ISR ,stacks
@	Initialize C-variables
@ HISTORY:
@ 2002.02.25:kwtark: ver 0.0
@ 2002.03.20:purnnamu: Add some functions for testing STOP,Sleep mode
@ 2003.03.14:DonGo: Modified for 2440.
@=========================================
*/

/* #include "option.S"*/

.equ _STACK_BASEADDRESS,	0xc7ff7e00
.equ _MMUTT_STARTADDRESS,	0xc7ff8000
.equ _ISR_STARTADDRESS,		0xc7ff7e00


.equ CLKDIV_VAL, 7

.equ M_MDIV, 68
.equ M_PDIV, 1
.equ M_SDIV, 1

.equ U_MDIV, 56
.equ U_PDIV, 2
.equ U_SDIV, 2


.equ BIT_SELFREFRESH, 	(1<<22)

@Pre-defined constants
.equ USERMODE,     	0x10
.equ FIQMODE,      	0x11
.equ IRQMODE,      	0x12
.equ SVCMODE,      	0x13
.equ ABORTMODE,    	0x17
.equ UNDEFMODE,    	0x1b
.equ MODEMASK,     	0x1f
.equ NOINT,        	0xc0

@The location of stacks
.equ FIQStack,		(_STACK_BASEADDRESS-0x0)	@0x33ff8000 ~
.equ UserStack,		(_STACK_BASEADDRESS-0x3800)	@0x33ff4800 ~
.equ SVCStack,		(_STACK_BASEADDRESS-0x2800)	@0x33ff5800 ~
.equ UndefStack,	(_STACK_BASEADDRESS-0x2400)	@0x33ff5c00 ~
.equ AbortStack,	(_STACK_BASEADDRESS-0x2000)	@0x33ff6000 ~
.equ IRQStack,		(_STACK_BASEADDRESS-0x1000)	@0x33ff7000 ~



.equ INTOFFSET,	  0x4a000014    @Interruot request source offset




@ :::::::::::::::::::::::::::::::::::::::::::::
@           BEGIN: Power Management 
@ - - - - - - - - - - - - - - - - - - - - - - -
.equ Mode_USR,                 0x10
.equ Mode_FIQ,                 0x11
.equ Mode_IRQ,                 0x12
.equ Mode_SVC,                 0x13
.equ Mode_ABT,                 0x17
.equ Mode_UND,                 0x1B
.equ Mode_SYS,                 0x1F

.equ I_Bit,                    0x80
.equ F_Bit,                    0x40
@ - - - - - - - - - - - - - - - - - - - - - - -

.macro MOV_PC_LR
    mov pc,lr
.endm

.macro MOVEQ_PC_LR
    moveq pc,lr
.endm
	
	.extern  Main    @ The main entry of mon program
	.extern  OS_CPU_IRQ_ISR @uCOS_II IrqISR
	.globl  HandleEINT0	 @for os_cpu_a.s
	
	.globl	HandleIRQ	@jkeqiang	
	.globl  __ENTRY
/*
	PRESERVE8 @jkeqiang
	AREA    Init,CODE,READONLY
*/

ENTRY:
__ENTRY:
    	b	ResetHandler
	b	HandlerUndef	@handler for Undefined mode
	b	HandlerSWI	    @handler for SWI interrupt
	b	HandlerPabort	@handler for PAbort
	b	HandlerDabort	@handler for DAbort
	b	.		        @reserved
	b	HandlerIRQ	@handler for IRQ interrupt
	b	HandlerFIQ	@handler for FIQ interrupt

// 0x20 
	b	HandlerUndef	@ Must be @0x20.
ChangeBigEndian:
	.long 0x0f10ee11 //0xee110f10
	.long 0x0080e380 //0xe3800080
	.long 0x0f10ee01 //0xee010f10
	.long 0xffffffff
	.long 0xffffffff
	.long 0xffffffff
	.long 0xffffffff
	.long 0xffffffff
	b ResetHandler

.macro HANDLER    HandlerLabel,HandleLabel

\HandlerLabel:
	sub	sp,sp,#4	@decrement sp(to store jump address)
	stmfd	sp!,{r0}	@PUSH the work register to stack(lr does''t push because it return to original address)
	ldr     r0,=\HandleLabel @load the address of HandleXXX to r0
	ldr     r0,[r0]	 @load the contents(service routine start address) of HandleXXX
	str     r0,[sp,#4]      @store the contents(ISR) of HandleXXX to stack
	ldmfd   sp!,{r0,pc}     @POP the work register and pc(jump to ISR)
.endm

HANDLER HandlerFIQ, HandleFIQ
HANDLER HandlerIRQ, HandleIRQ
HANDLER HandlerUndef, HandleUndef
HANDLER HandlerSWI, HandleSWI
HANDLER HandlerDabort, HandleDabort
HANDLER HandlerPabort, HandlePabort

IsrIRQ:
	sub	sp,sp,#4       @reserved for PC
	stmfd	sp!,{r8-r9}

	ldr	r9,=INTOFFSET
	ldr	r9,[r9]
	ldr	r8,=HandleEINT0
	add	r8,r8,r9,lsl #2
	ldr	r8,[r8]
	str	r8,[sp,#8]
	ldmfd	sp!,{r8-r9,pc}

@=======
@ ENTRY
@=======
ResetHandler:
 	@Initialize stacks
	bl	InitStacks
  	@ Setup IRQ handler
	ldr	r0,=HandleIRQ       @This routine is needed
	
	@ldr	r1,=IsrIRQ	  @if there isn''t 'subs pc,lr,#4' at 0x18, 0x1c
	ldr	r1, =OS_CPU_IRQ_ISR @modify by txf, for ucos 
	str	r1,[r0]	
	
	bl	Main
	b	.

	@MOV	r1,#0x02
	@MCR p15, 0, r1, c1, c1, 0

@function initializing stacks
InitStacks:
	@Don''t use DRAM,such as stmfd,ldmfd......
	@SVCstack is initialized before
	@Under toolkit ver 2.5, 'msr cpsr,r1' can be used instead of 'msr cpsr_cxsf,r1'
	mrs	r0,cpsr
	bic	r0,r0,#MODEMASK
	orr	r1,r0,#UNDEFMODE|NOINT
	msr	cpsr_cxsf,r1		@UndefMode
	ldr	sp,=UndefStack		@ UndefStack=0x33FF_5C00

	orr	r1,r0,#ABORTMODE|NOINT
	msr	cpsr_cxsf,r1		@AbortMode
	ldr	sp,=AbortStack		@ AbortStack=0x33FF_6000

	orr	r1,r0,#IRQMODE|NOINT
	msr	cpsr_cxsf,r1		@IRQMode
	ldr	sp,=IRQStack		@ IRQStack=0x33FF_7000

	orr	r1,r0,#FIQMODE|NOINT
	msr	cpsr_cxsf,r1		@FIQMode
	ldr	sp,=FIQStack		@ FIQStack=0x33FF_8000

	bic	r0,r0,#MODEMASK|NOINT
	orr	r1,r0,#SVCMODE
	msr	cpsr_cxsf,r1		@SVCMode
	ldr	sp,=SVCStack		@ SVCStack=0x33FF_5800

	@USER mode has not be initialized.
	
	mov	pc,lr
	@The LR register won''t be valid if the current mode is not SVC mode.

.align
.data

.equ HandleReset, 	_ISR_STARTADDRESS + 4 * 0
.equ HandleUndef, 	_ISR_STARTADDRESS + 4 * 1
.equ HandleSWI, 	_ISR_STARTADDRESS + 4 * 2
.equ HandlePabort,	_ISR_STARTADDRESS + 4 * 3
.equ HandleDabort,	_ISR_STARTADDRESS + 4 * 4
.equ HandleReserved, 	_ISR_STARTADDRESS + 4 * 5
.equ HandleIRQ, 	_ISR_STARTADDRESS + 4 * 6
.equ HandleFIQ, 	_ISR_STARTADDRESS + 4 * 7


@@0x33FF_Fe20
.equ HandleEINT0, 	_ISR_STARTADDRESS + 4 * 8
.equ HandleEINT1, 	_ISR_STARTADDRESS + 4 * 9
.equ HandleRTC_TIC, 	_ISR_STARTADDRESS + 4 * 10
.equ HandleCAMIF_C, 	_ISR_STARTADDRESS + 4 * 11
.equ HandleCAMIF_P, 	_ISR_STARTADDRESS + 4 * 12

.equ HandleI2C1, 	_ISR_STARTADDRESS + 4 * 13
.equ HandleI2S, 	_ISR_STARTADDRESS + 4 * 14
.equ HandleReserved1, 	_ISR_STARTADDRESS + 4 * 15
.equ Handle3D, 		_ISR_STARTADDRESS + 4 * 16
.equ HandlePost0, 	_ISR_STARTADDRESS + 4 * 17

.equ HandleROTATOR,	_ISR_STARTADDRESS + 4 * 18
.equ Handle2D,		_ISR_STARTADDRESS + 4 * 19
.equ HandleTVENC,	_ISR_STARTADDRESS + 4 * 20
.equ HandleSCALER,	_ISR_STARTADDRESS + 4 * 21
.equ HandleBATF,	_ISR_STARTADDRESS + 4 * 22
.equ HandleJPEG,	_ISR_STARTADDRESS + 4 * 23

@@0x33FF_Fe60
.equ HandleMFC,         _ISR_STARTADDRESS + 4 * 24
.equ HandleSDMA0,       _ISR_STARTADDRESS + 4 * 25
.equ HandleSDMA1,       _ISR_STARTADDRESS + 4 * 26
.equ HandleARM_DMAERR,  _ISR_STARTADDRESS + 4 * 27
.equ HandleARM_DMA,     _ISR_STARTADDRESS + 4 * 28
.equ HandleARM_DMAS,    _ISR_STARTADDRESS + 4 * 29
.equ HandleKEYPAD,      _ISR_STARTADDRESS + 4 * 30
.equ HandleTIMER0,      _ISR_STARTADDRESS + 4 * 31
.equ HandleTIMER1,      _ISR_STARTADDRESS + 4 * 32
.equ HandleTIMER2,      _ISR_STARTADDRESS + 4 * 33
.equ HandleWDT,         _ISR_STARTADDRESS + 4 * 34
.equ HandleTIMER3,      _ISR_STARTADDRESS + 4 * 35
.equ HandleTIMER4,      _ISR_STARTADDRESS + 4 * 36
.equ HandleLCD0,        _ISR_STARTADDRESS + 4 * 37
.equ HandleLCD1,        _ISR_STARTADDRESS + 4 * 38
.equ HandleLCD2,        _ISR_STARTADDRESS + 4 * 39

@@0x33FF_Fea0

.equ HandleEINT2,	_ISR_STARTADDRESS + 4 * 40
.equ HandleEINT3,	_ISR_STARTADDRESS + 4 * 41
.equ HandlePCM0,	_ISR_STARTADDRESS + 4 * 42
.equ HandlePCM1,	_ISR_STARTADDRESS + 4 * 43
.equ HandleAC97,	_ISR_STARTADDRESS + 4 * 44
.equ HandleUART0,	_ISR_STARTADDRESS + 4 * 45
.equ HandleUART1,	_ISR_STARTADDRESS + 4 * 46
.equ HandleUART2,	_ISR_STARTADDRESS + 4 * 47
.equ HandleUART3,	_ISR_STARTADDRESS + 4 * 48
.equ HandleDMA0,	_ISR_STARTADDRESS + 4 * 49
.equ HandleDMA1,	_ISR_STARTADDRESS + 4 * 50
.equ HandleONENAND0,	_ISR_STARTADDRESS + 4 * 51
.equ HandleONENAND1,	_ISR_STARTADDRESS + 4 * 52
.equ HandleNFC,		_ISR_STARTADDRESS + 4 * 53
.equ HandleCFC,		_ISR_STARTADDRESS + 4 * 54
.equ HandleUHOST,	_ISR_STARTADDRESS + 4 * 55

@@0x33FF_Fee0

.equ HandleSPI0,	_ISR_STARTADDRESS + 4 * 56
.equ HandleSPI1_HSMMC2,	_ISR_STARTADDRESS + 4 * 57
.equ HandleI2C0,	_ISR_STARTADDRESS + 4 * 58
.equ HandleHSItx,	_ISR_STARTADDRESS + 4 * 59
.equ HandleHSIrx,	_ISR_STARTADDRESS + 4 * 60
.equ HandleEINT4,	_ISR_STARTADDRESS + 4 * 61
.equ HandleMSM,		_ISR_STARTADDRESS + 4 * 62
.equ HandleHOSTIF,	_ISR_STARTADDRESS + 4 * 63
.equ HandleHSMMC0,	_ISR_STARTADDRESS + 4 * 64
.equ HandleHSMMC1,	_ISR_STARTADDRESS + 4 * 65
.equ HandleOTG,		_ISR_STARTADDRESS + 4 * 66
.equ HandleIrDA,	_ISR_STARTADDRESS + 4 * 67
.equ HandleRTC_ALARM,	_ISR_STARTADDRESS + 4 * 68
.equ HandleSEC,		_ISR_STARTADDRESS + 4 * 69
.equ HandlePENDNUP,	_ISR_STARTADDRESS + 4 * 70
.equ HandleADC,		_ISR_STARTADDRESS + 4 * 71

.end

