/***********************************************************************************************************************
    @file     reg_rcc.h
    @author   VV TEAM
    @brief    This flie contains all the RCC's register and its field definition.
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

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/

#ifndef __REG_RCC_H
#define __REG_RCC_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief RCC Base Address Definition
  */
#define  RCC_BASE                                  0x40021000 /*!<Base Address: 0x40021000*/

/**
  * @brief RCC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                  /*!<RCC Clock Control Register                     offset: 0x00*/
    __IO uint32_t CFGR;                /*!<RCC Clock Configuration Register               offset: 0x04*/
    __IO uint32_t CIR;                 /*!<RCC Clock Interrupt Register                   offset: 0x08*/
    __IO uint32_t RESERVED0x00C[2];    /*!<                                               offset: 0xc~0x10*/
    __IO uint32_t AHBRSTR;             /*!<RCC AHB Peripheral Reset Register              offset: 0x14*/
    __IO uint32_t APB2RSTR;            /*!<RCC APB2 Peripheral Reset Register             offset: 0x18*/
    __IO uint32_t APB1RSTR;            /*!<RCC APB1 Peripheral Reset Register             offset: 0x1C*/
    __IO uint32_t RESERVED0x020[2];    /*!<                                               offset: 0x20~0x24*/
    __IO uint32_t AHBENR;              /*!<RCC AHB Peripheral Clock Enable Register       offset: 0x28*/
    __IO uint32_t APB2ENR;             /*!<RCC APB2 Peripheral Clock Enable Register      offset: 0x2C*/
    __IO uint32_t APB1ENR;             /*!<RCC APB1 Peripheral Clock Enable Register      offset: 0x30*/
    __IO uint32_t BDCR;                /*!<RCC Backup Domain Control Register             offset: 0x34*/
    __IO uint32_t CSR;                 /*!<RCC Control Status Register                    offset: 0x38*/
    __IO uint32_t SYSCFGR;             /*!<RCC System Configuration Register              offset: 0x3C*/
    __IO uint32_t CFGR2;               /*!<RCC Clock Configuration Register 2             offset: 0x40*/
    __IO uint32_t ICSCR;               /*!<RCC Internal Clock Source Calibration Register offset: 0x44*/
    __IO uint32_t PLL1CFGR;            /*!<RCC PLL1 Configuration Register                offset: 0x48*/
    __IO uint32_t PLL2CFGR;            /*!<RCC PLL2 Configuration Register                offset: 0x4C*/
    __IO uint32_t RESERVED0x050[4];    /*!<                                               offset: 0x50~0x5c*/
    __IO uint32_t ADC1CFGR;            /*!<RCC ADC1 Configuration Register                offset: 0x60*/
    __IO uint32_t ADC2CFGR;            /*!<RCC ADC2 Configuration Register                offset: 0x64*/
    __IO uint32_t RESERVED0x068[2];    /*!<                                               offset: 0x68~0x6c*/
    __IO uint32_t DACCFGR;             /*!<RCC DAC Configuration Register                 offset: 0x70*/
    __IO uint32_t RESERVED0x074[2];    /*!<                                               offset: 0x74~0x78*/
    __IO uint32_t TPIUCFGR;            /*!<RCC TPIU Configuration Register                offset: 0x7C*/
} RCC_TypeDef;

/**
  * @brief RCC type pointer Definition
  */
#define RCC                                       ((RCC_TypeDef *)RCC_BASE)

/**
  * @brief RCC_CR Register Bit Definition
  */
#define  RCC_CR_HSION_Pos                         (0)
#define  RCC_CR_HSION_Msk                         (0x01U << RCC_CR_HSION_Pos)               /*!<*/
#define  RCC_CR_HSIRDY_Pos                        (1)
#define  RCC_CR_HSIRDY_Msk                        (0x01U << RCC_CR_HSIRDY_Pos)              /*!<*/
#define  RCC_CR_HSELPFBYP_Pos                     (4)
#define  RCC_CR_HSELPFBYP_Msk                     (0x01U << RCC_CR_HSELPFBYP_Pos)           /*!<*/
#define  RCC_CR_HSELPFSEL_Pos                     (5)
#define  RCC_CR_HSELPFSEL_Msk                     (0x01U << RCC_CR_HSELPFSEL_Pos)           /*!<*/
#define  RCC_CR_HSEDEGLITCHBYP_Pos                (6)
#define  RCC_CR_HSEDEGLITCHBYP_Msk                (0x01U << RCC_CR_HSEDEGLITCHBYP_Pos)      /*!<*/
#define  RCC_CR_HSEDEGLITCHSEL_Pos                (7)
#define  RCC_CR_HSEDEGLITCHSEL_Msk                (0x01U << RCC_CR_HSEDEGLITCHSEL_Pos)      /*!<*/
#define  RCC_CR_HSEOUTPUTSEL_Pos                  (8)
#define  RCC_CR_HSEOUTPUTSEL_Msk                  (0x01U << RCC_CR_HSEOUTPUTSEL_Pos)        /*!<*/
#define  RCC_CR_HSEDR_Pos                         (9)
#define  RCC_CR_HSEDR_Msk                         (0x03U << RCC_CR_HSEDR_Pos)               /*!<*/
#define  RCC_CR_HSIDIV_Pos                        (11)
#define  RCC_CR_HSIDIV_Msk                        (0x07U << RCC_CR_HSIDIV_Pos)              /*!<*/
#define  RCC_CR_HSEON_Pos                         (16)
#define  RCC_CR_HSEON_Msk                         (0x01U << RCC_CR_HSEON_Pos)               /*!<*/
#define  RCC_CR_HSERDY_Pos                        (17)
#define  RCC_CR_HSERDY_Msk                        (0x01U << RCC_CR_HSERDY_Pos)              /*!<*/
#define  RCC_CR_HSEBYP_Pos                        (18)
#define  RCC_CR_HSEBYP_Msk                        (0x01U << RCC_CR_HSEBYP_Pos)              /*!<*/
#define  RCC_CR_CSSON_Pos                         (19)
#define  RCC_CR_CSSON_Msk                         (0x01U << RCC_CR_CSSON_Pos)               /*!<*/
#define  RCC_CR_HSEAACSEL_Pos                     (21)
#define  RCC_CR_HSEAACSEL_Msk                     (0x01U << RCC_CR_HSEAACSEL_Pos)           /*!<*/
#define  RCC_CR_HSEIB_Pos                         (22)
#define  RCC_CR_HSEIB_Msk                         (0x03U << RCC_CR_HSEIB_Pos)               /*!<*/
#define  RCC_CR_PLL1ON_Pos                        (24)
#define  RCC_CR_PLL1ON_Msk                        (0x01U << RCC_CR_PLL1ON_Pos)              /*!<*/
#define  RCC_CR_PLL1RDY_Pos                       (25)
#define  RCC_CR_PLL1RDY_Msk                       (0x01U << RCC_CR_PLL1RDY_Pos)             /*!<*/
#define  RCC_CR_PLL2ON_Pos                        (28)
#define  RCC_CR_PLL2ON_Msk                        (0x01U << RCC_CR_PLL2ON_Pos)              /*!<*/
#define  RCC_CR_PLL2RDY_Pos                       (29)
#define  RCC_CR_PLL2RDY_Msk                       (0x01U << RCC_CR_PLL2RDY_Pos)             /*!<*/

/**
  * @brief RCC_CFGR Register Bit Definition
  */
#define  RCC_CFGR_SW_Pos                          (0)
#define  RCC_CFGR_SW_Msk                          (0x03U << RCC_CFGR_SW_Pos)         /*!<*/
#define  RCC_CFGR_SWS_Pos                         (2)
#define  RCC_CFGR_SWS_Msk                         (0x03U << RCC_CFGR_SWS_Pos)        /*!<*/
#define  RCC_CFGR_HPRE_Pos                        (4)
#define  RCC_CFGR_HPRE_Msk                        (0x0FU << RCC_CFGR_HPRE_Pos)       /*!<*/
#define  RCC_CFGR_PPRE1_Pos                       (8)
#define  RCC_CFGR_PPRE1_Msk                       (0x07U << RCC_CFGR_PPRE1_Pos)      /*!<*/
#define  RCC_CFGR_PPRE2_Pos                       (11)
#define  RCC_CFGR_PPRE2_Msk                       (0x07U << RCC_CFGR_PPRE2_Pos)      /*!<*/
#define  RCC_CFGR_ADC1CLKSEL_Pos                  (16)
#define  RCC_CFGR_ADC1CLKSEL_Msk                  (0x01U << RCC_CFGR_ADC1CLKSEL_Pos) /*!<*/
#define  RCC_CFGR_ADC2CLKSEL_Pos                  (17)
#define  RCC_CFGR_ADC2CLKSEL_Msk                  (0x01U << RCC_CFGR_ADC2CLKSEL_Pos) /*!<*/
#define  RCC_CFGR_USBCLKSEL_Pos                   (19)
#define  RCC_CFGR_USBCLKSEL_Msk                   (0x01U << RCC_CFGR_USBCLKSEL_Pos)  /*!<*/
#define  RCC_CFGR_USBPRE_Pos                      (22)
#define  RCC_CFGR_USBPRE_Msk                      (0x03U << RCC_CFGR_USBPRE_Pos)     /*!<*/
#define  RCC_CFGR_MCO_Pos                         (24)
#define  RCC_CFGR_MCO_Msk                         (0x0FU << RCC_CFGR_MCO_Pos)        /*!<*/

/**
  * @brief RCC_CIR Register Bit Definition
  */
#define  RCC_CIR_LSIRDYF_Pos                      (0)
#define  RCC_CIR_LSIRDYF_Msk                      (0x01U << RCC_CIR_LSIRDYF_Pos)   /*!<*/
#define  RCC_CIR_LSERDYF_Pos                      (1)
#define  RCC_CIR_LSERDYF_Msk                      (0x01U << RCC_CIR_LSERDYF_Pos)   /*!<*/
#define  RCC_CIR_HSIRDYF_Pos                      (2)
#define  RCC_CIR_HSIRDYF_Msk                      (0x01U << RCC_CIR_HSIRDYF_Pos)   /*!<*/
#define  RCC_CIR_HSERDYF_Pos                      (3)
#define  RCC_CIR_HSERDYF_Msk                      (0x01U << RCC_CIR_HSERDYF_Pos)   /*!<*/
#define  RCC_CIR_PLL1RDYF_Pos                     (4)
#define  RCC_CIR_PLL1RDYF_Msk                     (0x01U << RCC_CIR_PLL1RDYF_Pos)  /*!<*/
#define  RCC_CIR_PLL2RDYF_Pos                     (5)
#define  RCC_CIR_PLL2RDYF_Msk                     (0x01U << RCC_CIR_PLL2RDYF_Pos)  /*!<*/
#define  RCC_CIR_CSSF_Pos                         (7)
#define  RCC_CIR_CSSF_Msk                         (0x01U << RCC_CIR_CSSF_Pos)      /*!<*/
#define  RCC_CIR_LSIRDYIE_Pos                     (8)
#define  RCC_CIR_LSIRDYIE_Msk                     (0x01U << RCC_CIR_LSIRDYIE_Pos)  /*!<*/
#define  RCC_CIR_LSERDYIE_Pos                     (9)
#define  RCC_CIR_LSERDYIE_Msk                     (0x01U << RCC_CIR_LSERDYIE_Pos)  /*!<*/
#define  RCC_CIR_HSIRDYIE_Pos                     (10)
#define  RCC_CIR_HSIRDYIE_Msk                     (0x01U << RCC_CIR_HSIRDYIE_Pos)  /*!<*/
#define  RCC_CIR_HSERDYIE_Pos                     (11)
#define  RCC_CIR_HSERDYIE_Msk                     (0x01U << RCC_CIR_HSERDYIE_Pos)  /*!<*/
#define  RCC_CIR_PLL1RDYIE_Pos                    (12)
#define  RCC_CIR_PLL1RDYIE_Msk                    (0x01U << RCC_CIR_PLL1RDYIE_Pos) /*!<*/
#define  RCC_CIR_PLL2RDYIE_Pos                    (13)
#define  RCC_CIR_PLL2RDYIE_Msk                    (0x01U << RCC_CIR_PLL2RDYIE_Pos) /*!<*/
#define  RCC_CIR_LSIRDYC_Pos                      (16)
#define  RCC_CIR_LSIRDYC_Msk                      (0x01U << RCC_CIR_LSIRDYC_Pos)   /*!<*/
#define  RCC_CIR_LSERDYC_Pos                      (17)
#define  RCC_CIR_LSERDYC_Msk                      (0x01U << RCC_CIR_LSERDYC_Pos)   /*!<*/
#define  RCC_CIR_HSIRDYC_Pos                      (18)
#define  RCC_CIR_HSIRDYC_Msk                      (0x01U << RCC_CIR_HSIRDYC_Pos)   /*!<*/
#define  RCC_CIR_HSERDYC_Pos                      (19)
#define  RCC_CIR_HSERDYC_Msk                      (0x01U << RCC_CIR_HSERDYC_Pos)   /*!<*/
#define  RCC_CIR_PLL1RDYC_Pos                     (20)
#define  RCC_CIR_PLL1RDYC_Msk                     (0x01U << RCC_CIR_PLL1RDYC_Pos)  /*!<*/
#define  RCC_CIR_PLL2RDYC_Pos                     (21)
#define  RCC_CIR_PLL2RDYC_Msk                     (0x01U << RCC_CIR_PLL2RDYC_Pos)  /*!<*/
#define  RCC_CIR_CSSC_Pos                         (23)
#define  RCC_CIR_CSSC_Msk                         (0x01U << RCC_CIR_CSSC_Pos)      /*!<*/

/**
  * @brief RCC_AHBRSTR Register Bit Definition
  */
#define  RCC_AHBRSTR_GPIOA_Pos                    (0)
#define  RCC_AHBRSTR_GPIOA_Msk                    (0x01U << RCC_AHBRSTR_GPIOA_Pos)  /*!<*/
#define  RCC_AHBRSTR_GPIOB_Pos                    (1)
#define  RCC_AHBRSTR_GPIOB_Msk                    (0x01U << RCC_AHBRSTR_GPIOB_Pos)  /*!<*/
#define  RCC_AHBRSTR_GPIOC_Pos                    (2)
#define  RCC_AHBRSTR_GPIOC_Msk                    (0x01U << RCC_AHBRSTR_GPIOC_Pos)  /*!<*/
#define  RCC_AHBRSTR_GPIOD_Pos                    (3)
#define  RCC_AHBRSTR_GPIOD_Msk                    (0x01U << RCC_AHBRSTR_GPIOD_Pos)  /*!<*/
#define  RCC_AHBRSTR_GPIOE_Pos                    (4)
#define  RCC_AHBRSTR_GPIOE_Msk                    (0x01U << RCC_AHBRSTR_GPIOE_Pos)  /*!<*/
#define  RCC_AHBRSTR_GPIOF_Pos                    (5)
#define  RCC_AHBRSTR_GPIOF_Msk                    (0x01U << RCC_AHBRSTR_GPIOF_Pos)  /*!<*/
#define  RCC_AHBRSTR_GPIOG_Pos                    (6)
#define  RCC_AHBRSTR_GPIOG_Msk                    (0x01U << RCC_AHBRSTR_GPIOG_Pos)  /*!<*/
#define  RCC_AHBRSTR_GPIOH_Pos                    (7)
#define  RCC_AHBRSTR_GPIOH_Msk                    (0x01U << RCC_AHBRSTR_GPIOH_Pos)  /*!<*/
#define  RCC_AHBRSTR_GPIOI_Pos                    (8)
#define  RCC_AHBRSTR_GPIOI_Msk                    (0x01U << RCC_AHBRSTR_GPIOI_Pos)  /*!<*/
#define  RCC_AHBRSTR_CRC_Pos                      (12)
#define  RCC_AHBRSTR_CRC_Msk                      (0x01U << RCC_AHBRSTR_CRC_Pos)    /*!<*/
#define  RCC_AHBRSTR_CORDIC_Pos                   (15)
#define  RCC_AHBRSTR_CORDIC_Msk                   (0x01U << RCC_AHBRSTR_CORDIC_Pos) /*!<*/
#define  RCC_AHBRSTR_ENET_Pos                     (19)
#define  RCC_AHBRSTR_ENET_Msk                     (0x01U << RCC_AHBRSTR_ENET_Pos)   /*!<*/
#define  RCC_AHBRSTR_DMA1_Pos                     (21)
#define  RCC_AHBRSTR_DMA1_Msk                     (0x01U << RCC_AHBRSTR_DMA1_Pos)   /*!<*/
#define  RCC_AHBRSTR_DMA2_Pos                     (22)
#define  RCC_AHBRSTR_DMA2_Msk                     (0x01U << RCC_AHBRSTR_DMA2_Pos)   /*!<*/
#define  RCC_AHBRSTR_USB_FS_Pos                   (24)
#define  RCC_AHBRSTR_USB_FS_Msk                   (0x01U << RCC_AHBRSTR_USB_FS_Pos) /*!<*/
#define  RCC_AHBRSTR_FSMC_Pos                     (28)
#define  RCC_AHBRSTR_FSMC_Msk                     (0x01U << RCC_AHBRSTR_FSMC_Pos)   /*!<*/
#define  RCC_AHBRSTR_QSPI_Pos                     (30)
#define  RCC_AHBRSTR_QSPI_Msk                     (0x01U << RCC_AHBRSTR_QSPI_Pos)   /*!<*/

/**
  * @brief RCC_APB2RSTR Register Bit Definition
  */
#define  RCC_APB2RSTR_TIM1_Pos                    (0)
#define  RCC_APB2RSTR_TIM1_Msk                    (0x01U << RCC_APB2RSTR_TIM1_Pos)     /*!<*/
#define  RCC_APB2RSTR_TIM8_Pos                    (1)
#define  RCC_APB2RSTR_TIM8_Msk                    (0x01U << RCC_APB2RSTR_TIM8_Pos)     /*!<*/
#define  RCC_APB2RSTR_UART1_Pos                   (4)
#define  RCC_APB2RSTR_UART1_Msk                   (0x01U << RCC_APB2RSTR_UART1_Pos)    /*!<*/
#define  RCC_APB2RSTR_UART6_Pos                   (5)
#define  RCC_APB2RSTR_UART6_Msk                   (0x01U << RCC_APB2RSTR_UART6_Pos)    /*!<*/
#define  RCC_APB2RSTR_ADC1_Pos                    (8)
#define  RCC_APB2RSTR_ADC1_Msk                    (0x01U << RCC_APB2RSTR_ADC1_Pos)     /*!<*/
#define  RCC_APB2RSTR_ADC2_Pos                    (9)
#define  RCC_APB2RSTR_ADC2_Msk                    (0x01U << RCC_APB2RSTR_ADC2_Pos)     /*!<*/
#define  RCC_APB2RSTR_SPI1_Pos                    (12)
#define  RCC_APB2RSTR_SPI1_Msk                    (0x01U << RCC_APB2RSTR_SPI1_Pos)     /*!<*/
#define  RCC_APB2RSTR_SYSCFG_Pos                  (14)
#define  RCC_APB2RSTR_SYSCFG_Msk                  (0x01U << RCC_APB2RSTR_SYSCFG_Pos)   /*!<*/
#define  RCC_APB2RSTR_COMP_Pos                    (15)
#define  RCC_APB2RSTR_COMP_Msk                    (0x01U << RCC_APB2RSTR_COMP_Pos)     /*!<*/
#define  RCC_APB2RSTR_FLEXCAN2_Pos                (24)
#define  RCC_APB2RSTR_FLEXCAN2_Msk                (0x01U << RCC_APB2RSTR_FLEXCAN2_Pos) /*!<*/
#define  RCC_APB2RSTR_MDS_Pos                     (28)
#define  RCC_APB2RSTR_MDS_Msk                     (0x01U << RCC_APB2RSTR_MDS_Pos)      /*!<*/
#define  RCC_APB2RSTR_LPTIM_Pos                   (30)
#define  RCC_APB2RSTR_LPTIM_Msk                   (0x01U << RCC_APB2RSTR_LPTIM_Pos)    /*!<*/
#define  RCC_APB2RSTR_LPUART_Pos                  (31)
#define  RCC_APB2RSTR_LPUART_Msk                  (0x01U << RCC_APB2RSTR_LPUART_Pos)   /*!<*/

/**
  * @brief RCC_APB1RSTR Register Bit Definition
  */
#define  RCC_APB1RSTR_TIM2_Pos                    (0)
#define  RCC_APB1RSTR_TIM2_Msk                    (0x01U << RCC_APB1RSTR_TIM2_Pos)     /*!<*/
#define  RCC_APB1RSTR_TIM3_Pos                    (1)
#define  RCC_APB1RSTR_TIM3_Msk                    (0x01U << RCC_APB1RSTR_TIM3_Pos)     /*!<*/
#define  RCC_APB1RSTR_TIM4_Pos                    (2)
#define  RCC_APB1RSTR_TIM4_Msk                    (0x01U << RCC_APB1RSTR_TIM4_Pos)     /*!<*/
#define  RCC_APB1RSTR_TIM5_Pos                    (3)
#define  RCC_APB1RSTR_TIM5_Msk                    (0x01U << RCC_APB1RSTR_TIM5_Pos)     /*!<*/
#define  RCC_APB1RSTR_TIM6_Pos                    (4)
#define  RCC_APB1RSTR_TIM6_Msk                    (0x01U << RCC_APB1RSTR_TIM6_Pos)     /*!<*/
#define  RCC_APB1RSTR_TIM7_Pos                    (5)
#define  RCC_APB1RSTR_TIM7_Msk                    (0x01U << RCC_APB1RSTR_TIM7_Pos)     /*!<*/
#define  RCC_APB1RSTR_WWDG_Pos                    (11)
#define  RCC_APB1RSTR_WWDG_Msk                    (0x01U << RCC_APB1RSTR_WWDG_Pos)     /*!<*/
#define  RCC_APB1RSTR_SPI2_Pos                    (14)
#define  RCC_APB1RSTR_SPI2_Msk                    (0x01U << RCC_APB1RSTR_SPI2_Pos)     /*!<*/
#define  RCC_APB1RSTR_SPI3_Pos                    (15)
#define  RCC_APB1RSTR_SPI3_Msk                    (0x01U << RCC_APB1RSTR_SPI3_Pos)     /*!<*/
#define  RCC_APB1RSTR_UART2_Pos                   (17)
#define  RCC_APB1RSTR_UART2_Msk                   (0x01U << RCC_APB1RSTR_UART2_Pos)    /*!<*/
#define  RCC_APB1RSTR_UART3_Pos                   (18)
#define  RCC_APB1RSTR_UART3_Msk                   (0x01U << RCC_APB1RSTR_UART3_Pos)    /*!<*/
#define  RCC_APB1RSTR_UART4_Pos                   (19)
#define  RCC_APB1RSTR_UART4_Msk                   (0x01U << RCC_APB1RSTR_UART4_Pos)    /*!<*/
#define  RCC_APB1RSTR_UART5_Pos                   (20)
#define  RCC_APB1RSTR_UART5_Msk                   (0x01U << RCC_APB1RSTR_UART5_Pos)    /*!<*/
#define  RCC_APB1RSTR_I2C1_Pos                    (21)
#define  RCC_APB1RSTR_I2C1_Msk                    (0x01U << RCC_APB1RSTR_I2C1_Pos)     /*!<*/
#define  RCC_APB1RSTR_I2C2_Pos                    (22)
#define  RCC_APB1RSTR_I2C2_Msk                    (0x01U << RCC_APB1RSTR_I2C2_Pos)     /*!<*/
#define  RCC_APB1RSTR_CRS_Pos                     (24)
#define  RCC_APB1RSTR_CRS_Msk                     (0x01U << RCC_APB1RSTR_CRS_Pos)      /*!<*/
#define  RCC_APB1RSTR_FLEXCAN1_Pos                (25)
#define  RCC_APB1RSTR_FLEXCAN1_Msk                (0x01U << RCC_APB1RSTR_FLEXCAN1_Pos) /*!<*/
#define  RCC_APB1RSTR_DBG_Pos                     (26)
#define  RCC_APB1RSTR_DBG_Msk                     (0x01U << RCC_APB1RSTR_DBG_Pos)      /*!<*/
#define  RCC_APB1RSTR_BKP_Pos                     (27)
#define  RCC_APB1RSTR_BKP_Msk                     (0x01U << RCC_APB1RSTR_BKP_Pos)      /*!<*/
#define  RCC_APB1RSTR_PWR_Pos                     (28)
#define  RCC_APB1RSTR_PWR_Msk                     (0x01U << RCC_APB1RSTR_PWR_Pos)      /*!<*/
#define  RCC_APB1RSTR_DAC_Pos                     (29)
#define  RCC_APB1RSTR_DAC_Msk                     (0x01U << RCC_APB1RSTR_DAC_Pos)      /*!<*/
#define  RCC_APB1RSTR_UART7_Pos                   (30)
#define  RCC_APB1RSTR_UART7_Msk                   (0x01U << RCC_APB1RSTR_UART7_Pos)    /*!<*/

/**
  * @brief RCC_AHBENR Register Bit Definition
  */
#define  RCC_AHBENR_GPIOA_Pos                     (0)
#define  RCC_AHBENR_GPIOA_Msk                     (0x01U << RCC_AHBENR_GPIOA_Pos)  /*!<*/
#define  RCC_AHBENR_GPIOB_Pos                     (1)
#define  RCC_AHBENR_GPIOB_Msk                     (0x01U << RCC_AHBENR_GPIOB_Pos)  /*!<*/
#define  RCC_AHBENR_GPIOC_Pos                     (2)
#define  RCC_AHBENR_GPIOC_Msk                     (0x01U << RCC_AHBENR_GPIOC_Pos)  /*!<*/
#define  RCC_AHBENR_GPIOD_Pos                     (3)
#define  RCC_AHBENR_GPIOD_Msk                     (0x01U << RCC_AHBENR_GPIOD_Pos)  /*!<*/
#define  RCC_AHBENR_GPIOE_Pos                     (4)
#define  RCC_AHBENR_GPIOE_Msk                     (0x01U << RCC_AHBENR_GPIOE_Pos)  /*!<*/
#define  RCC_AHBENR_GPIOF_Pos                     (5)
#define  RCC_AHBENR_GPIOF_Msk                     (0x01U << RCC_AHBENR_GPIOF_Pos)  /*!<*/
#define  RCC_AHBENR_GPIOG_Pos                     (6)
#define  RCC_AHBENR_GPIOG_Msk                     (0x01U << RCC_AHBENR_GPIOG_Pos)  /*!<*/
#define  RCC_AHBENR_GPIOH_Pos                     (7)
#define  RCC_AHBENR_GPIOH_Msk                     (0x01U << RCC_AHBENR_GPIOH_Pos)  /*!<*/
#define  RCC_AHBENR_GPIOI_Pos                     (8)
#define  RCC_AHBENR_GPIOI_Msk                     (0x01U << RCC_AHBENR_GPIOI_Pos)  /*!<*/
#define  RCC_AHBENR_CRC_Pos                       (12)
#define  RCC_AHBENR_CRC_Msk                       (0x01U << RCC_AHBENR_CRC_Pos)    /*!<*/
#define  RCC_AHBENR_FLASH_Pos                     (13)
#define  RCC_AHBENR_FLASH_Msk                     (0x01U << RCC_AHBENR_FLASH_Pos)  /*!<*/
#define  RCC_AHBENR_SRAM_Pos                      (14)
#define  RCC_AHBENR_SRAM_Msk                      (0x01U << RCC_AHBENR_SRAM_Pos)   /*!<*/
#define  RCC_AHBENR_CORDIC_Pos                    (15)
#define  RCC_AHBENR_CORDIC_Msk                    (0x01U << RCC_AHBENR_CORDIC_Pos) /*!<*/
#define  RCC_AHBENR_ITCM_Pos                      (16)
#define  RCC_AHBENR_ITCM_Msk                      (0x01U << RCC_AHBENR_ITCM_Pos)   /*!<*/
#define  RCC_AHBENR_DTCM_Pos                      (17)
#define  RCC_AHBENR_DTCM_Msk                      (0x01U << RCC_AHBENR_DTCM_Pos)   /*!<*/
#define  RCC_AHBENR_ENET_Pos                      (19)
#define  RCC_AHBENR_ENET_Msk                      (0x01U << RCC_AHBENR_ENET_Pos)   /*!<*/
#define  RCC_AHBENR_DMA1_Pos                      (21)
#define  RCC_AHBENR_DMA1_Msk                      (0x01U << RCC_AHBENR_DMA1_Pos)   /*!<*/
#define  RCC_AHBENR_DMA2_Pos                      (22)
#define  RCC_AHBENR_DMA2_Msk                      (0x01U << RCC_AHBENR_DMA2_Pos)   /*!<*/
#define  RCC_AHBENR_USB_FS_Pos                    (24)
#define  RCC_AHBENR_USB_FS_Msk                    (0x01U << RCC_AHBENR_USB_FS_Pos) /*!<*/
#define  RCC_AHBENR_FSMC_Pos                      (28)
#define  RCC_AHBENR_FSMC_Msk                      (0x01U << RCC_AHBENR_FSMC_Pos)   /*!<*/
#define  RCC_AHBENR_QSPI_Pos                      (30)
#define  RCC_AHBENR_QSPI_Msk                      (0x01U << RCC_AHBENR_QSPI_Pos)   /*!<*/

/**
  * @brief RCC_APB2ENR Register Bit Definition
  */
#define  RCC_APB2ENR_TIM1_Pos                     (0)
#define  RCC_APB2ENR_TIM1_Msk                     (0x01U << RCC_APB2ENR_TIM1_Pos)     /*!<*/
#define  RCC_APB2ENR_TIM8_Pos                     (1)
#define  RCC_APB2ENR_TIM8_Msk                     (0x01U << RCC_APB2ENR_TIM8_Pos)     /*!<*/
#define  RCC_APB2ENR_UART1_Pos                    (4)
#define  RCC_APB2ENR_UART1_Msk                    (0x01U << RCC_APB2ENR_UART1_Pos)    /*!<*/
#define  RCC_APB2ENR_UART6_Pos                    (5)
#define  RCC_APB2ENR_UART6_Msk                    (0x01U << RCC_APB2ENR_UART6_Pos)    /*!<*/
#define  RCC_APB2ENR_ADC1_Pos                     (8)
#define  RCC_APB2ENR_ADC1_Msk                     (0x01U << RCC_APB2ENR_ADC1_Pos)     /*!<*/
#define  RCC_APB2ENR_ADC2_Pos                     (9)
#define  RCC_APB2ENR_ADC2_Msk                     (0x01U << RCC_APB2ENR_ADC2_Pos)     /*!<*/
#define  RCC_APB2ENR_SPI1_Pos                     (12)
#define  RCC_APB2ENR_SPI1_Msk                     (0x01U << RCC_APB2ENR_SPI1_Pos)     /*!<*/
#define  RCC_APB2ENR_SYSCFG_Pos                   (14)
#define  RCC_APB2ENR_SYSCFG_Msk                   (0x01U << RCC_APB2ENR_SYSCFG_Pos)   /*!<*/
#define  RCC_APB2ENR_COMP_Pos                     (15)
#define  RCC_APB2ENR_COMP_Msk                     (0x01U << RCC_APB2ENR_COMP_Pos)     /*!<*/
#define  RCC_APB2ENR_FLEXCAN2_Pos                 (24)
#define  RCC_APB2ENR_FLEXCAN2_Msk                 (0x01U << RCC_APB2ENR_FLEXCAN2_Pos) /*!<*/
#define  RCC_APB2ENR_MDS_Pos                      (28)
#define  RCC_APB2ENR_MDS_Msk                      (0x01U << RCC_APB2ENR_MDS_Pos)      /*!<*/
#define  RCC_APB2ENR_LPTIM_Pos                    (30)
#define  RCC_APB2ENR_LPTIM_Msk                    (0x01U << RCC_APB2ENR_LPTIM_Pos)    /*!<*/
#define  RCC_APB2ENR_LPUART_Pos                   (31)
#define  RCC_APB2ENR_LPUART_Msk                   (0x01U << RCC_APB2ENR_LPUART_Pos)   /*!<*/

/**
  * @brief RCC_APB1ENR Register Bit Definition
  */
#define  RCC_APB1ENR_TIM2_Pos                     (0)
#define  RCC_APB1ENR_TIM2_Msk                     (0x01U << RCC_APB1ENR_TIM2_Pos)     /*!<*/
#define  RCC_APB1ENR_TIM3_Pos                     (1)
#define  RCC_APB1ENR_TIM3_Msk                     (0x01U << RCC_APB1ENR_TIM3_Pos)     /*!<*/
#define  RCC_APB1ENR_TIM4_Pos                     (2)
#define  RCC_APB1ENR_TIM4_Msk                     (0x01U << RCC_APB1ENR_TIM4_Pos)     /*!<*/
#define  RCC_APB1ENR_TIM5_Pos                     (3)
#define  RCC_APB1ENR_TIM5_Msk                     (0x01U << RCC_APB1ENR_TIM5_Pos)     /*!<*/
#define  RCC_APB1ENR_TIM6_Pos                     (4)
#define  RCC_APB1ENR_TIM6_Msk                     (0x01U << RCC_APB1ENR_TIM6_Pos)     /*!<*/
#define  RCC_APB1ENR_TIM7_Pos                     (5)
#define  RCC_APB1ENR_TIM7_Msk                     (0x01U << RCC_APB1ENR_TIM7_Pos)     /*!<*/
#define  RCC_APB1ENR_WWDG_Pos                     (11)
#define  RCC_APB1ENR_WWDG_Msk                     (0x01U << RCC_APB1ENR_WWDG_Pos)     /*!<*/
#define  RCC_APB1ENR_SPI2_Pos                     (14)
#define  RCC_APB1ENR_SPI2_Msk                     (0x01U << RCC_APB1ENR_SPI2_Pos)     /*!<*/
#define  RCC_APB1ENR_SPI3_Pos                     (15)
#define  RCC_APB1ENR_SPI3_Msk                     (0x01U << RCC_APB1ENR_SPI3_Pos)     /*!<*/
#define  RCC_APB1ENR_UART2_Pos                    (17)
#define  RCC_APB1ENR_UART2_Msk                    (0x01U << RCC_APB1ENR_UART2_Pos)    /*!<*/
#define  RCC_APB1ENR_UART3_Pos                    (18)
#define  RCC_APB1ENR_UART3_Msk                    (0x01U << RCC_APB1ENR_UART3_Pos)    /*!<*/
#define  RCC_APB1ENR_UART4_Pos                    (19)
#define  RCC_APB1ENR_UART4_Msk                    (0x01U << RCC_APB1ENR_UART4_Pos)    /*!<*/
#define  RCC_APB1ENR_UART5_Pos                    (20)
#define  RCC_APB1ENR_UART5_Msk                    (0x01U << RCC_APB1ENR_UART5_Pos)    /*!<*/
#define  RCC_APB1ENR_I2C1_Pos                     (21)
#define  RCC_APB1ENR_I2C1_Msk                     (0x01U << RCC_APB1ENR_I2C1_Pos)     /*!<*/
#define  RCC_APB1ENR_I2C2_Pos                     (22)
#define  RCC_APB1ENR_I2C2_Msk                     (0x01U << RCC_APB1ENR_I2C2_Pos)     /*!<*/
#define  RCC_APB1ENR_CRS_Pos                      (24)
#define  RCC_APB1ENR_CRS_Msk                      (0x01U << RCC_APB1ENR_CRS_Pos)      /*!<*/
#define  RCC_APB1ENR_FLEXCAN1_Pos                 (25)
#define  RCC_APB1ENR_FLEXCAN1_Msk                 (0x01U << RCC_APB1ENR_FLEXCAN1_Pos) /*!<*/
#define  RCC_APB1ENR_BKP_Pos                      (27)
#define  RCC_APB1ENR_BKP_Msk                      (0x01U << RCC_APB1ENR_BKP_Pos)      /*!<*/
#define  RCC_APB1ENR_PWRDBG_Pos                   (28)
#define  RCC_APB1ENR_PWRDBG_Msk                   (0x01U << RCC_APB1ENR_PWRDBG_Pos)   /*!<*/
#define  RCC_APB1ENR_DAC_Pos                      (29)
#define  RCC_APB1ENR_DAC_Msk                      (0x01U << RCC_APB1ENR_DAC_Pos)      /*!<*/
#define  RCC_APB1ENR_UART7_Pos                    (30)
#define  RCC_APB1ENR_UART7_Msk                    (0x01U << RCC_APB1ENR_UART7_Pos)    /*!<*/

/**
  * @brief RCC_BDCR Register Bit Definition
  */
#define  RCC_BDCR_LSEON_Pos                       (0)
#define  RCC_BDCR_LSEON_Msk                       (0x01U << RCC_BDCR_LSEON_Pos)  /*!<*/
#define  RCC_BDCR_LSERDY_Pos                      (1)
#define  RCC_BDCR_LSERDY_Msk                      (0x01U << RCC_BDCR_LSERDY_Pos) /*!<*/
#define  RCC_BDCR_LSEBYP_Pos                      (2)
#define  RCC_BDCR_LSEBYP_Msk                      (0x01U << RCC_BDCR_LSEBYP_Pos) /*!<*/
#define  RCC_BDCR_RTCSEL_Pos                      (8)
#define  RCC_BDCR_RTCSEL_Msk                      (0x03U << RCC_BDCR_RTCSEL_Pos) /*!<*/
#define  RCC_BDCR_RTCEN_Pos                       (15)
#define  RCC_BDCR_RTCEN_Msk                       (0x01U << RCC_BDCR_RTCEN_Pos)  /*!<*/
#define  RCC_BDCR_BDRST_Pos                       (16)
#define  RCC_BDCR_BDRST_Msk                       (0x01U << RCC_BDCR_BDRST_Pos)  /*!<*/
#define  RCC_BDCR_DBP_Pos                         (24)
#define  RCC_BDCR_DBP_Msk                         (0x01U << RCC_BDCR_DBP_Pos)    /*!<*/

/**
  * @brief RCC_CSR Register Bit Definition
  */
#define  RCC_CSR_LSION_Pos                        (0)
#define  RCC_CSR_LSION_Msk                        (0x01U << RCC_CSR_LSION_Pos)    /*!<*/
#define  RCC_CSR_LSIRDY_Pos                       (1)
#define  RCC_CSR_LSIRDY_Msk                       (0x01U << RCC_CSR_LSIRDY_Pos)   /*!<*/
#define  RCC_CSR_LSIOE_Pos                        (5)
#define  RCC_CSR_LSIOE_Msk                        (0x01U << RCC_CSR_LSIOE_Pos)    /*!<*/
#define  RCC_CSR_PVDRSTEN_Pos                     (6)
#define  RCC_CSR_PVDRSTEN_Msk                     (0x01U << RCC_CSR_PVDRSTEN_Pos) /*!<*/
#define  RCC_CSR_LOCKUPEN_Pos                     (7)
#define  RCC_CSR_LOCKUPEN_Msk                     (0x01U << RCC_CSR_LOCKUPEN_Pos) /*!<*/
#define  RCC_CSR_PVDRSTF_Pos                      (22)
#define  RCC_CSR_PVDRSTF_Msk                      (0x01U << RCC_CSR_PVDRSTF_Pos)  /*!<*/
#define  RCC_CSR_LOCKUPF_Pos                      (23)
#define  RCC_CSR_LOCKUPF_Msk                      (0x01U << RCC_CSR_LOCKUPF_Pos)  /*!<*/
#define  RCC_CSR_RMVF_Pos                         (24)
#define  RCC_CSR_RMVF_Msk                         (0x01U << RCC_CSR_RMVF_Pos)     /*!<*/
#define  RCC_CSR_PINRSTF_Pos                      (26)
#define  RCC_CSR_PINRSTF_Msk                      (0x01U << RCC_CSR_PINRSTF_Pos)  /*!<*/
#define  RCC_CSR_PORRSTF_Pos                      (27)
#define  RCC_CSR_PORRSTF_Msk                      (0x01U << RCC_CSR_PORRSTF_Pos)  /*!<*/
#define  RCC_CSR_SFTRSTF_Pos                      (28)
#define  RCC_CSR_SFTRSTF_Msk                      (0x01U << RCC_CSR_SFTRSTF_Pos)  /*!<*/
#define  RCC_CSR_IWDGRSTF_Pos                     (29)
#define  RCC_CSR_IWDGRSTF_Msk                     (0x01U << RCC_CSR_IWDGRSTF_Pos) /*!<*/
#define  RCC_CSR_WWDGRSTF_Pos                     (30)
#define  RCC_CSR_WWDGRSTF_Msk                     (0x01U << RCC_CSR_WWDGRSTF_Pos) /*!<*/
#define  RCC_CSR_LPWRRSTF_Pos                     (31)
#define  RCC_CSR_LPWRRSTF_Msk                     (0x01U << RCC_CSR_LPWRRSTF_Pos) /*!<*/

/**
  * @brief RCC_SYSCFG Register Bit Definition
  */
#define  RCC_SYSCFG_PROG_CHECK_EN_Pos             (0)
#define  RCC_SYSCFG_PROG_CHECK_EN_Msk             (0x01U << RCC_SYSCFG_PROG_CHECK_EN_Pos) /*!<*/
#define  RCC_SYSCFG_HSE_RFB_SEL_Pos               (8)
#define  RCC_SYSCFG_HSE_RFB_SEL_Msk               (0x03U << RCC_SYSCFG_HSE_RFB_SEL_Pos)   /*!<*/
#define  RCC_SYSCFG_HSELPFEN_Pos                  (14)
#define  RCC_SYSCFG_HSELPFEN_Msk                  (0x01U << RCC_SYSCFG_HSELPFEN_Pos)      /*!<*/

/**
  * @brief RCC_CFGR2 Register Bit Definition
  */
#define  RCC_CFGR2_TIMADV_CKSEL_Pos               (0)
#define  RCC_CFGR2_TIMADV_CKSEL_Msk               (0x01U << RCC_CFGR2_TIMADV_CKSEL_Pos)    /*!<*/
#define  RCC_CFGR2_TIMADV_PRE_Pos                 (1)
#define  RCC_CFGR2_TIMADV_PRE_Msk                 (0x07U << RCC_CFGR2_TIMADV_PRE_Pos)      /*!<*/
#define  RCC_CFGR2_APB1_CLK_HV_PRE_Pos            (16)
#define  RCC_CFGR2_APB1_CLK_HV_PRE_Msk            (0x0FU << RCC_CFGR2_APB1_CLK_HV_PRE_Pos) /*!<*/
#define  RCC_CFGR2_MCO_PRE_Pos                    (20)
#define  RCC_CFGR2_MCO_PRE_Msk                    (0x0FU << RCC_CFGR2_MCO_PRE_Pos)         /*!<*/
#define  RCC_CFGR2_LPUARTCLKSEL_Pos               (26)
#define  RCC_CFGR2_LPUARTCLKSEL_Msk               (0x03U << RCC_CFGR2_LPUARTCLKSEL_Pos)    /*!<*/
#define  RCC_CFGR2_LPTIMCLKSEL_Pos                (29)
#define  RCC_CFGR2_LPTIMCLKSEL_Msk                (0x03U << RCC_CFGR2_LPTIMCLKSEL_Pos)     /*!<*/

/**
  * @brief RCC_ICSCR Register Bit Definition
  */
#define  RCC_ICSCR_TRIM_CRS_SEL_Pos               (0)
#define  RCC_ICSCR_TRIM_CRS_SEL_Msk               (0x01U << RCC_ICSCR_TRIM_CRS_SEL_Pos) /*!<*/

/**
  * @brief RCC_PLL1CFGR Register Bit Definition
  */
#define  RCC_PLL1CFGR_PLL1SRC_Pos                 (0)
#define  RCC_PLL1CFGR_PLL1SRC_Msk                 (0x01U << RCC_PLL1CFGR_PLL1SRC_Pos)    /*!<*/
#define  RCC_PLL1CFGR_PLL1XTPRE_Pos               (1)
#define  RCC_PLL1CFGR_PLL1XTPRE_Msk               (0x01U << RCC_PLL1CFGR_PLL1XTPRE_Pos)  /*!<*/
#define  RCC_PLL1CFGR_PLL1_ICTRL_Pos              (2)
#define  RCC_PLL1CFGR_PLL1_ICTRL_Msk              (0x03U << RCC_PLL1CFGR_PLL1_ICTRL_Pos) /*!<*/
#define  RCC_PLL1CFGR_PLL1_LDS_Pos                (4)
#define  RCC_PLL1CFGR_PLL1_LDS_Msk                (0x07U << RCC_PLL1CFGR_PLL1_LDS_Pos)   /*!<*/
#define  RCC_PLL1CFGR_PLL1DIV_Pos                 (8)
#define  RCC_PLL1CFGR_PLL1DIV_Msk                 (0x07U << RCC_PLL1CFGR_PLL1DIV_Pos)    /*!<*/
#define  RCC_PLL1CFGR_PLL1MUL_Pos                 (16)
#define  RCC_PLL1CFGR_PLL1MUL_Msk                 (0x7FU << RCC_PLL1CFGR_PLL1MUL_Pos)    /*!<*/

/**
  * @brief RCC_PLL2CFGR Register Bit Definition
  */
#define  RCC_PLL2CFGR_PLL2SRC_Pos                 (0)
#define  RCC_PLL2CFGR_PLL2SRC_Msk                 (0x01U << RCC_PLL2CFGR_PLL2SRC_Pos)    /*!<*/
#define  RCC_PLL2CFGR_PLL2XTPRE_Pos               (1)
#define  RCC_PLL2CFGR_PLL2XTPRE_Msk               (0x01U << RCC_PLL2CFGR_PLL2XTPRE_Pos)  /*!<*/
#define  RCC_PLL2CFGR_PLL2_ICTRL_Pos              (2)
#define  RCC_PLL2CFGR_PLL2_ICTRL_Msk              (0x03U << RCC_PLL2CFGR_PLL2_ICTRL_Pos) /*!<*/
#define  RCC_PLL2CFGR_PLL2_LDS_Pos                (4)
#define  RCC_PLL2CFGR_PLL2_LDS_Msk                (0x07U << RCC_PLL2CFGR_PLL2_LDS_Pos)   /*!<*/
#define  RCC_PLL2CFGR_PLL2DIV_Pos                 (8)
#define  RCC_PLL2CFGR_PLL2DIV_Msk                 (0x07U << RCC_PLL2CFGR_PLL2DIV_Pos)    /*!<*/
#define  RCC_PLL2CFGR_PLL2MUL_Pos                 (16)
#define  RCC_PLL2CFGR_PLL2MUL_Msk                 (0xFFU << RCC_PLL2CFGR_PLL2MUL_Pos)    /*!<*/
#define  RCC_PLL2CFGR_PLL2PDIV_Pos                (24)
#define  RCC_PLL2CFGR_PLL2PDIV_Msk                (0x07U << RCC_PLL2CFGR_PLL2PDIV_Pos)   /*!<*/

/**
  * @brief RCC_ADC1CFGR Register Bit Definition
  */
#define  RCC_ADC1CFGR_PRE_Pos                     (0)
#define  RCC_ADC1CFGR_PRE_Msk                     (0x0FU << RCC_ADC1CFGR_PRE_Pos)      /*!<*/
#define  RCC_ADC1CFGR_PRECAL_Pos                  (8)
#define  RCC_ADC1CFGR_PRECAL_Msk                  (0x01FFU << RCC_ADC1CFGR_PRECAL_Pos) /*!<*/

/**
  * @brief RCC_ADC2CFGR Register Bit Definition
  */
#define  RCC_ADC2CFGR_PRE_Pos                     (0)
#define  RCC_ADC2CFGR_PRE_Msk                     (0x0FU << RCC_ADC2CFGR_PRE_Pos)      /*!<*/
#define  RCC_ADC2CFGR_PRECAL_Pos                  (8)
#define  RCC_ADC2CFGR_PRECAL_Msk                  (0x01FFU << RCC_ADC2CFGR_PRECAL_Pos) /*!<*/

/**
  * @brief RCC_DACCFGR Register Bit Definition
  */
#define  RCC_DACCFGR_PRE_Pos                      (0)
#define  RCC_DACCFGR_PRE_Msk                      (0x7FU << RCC_DACCFGR_PRE_Pos) /*!<*/

/**
  * @brief RCC_TPIUCFGR Register Bit Definition
  */
#define  RCC_TPIUCFGR_PRE_Pos                     (0)
#define  RCC_TPIUCFGR_PRE_Msk                     (0x03U << RCC_TPIUCFGR_PRE_Pos) /*!<*/

#endif

