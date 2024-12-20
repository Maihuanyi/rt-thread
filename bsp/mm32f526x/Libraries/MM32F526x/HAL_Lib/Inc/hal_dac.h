/***********************************************************************************************************************
    @file     hal_dac.h
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
#ifndef __HAL_DAC_H
#define __HAL_DAC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup DAC_HAL
  * @brief DAC HAL modules
  * @{
  */

/** @defgroup DAC_Exported_Types
  * @{
  */

/**
  * @brief  DAC_Wave_Generation
  */
#define DAC_WaveGeneration_None         (0x00U << DAC_CR_WAVE1_Pos)
#define DAC_WaveGeneration_Noise        (0x01U << DAC_CR_WAVE1_Pos)
#define DAC_WaveGeneration_Triangle     (0x02U << DAC_CR_WAVE1_Pos)

/**
  * @brief  DAC_Mask_Amplitude
  */
#define DAC_TriangleAmplitude_1         (0x00U << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_3         (0x01U << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_7         (0x02U << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_15        (0x03U << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_31        (0x04U << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_63        (0x05U << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_127       (0x06U << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_255       (0x07U << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_511       (0x08U << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_1023      (0x09U << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_2047      (0x0AU << DAC_CR_MAMP1_Pos)
#define DAC_TriangleAmplitude_4095      (0x0BU << DAC_CR_MAMP1_Pos)

/**
  * @brief  DAC_Output_Buffer
  */
#define DAC_OutputBuffer_Enable         (0x00U << DAC_CR_BOFF1_Pos)
#define DAC_OutputBuffer_Disable        (0x01U << DAC_CR_BOFF1_Pos)

/**
  * @brief  channel
  */
#define DAC_Channel_1                   0x00 /*!< DAC Channel 1 */
#define DAC_Channel_2                   0x10 /*!< DAC Channel 2 */

/**
  * @brief  DAC_Data_Alignement
  */
#define DAC_Align_12b_R                 0x01
#define DAC_Align_12b_L                 0x02
#define DAC_Align_8b_R                  0x03

/**
  * @brief  DAC Init structure definition
  */
typedef struct
{
    uint32_t DAC_WaveGeneration;
    uint32_t DAC_LFSRUnmask_TriangleAmplitude;
    uint32_t DAC_OutputBuffer;
} DAC_InitTypeDef;

/**
  * @}
  */

/**
  * @defgroup DAC_Exported_Functions
  * @{
  */
void DAC_DeInit(void);
void DAC_Init(uint8_t channel, DAC_InitTypeDef *init_struct);
void DAC_StructInit(DAC_InitTypeDef *init_struct);
void DAC_Cmd(uint8_t channel, FunctionalState state);
void DAC_DMACmd(uint8_t channel, FunctionalState state);
void DAC_OutputCmd(uint8_t channel, FunctionalState state);
void DAC_ExternalTrigConvCmd(uint8_t channel, FunctionalState state);
void DAC_SoftwareTriggerCmd(uint8_t channel, FunctionalState state);
void DAC_WaveGenerationCmd(uint8_t channel, uint32_t wave, FunctionalState state);
void DAC_SetChannel1Data(uint8_t alignement, uint16_t data);
uint16_t DAC_GetDataOutputValue(uint8_t channel);

void DAC_DualSoftwareTriggerCmd(FunctionalState state);
void DAC_SetChannel2Data(uint8_t alignement, u16 data);
void DAC_SetDualChannelData(uint8_t alignement, u16 data2, u16 data1);
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

/*----------------------------------------------------------------------------*/
#endif /* __HAL_DAC_H ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

