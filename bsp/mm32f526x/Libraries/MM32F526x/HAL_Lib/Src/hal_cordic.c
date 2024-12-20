/***********************************************************************************************************************
    @file     hal_codic.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE CORDIC FIRMWARE FUNCTIONS.
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
#define _HAL_CORDIC_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_cordic.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup CORDIC_HAL
  * @{
  */

/** @addtogroup CORDIC_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the CORDIC module clock.
  * @param  None.
  * @retval None.
  */
void CORDIC_DeInit(void)
{
    RCC_AHBPeriphResetCmd(RCC_AHBPeriph_CORDIC, ENABLE);
    RCC_AHBPeriphResetCmd(RCC_AHBPeriph_CORDIC, DISABLE);
}

/**
  * @brief  Set the CORDIC CR Start bit to start Cordic.
  * @param  None.
  * @retval None.
  */
void CORDIC_Start(void)
{
    /* This register bit is valid when STARTMODE is set to 1. */
    /* At that time, it can be taken as one calculation when 1 is written and BSY bit is 0. */
    /* The hardware is auto cleared after completing the calculation. */
    CORDIC->CR |= (0x01U << CORDIC_CR_START_Pos);
}

/**
  * @brief  Configure the CORDIC work mode
  * @param  mode: Select CORDIC work mode.
  *         This parameter can be one of the following values:
  * @arg    CORDIC_WorkMode_Vector
  * @arg    CORDIC_WorkMode_Rotation
  * @retval None
  */
void CORDIC_SetWorkMode(uint32_t mode)
{
    MODIFY_REG(CORDIC->CR, CORDIC_CR_WORKMODE_Msk, mode);
}

/**
  * @brief  Configure the CORDIC start mode
  * @param  mode: Select CORDIC start mode.
  *         This parameter can be one of the following values:
  * @arg    CORDIC_StartMode_AfterDXWrite
  * @arg    CORDIC_StartMode_StartBitSet
  * @retval None
  */
void CORDIC_SetStartMode(uint32_t mode)
{
    MODIFY_REG(CORDIC->CR, CORDIC_CR_STARTMODE_Msk, mode);
}

/**
  * @brief  Enables or disables the CORDIC interface.
  * @param  state: new state of the CORDIC.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void CORDIC_Cmd(FunctionalState state)
{
    (state) ?                                         \
    (CORDIC->CR |= (0x01U << CORDIC_CR_ENABLE_Pos)) : \
    (CORDIC->CR &= ~(0x01U << CORDIC_CR_ENABLE_Pos));
}

/**
  * @brief  Checks whether the specified CORDIC busy flag is set or not.
  * @retval The new state of CORDIC_SR_BSY (SET or RESET).
  */
FlagStatus CORDIC_GetBusyStatus(void)
{
    return ((FlagStatus)(CORDIC->SR & CORDIC_SR_BSY_Msk));
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

