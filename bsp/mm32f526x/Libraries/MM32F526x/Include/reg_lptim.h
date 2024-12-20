/***********************************************************************************************************************
    @file     reg_lptim.h
    @author   VV TEAM
    @brief    This flie contains all the LPTIM's register and its field definition.
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

#ifndef __REG_LPTIM_H
#define __REG_LPTIM_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief LPTIM Base Address Definition
  */
#define  LPTIM_BASE                                0x4001D000 /*!<Base Address: 0x4001D000*/

/**
  * @brief LPTIM Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CFG;                 /*!<LPTIM Configuration rRegister                  offset: 0x00*/
    __IO uint32_t IE;                  /*!<LPTIM Interrupt Enable Register                offset: 0x04*/
    __IO uint32_t IF;                  /*!<LPTIM Interrupt Flag Register                  offset: 0x08*/
    __IO uint32_t CTRL;                /*!<LPTIM Control Register                         offset: 0x0C*/
    __IO uint32_t CNT;                 /*!<LPTIM Count Register                           offset: 0x10*/
    __IO uint32_t CMP;                 /*!<LPTIM Compare Value Register                   offset: 0x14*/
    __IO uint32_t TARGET;              /*!<LPTIM Target Value Register                    offset: 0x18*/
} LPTIM_TypeDef;

/**
  * @brief LPTIM type pointer Definition
  */
#define LPTIM                                     ((LPTIM_TypeDef *)LPTIM_BASE)

/**
  * @brief LPTIM_CFG Register Bit Definition
  */
#define  LPTIM_CFG_MODE_Pos                       (0)
#define  LPTIM_CFG_MODE_Msk                       (0x01U << LPTIM_CFG_MODE_Pos)     /*!<*/
#define  LPTIM_CFG_TMODE_Pos                      (1)
#define  LPTIM_CFG_TMODE_Msk                      (0x03U << LPTIM_CFG_TMODE_Pos)    /*!<*/
#define  LPTIM_CFG_PWM_Pos                        (3)
#define  LPTIM_CFG_PWM_Msk                        (0x01U << LPTIM_CFG_PWM_Pos)      /*!<*/
#define  LPTIM_CFG_POLARITY_Pos                   (4)
#define  LPTIM_CFG_POLARITY_Msk                   (0x01U << LPTIM_CFG_POLARITY_Pos) /*!<*/
#define  LPTIM_CFG_TRIGSEL_Pos                    (5)
#define  LPTIM_CFG_TRIGSEL_Msk                    (0x01U << LPTIM_CFG_TRIGSEL_Pos)  /*!<*/
#define  LPTIM_CFG_TRIGCFG_Pos                    (6)
#define  LPTIM_CFG_TRIGCFG_Msk                    (0x03U << LPTIM_CFG_TRIGCFG_Pos)  /*!<*/
#define  LPTIM_CFG_DIVSEL_Pos                     (8)
#define  LPTIM_CFG_DIVSEL_Msk                     (0x07U << LPTIM_CFG_DIVSEL_Pos)   /*!<*/
#define  LPTIM_CFG_FLTEN_Pos                      (15)
#define  LPTIM_CFG_FLTEN_Msk                      (0x01U << LPTIM_CFG_FLTEN_Pos)    /*!<*/

/**
  * @brief LPTIM_IE Register Bit Definition
  */
#define  LPTIM_IE_OVIE_Pos                        (0)
#define  LPTIM_IE_OVIE_Msk                        (0x01U << LPTIM_IE_OVIE_Pos)   /*!<*/
#define  LPTIM_IE_TRIGIE_Pos                      (1)
#define  LPTIM_IE_TRIGIE_Msk                      (0x01U << LPTIM_IE_TRIGIE_Pos) /*!<*/
#define  LPTIM_IE_COMPIE_Pos                      (2)
#define  LPTIM_IE_COMPIE_Msk                      (0x01U << LPTIM_IE_COMPIE_Pos) /*!<*/

/**
  * @brief LPTIM_IF Register Bit Definition
  */
#define  LPTIM_IF_OVIF_Pos                        (0)
#define  LPTIM_IF_OVIF_Msk                        (0x01U << LPTIM_IF_OVIF_Pos)   /*!<*/
#define  LPTIM_IF_TRIGIF_Pos                      (1)
#define  LPTIM_IF_TRIGIF_Msk                      (0x01U << LPTIM_IF_TRIGIF_Pos) /*!<*/
#define  LPTIM_IF_COMPIF_Pos                      (2)
#define  LPTIM_IF_COMPIF_Msk                      (0x01U << LPTIM_IF_COMPIF_Pos) /*!<*/

/**
  * @brief LPTIM_CTRL Register Bit Definition
  */
#define  LPTIM_CTRL_LPTEN_Pos                     (0)
#define  LPTIM_CTRL_LPTEN_Msk                     (0x01U << LPTIM_CTRL_LPTEN_Pos) /*!<*/

/**
  * @brief LPTIM_CNT Register Bit Definition
  */
#define  LPTIM_CNT_CNT_Pos                        (0)
#define  LPTIM_CNT_CNT_Msk                        (0xFFFFU << LPTIM_CNT_CNT_Pos) /*!<*/

/**
  * @brief LPTIM_CMP Register Bit Definition
  */
#define  LPTIM_CMP_COMPARE_REG_Pos                (0)
#define  LPTIM_CMP_COMPARE_REG_Msk                (0xFFFFU << LPTIM_CMP_COMPARE_REG_Pos) /*!<*/

/**
  * @brief LPTIM_TARGET Register Bit Definition
  */
#define  LPTIM_TARGET_TARGET_REG_Pos              (0)
#define  LPTIM_TARGET_TARGET_REG_Msk              (0xFFFFU << LPTIM_TARGET_TARGET_REG_Pos) /*!<*/

#endif

