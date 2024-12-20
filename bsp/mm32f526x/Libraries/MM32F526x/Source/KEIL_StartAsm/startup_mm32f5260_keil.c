/***********************************************************************************************************************
    @file     startup_mm32f5260_keil.c
    @author   VV TEAM
    @brief    CMSIS Core Device Startup File for ArmChina-STAR Device
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
       the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
       promote products derived from this software without specific prior written permission.

      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************************************************************/

/* Files include */
#include "mm32_device.h"

/***********************************************************************************************************************
   Exception / Interrupt Handler Function Prototype
  *********************************************************************************************************************/
typedef void (*pFunc)(void);

/*----------------------------------------------------------------------------
   External References
  *********************************************************************************************************************/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
extern __NO_RETURN void __PROGRAM_START(void);

/***********************************************************************************************************************
   Internal References
  *********************************************************************************************************************/
void __NO_RETURN Default_Handler(void);
void __NO_RETURN Reset_Handler(void);

/***********************************************************************************************************************
   Exception / Interrupt Handler
  *********************************************************************************************************************/

/* Exceptions */
void NMI_Handler               (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void SVCall_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));

void WWDG_IWDG_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void BKP_TAMPER_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void RCC_CRS_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI0_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI1_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI2_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI3_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI4_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH1_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH2_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH3_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH4_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH5_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH6_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH7_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1_2_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_CH8_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void FlexCAN1_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM4_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI2_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void UART3_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_ALR_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_WKUP_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_BRK_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM6_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH1_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH2_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH3_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH4_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH5_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void ENET_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void ENET_WKUP_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void COMP_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void FlexCAN2_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_FS_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH6_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH7_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_CH8_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UART6_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void UART7_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void QSPI_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void LPTIM_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void LPUART_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));

/***********************************************************************************************************************
   Exception / Interrupt Vector table
  *********************************************************************************************************************/
#if defined (__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const pFunc __VECTOR_TABLE[];
const pFunc __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE =
{
    (pFunc)(&__INITIAL_SP),            /*     Initial Stack Pointer */
    Reset_Handler,                     /*     Reset Handler */
    NMI_Handler,                       /* -14 NMI Handler */
    HardFault_Handler,                 /* -13 Hard Fault Handler */
    MemManage_Handler,                 /* -12 MPU Fault Handler */
    BusFault_Handler,                  /* -11 Bus Fault Handler */
    UsageFault_Handler,                /* -10 Usage Fault Handler */
    0,                                 /*     Reserved */
    0,                                 /*     Reserved */
    0,                                 /*     Reserved */
    0,                                 /*     Reserved */
    SVCall_Handler,                    /*  -5 SVCall Handler */
    DebugMon_Handler,                  /*  -4 Debug Monitor Handler */
    0,                                 /*     Reserved */
    PendSV_Handler,                    /*  -2 PendSV Handler */
    SysTick_Handler,                   /*  -1 SysTick Handler */

    /* Interrupts */
    WWDG_IWDG_IRQHandler,              /*   WWDG IWDG     */
    PVD_IRQHandler,                    /*   PVD           */
    BKP_TAMPER_IRQHandler,             /*   BKP TAMPER    */
    RTC_IRQHandler,                    /*   RTC           */
    FLASH_IRQHandler,                  /*   FLASH         */
    RCC_CRS_IRQHandler,                /*   RCC CRS       */
    EXTI0_IRQHandler,                  /*   EXTI0         */
    EXTI1_IRQHandler,                  /*   EXTI1         */
    EXTI2_IRQHandler,                  /*   EXTI2         */
    EXTI3_IRQHandler,                  /*   EXTI3         */
    EXTI4_IRQHandler,                  /*   EXTI4         */
    DMA1_CH1_IRQHandler,               /*   DMA1 Channel1 */
    DMA1_CH2_IRQHandler,               /*   DMA1 Channel2 */
    DMA1_CH3_IRQHandler,               /*   DMA1 Channel3 */
    DMA1_CH4_IRQHandler,               /*   DMA1 Channel4 */
    DMA1_CH5_IRQHandler,               /*   DMA1 Channel5 */
    DMA1_CH6_IRQHandler,               /*   DMA1 Channel6 */
    DMA1_CH7_IRQHandler,               /*   DMA1 Channel7 */
    ADC1_2_IRQHandler,                 /*   ADC1 ADC2     */
    0,                                 /*   Reserved      */
    DMA1_CH8_IRQHandler,               /*   DMA1 Channel8 */
    FlexCAN1_IRQHandler,               /*   FlexCAN1      */
    0,                                 /*   Reserved      */
    EXTI9_5_IRQHandler,                /*   EXTI9~5       */
    TIM1_BRK_IRQHandler,               /*   TIM1 BRK      */
    TIM1_UP_IRQHandler,                /*   TIM1 UP       */
    TIM1_TRG_COM_IRQHandler,           /*   TIM1 TRG COM  */
    TIM1_CC_IRQHandler,                /*   TIM1 CC       */
    TIM2_IRQHandler,                   /*   TIM2          */
    TIM3_IRQHandler,                   /*   TIM3          */
    TIM4_IRQHandler,                   /*   TIM4          */
    I2C1_IRQHandler,                   /*   I2C1          */
    0,                                 /*   Reserved      */
    I2C2_IRQHandler,                   /*   I2C2          */
    0,                                 /*   Reserved      */
    SPI1_IRQHandler,                   /*   SPI1          */
    SPI2_IRQHandler,                   /*   SPI2          */
    UART1_IRQHandler,                  /*   UART1         */
    UART2_IRQHandler,                  /*   UART2         */
    UART3_IRQHandler,                  /*   UART3         */
    EXTI15_10_IRQHandler,              /*   EXTI15~10     */
    RTC_ALR_IRQHandler,                /*   RTCAlarm      */
    USB_WKUP_IRQHandler,               /*   USB WKUP      */
    TIM8_BRK_IRQHandler,               /*   TIM8 BRK      */
    TIM8_UP_IRQHandler,                /*   TIM8 UP       */
    TIM8_TRG_COM_IRQHandler,           /*   TIM8 TRG COM  */
    TIM8_CC_IRQHandler,                /*   TIM8 CC       */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    TIM5_IRQHandler,                   /*   TIM5          */
    SPI3_IRQHandler,                   /*   SPI3          */
    UART4_IRQHandler,                  /*   UART4         */
    UART5_IRQHandler,                  /*   UART5         */
    TIM6_IRQHandler,                   /*   TIM6          */
    TIM7_IRQHandler,                   /*   TIM7          */
    DMA2_CH1_IRQHandler,               /*   DMA2 Channel1 */
    DMA2_CH2_IRQHandler,               /*   DMA2 Channel2 */
    DMA2_CH3_IRQHandler,               /*   DMA2 Channel3 */
    DMA2_CH4_IRQHandler,               /*   DMA2 Channel4 */
    DMA2_CH5_IRQHandler,               /*   DMA2 Channel5 */
    ENET_IRQHandler,                   /*   ENET          */
    ENET_WKUP_IRQHandler,              /*   ENET_WKUP     */
    0,                                 /*   Reserved      */
    COMP_IRQHandler,                   /*   COMP          */
    FlexCAN2_IRQHandler,               /*   FlexCAN2      */
    0,                                 /*   Reserved      */
    USB_FS_IRQHandler,                 /*   USB           */
    DMA2_CH6_IRQHandler,               /*   DMA2 Channel6 */
    DMA2_CH7_IRQHandler,               /*   DMA2 Channel7 */
    DMA2_CH8_IRQHandler,               /*   DMA2 Channel8 */
    UART6_IRQHandler,                  /*   UART6         */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    UART7_IRQHandler,                  /*   UART7         */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    QSPI_IRQHandler,                   /*   QSPI          */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    LPTIM_IRQHandler,                  /*   LPTIM         */
    0,                                 /*   Reserved      */
    LPUART_IRQHandler,                 /*   LPUART        */
    0,                                 /*   Reserved      */
    0,                                 /*   Reserved      */
    0                                  /*   Reserved      */
};

#if defined (__GNUC__)
#pragma GCC diagnostic pop
#endif

/***********************************************************************************************************************
   Reset Handler called on controller reset
  *********************************************************************************************************************/
void Reset_Handler(void)
{
    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));

    SystemInit();                      /* CMSIS System Initialization */

    __PROGRAM_START();                 /* Enter PreMain (C library entry point) */
}

/***********************************************************************************************************************
   Default Handler for Exceptions / Interrupts
  *********************************************************************************************************************/
void Default_Handler(void)
{
    while (1)
    {
    }
}

