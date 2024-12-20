/***********************************************************************************************************************
    @file     reg_rtc.h
    @author   VV TEAM
    @brief    This flie contains all the RTC's register and its field definition.
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

#ifndef __REG_RTC_H
#define __REG_RTC_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief RTC Base Address Definition
  */
#define  RTC_BASE                                  0x40002800 /*!<Base Address: 0x40002800*/

/**
  * @brief RTC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CRH;                 /*!<RTC RTC control register high                  offset: 0x00*/
    __IO uint32_t CRL;                 /*!<RTC RTC control register low                   offset: 0x04*/
    __IO uint32_t PRLH;                /*!<RTC RTC prescaler load register high           offset: 0x08*/
    __IO uint32_t PRLL;                /*!<RTC RTC prescaler load register low            offset: 0x0C*/
    __IO uint32_t DIVH;                /*!<RTC RTC prescaler divider register high        offset: 0x10*/
    __IO uint32_t DIVL;                /*!<RTC RTC prescaler divider register low         offset: 0x14*/
    __IO uint32_t CNTH;                /*!<RTC RTC counter register high                  offset: 0x18*/
    __IO uint32_t CNTL;                /*!<RTC RTC counter register low                   offset: 0x1C*/
    __IO uint32_t ALRH;                /*!<RTC RTC alarm register high                    offset: 0x20*/
    __IO uint32_t ALRL;                /*!<RTC RTC alarm register low                     offset: 0x24*/
    __IO uint32_t MSRH;                /*!<RTC RTC millisecond register high              offset: 0x28*/
    __IO uint32_t MSRL;                /*!<RTC RTC millisecond register low               offset: 0x2C*/
    __IO uint32_t RESERVED0x030[3];    /*!<                                               offset: 0x30~0x38*/
    __IO uint32_t LSE_CFG;             /*!<RTC RTC LSE configuration register             offset: 0x3C*/
} RTC_TypeDef;

/**
  * @brief RTC type pointer Definition
  */
#define RTC                                       ((RTC_TypeDef *)RTC_BASE)

/**
  * @brief RTC_CRH Register Bit Definition
  */
#define  RTC_CRH_SECIE_Pos                        (0)
#define  RTC_CRH_SECIE_Msk                        (0x01U << RTC_CRH_SECIE_Pos) /*!<*/
#define  RTC_CRH_ALRIE_Pos                        (1)
#define  RTC_CRH_ALRIE_Msk                        (0x01U << RTC_CRH_ALRIE_Pos) /*!<*/
#define  RTC_CRH_OWIE_Pos                         (2)
#define  RTC_CRH_OWIE_Msk                         (0x01U << RTC_CRH_OWIE_Pos)  /*!<*/

/**
  * @brief RTC_CRL Register Bit Definition
  */
#define  RTC_CRL_SECF_Pos                         (0)
#define  RTC_CRL_SECF_Msk                         (0x01U << RTC_CRL_SECF_Pos)  /*!<*/
#define  RTC_CRL_ALRF_Pos                         (1)
#define  RTC_CRL_ALRF_Msk                         (0x01U << RTC_CRL_ALRF_Pos)  /*!<*/
#define  RTC_CRL_OWF_Pos                          (2)
#define  RTC_CRL_OWF_Msk                          (0x01U << RTC_CRL_OWF_Pos)   /*!<*/
#define  RTC_CRL_RSF_Pos                          (3)
#define  RTC_CRL_RSF_Msk                          (0x01U << RTC_CRL_RSF_Pos)   /*!<*/
#define  RTC_CRL_CNF_Pos                          (4)
#define  RTC_CRL_CNF_Msk                          (0x01U << RTC_CRL_CNF_Pos)   /*!<*/
#define  RTC_CRL_RTOFF_Pos                        (5)
#define  RTC_CRL_RTOFF_Msk                        (0x01U << RTC_CRL_RTOFF_Pos) /*!<*/
#define  RTC_CRL_ALPEN_Pos                        (6)
#define  RTC_CRL_ALPEN_Msk                        (0x01U << RTC_CRL_ALPEN_Pos) /*!<*/

/**
  * @brief RTC_PRLH Register Bit Definition
  */
#define  RTC_PRLH_PRL_Pos                         (0)
#define  RTC_PRLH_PRL_Msk                         (0x0FU << RTC_PRLH_PRL_Pos) /*!<*/

/**
  * @brief RTC_PRLL Register Bit Definition
  */
#define  RTC_PRLL_PRL_Pos                         (0)
#define  RTC_PRLL_PRL_Msk                         (0xFFFFU << RTC_PRLL_PRL_Pos) /*!<*/

/**
  * @brief RTC_DIVH Register Bit Definition
  */
#define  RTC_DIVH_DIV_Pos                         (0)
#define  RTC_DIVH_DIV_Msk                         (0x0FU << RTC_DIVH_DIV_Pos) /*!<*/

/**
  * @brief RTC_DIVL Register Bit Definition
  */
#define  RTC_DIVL_DIV_Pos                         (0)
#define  RTC_DIVL_DIV_Msk                         (0xFFFFU << RTC_DIVL_DIV_Pos) /*!<*/

/**
  * @brief RTC_CNTH Register Bit Definition
  */
#define  RTC_CNTH_CNT_Pos                         (0)
#define  RTC_CNTH_CNT_Msk                         (0xFFFFU << RTC_CNTH_CNT_Pos) /*!<*/

/**
  * @brief RTC_CNTL Register Bit Definition
  */
#define  RTC_CNTL_CNT_Pos                         (0)
#define  RTC_CNTL_CNT_Msk                         (0xFFFFU << RTC_CNTL_CNT_Pos) /*!<*/

/**
  * @brief RTC_ALRH Register Bit Definition
  */
#define  RTC_ALRH_ALR_Pos                         (0)
#define  RTC_ALRH_ALR_Msk                         (0xFFFFU << RTC_ALRH_ALR_Pos) /*!<*/

/**
  * @brief RTC_ALRL Register Bit Definition
  */
#define  RTC_ALRL_ALR_Pos                         (0)
#define  RTC_ALRL_ALR_Msk                         (0xFFFFU << RTC_ALRL_ALR_Pos) /*!<*/

/**
  * @brief RTC_MSRH Register Bit Definition
  */
#define  RTC_MSRH_MSR_Pos                         (0)
#define  RTC_MSRH_MSR_Msk                         (0x0FU << RTC_MSRH_MSR_Pos) /*!<*/

/**
  * @brief RTC_MSRL Register Bit Definition
  */
#define  RTC_MSRL_MSR_Pos                         (0)
#define  RTC_MSRL_MSR_Msk                         (0xFFFFU << RTC_MSRL_MSR_Pos) /*!<*/

/**
  * @brief RTC_LSE_CFG Register Bit Definition
  */
#define  RTC_LSE_CFG_LSE_TC_Pos                   (0)
#define  RTC_LSE_CFG_LSE_TC_Msk                   (0x03U << RTC_LSE_CFG_LSE_TC_Pos)      /*!<*/
#define  RTC_LSE_CFG_LSE_OUTENH_Pos               (2)
#define  RTC_LSE_CFG_LSE_OUTENH_Msk               (0x01U << RTC_LSE_CFG_LSE_OUTENH_Pos)  /*!<*/
#define  RTC_LSE_CFG_LSE_DR_Pos                   (4)
#define  RTC_LSE_CFG_LSE_DR_Msk                   (0x03U << RTC_LSE_CFG_LSE_DR_Pos)      /*!<*/
#define  RTC_LSE_CFG_LSE_RFB_SEL_Pos              (6)
#define  RTC_LSE_CFG_LSE_RFB_SEL_Msk              (0x03U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) /*!<*/
#define  RTC_LSE_CFG_LSE_IB_Pos                   (8)
#define  RTC_LSE_CFG_LSE_IB_Msk                   (0x03U << RTC_LSE_CFG_LSE_IB_Pos)      /*!<*/
#define  RTC_LSE_CFG_LSE_AAC_Pos                  (10)
#define  RTC_LSE_CFG_LSE_AAC_Msk                  (0x01U << RTC_LSE_CFG_LSE_AAC_Pos)     /*!<*/

#endif

