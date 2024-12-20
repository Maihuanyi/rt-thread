/**
  ******************************************************************************
  * @file      startup_mm32f5260_gcc.s 
  * @author    Chasel
  * @brief     MM32F526XX devices vector table GCC toolchain.
  *            This module performs:
  *                - Set the initial SP
  *                - Set the initial PC == Reset_Handler,
  *                - Set the vector table entries with the exceptions ISR address,
  *                - Configure the clock system
  *                - Branches to main in the C library (which eventually
  *                  calls main()).
  *            After Reset the Cortex-M33 processor is in Thread mode,
  *            priority is Privileged, and the Stack is set to Main.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 Chasel.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

  .syntax unified
	.cpu cortex-m33
	.fpu softvfp
	.thumb

.global	g_pfnVectors
.global	Default_Handler

/* start address for the initialization values of the .data section.
defined in linker script */
.word	_sidata
/* start address for the .data section. defined in linker script */
.word	_sdata
/* end address for the .data section. defined in linker script */
.word	_edata
/* start address for the .bss section. defined in linker script */
.word	_sbss
/* end address for the .bss section. defined in linker script */
.word	_ebss

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called.
 * @param  None
 * @retval : None
*/

    .section	.text.Reset_Handler
	.weak	Reset_Handler
	.type	Reset_Handler, %function
Reset_Handler:
  ldr   sp, =_estack    /* set stack pointer */

/* Call the clock system initialization function.*/
  bl  SystemInit

/* Copy the data segment initializers from flash to SRAM */
  movs	r1, #0
  b	LoopCopyDataInit

CopyDataInit:
	ldr	r3, =_sidata
	ldr	r3, [r3, r1]
	str	r3, [r0, r1]
	adds	r1, r1, #4

LoopCopyDataInit:
	ldr	r0, =_sdata
	ldr	r3, =_edata
	adds	r2, r0, r1
	cmp	r2, r3
	bcc	CopyDataInit
	ldr	r2, =_sbss
	b	LoopFillZerobss
/* Zero fill the bss segment. */
FillZerobss:
	movs	r3, #0
	str	r3, [r2], #4

LoopFillZerobss:
	ldr	r3, = _ebss
	cmp	r2, r3
	bcc	FillZerobss

/* Call static constructors */
  bl __libc_init_array
/* Call the application's entry point.*/
	bl	entry

LoopForever:
    b LoopForever

.size	Reset_Handler, .-Reset_Handler

/**
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 *
 * @param  None
 * @retval : None
*/
    .section	.text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
	b	Infinite_Loop
	.size	Default_Handler, .-Default_Handler
/******************************************************************************
*
* The minimal vector table for a Cortex-M33.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************/
 	.section	.isr_vector,"a",%progbits
	.type	g_pfnVectors, %object
	.size	g_pfnVectors, .-g_pfnVectors


g_pfnVectors:
	.word	_estack
	.word	Reset_Handler
	.word	NMI_Handler
	.word	HardFault_Handler
	.word	MemManage_Handler
	.word	BusFault_Handler
	.word	UsageFault_Handler
    .word   0
	.word	0
	.word	0
	.word	0
	.word	SVCall_Handler
	.word	DebugMon_Handler
	.word	0
	.word	PendSV_Handler
	.word	SysTick_Handler
	.word	WWDG_IWDG_IRQHandler
	.word	PVD_IRQHandler
    .word   BKP_TAMPER_IRQHandler
	.word	RTC_IRQHandler
	.word	FLASH_IRQHandler
	.word	RCC_CRS_IRQHandler
	.word	EXTI0_IRQHandler
	.word	EXTI1_IRQHandler
	.word	EXTI2_IRQHandler
	.word	EXTI3_IRQHandler
	.word	EXTI4_IRQHandler
	.word	DMA1_CH1_IRQHandler
	.word	DMA1_CH2_IRQHandler
	.word	DMA1_CH3_IRQHandler
	.word	DMA1_CH4_IRQHandler
	.word	DMA1_CH5_IRQHandler
	.word	DMA1_CH6_IRQHandler
	.word	DMA1_CH7_IRQHandler
	.word	ADC1_2_IRQHandler
    .word   0
    .word   DMA1_CH8_IRQHandler
    .word   FlexCAN1_IRQHandler
    .word   0
    .word   EXTI9_5_IRQHandler
	.word	TIM1_BRK_IRQHandler
	.word	TIM1_UP_IRQHandler
	.word	TIM1_TRG_COM_IRQHandler
	.word	TIM1_CC_IRQHandler
	.word	TIM2_IRQHandler
	.word	TIM3_IRQHandler
	.word	TIM4_IRQHandler
    .word   I2C1_IRQHandler
    .word   0
    .word   I2C2_IRQHandler
    .word   0
	.word	SPI1_IRQHandler
	.word	SPI2_IRQHandler
	.word	UART1_IRQHandler
	.word	UART2_IRQHandler
	.word	UART3_IRQHandler
    .word   EXTI15_10_IRQHandler
    .word   RTC_ALR_IRQHandler
    .word   USB_WKUP_IRQHandler
    .word   TIM8_BRK_IRQHandler
    .word   TIM8_UP_IRQHandler
    .word   TIM8_TRG_COM_IRQHandler
    .word   TIM8_CC_IRQHandler
    .word   0
    .word   0
    .word   0
    .word   TIM5_IRQHandler
    .word   SPI3_IRQHandler
    .word   UART4_IRQHandler
    .word   UART5_IRQHandler
    .word   TIM6_IRQHandler
    .word   TIM7_IRQHandler
	.word	DMA2_CH1_IRQHandler
	.word	DMA2_CH2_IRQHandler
	.word	DMA2_CH3_IRQHandler
	.word	DMA2_CH4_IRQHandler
	.word	DMA2_CH5_IRQHandler
    .word   ENET_IRQHandler
    .word   ENET_WKUP_IRQHandler
    .word   0
    .word   COMP_IRQHandler
    .word   FlexCAN2_IRQHandler
    .word   0
    .word   USB_FS_IRQHandler
    .word   DMA2_CH6_IRQHandler
    .word   DMA2_CH7_IRQHandler
    .word   DMA2_CH8_IRQHandler
    .word   UART6_IRQHandler
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   UART7_IRQHandler
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   QSPI_IRQHandler
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   LPTIM_IRQHandler
    .word   0
    .word   LPUART_IRQHandler
    .word   0
    .word   0
    .word   0

/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/

	.weak	NMI_Handler
	.thumb_set NMI_Handler,Default_Handler

	.weak	HardFault_Handler
	.thumb_set HardFault_Handler,Default_Handler

	.weak	MemManage_Handler
	.thumb_set MemManage_Handler,Default_Handler

	.weak	BusFault_Handler
	.thumb_set BusFault_Handler,Default_Handler

	.weak	UsageFault_Handler
	.thumb_set UsageFault_Handler,Default_Handler

	.weak	SVCall_Handler
	.thumb_set SVCall_Handler,Default_Handler

	.weak	DebugMon_Handler
	.thumb_set DebugMon_Handler,Default_Handler

	.weak	PendSV_Handler
	.thumb_set PendSV_Handler,Default_Handler

	.weak	SysTick_Handler
	.thumb_set SysTick_Handler,Default_Handler

	.weak	WWDG_IWDG_IRQHandler
	.thumb_set WWDG_IWDG_IRQHandler,Default_Handler

	.weak	PVD_IRQHandler
	.thumb_set PVD_IRQHandler,Default_Handler

	.weak	BKP_TAMPER_IRQHandler
	.thumb_set BKP_TAMPER_IRQHandler,Default_Handler

	.weak	RTC_IRQHandler
	.thumb_set RTC_IRQHandler,Default_Handler

	.weak	FLASH_IRQHandler
	.thumb_set FLASH_IRQHandler,Default_Handler

	.weak	RCC_CRS_IRQHandler
	.thumb_set RCC_CRS_IRQHandler,Default_Handler

	.weak	EXTI0_IRQHandler
	.thumb_set EXTI0_IRQHandler,Default_Handler

	.weak	EXTI1_IRQHandler
	.thumb_set EXTI1_IRQHandler,Default_Handler

	.weak	EXTI2_IRQHandler
	.thumb_set EXTI2_IRQHandler,Default_Handler

	.weak	EXTI3_IRQHandler
	.thumb_set EXTI3_IRQHandler,Default_Handler

	.weak	EXTI4_IRQHandler
	.thumb_set EXTI4_IRQHandler,Default_Handler

	.weak	DMA1_CH1_IRQHandler
	.thumb_set DMA1_CH1_IRQHandler,Default_Handler

	.weak	DMA1_CH2_IRQHandler
	.thumb_set DMA1_CH2_IRQHandler,Default_Handler

	.weak	DMA1_CH3_IRQHandler
	.thumb_set DMA1_CH3_IRQHandler,Default_Handler

	.weak	DMA1_CH4_IRQHandler
	.thumb_set DMA1_CH4_IRQHandler,Default_Handler

	.weak	DMA1_CH5_IRQHandler
	.thumb_set DMA1_CH5_IRQHandler,Default_Handler

	.weak	DMA1_CH6_IRQHandler
	.thumb_set DMA1_CH6_IRQHandler,Default_Handler

	.weak	DMA1_CH7_IRQHandler
	.thumb_set DMA1_CH7_IRQHandler,Default_Handler

	.weak	ADC1_2_IRQHandler
	.thumb_set ADC1_2_IRQHandler,Default_Handler

	.weak	DMA1_CH8_IRQHandler
	.thumb_set DMA1_CH8_IRQHandler,Default_Handler

	.weak	FlexCAN1_IRQHandler
	.thumb_set FlexCAN1_IRQHandler,Default_Handler

	.weak	EXTI9_5_IRQHandler
	.thumb_set EXTI9_5_IRQHandler,Default_Handler

	.weak	TIM1_BRK_IRQHandler
	.thumb_set TIM1_BRK_IRQHandler,Default_Handler

	.weak	TIM1_UP_IRQHandler
	.thumb_set TIM1_UP_IRQHandler,Default_Handler

	.weak	TIM1_TRG_COM_IRQHandler
	.thumb_set TIM1_TRG_COM_IRQHandler,Default_Handler

	.weak	TIM1_CC_IRQHandler
	.thumb_set TIM1_CC_IRQHandler,Default_Handler

	.weak	TIM2_IRQHandler
	.thumb_set TIM2_IRQHandler,Default_Handler

	.weak	TIM3_IRQHandler
	.thumb_set TIM3_IRQHandler,Default_Handler

	.weak	TIM4_IRQHandler
	.thumb_set TIM4_IRQHandler,Default_Handler

	.weak	I2C1_IRQHandler
	.thumb_set I2C1_IRQHandler,Default_Handler

	.weak	I2C2_IRQHandler
	.thumb_set I2C2_IRQHandler,Default_Handler

	.weak	SPI1_IRQHandler
	.thumb_set SPI1_IRQHandler,Default_Handler

	.weak	SPI2_IRQHandler
	.thumb_set SPI2_IRQHandler,Default_Handler

	.weak	UART1_IRQHandler
	.thumb_set UART1_IRQHandler,Default_Handler

	.weak	UART2_IRQHandler
	.thumb_set UART2_IRQHandler,Default_Handler

	.weak	UART3_IRQHandler
	.thumb_set UART3_IRQHandler,Default_Handler

	.weak	EXTI15_10_IRQHandler
	.thumb_set EXTI15_10_IRQHandler,Default_Handler

	.weak	RTC_ALR_IRQHandler
	.thumb_set RTC_ALR_IRQHandler,Default_Handler

	.weak	USB_WKUP_IRQHandler
	.thumb_set USB_WKUP_IRQHandler,Default_Handler

	.weak	TIM8_BRK_IRQHandler
	.thumb_set TIM8_BRK_IRQHandler,Default_Handler

	.weak	TIM8_UP_IRQHandler
	.thumb_set TIM8_UP_IRQHandler,Default_Handler

	.weak	TIM8_TRG_COM_IRQHandler
	.thumb_set TIM8_TRG_COM_IRQHandler,Default_Handler

	.weak	TIM8_CC_IRQHandler
	.thumb_set TIM8_CC_IRQHandler,Default_Handler

	.weak	TIM5_IRQHandler
	.thumb_set TIM5_IRQHandler,Default_Handler

	.weak	SPI3_IRQHandler
	.thumb_set SPI3_IRQHandler,Default_Handler

	.weak	UART4_IRQHandler
	.thumb_set UART4_IRQHandler,Default_Handler

	.weak	UART5_IRQHandler
	.thumb_set UART5_IRQHandler,Default_Handler

	.weak	TIM6_IRQHandler
	.thumb_set TIM6_IRQHandler,Default_Handler

	.weak	TIM7_IRQHandler
	.thumb_set TIM7_IRQHandler,Default_Handler

	.weak	DMA2_CH1_IRQHandler
	.thumb_set DMA2_CH1_IRQHandler,Default_Handler

	.weak	DMA2_CH2_IRQHandler
	.thumb_set DMA2_CH2_IRQHandler,Default_Handler

	.weak	DMA2_CH3_IRQHandler
	.thumb_set DMA2_CH3_IRQHandler,Default_Handler

	.weak	DMA2_CH4_IRQHandler
	.thumb_set DMA2_CH4_IRQHandler,Default_Handler

	.weak	DMA2_CH5_IRQHandler
	.thumb_set DMA2_CH5_IRQHandler,Default_Handler

	.weak	ENET_IRQHandler
	.thumb_set ENET_IRQHandler,Default_Handler

	.weak	ENET_WKUP_IRQHandler
	.thumb_set ENET_WKUP_IRQHandler,Default_Handler

	.weak	COMP_IRQHandler
	.thumb_set COMP_IRQHandler,Default_Handler

	.weak	FlexCAN2_IRQHandler
	.thumb_set FlexCAN2_IRQHandler,Default_Handler

	.weak	USB_FS_IRQHandler
	.thumb_set USB_FS_IRQHandler,Default_Handler

	.weak	DMA2_CH6_IRQHandler
	.thumb_set DMA2_CH6_IRQHandler,Default_Handler

	.weak	DMA2_CH7_IRQHandler
	.thumb_set DMA2_CH7_IRQHandler,Default_Handler

	.weak	DMA2_CH8_IRQHandler
	.thumb_set DMA2_CH8_IRQHandler,Default_Handler

	.weak	UART6_IRQHandler
	.thumb_set UART6_IRQHandler,Default_Handler

	.weak	UART7_IRQHandler
	.thumb_set UART7_IRQHandler,Default_Handler

	.weak	QSPI_IRQHandler
	.thumb_set QSPI_IRQHandler,Default_Handler

	.weak	LPTIM_IRQHandler
	.thumb_set LPTIM_IRQHandler,Default_Handler

	.weak	LPUART_IRQHandler
	.thumb_set LPUART_IRQHandler,Default_Handler


/************************ (C) COPYRIGHT Chasel *****END OF FILE****/
