/***********************************************************************************************************************
    @file     reg_crs.h
    @author   VV TEAM
    @brief    This flie contains all the CRS's register and its field definition.
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

#ifndef __REG_CRS_H
#define __REG_CRS_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief CRS Base Address Definition
  */
#define  CRS_BASE                                  0x40006C00 /*!<Base Address: 0x40006C00*/

/**
  * @brief CRS Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                  /*!<CRS CRS control register                       offset: 0x00*/
    __IO uint32_t CFGR;                /*!<CRS CRS configuration register                 offset: 0x04*/
    __IO uint32_t ISR;                 /*!<CRS CRS interrupt status register              offset: 0x08*/
    __IO uint32_t ICR;                 /*!<CRS CRS interrupt flag clear register          offset: 0x0C*/
} CRS_TypeDef;

/**
  * @brief CRS type pointer Definition
  */
#define CRS                                       ((CRS_TypeDef *)CRS_BASE)

/**
  * @brief CRS_CR Register Bit Definition
  */
#define  CRS_CR_SYNCOKIE_Pos                      (0)
#define  CRS_CR_SYNCOKIE_Msk                      (0x01U << CRS_CR_SYNCOKIE_Pos)   /*!<*/
#define  CRS_CR_SYNCWARNIE_Pos                    (1)
#define  CRS_CR_SYNCWARNIE_Msk                    (0x01U << CRS_CR_SYNCWARNIE_Pos) /*!<*/
#define  CRS_CR_ERRIE_Pos                         (2)
#define  CRS_CR_ERRIE_Msk                         (0x01U << CRS_CR_ERRIE_Pos)      /*!<*/
#define  CRS_CR_ESYNCIE_Pos                       (3)
#define  CRS_CR_ESYNCIE_Msk                       (0x01U << CRS_CR_ESYNCIE_Pos)    /*!<*/
#define  CRS_CR_CEN_Pos                           (5)
#define  CRS_CR_CEN_Msk                           (0x01U << CRS_CR_CEN_Pos)        /*!<*/
#define  CRS_CR_AUTOTRIMEN_Pos                    (6)
#define  CRS_CR_AUTOTRIMEN_Msk                    (0x01U << CRS_CR_AUTOTRIMEN_Pos) /*!<*/
#define  CRS_CR_SWSYNC_Pos                        (7)
#define  CRS_CR_SWSYNC_Msk                        (0x01U << CRS_CR_SWSYNC_Pos)     /*!<*/
#define  CRS_CR_TRIM_Pos                          (8)
#define  CRS_CR_TRIM_Msk                          (0x03FFU << CRS_CR_TRIM_Pos)     /*!<*/

/**
  * @brief CRS_CFGR Register Bit Definition
  */
#define  CRS_CFGR_RELOAD_Pos                      (0)
#define  CRS_CFGR_RELOAD_Msk                      (0xFFFFU << CRS_CFGR_RELOAD_Pos) /*!<*/
#define  CRS_CFGR_FELIM_Pos                       (16)
#define  CRS_CFGR_FELIM_Msk                       (0xFFU << CRS_CFGR_FELIM_Pos)    /*!<*/
#define  CRS_CFGR_SYNCDIV_Pos                     (24)
#define  CRS_CFGR_SYNCDIV_Msk                     (0x07U << CRS_CFGR_SYNCDIV_Pos)  /*!<*/
#define  CRS_CFGR_SYNCSRC_Pos                     (28)
#define  CRS_CFGR_SYNCSRC_Msk                     (0x03U << CRS_CFGR_SYNCSRC_Pos)  /*!<*/
#define  CRS_CFGR_SYNCPOL_Pos                     (31)
#define  CRS_CFGR_SYNCPOL_Msk                     (0x01U << CRS_CFGR_SYNCPOL_Pos)  /*!<*/

/**
  * @brief CRS_ISR Register Bit Definition
  */
#define  CRS_ISR_SYNCOKF_Pos                      (0)
#define  CRS_ISR_SYNCOKF_Msk                      (0x01U << CRS_ISR_SYNCOKF_Pos)   /*!<*/
#define  CRS_ISR_SYNCWARNF_Pos                    (1)
#define  CRS_ISR_SYNCWARNF_Msk                    (0x01U << CRS_ISR_SYNCWARNF_Pos) /*!<*/
#define  CRS_ISR_ERRF_Pos                         (2)
#define  CRS_ISR_ERRF_Msk                         (0x01U << CRS_ISR_ERRF_Pos)      /*!<*/
#define  CRS_ISR_ESYNCF_Pos                       (3)
#define  CRS_ISR_ESYNCF_Msk                       (0x01U << CRS_ISR_ESYNCF_Pos)    /*!<*/
#define  CRS_ISR_SYNCERR_Pos                      (8)
#define  CRS_ISR_SYNCERR_Msk                      (0x01U << CRS_ISR_SYNCERR_Pos)   /*!<*/
#define  CRS_ISR_SYNCMISS_Pos                     (9)
#define  CRS_ISR_SYNCMISS_Msk                     (0x01U << CRS_ISR_SYNCMISS_Pos)  /*!<*/
#define  CRS_ISR_TRIMOVF_Pos                      (10)
#define  CRS_ISR_TRIMOVF_Msk                      (0x01U << CRS_ISR_TRIMOVF_Pos)   /*!<*/
#define  CRS_ISR_FEDIR_Pos                        (15)
#define  CRS_ISR_FEDIR_Msk                        (0x01U << CRS_ISR_FEDIR_Pos)     /*!<*/
#define  CRS_ISR_FECAP_Pos                        (16)
#define  CRS_ISR_FECAP_Msk                        (0xFFFFU << CRS_ISR_FECAP_Pos)   /*!<*/

/**
  * @brief CRS_ICR Register Bit Definition
  */
#define  CRS_ICR_SYNCOKC_Pos                      (0)
#define  CRS_ICR_SYNCOKC_Msk                      (0x01U << CRS_ICR_SYNCOKC_Pos)   /*!<*/
#define  CRS_ICR_SYNCWARNC_Pos                    (1)
#define  CRS_ICR_SYNCWARNC_Msk                    (0x01U << CRS_ICR_SYNCWARNC_Pos) /*!<*/
#define  CRS_ICR_ERRC_Pos                         (2)
#define  CRS_ICR_ERRC_Msk                         (0x01U << CRS_ICR_ERRC_Pos)      /*!<*/
#define  CRS_ICR_ESYNCC_Pos                       (3)
#define  CRS_ICR_ESYNCC_Msk                       (0x01U << CRS_ICR_ESYNCC_Pos)    /*!<*/

#endif

