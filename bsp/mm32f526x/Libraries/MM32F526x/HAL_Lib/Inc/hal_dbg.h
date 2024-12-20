/***********************************************************************************************************************
    @file     hal_dbg.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE DBG
              FIRMWARE LIBRARY.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HAL_DBG_H
#define __HAL_DBG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup DBG_HAL
  * @brief DBG HAL modules
  * @{
  */

/** @defgroup DBG_Exported_Types
  * @{
  */

/**
  * @brief DBG_CR Register Bit Definition
  */
#define DBG_STOP_FOR_LDO          (0x01U << DBG_CR_DBG_STOP_FOR_LDO_Pos) /*!< Debug stop mode LDO status */
#define DBG_TRACE_IOE             (0x01U << DBG_CR_TRACE_IOE_Pos)        /*!< Debug Trace pin */
#define DBG_IWDG_STOP             (0x01U << DBG_CR_DBG_IWDG_STOP_Pos)    /*!< Debug independent watchdog stopped when core is halted */
#define DBG_WWDG_STOP             (0x01U << DBG_CR_DBG_WWDG_STOP_Pos)    /*!< Debug window watchdog stopped when core is halted */
#define DBG_TIM1_STOP             (0x01U << DBG_CR_DBG_TIM1_STOP_Pos)    /*!< TIM1 stops work when the core enters the debug mode */
#define DBG_TIM2_STOP             (0x01U << DBG_CR_DBG_TIM2_STOP_Pos)    /*!< TIM2 stops work when the core enters the debug mode */
#define DBG_TIM3_STOP             (0x01U << DBG_CR_DBG_TIM3_STOP_Pos)    /*!< TIM3 stops work when the core enters the debug mode */
#define DBG_TIM4_STOP             (0x01U << DBG_CR_DBG_TIM4_STOP_Pos)    /*!< TIM4 stops work when the core enters the debug mode */
#define DBG_TIM8_STOP             (0x01U << DBG_CR_DBG_TIM8_STOP_Pos)    /*!< TIM8 stops work when the core enters the debug mode */
#define DBG_TIM5_STOP             (0x01U << DBG_CR_DBG_TIM5_STOP_Pos)    /*!< TIM5 stops work when the core enters the debug mode */
#define DBG_TIM6_STOP             (0x01U << DBG_CR_DBG_TIM6_STOP_Pos)    /*!< TIM6 stops work when the core enters the debug mode */
#define DBG_TIM7_STOP             (0x01U << DBG_CR_DBG_TIM7_STOP_Pos)    /*!< TIM7 stops work when the core enters the debug mode */

/** @defgroup DBG_Exported_Functions
  * @{
  */
void DBG_Configure(uint32_t periph, FunctionalState state);
uint32_t DBG_GetDeviceIDCode(void);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

/** --------------------------------------------------------------------------*/
#endif /* __HAL_DBG_H --------------------------------------------------------*/
/** --------------------------------------------------------------------------*/

