/***********************************************************************************************************************
    @file     reg_gpio.h
    @author   VV TEAM
    @brief    This flie contains all the GPIO's register and its field definition.
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

#ifndef __REG_GPIO_H
#define __REG_GPIO_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief GPIO Base Address Definition
  */
#define  GPIOA_BASE                                0x40040000 /*!<Base Address: 0x40040000*/
#define  GPIOB_BASE                                0x40040400 /*!<Base Address: 0x40040400*/
#define  GPIOC_BASE                                0x40040800 /*!<Base Address: 0x40040800*/
#define  GPIOD_BASE                                0x40040C00 /*!<Base Address: 0x40040C00*/
#define  GPIOE_BASE                                0x40041000 /*!<Base Address: 0x40041000*/
#define  GPIOF_BASE                                0x40041400 /*!<Base Address: 0x40041400*/
#define  GPIOG_BASE                                0x40041800 /*!<Base Address: 0x40041800*/
#define  GPIOH_BASE                                0x40041C00 /*!<Base Address: 0x40041C00*/
#define  GPIOI_BASE                                0x40042000 /*!<Base Address: 0x40042000*/

/**
  * @brief GPIO Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CRL;                 /*!<GPIO Port configuration register low           offset: 0x00*/
    __IO uint32_t CRH;                 /*!<GPIO Port configuration register high          offset: 0x04*/
    __IO uint32_t IDR;                 /*!<GPIO Port input data register                  offset: 0x08*/
    __IO uint32_t ODR;                 /*!<GPIO Port output data register                 offset: 0x0C*/
    __IO uint32_t BSRR;                /*!<GPIO Port bit set/reset register               offset: 0x10*/
    __IO uint32_t BRR;                 /*!<GPIO Port bit reset register                   offset: 0x14*/
    __IO uint32_t LCKR;                /*!<GPIO Port configuration lock register          offset: 0x18*/
    __IO uint32_t DCR;                 /*!<GPIO Port output open drain control register   offset: 0x1C*/
    __IO uint32_t AFRL;                /*!<GPIO Port alternate function register low      offset: 0x20*/
    __IO uint32_t AFRH;                /*!<GPIO Port alternate function register high     offset: 0x24*/
} GPIO_TypeDef;

/**
  * @brief GPIO type pointer Definition
  */
#define GPIOA                                     ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                                     ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                                     ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD                                     ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE                                     ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF                                     ((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG                                     ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH                                     ((GPIO_TypeDef *)GPIOH_BASE)
#define GPIOI                                     ((GPIO_TypeDef *)GPIOI_BASE)

/**
  * @brief GPIO_CRL Register Bit Definition
  */
#define  GPIO_CRL_MODE0_Pos                       (0)
#define  GPIO_CRL_MODE0_Msk                       (0x03U << GPIO_CRL_MODE0_Pos) /*!<*/
#define  GPIO_CRL_CNF0_Pos                        (2)
#define  GPIO_CRL_CNF0_Msk                        (0x03U << GPIO_CRL_CNF0_Pos)  /*!<*/
#define  GPIO_CRL_MODE1_Pos                       (4)
#define  GPIO_CRL_MODE1_Msk                       (0x03U << GPIO_CRL_MODE1_Pos) /*!<*/
#define  GPIO_CRL_CNF1_Pos                        (6)
#define  GPIO_CRL_CNF1_Msk                        (0x03U << GPIO_CRL_CNF1_Pos)  /*!<*/
#define  GPIO_CRL_MODE2_Pos                       (8)
#define  GPIO_CRL_MODE2_Msk                       (0x03U << GPIO_CRL_MODE2_Pos) /*!<*/
#define  GPIO_CRL_CNF2_Pos                        (10)
#define  GPIO_CRL_CNF2_Msk                        (0x03U << GPIO_CRL_CNF2_Pos)  /*!<*/
#define  GPIO_CRL_MODE3_Pos                       (12)
#define  GPIO_CRL_MODE3_Msk                       (0x03U << GPIO_CRL_MODE3_Pos) /*!<*/
#define  GPIO_CRL_CNF3_Pos                        (14)
#define  GPIO_CRL_CNF3_Msk                        (0x03U << GPIO_CRL_CNF3_Pos)  /*!<*/
#define  GPIO_CRL_MODE4_Pos                       (16)
#define  GPIO_CRL_MODE4_Msk                       (0x03U << GPIO_CRL_MODE4_Pos) /*!<*/
#define  GPIO_CRL_CNF4_Pos                        (18)
#define  GPIO_CRL_CNF4_Msk                        (0x03U << GPIO_CRL_CNF4_Pos)  /*!<*/
#define  GPIO_CRL_MODE5_Pos                       (20)
#define  GPIO_CRL_MODE5_Msk                       (0x03U << GPIO_CRL_MODE5_Pos) /*!<*/
#define  GPIO_CRL_CNF5_Pos                        (22)
#define  GPIO_CRL_CNF5_Msk                        (0x03U << GPIO_CRL_CNF5_Pos)  /*!<*/
#define  GPIO_CRL_MODE6_Pos                       (24)
#define  GPIO_CRL_MODE6_Msk                       (0x03U << GPIO_CRL_MODE6_Pos) /*!<*/
#define  GPIO_CRL_CNF6_Pos                        (26)
#define  GPIO_CRL_CNF6_Msk                        (0x03U << GPIO_CRL_CNF6_Pos)  /*!<*/
#define  GPIO_CRL_MODE7_Pos                       (28)
#define  GPIO_CRL_MODE7_Msk                       (0x03U << GPIO_CRL_MODE7_Pos) /*!<*/
#define  GPIO_CRL_CNF7_Pos                        (30)
#define  GPIO_CRL_CNF7_Msk                        (0x03U << GPIO_CRL_CNF7_Pos)  /*!<*/

/**
  * @brief GPIO_CRH Register Bit Definition
  */
#define  GPIO_CRH_MODE8_Pos                       (0)
#define  GPIO_CRH_MODE8_Msk                       (0x03U << GPIO_CRH_MODE8_Pos)  /*!<*/
#define  GPIO_CRH_CNF8_Pos                        (2)
#define  GPIO_CRH_CNF8_Msk                        (0x03U << GPIO_CRH_CNF8_Pos)   /*!<*/
#define  GPIO_CRH_MODE9_Pos                       (4)
#define  GPIO_CRH_MODE9_Msk                       (0x03U << GPIO_CRH_MODE9_Pos)  /*!<*/
#define  GPIO_CRH_CNF9_Pos                        (6)
#define  GPIO_CRH_CNF9_Msk                        (0x03U << GPIO_CRH_CNF9_Pos)   /*!<*/
#define  GPIO_CRH_MODE10_Pos                      (8)
#define  GPIO_CRH_MODE10_Msk                      (0x03U << GPIO_CRH_MODE10_Pos) /*!<*/
#define  GPIO_CRH_CNF10_Pos                       (10)
#define  GPIO_CRH_CNF10_Msk                       (0x03U << GPIO_CRH_CNF10_Pos)  /*!<*/
#define  GPIO_CRH_MODE11_Pos                      (12)
#define  GPIO_CRH_MODE11_Msk                      (0x03U << GPIO_CRH_MODE11_Pos) /*!<*/
#define  GPIO_CRH_CNF11_Pos                       (14)
#define  GPIO_CRH_CNF11_Msk                       (0x03U << GPIO_CRH_CNF11_Pos)  /*!<*/
#define  GPIO_CRH_MODE12_Pos                      (16)
#define  GPIO_CRH_MODE12_Msk                      (0x03U << GPIO_CRH_MODE12_Pos) /*!<*/
#define  GPIO_CRH_CNF12_Pos                       (18)
#define  GPIO_CRH_CNF12_Msk                       (0x03U << GPIO_CRH_CNF12_Pos)  /*!<*/
#define  GPIO_CRH_MODE13_Pos                      (20)
#define  GPIO_CRH_MODE13_Msk                      (0x03U << GPIO_CRH_MODE13_Pos) /*!<*/
#define  GPIO_CRH_CNF13_Pos                       (22)
#define  GPIO_CRH_CNF13_Msk                       (0x03U << GPIO_CRH_CNF13_Pos)  /*!<*/
#define  GPIO_CRH_MODE14_Pos                      (24)
#define  GPIO_CRH_MODE14_Msk                      (0x03U << GPIO_CRH_MODE14_Pos) /*!<*/
#define  GPIO_CRH_CNF14_Pos                       (26)
#define  GPIO_CRH_CNF14_Msk                       (0x03U << GPIO_CRH_CNF14_Pos)  /*!<*/
#define  GPIO_CRH_MODE15_Pos                      (28)
#define  GPIO_CRH_MODE15_Msk                      (0x03U << GPIO_CRH_MODE15_Pos) /*!<*/
#define  GPIO_CRH_CNF15_Pos                       (30)
#define  GPIO_CRH_CNF15_Msk                       (0x03U << GPIO_CRH_CNF15_Pos)  /*!<*/

/**
  * @brief GPIO_IDR Register Bit Definition
  */
#define  GPIO_IDR_IDRY_Pos                        (0)
#define  GPIO_IDR_IDRY_Msk                        (0xFFFFU << GPIO_IDR_IDRY_Pos) /*!<*/

/**
  * @brief GPIO_ODR Register Bit Definition
  */
#define  GPIO_ODR_ODRY_Pos                        (0)
#define  GPIO_ODR_ODRY_Msk                        (0xFFFFU << GPIO_ODR_ODRY_Pos) /*!<*/

/**
  * @brief GPIO_BSRR Register Bit Definition
  */
#define  GPIO_BSRR_BSY_Pos                        (0)
#define  GPIO_BSRR_BSY_Msk                        (0xFFFFU << GPIO_BSRR_BSY_Pos) /*!<*/
#define  GPIO_BSRR_BRY_Pos                        (16)
#define  GPIO_BSRR_BRY_Msk                        (0xFFFFU << GPIO_BSRR_BRY_Pos) /*!<*/

/**
  * @brief GPIO_BRR Register Bit Definition
  */
#define  GPIO_BRR_BRY_Pos                         (0)
#define  GPIO_BRR_BRY_Msk                         (0xFFFFU << GPIO_BRR_BRY_Pos) /*!<*/

/**
  * @brief GPIO_LCKR Register Bit Definition
  */
#define  GPIO_LCKR_LCKY_Pos                       (0)
#define  GPIO_LCKR_LCKY_Msk                       (0xFFFFU << GPIO_LCKR_LCKY_Pos) /*!<*/
#define  GPIO_LCKR_LCKK_Pos                       (16)
#define  GPIO_LCKR_LCKK_Msk                       (0x01U << GPIO_LCKR_LCKK_Pos)   /*!<*/

/**
  * @brief GPIO_DCR Register Bit Definition
  */
#define  GPIO_DCR_PX0_Pos                         (0)
#define  GPIO_DCR_PX0_Msk                         (0x03U << GPIO_DCR_PX0_Pos)  /*!<*/
#define  GPIO_DCR_PX1_Pos                         (2)
#define  GPIO_DCR_PX1_Msk                         (0x03U << GPIO_DCR_PX1_Pos)  /*!<*/
#define  GPIO_DCR_PX2_Pos                         (4)
#define  GPIO_DCR_PX2_Msk                         (0x03U << GPIO_DCR_PX2_Pos)  /*!<*/
#define  GPIO_DCR_PX3_Pos                         (6)
#define  GPIO_DCR_PX3_Msk                         (0x03U << GPIO_DCR_PX3_Pos)  /*!<*/
#define  GPIO_DCR_PX4_Pos                         (8)
#define  GPIO_DCR_PX4_Msk                         (0x03U << GPIO_DCR_PX4_Pos)  /*!<*/
#define  GPIO_DCR_PX5_Pos                         (10)
#define  GPIO_DCR_PX5_Msk                         (0x03U << GPIO_DCR_PX5_Pos)  /*!<*/
#define  GPIO_DCR_PX6_Pos                         (12)
#define  GPIO_DCR_PX6_Msk                         (0x03U << GPIO_DCR_PX6_Pos)  /*!<*/
#define  GPIO_DCR_PX7_Pos                         (14)
#define  GPIO_DCR_PX7_Msk                         (0x03U << GPIO_DCR_PX7_Pos)  /*!<*/
#define  GPIO_DCR_PX8_Pos                         (16)
#define  GPIO_DCR_PX8_Msk                         (0x03U << GPIO_DCR_PX8_Pos)  /*!<*/
#define  GPIO_DCR_PX9_Pos                         (18)
#define  GPIO_DCR_PX9_Msk                         (0x03U << GPIO_DCR_PX9_Pos)  /*!<*/
#define  GPIO_DCR_PX10_Pos                        (20)
#define  GPIO_DCR_PX10_Msk                        (0x03U << GPIO_DCR_PX10_Pos) /*!<*/
#define  GPIO_DCR_PX11_Pos                        (22)
#define  GPIO_DCR_PX11_Msk                        (0x03U << GPIO_DCR_PX11_Pos) /*!<*/
#define  GPIO_DCR_PX12_Pos                        (24)
#define  GPIO_DCR_PX12_Msk                        (0x03U << GPIO_DCR_PX12_Pos) /*!<*/
#define  GPIO_DCR_PX13_Pos                        (26)
#define  GPIO_DCR_PX13_Msk                        (0x03U << GPIO_DCR_PX13_Pos) /*!<*/
#define  GPIO_DCR_PX14_Pos                        (28)
#define  GPIO_DCR_PX14_Msk                        (0x03U << GPIO_DCR_PX14_Pos) /*!<*/
#define  GPIO_DCR_PX15_Pos                        (30)
#define  GPIO_DCR_PX15_Msk                        (0x03U << GPIO_DCR_PX15_Pos) /*!<*/

/**
  * @brief GPIO_AFRL Register Bit Definition
  */
#define  GPIO_AFRL_AFR0_Pos                       (0)
#define  GPIO_AFRL_AFR0_Msk                       (0x0FU << GPIO_AFRL_AFR0_Pos) /*!<*/
#define  GPIO_AFRL_AFR1_Pos                       (4)
#define  GPIO_AFRL_AFR1_Msk                       (0x0FU << GPIO_AFRL_AFR1_Pos) /*!<*/
#define  GPIO_AFRL_AFR2_Pos                       (8)
#define  GPIO_AFRL_AFR2_Msk                       (0x0FU << GPIO_AFRL_AFR2_Pos) /*!<*/
#define  GPIO_AFRL_AFR3_Pos                       (12)
#define  GPIO_AFRL_AFR3_Msk                       (0x0FU << GPIO_AFRL_AFR3_Pos) /*!<*/
#define  GPIO_AFRL_AFR4_Pos                       (16)
#define  GPIO_AFRL_AFR4_Msk                       (0x0FU << GPIO_AFRL_AFR4_Pos) /*!<*/
#define  GPIO_AFRL_AFR5_Pos                       (20)
#define  GPIO_AFRL_AFR5_Msk                       (0x0FU << GPIO_AFRL_AFR5_Pos) /*!<*/
#define  GPIO_AFRL_AFR6_Pos                       (24)
#define  GPIO_AFRL_AFR6_Msk                       (0x0FU << GPIO_AFRL_AFR6_Pos) /*!<*/
#define  GPIO_AFRL_AFR7_Pos                       (28)
#define  GPIO_AFRL_AFR7_Msk                       (0x0FU << GPIO_AFRL_AFR7_Pos) /*!<*/

/**
  * @brief GPIO_AFRH Register Bit Definition
  */
#define  GPIO_AFRH_AFR8_Pos                       (0)
#define  GPIO_AFRH_AFR8_Msk                       (0x0FU << GPIO_AFRH_AFR8_Pos)  /*!<*/
#define  GPIO_AFRH_AFR9_Pos                       (4)
#define  GPIO_AFRH_AFR9_Msk                       (0x0FU << GPIO_AFRH_AFR9_Pos)  /*!<*/
#define  GPIO_AFRH_AFR10_Pos                      (8)
#define  GPIO_AFRH_AFR10_Msk                      (0x0FU << GPIO_AFRH_AFR10_Pos) /*!<*/
#define  GPIO_AFRH_AFR11_Pos                      (12)
#define  GPIO_AFRH_AFR11_Msk                      (0x0FU << GPIO_AFRH_AFR11_Pos) /*!<*/
#define  GPIO_AFRH_AFR12_Pos                      (16)
#define  GPIO_AFRH_AFR12_Msk                      (0x0FU << GPIO_AFRH_AFR12_Pos) /*!<*/
#define  GPIO_AFRH_AFR13_Pos                      (20)
#define  GPIO_AFRH_AFR13_Msk                      (0x0FU << GPIO_AFRH_AFR13_Pos) /*!<*/
#define  GPIO_AFRH_AFR14_Pos                      (24)
#define  GPIO_AFRH_AFR14_Msk                      (0x0FU << GPIO_AFRH_AFR14_Pos) /*!<*/
#define  GPIO_AFRH_AFR15_Pos                      (28)
#define  GPIO_AFRH_AFR15_Msk                      (0x0FU << GPIO_AFRH_AFR15_Pos) /*!<*/

#endif

