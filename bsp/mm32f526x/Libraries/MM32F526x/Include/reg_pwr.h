/***********************************************************************************************************************
    @file     reg_pwr.h
    @author   VV TEAM
    @brief    This flie contains all the PWR's register and its field definition.
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

#ifndef __REG_PWR_H
#define __REG_PWR_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief PWR Base Address Definition
  */
#define  PWR_BASE                                  0x40007000 /*!<Base Address: 0x40007000*/

/**
  * @brief PWR Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR1;                 /*!<PWR Power control register 1                   offset: 0x00*/
    __IO uint32_t CSR;                 /*!<PWR Power control status register              offset: 0x04*/
    __IO uint32_t CR2;                 /*!<PWR Power control register 2                   offset: 0x08*/
    __IO uint32_t CR3;                 /*!<PWR Power control register 3                   offset: 0x0C*/
    __IO uint32_t CR4;                 /*!<PWR Power control register 4                   offset: 0x10*/
    __IO uint32_t CR5;                 /*!<PWR Power control register 5                   offset: 0x14*/
    __IO uint32_t CR6;                 /*!<PWR Power control register 6                   offset: 0x18*/
    __IO uint32_t SR;                  /*!<PWR Power status register                      offset: 0x1C*/
    __IO uint32_t SCR;                 /*!<PWR Power status clear register                offset: 0x20*/
    __IO uint32_t CFGR;                /*!<PWR Power configuration register               offset: 0x24*/
} PWR_TypeDef;

/**
  * @brief PWR type pointer Definition
  */
#define PWR                                       ((PWR_TypeDef *)PWR_BASE)

/**
  * @brief PWR_CR1 Register Bit Definition
  */
#define  PWR_CR1_LPDS_Pos                         (0)
#define  PWR_CR1_LPDS_Msk                         (0x01U << PWR_CR1_LPDS_Pos) /*!<*/
#define  PWR_CR1_PDDS_Pos                         (1)
#define  PWR_CR1_PDDS_Msk                         (0x01U << PWR_CR1_PDDS_Pos) /*!<*/
#define  PWR_CR1_CSBF_Pos                         (3)
#define  PWR_CR1_CSBF_Msk                         (0x01U << PWR_CR1_CSBF_Pos) /*!<*/
#define  PWR_CR1_LPR_Pos                          (13)
#define  PWR_CR1_LPR_Msk                          (0x01U << PWR_CR1_LPR_Pos)  /*!<*/
#define  PWR_CR1_VOS_Pos                          (14)
#define  PWR_CR1_VOS_Msk                          (0x03U << PWR_CR1_VOS_Pos)  /*!<*/

/**
  * @brief PWR_CSR Register Bit Definition
  */
#define  PWR_CSR_SBF_Pos                          (1)
#define  PWR_CSR_SBF_Msk                          (0x01U << PWR_CSR_SBF_Pos)    /*!<*/
#define  PWR_CSR_VOSRDY_Pos                       (14)
#define  PWR_CSR_VOSRDY_Msk                       (0x01U << PWR_CSR_VOSRDY_Pos) /*!<*/

/**
  * @brief PWR_CR2 Register Bit Definition
  */
#define  PWR_CR2_EWUP0_Pos                        (0)
#define  PWR_CR2_EWUP0_Msk                        (0x01U << PWR_CR2_EWUP0_Pos) /*!<*/
#define  PWR_CR2_EWUP1_Pos                        (1)
#define  PWR_CR2_EWUP1_Msk                        (0x01U << PWR_CR2_EWUP1_Pos) /*!<*/
#define  PWR_CR2_EWUP2_Pos                        (2)
#define  PWR_CR2_EWUP2_Msk                        (0x01U << PWR_CR2_EWUP2_Pos) /*!<*/
#define  PWR_CR2_EWUP3_Pos                        (3)
#define  PWR_CR2_EWUP3_Msk                        (0x01U << PWR_CR2_EWUP3_Pos) /*!<*/
#define  PWR_CR2_EWUP4_Pos                        (4)
#define  PWR_CR2_EWUP4_Msk                        (0x01U << PWR_CR2_EWUP4_Pos) /*!<*/
#define  PWR_CR2_EWUP5_Pos                        (5)
#define  PWR_CR2_EWUP5_Msk                        (0x01U << PWR_CR2_EWUP5_Pos) /*!<*/

/**
  * @brief PWR_CR3 Register Bit Definition
  */
#define  PWR_CR3_WP0_Pos                          (0)
#define  PWR_CR3_WP0_Msk                          (0x01U << PWR_CR3_WP0_Pos) /*!<*/
#define  PWR_CR3_WP1_Pos                          (1)
#define  PWR_CR3_WP1_Msk                          (0x01U << PWR_CR3_WP1_Pos) /*!<*/
#define  PWR_CR3_WP2_Pos                          (2)
#define  PWR_CR3_WP2_Msk                          (0x01U << PWR_CR3_WP2_Pos) /*!<*/
#define  PWR_CR3_WP3_Pos                          (3)
#define  PWR_CR3_WP3_Msk                          (0x01U << PWR_CR3_WP3_Pos) /*!<*/
#define  PWR_CR3_WP4_Pos                          (4)
#define  PWR_CR3_WP4_Msk                          (0x01U << PWR_CR3_WP4_Pos) /*!<*/
#define  PWR_CR3_WP5_Pos                          (5)
#define  PWR_CR3_WP5_Msk                          (0x01U << PWR_CR3_WP5_Pos) /*!<*/

/**
  * @brief PWR_CR4 Register Bit Definition
  */
#define  PWR_CR4_FILTSEL0_Pos                     (0)
#define  PWR_CR4_FILTSEL0_Msk                     (0x03U << PWR_CR4_FILTSEL0_Pos) /*!<*/
#define  PWR_CR4_FILTE0_Pos                       (2)
#define  PWR_CR4_FILTE0_Msk                       (0x03U << PWR_CR4_FILTE0_Pos)   /*!<*/
#define  PWR_CR4_FILTF0_Pos                       (4)
#define  PWR_CR4_FILTF0_Msk                       (0x01U << PWR_CR4_FILTF0_Pos)   /*!<*/
#define  PWR_CR4_FILTCNT0_Pos                     (8)
#define  PWR_CR4_FILTCNT0_Msk                     (0xFFU << PWR_CR4_FILTCNT0_Pos) /*!<*/

/**
  * @brief PWR_CR5 Register Bit Definition
  */
#define  PWR_CR5_FILTSEL1_Pos                     (0)
#define  PWR_CR5_FILTSEL1_Msk                     (0x03U << PWR_CR5_FILTSEL1_Pos) /*!<*/
#define  PWR_CR5_FILTE1_Pos                       (2)
#define  PWR_CR5_FILTE1_Msk                       (0x03U << PWR_CR5_FILTE1_Pos)   /*!<*/
#define  PWR_CR5_FILTF1_Pos                       (4)
#define  PWR_CR5_FILTF1_Msk                       (0x01U << PWR_CR5_FILTF1_Pos)   /*!<*/
#define  PWR_CR5_FILTCNT1_Pos                     (8)
#define  PWR_CR5_FILTCNT1_Msk                     (0xFFU << PWR_CR5_FILTCNT1_Pos) /*!<*/

/**
  * @brief PWR_CR6 Register Bit Definition
  */
#define  PWR_CR6_STDBY_FS_WK_Pos                  (0)
#define  PWR_CR6_STDBY_FS_WK_Msk                  (0x07U << PWR_CR6_STDBY_FS_WK_Pos) /*!<*/

/**
  * @brief PWR_SR Register Bit Definition
  */
#define  PWR_SR_WUF0_Pos                          (0)
#define  PWR_SR_WUF0_Msk                          (0x01U << PWR_SR_WUF0_Pos) /*!<*/
#define  PWR_SR_WUF1_Pos                          (1)
#define  PWR_SR_WUF1_Msk                          (0x01U << PWR_SR_WUF1_Pos) /*!<*/
#define  PWR_SR_WUF2_Pos                          (2)
#define  PWR_SR_WUF2_Msk                          (0x01U << PWR_SR_WUF2_Pos) /*!<*/
#define  PWR_SR_WUF3_Pos                          (3)
#define  PWR_SR_WUF3_Msk                          (0x01U << PWR_SR_WUF3_Pos) /*!<*/
#define  PWR_SR_WUF4_Pos                          (4)
#define  PWR_SR_WUF4_Msk                          (0x01U << PWR_SR_WUF4_Pos) /*!<*/
#define  PWR_SR_WUF5_Pos                          (5)
#define  PWR_SR_WUF5_Msk                          (0x01U << PWR_SR_WUF5_Pos) /*!<*/

/**
  * @brief PWR_SCR Register Bit Definition
  */
#define  PWR_SCR_CWUF0_Pos                        (0)
#define  PWR_SCR_CWUF0_Msk                        (0x01U << PWR_SCR_CWUF0_Pos) /*!<*/
#define  PWR_SCR_CWUF1_Pos                        (1)
#define  PWR_SCR_CWUF1_Msk                        (0x01U << PWR_SCR_CWUF1_Pos) /*!<*/
#define  PWR_SCR_CWUF2_Pos                        (2)
#define  PWR_SCR_CWUF2_Msk                        (0x01U << PWR_SCR_CWUF2_Pos) /*!<*/
#define  PWR_SCR_CWUF3_Pos                        (3)
#define  PWR_SCR_CWUF3_Msk                        (0x01U << PWR_SCR_CWUF3_Pos) /*!<*/
#define  PWR_SCR_CWUF4_Pos                        (4)
#define  PWR_SCR_CWUF4_Msk                        (0x01U << PWR_SCR_CWUF4_Pos) /*!<*/
#define  PWR_SCR_CWUF5_Pos                        (5)
#define  PWR_SCR_CWUF5_Msk                        (0x01U << PWR_SCR_CWUF5_Pos) /*!<*/

/**
  * @brief PWR_CFGR Register Bit Definition
  */
#define  PWR_CFGR_LSICALSEL_Pos                   (0)
#define  PWR_CFGR_LSICALSEL_Msk                   (0x1FU << PWR_CFGR_LSICALSEL_Pos) /*!<*/
#define  PWR_CFGR_LSICAL_Pos                      (5)
#define  PWR_CFGR_LSICAL_Msk                      (0x1FU << PWR_CFGR_LSICAL_Pos)    /*!<*/

#endif

