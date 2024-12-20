/***********************************************************************************************************************
    @file     hal_crcpoly.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE CRCPOLY
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
#ifndef __HAL_CRCPOLY_H
#define __HAL_CRCPOLY_H

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup CRCPOLY_HAL
  * @brief CRCPOLY HAL modules
  * @{
  */

/** @defgroup CRCPOLY_Exported_Types
  * @{
  */


#define CRCPOLY_POLYLENGTH_32B      (0x00U << CRCPOLY_CR_PWIDTH_Pos)
#define CRCPOLY_POLYLENGTH_16B      (0x01U << CRCPOLY_CR_PWIDTH_Pos)
#define CRCPOLY_POLYLENGTH_8B       (0x02U << CRCPOLY_CR_PWIDTH_Pos)

#define CRCPOLY_RI_RESET            (0x00U << CRCPOLY_CR_RI_Pos)
#define CRCPOLY_RI_SET              (0x01U << CRCPOLY_CR_RI_Pos)

#define CRCPOLY_RO_RESET            (0x00U << CRCPOLY_CR_RO_Pos)
#define CRCPOLY_RO_SET              (0x01U << CRCPOLY_CR_RO_Pos)

#define CRCPOLY_IN_LITTLE_ENDIAN    (0x00U << CRCPOLY_CR_BEI_Pos)
#define CRCPOLY_IN_BIG_ENDIAN       (0x01U << CRCPOLY_CR_BEI_Pos)

#define CRCPOLY_OUT_LITTLE_ENDIAN   (0x00U << CRCPOLY_CR_BEO_Pos)
#define CRCPOLY_OUT_BIG_ENDIAN      (0x01U << CRCPOLY_CR_BEO_Pos)


/**
  * @}
  */


/** @defgroup CRCPOLY_Exported_Functions
  * @{
  */
void CRCPOLY_DeInit(void);
void CRCPOLY_ResetDR(void);

void CRCPOLY_FeedCRC32(uint32_t in_data);
void CRCPOLY_FeedCRC16(uint16_t in_data);
void CRCPOLY_FeedCRC8(uint8_t in_data);

uint32_t CRCPOLY_GetCRC32(void);
uint16_t CRCPOLY_GetCRC16(void);
uint8_t CRCPOLY_GetCRC8(void);

uint32_t CRCPOLY_CalcCRC32(uint32_t in_data);
uint16_t CRCPOLY_CalcCRC16(uint16_t in_data);
uint8_t CRCPOLY_CalcCRC8(uint8_t in_data);

uint32_t CRCPOLY_CalcBlockCRC(uint32_t *buffer, uint32_t length);
uint32_t CRCPOLY_CalcBlockCRC32(uint32_t *buffer, uint32_t length);
uint16_t CRCPOLY_CalcBlockCRC16(uint16_t *buffer, uint32_t length);
uint8_t CRCPOLY_CalcBlockCRC8(uint8_t *buffer, uint32_t length);

void CRCPOLY_SetIDRegister(uint32_t id_value);
uint32_t CRCPOLY_GetIDRegister(void);
void CRCPOLY_SetInitialValueRegister(uint32_t in_data);
uint32_t CRCPOLY_GetInitialValueRegister(void);
void CRCPOLY_SetPolynomialRegister(uint32_t in_data);
uint32_t CRCPOLY_GetPolynomialRegister(void);

void CRCPOLY_SetPolynomialSize(uint32_t width);
void CRCPOLY_SetInputDataReverseMode(uint32_t mode);
void CRCPOLY_SetOutputDataReverseMode(uint32_t mode);
void CRCPOLY_SetInputDataEndianSelectionMode(uint32_t mode);
void CRCPOLY_SetOutputDataEndianSelectionMode(uint32_t mode);

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

