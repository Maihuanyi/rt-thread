/***********************************************************************************************************************
    @file     reg_iwdg.h
    @author   VV TEAM
    @brief    This flie contains all the IWDG's register and its field definition.
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

#ifndef __REG_IWDG_H
#define __REG_IWDG_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief IWDG Base Address Definition
  */
#define  IWDG_BASE                                 0x40003000 /*!<Base Address: 0x40003000*/

/**
  * @brief IWDG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t KR;                  /*!<IWDG Key register                              offset: 0x00*/
    __IO uint32_t PR;                  /*!<IWDG Prescaler register                        offset: 0x04*/
    __IO uint32_t RLR;                 /*!<IWDG Reload register                           offset: 0x08*/
    __IO uint32_t SR;                  /*!<IWDG Status register                           offset: 0x0C*/
    __IO uint32_t CR;                  /*!<IWDG Control register                          offset: 0x10*/
    __IO uint32_t IGEN;                /*!<IWDG Interrupt generate register               offset: 0x14*/
    __IO uint32_t CNT;                 /*!<IWDG Counter register                          offset: 0x18*/
    __IO uint32_t PS;                  /*!<IWDG Prescaler counter register                offset: 0x1C*/
} IWDG_TypeDef;

/**
  * @brief IWDG type pointer Definition
  */
#define IWDG                                      ((IWDG_TypeDef *)IWDG_BASE)

/**
  * @brief IWDG_KR Register Bit Definition
  */
#define  IWDG_KR_KEY_Pos                          (0)
#define  IWDG_KR_KEY_Msk                          (0xFFFFU << IWDG_KR_KEY_Pos) /*!<*/

/**
  * @brief IWDG_PR Register Bit Definition
  */
#define  IWDG_PR_PR_Pos                           (0)
#define  IWDG_PR_PR_Msk                           (0x07U << IWDG_PR_PR_Pos) /*!<*/

/**
  * @brief IWDG_RLR Register Bit Definition
  */
#define  IWDG_RLR_RL_Pos                          (0)
#define  IWDG_RLR_RL_Msk                          (0x0FFFU << IWDG_RLR_RL_Pos) /*!<*/

/**
  * @brief IWDG_SR Register Bit Definition
  */
#define  IWDG_SR_PVU_Pos                          (0)
#define  IWDG_SR_PVU_Msk                          (0x01U << IWDG_SR_PVU_Pos)    /*!<*/
#define  IWDG_SR_RVU_Pos                          (1)
#define  IWDG_SR_RVU_Msk                          (0x01U << IWDG_SR_RVU_Pos)    /*!<*/
#define  IWDG_SR_IVU_Pos                          (2)
#define  IWDG_SR_IVU_Msk                          (0x01U << IWDG_SR_IVU_Pos)    /*!<*/
#define  IWDG_SR_UPDATE_Pos                       (3)
#define  IWDG_SR_UPDATE_Msk                       (0x01U << IWDG_SR_UPDATE_Pos) /*!<*/

/**
  * @brief IWDG_CR Register Bit Definition
  */
#define  IWDG_CR_IRQ_SEL_Pos                      (0)
#define  IWDG_CR_IRQ_SEL_Msk                      (0x01U << IWDG_CR_IRQ_SEL_Pos) /*!<*/
#define  IWDG_CR_IRQ_CLR_Pos                      (1)
#define  IWDG_CR_IRQ_CLR_Msk                      (0x01U << IWDG_CR_IRQ_CLR_Pos) /*!<*/

/**
  * @brief IWDG_IGEN Register Bit Definition
  */
#define  IWDG_IGEN_IGEN_Pos                       (0)
#define  IWDG_IGEN_IGEN_Msk                       (0x0FFFU << IWDG_IGEN_IGEN_Pos) /*!<*/

/**
  * @brief IWDG_CNT Register Bit Definition
  */
#define  IWDG_CNT_IWDG_CNT_Pos                    (0)
#define  IWDG_CNT_IWDG_CNT_Msk                    (0x0FFFU << IWDG_CNT_IWDG_CNT_Pos) /*!<*/

/**
  * @brief IWDG_PS Register Bit Definition
  */
#define  IWDG_PS_IWDG_PS_Pos                      (0)
#define  IWDG_PS_IWDG_PS_Msk                      (0xFFU << IWDG_PS_IWDG_PS_Pos) /*!<*/

#endif

