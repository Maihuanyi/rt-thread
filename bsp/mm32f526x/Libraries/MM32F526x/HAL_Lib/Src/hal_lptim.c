/***********************************************************************************************************************
    @file     hal_lptim.c
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
#define _HAL_LPTIM_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_lptim.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup LPTIM_HAL
  * @{
  */

/** @addtogroup LPTIM_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the lptim peripheral registers to their default reset values.
  * @param  lptim:  select the LPTIM peripheral.
  * @retval None.
  */
void LPTIM_DeInit(LPTIM_TypeDef *lptim)
{
    if (lptim == LPTIM)
    {
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_LPTIM, ENABLE);
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_LPTIM, DISABLE);
    }
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct : pointer to a LPTIM_TimeBaseInit_TypeDef
  *         structure which will be initialized.
  * @retval None.
  */
void LPTIM_TimeBaseStructInit(LPTIM_TimeBaseInit_TypeDef *init_struct)
{
    init_struct->ClockSource            = LPTIM_CLK_PCLK;
    init_struct->CountMode              = LPTIM_CNT_Continuous;
    init_struct->WorkMode               = LPTIM_MODE_NormalWave;
    init_struct->Waveform               = LPTIM_Waveform_CycleSquare;
    init_struct->Polarity               = LPTIM_Positive_Wave;
    init_struct->ClockDivision          = LPTIM_CLK_Div1;
}

/**
  * @brief  Initializes the lptim Time Base Unit peripheral according to
  *         the specified parameters in the init_struct.
  * @param  lptim: select the LPTIM peripheral.
  * @param  init_struct: pointer to a LPTIM_TimeBaseInit_TypeDef
  *         structure that contains the configuration information for the
  *         specified LPTIM peripheral.
  *         ClockSource: Specifies the clock source of the LPTIM.
  *         CountMode:Specifies the Count mode
  *         WorkMode:Specifies the Output Mode
  *         Waveform:Specifies the PWM wave form.
  *         Polarity:Specifies the Output Polarity
  *         ClockDivision:Specifies the clock divide.
  * @retval None.
  */
void LPTIM_TimeBaseInit(LPTIM_TypeDef *lptim, LPTIM_TimeBaseInit_TypeDef *init_struct)
{
    MODIFY_REG(RCC->CFGR2, RCC_CFGR2_LPTIMCLKSEL_Msk, init_struct->ClockSource);
    MODIFY_REG(lptim->CFG, (LPTIM_CFG_MODE_Msk |
                            LPTIM_CFG_TMODE_Msk |
                            LPTIM_CFG_PWM_Msk |
                            LPTIM_CFG_POLARITY_Msk |
                            LPTIM_CFG_DIVSEL_Msk), (init_struct->CountMode |
                                                    init_struct->WorkMode |
                                                    init_struct->Waveform |
                                                    init_struct->Polarity |
                                                    init_struct->ClockDivision));
}

/**
  * @brief  Enables or disables the specified LPTIM peripheral.
  * @param  lptim: select the lptim peripheral.
  * @param  state: new state of the lptim peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPTIM_Cmd(LPTIM_TypeDef *lptim, FunctionalState state)
{
    (state) ?                                          \
    (lptim->CTRL |= (0x01U << LPTIM_CTRL_LPTEN_Pos)) : \
    (lptim->CTRL &= ~(0x01U << LPTIM_CTRL_LPTEN_Pos));
}

/**
  * @brief  Configures the specified LPTIM trigger source .
  * @param  lptim:  select the lptim peripheral.
  * @param  trig_source: Configuring the external trigger source
  *     @arg    LPTIM_Trig_ExternalPIN
  *     @arg    LPTIM_Trig_ComparerOut
  * @param  trig_edge:
  *     @arg   LPTIM_TrigEdge_UpEdge
  *     @arg   LPTIM_TrigEdge_DownEdge
  *     @arg   LPTIM_TrigEdge_UpDownEdge
  * @retval None.
  */
void LPTIM_ExternalTrigSourceConfig(LPTIM_TypeDef *lptim, uint32_t trig_source, uint32_t trig_edge)
{
    MODIFY_REG(lptim->CFG, LPTIM_CFG_TRIGSEL_Msk, trig_source);
    MODIFY_REG(lptim->CFG, LPTIM_CFG_TRIGCFG_Msk, trig_edge);
}

/**
  * @brief  Sets the lptim Clock Division value.
  * @param  lptim:  select the LPTIM peripheral.
  * @param  clock_div: specifies the clock division value.
  *   This parameter can be one of the following value:
  *     @arg LPTIM_CLK_Div1
  *     @arg LPTIM_CLK_Div2
  *     @arg LPTIM_CLK_Div4
  *     @arg LPTIM_CLK_Div8
  *     @arg LPTIM_CLK_Div16
  *     @arg LPTIM_CLK_Div32
  *     @arg LPTIM_CLK_Div64
  *     @arg LPTIM_CLK_Div128
  * @retval None.
  */
void LPTIM_SetClockDivision(LPTIM_TypeDef *lptim, uint32_t clock_div)
{
    MODIFY_REG(lptim->CFG, LPTIM_CFG_DIVSEL_Msk, clock_div);
}

/**
  * @brief  Enables or disables the specified LPTIM input filter function.
  * @param  lptim:  select the lptim peripheral.
  * @param  state: new state of the LPTIM input filter mode.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPTIM_InputFilterCmd(LPTIM_TypeDef *lptim, FunctionalState state)
{
    (state) ?                                        \
    (lptim->CFG |= (0x01U << LPTIM_CFG_FLTEN_Pos)) : \
    (lptim->CFG &= ~(0x01U << LPTIM_CFG_FLTEN_Pos));
}

/**
  * @brief  Sets the lptim Counter Register value
  * @param  lptim:  select the LPTIM peripheral.
  * @param  counter: specifies the Counter register new value.
  * @retval None.
  */
void LPTIM_SetCounter(LPTIM_TypeDef *lptim, uint16_t counter)
{
    lptim->CNT = (uint32_t)counter;
}

/**
  * @brief  Gets the lptim Counter value.
  * @param  lptim:  select the LPTIM peripheral.
  * @retval Value: Counter Register value.
  */
uint32_t LPTIM_GetCounter(LPTIM_TypeDef *lptim)
{
    return (lptim->CNT);
}

/**
  * @brief  Sets the lptim Compare Register value
  * @param  lptim:  select the LPTIM peripheral.
  * @param  value: specifies the Compare register new value.
  * @retval None.
  */
void LPTIM_SetCompare(LPTIM_TypeDef *lptim, uint16_t value)
{
    lptim->CMP = (uint32_t)value;
}

/**
  * @brief  Gets the lptim Compare value.
  * @param  lptim:  select the LPTIM peripheral.
  * @retval Value: Compare Register value.
  */
uint16_t LPTIM_GetCompare(LPTIM_TypeDef *lptim)
{
    return ((uint16_t)lptim->CMP);
}

/**
  * @brief  Sets the lptim target Register value
  * @param  lptim:  select the LPTIM peripheral.
  * @param  target: specifies the target register new value.
  * @retval None.
  */
void LPTIM_SetTarget(LPTIM_TypeDef *lptim, uint16_t target)
{
    lptim->TARGET = (uint32_t)target;
}

/**
  * @brief  Gets the lptim target value.
  * @param  lptim:  select the LPTIM peripheral.
  * @retval Value: target Register value.
  */
uint16_t LPTIM_GetTarget(LPTIM_TypeDef *lptim)
{
    return ((uint16_t)lptim->TARGET);
}

/**
  * @brief  Enables or disables the specified LPTIM interrupts.
  * @param  lptim:  select the lptim peripheral.
  * @param  it: specifies the LPTIM interrupts sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  *     @arg LPTIM_IT_COMPIE: LPTIM COMPARE Interrupt Enable Bit
  *     @arg LPTIM_IT_TRIGIE: LPTIM Ext Trig Interrupt Enable Bit
  *     @arg LPTIM_IT_OVIE  : LPTIM Overflow Interrupt Enable Bit
  * @param  state: new state of the LPTIM interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPTIM_ITConfig(LPTIM_TypeDef *lptim, uint32_t it, FunctionalState state)
{
    (state) ?           \
    (lptim->IE |= it) : \
    (lptim->IE &= ~it);
}

/**
  * @brief  Checks whether the LPTIM interrupt has occurred or not.
  * @param  lptim:  select the LPTIM peripheral.
  * @param  it: specifies the LPTIM interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg LPTIM_IT_COMPIE: LPTIM Compare Interrupt Flag
  *     @arg LPTIM_IT_TRIGIE: LPTIM Trig Interrupt Flag
  *     @arg LPTIM_IT_OVIE  : LPTIM Counter Overflow Interrupt Flag
  * @retval State: The new state of the LPTIM_IT(SET or RESET).
  */
ITStatus LPTIM_GetITStatus(LPTIM_TypeDef *lptim, uint32_t it)
{
    return ((lptim->IF & it) ? SET : RESET);
}

/**
  * @brief  Clears the lptim's interrupt pending bits, write 1 to clear bit.
  * @param  lptim:  select the LPTIM peripheral.
  * @param  it: specifies the pending bit to clear by write 1 to clear.
  *   This parameter can be any combination of the following values:
  *     @arg LPTIM_IT_COMPIE: LPTIM Compare Interrupt Flag
  *     @arg LPTIM_IT_TRIGIE: LPTIM Trig Interrupt Flag
  *     @arg LPTIM_IT_OVIE  : LPTIM Counter Overflow Interrupt Flag
  * @retval None.
  */
void LPTIM_ClearITPendingBit(LPTIM_TypeDef *lptim, uint32_t it)
{
    lptim->IF = it;
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

