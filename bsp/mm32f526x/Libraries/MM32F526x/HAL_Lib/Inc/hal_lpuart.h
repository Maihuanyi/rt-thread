/***********************************************************************************************************************
    @file     hal_lpuart.h
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
#ifndef __HAL_LPUART_H
#define __HAL_LPUART_H

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup LPUART_HAL
  * @brief UART HAL modules
  * @{
  */

/** @defgroup LPUART_Exported_Types
  * @{
  */

typedef struct
{
    uint32_t    LPUART_BaudRate;                                               /*!< This member configures the LPUART communication baud rate. */
    uint32_t    LPUART_WordLength;                                             /*!< Specifies the number of data bits transmitted or received in a frame. */
    uint32_t    LPUART_StopBits;                                               /*!< Specifies the number of stop bits transmitted. */
    uint32_t    LPUART_Parity;                                                 /*!< Specifies the parity mode. */
    uint32_t    LPUART_ClockSource;                                            /*!< Specifies Clock Source (0, 1, 2, 3 ... ) */
    uint32_t    LPUART_MODU;                                                   /*!< Specifies the MDU value */
    uint32_t    LPUART_NEDET;                                                  /*!< Specifies Negative Detect Clock Source Ext 32K, or ... */
    uint32_t    LPUART_RecvEvent;                                              /*!< Specifies wether the receoved event mode */
} LPUART_InitTypeDef;

#define LPUART_Baudrate_9600                (0x00U << LPUART_LPUBAUD_BAUD_Pos) /*!< Baud is 9600 bps */
#define LPUART_Baudrate_4800                (0x01U << LPUART_LPUBAUD_BAUD_Pos) /*!< Baud is 4800 bps */
#define LPUART_Baudrate_2400                (0x02U << LPUART_LPUBAUD_BAUD_Pos) /*!< Baud is 2400 bps */
#define LPUART_Baudrate_1200                (0x03U << LPUART_LPUBAUD_BAUD_Pos) /*!< Baud is 1200 bps */
#define LPUART_Baudrate_600                 (0x04U << LPUART_LPUBAUD_BAUD_Pos) /*!< Baud is 600  bps */
#define LPUART_Baudrate_300                 (0x05U << LPUART_LPUBAUD_BAUD_Pos) /*!< Baud is 300  bps */

/**
  * @brief UART Word Length Enumerate definition
  * @anchor LPUART_Word_Length
  */
#define LPUART_WordLength_7b                (0x01U << LPUART_LPUCON_DL_Pos)
#define LPUART_WordLength_8b                (0x00U << LPUART_LPUCON_DL_Pos)

/**
  * @brief UART Stop Bits Enumerate definition
  * @anchor LPUART_Stop_Bits
  */
#define LPUART_StopBits_1                   (0x00U << LPUART_LPUCON_SL_Pos)
#define LPUART_StopBits_2                   (0x01U << LPUART_LPUCON_SL_Pos)

#define LPUART_Parity_No                    (0x00U << LPUART_LPUCON_PAREN_Pos)
#define LPUART_Parity_Even                  (0x01U << LPUART_LPUCON_PAREN_Pos)
#define LPUART_Parity_Odd                   ((0x01U << LPUART_LPUCON_PAREN_Pos) | (0x01U << LPUART_LPUCON_PTYP_Pos))

#define LPUART_ClockSource_LSE              (0x00U << RCC_CFGR2_LPUARTCLKSEL_Pos)
#define LPUART_ClockSource_LSI              (0x01U << RCC_CFGR2_LPUARTCLKSEL_Pos)
#define LPUART_ClockSource_PCLK             (0x02U << RCC_CFGR2_LPUARTCLKSEL_Pos)
#define LPUART_ClockSource_HSI              (0x03U << RCC_CFGR2_LPUARTCLKSEL_Pos)

/**
  * @brief UART Falling Edge Detect Enumerate definition
  */
#define LPUART_NegativeDectect_No           (0x00U << LPUART_LPUCON_NEDET_Pos)
#define LPUART_NegativeDectect_Use          (0x01U << LPUART_LPUCON_NEDET_Pos)

#define LPUART_WakeUp_ByData                (0x00U << LPUART_WKCKE_WKCKE_Pos)
#define LPUART_WakeUp_ByMatch               (0x01U << LPUART_WKCKE_WKCKE_Pos)

/**
  * @brief
  */
#define LPUART_RecvEvent_Start_Bit          (0x00U << LPUART_LPUCON_RXEV_Pos)
#define LPUART_RecvEvent_OneByte_Complete   (0x01U << LPUART_LPUCON_RXEV_Pos)
#define LPUART_RecvEvent_RecvData_Mactched  (0x02U << LPUART_LPUCON_RXEV_Pos)
#define LPUART_RecvEvent_Falling_Edge       (0x03U << LPUART_LPUCON_RXEV_Pos)

#define LPUART_IT_ERR                       (0x01U << LPUART_LPUCON_ERRIE_Pos)
#define LPUART_IT_RX                        (0x01U << LPUART_LPUCON_RXIE_Pos)
#define LPUART_IT_TC                        (0x01U << LPUART_LPUCON_TCIE_Pos)
#define LPUART_IT_TX                        (0x01U << LPUART_LPUCON_TXIE_Pos)
#define LPUART_IT_RXNEG                     (0x01U << LPUART_LPUIF_RXNEGIF_Pos)

#define LPUART_FLAG_START                   (0x01U << LPUART_LPUSTA_START_Pos)
#define LPUART_FLAG_PERR                    (0x01U << LPUART_LPUSTA_PERR_Pos)
#define LPUART_FLAG_TC                      (0x01U << LPUART_LPUSTA_TC_Pos)
#define LPUART_FLAG_TXE                     (0x01U << LPUART_LPUSTA_TXE_Pos)
#define LPUART_FLAG_RXF                     (0x01U << LPUART_LPUSTA_RXF_Pos)
#define LPUART_FLAG_MATCH                   (0x01U << LPUART_LPUSTA_MATCH_Pos)
#define LPUART_FLAG_FERR                    (0x01U << LPUART_LPUSTA_FERR_Pos)
#define LPUART_FLAG_RXOV                    (0x01U << LPUART_LPUSTA_RXOV_Pos)

/** @defgroup LPUART_Exported_Functions
  * @{
  */
void LPUART_DeInit(LPUART_TypeDef *lpuart);
void LPUART_Init(LPUART_TypeDef *lpuart, LPUART_InitTypeDef *init_struct);
void LPUART_StructInit(LPUART_InitTypeDef *init_struct);
void LPUART_Cmd(LPUART_TypeDef *lpuart, FunctionalState state);
void LPUART_TX_Cmd(LPUART_TypeDef *lpuart, FunctionalState state);
void LPUART_RX_Cmd(LPUART_TypeDef *lpuart, FunctionalState state);
void LPUART_ITConfig(LPUART_TypeDef *lpuart, uint32_t it, FunctionalState state);
void LPUART_DMACmd(LPUART_TypeDef *lpuart, FunctionalState state);
void LPUART_TX_DMACmd(LPUART_TypeDef *lpuart, FunctionalState state);
void LPUART_RX_DMACmd(LPUART_TypeDef *lpuart, FunctionalState state);
void LPUART_SendData(LPUART_TypeDef *lpuart, uint8_t value);
uint8_t LPUART_ReceiveData(LPUART_TypeDef *lpuart);
FlagStatus LPUART_GetFlagStatus(LPUART_TypeDef *lpuart, uint32_t flag);
void LPUART_ClearFlagStatus(LPUART_TypeDef *lpuart, uint32_t flag);
ITStatus LPUART_GetITStatus(LPUART_TypeDef *lpuart, uint32_t it);
void LPUART_ClearITPendingBit(LPUART_TypeDef *lpuart, uint32_t it);
void LPUART_WakeUpConfig(LPUART_TypeDef *lpuart, uint32_t mode);
void LPUART_TXToggleCmd(LPUART_TypeDef *lpuart, FunctionalState state);
void LPUART_RXToggleCmd(LPUART_TypeDef *lpuart, FunctionalState state);
void LPUART_SetMatchData(LPUART_TypeDef *lpuart, uint8_t value);

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

