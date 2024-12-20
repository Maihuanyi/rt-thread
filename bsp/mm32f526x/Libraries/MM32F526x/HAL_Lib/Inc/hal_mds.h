/***********************************************************************************************************************
    @file     hal_mds.h
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
#ifndef __HAL_MDS_H
#define __HAL_MDS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup MDS_HAL
  * @brief MDS HAL modules
  * @{
  */

/** @defgroup MDS_Exported_Types
  * @{
  */

/**
  * @brief MDS_CLUGROUP_INPUT_MAX
  */
#define MDS_CLUGROUP_INPUT_MAX                  4 /*!< The number of input channels per CLU unit */

/**
  * @brief MDS_TriggerSource_Sel
  */
#define MDS_TriggerSource_LOW_LEVEL             0
#define MDS_TriggerSource_HIGH_LEVEL            1
#define MDS_TriggerSource_SOFTWARE              2
#define MDS_TriggerSource_TIM1_CC1              3
#define MDS_TriggerSource_TIM1_CC2              4
#define MDS_TriggerSource_TIM1_CC3              5
#define MDS_TriggerSource_TIM1_CC4              6
#define MDS_TriggerSource_TIM1_CC5              7
#define MDS_TriggerSource_TIM2_CC1              8
#define MDS_TriggerSource_TIM2_CC2              9
#define MDS_TriggerSource_TIM2_CC3              10
#define MDS_TriggerSource_TIM2_CC4              11
#define MDS_TriggerSource_TIM3_CC1              12
#define MDS_TriggerSource_TIM3_CC2              13
#define MDS_TriggerSource_TIM3_CC3              14
#define MDS_TriggerSource_TIM3_CC4              15
#define MDS_TriggerSource_TIM4_CC1              16
#define MDS_TriggerSource_TIM4_CC2              17
#define MDS_TriggerSource_TIM4_CC3              18
#define MDS_TriggerSource_TIM4_CC4              19
#define MDS_TriggerSource_TIM5_CC1              20
#define MDS_TriggerSource_TIM5_CC2              21
#define MDS_TriggerSource_TIM5_CC3              22
#define MDS_TriggerSource_TIM5_CC4              23
#define MDS_TriggerSource_TIM8_CC1              24
#define MDS_TriggerSource_TIM8_CC2              25
#define MDS_TriggerSource_TIM8_CC3              26
#define MDS_TriggerSource_TIM8_CC4              27
#define MDS_TriggerSource_TIM8_CC5              28
#define MDS_TriggerSource_TIM1_TRGOUT           29
#define MDS_TriggerSource_TIM2_TRGOUT           30
#define MDS_TriggerSource_TIM3_TRGOUT           31
#define MDS_TriggerSource_TIM4_TRGOUT           32
#define MDS_TriggerSource_TIM5_TRGOUT           33
#define MDS_TriggerSource_TIM8_TRGOUT           36
#define MDS_TriggerSource_EXTI0                 37
#define MDS_TriggerSource_EXTI1                 38
#define MDS_TriggerSource_EXTI2                 39
#define MDS_TriggerSource_EXTI3                 40
#define MDS_TriggerSource_EXTI4                 41
#define MDS_TriggerSource_EXTI5                 42
#define MDS_TriggerSource_EXTI6                 43
#define MDS_TriggerSource_EXTI7                 44
#define MDS_TriggerSource_EXTI8                 45
#define MDS_TriggerSource_EXTI9                 46
#define MDS_TriggerSource_EXTI10                47
#define MDS_TriggerSource_EXTI11                48
#define MDS_TriggerSource_EXTI12                49
#define MDS_TriggerSource_EXTI13                50
#define MDS_TriggerSource_EXTI14                51
#define MDS_TriggerSource_EXTI15                52

/**
  * @brief MDS_TriggerOutput_Sel
  */
#define MDS_TriggerOutput_ADC1_EXT_TRIGGER      0
#define MDS_TriggerOutput_ADC1_INJ_TRIGGER      1
#define MDS_TriggerOutput_ADC2_EXT_TRIGGER      2
#define MDS_TriggerOutput_ADC2_INJ_TRIGGER      3
#define MDS_TriggerOutput_DAC1_EXT_TRIGGER      6
#define MDS_TriggerOutput_DAC2_EXT_TRIGGER      7

/**
  * @brief MDS_ConnectionSource_Sel
  */
#define MDS_ConnectionSource_LOW_LEVEL          0
#define MDS_ConnectionSource_HIGH_LEVEL         1
#define MDS_ConnectionSource_TIM1_CH1           2
#define MDS_ConnectionSource_TIM1_CH1N          3
#define MDS_ConnectionSource_TIM1_CH2           4
#define MDS_ConnectionSource_TIM1_CH2N          5
#define MDS_ConnectionSource_TIM1_CH3           6
#define MDS_ConnectionSource_TIM1_CH3N          7
#define MDS_ConnectionSource_TIM1_CH4           8
#define MDS_ConnectionSource_TIM1_CH4N          9
#define MDS_ConnectionSource_TIM2_CH1           10
#define MDS_ConnectionSource_TIM2_CH2           11
#define MDS_ConnectionSource_TIM2_CH3           12
#define MDS_ConnectionSource_TIM2_CH4           13
#define MDS_ConnectionSource_TIM3_CH4           14
#define MDS_ConnectionSource_TIM4_CH4           15
#define MDS_ConnectionSource_TIM5_CH4           16
#define MDS_ConnectionSource_TIM8_CH4           17
#define MDS_ConnectionSource_MDS_IN0            18
#define MDS_ConnectionSource_MDS_IN1            19
#define MDS_ConnectionSource_MDS_IN2            20
#define MDS_ConnectionSource_MDS_IN3            21

/**
  * @brief MDS_ConnectionOutput_Sel
  */
#define MDS_ConnectionOutput_COMP1_BLANKING     0
#define MDS_ConnectionOutput_COMP2_BLANKING     1
#define MDS_ConnectionOutput_COMP3_BLANKING     2
#define MDS_ConnectionOutput_MDS_OUT0           3
#define MDS_ConnectionOutput_MDS_OUT1           4
#define MDS_ConnectionOutput_MDS_OUT2           5
#define MDS_ConnectionOutput_MDS_OUT3           6

/**
  * @brief MDS_InputEdge_Sel
  */
#define MDS_InputEdge_Rising                    0                                     /*!< Rising as trigger source edge. */
#define MDS_InputEdge_Falling                   1                                     /*!< Falling as trigger source edge. */
#define MDS_InputEdge_Both                      2                                     /*!< Both Rising and Falling as trigger source edge. */

/**
  * @brief MDS_TriggerSourceSel_CLUX
  */
#define MDS_TriggerSourceSel_CLU0               0                                     /*!< Select the CLU0 output as the trigger source. */
#define MDS_TriggerSourceSel_CLU1               1                                     /*!< Select the CLU1 output as the trigger source. */
#define MDS_TriggerSourceSel_CLU2               2                                     /*!< Select the CLU2 output as the trigger source. */
#define MDS_TriggerSourceSel_CLU3               3                                     /*!< Select the CLU3 output as the trigger source. */

/**
  * @brief MDS_CLU_InputX_Invert_Sel
  */
#define MDS_CLU_Input_NonInvert                 0x00                                  /*!< CLU INPUT0 as input to the combinatorial logical operation. */
#define MDS_CLU_Input_Invert                    0x01                                  /*!< Invert CLU INPUT0 as the input to the combinatorial logical operation. */

/**
  * @brief MDS_CluLogicMode_Sel
  */
#define MDS_CluLogicMode_OR_OR_OR               (0x00U << MDS_CONN_CLUCFG_CLMODE_Pos) /*!< Output = in0|in1|in2|in3      */
#define MDS_CluLogicMode_AND_OR_AND             (0x01U << MDS_CONN_CLUCFG_CLMODE_Pos) /*!< Output = (in0&in1)|(in2&in3)  */
#define MDS_CluLogicMode_OR_XOR_OR              (0x02U << MDS_CONN_CLUCFG_CLMODE_Pos) /*!< Output = (in0|in1)^(in2|in3)  */
#define MDS_CluLogicMode_AND_AND_AND            (0x03U << MDS_CONN_CLUCFG_CLMODE_Pos) /*!< Output = in0&in1&in2&in3      */

/**
  * @brief MDS_TriggerNotCLU_TypeDef
  */
typedef struct
{
    uint8_t  MDS_Channel;              /*!< Select trigger target. */
    uint8_t  MDS_InputEdge;            /*!< Select edge. */
    uint8_t  MDS_InputSource;          /*!< Select trigger source. */
} MDS_TriggerNotCLU_TypeDef;

/**
  * @brief MDS_TriggerCLU_TypeDef
  */
typedef struct
{
    uint8_t  MDS_Channel;                            /*!< Select trigger target. */
    uint8_t  MDS_CluNumber;                          /*!< Select the CLUx output as the trigger source. */
    uint8_t  CluInputSource[MDS_CLUGROUP_INPUT_MAX]; /*!< Select trigger source for each input channel of the CLU. */
    uint8_t  CluInputEdge[MDS_CLUGROUP_INPUT_MAX];   /*!< Select edge. */
} MDS_TriggerCLU_TypeDef;

/**
  * @brief MDS_ConnectionNotCLU_TypeDef
  */
typedef struct
{
    uint8_t  MDS_Channel;              /*!< Select connection target. */
    uint8_t  MDS_InputSource;          /*!< Select connection source. */
} MDS_ConnectionNotCLU_TypeDef;

/**
  * @brief MDS_ConnectionCLU_TypeDef
  */
typedef struct
{
    uint8_t  MDS_Channel;                            /*!< Select connection target. */
    uint8_t  MDS_CluNumber;                          /*!< Select the CLUx output as the connection source. */
    uint8_t  CluInputSource[MDS_CLUGROUP_INPUT_MAX]; /*!< Select connection source for each input channel of the CLU. */
    uint8_t  MDS_CluLogicMode;                       /*!< Select CLU Mode. */
    uint8_t  CluInputInvert[MDS_CLUGROUP_INPUT_MAX]; /*!< Invert CLU INPUTx as the input to the combinatorial logical operation. */
} MDS_ConnectionCLU_TypeDef;

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup MDS_Exported_Functions
  * @{
  */
void MDS_DeInit(void);

void MDS_TriggerCluInit(MDS_TriggerCLU_TypeDef *init_struct);
void MDS_TriggerCluStructInit(MDS_TriggerCLU_TypeDef *init_struct);
void MDS_TriggerNotCluInit(MDS_TriggerNotCLU_TypeDef *init_struct);
void MDS_TriggerNotCluStructInit(MDS_TriggerNotCLU_TypeDef *init_struct);
void MDS_SoftTriggerCmd(FunctionalState state);

void MDS_ConnectionNotCluInit(MDS_ConnectionNotCLU_TypeDef *init_struct);
void MDS_ConnectionNotCluStructInit(MDS_ConnectionNotCLU_TypeDef *init_struct);
void MDS_ConnectionCluInit(MDS_ConnectionCLU_TypeDef *init_struct);
void MDS_ConnectionCluStructInit(MDS_ConnectionCLU_TypeDef *init_struct);

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
#endif
/** --------------------------------------------------------------------------*/

