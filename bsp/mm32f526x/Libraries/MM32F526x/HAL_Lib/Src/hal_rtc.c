/***********************************************************************************************************************
    @file     hal_rtc.c
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

/* Files includes ------------------------------------------------------------*/
#include "hal_rtc.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/**
  * @brief  Enables or disables the specified RTC interrupts.
  * @param  RTC_IT: specifies the RTC interrupts sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  *     @arg RTC_IT_OW: Overflow interrupt
  *     @arg RTC_IT_ALR: Alarm interrupt
  *     @arg RTC_IT_SEC: Second interrupt
  * @param  state: new state of the specified RTC interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RTC_ITConfig(uint16_t RTC_IT, FunctionalState state)
{
    (state) ?              \
    (RTC->CRH |= RTC_IT) : \
    (RTC->CRH &= ~RTC_IT);
}

/**
  * @brief  Enters the RTC configuration mode.
  * @param  None
  * @retval None
  */
void RTC_EnterConfigMode(void)
{
    /* Set the CNF flag to enter in the Configuration Mode */
    RTC->CRL |= (0x01U << RTC_CRL_CNF_Pos);
}

/**
  * @brief  Exits from the RTC configuration mode.
  * @param  None
  * @retval None
  */
void RTC_ExitConfigMode(void)
{
    /* Reset the CNF flag to exit from the Configuration Mode */
    RTC->CRL &= ~(0x01U << RTC_CRL_CNF_Pos);
}

/**
  * @brief  Enable or disable the RTC alarm loop mode.
  * @param  state: new state of the RTC alarm loop mode .
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RTC_AlarmLoopCmd(FunctionalState state)
{
    (state) ?                                    \
    (RTC->CRL |= (0x01U << RTC_CRL_ALPEN_Pos)) : \
    (RTC->CRL &= ~(0x01U << RTC_CRL_ALPEN_Pos));
}

/**
  * @brief  Gets the RTC counter value.
  * @param  None
  * @retval RTC counter value.
  */
uint32_t RTC_GetCounter(void)
{
    uint16_t high1 = 0, high2 = 0, low = 0;

    high1 = RTC->CNTH;
    low   = RTC->CNTL;
    high2 = RTC->CNTH;

    if (high1 != high2)
    {
        /* In this case the counter roll over during reading of CNTL and CNTH registers,
           read again CNTL register then return the counter value */
        return (((uint32_t)high2 << 16) | RTC->CNTL);
    }
    else
    {
        /* No counter roll over during reading of CNTL and CNTH registers, counter
           value is equal to first value of CNTL and CNTH */
        return (((uint32_t)high1 << 16) | low);
    }
}

/**
  * @brief  Sets the RTC counter value.
  * @param  CounterValue: RTC counter new value.
  * @retval None
  */
void RTC_SetCounter(uint32_t CounterValue)
{
    RTC_EnterConfigMode();
    /* Set RTC COUNTER MSB word */
    RTC->CNTH = CounterValue >> 16;
    /* Set RTC COUNTER LSB word */
    RTC->CNTL = (CounterValue & RTC_CNTL_CNT_Msk);
    RTC_ExitConfigMode();
}

/**
  * @brief  Sets the RTC prescaler value.
  * @param  PrescalerValue: RTC prescaler new value.
  * @retval None
  */
void RTC_SetPrescaler(uint32_t PrescalerValue)
{
    RTC_EnterConfigMode();
    /* Set RTC PRESCALER MSB word */
    RTC->PRLH = ((PrescalerValue >> 16) & RTC_PRLH_PRL_Msk);
    /* Set RTC PRESCALER LSB word */
    RTC->PRLL = (PrescalerValue & RTC_PRLL_PRL_Msk);
    RTC_ExitConfigMode();
}

/**
  * @brief  Sets the RTC alarm value.
  * @param  AlarmValue: RTC alarm new value.
  * @retval None
  */
void RTC_SetAlarm(uint32_t AlarmValue)
{
    RTC_EnterConfigMode();
    RTC->MSRH = 0;
    RTC->MSRL = 0;
    /* Set the ALARM MSB word */
    RTC->ALRH = AlarmValue >> 16;
    /* Set the ALARM LSB word */
    RTC->ALRL = (AlarmValue & RTC_ALRL_ALR_Msk);
    RTC_ExitConfigMode();
}

/**
  * @brief  Sets the RTC millisecond alarm value.
  * @param  MsAlarmValue: RTC millisecond alarm new value.
  * @retval None
  */
void RTC_SetMsAlarm(uint32_t MsAlarmValue)
{
    RTC_EnterConfigMode();
    RTC->ALRH = 0;
    RTC->ALRL = 0;
    /* Set the MsALARM MSB word */
    RTC->MSRH = ((MsAlarmValue >> 16) & RTC_MSRH_MSR_Msk);
    /* Set the MsALARM LSB word */
    RTC->MSRL = (MsAlarmValue & RTC_MSRL_MSR_Msk);
    RTC_ExitConfigMode();
}

/**
  * @brief  Gets the RTC divider value.
  * @param  None
  * @retval RTC Divider value.
  */
uint32_t RTC_GetDivider(void)
{
    uint32_t tmp = 0x00;

    tmp  = ((uint32_t)RTC->DIVH & RTC_DIVH_DIV_Msk) << 16;
    tmp |= RTC->DIVL;
    return (tmp);
}

/**
  * @brief  Waits until last write operation on RTC registers has finished.
  * @note   This function must be called before any write to RTC registers.
  * @param  None
  * @retval None
  */
void RTC_WaitForLastTask(void)
{
    /* Loop until RTOFF flag is set */
    while ((RTC->CRL & RTC_CRL_RTOFF_Msk) == (uint16_t)RESET)
    {
    }
}

/**
  * @brief  Waits until the RTC registers (RTC_CNT, RTC_ALR and RTC_PRL)
  *   are synchronized with RTC APB clock.
  * @note   This function must be called before any read operation after an APB reset
  *   or an APB clock stop.
  * @param  None
  * @retval None
  */
void RTC_WaitForSynchro(void)
{
    /* Clear RSF flag */
    RTC->CRL &= ~(0x01U << RTC_CRL_RSF_Pos);

    /* Loop until RSF flag is set */
    while ((RTC->CRL & RTC_CRL_RSF_Msk) == (uint16_t)RESET)
    {
    }
}

/**
  * @brief  Checks whether the specified RTC flag is set or not.
  * @param  RTC_FLAG: specifies the flag to check.
  *   This parameter can be one the following values:
  *     @arg RTC_FLAG_RTOFF: RTC Operation OFF flag
  *     @arg RTC_FLAG_RSF: Registers Synchronized flag
  *     @arg RTC_FLAG_OW: Overflow flag
  *     @arg RTC_FLAG_ALR: Alarm flag
  *     @arg RTC_FLAG_SEC: Second flag
  * @retval The new state of RTC_FLAG (SET or RESET).
  */
FlagStatus RTC_GetFlagStatus(uint16_t RTC_FLAG)
{
    return ((RTC->CRL & RTC_FLAG) ? SET : RESET);
}

/**
  * @brief  Clears the RTC's pending flags.
  * @param  RTC_FLAG: specifies the flag to clear.
  *   This parameter can be any combination of the following values:
  *     @arg RTC_FLAG_RSF: Registers Synchronized flag. This flag is cleared only after
  *                        an APB reset or an APB Clock stop.
  *     @arg RTC_FLAG_OW: Overflow flag
  *     @arg RTC_FLAG_ALR: Alarm flag
  *     @arg RTC_FLAG_SEC: Second flag
  * @retval None
  */
void RTC_ClearFlag(uint16_t RTC_FLAG)
{
    RTC->CRL &= ~RTC_FLAG;
}

/**
  * @brief  Checks whether the specified RTC interrupt has occurred or not.
  * @param  RTC_IT: specifies the RTC interrupts sources to check.
  *   This parameter can be one of the following values:
  *     @arg RTC_IT_OW: Overflow interrupt
  *     @arg RTC_IT_ALR: Alarm interrupt
  *     @arg RTC_IT_SEC: Second interrupt
  * @retval The new state of the RTC_IT (SET or RESET).
  */
ITStatus RTC_GetITStatus(uint16_t RTC_IT)
{
    return ((((RTC->CRH & RTC_IT) != (uint16_t)RESET) && ((RTC->CRL & RTC_IT) != (uint16_t)RESET)) ? SET : RESET);
}

/**
  * @brief  Clears the RTC's interrupt pending bits.
  * @param  RTC_IT: specifies the interrupt pending bit to clear.
  *   This parameter can be any combination of the following values:
  *     @arg RTC_IT_OW: Overflow interrupt
  *     @arg RTC_IT_ALR: Alarm interrupt
  *     @arg RTC_IT_SEC: Second interrupt
  * @retval None
  */
void RTC_ClearITPendingBit(uint16_t RTC_IT)
{
    /* Clear the corresponding RTC pending bit */
    RTC->CRL &= ~RTC_IT;
}

/**
  * @brief  Initializes the RTC registers according to the specified parameters
  *         in init_struct.
  * @param  init_struct: pointer to a RTC_LSEConfig_TypeDef structure that contains
  *         the configuration information for the RTC peripheral.
  * @note   The RTC LSEConfig parameters can be config when LSE is off only.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are initialized
  *          - ERROR: RTC registers are not initialized
  */
ErrorStatus RTC_LSEConfig(RTC_LSEConfig_TypeDef *config_struct)
{
    ErrorStatus status = ERROR;
    uint32_t temp = 0;

    if ((RCC->BDCR & RCC_BDCR_LSEON_Msk) != RESET)
    {
        return (status);
    }

    /* Set RTC_LSE_CFG register */
    temp = (uint32_t)((config_struct->RTC_LSE_TemperatureCompensation) | \
                      (config_struct->RTC_LSE_OutputEnhancement) |       \
                      (config_struct->RTC_LSE_DriverLevel) |             \
                      (config_struct->RTC_LSE_ResistorFeedbackMode) |    \
                      (config_struct->RTC_LSE_BiasCurrentLevel) |        \
                      (config_struct->RTC_LSE_AutoGain));
    RTC->LSE_CFG = temp;
    return (SUCCESS);
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

