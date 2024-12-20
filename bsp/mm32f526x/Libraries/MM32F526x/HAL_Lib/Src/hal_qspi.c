/***********************************************************************************************************************
    @file     hal_qspi.c
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
  *******************************************************************************************************************  */

/* Define to prevent recursive inclusion -------------------------------------*/
#define _HAL_QSPI_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_qspi.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup PWR_HAL
  * @{
  */

/** @addtogroup PWR_Exported_Functions
  * @{
  */
/**
  * @brief  Deinitializes the qspi peripheral registers to their
  *         default reset values.
  * @param  qspi: Select the QSPI peripheral.
  * @retval None.
  */
void QSPI_DeInit(QSPI_TypeDef *qspi)
{
    if (qspi == QSPI)
    {
        RCC_AHBPeriphResetCmd(RCC_AHBPeriph_QSPI, ENABLE);
        RCC_AHBPeriphResetCmd(RCC_AHBPeriph_QSPI, DISABLE);
    }
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to a QSPI_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void QSPI_StructInit(QSPI_InitTypeDef *init_struct)
{
    init_struct->ClockPrescalar         = 3;
    init_struct->NssHighLevelHold       = 0;
    init_struct->ModeSelection          = QSPI_MODE_3;
}

/**
  * @brief  Initializes the qspi peripheral according to the specified
  *         parameters in the init_struct .
  * @param  qspi: Select the QSPI peripheral.
  * @param  init_struct: pointer to a QSPI_InitTypeDef structure
  *         that contains the configuration information for the
  *         specified QSPI peripheral.
  * @retval None.
  */
void QSPI_Init(QSPI_TypeDef *qspi, QSPI_InitTypeDef *init_struct)
{
    MODIFY_REG(qspi->CR, QSPI_CR_SCKDIV_Msk, init_struct->ClockPrescalar << QSPI_CR_SCKDIV_Pos);
    MODIFY_REG(qspi->CR, QSPI_CR_CSRHT_Msk, init_struct->NssHighLevelHold << QSPI_CR_CSRHT_Pos);
    MODIFY_REG(qspi->CR, QSPI_CR_SCKMODE_Msk, init_struct->ModeSelection);
}

/**
  * @brief  Initializes the qspi peripheral according to the specified
  *         parameters in the init_struct .
  * @param  qspi: Select the QSPI peripheral.
  * @param  init_struct: pointer to a QSPI_InitTypeDef structure
  *         that contains the configuration information for the
  *         specified QSPI peripheral.
  * @retval None.
  */
void QSPI_CommonConfigStructInit(QSPI_CommonConfig_TypeDef *init_struct)
{
    init_struct->InstructionCode        = 0;
    init_struct->InstructPhaseMode      = QSPI_InstructPhaseMode_Single;
    init_struct->AddressPhaseMode       = QSPI_AddressPhaseMode_Single;
    init_struct->AddressPhaseSize       = QSPI_AddressPhaseSize_8Bit;
    init_struct->AltBytesPhaseMode      = QSPI_AltBytePhaseMode_None;
    init_struct->AltBytesPhaseSize      = QSPI_AltBytePhaseSize_8Bit;
    init_struct->DataPhaseMode          = QSPI_DataPhaseMode_Single;
    init_struct->DataPhaseSize          = QSPI_DataPhaseSize_32Bit;
    init_struct->RxdSampleDelayCycles   = QSPI_DelayCycles_0;
    init_struct->DummyPhaseCycles       = 0;
    init_struct->AltBytesValue          = 0;
}

/**
  * @brief  Initializes the qspi peripheral according to the specified
  *         parameters in the init_struct .
  * @param  qspi: Select the QSPI peripheral.
  * @param  init_struct: pointer to a QSPI_InitTypeDef structure
  *         that contains the configuration information for the
  *         specified QSPI peripheral.
  * @retval None.
  */
void QSPI_DirectInit(QSPI_TypeDef *qspi, QSPI_CommonConfig_TypeDef *init_struct)
{
    if (QSPI_GetOperationMode(qspi) != QSPI_OperationMode_Inactive)
    {
        QSPI_InactiveInit(qspi);
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        __NOP();
    }

    MODIFY_REG(qspi->DMCR, (QSPI_DMCR_INST_Msk |                                                        \
                            QSPI_DMCR_IMODE_Msk |                                                       \
                            QSPI_DMCR_ADMODE_Msk |                                                      \
                            QSPI_DMCR_ADSIZE_Msk |                                                      \
                            QSPI_DMCR_ABMODE_Msk |                                                      \
                            QSPI_DMCR_ABSIZE_Msk |                                                      \
                            QSPI_DMCR_DMODE_Msk |                                                       \
                            QSPI_DMCR_DSIZE_Msk |                                                       \
                            QSPI_DMCR_RXDLY_Msk |                                                       \
                            QSPI_DMCR_NUMDC_Msk), (init_struct->InstructionCode << QSPI_DMCR_INST_Pos | \
                                                   init_struct->InstructPhaseMode |                     \
                                                   init_struct->AddressPhaseMode |                      \
                                                   init_struct->AddressPhaseSize |                      \
                                                   init_struct->AltBytesPhaseMode |                     \
                                                   init_struct->AltBytesPhaseSize |                     \
                                                   init_struct->DataPhaseMode |                         \
                                                   init_struct->DataPhaseSize |                         \
                                                   init_struct->RxdSampleDelayCycles |                  \
                                                   init_struct->DummyPhaseCycles << QSPI_DMCR_NUMDC_Pos));
    qspi->DABR = init_struct->AltBytesValue;
    MODIFY_REG(qspi->CR, QSPI_CR_OPMODE_Msk, QSPI_OperationMode_Direct);
}

/**
  * @brief  Initializes the qspi peripheral according to the specified
  *         parameters in the init_struct .
  * @param  qspi: Select the QSPI peripheral.
  * @param  init_struct: pointer to a QSPI_CommonConfig_TypeDef structure
  *         that contains the configuration information for the
  *         specified QSPI peripheral.
  * @param  extendconfig: pointer to a QSPI_IndirectExtendConfig_TypeDef structure
  *         that contains the configuration information for the
  *         specified QSPI peripheral.
  * @param  accessmode: QSPI Indirect Mode Access
  * @arg    QSPI_IndirectModeAccess_Read
  * @arg    QSPI_IndirectModeAccess_Write
  * @retval None.
  */
void QSPI_IndirectInit(QSPI_TypeDef *qspi, QSPI_CommonConfig_TypeDef *init_struct, QSPI_IndirectExtendConfig_TypeDef *extendconfig, uint32_t accessmode)
{
    if (QSPI_GetOperationMode(qspi) != QSPI_OperationMode_Inactive)
    {
        QSPI_InactiveInit(qspi);
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        __NOP();
    }

    MODIFY_REG(qspi->IMCR, (QSPI_IMCR_INST_Msk |                                                           \
                            QSPI_IMCR_IMODE_Msk |                                                          \
                            QSPI_IMCR_ADMODE_Msk |                                                         \
                            QSPI_IMCR_ADSIZE_Msk |                                                         \
                            QSPI_IMCR_ABMODE_Msk |                                                         \
                            QSPI_IMCR_ABSIZE_Msk |                                                         \
                            QSPI_IMCR_DMODE_Msk |                                                          \
                            QSPI_IMCR_DSIZE_Msk |                                                          \
                            QSPI_IMCR_RXDLY_Msk |                                                          \
                            QSPI_IMCR_NUMDC_Msk |                                                          \
                            QSPI_IMCR_IDMODE_Msk), (init_struct->InstructionCode << QSPI_IMCR_INST_Pos |   \
                                                    init_struct->InstructPhaseMode |                       \
                                                    init_struct->AddressPhaseMode |                        \
                                                    init_struct->AddressPhaseSize |                        \
                                                    init_struct->AltBytesPhaseMode |                       \
                                                    init_struct->AltBytesPhaseSize |                       \
                                                    init_struct->DataPhaseMode |                           \
                                                    init_struct->DataPhaseSize |                           \
                                                    init_struct->RxdSampleDelayCycles |                    \
                                                    init_struct->DummyPhaseCycles << QSPI_IMCR_NUMDC_Pos | \
                                                    accessmode));

    qspi->IABR = init_struct->AltBytesValue;
    qspi->IADR = extendconfig->address;
    qspi->IDLR = extendconfig->length;
    qspi->IWCR = extendconfig->count;
    MODIFY_REG(qspi->CR, QSPI_CR_OPMODE_Msk, QSPI_OperationMode_Indirect);
}

/**
  * @brief  Initializes the qspi peripheral according to the specified
  *         parameters in the init_struct .
  * @param  qspi: Select the QSPI peripheral.
  * @retval None.
  */
void QSPI_InactiveInit(QSPI_TypeDef *qspi)
{
    MODIFY_REG(qspi->CR, QSPI_CR_XIPMODE_Msk, QSPI_OperationMode_Inactive);
}

/**
  * @brief  Enter or Exit XIP mode direct mode
  * @param  state: state of the enter or exit to the XIP mode for direct mode
  *         registers. This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void QSPI_DirectEnterXIPCmd(QSPI_TypeDef *qspi, FunctionalState state)
{
    (state) ?                           \
    (qspi->CR |= QSPI_CR_XIPMODE_Pos) : \
    (qspi->CR &= ~QSPI_CR_XIPMODE_Pos);
}

/**
  * @brief  Enter or Exit XIP mode indirect mode
  * @param  state: state of the enter or exit to the XIP mode for indirect mode
  *         registers. This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void QSPI_IndirectEnterXIPCmd(QSPI_TypeDef *qspi, FunctionalState state)
{
    (state) ?                             \
    (qspi->IMCR |= QSPI_IMCR_XIPIM_Msk) : \
    (qspi->IMCR &= ~QSPI_IMCR_XIPIM_Msk);
}

/**
  * @brief  Enter or Exit XIP mode indirect mode
  * @param  state: state of the enter or exit to the XIP mode for indirect mode
  *         registers. This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void QSPI_XIPFromIndirectCmd(QSPI_TypeDef *qspi, FunctionalState state)
{
    (state) ?                             \
    (qspi->IMCR |= QSPI_IMCR_XIPIM_Pos) : \
    (qspi->IMCR &= ~QSPI_IMCR_XIPIM_Pos);
}

/**
  * @brief  Set QSPI Operation Mode.
  * @param  qspi: Select the QSPI peripheral.
  * @param  mode: Select the QSPI Operation Mode.
  *         This parameter can be one of the following values:
  * @arg    QSPI_OperationMode_Direct
  * @arg    QSPI_OperationMode_Reserved
  * @arg    QSPI_OperationMode_Indirect
  * @arg    QSPI_OperationMode_Inactive
  * @retval The value of the received data.
  */
void QSPI_SetOperationMode(QSPI_TypeDef *qspi, uint32_t mode)
{
    MODIFY_REG(qspi->CR, QSPI_CR_OPMODE_Msk, mode);
}

/**
  * @brief  Get QSPI Current Operation Mode.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetOperationMode(QSPI_TypeDef *qspi)
{
    return (qspi->SR & QSPI_SR_CUROP_Msk);
}

/**
  * @brief  Get FIFO level.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetFifoLevel(QSPI_TypeDef *qspi)
{
    return ((qspi->SR & QSPI_SR_LEVEL_Msk) >> QSPI_SR_LEVEL_Pos);
}

/**
  * @brief  Get FIFO depth.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetFifoDepth(QSPI_TypeDef *qspi)
{
    return ((qspi->SR & QSPI_SR_DEPTH_Msk) >> QSPI_SR_DEPTH_Pos);
}

/**
  * @brief  Set direct mode alternate bytes.
  * @param  qspi: Select the QSPI peripheral.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void QSPI_SetDirectAlternateBytes(QSPI_TypeDef *qspi, uint32_t data)
{
    qspi->DABR = data;
}

/**
  * @brief  Get direct mode alternate bytes.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetDirectAlternateBytes(QSPI_TypeDef *qspi)
{
    return (qspi->DABR);
}

/**
  * @brief  Set indirect mode alternate bytes.
  * @param  qspi: Select the QSPI peripheral.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void QSPI_SetIndirectAlternateBytes(QSPI_TypeDef *qspi, uint32_t data)
{
    qspi->IABR = data;
}

/**
  * @brief  Get indirect mode alternate bytes.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetIndirectAlternateBytes(QSPI_TypeDef *qspi)
{
    return (qspi->IABR);
}

/**
  * @brief  Set indirect mode address.
  * @param  qspi: Select the QSPI peripheral.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void QSPI_SetIndirectAddress(QSPI_TypeDef *qspi, uint32_t data)
{
    qspi->IADR = data;
}

/**
  * @brief  Get indirect mode address.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetIndirectAddress(QSPI_TypeDef *qspi)
{
    return (qspi->IADR);
}

/**
  * @brief  Set indirect mode data length.
  * @param  qspi: Select the QSPI peripheral.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void QSPI_SetIndirectDataLength(QSPI_TypeDef *qspi, uint32_t data)
{
    qspi->IDLR = data;
}

/**
  * @brief  Get indirect mode data length.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetIndirectDataLength(QSPI_TypeDef *qspi)
{
    return (qspi->IDLR);
}

/**
  * @brief  Set indirect mode wait count.
  * @param  qspi: Select the QSPI peripheral.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void QSPI_SetIndirectWaitCount(QSPI_TypeDef *qspi, uint32_t data)
{
    qspi->IWCR = data;
}

/**
  * @brief  Get indirect mode wait count.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetIndirectWaitCount(QSPI_TypeDef *qspi)
{
    return (qspi->IWCR);
}

/**
  * @brief  Transmits a Data through the qspi fifo indirectly.
  * @param  qspi: Select the QSPI peripheral.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void QSPI_SendIndirectDataFifo(QSPI_TypeDef *qspi, uint32_t data)
{
    qspi->IDFR = data;
}

/**
  * @brief  Returns received data by the qspi fifo indirectly.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_ReceiveIndirectDataFifo(QSPI_TypeDef *qspi)
{
    return (qspi->IDFR);
}

/**
  * @brief  Checks whether the specified QSPI flag is set or not.
  * @param  qspi: Select the QSPI peripheral.
  * @param  flag: specifies the QSPI flag to check.
  *         This parameter can be one of the following values:
  * @arg    QSPI_FLAG_TCF
  * @arg    QSPI_FLAG_EMPTY
  * @arg    QSPI_FLAG_FULL
  * @arg    QSPI_FLAG_BUSY
  * @arg    QSPI_FLAG_XIP
  * @retval The new state of flag (SET or RESET).
  */
FlagStatus QSPI_GetFlagStatus(QSPI_TypeDef *qspi, uint32_t flag)
{
    return ((qspi->SR & flag) ? SET : RESET);
}

/**
  * @brief  Clears the QSPI flag.
  * @param  qspi: Select the QSPI peripheral.
  * @param  flag: specifies the QSPI flag to clear.
  *         This parameter can be one of the following values:
  * @arg    QSPI_FLAG_TCF
  * @arg    QSPI_FLAG_EMPTY
  * @retval None
  */
void QSPI_ClearFlag(QSPI_TypeDef *qspi, uint32_t flag)
{
    qspi->SR = flag;
}

/**
  * @brief  Enables or disables the specified QSPI interrupts.
  * @param  qspi: Select the QSPI peripheral.
  * @param  it: specifies the QSPI interrupt source to be enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    QSPI_DMARequest_TCF
  * @arg    QSPI_DMARequest_EMPTY
  * @arg    QSPI_DMARequest_FULL
  * @param  state: new state of the specified QSPI interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_ITConfig(QSPI_TypeDef *qspi, uint32_t it, FunctionalState state)
{
    (state) ?                   \
    (qspi->IDER |= (it >> 8)) : \
    (qspi->IDER &= ~(it >> 8));
}

/**
  * @brief  Enables or disables the specified QSPI interrupts.
  * @param  qspi: Select the QSPI peripheral.
  * @param  dmaconfig: specifies the QSPI interrupt source to be enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    QSPI_DMARequest_TCF
  * @arg    QSPI_DMARequest_EMPTY
  * @arg    QSPI_DMARequest_FULL
  * @param  state: new state of the specified QSPI interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_DMAConfig(QSPI_TypeDef *qspi, uint32_t dmaconfig, FunctionalState state)
{
    (state) ?                   \
    (qspi->IDER |= dmaconfig) : \
    (qspi->IDER &= ~dmaconfig);
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

