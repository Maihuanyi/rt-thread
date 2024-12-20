/***********************************************************************************************************************
    @file     hal_qspi.h
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
#ifndef __HAL_QSPI_H
#define __HAL_QSPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup QSPI_HAL
  * @brief QSPI HAL modules
  * @{
  */

/** @defgroup QSPI_Exported_Types
  * @{
  */

/**
  * @brief  Delay Cycles when Sample the Input Data
  */
#define QSPI_DelayCycles_0                   (0x00U << QSPI_DMCR_RXDLY_Pos)  /*!<No sampling delay */
#define QSPI_DelayCycles_1                   (0x01U << QSPI_DMCR_RXDLY_Pos)  /*!<Add 1 sampling delay for AHB_CLK */
#define QSPI_DelayCycles_2                   (0x02U << QSPI_DMCR_RXDLY_Pos)  /*!<Add 2 sampling delays for AHB_CLK */
#define QSPI_DelayCycles_3                   (0x03U << QSPI_DMCR_RXDLY_Pos)  /*!<Add 3 sampling delays for AHB_CLK */

/**
  * @brief  QSPI Operation Mode Select
  */
#define QSPI_OperationMode_Direct            (0x00U << QSPI_CR_OPMODE_Pos)   /*!<Direct mode*/
#define QSPI_OperationMode_Reserved          (0x01U << QSPI_CR_OPMODE_Pos)   /*!<Reserved */
#define QSPI_OperationMode_Indirect          (0x02U << QSPI_CR_OPMODE_Pos)   /*!<Indirect mode */
#define QSPI_OperationMode_Inactive          (0x03U << QSPI_CR_OPMODE_Pos)   /*!<Inactive mode */

/**
  * @brief  QSPI Data Phase Size
  */
#define QSPI_DataPhaseSize_8Bit              (0x00U << QSPI_DMCR_DSIZE_Pos)  /*!<8bit */
#define QSPI_DataPhaseSize_16Bit             (0x01U << QSPI_DMCR_DSIZE_Pos)  /*!<16bit */
#define QSPI_DataPhaseSize_24Bit             (0x02U << QSPI_DMCR_DSIZE_Pos)  /*!<24bit */
#define QSPI_DataPhaseSize_32Bit             (0x03U << QSPI_DMCR_DSIZE_Pos)  /*!<32bit */

/**
  *  @brief  QSPI Data Phase Mode
  */
#define QSPI_DataPhaseMode_None              (0x00U << QSPI_DMCR_DMODE_Pos)  /*!<Reserved */
#define QSPI_DataPhaseMode_Single            (0x01U << QSPI_DMCR_DMODE_Pos)  /*!<Single-wire type */
#define QSPI_DataPhaseMode_Dual              (0x02U << QSPI_DMCR_DMODE_Pos)  /*!<Two-wire type */
#define QSPI_DataPhaseMode_Quad              (0x03U << QSPI_DMCR_DMODE_Pos)  /*!<Four-wire type */

/**
  * @brief Alternate Byte Phase Size
  */
#define QSPI_AltBytePhaseSize_8Bit           (0x00U << QSPI_DMCR_ABSIZE_Pos) /*!<8bit */
#define QSPI_AltBytePhaseSize_16Bit          (0x01U << QSPI_DMCR_ABSIZE_Pos) /*!<16bit */
#define QSPI_AltBytePhaseSize_24Bit          (0x02U << QSPI_DMCR_ABSIZE_Pos) /*!<24bit */
#define QSPI_AltBytePhaseSize_32Bit          (0x03U << QSPI_DMCR_ABSIZE_Pos) /*!<32bit */

/**
  * @brief  Alternate Byte Phase Mode
  */
#define QSPI_AltBytePhaseMode_None           (0x00U << QSPI_DMCR_ABMODE_Pos) /*!<No alternate byte phase */
#define QSPI_AltBytePhaseMode_Single         (0x01U << QSPI_DMCR_ABMODE_Pos) /*!<Single-wire type */
#define QSPI_AltBytePhaseMode_Dual           (0x02U << QSPI_DMCR_ABMODE_Pos) /*!<Two-wire type */
#define QSPI_AltBytePhaseMode_Quad           (0x03U << QSPI_DMCR_ABMODE_Pos) /*!<Four-wire type */

/**
  * @brief  QSPI Address Phase Size
  */
#define QSPI_AddressPhaseSize_8Bit           (0x00U << QSPI_DMCR_ADSIZE_Pos) /*!<Reserved */
#define QSPI_AddressPhaseSize_16Bit          (0x01U << QSPI_DMCR_ADSIZE_Pos) /*!<Reserved */
#define QSPI_AddressPhaseSize_24Bit          (0x02U << QSPI_DMCR_ADSIZE_Pos) /*!<24bit */
#define QSPI_AddressPhaseSize_32Bit          (0x03U << QSPI_DMCR_ADSIZE_Pos) /*!<32bit */

/**
  * @brief  QSPI Address Phase Mode
  */
#define QSPI_AddressPhaseMode_None           (0x00U << QSPI_DMCR_ADMODE_Pos) /*!<No-address phase */
#define QSPI_AddressPhaseMode_Single         (0x01U << QSPI_DMCR_ADMODE_Pos) /*!<Single-wire type */
#define QSPI_AddressPhaseMode_Dual           (0x02U << QSPI_DMCR_ADMODE_Pos) /*!<Two-wire type */
#define QSPI_AddressPhaseMode_Quad           (0x03U << QSPI_DMCR_ADMODE_Pos) /*!<Four-wire type */

/**
  * @brief  QSPI Instruction Phase Mode
  */
#define QSPI_InstructPhaseMode_None          (0x00U << QSPI_DMCR_IMODE_Pos)  /*!<No-instruction phase */
#define QSPI_InstructPhaseMode_Single        (0x01U << QSPI_DMCR_IMODE_Pos)  /*!<Single-wire type */
#define QSPI_InstructPhaseMode_Dual          (0x02U << QSPI_DMCR_IMODE_Pos)  /*!<Two-wire type */
#define QSPI_InstructPhaseMode_Quad          (0x03U << QSPI_DMCR_IMODE_Pos)  /*!<Four-wire type */

/**
  * @brief  QSPI Indirect Mode Access
  */
#define QSPI_IndirectModeAccess_Read         (0x00U << QSPI_IMCR_IDMODE_Pos) /*!<Read access */
#define QSPI_IndirectModeAccess_Write        (0x01U << QSPI_IMCR_IDMODE_Pos) /*!<Write access */

/**
  * @brief  QSPI Init structure definition
  */
typedef struct
{
    uint32_t  ClockPrescalar;          /*!<Specify the QSPI SCK Prescaler. */
    uint32_t  NssHighLevelHold;        /*!<Specify the QSPI NSS High Level Hold time Cycles. */
    uint32_t  ModeSelection;           /*!<Specify the SPI mode. */
} QSPI_InitTypeDef;

/**
  * @brief  SPI Mode Select
  */
#define QSPI_MODE_0   (0x00U << QSPI_CR_SCKMODE_Pos) /*!<Mode 0 */
#define QSPI_MODE_3   (0x01U << QSPI_CR_SCKMODE_Pos) /*!<Mode 3 */

/**
  * @brief  QSPI Common config structure definition
  */
typedef struct
{
    uint8_t     InstructionCode;       /*!<Instruction Code */
    uint32_t    InstructPhaseMode;     /*!<Instruction Phase Mode */
    uint32_t    AddressPhaseMode;      /*!<Address Phase Mode */
    uint32_t    AddressPhaseSize;      /*!<Address Phase Size */
    uint32_t    AltBytesPhaseMode;     /*!<Alternate Bytes Phase Mode */
    uint32_t    AltBytesPhaseSize;     /*!<Alternate Bytes Phase Size */
    uint32_t    DataPhaseMode;         /*!<Data Phase Mode */
    uint32_t    DataPhaseSize;         /*!<Data Phase Size */
    uint32_t    RxdSampleDelayCycles;  /*!<Delay AHB_CLK Cycles when Sample the Input Data */
    uint32_t    DummyPhaseCycles;      /*!<QSPI SCK Cycles at Dummy Phase */
    uint32_t    AltBytesValue;         /*!<Alternate Bytes */
} QSPI_CommonConfig_TypeDef;

/**
  * @brief  QSPI Indirect externd config structure definition
  */
typedef struct
{
    uint32_t  address;                 /*!<Indirect mode address */
    uint32_t  length;                  /*!<Indirect mode data length */
    uint32_t  count;                   /*!<Indirect mode wait count */
} QSPI_IndirectExtendConfig_TypeDef;

/**
  * @brief  QSPI DMA Request
  */
#define QSPI_DMARequest_TCF       (0x01U << QSPI_IDER_TCFDMAEN_Pos)   /*!<Transfer Complete */
#define QSPI_DMARequest_EMPTY     (0x01U << QSPI_IDER_EMPTYDMAEN_Pos) /*!<FIFO Empty */
#define QSPI_DMARequest_FULL      (0x01U << QSPI_IDER_FULLDMAEN_Pos)  /*!<FIFO Full */

/**
  * @brief  QSPI Status flag
  */
#define QSPI_FLAG_TCF             (0x01U << QSPI_SR_TCF_Pos)          /*!<Transfer Complete */
#define QSPI_FLAG_EMPTY           (0x01U << QSPI_SR_EMPTY_Pos)        /*!<FIFO Empty */
#define QSPI_FLAG_FULL            (0x01U << QSPI_SR_FULL_Pos)         /*!<FIFO Full */
#define QSPI_FLAG_BUSY            (0x01U << QSPI_SR_BUSY_Pos)         /*!<Busy status */
#define QSPI_FLAG_XIP             (0x01U << QSPI_SR_XIPST_Pos)        /*!<XIP status */

/** @defgroup QSPI_Exported_Functions
  * @{
  */
void QSPI_DeInit(QSPI_TypeDef *qspi);
void QSPI_StructInit(QSPI_InitTypeDef *init_struct);
void QSPI_Init(QSPI_TypeDef *qspi, QSPI_InitTypeDef *init_struct);
void QSPI_CommonConfigStructInit(QSPI_CommonConfig_TypeDef *init_struct);
void QSPI_DirectInit(QSPI_TypeDef *qspi, QSPI_CommonConfig_TypeDef *init_struct);
void QSPI_IndirectInit(QSPI_TypeDef *qspi, QSPI_CommonConfig_TypeDef *init_struct, QSPI_IndirectExtendConfig_TypeDef *extendconfig, uint32_t accessmode);
void QSPI_InactiveInit(QSPI_TypeDef *qspi);
void QSPI_DirectEnterXIPCmd(QSPI_TypeDef *qspi, FunctionalState state);
void QSPI_IndirectEnterXIPCmd(QSPI_TypeDef *qspi, FunctionalState state);
void QSPI_XIPFromIndirectCmd(QSPI_TypeDef *qspi, FunctionalState state);
void QSPI_SetOperationMode(QSPI_TypeDef *qspi, uint32_t mode);
uint32_t QSPI_GetOperationMode(QSPI_TypeDef *qspi);
uint32_t QSPI_GetFifoLevel(QSPI_TypeDef *qspi);
uint32_t QSPI_GetFifoDepth(QSPI_TypeDef *qspi);
void QSPI_SetDirectAlternateBytes(QSPI_TypeDef *qspi, uint32_t data);
uint32_t QSPI_GetDirectAlternateBytes(QSPI_TypeDef *qspi);
void QSPI_SetIndirectAlternateBytes(QSPI_TypeDef *qspi, uint32_t data);
uint32_t QSPI_GetIndirectAlternateBytes(QSPI_TypeDef *qspi);
void QSPI_SetIndirectAddress(QSPI_TypeDef *qspi, uint32_t data);
uint32_t QSPI_GetIndirectAddress(QSPI_TypeDef *qspi);
void QSPI_SetIndirectDataLength(QSPI_TypeDef *qspi, uint32_t data);
uint32_t QSPI_GetIndirectDataLength(QSPI_TypeDef *qspi);
void QSPI_SetIndirectWaitCount(QSPI_TypeDef *qspi, uint32_t data);
uint32_t QSPI_GetIndirectWaitCount(QSPI_TypeDef *qspi);
void QSPI_SendIndirectDataFifo(QSPI_TypeDef *qspi, uint32_t data);
uint32_t QSPI_ReceiveIndirectDataFifo(QSPI_TypeDef *qspi);

FlagStatus QSPI_GetFlagStatus(QSPI_TypeDef *qspi, uint32_t flag);
void QSPI_ClearFlag(QSPI_TypeDef *qspi, uint32_t flag);
void QSPI_ITConfig(QSPI_TypeDef *qspi, uint32_t it, FunctionalState state);
void QSPI_DMAConfig(QSPI_TypeDef *qspi, uint32_t dmaconfig, FunctionalState state);

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
#endif /* __HAL_QSPI_H -------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

