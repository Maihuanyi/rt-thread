/***********************************************************************************************************************
    @file     hal_wwdg.c
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
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
#define _HAL_WWDG_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_wwdg.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup WWDG_HAL
  * @{
  */

/** @addtogroup WWDG_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the WWDG peripheral registers to their default reset
  * values.
  * @param  None.
  * @retval None.
  */
void WWDG_DeInit(void)
{
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_WWDG, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_WWDG, DISABLE);
}

/**
  * @brief  Sets the WWDG Prescaler.
  * @param  prescaler: specifies the WWDG Prescaler.
  *         This parameter can be one of the following values:
  * @arg    WWDG_Prescaler_1: WWDG counter clock = APB1CLK / 4096 / 1
  * @arg    WWDG_Prescaler_2: WWDG counter clock = APB1CLK / 4096 / 2
  * @arg    WWDG_Prescaler_4: WWDG counter clock = APB1CLK / 4096 / 4
  * @arg    WWDG_Prescaler_8: WWDG counter clock = APB1CLK / 4096 / 8
  * @retval None.
  */
void WWDG_SetPrescaler(uint32_t prescaler)
{
    MODIFY_REG(WWDG->CFGR, WWDG_CFGR_WDGTB_Msk, prescaler);
}

/**
  * @brief  Sets the WWDG window value.
  * @param  window_value: specifies the window value to be compared to the downcounter.
  *         This parameter value must be lower than 0x80.
  * @retval None.
  */
void WWDG_SetWindowValue(uint8_t window_value)
{
    MODIFY_REG(WWDG->CFGR, WWDG_CFGR_W_Msk, window_value << WWDG_CFGR_W_Pos);
}

/**
  * @brief  Enables the WWDG Early Wakeup interrupt(EWI).
  * @note   Once enabled this interrupt cannot be disabled except by a system
  * reset.
  * @param  None.
  * @retval None.
  */
void WWDG_EnableIT(void)
{
    WWDG->CFGR |= (0x01U << WWDG_CFGR_EWI_Pos);
}

/**
  * @brief  Sets the WWDG counter value.
  * @param  Counter: specifies the watchdog counter value.
  *         This parameter must be a number between 0x40 and 0x7F (to prevent
  *         generating an immediate reset).
  * @retval None.
  */
void WWDG_SetCounter(uint8_t count)
{
    WWDG->CR = count & WWDG_CR_T_Msk;
}

/**
  * @brief  Gets the WWDG counter value.
  * @param  None.
  * @retval The WWDG counter value.
  */
uint32_t WWDG_GetCounter(void)
{
    return (WWDG->CR & WWDG_CR_T_Msk);
}

/**
  * @brief  Enables WWDG and load the counter value.
  * @param  count: specifies the watchdog counter value.
  *         This parameter must be a number between 0x40 and 0x7F (to prevent
  *         generating an immediate reset).
  * @retval None.
  */
void WWDG_Enable(uint8_t count)
{
    WWDG->CR = ((0x01U << WWDG_CR_WDGA_Pos) | count);
}

/**
  * @brief  Checks whether the Early Wakeup interrupt flag is set or not.
  * @param  None.
  * @retval The new state of the Early Wakeup interrupt flag (SET or RESET).
  */
FlagStatus WWDG_GetFlagStatus(void)
{
    return (WWDG->SR ? SET : RESET);
}

/**
  * @brief  Clears Early Wakeup interrupt flag.
  * @param  None.
  * @retval None.
  */
void WWDG_ClearFlag(void)
{
    WWDG->SR = ~(0x01U << WWDG_SR_EWIF_Pos);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

