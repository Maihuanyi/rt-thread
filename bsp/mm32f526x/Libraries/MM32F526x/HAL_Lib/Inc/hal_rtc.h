/***********************************************************************************************************************
    @file     hal_rtc.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE RTC
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
#ifndef __HAL_RTC_H
#define __HAL_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup RTC_HAL
  * @brief RTC HAL modules
  * @{
  */

/** @defgroup RTC_Exported_Types
  * @{
  */

/** @defgroup RTC_Exported_Constants
  * @{
  */

/**
  * @brief  RTC_interrupts_define
  */
#define RTC_IT_OW                          (0x01U << RTC_CRH_OWIE_Pos)  /*!< Overflow interrupt */
#define RTC_IT_ALR                         (0x01U << RTC_CRH_ALRIE_Pos) /*!< Alarm interrupt */
#define RTC_IT_SEC                         (0x01U << RTC_CRH_SECIE_Pos) /*!< Second interrupt */

/**
  * @brief  RTC_interrupts_flags
  */
#define RTC_FLAG_RTOFF                     (0x01U << RTC_CRL_RTOFF_Pos) /*!< RTC Operation OFF flag */
#define RTC_FLAG_RSF                       (0x01U << RTC_CRL_RSF_Pos)   /*!< Registers Synchronized flag */
#define RTC_FLAG_OW                        (0x01U << RTC_CRL_OWF_Pos)   /*!< Overflow flag */
#define RTC_FLAG_ALR                       (0x01U << RTC_CRL_ALRF_Pos)  /*!< Alarm flag */
#define RTC_FLAG_SEC                       (0x01U << RTC_CRL_SECF_Pos)  /*!< Second flag */

/**
  * @brief RTC_LSE_TemperatureCompensation
  */

#define    RTC_LSE_TC_None                 (0x00U << RTC_LSE_CFG_LSE_TC_Pos)
#define    RTC_LSE_TC_Weak                 (0x01U << RTC_LSE_CFG_LSE_TC_Pos)
#define    RTC_LSE_TC_Normal               (0x02U << RTC_LSE_CFG_LSE_TC_Pos)
#define    RTC_LSE_TC_Strong               (0x03U << RTC_LSE_CFG_LSE_TC_Pos)

/**
  * @brief RTC_LSE_OutputEnhance
  */
#define    RTC_LSE_OutputEnhance_Reset     (0x00U << RTC_LSE_CFG_LSE_OUTENH_Pos)
#define    RTC_LSE_OutputEnhance_Set       (0x01U << RTC_LSE_CFG_LSE_OUTENH_Pos)  /*!< LSE enhanced output mode */

/**
  * @brief RTC_LSE_FeedbackResistor
  */
#define    RTC_LSE_FeedbackResistorMode0   (0x00U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) /*!< Feedback resistor selection */
#define    RTC_LSE_FeedbackResistorMode1   (0x01U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) /*!< Feedback resistor selection */
#define    RTC_LSE_FeedbackResistorMode2   (0x02U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) /*!< Feedback resistor selection */
#define    RTC_LSE_FeedbackResistorMode3   (0x03U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) /*!< Feedback resistor selection */

/**
  * @brief RTC_LSE_AutoGain
  */

#define    RTC_LSE_AutoGain_Reset          (0x00U << RTC_LSE_CFG_LSE_AAC_Pos)
#define    RTC_LSE_AutoGain_Set            (0x01U << RTC_LSE_CFG_LSE_AAC_Pos) /*!< LSE oscillation amplitude select bit */

/**
  * @brief  RTCCAL Init structures definition
  */
typedef struct
{
    uint32_t   RTC_LSE_TemperatureCompensation;
    uint32_t   RTC_LSE_OutputEnhancement;
    uint32_t   RTC_LSE_DriverLevel;
    uint32_t   RTC_LSE_ResistorFeedbackMode;
    uint32_t   RTC_LSE_BiasCurrentLevel;
    uint32_t   RTC_LSE_AutoGain;
} RTC_LSEConfig_TypeDef;

/**
  * @}
  */

/** @defgroup RTC_Exported_Functions
  * @{
  */
void RTC_ITConfig(uint16_t RTC_IT, FunctionalState state);
void RTC_EnterConfigMode(void);
void RTC_ExitConfigMode(void);
void RTC_AlarmLoopCmd(FunctionalState state);
uint32_t RTC_GetCounter(void);
void RTC_SetCounter(uint32_t CounterValue);
void RTC_SetPrescaler(uint32_t PrescalerValue);
void RTC_SetAlarm(uint32_t AlarmValue);
void RTC_SetMsAlarm(uint32_t MsAlarmValue);
uint32_t RTC_GetDivider(void);
void RTC_WaitForLastTask(void);
void RTC_WaitForSynchro(void);
FlagStatus RTC_GetFlagStatus(uint16_t RTC_FLAG);
void RTC_ClearFlag(uint16_t RTC_FLAG);
ITStatus RTC_GetITStatus(uint16_t RTC_IT);
void RTC_ClearITPendingBit(uint16_t RTC_IT);
ErrorStatus RTC_LSEConfig(RTC_LSEConfig_TypeDef *config_struct);

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
#endif /* __HAL_RTC_H ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

