/***********************************************************************************************************************
    @file     hal_rcc.h
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
#ifndef __HAL_RCC_H
#define __HAL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup RCC_HAL
  * @brief RCC HAL modules
  * @{
  */

/** @defgroup RCC_Exported_Types
  * @{
  */

/** @defgroup RCC_Exported_Constants
  * @{
  */

/**
  * @brief HSE configuration
  */
#define RCC_HSE_OFF                      (0x00U << RCC_CR_HSEON_Pos)  /* HSE OFF */
#define RCC_HSE_ON                       (0x01U << RCC_CR_HSEON_Pos)  /* HSE ON */
#define RCC_HSE_Bypass                   (0x01U << RCC_CR_HSEBYP_Pos) /* HSE Bypass */

/**
  * @brief RCC Flag
  */
/* Flags in the CR register */
#define RCC_FLAG_HSIRDY                  ((uint8_t)((1 << 5U) | RCC_CR_HSIRDY_Pos))    /*!< Internal High Speed clock ready flag */
#define RCC_FLAG_HSERDY                  ((uint8_t)((1 << 5U) | RCC_CR_HSERDY_Pos))    /*!< External High Speed clock ready flag */
#define RCC_FLAG_PLL1RDY                 ((uint8_t)((1 << 5U) | RCC_CR_PLL1RDY_Pos))   /*!< PLL clock ready flag */
#define RCC_FLAG_PLL2RDY                 ((uint8_t)((1 << 5U) | RCC_CR_PLL2RDY_Pos))   /*!< PLL clock ready flag */

/* Flags in the BDCR register */
#define RCC_FLAG_LSERDY                  ((uint8_t)((2 << 5U) | RCC_BDCR_LSERDY_Pos))  /*!< External Low Speed oscillator Ready */

/* Flags in the CSR register */
#define RCC_FLAG_LSIRDY                  ((uint8_t)((3 << 5U) | RCC_CSR_LSIRDY_Pos))   /*!< Internal Low Speed oscillator Ready */
#define RCC_FLAG_PINRST                  ((uint8_t)((3 << 5U) | RCC_CSR_PINRSTF_Pos))  /*!< PIN reset flag */
#define RCC_FLAG_PORRST                  ((uint8_t)((3 << 5U) | RCC_CSR_PORRSTF_Pos))  /*!< POR/PDR reset flag */
#define RCC_FLAG_SFTRST                  ((uint8_t)((3 << 5U) | RCC_CSR_SFTRSTF_Pos))  /*!< Software Reset flag */
#define RCC_FLAG_IWDGRST                 ((uint8_t)((3 << 5U) | RCC_CSR_IWDGRSTF_Pos)) /*!< Independent Watchdog reset flag */
#define RCC_FLAG_WWDGRST                 ((uint8_t)((3 << 5U) | RCC_CSR_WWDGRSTF_Pos)) /*!< Window watchdog reset flag */

/**
  * @brief PLL1 entry clock source
  */
#define RCC_PLL1Source_HSI               (0x00U << RCC_PLL1CFGR_PLL1SRC_Pos)
#define RCC_PLL1Source_HSE               (0x01U << RCC_PLL1CFGR_PLL1SRC_Pos)

/**
  * @brief PLL2 entry clock source
  */
#define RCC_PLL2Source_HSI               (0x00U << RCC_PLL2CFGR_PLL2SRC_Pos)
#define RCC_PLL2Source_HSE               (0x01U << RCC_PLL2CFGR_PLL2SRC_Pos)

/**
  * @brief System clock source
  */
#define RCC_SYSCLKSource_HSI             (0x00U << RCC_CFGR_SW_Pos)   /* Set HSI as systemCLOCK */
#define RCC_SYSCLKSource_HSE             (0x01U << RCC_CFGR_SW_Pos)   /* Set HSE as systemCLOCK */
#define RCC_SYSCLKSource_PLL1            (0x02U << RCC_CFGR_SW_Pos)   /* Set PLL as systemCLOCK */
#define RCC_SYSCLKSource_LSI             (0x03U << RCC_CFGR_SW_Pos)   /* Set LSI as systemCLOCK */

/**
  * @brief HSI clock source
  */
#define RCC_HSI_Div1                     (0x00U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 1   factor  */
#define RCC_HSI_Div2                     (0x01U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 2   factor  */
#define RCC_HSI_Div4                     (0x02U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 4   factor  */
#define RCC_HSI_Div8                     (0x03U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 8   factor  */
#define RCC_HSI_Div16                    (0x04U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 16  factor  */
#define RCC_HSI_Div32                    (0x05U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 32  factor  */
#define RCC_HSI_Div64                    (0x06U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 64  factor  */
#define RCC_HSI_Div128                   (0x07U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 128 factor  */

/**
  * @brief AHB clock source
  */
#define RCC_SYSCLK_Div1                  (0x00U << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div2                  (0x08U << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div4                  (0x09U << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div8                  (0x0AU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div16                 (0x0BU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div64                 (0x0CU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div128                (0x0DU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div256                (0x0EU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div512                (0x0FU << RCC_CFGR_HPRE_Pos)

#define RCC_HCLK_Div1                    0x00
#define RCC_HCLK_Div2                    0x04
#define RCC_HCLK_Div4                    0x05
#define RCC_HCLK_Div8                    0x06
#define RCC_HCLK_Div16                   0x07

/**
  * @brief RCC Interrupt source
  */
#define RCC_IT_LSIRDY                    0x01
#define RCC_IT_LSERDY                    0x02
#define RCC_IT_HSIRDY                    0x04
#define RCC_IT_HSERDY                    0x08
#define RCC_IT_PLL1RDY                   0x10
#define RCC_IT_PLL2RDY                   0x20

/**
  * @brief LSE configuration
  */
#define RCC_LSE_OFF                      (0x00U << RCC_BDCR_LSEON_Pos)  /* LSE OFF */
#define RCC_LSE_ON                       (0x01U << RCC_BDCR_LSEON_Pos)  /* LSE ON */
#define RCC_LSE_Bypass                   (0x01U << RCC_BDCR_LSEBYP_Pos) /* LSE Bypass */

/**
  * @brief RTC clock source
  */
#define RCC_RTCCLKSource_LSE             (0x01U << RCC_BDCR_RTCSEL_Pos)
#define RCC_RTCCLKSource_LSI             (0x02U << RCC_BDCR_RTCSEL_Pos)
#define RCC_RTCCLKSource_HSE_Div128      (0x03U << RCC_BDCR_RTCSEL_Pos)

/**
  * @brief RCC clock frequency type definition
  */
typedef struct
{
    uint32_t SYSCLK_Frequency;         /*!< returns SYSCLK clock frequency. */
    uint32_t HCLK_Frequency;           /*!< returns hclk clock frequency. */
    uint32_t PCLK1_Frequency;          /*!< returns PCLK1 clock frequency. */
    uint32_t PCLK2_Frequency;          /*!< returns PCLK2 clock frequency. */
} RCC_ClocksTypeDef;

#define RCC_AHBPeriph_GPIOA                (0x01U << RCC_AHBENR_GPIOA_Pos)
#define RCC_AHBPeriph_GPIOB                (0x01U << RCC_AHBENR_GPIOB_Pos)
#define RCC_AHBPeriph_GPIOC                (0x01U << RCC_AHBENR_GPIOC_Pos)
#define RCC_AHBPeriph_GPIOD                (0x01U << RCC_AHBENR_GPIOD_Pos)
#define RCC_AHBPeriph_GPIOE                (0x01U << RCC_AHBENR_GPIOE_Pos)
#define RCC_AHBPeriph_GPIOF                (0x01U << RCC_AHBENR_GPIOF_Pos)
#define RCC_AHBPeriph_GPIOG                (0x01U << RCC_AHBENR_GPIOG_Pos)
#define RCC_AHBPeriph_GPIOH                (0x01U << RCC_AHBENR_GPIOH_Pos)
#define RCC_AHBPeriph_GPIOI                (0x01U << RCC_AHBENR_GPIOI_Pos)
#define RCC_AHBPeriph_CRC                  (0x01U << RCC_AHBENR_CRC_Pos)
#define RCC_AHBPeriph_CORDIC               (0x01U << RCC_AHBENR_CORDIC_Pos)
#define RCC_AHBPeriph_ENET                 (0x01U << RCC_AHBENR_ENET_Pos)
#define RCC_AHBPeriph_DMA1                 (0x01U << RCC_AHBENR_DMA1_Pos)
#define RCC_AHBPeriph_DMA2                 (0x01U << RCC_AHBENR_DMA2_Pos)
#define RCC_AHBPeriph_USB_FS               (0x01U << RCC_AHBENR_USB_FS_Pos)
#define RCC_AHBPeriph_FSMC                 (0x01U << RCC_AHBENR_FSMC_Pos)
#define RCC_AHBPeriph_QSPI                 (0x01U << RCC_AHBENR_QSPI_Pos)

#define RCC_APB1Periph_TIM2                (0x01U << RCC_APB1ENR_TIM2_Pos)
#define RCC_APB1Periph_TIM3                (0x01U << RCC_APB1ENR_TIM3_Pos)
#define RCC_APB1Periph_TIM4                (0x01U << RCC_APB1ENR_TIM4_Pos)
#define RCC_APB1Periph_TIM5                (0x01U << RCC_APB1ENR_TIM5_Pos)
#define RCC_APB1Periph_TIM6                (0x01U << RCC_APB1ENR_TIM6_Pos)
#define RCC_APB1Periph_TIM7                (0x01U << RCC_APB1ENR_TIM7_Pos)
#define RCC_APB1Periph_WWDG                (0x01U << RCC_APB1ENR_WWDG_Pos)
#define RCC_APB1Periph_SPI2                (0x01U << RCC_APB1ENR_SPI2_Pos)
#define RCC_APB1Periph_SPI3                (0x01U << RCC_APB1ENR_SPI3_Pos)
#define RCC_APB1Periph_UART2               (0x01U << RCC_APB1ENR_UART2_Pos)
#define RCC_APB1Periph_UART3               (0x01U << RCC_APB1ENR_UART3_Pos)
#define RCC_APB1Periph_UART4               (0x01U << RCC_APB1ENR_UART4_Pos)
#define RCC_APB1Periph_UART5               (0x01U << RCC_APB1ENR_UART5_Pos)
#define RCC_APB1Periph_I2C1                (0x01U << RCC_APB1ENR_I2C1_Pos)
#define RCC_APB1Periph_I2C2                (0x01U << RCC_APB1ENR_I2C2_Pos)
#define RCC_APB1Periph_CRS                 (0x01U << RCC_APB1ENR_CRS_Pos)
#define RCC_APB1Periph_FLEXCAN1            (0x01U << RCC_APB1ENR_FLEXCAN1_Pos)
#define RCC_APB1Periph_BKP                 (0x01U << RCC_APB1ENR_BKP_Pos)
#define RCC_APB1Periph_PWRDBG              (0x01U << RCC_APB1ENR_PWRDBG_Pos)
#define RCC_APB1Periph_DAC                 (0x01U << RCC_APB1ENR_DAC_Pos)
#define RCC_APB1Periph_UART7               (0x01U << RCC_APB1ENR_UART7_Pos)

#define RCC_APB2Periph_TIM1                (0x01U << RCC_APB2ENR_TIM1_Pos)
#define RCC_APB2Periph_TIM8                (0x01U << RCC_APB2ENR_TIM8_Pos)
#define RCC_APB2Periph_UART1               (0x01U << RCC_APB2ENR_UART1_Pos)
#define RCC_APB2Periph_UART6               (0x01U << RCC_APB2ENR_UART6_Pos)
#define RCC_APB2Periph_ADC1                (0x01U << RCC_APB2ENR_ADC1_Pos)
#define RCC_APB2Periph_ADC2                (0x01U << RCC_APB2ENR_ADC2_Pos)
#define RCC_APB2Periph_SPI1                (0x01U << RCC_APB2ENR_SPI1_Pos)
#define RCC_APB2Periph_SYSCFG              (0x01U << RCC_APB2ENR_SYSCFG_Pos)
#define RCC_APB2Periph_COMP                (0x01U << RCC_APB2ENR_COMP_Pos)
#define RCC_APB2Periph_FLEXCAN2            (0x01U << RCC_APB2ENR_FLEXCAN2_Pos)
#define RCC_APB2Periph_MDS                 (0x01U << RCC_APB2ENR_MDS_Pos)
#define RCC_APB2Periph_LPTIM               (0x01U << RCC_APB2ENR_LPTIM_Pos)
#define RCC_APB2Periph_LPUART              (0x01U << RCC_APB2ENR_LPUART_Pos)

/**
  * @brief Clock source to output on MCO pin
  */
#define RCC_MCO_NoClock                    (0x00U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_LSI                        (0x02U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_LSE                        (0x03U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_SYSCLK                     (0x04U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_HSI                        (0x05U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_HSE                        (0x06U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_PLL1                       (0x07U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_PLL2                       (0x08U << RCC_CFGR_MCO_Pos)

/**
  * @brief  MCO predivision coefficient
  */
#define RCC_MCO_Div1                       (0x00U << RCC_CFGR2_MCO_PRE_Pos)
#define RCC_MCO_Div2                       (0x08U << RCC_CFGR2_MCO_PRE_Pos)
#define RCC_MCO_Div4                       (0x09U << RCC_CFGR2_MCO_PRE_Pos)
#define RCC_MCO_Div8                       (0x0AU << RCC_CFGR2_MCO_PRE_Pos)
#define RCC_MCO_Div16                      (0x0BU << RCC_CFGR2_MCO_PRE_Pos)
#define RCC_MCO_Div64                      (0x0CU << RCC_CFGR2_MCO_PRE_Pos)
#define RCC_MCO_Div128                     (0x0DU << RCC_CFGR2_MCO_PRE_Pos)
#define RCC_MCO_Div256                     (0x0EU << RCC_CFGR2_MCO_PRE_Pos)
#define RCC_MCO_Div512                     (0x0FU << RCC_CFGR2_MCO_PRE_Pos)

/**
  * @brief  APB1_HV output clock predivision coefficient
  */
#define RCC_APB1HV_OutputPre_Div1          (0x00U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div8          (0x03U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div10         (0x04U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div12         (0x05U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div14         (0x06U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div16         (0x07U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div18         (0x08U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div20         (0x09U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div22         (0x0AU << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div24         (0x0BU << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div26         (0x0CU << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div28         (0x0DU << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div30         (0x0EU << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)
#define RCC_APB1HV_OutputPre_Div32         (0x0FU << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)

/**
  * @brief  TIMADV clock source
  */
#define RCC_TIMADVCLKSource_PCLK2          (0x00U << RCC_CFGR2_TIMADV_CKSEL_Pos)
#define RCC_TIMADVCLKSource_TIMADVCLK      (0x01U << RCC_CFGR2_TIMADV_CKSEL_Pos)

/**
  * @brief  TIMADV_CLK Predivision Config
  */
#define RCC_TIMADVCLK_Div1                 (0x00U << RCC_CFGR2_TIMADV_PRE_Pos)
#define RCC_TIMADVCLK_Div2                 (0x04U << RCC_CFGR2_TIMADV_PRE_Pos)
#define RCC_TIMADVCLK_Div4                 (0x05U << RCC_CFGR2_TIMADV_PRE_Pos)
#define RCC_TIMADVCLK_Div8                 (0x06U << RCC_CFGR2_TIMADV_PRE_Pos)
#define RCC_TIMADVCLK_Div16                (0x07U << RCC_CFGR2_TIMADV_PRE_Pos)

/**
  * @}
  */

/** @defgroup RCC_Exported_Functions
  * @{
  */
void RCC_DeInit(void);
void RCC_HSEConfig(uint32_t hsesource);
FlagStatus RCC_GetFlagStatus(uint8_t flag);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_HSICmd(FunctionalState state);
void RCC_PLL1Config(uint32_t pll_src, uint32_t pll_pdiv, uint32_t pll_mul, uint32_t pll_div);
void RCC_PLL2Config(uint32_t pll_src, uint32_t pll_pdiv, uint32_t pll_mul, uint32_t pll_div);
void RCC_PLL1Cmd(FunctionalState state);
void RCC_PLL2Cmd(FunctionalState state);
void RCC_SYSCLKConfig(uint32_t sys_clk_src);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HSIConfig(uint32_t clk);
void RCC_HCLKConfig(uint32_t clk);
void RCC_PCLK1Config(uint32_t clk);
void RCC_PCLK2Config(uint32_t clk);
void RCC_ITConfig(uint8_t it, FunctionalState state);
ITStatus RCC_GetITStatus(uint8_t it);
void RCC_ClearITPendingBit(uint8_t it);
void RCC_LSEConfig(uint32_t rcc_lse);
void RCC_LSICmd(FunctionalState state);
void RCC_RTCCLKConfig(uint32_t rtc_clk_src);
void RCC_RTCCLKCmd(FunctionalState state);
void RCC_GetClocksFreq(RCC_ClocksTypeDef *clk);
void RCC_AHBPeriphClockCmd(uint32_t ahb_periph, FunctionalState state);
void RCC_APB2PeriphClockCmd(uint32_t apb2_periph, FunctionalState state);
void RCC_APB1PeriphClockCmd(uint32_t apb1_periph, FunctionalState state);
void RCC_AHBPeriphResetCmd(uint32_t ahb1_periph, FunctionalState state);
void RCC_APB2PeriphResetCmd(uint32_t apb2_periph, FunctionalState state);
void RCC_APB1PeriphResetCmd(uint32_t apb1_periph, FunctionalState state);
void RCC_ClockSecuritySystemCmd(FunctionalState state);
void RCC_MCOConfig(uint32_t mco_src);
void RCC_MCOPrescalerConfig(uint32_t pre_sel);
void RCC_ClearFlag(void);
void RCC_BackupResetCmd(FunctionalState state);

void RCC_APB1HVOutputPreConfig(uint32_t div_sel);
void RCC_TIMADVCLKConfig(uint32_t clk_sel);
void RCC_TIMADVPrescalerConfig(uint32_t div_sel);
void RCC_HSITrimUseCrsModuleCmd(FunctionalState state);

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

/*----------------------------------------------------------------------------*/
#endif /* __HAL_RCC_H ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

