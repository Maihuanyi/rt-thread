/***********************************************************************************************************************
    @file     hal_uart.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE UART
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
#ifndef __HAL_UART_H
#define __HAL_UART_H

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/**
  * @brief UART Init Structure definition
  */
typedef struct
{
    uint32_t      BaudRate;            /*!< This member configures the UART communication baud rate. */
    uint32_t      WordLength;          /*!< Specifies the number of data bits transmitted or received in a frame. */
    uint32_t      StopBits;            /*!< Specifies the number of stop bits transmitted. */
    uint32_t      Parity;              /*!< Specifies the parity mode. */
    uint32_t      Mode;                /*!< Specifies wether the Receive or Transmit mode is */
    uint32_t      HWFlowControl;       /*!< Specifies wether the hardware flow control mode is enabled or disabled. */
} UART_InitTypeDef;

/**
  * @brief UART Word Length Enumerate definition
  * @anchor UART_Word_Length
  */
#define UART_WordLength_5b                     (0x00U << UART_CCR_CHAR_Pos)
#define UART_WordLength_6b                     (0x01U << UART_CCR_CHAR_Pos)
#define UART_WordLength_7b                     (0x02U << UART_CCR_CHAR_Pos)
#define UART_WordLength_8b                     (0x03U << UART_CCR_CHAR_Pos)

/**
  * @brief UART Stop Bits Enumerate definition
  * @anchor UART_Stop_Bits
  */
#define UART_StopBits_1                        (0x00U << UART_CCR_SPB0_Pos)
#define UART_StopBits_2                        (0x01U << UART_CCR_SPB0_Pos)
#define UART_StopBits_0_5                      (0x01U << UART_CCR_SPB1_Pos)
#define UART_StopBits_1_5                      ((0x01U << UART_CCR_SPB1_Pos) | (0x01U << UART_CCR_SPB0_Pos))

/**
  * @brief UART Parity Enumerate definition
  * @anchor UART_Parity
  */
#define UART_Parity_No                         (0x00U << UART_CCR_PSEL_Pos)
#define UART_Parity_Even                       ((0x01U << UART_CCR_PEN_Pos) | (0x01U << UART_CCR_PSEL_Pos))
#define UART_Parity_Odd                        (0x01U << UART_CCR_PEN_Pos)

#define UART_Mode_Rx                           (0x01U << UART_GCR_RXEN_Pos)
#define UART_Mode_Tx                           (0x01U << UART_GCR_TXEN_Pos)

/**
  * @brief UART Hardware Flow Control Enumerate definition
  * @anchor UART_Hardware_Flow_Control
  */
#define UART_HWFlowControl_None                (0x00U << UART_GCR_AUTOFLOWEN_Pos)
#define UART_HWFlowControl_RTS_CTS             (0x01U << UART_GCR_AUTOFLOWEN_Pos)

#define UART_WakeUp_IdleLine                   (0x00U << UART_CCR_WAKE_Pos)
#define UART_WakeUp_AddressMark                (0x01U << UART_CCR_WAKE_Pos)

#define UART_9bit_Polarity_Low                 (0x00U << UART_CCR_B8POL_Pos)
#define UART_9bit_Polarity_High                (0x01U << UART_CCR_B8POL_Pos)

/**
  * @brief UART Auto BaudRate definition
  */
#define Data_F8                                (0x00U)
#define Data_FE                                (0x01U)
#define ABRMODE_FALLING_TO_RISINGEDGE1BIT      (0x02U)
#define ABRMODE_FALLING_TO_RISINGEDGE2BIT      (0x03U)
#define ABRMODE_FALLING_TO_RISINGEDGE4BIT      (0x04U)
#define ABRMODE_FALLING_TO_RISINGEDGE8BIT      (0x05U)
#define ABRMODE_FALLING_TO_FALLINGEDGE2BIT     (0x06U)
#define ABRMODE_FALLING_TO_FALLINGEDGE4BIT     (0x07U)
#define ABRMODE_FALLING_TO_FALLINGEDGE8BIT     (0x08U)
#define ABRMODE_STARTBIT                       (0x09U)
#define ABRMODE_VALUE0X55                      (0x0AU)
#define ABRMODE_VALUE0x7F                      (0x0BU)
#define ABRMODE_VALUE0X80                      (0x0CU)
#define ABRMODE_VALUE0XF7                      (0x0DU)
#define ABRMODE_VALUE0XF8                      (0x00U)
#define ABRMODE_VALUE0XFE                      (0x01U)
#define ABRMODE_VALUE0XFF                      (0x02U)

#define UART_IT_TX                             (0x01U << UART_IER_TX_IEN_Pos)
#define UART_IT_RX                             (0x01U << UART_IER_RX_IEN_Pos)
#define UART_IT_TXC                            (0x01U << UART_IER_TXC_IEN_Pos)
#define UART_IT_RXOERR                         (0x01U << UART_IER_RXOERR_IEN_Pos)
#define UART_IT_RXPERR                         (0x01U << UART_IER_RXPERR_IEN_Pos)
#define UART_IT_RXFERR                         (0x01U << UART_IER_RXFERR_IEN_Pos)
#define UART_IT_RXBRK                          (0x01U << UART_IER_RXBRK_IEN_Pos)
#define UART_IT_TXBRK                          (0x01U << UART_IER_TXBRK_IEN_Pos)
#define UART_IT_RXB8                           (0x01U << UART_IER_RXB8_IEN_Pos)
#define UART_IT_RXIDLE                         (0x01U << UART_IER_RXIDLE_IEN_Pos)
#define UART_IT_ABREND                         (0x01U << UART_IER_ABREND_IEN_Pos)
#define UART_IT_ABRERR                         (0x01U << UART_IER_ABRERR_IEN_Pos)

#define UART_FLAG_TXEPT                        (0x01U << UART_CSR_TXEPT_Pos)
#define UART_FLAG_TXFULL                       (0x01U << UART_CSR_TXFULL_Pos)
#define UART_FLAG_RXAVL                        (0x01U << UART_CSR_RXAVL_Pos)
#define UART_FLAG_TXC                          (0x01U << UART_CSR_TXC_Pos)

/**
  * @brief UART DMA transmit request definition
  */
#define UART_DMAReq_EN                         (0x01U << UART_GCR_DMAMODE_Pos)

/**
  * @brief UART_9bitLevel
  */
#define UART_9bitLevel_High                    ((uint32_t)0x00000001)               /*!<  High level */
#define UART_9bitLevel_Low                     ((uint32_t)0x00000000)               /*!<  Low level */

/**
  * @brief UART_ABRCR_ABR_BITCNT_MODE
  */
#define UART_ABRCR_ABR_BITCNT_MODE0            (0x00U << UART_ABRCR_ABR_BITCNT_Pos) /*!< Automatic baud rate length detection 1 */
#define UART_ABRCR_ABR_BITCNT_MODE1            (0x01U << UART_ABRCR_ABR_BITCNT_Pos) /*!< Automatic baud rate length detection 2 */
#define UART_ABRCR_ABR_BITCNT_MODE2            (0x02U << UART_ABRCR_ABR_BITCNT_Pos) /*!< Automatic baud rate length detection 4 */
#define UART_ABRCR_ABR_BITCNT_MODE3            (0x03U << UART_ABRCR_ABR_BITCNT_Pos) /*!< Automatic baud rate length detection 8 */

/**
  * @}
  */

/** @defgroup UART_Exported_Functions
  * @{
  */
void UART_DeInit(UART_TypeDef *uart);
void UART_Init(UART_TypeDef *uart, UART_InitTypeDef *init_struct);
void UART_StructInit(UART_InitTypeDef *init_struct);
void UART_Cmd(UART_TypeDef *uart, FunctionalState state);
void UART_ITConfig(UART_TypeDef *uart, uint32_t it, FunctionalState state);
void UART_DMACmd(UART_TypeDef *uart, uint32_t dma_request, FunctionalState state);
void UART_SendData(UART_TypeDef *uart, uint8_t Data);
uint8_t UART_ReceiveData(UART_TypeDef *uart);
FlagStatus UART_GetFlagStatus(UART_TypeDef *uart, uint32_t flag);
ITStatus UART_GetITStatus(UART_TypeDef *uart, uint32_t it);
void UART_ClearITPendingBit(UART_TypeDef *uart, uint32_t it);
void UART_WakeUpConfig(UART_TypeDef *uart, uint32_t mode);
void UART_ReceiverWakeUpCmd(UART_TypeDef *uart, FunctionalState state);
void UART_SetRXAddress(UART_TypeDef *uart, uint8_t address);
void UART_SetRXMASK(UART_TypeDef *uart, uint8_t address);
void UART_9bitCmd(UART_TypeDef *uart, FunctionalState state);
void UART_Set9bitLevel(UART_TypeDef *uart, uint32_t level);
uint32_t UART_Get9bitLevel(UART_TypeDef *uart);
void UART_Set9bitPolarity(UART_TypeDef *uart, uint32_t polarity);
void UART_9bitAutoToggleCmd(UART_TypeDef *uart, FunctionalState state);
void UART_HalfDuplexCmd(UART_TypeDef *uart, FunctionalState state);
void UART_SetGuardTime(UART_TypeDef *uart, uint8_t guard_time);
void UART_SmartCardCmd(UART_TypeDef *uart, FunctionalState state);
void UART_SmartCardNACKCmd(UART_TypeDef *uart, FunctionalState state);
void UART_SendBreak(UART_TypeDef *uart);
void UART_AutoBaudRateCmd(UART_TypeDef *uart, FunctionalState state);
void UART_TXToggleCmd(UART_TypeDef *uart, FunctionalState state);
void UART_RXToggleCmd(UART_TypeDef *uart, FunctionalState state);
void UART_AutoBaudRateSet(UART_TypeDef *uart, uint32_t value);
void UART_TxRxSWAPCmd(UART_TypeDef *uart, FunctionalState state);
void UART_TransmitCmd(UART_TypeDef *uart, FunctionalState state);
void UART_RecevieCmd(UART_TypeDef *uart, FunctionalState state);
void UART_LINCmd(UART_TypeDef *uart, FunctionalState state);
void UART_IrDACmd(UART_TypeDef *uart, FunctionalState state);
void UART_IrDALowPowerCmd(UART_TypeDef *uart, FunctionalState state);
void UART_IrDASetPscValue(UART_TypeDef *uart, uint8_t pscvalue);
void UART_IDLRConfig(UART_TypeDef *uart, uint16_t idlr);

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

