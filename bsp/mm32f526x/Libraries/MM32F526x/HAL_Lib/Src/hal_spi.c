/***********************************************************************************************************************
    @file     hal_spi.c
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
#define _HAL_SPI_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_spi.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup SPI_HAL
  * @{
  */

/** @addtogroup SPI_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the spi peripheral registers to their
  *         default reset values.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @retval None.
  */
void SPI_DeInit(SPI_TypeDef *spi)
{
    if (spi == SPI1)
    {
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1, ENABLE);
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1, DISABLE);
    }
    else if (spi == SPI2)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI2, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI2, DISABLE);
    }
    else if (spi == SPI3)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI3, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI3, DISABLE);
    }
}

/**
  * @brief  Initializes the spi peripheral according to the specified
  *         parameters in the init_struct .
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  init_struct: pointer to a SPI_InitTypeDef structure
  *         that contains the configuration information for the
  *         specified SPI peripheral.
  * @retval None.
  */
void SPI_Init(SPI_TypeDef *spi, SPI_InitTypeDef *init_struct)
{
    spi->RXDNR = 0;

    if (init_struct->SPI_DataSize == SPI_DataSize_32b)
    {
        spi->GCTL |= (0x01U << SPI_GCTL_DW8_32_Pos);
    }
    else
    {
        spi->GCTL &= ~(0x01U << SPI_GCTL_DW8_32_Pos);
    }

    MODIFY_REG(spi->GCTL, SPI_GCTL_NSS_Msk, init_struct->SPI_NSS);
    MODIFY_REG(spi->GCTL, SPI_GCTL_MODE_Msk, init_struct->SPI_Mode);
    MODIFY_REG(spi->CCTL, SPI_CCTL_LSBFE_Msk, init_struct->SPI_FirstBit);
    MODIFY_REG(spi->CCTL, SPI_CCTL_CPOL_Msk, init_struct->SPI_CPOL);
    MODIFY_REG(spi->CCTL, SPI_CCTL_CPHA_Msk, init_struct->SPI_CPHA);

    spi->CCTL |= (0x01U << SPI_CCTL_SPILEN_Pos);
    MODIFY_REG(spi->SPBRG, SPI_SPBRG_SPBRG_Msk, init_struct->SPI_BaudRatePrescaler);

    if (init_struct->SPI_DataWidth >= 32)
    {
        MODIFY_REG(spi->EXTCTL, SPI_EXTCTL_EXTLEN_Msk, 0);
    }
    else
    {
        MODIFY_REG(spi->EXTCTL, SPI_EXTCTL_EXTLEN_Msk, init_struct->SPI_DataWidth);
    }
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to a SPI_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void SPI_StructInit(SPI_InitTypeDef *init_struct)
{
    init_struct->SPI_Mode              = SPI_Mode_Slave;
    init_struct->SPI_DataSize          = SPI_DataSize_8b;
    init_struct->SPI_DataWidth         = 8;
    init_struct->SPI_CPOL              = SPI_CPOL_Low;
    init_struct->SPI_CPHA              = SPI_CPHA_1Edge;
    init_struct->SPI_NSS               = SPI_NSS_Soft;
    init_struct->SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
    init_struct->SPI_FirstBit          = SPI_FirstBit_MSB;
}

/**
  * @brief  Enables or disables the specified SPI peripheral.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  state: new state of the spi peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void SPI_Cmd(SPI_TypeDef *spi, FunctionalState state)
{
    (state) ?                                      \
    (spi->GCTL |= (0x01U << SPI_GCTL_SPIEN_Pos)) : \
    (spi->GCTL &= ~(0x01U << SPI_GCTL_SPIEN_Pos));
}

/**
  * @brief  Enables or disables the SPI DMA interface.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  state: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void SPI_DMACmd(SPI_TypeDef *spi, FunctionalState state)
{
    (state) ?                                        \
    (spi->GCTL |= (0x01U << SPI_GCTL_DMAMODE_Pos)) : \
    (spi->GCTL &= ~(0x01U << SPI_GCTL_DMAMODE_Pos));
}

/**
  * @brief  Transmits a Data through the spi peripheral.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void SPI_SendByte(SPI_TypeDef *spi, uint8_t data)
{
    spi->TXREG = (uint32_t)data;
}

/**
  * @brief  Transmits a Data through the spi peripheral.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void SPI_SendData(SPI_TypeDef *spi, uint32_t data)
{
    spi->TXREG = data;
}

/**
  * @brief  Returns the most recent received data by the spi peripheral.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @retval The value of the received data.
  */
uint8_t SPI_ReceiveByte(SPI_TypeDef *spi)
{
    return ((uint8_t)spi->RXREG);
}

/**
  * @brief  Returns the most recent received data by the spi peripheral.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @retval The value of the received data.
  */
uint32_t SPI_ReceiveData(SPI_TypeDef *spi)
{
    uint32_t temp;
    uint8_t templen;

    temp = READ_REG(spi->RXREG);

    templen = READ_REG(spi->EXTCTL);

    if (templen == 0)
    {
        templen = 32;
    }

    if (templen > 8)
    {
        temp |= (uint32_t)(READ_REG(spi->RXREG) << 8);
    }

    if (templen > 16)
    {
        temp |= (uint32_t)(READ_REG(spi->RXREG) << 16);
    }

    if (templen > 24)
    {
        temp |= (uint32_t)(READ_REG(spi->RXREG) << 24);
    }

    return (temp);
}

/**
  * @brief  Slave chip csn single by selected
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  state: new state of the selected SPI CS pin
  *         request.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void SPI_CSInternalSelected(SPI_TypeDef *spi, FunctionalState state)
{
    (state) ?                                     \
    (spi->NSSR &= ~(0x01U << SPI_NSSR_NSS_Pos)) : \
    (spi->NSSR |= (0x01U << SPI_NSSR_NSS_Pos));
}

/**
  * @brief  Configures the NSS pin control mode for the selected SPI.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  nss: specifies the SPI NSS internal state.
  *         This parameter can be one of the following values:
  * @arg    SPI_NSS_Soft: NSS pin control by software
  * @arg    SPI_NSS_Hard: NSS pin control by hardware
  * @retval None.
  */
void SPI_NSSInternalSoftwareConfig(SPI_TypeDef *spi, uint32_t nss)
{
    MODIFY_REG(spi->GCTL, SPI_GCTL_NSS_Msk, nss);
}

/**
  * @brief  Configures the data size for the selected SPI.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  data_size: specifies the SPI data size.
  *         This parameter can be one of the following values:
  *         0 to 31, 0 = 32b, 1 = 1b, 2 = 2b
  * @arg    DataSize : 0 to 31
  * @retval None.
  * @retval None.
  */
bool SPI_DataSizeConfig(SPI_TypeDef *spi, uint8_t data_size)
{
    if (data_size > 32)
    {
        return (false);
    }

    data_size  &= 0x1F;
    spi->EXTCTL = data_size;
    return (true);
}

/**
  * @brief Configures the data SizeType for the selected SPI.
  * @param spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  DataSize: selects the send and receive data register valid data.
  *         This parameter can be one of the following values:
  * @arg    SPI_DataSize_8b: 8 bits valid data
  * @arg    SPI_DataSize_32b: 32 bits valid data
  * @retval None.
  */
void SPI_DataSizeTypeConfig(SPI_TypeDef *spi, uint32_t DataSize)
{
    MODIFY_REG(spi->GCTL, SPI_GCTL_DW8_32_Msk, DataSize);
}

/**
  * @brief  Selects the data transfer direction in bi-directional mode
  *         for the specified SPI.
  * @param spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param direction: specifies the data transfer direction in
  *         bi-directional mode.
  *         This parameter can be one of the following values:
  * @arg    SPI_Direction_Tx: Selects Tx transmission direction
  * @arg    SPI_Direction_Rx: Selects Rx receive direction
  * @arg    SPI_Disable_Tx: Selects Rx receive direction
  * @arg    SPI_Disable_Rx: Selects Rx receive direction
  * @retval None.
  */
void SPI_BiDirectionalLineConfig(SPI_TypeDef *spi, uint32_t direction)
{
    if (direction == SPI_Enable_RX)
    {
        spi->GCTL |= (0x01U << SPI_GCTL_RXEN_Pos);
    }
    else if (direction == SPI_Disable_RX)
    {
        spi->GCTL &= ~(0x01U << SPI_GCTL_RXEN_Pos);
    }
    else if (direction == SPI_Enable_TX)
    {
        spi->GCTL |= (0x01U << SPI_GCTL_TXEN_Pos);
    }
    else if (direction == SPI_Disable_TX)
    {
        spi->GCTL &= ~(0x01U << SPI_GCTL_TXEN_Pos);
    }
}

/**
  * @brief  Checks whether the specified SPI flag is set or not.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  flag: specifies the SPI flag to check.
  *         This parameter can be one of the following values:
  * @arg    SPI_FLAG_RXAVL: Rx buffer has bytes flag
  * @arg    SPI_FLAG_TXEPT: Tx buffer and tx shifter empty flag
  * @arg    SPI_FLAG_TXFULL: Tx buffer full flag
  * @arg    SPI_FLAG_RXAVL_4BYTE: Receive available 4 byte data message flag.
  * @retval The new state of SPI_FLAG (SET or RESET).
  */
FlagStatus SPI_GetFlagStatus(SPI_TypeDef *spi, uint32_t flag)
{
    return ((spi->CSTAT & flag) ? SET : RESET);
}

/**
  * @brief  Checks whether the specified SPI interrupt has occurred or not.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  interrupt: specifies the SPI interrupt source to check.
  *         This parameter can be one of the following values:
  * @arg    SPI_IT_TX: Tx buffer empty interrupt
  * @arg    SPI_IT_RX: Rx buffer  interrupt
  * @arg    SPI_IT_UNDERRUN: under Error interrupt in slave mode
  * @arg    SPI_IT_RXOVER: RX OVER Error interrupt
  * @arg    SPI_IT_RXMATCH: spectials rx data numbers  interrupt
  * @arg    SPI_IT_RXFULL: Rx buffer full interrupt
  * @arg    SPI_IT_TXEPT: Tx buffer  and tx shifter empty interrupt
  * @retval The new state of SPI_IT (SET or RESET).
  */
ITStatus SPI_GetITStatus(SPI_TypeDef *spi, uint32_t interrupt)
{
    return ((spi->INTSTAT & interrupt) ? SET : RESET);
}

/**
  * @brief  Clears the spi  interrupt pending bit.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  interrupt: specifies the SPI interrupt pending bit to clear.
  * @arg    SPI_IT_TX: Tx buffer empty interrupt
  * @arg    SPI_IT_RX: Rx buffer  interrupt
  * @arg    SPI_IT_UNDERRUN: under Error interrupt in slave mode
  * @arg    SPI_IT_RXOVER: RX OVER Error interrupt
  * @arg    SPI_IT_RXMATCH: spectials rx data numbers  interrupt
  * @arg    SPI_IT_RXFULL: Rx buffer full interrupt
  * @arg    SPI_IT_TXEPT: Tx buffer  and tx shifter empty interrupt
  *         This function clears only ERR intetrrupt pending bit.
  * @retval None.
  */
void SPI_ClearITPendingBit(SPI_TypeDef *spi, uint32_t interrupt)
{
    spi->INTCLR = interrupt;
}

/**
  * @brief  SPI Hole a count Received bytes in next receive process.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  number: specifies the SPI receive Number.
  *         This parament can be 1-65535.
  *         This function can use only in SPI master single receive mode.
  * @retval None.
  */
void SPI_RxBytes(SPI_TypeDef *spi, uint16_t number)
{
    spi->RXDNR = number;
}

/**
  * @brief  slave mode tx data transmit phase adjust set.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  adjust_value: slave mode tx data transmit phase adjust enum.
  *         This parament can be :
  *         SPI_SlaveAdjust_FAST:  fast speed use
  *         SPI_SlaveAdjust_LOW:   low speed use
  *         This function can use only in SPI master single receive mode.
  * @retval None.
  */
void SPI_SlaveAdjust(SPI_TypeDef *spi, uint32_t adjust_value)
{
    MODIFY_REG(spi->CCTL, SPI_CCTL_TXEDGE_Msk, adjust_value);
}

/**
  * @brief  Enables or disables all SPI interrupts.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  state: new state of all spi interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void SPI_ITCmd(SPI_TypeDef *spi, FunctionalState state)
{
    (state) ?                                      \
    (spi->GCTL |= (0x01U << SPI_GCTL_INTEN_Pos)) : \
    (spi->GCTL &= ~(0x01U << SPI_GCTL_INTEN_Pos));
}

/**
  * @brief  Enables or disables the specified SPI interrupts.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  interrupt: specifies the SPI interrupt sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    SPI_IT_TXEPT: Transmitter empty interrupt
  * @arg    SPI_IT_RXFULL: RX FIFO full interrupt
  * @arg    SPI_IT_RXMATCH: Receive data match the RXDNR number interrupt
  * @arg    SPI_IT_RXOERR: Receive overrun error interrupt
  * @arg    SPI_IT_UNDERRUN: underrun interrupt
  * @arg    SPI_IT_RX: Receive data available interrupt
  * @arg    SPI_IT_TX: Transmit FIFO available interrupt
  * @param  state: new state of the specified spi interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void SPI_ITConfig(SPI_TypeDef *spi, uint32_t interrupt, FunctionalState state)
{
    (state) ?                   \
    (spi->INTEN |= interrupt) : \
    (spi->INTEN &= ~interrupt);
}

/**
  * @brief  Set or reset i2s
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  state: new state of Slave chip csn signal output.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2S_Cmd(SPI_TypeDef *spi, FunctionalState state)
{
    (state) ?                                              \
    (spi->I2SCFGR |= (0x01U << SPI_I2SCFGR_SPI_I2S_Pos)) : \
    (spi->I2SCFGR &= (0x01U << SPI_I2SCFGR_SPI_I2S_Pos));
}

/**
  * @brief  i2s Config
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  state: new state of Slave chip csn signal output.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2S_Init(SPI_TypeDef *spi, I2S_InitTypeDef *I2S_InitStruct)
{
    uint32_t i2sdiv = 2;
    uint32_t tmpreg = 0;
    uint32_t packetlength = 1;
    uint32_t result = 0, remainder = 0;
    uint32_t sourceclock = 0;
    RCC_ClocksTypeDef RCC_Clocks;

    if (I2S_InitStruct->I2S_AudioFreq == I2S_AudioFreq_Default)
    {
        i2sdiv = 2;
    }
    else
    {
        if (I2S_InitStruct->I2S_DataFormat == I2S_DataFormat_16b)
        {
            packetlength = 1;
        }
        else
        {
            packetlength = 2;
        }

        RCC_GetClocksFreq(&RCC_Clocks);

        if ((spi == SPI2) || (spi == SPI3))
        {
            sourceclock = RCC_Clocks.PCLK1_Frequency;
        }
        else
        {
            sourceclock = RCC_Clocks.PCLK2_Frequency;
        }

        if (I2S_InitStruct->I2S_MCKOutput == I2S_MCKOutput_Enable)
        {
            result    = (sourceclock) / (256 * (I2S_InitStruct->I2S_AudioFreq));
            remainder = (sourceclock) % (256 * (I2S_InitStruct->I2S_AudioFreq));

            if (remainder > (128 * (I2S_InitStruct->I2S_AudioFreq)))
            {
                result = result + 1;
            }

            i2sdiv = result;

            if ((i2sdiv < 2) || (i2sdiv > 0x1FF))
            {
                i2sdiv = 2;
            }
        }
        else
        {
            result    = (sourceclock) / (16 * 2 * packetlength * (I2S_InitStruct->I2S_AudioFreq));
            remainder = (sourceclock) % (16 * 2 * packetlength * (I2S_InitStruct->I2S_AudioFreq));

            if (remainder > ((16 * packetlength * (I2S_InitStruct->I2S_AudioFreq))))
            {
                result = result + 1;
            }

            if ((i2sdiv < 1) || (i2sdiv > 0x1FF))
            {
                i2sdiv = 1;
            }
        }
    }

    if (I2S_CPOL_High == I2S_InitStruct->I2S_CPOL)
    {
        spi->CCTL |= (0x01U << SPI_CCTL_CPOL_Pos);
    }
    else
    {
        spi->CCTL &= ~(0x01U << SPI_CCTL_CPOL_Pos);
    }

    spi->I2SCFGR = 0x2 << SPI_I2SCFGR_I2SDIV_Pos;

    if ((I2S_InitStruct->I2S_Mode == I2S_Mode_MasterTx) || (I2S_InitStruct->I2S_Mode == I2S_Mode_MasterRx))
    {
        spi->GCTL |= (0x01U << SPI_GCTL_MODE_Pos);
    }
    else
    {
        spi->GCTL &= ~(0x01U << SPI_GCTL_MODE_Pos);
    }

    if ((I2S_InitStruct->I2S_Mode == I2S_Mode_MasterTx) || (I2S_InitStruct->I2S_Mode == I2S_Mode_SlaveTx))
    {
        spi->GCTL |= (0x01U << SPI_GCTL_TXEN_Pos);
        spi->GCTL &= ~(0x01U << SPI_GCTL_RXEN_Pos);
    }
    else
    {
        spi->GCTL &= ~(0x01U << SPI_GCTL_TXEN_Pos);
        spi->GCTL |= (0x01U << SPI_GCTL_RXEN_Pos);
    }

    tmpreg  = 0;
    tmpreg |= (i2sdiv << SPI_I2SCFGR_I2SDIV_Pos) |
              (I2S_InitStruct->I2S_MCKOutput) |
              (0x01U << SPI_I2SCFGR_SPI_I2S_Pos) |
              (I2S_InitStruct->I2S_Standard) |
              (I2S_InitStruct->I2S_DataFormat);
    spi->I2SCFGR &= ~(0x1FFU << SPI_I2SCFGR_I2SDIV_Pos);
    spi->I2SCFGR |= tmpreg;
}

/**
  * @brief  Configure the I2S communication mode.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  com_mode: Select full duplex or half duplex mode.
  *         This parament can be :
  *         I2S_Communication_FullDuplex
  *         I2S_Communication_HalfDuplex
  * @retval None.
  */
void I2S_CommunicationModeConfig(SPI_TypeDef *spi, uint32_t com_mode)
{
    MODIFY_REG(spi->CCTL, SPI_I2SCFGR_HDSEL_Msk, com_mode);
}

/**
  * @brief  I2S MCK Output signal selection, This parameter is
  *         valid only in half duplex mode.
  * @param  spi: Select the SPI peripheral.
  *         This parameter can be one of the following values:
  *         SPI1, SPI2, SPI3.
  * @param  output_sel: Select the output pin of the signal.
  *         This parament can be :
  *         I2S_MCKOutput_MISO
  *         I2S_MCKOutput_MCK
  * @retval None.
  */
void I2S_MCKOutputConfig(SPI_TypeDef *spi, uint32_t output_sel)
{
    MODIFY_REG(spi->CCTL, SPI_I2SCFGR_MCKSEL_Msk, output_sel);
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

