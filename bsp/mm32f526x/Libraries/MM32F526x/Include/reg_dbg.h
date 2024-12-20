/***********************************************************************************************************************
    @file     reg_dbg.h
    @author   VV TEAM
    @brief    This flie contains all the DBG's register and its field definition.
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

#ifndef __REG_DBG_H
#define __REG_DBG_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief DBG Base Address Definition
  */
#define  DBG_BASE                                  0x40007080 /*!<Base Address: 0x40007080*/

/**
  * @brief DBG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t IDCODE;              /*!<DBG DBG ID encode register                     offset: 0x00*/
    __IO uint32_t CR;                  /*!<DBG DBG control register                       offset: 0x04*/
} DBG_TypeDef;

/**
  * @brief DBG type pointer Definition
  */
#define DBG                                       ((DBG_TypeDef *)DBG_BASE)

/**
  * @brief DBG_IDCODE Register Bit Definition
  */
#define  DBG_IDCODE_DEV_ID_Pos                    (0)
#define  DBG_IDCODE_DEV_ID_Msk                    (0xFFFFFFFFU << DBG_IDCODE_DEV_ID_Pos) /*!<*/

/**
  * @brief DBG_CR Register Bit Definition
  */
#define  DBG_CR_DBG_STOP_FOR_LDO_Pos              (3)
#define  DBG_CR_DBG_STOP_FOR_LDO_Msk              (0x01U << DBG_CR_DBG_STOP_FOR_LDO_Pos) /*!<*/
#define  DBG_CR_TRACE_IOE_Pos                     (5)
#define  DBG_CR_TRACE_IOE_Msk                     (0x01U << DBG_CR_TRACE_IOE_Pos)        /*!<*/
#define  DBG_CR_TRACE_MODE_Pos                    (6)
#define  DBG_CR_TRACE_MODE_Msk                    (0x03U << DBG_CR_TRACE_MODE_Pos)       /*!<*/
#define  DBG_CR_DBG_IWDG_STOP_Pos                 (8)
#define  DBG_CR_DBG_IWDG_STOP_Msk                 (0x01U << DBG_CR_DBG_IWDG_STOP_Pos)    /*!<*/
#define  DBG_CR_DBG_WWDG_STOP_Pos                 (9)
#define  DBG_CR_DBG_WWDG_STOP_Msk                 (0x01U << DBG_CR_DBG_WWDG_STOP_Pos)    /*!<*/
#define  DBG_CR_DBG_TIM1_STOP_Pos                 (10)
#define  DBG_CR_DBG_TIM1_STOP_Msk                 (0x01U << DBG_CR_DBG_TIM1_STOP_Pos)    /*!<*/
#define  DBG_CR_DBG_TIM2_STOP_Pos                 (11)
#define  DBG_CR_DBG_TIM2_STOP_Msk                 (0x01U << DBG_CR_DBG_TIM2_STOP_Pos)    /*!<*/
#define  DBG_CR_DBG_TIM3_STOP_Pos                 (12)
#define  DBG_CR_DBG_TIM3_STOP_Msk                 (0x01U << DBG_CR_DBG_TIM3_STOP_Pos)    /*!<*/
#define  DBG_CR_DBG_TIM4_STOP_Pos                 (13)
#define  DBG_CR_DBG_TIM4_STOP_Msk                 (0x01U << DBG_CR_DBG_TIM4_STOP_Pos)    /*!<*/
#define  DBG_CR_DBG_TIM8_STOP_Pos                 (17)
#define  DBG_CR_DBG_TIM8_STOP_Msk                 (0x01U << DBG_CR_DBG_TIM8_STOP_Pos)    /*!<*/
#define  DBG_CR_DBG_TIM5_STOP_Pos                 (18)
#define  DBG_CR_DBG_TIM5_STOP_Msk                 (0x01U << DBG_CR_DBG_TIM5_STOP_Pos)    /*!<*/
#define  DBG_CR_DBG_TIM6_STOP_Pos                 (19)
#define  DBG_CR_DBG_TIM6_STOP_Msk                 (0x01U << DBG_CR_DBG_TIM6_STOP_Pos)    /*!<*/
#define  DBG_CR_DBG_TIM7_STOP_Pos                 (20)
#define  DBG_CR_DBG_TIM7_STOP_Msk                 (0x01U << DBG_CR_DBG_TIM7_STOP_Pos)    /*!<*/

#endif

