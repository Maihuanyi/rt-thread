/***********************************************************************************************************************
    @file     hal_pwr.h
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
#ifndef __HAL_PWR_H
#define __HAL_PWR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup PWR_HAL
  * @brief PWR HAL modules
  * @{
  */

/** @defgroup PWR_Exported_Types
  * @{
  */
#define WAKEUP_PIN0                     (0x01U << PWR_CR2_EWUP0_Pos)
#define WAKEUP_PIN1                     (0x01U << PWR_CR2_EWUP1_Pos)
#define WAKEUP_PIN2                     (0x01U << PWR_CR2_EWUP2_Pos)
#define WAKEUP_PIN3                     (0x01U << PWR_CR2_EWUP3_Pos)
#define WAKEUP_PIN4                     (0x01U << PWR_CR2_EWUP4_Pos)
#define WAKEUP_PIN5                     (0x01U << PWR_CR2_EWUP5_Pos)

/** @defgroup WakeUp_PinX_Edge
  * @{
  */
#define WAKEUP_EDGE_FALL                0x01
#define WAKEUP_EDGE_RISE                0x00

/** @defgroup WakeUp_Filter_Config
  * @{
  */
#define WAKEUP_FILTER_INVALID           0x00
#define WAKEUP_FILTER_LEVEL_HIGH        0x01
#define WAKEUP_FILTER_LEVEL_LOW         0x02

/** @defgroup Standby_Fast_WakeUp_Cycles
  * @{
  */
#define PWR_STANDBY_FS_WK_3_Cycles      (0x02U << PWR_CR6_STDBY_FS_WK_Pos) /*!< 3 LSI cycles wakeup */
#define PWR_STANDBY_FS_WK_4_Cycles      (0x03U << PWR_CR6_STDBY_FS_WK_Pos) /*!< 4 LSI cycles wakeup */
#define PWR_STANDBY_FS_WK_5_Cycles      (0x04U << PWR_CR6_STDBY_FS_WK_Pos) /*!< 5 LSI cycles wakeup */
#define PWR_STANDBY_FS_WK_6_Cycles      (0x05U << PWR_CR6_STDBY_FS_WK_Pos) /*!< 6 LSI cycles wakeup */
#define PWR_STANDBY_FS_WK_7_Cycles      (0x06U << PWR_CR6_STDBY_FS_WK_Pos) /*!< 7 LSI cycles wakeup */
#define PWR_STANDBY_FS_WK_8_Cycles      (0x07U << PWR_CR6_STDBY_FS_WK_Pos) /*!< 8 LSI cycles wakeup */

/**
  * @brief Regulator_state
  */
#define PWR_Regulator_ON                (0x00U << PWR_CR1_LPR_Pos)
#define PWR_Regulator_LowPower          (0x01U << PWR_CR1_LPR_Pos)

/**
  * @brief SLEEP_mode_entry
  */
#define PWR_SLEEPNOW_WFI                0x00000001
#define PWR_SLEEPNOW_WFE                0x00000002
#define PWR_SLEEPONEXIT                 0x00000003

/**
  * @brief STOP_mode_entry
  */
#define PWR_STOPEntry_WFI               0x00000001
#define PWR_STOPEntry_WFE               0x00000002

#define PWR_MODE_STOP                   0x00000001
#define PWR_MODE_DEEPSTOP               0x00000002

/**
  * @brief PWR_FLAG
  */
#define PWR_FLAG_SB                     (0x01U << PWR_CSR_SBF_Pos)
#define PWR_FLAG_VOSRDY                 (0x01U << PWR_CSR_VOSRDY_Pos)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup PWR_Exported_Functions
  * @{
  */
void PWR_DeInit(void);
void PWR_BackupAccessCmd(FunctionalState state);
void PWR_WakeUpPinXCmd(uint8_t pin, FunctionalState state);

void PWR_WakeUpPinXEdgeConfig(uint8_t pin, uint8_t edge);
void PWR_WakeUpPinXFilterConfig(uint8_t pin, uint8_t cnt, uint8_t mode);
FlagStatus PWR_GetWakeUpPinXFlagStatus(uint32_t flag);
void PWR_ClearWakeUpPinXFlag(uint32_t flag);
void PWR_StandbyFastWakeUpConfig(uint8_t cycle);

void PWR_EnterSLEEPMode(uint32_t regulator, uint32_t sleep_entry);
void PWR_EnterSTOPMode(uint32_t stop_mode, uint32_t stop_entry);
void PWR_EnterSTANDBYMode(void);
void PWR_LowPowerRunModeCmd(FunctionalState state);

FlagStatus PWR_GetFlagStatus(uint32_t flag);
void PWR_ClearFlag(uint32_t flag);

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
#endif /* __HAL_PWR_H ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

