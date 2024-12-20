/***********************************************************************************************************************
    @file     hal_dac.c
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
#define _HAL_DAC_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_dac.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup DAC_HAL
  * @{
  */

/** @addtogroup DAC_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the DAC peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */
void DAC_DeInit(void)
{
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_DAC, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_DAC, DISABLE);
}

/**
  * @brief  Initializes the DAC peripheral according to the specified parameters in the DAC_InitStruct.
  * @param  channel: the selected DAC channel.
  *         This parameter can be one of the following values:
  * @arg    DAC_Channel_1
  * @param  DAC_InitStruct: pointer to a DAC_InitTypeDef structure that contains the configuration information for the specified
  * DAC channel.
  * @retval None.
  */
void DAC_Init(uint8_t channel, DAC_InitTypeDef *init_struct)
{
    MODIFY_REG(DAC->CR,
               ((DAC_CR_BOFF1_Msk |  DAC_CR_WAVE1_Msk | DAC_CR_MAMP1_Msk) << channel), 
               (((uint32_t)(init_struct->DAC_WaveGeneration)               | \
                 (uint32_t)(init_struct->DAC_LFSRUnmask_TriangleAmplitude) | \
                 (uint32_t)(init_struct->DAC_OutputBuffer)) << channel));
}

/**
  * @brief  Fills each DAC_InitStruct member with its default value.
  * @param  DAC_InitStruct : pointer to a DAC_InitTypeDef structure which will be initialized.
  * @retval None.
  */
void DAC_StructInit(DAC_InitTypeDef *init_struct)
{
    init_struct->DAC_WaveGeneration               = DAC_WaveGeneration_None;
    init_struct->DAC_LFSRUnmask_TriangleAmplitude = DAC_TriangleAmplitude_1;
    init_struct->DAC_OutputBuffer                 = DAC_OutputBuffer_Enable;
}

/**
  * @brief  Enables or disables the specified DAC channel.
  * @param  channel: the selected DAC channel.
  *         This parameter can be one of the following values:
  * @arg    DAC_Channel_1
  * @param  state: new state of the DAC channel.
  * @retval None.
  */
void DAC_Cmd(uint8_t channel, FunctionalState state)
{
    (state) ?                                             \
    (DAC->CR |= ((0x01U << DAC_CR_EN1_Pos) << channel)) : \
    (DAC->CR &= ~((0x01U << DAC_CR_EN1_Pos) << channel));
}

/**
  * @brief  Enables or disables the specified DAC channel DMA request.
  * @param  channel: the selected DAC channel.
  *         This parameter can be one of the following values:
  * @arg    DAC_Channel_1
  * @param  state: new state of the selected DAC channel DMA request.
  * @retval None.
  */
void DAC_DMACmd(uint8_t channel, FunctionalState state)
{
    (state) ?                                                 \
    (DAC->CR |= ((0x01U << DAC_CR_DMA_EN1_Pos) << channel)) : \
    (DAC->CR &= ~((0x01U << DAC_CR_DMA_EN1_Pos) << channel));
}

/**
  * @brief  Enables or disables the specified DAC channel output.
  * @param  channel: the selected DAC channel.
  *         This parameter can be one of the following values:
  * @arg    DAC_Channel_1
  * @param  state: new state of the DAC channel.
  * @retval None.
  */
void DAC_OutputCmd(uint8_t channel, FunctionalState state)
{
    (state) ?                                                \
    (DAC->CR |= ((0x01U << DAC_CR_OE_EN1_Pos) << channel)) : \
    (DAC->CR &= ~((0x01U << DAC_CR_OE_EN1_Pos) << channel));
}

/**
  * @brief  Enables or disables the dac conversion through external trigger.
  * @param  channel: the selected DAC channel.
  *         This parameter can be one of the following values:
  * @arg    DAC_Channel_1
  * @param  state: New state of the selected DAC external trigger.
  * @retval None.
  */
void DAC_ExternalTrigConvCmd(uint8_t channel, FunctionalState state)
{
    (state) ?                                              \
    (DAC->CR |= ((0x01U << DAC_CR_TEN1_Pos) << channel)) : \
    (DAC->CR &= ~((0x01U << DAC_CR_TEN1_Pos) << channel));
}

/**
  * @brief  Enables or disables the selected DAC channel software trigger.
  *         This parameter can be one of the following values:
  * @arg    DAC_Channel_1
  * @param  state: new state of the selected DAC channel software trigger.
  * @retval None.
  */
void DAC_SoftwareTriggerCmd(uint8_t channel, FunctionalState state)
{
    (state) ?                                                                   \
    (DAC->SWTRIGR |= ((0x01U << DAC_SWTRIGR_SW_TRIG1_Pos) << (channel >> 4))) : \
    (DAC->SWTRIGR &= ~((0x01U << DAC_SWTRIGR_SW_TRIG1_Pos) << (channel >> 4)));
}

/**
  * @brief  Enables or disables the selected DAC channel wave generation.
  * @param  channel: the selected DAC channel.
  *         This parameter can be one of the following values:
  * @arg    DAC_Channel_1
  * @param  wave: Specifies the wave type to enable or disable.
  *         This parameter can be one of the following values:
  * @arg    DAC_WaveGeneration_None
  * @arg    DAC_WaveGeneration_Noise
  * @arg    DAC_WaveGeneration_Triangle
  * @param  state: new state of the selected DAC channel wave generation.
  * @retval None.
  */
void DAC_WaveGenerationCmd(uint8_t channel, uint32_t wave, FunctionalState state)
{
    (state) ?                        \
    (DAC->CR |= (wave << channel)) : \
    (DAC->CR &= ~(wave << channel));
}

/**
  * @brief  Set the specified data holding register value for DAC channel1.
  * @param  alignement: Specifies the data alignement for DAC channel1.
  *         This parameter can be one of the following values:
  * @arg    DAC_Align_12b_R
  * @arg    DAC_Align_12b_L
  * @arg    DAC_Align_8b_R
  * @param  data: Specifies the alignment of Channel1 data.
  * @retval None.
  */
void DAC_SetChannel1Data(uint8_t alignement, uint16_t data)
{
    if (alignement == DAC_Align_12b_R)
    {
        DAC->DHR12R1 = (uint32_t)data;
    }
    else if (alignement == DAC_Align_12b_L)
    {
        DAC->DHR12L1 = (uint32_t)(data << 4);
    }
    else
    {
        DAC->DHR8R1 = (uint32_t)data;
    }
}

/**
  * @brief  Returns the last data output value of the selected DAC cahnnel.
  * @param  channel: the selected DAC channel.
  * @retval The selected DAC channel data output value.
  *         This parameter can be one of the following values:
  * @arg    DAC_Channel_1
  * @retval Output data of the DAC channel.
  */
uint16_t DAC_GetDataOutputValue(uint8_t channel)
{
    uint32_t value = 0;

    if (channel == DAC_Channel_1)
    {
        value = DAC->DOR1;
    }

    return ((uint16_t)value);
}

/**
  * @brief  Enables or disables simultaneously the two DAC channels software triggers.
  * @param  state: new state of the DAC channels software triggers.
  * @retval None.
  */
void DAC_DualSoftwareTriggerCmd(FunctionalState state)
{
    (state) ?                                                                 \
    (DAC->SWTRIGR |= (DAC_SWTRIGR_SW_TRIG1_Msk | DAC_SWTRIGR_SW_TRIG2_Msk)) : \
    (DAC->SWTRIGR &= ~(DAC_SWTRIGR_SW_TRIG1_Msk | DAC_SWTRIGR_SW_TRIG2_Msk));
}

/**
  * @brief  Set the specified data holding register value for DAC channel2.
  * @param  alignement: Specifies the data alignement for DAC channel1.
  *         This parameter can be one of the following values:
  * @arg    DAC_Align_12b_R
  * @arg    DAC_Align_12b_L
  * @arg    DAC_Align_8b_R
  * @param  data: Specifies the alignment of Channel2 data.
  * @retval None.
  */
void DAC_SetChannel2Data(uint8_t alignement, uint16_t data)
{
    if (alignement == DAC_Align_12b_R)
    {
        DAC->DHR12R2 = (uint32_t)data;
    }
    else if (alignement == DAC_Align_12b_L)
    {
        DAC->DHR12L2 = (uint32_t)(data << 4);
    }
    else
    {
        DAC->DHR8R2 = (uint32_t)data;
    }
}

/**
  * @brief  Set the specified data holding register value for dual channel DAC.
  * @param  alignement: Specifies the data alignement for DAC channel1.
  *         This parameter can be one of the following values:
  * @arg    DAC_Align_12b_R
  * @arg    DAC_Align_12b_L
  * @arg    DAC_Align_8b_R
  * @param  data1: Specifies the alignment of Channel1 data.
  * @param  data2: Specifies the alignment of Channel2 data.
  * @retval None.
  */
void DAC_SetDualChannelData(uint8_t alignement, u16 data1, u16 data2)
{
    if (alignement == DAC_Align_12b_R)
    {
        DAC->DHR12RD = (uint32_t)(data1 | (data2 << 16));
    }
    else if (alignement == DAC_Align_12b_L)
    {
        DAC->DHR12LD = (uint32_t)((data1 << 4) | (data2 << 20));
    }
    else
    {
        DAC->DHR8RD = (uint32_t)(data1 | (data2 << 8));
    }
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

