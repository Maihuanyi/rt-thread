/***********************************************************************************************************************
    @file     hal_bkp.h
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
#ifndef __HAL_BKP_H
#define __HAL_BKP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup BKP_HAL
  * @brief BKP HAL modules
  * @{
  */

/** @defgroup BKP_Exported_Types
  * @{
  ******************************************************************************
  * @brief  Data Backup Register
  */
#define BKP_DR1                           0x10
#define BKP_DR2                           0x14
#define BKP_DR3                           0x18
#define BKP_DR4                           0x1C
#define BKP_DR5                           0x20
#define BKP_DR6                           0x24
#define BKP_DR7                           0x28
#define BKP_DR8                           0x2C
#define BKP_DR9                           0x30
#define BKP_DR10                          0x34
#define BKP_DR11                          0x38
#define BKP_DR12                          0x3C
#define BKP_DR13                          0x40
#define BKP_DR14                          0x44
#define BKP_DR15                          0x48
#define BKP_DR16                          0x4C
#define BKP_DR17                          0x50
#define BKP_DR18                          0x54
#define BKP_DR19                          0x58
#define BKP_DR20                          0x5C

/**
  * @brief Tamper Pin active level
  */
#define BKP_TamperPinLevel_High           (0x00U << BKP_CR_TPAL_Pos)                                      /*!< Tamper pin active on high level */
#define BKP_TamperPinLevel_Low            (0x01U << BKP_CR_TPAL_Pos)                                      /*!< Tamper pin active on low level */

/**
  * @brief RTC output source to output on the Tamper pin
  */
#define BKP_RTCOutputSource_None          0x0000                                                          /*!< No RTC output on the Tamper pin */
#define BKP_RTCOutputSource_CalibClock    (0x01U << BKP_RTCCR_CCO_Pos)                                    /*!< Output the RTC clock with frequency divided by 64 on the Tamper pin */
#define BKP_RTCOutputSource_Alarm         (0x01U << BKP_RTCCR_ASOE_Pos)                                   /*!< Output the RTC Alarm pulse signal on the Tamper pin */
#define BKP_RTCOutputSource_Second        ((0x01U << BKP_RTCCR_ASOE_Pos) | (0x01U << BKP_RTCCR_ASOS_Pos)) /*!< Output the RTC Second pulse signal on the Tamper pin */

/**
  * @}
  */

/**
  * @defgroup BKP_Exported_Functions
  * @{
  */
void BKP_WriteBackupRegister(uint8_t bkp_dr, uint16_t data);
uint16_t BKP_ReadBackupRegister(uint8_t bkp_dr);

void BKP_DeInit(void);
void BKP_ClearFlag(void);
void BKP_ClearITPendingBit(void);
void BKP_TamperPinLevelConfig(uint8_t tamper_pin_level);
void BKP_TamperPinCmd(FunctionalState state);
void BKP_ITConfig(FunctionalState state);
void BKP_RTCOutputConfig(uint16_t rtc_output_source);
void BKP_SetRTCCalibrationValue(uint8_t calibration_value);

ITStatus BKP_GetITStatus(void);
FlagStatus BKP_GetFlagStatus(void);

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
#endif /* __HAL_BKP_H --------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

