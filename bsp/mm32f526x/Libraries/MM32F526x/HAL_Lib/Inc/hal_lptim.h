/***********************************************************************************************************************
    @file     hal_lptim.h
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
#ifndef __HAL_LPTIM_H
#define __HAL_LPTIM_H

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup LPTIM_HAL
  * @brief TIM HAL modules
  * @{
  */

/** @defgroup LPTIM_Exported_Types
  * @{
  */

/**
  * @brief  TIM Time Base Init structure definition
  * @note   This structure is used with all lptim.
  */
typedef struct
{
    uint32_t   ClockSource;            /*!< Specifies the clock source of the LPTIM. */
    uint32_t   CountMode;              /*!< Specifies the Count mode */
    uint32_t   WorkMode;               /*!< Specifies the Output Mode */
    uint32_t   Waveform;               /*!< Specifies the PWM wave form. */
    uint32_t   Polarity;               /*!< Specifies the Output Polarity */
    uint32_t   ClockDivision;          /*!< Specifies the clock divide. */
} LPTIM_TimeBaseInit_TypeDef;

/**
  * @brief LPTIM_CLK_SOURCE_TypeDef
  */
#define LPTIM_CLK_LSE                  (0x00U << RCC_CFGR2_LPTIMCLKSEL_Pos) /*!< LPTIM clock source select LSE */
#define LPTIM_CLK_LSI                  (0x01U << RCC_CFGR2_LPTIMCLKSEL_Pos) /*!< LPTIM clock source select LSI */
#define LPTIM_CLK_PCLK                 (0x02U << RCC_CFGR2_LPTIMCLKSEL_Pos) /*!< LPTIM clock source select PCLK */
#define LPTIM_CLK_HSI                  (0x03U << RCC_CFGR2_LPTIMCLKSEL_Pos) /*!< LPTIM clock source select HSI */

/**
  * @brief LPTIM_Count_Mode_TypeDef
  */
#define LPTIM_CNT_Continuous           (0x00U << LPTIM_CFG_MODE_Pos)        /*!< LPTIM Continuous Count mode */
#define LPTIM_CNT_Single               (0x01U << LPTIM_CFG_MODE_Pos)        /*!< LPTIM Single Count mode */

/**
  * @brief LPTIM_Mode_TypeDef
  */
#define LPTIM_MODE_NormalWave          (0x00U << LPTIM_CFG_TMODE_Pos)       /*!< LPTIM Normal TIM Wave output mode */
#define LPTIM_MODE_TrigCNT             (0x01U << LPTIM_CFG_TMODE_Pos)       /*!< LPTIM pulse trig count output mode */
#define LPTIM_MODE_TimeOut             (0x03U << LPTIM_CFG_TMODE_Pos)       /*!< LPTIM time out output mode */

/**
  * @brief LPTIM_PWMOUT_Mode_TypeDef
  */
#define LPTIM_Waveform_CycleSquare     (0x00U << LPTIM_CFG_PWM_Pos)         /*!< LPTIM Cycle Square Wave output mode */
#define LPTIM_Waveform_PWM             (0x01U << LPTIM_CFG_PWM_Pos)         /*!< LPTIM Pulse Wave Modified output mode */

/**
  * @brief LPTIM_COMPARE_Polarity_TypeDef
  */
#define LPTIM_Positive_Wave            (0x00U << LPTIM_CFG_POLARITY_Pos)    /*!< LPTIM Compare Match Wave mode(positive) */
#define LPTIM_Negative_Wave            (0x01U << LPTIM_CFG_POLARITY_Pos)    /*!< LPTIM Compare Match Wave mode(negative) */

/**
  * @brief LPTIM_TrigSourceConfig_TypeDef
  */
#define LPTIM_Trig_ExternalPIN         (0x00U << LPTIM_CFG_TRIGSEL_Pos)     /*!< LPTIM use external pin as trig source */
#define LPTIM_Trig_ComparerOut         (0x01U << LPTIM_CFG_TRIGSEL_Pos)     /*!< LPTIM out COPM output as trig source */

/**
  * @brief LPTIM_TrigEdgeConfig_TypeDef
  */
#define LPTIM_TrigEdge_UpEdge          (0x00U << LPTIM_CFG_TRIGCFG_Pos)     /*!< LPTIM use external signal raise edge trig */
#define LPTIM_TrigEdge_DownEdge        (0x01U << LPTIM_CFG_TRIGCFG_Pos)     /*!< LPTIM use external signal fall edge trig */
#define LPTIM_TrigEdge_UpDownEdge      (0x02U << LPTIM_CFG_TRIGCFG_Pos)     /*!< LPTIM use external signal raise and fall edge trig */

/**
  * @brief LPTIM_CLOCK_DIV_TypeDef
  */
#define LPTIM_CLK_Div1                 (0x00U << LPTIM_CFG_DIVSEL_Pos)      /*!< LPTIM  Counter Clock div 1 */
#define LPTIM_CLK_Div2                 (0x01U << LPTIM_CFG_DIVSEL_Pos)      /*!< LPTIM  Counter Clock div 2 */
#define LPTIM_CLK_Div4                 (0x02U << LPTIM_CFG_DIVSEL_Pos)      /*!< LPTIM  Counter Clock div 4 */
#define LPTIM_CLK_Div8                 (0x03U << LPTIM_CFG_DIVSEL_Pos)      /*!< LPTIM  Counter Clock div 8 */
#define LPTIM_CLK_Div16                (0x04U << LPTIM_CFG_DIVSEL_Pos)      /*!< LPTIM  Counter Clock div 16 */
#define LPTIM_CLK_Div32                (0x05U << LPTIM_CFG_DIVSEL_Pos)      /*!< LPTIM  Counter Clock div 32 */
#define LPTIM_CLK_Div64                (0x06U << LPTIM_CFG_DIVSEL_Pos)      /*!< LPTIM  Counter Clock div 64 */
#define LPTIM_CLK_Div128               (0x07U << LPTIM_CFG_DIVSEL_Pos)      /*!< LPTIM  Counter Clock div 128 */

/**
  * @brief LPTIM_FilterTrig_TypeDef
  */
#define LPTIM_TrigFilter_Disable       (0x00U << LPTIM_CFG_FLTEN_Pos)       /*!< LPTIM Filter Trig disable */
#define LPTIM_TrigFilter_Enable        (0x01U << LPTIM_CFG_FLTEN_Pos)       /*!< LPTIM Filter Trig enable */

/**
  * @}
  */
#define LPTIM_IT_OVIE                  (0x01U << LPTIM_IE_OVIE_Pos)
#define LPTIM_IT_TRIGIE                (0x01U << LPTIM_IE_TRIGIE_Pos) /*!< Counter value and comparison value match interrupt enable */
#define LPTIM_IT_COMPIE                (0x01U << LPTIM_IE_COMPIE_Pos) /*!< External trigger arrival interrupt enable */

/**
  * @defgroup LPTIM_Exported_Functions
  * @{
  */
void LPTIM_DeInit(LPTIM_TypeDef *lptim);
void LPTIM_TimeBaseStructInit(LPTIM_TimeBaseInit_TypeDef *init_struct);
void LPTIM_TimeBaseInit(LPTIM_TypeDef *lptim, LPTIM_TimeBaseInit_TypeDef *init_struct);
void LPTIM_Cmd(LPTIM_TypeDef *lptim, FunctionalState state);
void LPTIM_ExternalTrigSourceConfig(LPTIM_TypeDef *lptim, uint32_t trig_source, uint32_t trig_edge);
void LPTIM_SetClockDivision(LPTIM_TypeDef *lptim, uint32_t clock_div);
void LPTIM_InputFilterCmd(LPTIM_TypeDef *lptim, FunctionalState state);
void LPTIM_SetCounter(LPTIM_TypeDef *lptim, uint16_t counter);
uint32_t LPTIM_GetCounter(LPTIM_TypeDef *lptim);
void LPTIM_SetCompare(LPTIM_TypeDef *lptim, uint16_t value);
uint16_t LPTIM_GetCompare(LPTIM_TypeDef *lptim);
void LPTIM_SetTarget(LPTIM_TypeDef *lptim, uint16_t target);
uint16_t LPTIM_GetTarget(LPTIM_TypeDef *lptim);
void LPTIM_ITConfig(LPTIM_TypeDef *lptim, uint32_t it, FunctionalState state);
ITStatus LPTIM_GetITStatus(LPTIM_TypeDef *lptim, uint32_t it);
void LPTIM_ClearITPendingBit(LPTIM_TypeDef *lptim, uint32_t it);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif

