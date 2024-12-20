/***********************************************************************************************************************
    @file     mm32f5260.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
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

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __MM32F5260_H
#define __MM32F5260_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__CC_ARM)
#pragma anon_unions
#elif defined(__ICCARM__)
#pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined(__GNUC__)
/* anonymous unions are enabled by default -----------------------------------*/
#else
#warning Not supported compiler type
#endif

extern void SystemInit(void);


/* MM32 Library version is V0.10 --------------------------------------------*/

#define __MM32_LIB_VERSION_MAIN                 (0x00U) /*!< [15:8] main version */
#define __MM32_LIB_VERSION_SUB                  (0x10U) /*!< [7:0]  sub version */
#define __MM32_LIB_VERSION               \
        ((__MM32_LIB_VERSION_MAIN << 8U) \
         | (__MM32_LIB_VERSION_SUB << 0U))

/* MM32 Library release date is 2024-09-27 -----------------------------------*/
#define __MM32_LIB_RELESE_YEARH                 (0x20U) /*!< [31:24] release year high */
#define __MM32_LIB_RELESE_YEARL                 (0x24U) /*!< [23:16] release year low */
#define __MM32_LIB_RELESE_MONTH                 (0x09U) /*!< [15:8]  release month */
#define __MM32_LIB_RELESE_DAY                   (0x27U) /*!< [7:0]   release day */
#define __MM32_LIB_RELESE_DATE              \
        ((__MM32_LIB_RELESE_YEARH << 24U)   \
         | (__MM32_LIB_RELESE_YEARL << 16U) \
         | (__MM32_LIB_RELESE_MONTH << 8U)  \
         | (__MM32_LIB_RELESE_DAY << 0U))

#define HSI_STARTUP_TIMEOUT                     (0x8000U) /*!< Time out for HSI start up. */
#define HSE_STARTUP_TIMEOUT                     (0x8000U) /*!< Time out for HSE start up. */


#ifdef  CUSTOM_HSE_VAL
#define HSE_VALUE                               (12000000U) /*!< Value of the External oscillator in Hz. */
#else
#define HSE_VALUE                               (8000000U) /*!< Value of the External oscillator in Hz. */
#endif

#define LSE_VALUE                               (32768U)        /*!< Value of the External low oscillator in Hz. */
#define HSI_VALUE                               (8000000U) /*!< Value of the Internal oscillator in Hz. */
#define LSI_VALUE                               (40000U) /*!< Value of the Internal oscillator in Hz. */


/**
  * @brief Configuration of the Cortex-Star Processor and Core Peripherals
  */
#define __STAR_REV                              (0x0100U)
#define __FPU_PRESENT                           (1U) /*!< FPU present                                   */
#define __DSP_PRESENT                           (1U) /*!< star MC1 provides an DSP                      */
#define __SAUREGION_PRESENT                     (0U)
#define __MPU_PRESENT                           (1U) /*!< star MC1 provides an MPU                      */
#define __ICACHE_PRESENT                        (1U) /*!< star MC1 instruction cache present            */
#define __DCACHE_PRESENT                        (1U) /*!< star MC1 data cache present                   */
#define __DTCM_PRESENT                          (0U)
#define __NVIC_PRIO_BITS                        (4U) 
#define __Vendor_SysTickConfig                  (0U) /*!< Set to 1 if different SysTick Config is used  */


/**
  * @brief  MM32 MCU Interrupt Handle
  */
typedef enum IRQn
{
    NMI_IRQn                    = -14, /*!< -14 NMI Interrupt                                    */
    HardFault_IRQn              = -13, /*!< -13 Hard Fault Interrupt                             */
    MemManage_IRQn              = -12, /*!< -12 Memory management Interrupt                      */
    BusFault_IRQn               = -11, /*!< -11 Bus Fault Interrupt                              */
    UsageFault_IRQn             = -10, /*!< -10 Usage Fault Interrupt                            */
    SVCall_IRQn                 = -5,  /*!< -5 SVCall Interrupt                                  */
    DebugMon_IRQn               = -4,  /*!< -4 Debug Monitor Interrupt                           */
    PendSV_IRQn                 = -2,  /*!< -2 PendSV Interrupt                                  */
    SysTick_IRQn                = -1,  /*!< -1 SysTick Interrupt                                 */

    WWDG_IWDG_IRQn              = 0,   /*!< Window WatchDog Interrupt                            */
    PVD_IRQn                    = 1,   /*!< PVD through EXTI Line detection Interrupt            */
    BKP_TAMPER_IRQn             = 2,   /*!< BKP tamper Interrupt                                 */
    RTC_IRQn                    = 3,   /*!< RTC global Interrupt                                 */
    FLASH_IRQn                  = 4,   /*!< FLASH global Interrupt                               */
    RCC_CRS_IRQn                = 5,   /*!< RCC and CRS global Interrupt                         */
    EXTI0_IRQn                  = 6,   /*!< EXTI Line0 Interrupt                                 */
    EXTI1_IRQn                  = 7,   /*!< EXTI Line1 Interrupt                                 */
    EXTI2_IRQn                  = 8,   /*!< EXTI Line2 Interrupt                                 */
    EXTI3_IRQn                  = 9,   /*!< EXTI Line3 Interrupt                                 */
    EXTI4_IRQn                  = 10,  /*!< EXTI Line4 Interrupt                                 */
    DMA1_CH1_IRQn               = 11,  /*!< DMA1 Channel 1 global Interrupt                      */
    DMA1_CH2_IRQn               = 12,  /*!< DMA1 Channel 2 global Interrupt                      */
    DMA1_CH3_IRQn               = 13,  /*!< DMA1 Channel 3 global Interrupt                      */
    DMA1_CH4_IRQn               = 14,  /*!< DMA1 Channel 4 global Interrupt                      */
    DMA1_CH5_IRQn               = 15,  /*!< DMA1 Channel 5 global Interrupt                      */
    DMA1_CH6_IRQn               = 16,  /*!< DMA1 Channel 6 global Interrupt                      */
    DMA1_CH7_IRQn               = 17,  /*!< DMA1 Channel 7 global Interrupt                      */
    ADC1_2_IRQn                 = 18,  /*!< ADC1 et ADC2 global Interrupt                        */
    DMA1_CH8_IRQn               = 20,  /*!< DMA1 Channel 8 global Interrupt                      */
    FlexCAN1_IRQn               = 21,  /*!< FlexCAN1 Interrupt                                   */
    EXTI9_5_IRQn                = 23,  /*!< External Line[9:5] Interrupts                        */
    TIM1_BRK_IRQn               = 24,  /*!< TIM1 Break Interrupt                                 */
    TIM1_UP_IRQn                = 25,  /*!< TIM1 Update Interrupt                                */
    TIM1_TRG_COM_IRQn           = 26,  /*!< TIM1 Trigger and Commutation Interrupt               */
    TIM1_CC_IRQn                = 27,  /*!< TIM1 Capture Compare Interrupt                       */
    TIM2_IRQn                   = 28,  /*!< TIM2 global Interrupt                                */
    TIM3_IRQn                   = 29,  /*!< TIM3 global Interrupt                                */
    TIM4_IRQn                   = 30,  /*!< TIM4 global Interrupt                                */
    I2C1_IRQn                   = 31,  /*!< I2C1 Event Interrupt                                 */
    I2C2_IRQn                   = 33,  /*!< I2C2 Event Interrupt                                 */
    SPI1_IRQn                   = 35,  /*!< SPI1 global Interrupt                                */
    SPI2_IRQn                   = 36,  /*!< SPI2 global Interrupt                                */
    UART1_IRQn                  = 37,  /*!< UART1 global Interrupt                               */
    UART2_IRQn                  = 38,  /*!< UART2 global Interrupt                               */
    UART3_IRQn                  = 39,  /*!< UART3 global Interrupt                               */
    EXTI15_10_IRQn              = 40,  /*!< External Line[15:10] Interrupts                      */
    RTC_ALR_IRQn                = 41,  /*!< RTC Alarm through EXTI Line Interrupt                */
    USB_WKUP_IRQn               = 42,  /*!< USB WakeUp from suspend through EXTI Line Interrupt  */
    TIM8_BRK_IRQn               = 43,  /*!< TIM8 Break Interrupt                                 */
    TIM8_UP_IRQn                = 44,  /*!< TIM8 Update Interrupt                                */
    TIM8_TRG_COM_IRQn           = 45,  /*!< TIM8 Trigger and Commutation Interrupt               */
    TIM8_CC_IRQn                = 46,  /*!< TIM8 Capture Compare Interrupt                       */
    TIM5_IRQn                   = 50,  /*!< TIM5              */
    SPI3_IRQn                   = 51,  /*!< SPI3              */
    UART4_IRQn                  = 52,  /*!< UART4             */
    UART5_IRQn                  = 53,  /*!< UART5             */
    TIM6_IRQn                   = 54,  /*!< TIM6              */
    TIM7_IRQn                   = 55,  /*!< TIM7              */
    DMA2_CH1_IRQn               = 56,  /*!< DMA2 Channel 1    */
    DMA2_CH2_IRQn               = 57,  /*!< DMA2 Channel 2    */
    DMA2_CH3_IRQn               = 58,  /*!< DMA2 Channel 3    */
    DMA2_CH4_IRQn               = 59,  /*!< DMA2 Channel 4    */
    DMA2_CH5_IRQn               = 60,  /*!< DMA2 Channel 5    */
    ENET_IRQn                   = 61,  /*!< ENET              */
    ENET_WKUP_IRQn              = 62,  /*!< ENET_WKUP         */
    COMP_IRQn                   = 64,  /*!< COMP              */
    FlexCAN2_IRQn               = 65,  /*!< FlexCAN2          */
    USB_FS_IRQn                 = 67,  /*!< USB_FS global Interrupt */
    DMA2_CH6_IRQn               = 68,  /*!< DMA2 Channel 6    */
    DMA2_CH7_IRQn               = 69,  /*!< DMA2 Channel 7    */
    DMA2_CH8_IRQn               = 70,  /*!< DMA2 Channel 8    */
    UART6_IRQn                  = 71,  /*!< UART6             */
    UART7_IRQn                  = 82,  /*!< UART7             */
    QSPI_IRQn                   = 95,  /*!< QSPI              */
    LPTIM_IRQn                  = 102, /*!< LPTIM             */
    LPUART_IRQn                 = 104  /*!< LPUART            */
} IRQn_Type;

#include "core_starmc1.h"
#include <stdint.h>
#include <stdbool.h>

typedef int64_t                         s64;
typedef uint64_t                        u64;
typedef int32_t                         s32;
typedef int16_t                         s16;
typedef int8_t                          s8;

typedef const int32_t                   sc32; /*!< Read Only */
typedef const int16_t                   sc16; /*!< Read Only */
typedef const int8_t                    sc8;  /*!< Read Only */

typedef __IO int32_t                    vs32;
typedef __IO int16_t                    vs16;
typedef __IO int8_t                     vs8;

typedef __I int32_t                     vsc32; /*!< Read Only */
typedef __I int16_t                     vsc16; /*!< Read Only */
typedef __I int8_t                      vsc8;  /*!< Read Only */

typedef uint32_t                        u32;
typedef uint16_t                        u16;
typedef uint8_t                         u8;

typedef const uint32_t                  uc32; /*!< Read Only */
typedef const uint16_t                  uc16; /*!< Read Only */
typedef const uint8_t                   uc8;  /*!< Read Only */

typedef __IO uint32_t                   vu32;
typedef __IO uint16_t                   vu16;
typedef __IO uint8_t                    vu8;

typedef __I uint32_t                    vuc32; /*!< Read Only */
typedef __I uint16_t                    vuc16; /*!< Read Only */
typedef __I uint8_t                     vuc8;  /*!< Read Only */

typedef bool                            BOOL;

#ifndef NULL
#define NULL                            ((void *)0)
#endif

typedef enum
{
    RESET = 0,
    SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
    DISABLE = 0,
    ENABLE  = !DISABLE
} FunctionalState;

typedef enum
{
    ERROR = 0,
    SUCCESS = !ERROR
} ErrorStatus;

#define U8_MAX                  ((u8)255)
#define S8_MAX                  ((s8)127)
#define S8_MIN                  ((s8) - 128)
#define U16_MAX                 ((u16)65535u)
#define S16_MAX                 ((s16)32767)
#define S16_MIN                 ((s16) - 32768)
#define U32_MAX                 ((u32)4294967295uL)
#define S32_MAX                 ((s32)2147483647)
#define S32_MIN                 ((s32) - 2147483648uL)

#define MAX(a, b)             ((a) > (b) ? (a) : (b))
#define MIN(a, b)             ((a) < (b) ? (a) : (b))

#define SET_BIT(reg, bit)     ((reg) = (reg) | (bit))
#define CLEAR_BIT(reg, bit)   ((reg) = (reg) & (~(bit)))
#define READ_BIT(reg, bit)    ((reg) & (bit))
#define CLEAR_REG(reg)        ((reg) = (0x0))
#define WRITE_REG(reg, value) ((reg) = (value))
#define READ_REG(reg)         ((reg))
#define MODIFY_REG(reg, MASK_CLEAR, SET_BITS)                   \
        WRITE_REG((reg), (((READ_REG(reg)) & (~(MASK_CLEAR))) | \
                          ((SET_BITS)&(MASK_CLEAR))))

#define POSITION_VAL(value)   (__CLZ(__RBIT(value)))

#ifndef LEFT_SHIFT_BIT
#define LEFT_SHIFT_BIT(x)     (1 << x)
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x)         (sizeof(x) / sizeof((x)[0]))
#endif

#define PERIPH_BASE             (0x40000000U) /*!< Peripheral base address in the alias region */
#define APB1PERIPH_BASE         (PERIPH_BASE + 0x00000000)
#define APB2PERIPH_BASE         (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE         (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE         (0x50000000U)

/**
  * @brief UID type pointer Definition
  */
#define UID_BASE                (0x1FFFF7E8U) /*!< Unique device ID register base address */

#include "reg_adc.h"
#include "reg_bkp.h"
#include "reg_comp.h"
#include "reg_cordic.h"
#include "reg_crcpoly.h"
#include "reg_crs.h"
#include "reg_dac.h"
#include "reg_dbg.h"
#include "reg_dma.h"
#include "reg_enet.h"
#include "reg_exti.h"
#include "reg_flash.h"
#include "reg_flexcan.h"
#include "reg_fsmc.h"
#include "reg_gpio.h"
#include "reg_i2c.h"
#include "reg_iwdg.h"
#include "reg_lpuart.h"
#include "reg_lptim.h"
#include "reg_mds.h"
#include "reg_pwr.h"
#include "reg_qspi.h"
#include "reg_rcc.h"
#include "reg_rtc.h"
#include "reg_spi.h"
#include "reg_syscfg.h"
#include "reg_tim.h"
#include "reg_uart.h"
#include "reg_usb_fs.h"
#include "reg_wwdg.h"

#ifdef USE_STDPERIPH_DRIVER
#include "hal_conf.h"
#endif

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

/** --------------------------------------------------------------------------*/
#endif
/** --------------------------------------------------------------------------*/
