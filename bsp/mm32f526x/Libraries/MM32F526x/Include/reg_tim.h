/***********************************************************************************************************************
    @file     reg_tim.h
    @author   VV TEAM
    @brief    This flie contains all the TIM's register and its field definition.
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

#ifndef __REG_TIM_H
#define __REG_TIM_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief TIM Base Address Definition
  */
#define  TIM1_BASE                                 0x40012C00 /*!<Base Address: 0x40012C00*/
#define  TIM8_BASE                                 0x40013400 /*!<Base Address: 0x40013400*/
#define  TIM2_BASE                                 0x40000000 /*!<Base Address: 0x40000000*/
#define  TIM5_BASE                                 0x40000C00 /*!<Base Address: 0x40000C00*/
#define  TIM3_BASE                                 0x40000400 /*!<Base Address: 0x40000400*/
#define  TIM4_BASE                                 0x40000800 /*!<Base Address: 0x40000800*/
#define  TIM6_BASE                                 0x40001000 /*!<Base Address: 0x40001000*/
#define  TIM7_BASE                                 0x40001400 /*!<Base Address: 0x40001400*/

/**
  * @brief TIM Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR1;                 /*!< TIM control register 1,                        offset: 0x00 */
    __IO uint32_t CR2;                 /*!< TIM control register 2,                        offset: 0x04 */
    __IO uint32_t SMCR;                /*!< TIM slave Mode Control register,               offset: 0x08 */
    __IO uint32_t DIER;                /*!< TIM DMA/interrupt enable register,             offset: 0x0C */
    __IO uint32_t SR;                  /*!< TIM status register,                           offset: 0x10 */
    __IO uint32_t EGR;                 /*!< TIM event generation register,                 offset: 0x14 */
    __IO uint32_t CCMR1;               /*!< TIM capture/compare mode register 1,           offset: 0x18 */
    __IO uint32_t CCMR2;               /*!< TIM capture/compare mode register 2,           offset: 0x1C */
    __IO uint32_t CCER;                /*!< TIM capture/compare enable register,           offset: 0x20 */
    __IO uint32_t CNT;                 /*!< TIM counter register,                          offset: 0x24 */
    __IO uint32_t PSC;                 /*!< TIM prescaler register,                        offset: 0x28 */
    __IO uint32_t ARR;                 /*!< TIM auto-reload register,                      offset: 0x2C */
    __IO uint32_t RCR;                 /*!< TIM repetition counter register,               offset: 0x30 */
    __IO uint32_t CCR1;                /*!< TIM capture/compare register 1,                offset: 0x34 */
    __IO uint32_t CCR2;                /*!< TIM capture/compare register 2,                offset: 0x38 */
    __IO uint32_t CCR3;                /*!< TIM capture/compare register 3,                offset: 0x3C */
    __IO uint32_t CCR4;                /*!< TIM capture/compare register 4,                offset: 0x40 */
    __IO uint32_t BDTR;                /*!< TIM break and dead-time register,              offset: 0x44 */
    __IO uint32_t DCR;                 /*!< TIM DMA control register,                      offset: 0x48 */
    __IO uint32_t DMAR;                /*!< TIM DMA address for full transfer register,    offset: 0x4C */
    __IO uint32_t OR;                  /*!< TIM Input option register,                     offset: 0x50 */
    __IO uint32_t CCMR3;               /*!< TIM capture/compare mode register 3,           offset: 0x54 */
    __IO uint32_t CCR5;                /*!< TIM capture/compare register 5,                offset: 0x58 */
    __IO uint32_t PDER;                /*!< PWM Shift repeat enable register,              offset: 0x5C */
    __IO uint32_t CCR1FALL;            /*!< PWM shift count CCR1 register,                 offset: 0x60 */
    __IO uint32_t CCR2FALL;            /*!< PWM shift count CCR2 register,                 offset: 0x64 */
    __IO uint32_t CCR3FALL;            /*!< PWM shift count CCR3 register,                 offset: 0x68 */
    __IO uint32_t CCR4FALL;            /*!< PWM shift count CCR4 register,                 offset: 0x6C */
    __IO uint32_t CCR5FALL;            /*!< PWM shift count CCR5 register,                 offset: 0x70 */
    __IO uint32_t BKINF;               /*!< TIM Brake input filter register,               offset: 0x74 */
} TIM_TypeDef;

/**
  * @brief TIM type pointer Definition
  */
#define TIM1                                      ((TIM_TypeDef *)TIM1_BASE)
#define TIM8                                      ((TIM_TypeDef *)TIM8_BASE)
#define TIM2                                      ((TIM_TypeDef *)TIM2_BASE)
#define TIM5                                      ((TIM_TypeDef *)TIM5_BASE)
#define TIM3                                      ((TIM_TypeDef *)TIM3_BASE)
#define TIM4                                      ((TIM_TypeDef *)TIM4_BASE)
#define TIM6                                      ((TIM_TypeDef *)TIM6_BASE)
#define TIM7                                      ((TIM_TypeDef *)TIM7_BASE)

/**
  * @brief TIM_CR1 Register Bit Definition
  */
#define  TIM_CR1_CEN_Pos                          (0)
#define  TIM_CR1_CEN_Msk                          (0x01U << TIM_CR1_CEN_Pos)  /*!<*/
#define  TIM_CR1_UDIS_Pos                         (1)
#define  TIM_CR1_UDIS_Msk                         (0x01U << TIM_CR1_UDIS_Pos) /*!<*/
#define  TIM_CR1_URS_Pos                          (2)
#define  TIM_CR1_URS_Msk                          (0x01U << TIM_CR1_URS_Pos)  /*!<*/
#define  TIM_CR1_OPM_Pos                          (3)
#define  TIM_CR1_OPM_Msk                          (0x01U << TIM_CR1_OPM_Pos)  /*!<*/
#define  TIM_CR1_DIR_Pos                          (4)
#define  TIM_CR1_DIR_Msk                          (0x01U << TIM_CR1_DIR_Pos)  /*!<*/
#define  TIM_CR1_CMS_Pos                          (5)
#define  TIM_CR1_CMS_Msk                          (0x03U << TIM_CR1_CMS_Pos)  /*!<*/
#define  TIM_CR1_APRE_Pos                         (7)
#define  TIM_CR1_APRE_Msk                         (0x01U << TIM_CR1_APRE_Pos) /*!<*/
#define  TIM_CR1_CKD_Pos                          (8)
#define  TIM_CR1_CKD_Msk                          (0x03U << TIM_CR1_CKD_Pos)  /*!<*/

/**
  * @brief TIM_CR2 Register Bit Definition
  */
#define  TIM_CR2_CCPC_Pos                         (0)
#define  TIM_CR2_CCPC_Msk                         (0x01U << TIM_CR2_CCPC_Pos)  /*!<*/
#define  TIM_CR2_CCUS_Pos                         (2)
#define  TIM_CR2_CCUS_Msk                         (0x01U << TIM_CR2_CCUS_Pos)  /*!<*/
#define  TIM_CR2_CCDS_Pos                         (3)
#define  TIM_CR2_CCDS_Msk                         (0x01U << TIM_CR2_CCDS_Pos)  /*!<*/
#define  TIM_CR2_MMS_Pos                          (4)
#define  TIM_CR2_MMS_Msk                          (0x07U << TIM_CR2_MMS_Pos)   /*!<*/
#define  TIM_CR2_TI1S_Pos                         (7)
#define  TIM_CR2_TI1S_Msk                         (0x01U << TIM_CR2_TI1S_Pos)  /*!<*/
#define  TIM_CR2_OIS1_Pos                         (8)
#define  TIM_CR2_OIS1_Msk                         (0x01U << TIM_CR2_OIS1_Pos)  /*!<*/
#define  TIM_CR2_OIS1N_Pos                        (9)
#define  TIM_CR2_OIS1N_Msk                        (0x01U << TIM_CR2_OIS1N_Pos) /*!<*/
#define  TIM_CR2_OIS2_Pos                         (10)
#define  TIM_CR2_OIS2_Msk                         (0x01U << TIM_CR2_OIS2_Pos)  /*!<*/
#define  TIM_CR2_OIS2N_Pos                        (11)
#define  TIM_CR2_OIS2N_Msk                        (0x01U << TIM_CR2_OIS2N_Pos) /*!<*/
#define  TIM_CR2_OIS3_Pos                         (12)
#define  TIM_CR2_OIS3_Msk                         (0x01U << TIM_CR2_OIS3_Pos)  /*!<*/
#define  TIM_CR2_OIS3N_Pos                        (13)
#define  TIM_CR2_OIS3N_Msk                        (0x01U << TIM_CR2_OIS3N_Pos) /*!<*/
#define  TIM_CR2_OIS4_Pos                         (14)
#define  TIM_CR2_OIS4_Msk                         (0x01U << TIM_CR2_OIS4_Pos)  /*!<*/
#define  TIM_CR2_OIS4N_Pos                        (15)
#define  TIM_CR2_OIS4N_Msk                        (0x01U << TIM_CR2_OIS4N_Pos) /*!<*/

/**
  * @brief TIM_SMCR Register Bit Definition
  */
#define  TIM_SMCR_SMS_Pos                         (0)
#define  TIM_SMCR_SMS_Msk                         (0x07U << TIM_SMCR_SMS_Pos)  /*!<*/
#define  TIM_SMCR_OCCS_Pos                        (3)
#define  TIM_SMCR_OCCS_Msk                        (0x01U << TIM_SMCR_OCCS_Pos) /*!<*/
#define  TIM_SMCR_TS_Pos                          (4)
#define  TIM_SMCR_TS_Msk                          (0x07U << TIM_SMCR_TS_Pos)   /*!<*/
#define  TIM_SMCR_MSM_Pos                         (7)
#define  TIM_SMCR_MSM_Msk                         (0x01U << TIM_SMCR_MSM_Pos)  /*!<*/
#define  TIM_SMCR_ETF_Pos                         (8)
#define  TIM_SMCR_ETF_Msk                         (0x0FU << TIM_SMCR_ETF_Pos)  /*!<*/
#define  TIM_SMCR_ETPS_Pos                        (12)
#define  TIM_SMCR_ETPS_Msk                        (0x03U << TIM_SMCR_ETPS_Pos) /*!<*/
#define  TIM_SMCR_ECE_Pos                         (14)
#define  TIM_SMCR_ECE_Msk                         (0x01U << TIM_SMCR_ECE_Pos)  /*!<*/
#define  TIM_SMCR_ETP_Pos                         (15)
#define  TIM_SMCR_ETP_Msk                         (0x01U << TIM_SMCR_ETP_Pos)  /*!<*/

/**
  * @brief TIM_DIER Register Bit Definition
  */
#define  TIM_DIER_UIE_Pos                         (0)
#define  TIM_DIER_UIE_Msk                         (0x01U << TIM_DIER_UIE_Pos)   /*!<*/
#define  TIM_DIER_CC1IE_Pos                       (1)
#define  TIM_DIER_CC1IE_Msk                       (0x01U << TIM_DIER_CC1IE_Pos) /*!<*/
#define  TIM_DIER_CC2IE_Pos                       (2)
#define  TIM_DIER_CC2IE_Msk                       (0x01U << TIM_DIER_CC2IE_Pos) /*!<*/
#define  TIM_DIER_CC3IE_Pos                       (3)
#define  TIM_DIER_CC3IE_Msk                       (0x01U << TIM_DIER_CC3IE_Pos) /*!<*/
#define  TIM_DIER_CC4IE_Pos                       (4)
#define  TIM_DIER_CC4IE_Msk                       (0x01U << TIM_DIER_CC4IE_Pos) /*!<*/
#define  TIM_DIER_COMIE_Pos                       (5)
#define  TIM_DIER_COMIE_Msk                       (0x01U << TIM_DIER_COMIE_Pos) /*!<*/
#define  TIM_DIER_TIE_Pos                         (6)
#define  TIM_DIER_TIE_Msk                         (0x01U << TIM_DIER_TIE_Pos)   /*!<*/
#define  TIM_DIER_BIE_Pos                         (7)
#define  TIM_DIER_BIE_Msk                         (0x01U << TIM_DIER_BIE_Pos)   /*!<*/
#define  TIM_DIER_UDE_Pos                         (8)
#define  TIM_DIER_UDE_Msk                         (0x01U << TIM_DIER_UDE_Pos)   /*!<*/
#define  TIM_DIER_CC1DE_Pos                       (9)
#define  TIM_DIER_CC1DE_Msk                       (0x01U << TIM_DIER_CC1DE_Pos) /*!<*/
#define  TIM_DIER_CC2DE_Pos                       (10)
#define  TIM_DIER_CC2DE_Msk                       (0x01U << TIM_DIER_CC2DE_Pos) /*!<*/
#define  TIM_DIER_CC3DE_Pos                       (11)
#define  TIM_DIER_CC3DE_Msk                       (0x01U << TIM_DIER_CC3DE_Pos) /*!<*/
#define  TIM_DIER_CC4DE_Pos                       (12)
#define  TIM_DIER_CC4DE_Msk                       (0x01U << TIM_DIER_CC4DE_Pos) /*!<*/
#define  TIM_DIER_COMDE_Pos                       (13)
#define  TIM_DIER_COMDE_Msk                       (0x01U << TIM_DIER_COMDE_Pos) /*!<*/
#define  TIM_DIER_TDE_Pos                         (14)
#define  TIM_DIER_TDE_Msk                         (0x01U << TIM_DIER_TDE_Pos)   /*!<*/
#define  TIM_DIER_CC5IE_Pos                       (16)
#define  TIM_DIER_CC5IE_Msk                       (0x01U << TIM_DIER_CC5IE_Pos) /*!<*/
#define  TIM_DIER_CC5DE_Pos                       (17)
#define  TIM_DIER_CC5DE_Msk                       (0x01U << TIM_DIER_CC5DE_Pos) /*!<*/

/**
  * @brief TIM_SR Register Bit Definition
  */
#define  TIM_SR_UIF_Pos                           (0)
#define  TIM_SR_UIF_Msk                           (0x01U << TIM_SR_UIF_Pos)   /*!<*/
#define  TIM_SR_CC1IF_Pos                         (1)
#define  TIM_SR_CC1IF_Msk                         (0x01U << TIM_SR_CC1IF_Pos) /*!<*/
#define  TIM_SR_CC2IF_Pos                         (2)
#define  TIM_SR_CC2IF_Msk                         (0x01U << TIM_SR_CC2IF_Pos) /*!<*/
#define  TIM_SR_CC3IF_Pos                         (3)
#define  TIM_SR_CC3IF_Msk                         (0x01U << TIM_SR_CC3IF_Pos) /*!<*/
#define  TIM_SR_CC4IF_Pos                         (4)
#define  TIM_SR_CC4IF_Msk                         (0x01U << TIM_SR_CC4IF_Pos) /*!<*/
#define  TIM_SR_COMIF_Pos                         (5)
#define  TIM_SR_COMIF_Msk                         (0x01U << TIM_SR_COMIF_Pos) /*!<*/
#define  TIM_SR_TIF_Pos                           (6)
#define  TIM_SR_TIF_Msk                           (0x01U << TIM_SR_TIF_Pos)   /*!<*/
#define  TIM_SR_BIF_Pos                           (7)
#define  TIM_SR_BIF_Msk                           (0x01U << TIM_SR_BIF_Pos)   /*!<*/
#define  TIM_SR_CC1OF_Pos                         (9)
#define  TIM_SR_CC1OF_Msk                         (0x01U << TIM_SR_CC1OF_Pos) /*!<*/
#define  TIM_SR_CC2OF_Pos                         (10)
#define  TIM_SR_CC2OF_Msk                         (0x01U << TIM_SR_CC2OF_Pos) /*!<*/
#define  TIM_SR_CC3OF_Pos                         (11)
#define  TIM_SR_CC3OF_Msk                         (0x01U << TIM_SR_CC3OF_Pos) /*!<*/
#define  TIM_SR_CC4OF_Pos                         (12)
#define  TIM_SR_CC4OF_Msk                         (0x01U << TIM_SR_CC4OF_Pos) /*!<*/
#define  TIM_SR_CC5IF_Pos                         (16)
#define  TIM_SR_CC5IF_Msk                         (0x01U << TIM_SR_CC5IF_Pos) /*!<*/

/**
  * @brief TIM_EGR Register Bit Definition
  */
#define  TIM_EGR_UG_Pos                           (0)
#define  TIM_EGR_UG_Msk                           (0x01U << TIM_EGR_UG_Pos)   /*!<*/
#define  TIM_EGR_CC1G_Pos                         (1)
#define  TIM_EGR_CC1G_Msk                         (0x01U << TIM_EGR_CC1G_Pos) /*!<*/
#define  TIM_EGR_CC2G_Pos                         (2)
#define  TIM_EGR_CC2G_Msk                         (0x01U << TIM_EGR_CC2G_Pos) /*!<*/
#define  TIM_EGR_CC3G_Pos                         (3)
#define  TIM_EGR_CC3G_Msk                         (0x01U << TIM_EGR_CC3G_Pos) /*!<*/
#define  TIM_EGR_CC4G_Pos                         (4)
#define  TIM_EGR_CC4G_Msk                         (0x01U << TIM_EGR_CC4G_Pos) /*!<*/
#define  TIM_EGR_COMG_Pos                         (5)
#define  TIM_EGR_COMG_Msk                         (0x01U << TIM_EGR_COMG_Pos) /*!<*/
#define  TIM_EGR_TG_Pos                           (6)
#define  TIM_EGR_TG_Msk                           (0x01U << TIM_EGR_TG_Pos)   /*!<*/
#define  TIM_EGR_BG_Pos                           (7)
#define  TIM_EGR_BG_Msk                           (0x01U << TIM_EGR_BG_Pos)   /*!<*/
#define  TIM_EGR_CC5G_Pos                         (16)
#define  TIM_EGR_CC5G_Msk                         (0x01U << TIM_EGR_CC5G_Pos) /*!<*/

/**
  * @brief TIM_CCMR1 Register Bit Definition
  */
#define TIM_CCMR1_CC1S_Pos                        (0)
#define TIM_CCMR1_CC1S_Msk                        (0x03U << TIM_CCMR1_CC1S_Pos)   /*!< CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_OC1FE_Pos                       (2)
#define TIM_CCMR1_OC1FE_Msk                       (0x01U << TIM_CCMR1_OC1FE_Pos)  /*!< Output Compare 1 Fast enable */
#define TIM_CCMR1_OC1PE_Pos                       (3)
#define TIM_CCMR1_OC1PE_Msk                       (0x01U << TIM_CCMR1_OC1PE_Pos)  /*!< Output Compare 1 Preload enable */
#define TIM_CCMR1_OC1M_Pos                        (4)
#define TIM_CCMR1_OC1M_Msk                        (0x07U << TIM_CCMR1_OC1M_Pos)   /*!< OC1M[2:0] bits (Output Compare 1 Mode) */
#define TIM_CCMR1_OC1CE_Pos                       (7)
#define TIM_CCMR1_OC1CE_Msk                       (0x01U << TIM_CCMR1_OC1CE_Pos)  /*!< Output Compare 1Clear Enable */
#define TIM_CCMR1_CC2S_Pos                        (8)
#define TIM_CCMR1_CC2S_Msk                        (0x03U << TIM_CCMR1_CC2S_Pos)   /*!< CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_OC2FE_Pos                       (10)
#define TIM_CCMR1_OC2FE_Msk                       (0x01U << TIM_CCMR1_OC2FE_Pos)  /*!< Output Compare 2 Fast enable */
#define TIM_CCMR1_OC2PE_Pos                       (11)
#define TIM_CCMR1_OC2PE_Msk                       (0x01U << TIM_CCMR1_OC2PE_Pos)  /*!< Output Compare 2 Preload enable */
#define TIM_CCMR1_OC2M_Pos                        (12)
#define TIM_CCMR1_OC2M_Msk                        (0x07U << TIM_CCMR1_OC2M_Pos)   /*!< OC2M[2:0] bits (Output Compare 2 Mode) */
#define TIM_CCMR1_OC2CE_Pos                       (15)
#define TIM_CCMR1_OC2CE_Msk                       (0x01U << TIM_CCMR1_OC2CE_Pos)  /*!< Output Compare 2 Clear Enable */

#define TIM_CCMR1_IC1PSC_Pos                      (2)
#define TIM_CCMR1_IC1PSC_Msk                      (0x03U << TIM_CCMR1_IC1PSC_Pos) /*!< IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMR1_IC1F_Pos                        (4)
#define TIM_CCMR1_IC1F_Msk                        (0x0FU << TIM_CCMR1_IC1F_Pos)   /*!< IC1F[3:0] bits (Input Capture 1 Filter) */
#define TIM_CCMR1_IC2PSC_Pos                      (10)
#define TIM_CCMR1_IC2PSC_Msk                      (0x03U << TIM_CCMR1_IC2PSC_Pos) /*!< IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TIM_CCMR1_IC2F_Pos                        (12)
#define TIM_CCMR1_IC2F_Msk                        (0x0FU << TIM_CCMR1_IC2F_Pos)   /*!< IC2F[3:0] bits (Input Capture 2 Filter) */

/**
  * @brief TIM_CCMR2 Register Bit Definition
  */
#define TIM_CCMR2_CC3S_Pos                        (0)
#define TIM_CCMR2_CC3S_Msk                        (0x03U << TIM_CCMR2_CC3S_Pos)   /*!< CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TIM_CCMR2_OC3FE_Pos                       (2)
#define TIM_CCMR2_OC3FE_Msk                       (0x01U << TIM_CCMR2_OC3FE_Pos)  /*!< Output Compare 3 Fast enable */
#define TIM_CCMR2_OC3PE_Pos                       (3)
#define TIM_CCMR2_OC3PE_Msk                       (0x01U << TIM_CCMR2_OC3PE_Pos)  /*!< Output Compare 3 Preload enable */
#define TIM_CCMR2_OC3M_Pos                        (4)
#define TIM_CCMR2_OC3M_Msk                        (0x07U << TIM_CCMR2_OC3M_Pos)   /*!< OC3M[2:0] bits (Output Compare 3 Mode) */
#define TIM_CCMR2_OC3CE_Pos                       (7)
#define TIM_CCMR2_OC3CE_Msk                       (0x01U << TIM_CCMR2_OC3CE_Pos)  /*!< Output Compare 3 Clear Enable */
#define TIM_CCMR2_CC4S_Pos                        (8)
#define TIM_CCMR2_CC4S_Msk                        (0x03U << TIM_CCMR2_CC4S_Pos)   /*!< CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMR2_OC4FE_Pos                       (10)
#define TIM_CCMR2_OC4FE_Msk                       (0x01U << TIM_CCMR2_OC4FE_Pos)  /*!< Output Compare 4 Fast enable */
#define TIM_CCMR2_OC4PE_Pos                       (11)
#define TIM_CCMR2_OC4PE_Msk                       (0x01U << TIM_CCMR2_OC4PE_Pos)  /*!< Output Compare 4 Preload enable */
#define TIM_CCMR2_OC4M_Pos                        (12)
#define TIM_CCMR2_OC4M_Msk                        (0x07U << TIM_CCMR2_OC4M_Pos)   /*!< OC4M[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR2_OC4CE_Pos                       (15)
#define TIM_CCMR2_OC4CE_Msk                       (0x01U << TIM_CCMR2_OC4CE_Pos)  /*!< Output Compare 4 Clear Enable */

#define TIM_CCMR2_IC3PSC_Pos                      (2)
#define TIM_CCMR2_IC3PSC_Msk                      (0x03U << TIM_CCMR2_IC3PSC_Pos) /*!< IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3F_Pos                        (4)
#define TIM_CCMR2_IC3F_Msk                        (0x0FU << TIM_CCMR2_IC3F_Pos)   /*!< IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC4PSC_Pos                      (10)
#define TIM_CCMR2_IC4PSC_Msk                      (0x03U << TIM_CCMR2_IC4PSC_Pos) /*!< IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4F_Pos                        (12)
#define TIM_CCMR2_IC4F_Msk                        (0x0FU << TIM_CCMR2_IC4F_Pos)   /*!< IC4F[3:0] bits (Input Capture 4 Filter) */

/**
  * @brief TIM_CCER Register Bit Definition
  */
#define  TIM_CCER_CC1E_Pos                        (0)
#define  TIM_CCER_CC1E_Msk                        (0x01U << TIM_CCER_CC1E_Pos)  /*!<*/
#define  TIM_CCER_CC1P_Pos                        (1)
#define  TIM_CCER_CC1P_Msk                        (0x01U << TIM_CCER_CC1P_Pos)  /*!<*/
#define  TIM_CCER_CC1NE_Pos                       (2)
#define  TIM_CCER_CC1NE_Msk                       (0x01U << TIM_CCER_CC1NE_Pos) /*!<*/
#define  TIM_CCER_CC1NP_Pos                       (3)
#define  TIM_CCER_CC1NP_Msk                       (0x01U << TIM_CCER_CC1NP_Pos) /*!<*/
#define  TIM_CCER_CC2E_Pos                        (4)
#define  TIM_CCER_CC2E_Msk                        (0x01U << TIM_CCER_CC2E_Pos)  /*!<*/
#define  TIM_CCER_CC2P_Pos                        (5)
#define  TIM_CCER_CC2P_Msk                        (0x01U << TIM_CCER_CC2P_Pos)  /*!<*/
#define  TIM_CCER_CC2NE_Pos                       (6)
#define  TIM_CCER_CC2NE_Msk                       (0x01U << TIM_CCER_CC2NE_Pos) /*!<*/
#define  TIM_CCER_CC2NP_Pos                       (7)
#define  TIM_CCER_CC2NP_Msk                       (0x01U << TIM_CCER_CC2NP_Pos) /*!<*/
#define  TIM_CCER_CC3E_Pos                        (8)
#define  TIM_CCER_CC3E_Msk                        (0x01U << TIM_CCER_CC3E_Pos)  /*!<*/
#define  TIM_CCER_CC3P_Pos                        (9)
#define  TIM_CCER_CC3P_Msk                        (0x01U << TIM_CCER_CC3P_Pos)  /*!<*/
#define  TIM_CCER_CC3NE_Pos                       (10)
#define  TIM_CCER_CC3NE_Msk                       (0x01U << TIM_CCER_CC3NE_Pos) /*!<*/
#define  TIM_CCER_CC3NP_Pos                       (11)
#define  TIM_CCER_CC3NP_Msk                       (0x01U << TIM_CCER_CC3NP_Pos) /*!<*/
#define  TIM_CCER_CC4E_Pos                        (12)
#define  TIM_CCER_CC4E_Msk                        (0x01U << TIM_CCER_CC4E_Pos)  /*!<*/
#define  TIM_CCER_CC4P_Pos                        (13)
#define  TIM_CCER_CC4P_Msk                        (0x01U << TIM_CCER_CC4P_Pos)  /*!<*/
#define  TIM_CCER_CC4NE_Pos                       (14)
#define  TIM_CCER_CC4NE_Msk                       (0x01U << TIM_CCER_CC4NE_Pos) /*!<*/
#define  TIM_CCER_CC4NP_Pos                       (15)
#define  TIM_CCER_CC4NP_Msk                       (0x01U << TIM_CCER_CC4NP_Pos) /*!<*/

/**
  * @brief TIM_CNT Register Bit Definition
  */
#define  TIM_CNT_CNT_Pos                          (0)
#define  TIM_CNT_CNT_Msk                          (0xFFFFFFFFU << TIM_CNT_CNT_Pos) /*!<*/

/**
  * @brief TIM_PSC Register Bit Definition
  */
#define  TIM_PSC_PSC_Pos                          (0)
#define  TIM_PSC_PSC_Msk                          (0xFFFFU << TIM_PSC_PSC_Pos) /*!<*/

/**
  * @brief TIM_ARR Register Bit Definition
  */
#define  TIM_ARR_ARR_Pos                          (0)
#define  TIM_ARR_ARR_Msk                          (0xFFFFFFFFU << TIM_ARR_ARR_Pos) /*!<*/

/**
  * @brief TIM_RCR Register Bit Definition
  */
#define  TIM_RCR_REP_Pos                          (0)
#define  TIM_RCR_REP_Msk                          (0xFFU << TIM_RCR_REP_Pos)     /*!<*/
#define  TIM_RCR_REP_CNT_Pos                      (8)
#define  TIM_RCR_REP_CNT_Msk                      (0xFFU << TIM_RCR_REP_CNT_Pos) /*!<*/

/**
  * @brief TIM_CCR1 Register Bit Definition
  */
#define  TIM_CCR1_CCR1_Pos                        (0)
#define  TIM_CCR1_CCR1_Msk                        (0xFFFFFFFFU << TIM_CCR1_CCR1_Pos) /*!<*/

/**
  * @brief TIM_CCR2 Register Bit Definition
  */
#define  TIM_CCR2_CCR2_Pos                        (0)
#define  TIM_CCR2_CCR2_Msk                        (0xFFFFFFFFU << TIM_CCR2_CCR2_Pos) /*!<*/

/**
  * @brief TIM_CCR3 Register Bit Definition
  */
#define  TIM_CCR3_CCR3_Pos                        (0)
#define  TIM_CCR3_CCR3_Msk                        (0xFFFFFFFFU << TIM_CCR3_CCR3_Pos) /*!<*/

/**
  * @brief TIM_CCR4 Register Bit Definition
  */
#define  TIM_CCR4_CCR4_Pos                        (0)
#define  TIM_CCR4_CCR4_Msk                        (0xFFFFFFFFU << TIM_CCR4_CCR4_Pos) /*!<*/

/**
  * @brief TIM_BDTR Register Bit Definition
  */
#define  TIM_BDTR_DTG_Pos                         (0)
#define  TIM_BDTR_DTG_Msk                         (0xFFU << TIM_BDTR_DTG_Pos)  /*!<*/
#define  TIM_BDTR_LOCK_Pos                        (8)
#define  TIM_BDTR_LOCK_Msk                        (0x03U << TIM_BDTR_LOCK_Pos) /*!<*/
#define  TIM_BDTR_OSSI_Pos                        (10)
#define  TIM_BDTR_OSSI_Msk                        (0x01U << TIM_BDTR_OSSI_Pos) /*!<*/
#define  TIM_BDTR_OSSR_Pos                        (11)
#define  TIM_BDTR_OSSR_Msk                        (0x01U << TIM_BDTR_OSSR_Pos) /*!<*/
#define  TIM_BDTR_BKE_Pos                         (12)
#define  TIM_BDTR_BKE_Msk                         (0x01U << TIM_BDTR_BKE_Pos)  /*!<*/
#define  TIM_BDTR_BKP_Pos                         (13)
#define  TIM_BDTR_BKP_Msk                         (0x01U << TIM_BDTR_BKP_Pos)  /*!<*/
#define  TIM_BDTR_AOE_Pos                         (14)
#define  TIM_BDTR_AOE_Msk                         (0x01U << TIM_BDTR_AOE_Pos)  /*!<*/
#define  TIM_BDTR_MOE_Pos                         (15)
#define  TIM_BDTR_MOE_Msk                         (0x01U << TIM_BDTR_MOE_Pos)  /*!<*/
#define  TIM_BDTR_DOE_Pos                         (16)
#define  TIM_BDTR_DOE_Msk                         (0x01U << TIM_BDTR_DOE_Pos)  /*!<*/

/**
  * @brief TIM_DCR Register Bit Definition
  */
#define  TIM_DCR_DBA_Pos                          (0)
#define  TIM_DCR_DBA_Msk                          (0x1FU << TIM_DCR_DBA_Pos) /*!<*/
#define  TIM_DCR_DBL_Pos                          (8)
#define  TIM_DCR_DBL_Msk                          (0x1FU << TIM_DCR_DBL_Pos) /*!<*/

/**
  * @brief TIM_DMAR Register Bit Definition
  */
#define  TIM_DMAR_DMAB_Pos                        (0)
#define  TIM_DMAR_DMAB_Msk                        (0xFFFFU << TIM_DMAR_DMAB_Pos) /*!<*/

/**
  * @brief TIM_OR Register Bit Definition
  */
#define  TIM_OR_ETR_RMP_Pos                       (0)
#define  TIM_OR_ETR_RMP_Msk                       (0x03U << TIM_OR_ETR_RMP_Pos) /*!<*/
#define  TIM_OR_TI4_RMP_Pos                       (6)
#define  TIM_OR_TI4_RMP_Msk                       (0x03U << TIM_OR_TI4_RMP_Pos) /*!<*/

/**
  * @brief TIM_CCMR3 Register Bit Definition
  */
#define  TIM_CCMR3_OC5PE_Pos                      (3)
#define  TIM_CCMR3_OC5PE_Msk                      (0x01U << TIM_CCMR3_OC5PE_Pos) /*!<*/

/**
  * @brief TIM_CCR5 Register Bit Definition
  */
#define  TIM_CCR5_CCR5_Pos                        (0)
#define  TIM_CCR5_CCR5_Msk                        (0xFFFFU << TIM_CCR5_CCR5_Pos) /*!<*/

/**
  * @brief TIM_PDER Register Bit Definition
  */
#define  TIM_PDER_CCDREPE_Pos                     (0)
#define  TIM_PDER_CCDREPE_Msk                     (0x01U << TIM_PDER_CCDREPE_Pos)       /*!<*/
#define  TIM_PDER_CCR1_SHIFT_EN_Pos               (1)
#define  TIM_PDER_CCR1_SHIFT_EN_Msk               (0x01U << TIM_PDER_CCR1_SHIFT_EN_Pos) /*!<*/
#define  TIM_PDER_CCR2_SHIFT_EN_Pos               (2)
#define  TIM_PDER_CCR2_SHIFT_EN_Msk               (0x01U << TIM_PDER_CCR2_SHIFT_EN_Pos) /*!<*/
#define  TIM_PDER_CCR3_SHIFT_EN_Pos               (3)
#define  TIM_PDER_CCR3_SHIFT_EN_Msk               (0x01U << TIM_PDER_CCR3_SHIFT_EN_Pos) /*!<*/
#define  TIM_PDER_CCR4_SHIFT_EN_Pos               (4)
#define  TIM_PDER_CCR4_SHIFT_EN_Msk               (0x01U << TIM_PDER_CCR4_SHIFT_EN_Pos) /*!<*/
#define  TIM_PDER_CCR5_SHIFT_EN_Pos               (5)
#define  TIM_PDER_CCR5_SHIFT_EN_Msk               (0x01U << TIM_PDER_CCR5_SHIFT_EN_Pos) /*!<*/

/**
  * @brief TIM_CCRFALL Register Bit Definition
  */
#define TIM_CCR1FALL_CCR1FALL                     (0xFFFFU)                             /*!< Capture/compare value for ch1 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR2FALL Register Bit Definition
  */
#define TIM_CCR2FALL_CCR2FALL                     (0xFFFFU)                             /*!< Capture/compare value for ch2 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR3FALL Register Bit Definition
  */
#define TIM_CCR3FALL_CCR3FALL                     (0xFFFFU)                             /*!< Capture/compare value for ch3 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR4FALL Register Bit Definition
  */
#define TIM_CCR4FALL_CCR4FALL                     (0xFFFFU)                             /*!< Capture/compare value for ch4 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR5FALL Register Bit Definition
  */
#define TIM_CCR5FALL_CCR5FALL                     (0xFFFFU)                             /*!< Capture/compare value for ch5 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_BKINF Register Bit Definition
  */
#define  TIM_BKINF_BKINFE_Pos                     (0)
#define  TIM_BKINF_BKINFE_Msk                     (0x01U << TIM_BKINF_BKINFE_Pos)       /*!<*/
#define  TIM_BKINF_BKINF_Pos                      (1)
#define  TIM_BKINF_BKINF_Msk                      (0x0FU << TIM_BKINF_BKINF_Pos)        /*!<*/
#define  TIM_BKINF_CSSBKIN_SEL_Pos                (5)
#define  TIM_BKINF_CSSBKIN_SEL_Msk                (0x01U << TIM_BKINF_CSSBKIN_SEL_Pos)  /*!<*/
#define  TIM_BKINF_IOBKIN_SEL_Pos                 (6)
#define  TIM_BKINF_IOBKIN_SEL_Msk                 (0x0FU << TIM_BKINF_IOBKIN_SEL_Pos)   /*!<*/
#define  TIM_BKINF_COMPBKIN_SEL_Pos               (13)
#define  TIM_BKINF_COMPBKIN_SEL_Msk               (0x07U << TIM_BKINF_COMPBKIN_SEL_Pos) /*!<*/

#endif

