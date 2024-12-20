/***********************************************************************************************************************
    @file     hal_crcpoly.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE CRCPOLY FIRMWARE FUNCTIONS.
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
#define _HAL_CRCPOLY_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_crcpoly.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup CRCPOLY_HAL
  * @{
  */

/** @addtogroup CRCPOLY_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the CRCPOLY module clock.
  * @param  None.
  * @retval None.
  */
void CRCPOLY_DeInit(void)
{
    RCC_AHBPeriphResetCmd(RCC_AHBPeriph_CRC, ENABLE);
    RCC_AHBPeriphResetCmd(RCC_AHBPeriph_CRC, DISABLE);
}

/**
  * @brief  Resets the CRCPOLY Data register (DR).
  * @param  None.
  * @retval None.
  */
void CRCPOLY_ResetDR(void)
{
    CRCPOLY->CR |= (0x01U << CRCPOLY_CR_RST_Pos);
}

/**
  * @brief  Feed the 32-bit CRCPOLY of a given data word(32-bit).
  * @param  in_data: 32-bit value to be stored in the DR register
  * @retval None.
  */
void CRCPOLY_FeedCRC32(uint32_t in_data)
{
    CRCPOLY->DR = in_data;
}

/**
  * @brief  Feed the 16-bit CRCPOLY of a given data (16-bit).
  * @param  in_data: 16-bit value to be stored in the DR register
  * @retval None.
  */
void CRCPOLY_FeedCRC16(uint16_t in_data)
{
    *(__IO uint16_t *)(&CRCPOLY->DR) = in_data;
}

/**
  * @brief  Feed the 8-bit CRCPOLY of a given data (8-bit).
  * @param  in_data: 8-bit value to be stored in the DR register
  * @retval None.
  */
void CRCPOLY_FeedCRC8(uint8_t in_data)
{
    *(__IO uint8_t *)(&CRCPOLY->DR) = in_data;
}

/**
  * @brief  Returns the current CRCPOLY value.
  * @param  None.
  * @retval 32-bit CRCPOLY
  */
uint32_t CRCPOLY_GetCRC32(void)
{
    return (CRCPOLY->DR);
}

/**
  * @brief  Returns the current CRCPOLY value.
  * @param  None.
  * @retval 16-bit CRCPOLY
  */
uint16_t CRCPOLY_GetCRC16(void)
{
    return ((uint16_t)(CRCPOLY->DR));
}

/**
  * @brief  Returns the current CRCPOLY value.
  * @param  None.
  * @retval 8-bit CRCPOLY
  */
uint8_t CRCPOLY_GetCRC8(void)
{
    return ((uint8_t)(CRCPOLY->DR));
}

/**
  * @brief  Computes the 32-bit CRCPOLY of a given data word(32-bit).
  * @param  in_data: data word(32-bit) to compute its CRCPOLY
  * @retval 32-bit CRCPOLY
  */
uint32_t CRCPOLY_CalcCRC32(uint32_t in_data)
{
    CRCPOLY->DR = in_data;
    return (CRCPOLY->DR);
}

/**
  * @brief  Computes the 16-bit CRCPOLY of a given data (16-bit).
  * @param  in_data: data (16-bit) to compute its CRCPOLY
  * @retval 16-bit CRCPOLY
  */
uint16_t CRCPOLY_CalcCRC16(uint16_t in_data)
{
    *(__IO uint16_t *)(&CRCPOLY->DR) = in_data;

    return ((uint16_t)(CRCPOLY->DR));
}

/**
  * @brief  Computes the 8-bit CRCPOLY of a given data (8-bit).
  * @param  in_data: data (8-bit) to compute its CRCPOLY
  * @retval 8-bit CRCPOLY
  */
uint8_t CRCPOLY_CalcCRC8(uint8_t in_data)
{
    *(__IO uint8_t *)(&CRCPOLY->DR) = in_data;
    return ((uint8_t)(CRCPOLY->DR));
}

/**
  * @brief  Computes the 32-bit CRCPOLY of a given buffer of data word(32-bit).
  * @param  buffer: pointer to the buffer containing the data to be computed
  * @param  length: length of the buffer to be computed
  * @retval 32-bit CRCPOLY
  */
uint32_t CRCPOLY_CalcBlockCRC(uint32_t *buffer, uint32_t length)
{
    uint32_t i;

    for (i = 0; i < length; i++)
    {
        CRCPOLY->DR = buffer[i];
    }

    return (CRCPOLY->DR);
}

/**
  * @brief  Computes the 32-bit CRCPOLY of a given buffer of data (32-bit).
  * @param  buffer: pointer to the buffer containing the data to be computed
  * @param  length: length of the buffer to be computed
  * @retval 32-bit CRCPOLY
  */
uint32_t CRCPOLY_CalcBlockCRC32(uint32_t *buffer, uint32_t length)
{
    uint32_t i;

    for (i = 0; i < length; i++)
    {
        CRCPOLY->DR = buffer[i];
    }

    return (CRCPOLY->DR);
}

/**
  * @brief  Computes the 16-bit CRCPOLY of a given buffer of data (16-bit).
  * @param  buffer: pointer to the buffer containing the data to be computed
  * @param  length: length of the buffer to be computed
  * @retval 16-bit CRCPOLY
  */
uint16_t CRCPOLY_CalcBlockCRC16(uint16_t *buffer, uint32_t length)
{
    uint32_t i;

    for (i = 0; i < length; i++)
    {
        *(__IO uint16_t *)(&CRCPOLY->DR)  = buffer[i];
    }

    return ((uint16_t)(CRCPOLY->DR));
}

/**
  * @brief  Computes the 8-bit CRCPOLY of a given buffer of data (8-bit).
  * @param  buffer: pointer to the buffer containing the data to be computed
  * @param  length: length of the buffer to be computed
  * @retval 8-bit CRCPOLY
  */
uint8_t CRCPOLY_CalcBlockCRC8(uint8_t *buffer, uint32_t length)
{
    uint32_t i;

    for (i = 0; i < length; i++)
    {
        *(__IO uint8_t *)(&CRCPOLY->DR)  = buffer[i];
    }

    return ((uint8_t)(CRCPOLY->DR));
}

/**
  * @brief  Stores a 32-bit data in the Independent Data(ID) register.
  * @param  id_value: 32-bit value to be stored in the ID register
  * @retval None.
  */
void CRCPOLY_SetIDRegister(uint32_t id_value)
{
    CRCPOLY->IDR = id_value;
}

/**
  * @brief  Returns the 32-bit data stored in the Independent Data(ID) register
  * @param  None.
  * @retval 32-bit value of the ID register
  */
uint32_t CRCPOLY_GetIDRegister(void)
{
    return (CRCPOLY->IDR);
}

/**
  * @brief  Stores a 32-bit data in the initial value register.
  * @param  in_data: 32-bit value to be stored in the initial value register
  * @retval None.
  */
void CRCPOLY_SetInitialValueRegister(uint32_t in_data)
{
    CRCPOLY->IVR = in_data;
}

/**
  * @brief  Returns the 32-bit data stored in the initial value register
  * @param  None.
  * @retval 32-bit value of the initial value register
  */
uint32_t CRCPOLY_GetInitialValueRegister(void)
{
    return (CRCPOLY->IVR);
}

/**
  * @brief  Stores a 32-bit data in the Polynomial register.
  * @param  in_data: 32-bit value to be stored in the Polynomial register
  * @retval None.
  */
void CRCPOLY_SetPolynomialRegister(uint32_t in_data)
{
    CRCPOLY->PR = in_data;
}

/**
  * @brief  Returns the 32-bit data stored in the Polynomial register
  * @param  None.
  * @retval 32-bit value of the initial Polynomial register
  */
uint32_t CRCPOLY_GetPolynomialRegister(void)
{
    return (CRCPOLY->IVR);
}

/**
  * @brief  Configure size of the polynomial.
  * @param  width This parameter can be one of the following values:
  *         @arg CRCPOLY_POLYLENGTH_32B
  *         @arg CRCPOLY_POLYLENGTH_16B
  *         @arg CRCPOLY_POLYLENGTH_8B
  * @retval None
  */
void CRCPOLY_SetPolynomialSize(uint32_t width)
{
    MODIFY_REG(CRCPOLY->CR, CRCPOLY_CR_PWIDTH_Msk, width);
}

/**
  * @brief  Configure the reversal of the bit order of the input data
  * @param  mode This parameter can be one of the following values:
  *         @arg CRCPOLY_RI_RESET
  *         @arg CRCPOLY_RI_SET
  * @retval None
  */
void CRCPOLY_SetInputDataReverseMode(uint32_t mode)
{
    MODIFY_REG(CRCPOLY->CR, CRCPOLY_CR_RI_Msk, mode);
}

/**
  * @brief  Configure the reversal of the bit order of the Output data
  * @param  mode This parameter can be one of the following values:
  *         @arg CRCPOLY_RO_RESET
  *         @arg CRCPOLY_RO_SET
  * @retval None
  */
void CRCPOLY_SetOutputDataReverseMode(uint32_t mode)
{
    MODIFY_REG(CRCPOLY->CR, CRCPOLY_CR_RO_Msk, mode);
}

/**
  * @brief  Configure the endian of the bit order of the input data
  * @param  mode This parameter can be one of the following values:
  *         @arg CRCPOLY_IN_LITTLE_ENDIAN
  *         @arg CRCPOLY_IN_BIG_ENDIAN
  * @retval None
  */
void CRCPOLY_SetInputDataEndianSelectionMode(uint32_t mode)
{
    MODIFY_REG(CRCPOLY->CR, CRCPOLY_CR_BEI_Msk, mode);
}

/**
  * @brief  Configure the endian of the bit order of the Output data
  * @param  mode This parameter can be one of the following values:
  *         @arg CRCPOLY_OUT_LITTLE_ENDIAN
  *         @arg CRCPOLY_OUT_BIG_ENDIAN
  * @retval None
  */
void CRCPOLY_SetOutputDataEndianSelectionMode(uint32_t mode)
{
    MODIFY_REG(CRCPOLY->CR, CRCPOLY_CR_BEO_Msk, mode);
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

