/***********************************************************************************************************************
    @file     reg_bkp.h
    @author   VV TEAM
    @brief    This flie contains all the BKP's register and its field definition.
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

#ifndef __REG_BKP_H
#define __REG_BKP_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief BKP Base Address Definition
  */
#define  BKP_BASE                                  0x40002840 /*!<Base Address: 0x40002840*/

/**
  * @brief BKP Register Structure Definition
  */
typedef struct
{
    __IO uint32_t RTCCR;               /*!<BKP RTC clock calibration register             offset: 0x00*/
    __IO uint32_t CR;                  /*!<BKP Backup control register                    offset: 0x04*/
    __IO uint32_t CSR;                 /*!<BKP Backup control status register             offset: 0x08*/
    __IO uint32_t RESERVED0x00C[1];    /*!<                                               offset: 0xc*/
    __IO uint32_t DR0;                 /*!<BKP Backup data register n                     offset: 0x10*/
    __IO uint32_t DR1;                 /*!<BKP Backup data register n                     offset: 0x14*/
    __IO uint32_t DR2;                 /*!<BKP Backup data register n                     offset: 0x18*/
    __IO uint32_t DR3;                 /*!<BKP Backup data register n                     offset: 0x1C*/
    __IO uint32_t DR4;                 /*!<BKP Backup data register n                     offset: 0x20*/
    __IO uint32_t DR5;                 /*!<BKP Backup data register n                     offset: 0x24*/
    __IO uint32_t DR6;                 /*!<BKP Backup data register n                     offset: 0x28*/
    __IO uint32_t DR7;                 /*!<BKP Backup data register n                     offset: 0x2C*/
    __IO uint32_t DR8;                 /*!<BKP Backup data register n                     offset: 0x30*/
    __IO uint32_t DR9;                 /*!<BKP Backup data register n                     offset: 0x34*/
    __IO uint32_t DR10;                /*!<BKP Backup data register n                     offset: 0x38*/
    __IO uint32_t DR11;                /*!<BKP Backup data register n                     offset: 0x3C*/
    __IO uint32_t DR12;                /*!<BKP Backup data register n                     offset: 0x40*/
    __IO uint32_t DR13;                /*!<BKP Backup data register n                     offset: 0x44*/
    __IO uint32_t DR14;                /*!<BKP Backup data register n                     offset: 0x48*/
    __IO uint32_t DR15;                /*!<BKP Backup data register n                     offset: 0x4C*/
    __IO uint32_t DR16;                /*!<BKP Backup data register n                     offset: 0x50*/
    __IO uint32_t DR17;                /*!<BKP Backup data register n                     offset: 0x54*/
    __IO uint32_t DR18;                /*!<BKP Backup data register n                     offset: 0x58*/
    __IO uint32_t DR19;                /*!<BKP Backup data register n                     offset: 0x5C*/
} BKP_TypeDef;

/**
  * @brief BKP type pointer Definition
  */
#define BKP                                       ((BKP_TypeDef *)BKP_BASE)

/**
  * @brief BKP_RTCCR Register Bit Definition
  */
#define  BKP_RTCCR_CAL_Pos                        (0)
#define  BKP_RTCCR_CAL_Msk                        (0x7FU << BKP_RTCCR_CAL_Pos)  /*!<*/
#define  BKP_RTCCR_CCO_Pos                        (7)
#define  BKP_RTCCR_CCO_Msk                        (0x01U << BKP_RTCCR_CCO_Pos)  /*!<*/
#define  BKP_RTCCR_ASOE_Pos                       (8)
#define  BKP_RTCCR_ASOE_Msk                       (0x01U << BKP_RTCCR_ASOE_Pos) /*!<*/
#define  BKP_RTCCR_ASOS_Pos                       (9)
#define  BKP_RTCCR_ASOS_Msk                       (0x01U << BKP_RTCCR_ASOS_Pos) /*!<*/

/**
  * @brief BKP_CR Register Bit Definition
  */
#define  BKP_CR_TPE_Pos                           (0)
#define  BKP_CR_TPE_Msk                           (0x01U << BKP_CR_TPE_Pos)  /*!<*/
#define  BKP_CR_TPAL_Pos                          (1)
#define  BKP_CR_TPAL_Msk                          (0x01U << BKP_CR_TPAL_Pos) /*!<*/

/**
  * @brief BKP_CSR Register Bit Definition
  */
#define  BKP_CSR_CTE_Pos                          (0)
#define  BKP_CSR_CTE_Msk                          (0x01U << BKP_CSR_CTE_Pos)  /*!<*/
#define  BKP_CSR_CTI_Pos                          (1)
#define  BKP_CSR_CTI_Msk                          (0x01U << BKP_CSR_CTI_Pos)  /*!<*/
#define  BKP_CSR_TPIE_Pos                         (2)
#define  BKP_CSR_TPIE_Msk                         (0x01U << BKP_CSR_TPIE_Pos) /*!<*/
#define  BKP_CSR_TEF_Pos                          (8)
#define  BKP_CSR_TEF_Msk                          (0x01U << BKP_CSR_TEF_Pos)  /*!<*/
#define  BKP_CSR_TIF_Pos                          (9)
#define  BKP_CSR_TIF_Msk                          (0x01U << BKP_CSR_TIF_Pos)  /*!<*/

/**
  * @brief BKP_DR Register Bit Definition
  */
#define  BKP_DR_BKP_Pos                           (0)
#define  BKP_DR_BKP_Msk                           (0xFFFFU << BKP_DR_BKP_Pos) /*!<*/

#endif

