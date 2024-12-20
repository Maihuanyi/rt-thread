/***********************************************************************************************************************
    @file     hal_spi.h
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
#ifndef __HAL_SPI_H
#define __HAL_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup SPI_HAL
  * @brief SPI HAL modules
  * @{
  */

/** @defgroup SPI_Exported_Types
  * @{
  */

/**
  * @brief  SPI mode definition
  */
#define SPI_Mode_Slave                      (0x00U << SPI_GCTL_MODE_Pos)   /*!< SPI slave mode */
#define SPI_Mode_Master                     (0x01U << SPI_GCTL_MODE_Pos)   /*!< SPI master mode */

/**
  * @brief  SPI data size definition
  */
#define SPI_DataSize_8b                     (0x00U << SPI_GCTL_DW8_32_Pos) /*!< 8 bits valid data */
#define SPI_DataSize_32b                    (0x01U << SPI_GCTL_DW8_32_Pos) /*!< 32 bits valid data */

/**
  * @brief  SPI clock polarity definition
  */

#define SPI_CPOL_Low                        (0x00U << SPI_CCTL_CPOL_Pos) /*!< The clock is low in idle state. */
#define SPI_CPOL_High                       (0x01U << SPI_CCTL_CPOL_Pos) /*!< The clock is high in idle state. */

/**
  * @brief  SPI clock phase definition
  */
#define SPI_CPHA_2Edge                      (0x00U << SPI_CCTL_CPHA_Pos) /*!< Data sampling starts from the second clock edge. */
#define SPI_CPHA_1Edge                      (0x01U << SPI_CCTL_CPHA_Pos) /*!< Data sampling starts from the first clock edge. */

/**
  * @brief  SPI nss control mode definition
  */
#define SPI_NSS_Soft                        (0x00U << SPI_GCTL_NSS_Pos)
#define SPI_NSS_Hard                        (0x01U << SPI_GCTL_NSS_Pos)

/**
  * @brief  SPI baud rate prescaler definition
  */
#define SPI_BaudRatePrescaler_2             0x0002                               /*!< SCK clock devide by 2 */
#define SPI_BaudRatePrescaler_4             0x0004                               /*!< SCK clock devide by 4 */
#define SPI_BaudRatePrescaler_8             0x0008                               /*!< SCK clock devide by 7 */
#define SPI_BaudRatePrescaler_16            0x0010                               /*!< SCK clock devide by 16 */
#define SPI_BaudRatePrescaler_32            0x0020                               /*!< SCK clock devide by 32 */
#define SPI_BaudRatePrescaler_64            0x0040                               /*!< SCK clock devide by 64 */
#define SPI_BaudRatePrescaler_128           0x0080                               /*!< SCK clock devide by 128 */
#define SPI_BaudRatePrescaler_256           0x0100                               /*!< SCK clock devide by 256 */
/**
  * @brief  SPI first bit definition
  */
#define SPI_FirstBit_MSB                    (0x00U << SPI_CCTL_LSBFE_Pos)        /*!< Data transfers start from MSB */
#define SPI_FirstBit_LSB                    (0x01U << SPI_CCTL_LSBFE_Pos)        /*!< Data transfers start from LSB */

/**
  * @brief  SPI bit derection definition
  */
#define SPI_Disable_RX                      (~(0x01U << SPI_GCTL_RXEN_Pos))         /*!< Receive disable */
#define SPI_Enable_RX                       (0x01U << SPI_GCTL_RXEN_Pos)          /*!< Receive enable */

#define SPI_Disable_TX                      (~(0x01U << SPI_GCTL_TXEN_Pos))         /*!< Transmit disable */
#define SPI_Enable_TX                       (0x01U << SPI_GCTL_TXEN_Pos)          /*!< Transmit enable */

/**
  * @brief  SPI flag definition
  */
#define SPI_FLAG_RXAVL                      (0x01U << SPI_CSTAT_RXAVL_Pos)       /*!< Receive 1 byte available data flag */
#define SPI_FLAG_TXEPT                      (0x01U << SPI_CSTAT_TXEPT_Pos)       /*!< Transmitter empty flag */
#define SPI_FLAG_TXFULL                     (0x01U << SPI_CSTAT_TXFULL_Pos)      /*!< Transmitter FIFO full status flag */
#define SPI_FLAG_RXAVL_4BYTE                (0x01U << SPI_CSTAT_RXAVL_4BYTE_Pos) /*!< Receive 4 bytes available data flag */

/**
  * @brief  SPI slave mode data edge adjust definition
  */
#define SPI_SlaveAdjust_LOW                 (0x00U << SPI_CCTL_TXEDGE_Pos)       /*!< SPI slave mode data edge adjust in low speed mode */
#define SPI_SlaveAdjust_FAST                (0x01U << SPI_CCTL_TXEDGE_Pos)       /*!< SPI slave mode data edge adjust in fast speed mode */

/**
  * @brief  SPI data edge adjust enum definition
  */
#define SPI_DataEdgeAdjust_LOW              0x00                                 /*!< SPI data edge adjust in low speed mode */
#define SPI_DataEdgeAdjust_FAST             0x01                                 /*!< SPI data edge adjust in fast speed mode */

/**
  * @brief  SPI interruput definition
  */

#define SPI_IT_TXEPT                        (0x01U << SPI_INTEN_TXEPT_IEN_Pos)    /*!< Transmitter empty interrupt */
#define SPI_IT_RXFULL                       (0x01U << SPI_INTEN_RXFULL_IEN_Pos)   /*!< RX FIFO full interrupt */
#define SPI_IT_RXMATCH                      (0x01U << SPI_INTEN_RXMATCH_IEN_Pos)  /*!< Receive data match the RXDNR number interrut */
#define SPI_IT_RXOERR                       (0x01U << SPI_INTEN_RXOERR_IEN_Pos)   /*!< Receive overrun error interrupt */
#define SPI_IT_UNDERRUN                     (0x01U << SPI_INTEN_UNDERRUN_IEN_Pos) /*!< Underrun interrupt */
#define SPI_IT_RX                           (0x01U << SPI_INTEN_RX_IEN_Pos)       /*!< Receive available data interrupt */
#define SPI_IT_TX                           (0x01U << SPI_INTEN_TX_IEN_Pos)       /*!< Transmit FIFO available interrupt */

/**
  * @brief  I2S standard definition
  */
#define I2S_Standard_Philips                (0x00U << SPI_I2SCFGR_I2SSTD_Pos)
#define I2S_Standard_MSB                    (0x01U << SPI_I2SCFGR_I2SSTD_Pos)
#define I2S_Standard_LSB                    (0x02U << SPI_I2SCFGR_I2SSTD_Pos)
#define I2S_Standard_PCMShort               ((0x03U << SPI_I2SCFGR_I2SSTD_Pos) | (0x00U << SPI_I2SCFGR_PCMSYNC_Pos))
#define I2S_Standard_PCMLong                ((0x03U << SPI_I2SCFGR_I2SSTD_Pos) | (0x01U << SPI_I2SCFGR_PCMSYNC_Pos))

/**
  * @brief  I2S data format definition
  */
#define I2S_DataFormat_16b                  (0x00U << SPI_I2SCFGR_CHLEN_Pos)
#define I2S_DataFormat_16bextended          (0x01U << SPI_I2SCFGR_CHLEN_Pos)
#define I2S_DataFormat_24b                  ((0x01U << SPI_I2SCFGR_DATLEN_Pos) | (0x01U << SPI_I2SCFGR_CHLEN_Pos))
#define I2S_DataFormat_32b                  ((0x02U << SPI_I2SCFGR_DATLEN_Pos) | (0x01U << SPI_I2SCFGR_CHLEN_Pos))

/**
  * @brief  I2S AUDIO FREQ definition
  */
#define I2S_AudioFreq_192k                  (192000)
#define I2S_AudioFreq_96k                   (96000)
#define I2S_AudioFreq_48k                   (48000)
#define I2S_AudioFreq_44k                   (44100)
#define I2S_AudioFreq_32k                   (32000)
#define I2S_AudioFreq_24k                   (24000)
#define I2S_AudioFreq_22k                   (22050)
#define I2S_AudioFreq_16k                   (16000)
#define I2S_AudioFreq_11k                   (11025)
#define I2S_AudioFreq_12k                   (12000)
#define I2S_AudioFreq_8k                    (8000)
#define I2S_AudioFreq_4k                    (4000)
#define I2S_AudioFreq_Default               (2)

/**
  * @brief  I2S trans mode definition
  */
#define I2S_Mode_SlaveTx                    0x0000
#define I2S_Mode_SlaveRx                    0x0100
#define I2S_Mode_MasterTx                   0x0200
#define I2S_Mode_MasterRx                   0x0300

/**
  * @brief  I2S MCK output definition
  */
#define I2S_MCKOutput_Disable               (0x00U << SPI_I2SCFGR_MCKOE_Pos)
#define I2S_MCKOutput_Enable                (0x01U << SPI_I2SCFGR_MCKOE_Pos)

/**
  * @brief  I2S CPOL definition
  */
#define I2S_CPOL_Low                        (0x00U << SPI_CCTL_CPOL_Pos) /*!< The clock is low in idle state. */
#define I2S_CPOL_High                       (0x01U << SPI_CCTL_CPOL_Pos) /*!< The clock is high in idle state. */

/**
  * @brief  I2S communication mode
  */
#define I2S_Communication_FullDuplex        (0x00U << SPI_I2SCFGR_HDSEL_Pos)
#define I2S_Communication_HalfDuplex        (0x01U << SPI_I2SCFGR_HDSEL_Pos)

/**
  * @brief  I2S MCK Output signal selection
  */
#define I2S_MCKOutput_MISO                  (0x00U << SPI_I2SCFGR_MCKSEL_Pos)
#define I2S_MCKOutput_MCK                   (0x01U << SPI_I2SCFGR_MCKSEL_Pos)

/**
  * @brief  SPI Init structure definition
  */
typedef struct
{
    uint32_t       SPI_Mode;              /*!< Specifies the SPI operating mode */
    uint32_t       SPI_DataSize;          /*!< Specifies the SPI available data size */
    uint32_t       SPI_DataWidth;         /*!< SPI data length */
    uint32_t       SPI_CPOL;              /*!< Specifies the serial clock steady state */
    uint32_t       SPI_CPHA;              /*!< Specifies the clock active edge for the bit capture */
    uint32_t       SPI_NSS;               /*!< Specifies whether the NSS signal is managed by hardware or by software */
    uint32_t       SPI_BaudRatePrescaler; /*!< Specifies the Baud Rate prescaler value which will be */
    /*!< used to configure the transmit and receive SCK clock */
    uint32_t       SPI_FirstBit;          /*!< Specifies whether data transfers start from MSB or LSB bit */
    /*  uint16_t     SPI_length; */
} SPI_InitTypeDef;

/**
  * @brief  I2S Init structure definition
  */
typedef struct
{
    uint32_t         I2S_Mode;         /*!< Specifies the I2S operating mode. */
    uint32_t         I2S_Standard;     /*!< Specifies the standard used for the I2S communication. */
    uint32_t         I2S_DataFormat;   /*!< Specifies the data format for the I2S communication. */
    uint32_t         I2S_MCKOutput;    /*!< Specifies whether the I2S MCLK output is enabled or not. */
    uint32_t         I2S_AudioFreq;    /*!< Specifies the frequency selected for the I2S communication. */
    uint32_t         I2S_CPOL;         /*!< Specifies the idle state of the I2S clock. */
} I2S_InitTypeDef;

/**
  * @brief  SPI data width definition
  */
#define SPI_DataWidth_1b                (0x01U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_2b                (0x02U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_3b                (0x03U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_4b                (0x04U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_5b                (0x05U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_6b                (0x06U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_7b                (0x07U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_8b                (0x08U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_9b                (0x09U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_10b               (0x0AU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_11b               (0x0BU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_12b               (0x0CU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_13b               (0x0DU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_14b               (0x0EU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_15b               (0x0FU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_16b               (0x10U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_17b               (0x11U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_18b               (0x12U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_19b               (0x13U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_20b               (0x14U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_21b               (0x15U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_22b               (0x16U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_23b               (0x17U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_24b               (0x18U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_25b               (0x19U << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_26b               (0x1AU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_27b               (0x1BU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_28b               (0x1CU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_29b               (0x1DU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_30b               (0x1EU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_31b               (0x1FU << SPI_EXTCTL_EXTLEN_Pos)
#define SPI_DataWidth_32b               (0x00U << SPI_EXTCTL_EXTLEN_Pos)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup SPI_Exported_Functions
  * @{
  */
void SPI_DeInit(SPI_TypeDef *spi);
void SPI_Init(SPI_TypeDef *spi, SPI_InitTypeDef *init_struct);
void SPI_StructInit(SPI_InitTypeDef *init_struct);
void SPI_Cmd(SPI_TypeDef *spi, FunctionalState state);
void SPI_DMACmd(SPI_TypeDef *spi, FunctionalState state);

void SPI_SendByte(SPI_TypeDef *spi, uint8_t data);
void SPI_SendData(SPI_TypeDef *spi, uint32_t data);
uint8_t SPI_ReceiveByte(SPI_TypeDef *spi);
uint32_t SPI_ReceiveData(SPI_TypeDef *spi);

void SPI_CSInternalSelected(SPI_TypeDef *spi, FunctionalState state);
void SPI_NSSInternalSoftwareConfig(SPI_TypeDef *spi, uint32_t nss);
bool SPI_DataSizeConfig(SPI_TypeDef *spi, uint8_t data_size);
void SPI_DataSizeTypeConfig(SPI_TypeDef *spi, uint32_t DataSize);

void SPI_BiDirectionalLineConfig(SPI_TypeDef *spi, uint32_t direction);

FlagStatus SPI_GetFlagStatus(SPI_TypeDef *spi, uint32_t flag);
ITStatus SPI_GetITStatus(SPI_TypeDef *spi, uint32_t interrupt);
void SPI_ClearITPendingBit(SPI_TypeDef *spi, uint32_t interrupt);

void SPI_RxBytes(SPI_TypeDef *spi, uint16_t number);
void SPI_SlaveAdjust(SPI_TypeDef *spi, uint32_t adjust_value);

void SPI_ITCmd(SPI_TypeDef *spi, FunctionalState state);
void SPI_ITConfig(SPI_TypeDef *spi, uint32_t interrput, FunctionalState state);

void I2S_Cmd(SPI_TypeDef *spi, FunctionalState state);
void I2S_Init(SPI_TypeDef *spi, I2S_InitTypeDef *I2S_InitStruct);
void I2S_CommunicationModeConfig(SPI_TypeDef *spi, uint32_t com_mode);
void I2S_MCKOutputConfig(SPI_TypeDef *spi, uint32_t output_sel);

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
#endif /* __HAL_SPI_H ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

