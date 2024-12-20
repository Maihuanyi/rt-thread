/***********************************************************************************************************************
    @file     hal_i2c.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE I2C FIRMWARE FUNCTIONS.
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
#define _HAL_I2C_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_i2c.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup I2C_HAL
  * @{
  */

/** @addtogroup I2C_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the i2c peripheral registers to their default
  *         reset values.
  * @param  i2c: where n can be 1 or 2 to select the I2C peripheral.
  * @retval None.
  */
void I2C_DeInit(I2C_TypeDef *i2c)
{
    if (i2c == I2C1)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, DISABLE);
    }

    if (i2c == I2C2)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C2, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C2, DISABLE);
    }
}

/**
  * @brief  Initializes the i2c peripheral according to the specified
  *         parameters in the init_struct.
  * @param  i2c: select the I2C peripheral.
  * @param  init_struct: pointer to a I2C_InitTypeDef structure that
  *         contains the configuration information for the specified
  *         I2C peripheral.
  * @retval None.
  */
void I2C_Init(I2C_TypeDef *i2c, I2C_InitTypeDef *init_struct)
{
    uint32_t pclk1         = 0;
    uint32_t pclk1Period   = 0;
    uint32_t i2cPeriod     = 0;
    uint32_t SCLH          = 0;
    uint32_t SCLL          = 0;
    RCC_ClocksTypeDef RCC_ClocksStatus;

    if (init_struct->I2C_ClockSpeed < 10000)
    {
        init_struct->I2C_ClockSpeed = 10000;
    }

    RCC_GetClocksFreq(&RCC_ClocksStatus);
    pclk1       = RCC_ClocksStatus.PCLK1_Frequency;
    /* Get pclk1 period value. unit nS */
    pclk1Period = 1000000000 / pclk1;
    /* Get I2C period value. unit nS */
    i2cPeriod   = 1000000000 / init_struct->I2C_ClockSpeed;
    /* Calculate I2C clk  Low Time.  */
    SCLL = (i2cPeriod / pclk1Period) / 2;
    /* Calculate I2C clk  High Time.  */
    SCLH = (i2cPeriod - SCLL * pclk1Period) / pclk1Period;

    i2c->ENR &= ~(0x01U << I2C_ENR_ENABLE_Pos);

    if (init_struct->I2C_ClockSpeed <= 100000)
    {
        i2c->SSLR = (i2cPeriod * SCLL - i2cPeriod * 1) / i2cPeriod - 1;
        i2c->SSHR = (i2cPeriod * SCLH - i2cPeriod * 1) / i2cPeriod - 12;
    }
    else
    {
        i2c->FSLR = (i2cPeriod * SCLL - i2cPeriod * 3) / i2cPeriod - 1;
        i2c->FSHR = (i2cPeriod * SCLH - i2cPeriod * 3) / i2cPeriod - 12;
    }

    MODIFY_REG(i2c->CR, (I2C_CR_EMPINT_Msk |
                         I2C_CR_DISSLAVE_Msk |
                         I2C_CR_REPEN_Msk |
                         I2C_CR_MASTER10_Msk |
                         I2C_CR_SLAVE10_Msk |
                         I2C_CR_SPEED_Msk |
                         I2C_CR_MASTER_Msk), ((0x01U << I2C_CR_EMPINT_Pos) |
                                              ((init_struct->I2C_Mode == I2C_MODE_MASTER) ? (0x01U << I2C_CR_DISSLAVE_Pos) : (0x00U << I2C_CR_DISSLAVE_Pos)) |
                                              (0x01U << I2C_CR_REPEN_Pos) |
                                              ((init_struct->I2C_ClockSpeed <= 100000) ? I2C_SPEED_STD : I2C_SPEED_FAST) |
                                              init_struct->I2C_Mode));

    i2c->IMR  &= 0xC000;
    i2c->RXTLR = 0x00;
    i2c->TXTLR = 0x00;
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to an I2C_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void I2C_StructInit(I2C_InitTypeDef *init_struct)
{
    init_struct->I2C_Mode       = I2C_MODE_MASTER;
    init_struct->I2C_OwnAddress = I2C_OWN_ADDRESS;
    init_struct->I2C_ClockSpeed = 100000;
}

/**
  * @brief  Enables or disables the specified I2C peripheral.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the i2c peripheral. This parameter
  *         can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_Cmd(I2C_TypeDef *i2c, FunctionalState state)
{
    (state) ?                                     \
    (i2c->ENR |= (0x01U << I2C_ENR_ENABLE_Pos)) : \
    (i2c->ENR &= ~(0x01U << I2C_ENR_ENABLE_Pos));
}

/**
  * @brief  Enables or disables the specified I2C DMA requests.
  * @param  i2c: select the I2C peripheral.
  * @param  request:
  *     @arg  I2C_DMA_RXEN
  *     @arg  I2C_DMA_TXEN
  * @param  state: new state of the I2C DMA transfer.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_DMACmd(I2C_TypeDef *i2c, uint32_t request, FunctionalState state)
{
    (state) ?               \
    (i2c->DMA |= request) : \
    (i2c->DMA &= ~request);
}

/**
  * @brief  Generates i2c communication START condition.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the I2C START condition generation.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_GenerateSTART(I2C_TypeDef *i2c, FunctionalState state)
{
    (state) ?                                  \
    (i2c->CR |= (0x01U << I2C_CR_REPEN_Pos)) : \
    (i2c->CR &= ~(0x01U << I2C_CR_REPEN_Pos));
}

/**
  * @brief  Generates i2c communication STOP condition.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the I2C STOP condition generation.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_GenerateSTOP(I2C_TypeDef *i2c, FunctionalState state)
{
    i2c->ENR |= (0x01U << I2C_ENR_ABORT_Pos);

    while (i2c->ENR & I2C_ENR_ABORT_Msk)
    {
    }

    i2c->TX_ABRT;
}

/**
  * @brief  Configures the specified I2C Target Address.
  * @param  i2c: select the I2C peripheral.
  * @param  addr: specifies the 7bit I2C Target Address.
  * @retval None.
  */
void I2C_TargetAddressConfig(I2C_TypeDef *i2c, uint8_t addr)
{
    MODIFY_REG(i2c->TAR, I2C_TAR_ADDR_Msk, (addr >> 1));
}

/**
  * @brief  Enables or disables the specified I2C general call feature.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the I2C General call.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_GeneralCallCmd(I2C_TypeDef *i2c, FunctionalState state)
{
    (state) ?                                      \
    (i2c->TAR |= (0x01U << I2C_TAR_SPECIAL_Pos)) : \
    (i2c->TAR &= ~(0x01U << I2C_TAR_SPECIAL_Pos));
}

/**
  * @brief  Enables or disables the specified I2C interrupts.
  * @param  i2c: select the I2C peripheral.
  * @param  it: specifies the I2C interrupts sources to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  * @arg    I2C_IT_RX_UNDER   : Rx Buffer is empty interrupt mask
  * @arg    I2C_IT_RX_OVER    : RX  Buffer Overrun interrupt mask
  * @arg    I2C_IT_RX_FULL    : Rx buffer full interrupt mask
  * @arg    I2C_IT_TX_OVER    : TX  Buffer Overrun interrupt mask
  * @arg    I2C_IT_TX_EMPTY   : TX_FIFO empty interrupt mask
  * @arg    I2C_IT_RD_REQ     : I2C work as slave or master interrupt mask
  * @arg    I2C_IT_TX_ABRT    : TX error interrupt  mask(Master mode)
  * @arg    I2C_IT_RX_DONE    : Master not ack interrupt mask(slave mode)
  * @arg    I2C_IT_ACTIVITY   : I2C activity interrupt mask
  * @arg    I2C_IT_STOP_DET   : stop condition  interrupt mask
  * @arg    I2C_IT_START_DET  : start condition  interrupt mask
  * @arg    I2C_IT_GEN_CALL   : a general call address and ack interrupt mask
  * @param  state: new state of the specified I2C interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_ITConfig(I2C_TypeDef *i2c, uint16_t it, FunctionalState state)
{
    if (it == I2C_IT_RX_FULL)
    {
        I2C_ReadCmd(i2c);
    }

    (state) ?          \
    (i2c->IMR |= it) : \
    (i2c->IMR &= ~it);
}

/**
  * @brief  Sends a data byte through the i2c peripheral.
  * @param  i2c: select the I2C peripheral.
  * @param  dat: Byte to be transmitted..
  * @retval None.
  */
void I2C_SendData(I2C_TypeDef *i2c, uint8_t dat)
{
    i2c->DR = CMD_WRITE | dat;
}

/**
  * @brief  Returns the most recent received data by the i2c peripheral.
  * @param  i2c: select the I2C peripheral.
  * @retval The value of the received data.
  */
void I2C_ReadCmd(I2C_TypeDef *i2c)
{
    i2c->DR |= (0x01U << I2C_DR_CMD_Pos);
}

/**
  * @brief  Returns the most recent received data by the i2c peripheral.
  * @param  i2c: select the I2C peripheral.
  * @retval The value of the received data.
  */
uint8_t I2C_ReceiveData(I2C_TypeDef *i2c)
{
    return ((uint8_t)i2c->DR);
}

/**
  * @brief  Returns the last i2c Event.
  * @param  i2c: select the I2C peripheral.
  * @retval The last event
  */
uint32_t I2C_GetLastEvent(I2C_TypeDef *i2c)
{
    return ((uint32_t)i2c->RAWISR & 0x0FFF);
}

/**
  * @brief  Checks whether the last i2c Event is equal to the one passed
  *   as parameter.
  * @param  i2c: select the I2C peripheral.
  * @param  event: specifies the event to be checked.
  *   This parameter can be one of the following values:
  * @arg  I2C_EVENT_RX_UNDER : Rx Buffer is empty event
  * @arg  I2C_EVENT_RX_OVER  : RX  Buffer Overrun event
  * @arg  I2C_EVENTT_RX_FULL : Rx buffer full event
  * @arg  I2C_EVENT_TX_OVER  : TX  Buffer Overrun event
  * @arg  I2C_EVENT_TX_EMPTY : TX_FIFO empty event
  * @arg  I2C_EVENT_RD_REQ   : I2C work as slave or master event
  * @arg  I2C_EVENT_TX_ABRT  : TX error event(Master mode)
  * @arg  I2C_EVENT_RX_DONE  : Master not ack event(slave mode)
  * @arg  I2C_EVENT_ACTIVITY : I2C activity event
  * @arg  I2C_EVENT_STOP_DET : stop condition  event
  * @arg  I2C_EVENT_START_DET: start condition  event
  * @arg  I2C_EVENT_GEN_CALL : a general call address and ack event
  * - SUCCESS: Last event is equal to the I2C_EVENT
  * - ERROR: Last event is different from the I2C_EVENT
  */
ErrorStatus I2C_CheckEvent(I2C_TypeDef *i2c, uint32_t event)
{
    return ((ErrorStatus)((i2c->RAWISR & event) == event));
}

/**
  * @brief  Checks whether the specified I2C flag is set or not.
  * @param  i2c: select the I2C peripheral.
  * @param  flag: specifies the flag to check.
  *   This parameter can be one of the following values:
  * @arg  I2C_FLAG_RX_UNDER : Rx Buffer is empty flag
  * @arg  I2C_FLAG_RX_OVER  : RX  Buffer Overrun flag
  * @arg  I2C_FLAG_RX_FULL  : Rx buffer full flag
  * @arg  I2C_FLAG_TX_OVER  : TX  Buffer Overrun flag
  * @arg  I2C_FLAG_TX_EMPTY : TX_FIFO empty flag
  * @arg  I2C_FLAG_RD_REQ   : I2C work as slave or master flag
  * @arg  I2C_FLAG_TX_ABRT  : TX error flag(Master mode)
  * @arg  I2C_FLAG_RX_DONE  : Master not ack flag(slave mode)
  * @arg  I2C_FLAG_ACTIVITY : I2C activity flag
  * @arg  I2C_FLAG_STOP_DET : stop condition  flag
  * @arg  I2C_FLAG_START_DET: start condition  flag
  * @arg  I2C_FLAG_GEN_CALL : a general call address and ack flag
  * @arg I2C_STATUS_FLAG_ACTIVITY
  * @arg I2C_STATUS_FLAG_TFNF
  * @arg I2C_STATUS_FLAG_TFE
  * @arg I2C_STATUS_FLAG_RFNE
  * @arg I2C_STATUS_FLAG_RFF
  * @arg I2C_STATUS_FLAG_M_ACTIVITY
  * @arg I2C_STATUS_FLAG_S_ACTIVITY
  * @retval The new state of I2C_FLAG (SET or RESET).
  */
FlagStatus I2C_GetFlagStatus(I2C_TypeDef *i2c, uint32_t flag)
{
    if (flag & 0x8000)
    {
        return ((i2c->SR & (flag & 0x7FFF)) ? SET : RESET);
    }
    else
    {
        return (((i2c->RAWISR & flag)) ? SET : RESET);
    }
}

/**
  * @brief  Clears the i2c's pending flags.
  * @param  i2c: select the I2C peripheral.
  * @param  flag: specifies the flag to clear.
  *   This parameter can be any combination of the following values:
  * @arg  I2C_FLAG_RX_UNDER : Rx Buffer is empty flag
  * @arg  I2C_FLAG_RX_OVER  : RX  Buffer Overrun flag
  * @arg  I2C_FLAG_RX_FULL  : Rx buffer full flag
  * @arg  I2C_FLAG_TX_OVER  : TX  Buffer Overrun flag
  * @arg  I2C_FLAG_TX_EMPTY : TX_FIFO empty flag
  * @arg  I2C_FLAG_RD_REQ   : I2C work as slave or master flag
  * @arg  I2C_FLAG_TX_ABRT  : TX error flag(Master mode)
  * @arg  I2C_FLAG_RX_DONE  : Master not ack flag(slave mode)
  * @arg  I2C_FLAG_ACTIVITY : I2C activity flag
  * @arg  I2C_FLAG_STOP_DET : stop condition  flag
  * @arg  I2C_FLAG_START_DET: start condition  flag
  * @arg  I2C_FLAG_GEN_CALL : a general call address and ack flag
  * @retval None.
  */
void I2C_ClearFlag(I2C_TypeDef *i2c, uint32_t flag)
{
    __IO uint32_t temp = 0;

    if ((flag & I2C_FLAG_RX_UNDER) == I2C_FLAG_RX_UNDER)
    {
        temp = i2c->RX_UNDER;
    }

    if ((flag & I2C_FLAG_RX_OVER) == I2C_FLAG_RX_OVER)
    {
        temp = i2c->RX_OVER;
    }

    if ((flag & I2C_FLAG_TX_OVER) == I2C_FLAG_TX_OVER)
    {
        temp = i2c->TX_OVER;
    }

    if ((flag & I2C_FLAG_RD_REQ) == I2C_FLAG_RD_REQ)
    {
        temp = i2c->RD_REQ;
    }

    if ((flag & I2C_FLAG_TX_ABRT) == I2C_FLAG_TX_ABRT)
    {
        temp = i2c->TX_ABRT;
    }

    if ((flag & I2C_FLAG_RX_DONE) == I2C_FLAG_RX_DONE)
    {
        temp = i2c->RX_DONE;
    }

    if ((flag & I2C_FLAG_ACTIVITY) == I2C_FLAG_ACTIVITY)
    {
        temp = i2c->ACTIV;
    }

    if ((flag & I2C_FLAG_STOP_DET) == I2C_FLAG_STOP_DET)
    {
        temp = i2c->STOP;
    }

    if ((flag & I2C_FLAG_START_DET) == I2C_FLAG_START_DET)
    {
        temp = i2c->START;
    }

    if ((flag & I2C_FLAG_GEN_CALL) == I2C_FLAG_GEN_CALL)
    {
        temp = i2c->GC;
    }

    temp += 1;
}

/**
  * @brief  Checks whether the specified I2C interrupt has occurred or not.
  * @param  i2c: select the I2C peripheral.
  * @param  it: specifies the interrupt source to check.
  *   This parameter can be one of the following values:
  * @arg  I2C_IT_RX_UNDER : Rx Buffer is empty interrupt
  * @arg  I2C_IT_RX_OVER  : RX  Buffer Overrun interrupt
  * @arg  I2C_IT_RX_FULL  : Rx buffer full interrupt
  * @arg  I2C_IT_TX_OVER  : TX  Buffer Overrun interrupt
  * @arg  I2C_IT_TX_EMPTY : TX_FIFO empty interrupt
  * @arg  I2C_IT_RD_REQ   : I2C work as slave or master interrupt
  * @arg  I2C_IT_TX_ABRT  : TX error interrupt  (Master mode)
  * @arg  I2C_IT_RX_DONE  : Master not ack interrupt (slave mode)
  * @arg  I2C_IT_ACTIVITY : I2C activity interrupt
  * @arg  I2C_IT_STOP_DET : stop condition  interrupt
  * @arg  I2C_IT_START_DET: start condition  interrupt
  * @arg  I2C_IT_GEN_CALL : a general call address and ack interrupt
  * @retval The new state of I2C_IT (SET or RESET).
  */
ITStatus I2C_GetITStatus(I2C_TypeDef *i2c, uint32_t it)
{
    return ((i2c->RAWISR & it) ? SET : RESET);
}

/**
  * @brief  Clears the i2c interrupt pending bits.
  * @param  i2c: select the I2C peripheral.
  * @param  it: specifies the interrupt pending bit to clear.
  *   This parameter can be any combination of the following values:
  * @arg  I2C_IT_RX_UNDER : Rx Buffer is empty interrupt
  * @arg  I2C_IT_RX_OVER  : RX  Buffer Overrun interrupt
  * @arg  I2C_IT_RX_FULL  : Rx buffer full interrupt
  * @arg  I2C_IT_TX_OVER  : TX  Buffer Overrun interrupt
  * @arg  I2C_IT_TX_EMPTY : TX_FIFO empty interrupt
  * @arg  I2C_IT_RD_REQ   : I2C work as slave or master interrupt
  * @arg  I2C_IT_TX_ABRT  : TX error interrupt  (Master mode)
  * @arg  I2C_IT_RX_DONE  : Master not ack interrupt (slave mode)
  * @arg  I2C_IT_ACTIVITY : I2C activity interrupt
  * @arg  I2C_IT_STOP_DET : stop condition  interrupt
  * @arg  I2C_IT_START_DET: start condition  interrupt
  * @arg  I2C_IT_GEN_CALL : a general call address and ack interrupt
  * @retval None.
  */
void I2C_ClearITPendingBit(I2C_TypeDef *i2c, uint32_t it)
{
    if ((it & I2C_IT_RX_UNDER) == I2C_FLAG_RX_UNDER)
    {
        i2c->RX_UNDER;
    }

    if ((it & I2C_IT_RX_OVER) == I2C_FLAG_RX_OVER)
    {
        i2c->RX_OVER;
    }

    if ((it & I2C_IT_TX_OVER) == I2C_FLAG_TX_OVER)
    {
        i2c->TX_OVER;
    }

    if ((it & I2C_IT_RD_REQ) == I2C_FLAG_RD_REQ)
    {
        i2c->RD_REQ;
    }

    if ((it & I2C_IT_TX_ABRT) == I2C_FLAG_TX_ABRT)
    {
        i2c->TX_ABRT;
    }

    if ((it & I2C_IT_RX_DONE) == I2C_FLAG_RX_DONE)
    {
        i2c->RX_DONE;
    }

    if ((it & I2C_IT_ACTIVITY) == I2C_FLAG_ACTIVITY)
    {
        i2c->ACTIV;
    }

    if ((it & I2C_IT_STOP_DET) == I2C_FLAG_STOP_DET)
    {
        i2c->STOP;
    }

    if ((it & I2C_IT_START_DET) == I2C_FLAG_START_DET)
    {
        i2c->START;
    }

    if ((it & I2C_IT_GEN_CALL) == I2C_FLAG_GEN_CALL)
    {
        i2c->GC;
    }
}

/**
  * @brief  Configures slave address.
  * @param  i2c: select the I2C peripheral.
  * @param  addr: specifies the slave address which will be transmitted
  *   This parameter can be one of the following values
  * @retval None.
  */
void I2C_SlaveAddressConfig(I2C_TypeDef *i2c, uint8_t addr)
{
    MODIFY_REG(i2c->SAR, I2C_SAR_ADDR_Msk, (addr >> 1));
}

/**
  * @brief  Enables or disables the I2C slave mode.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the specified I2C interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_SlaveModeCmd(I2C_TypeDef *i2c, FunctionalState state)
{
    (state) ?                                     \
    (i2c->CR |= (0x01U << I2C_CR_DISSLAVE_Pos)) : \
    (i2c->CR &= ~(0x01U << I2C_CR_DISSLAVE_Pos));
}

/**
  * @brief  Configures slave address mask.
  * @param  i2c: select the I2C peripheral.
  * @param  mask: specifies the slave address mask
  * @retval None.
  */
void I2C_SlaveAddressMaskConfig(I2C_TypeDef *i2c, uint16_t  mask)
{
    MODIFY_REG(i2c->SLVMASK, I2C_SLVMASK_MASK_Msk, (mask << I2C_SLVMASK_MASK_Pos));
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

