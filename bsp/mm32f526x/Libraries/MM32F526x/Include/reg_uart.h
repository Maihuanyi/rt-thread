/***********************************************************************************************************************
    @file     reg_uart.h
    @author   VV TEAM
    @brief    This flie contains all the UART's register and its field definition.
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

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/

#ifndef __REG_UART_H
#define __REG_UART_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief UART Base Address Definition
  */
#define  UART1_BASE                                0x40013800 /*!<Base Address: 0x40013800*/
#define  UART2_BASE                                0x40004400 /*!<Base Address: 0x40004400*/
#define  UART3_BASE                                0x40004800 /*!<Base Address: 0x40004800*/
#define  UART4_BASE                                0x40004C00 /*!<Base Address: 0x40004C00*/
#define  UART5_BASE                                0x40005000 /*!<Base Address: 0x40005000*/
#define  UART6_BASE                                0x40013C00 /*!<Base Address: 0x40013C00*/
#define  UART7_BASE                                0x40007800 /*!<Base Address: 0x40007800*/

/**
  * @brief UART Register Structure Definition
  */
typedef struct
{
    __IO uint32_t TDR;                 /*!<UART UART Transmission Data Register           offset: 0x00*/
    __IO uint32_t RDR;                 /*!<UART UART Receipt Data Register                offset: 0x04*/
    __IO uint32_t CSR;                 /*!<UART UART Current Status Register              offset: 0x08*/
    __IO uint32_t ISR;                 /*!<UART UART Interrupt Status Register            offset: 0x0C*/
    __IO uint32_t IER;                 /*!<UART UART Interrupt Enable Register            offset: 0x10*/
    __IO uint32_t ICR;                 /*!<UART UART Interrupt Clear Register             offset: 0x14*/
    __IO uint32_t GCR;                 /*!<UART UART Global Control Register              offset: 0x18*/
    __IO uint32_t CCR;                 /*!<UART UART Universal Control Register           offset: 0x1C*/
    __IO uint32_t BRR;                 /*!<UART UART Baud Rate Register                   offset: 0x20*/
    __IO uint32_t FRA;                 /*!<UART UART Fraction Baud Rate Register          offset: 0x24*/
    __IO uint32_t RXADDR;              /*!<UART UART Receipt Address Register             offset: 0x28*/
    __IO uint32_t RXMASK;              /*!<UART UART Receipt Mask Register                offset: 0x2C*/
    __IO uint32_t SCR;                 /*!<UART UART SCR Register                         offset: 0x30*/
    __IO uint32_t IDLR;                /*!<UART UART Idle Data Length Register            offset: 0x34*/
    __IO uint32_t ABRCR;               /*!<UART UART Auto Baud Rate Control Register      offset: 0x38*/
    __IO uint32_t IRDA;                /*!<UART UART Infrared Function Control Register   offset: 0x3C*/
} UART_TypeDef;

/**
  * @brief UART type pointer Definition
  */
#define UART1                                     ((UART_TypeDef *)UART1_BASE)
#define UART2                                     ((UART_TypeDef *)UART2_BASE)
#define UART3                                     ((UART_TypeDef *)UART3_BASE)
#define UART4                                     ((UART_TypeDef *)UART4_BASE)
#define UART5                                     ((UART_TypeDef *)UART5_BASE)
#define UART6                                     ((UART_TypeDef *)UART6_BASE)
#define UART7                                     ((UART_TypeDef *)UART7_BASE)

/**
  * @brief UART_TDR Register Bit Definition
  */
#define  UART_TDR_TXREG_Pos                       (0)
#define  UART_TDR_TXREG_Msk                       (0x01FFU << UART_TDR_TXREG_Pos) /*!<*/

/**
  * @brief UART_RDR Register Bit Definition
  */
#define  UART_RDR_RXREG_Pos                       (0)
#define  UART_RDR_RXREG_Msk                       (0x01FFU << UART_RDR_RXREG_Pos) /*!<*/

/**
  * @brief UART_CSR Register Bit Definition
  */
#define  UART_CSR_TXC_Pos                         (0)
#define  UART_CSR_TXC_Msk                         (0x01U << UART_CSR_TXC_Pos)    /*!<*/
#define  UART_CSR_RXAVL_Pos                       (1)
#define  UART_CSR_RXAVL_Msk                       (0x01U << UART_CSR_RXAVL_Pos)  /*!<*/
#define  UART_CSR_TXFULL_Pos                      (2)
#define  UART_CSR_TXFULL_Msk                      (0x01U << UART_CSR_TXFULL_Pos) /*!<*/
#define  UART_CSR_TXEPT_Pos                       (3)
#define  UART_CSR_TXEPT_Msk                       (0x01U << UART_CSR_TXEPT_Pos)  /*!<*/

/**
  * @brief UART_ISR Register Bit Definition
  */
#define  UART_ISR_TX_INTF_Pos                     (0)
#define  UART_ISR_TX_INTF_Msk                     (0x01U << UART_ISR_TX_INTF_Pos)     /*!<*/
#define  UART_ISR_RX_INTF_Pos                     (1)
#define  UART_ISR_RX_INTF_Msk                     (0x01U << UART_ISR_RX_INTF_Pos)     /*!<*/
#define  UART_ISR_TXC_INTF_Pos                    (2)
#define  UART_ISR_TXC_INTF_Msk                    (0x01U << UART_ISR_TXC_INTF_Pos)    /*!<*/
#define  UART_ISR_RXOERR_INTF_Pos                 (3)
#define  UART_ISR_RXOERR_INTF_Msk                 (0x01U << UART_ISR_RXOERR_INTF_Pos) /*!<*/
#define  UART_ISR_RXPERR_INTF_Pos                 (4)
#define  UART_ISR_RXPERR_INTF_Msk                 (0x01U << UART_ISR_RXPERR_INTF_Pos) /*!<*/
#define  UART_ISR_RXFERR_INTF_Pos                 (5)
#define  UART_ISR_RXFERR_INTF_Msk                 (0x01U << UART_ISR_RXFERR_INTF_Pos) /*!<*/
#define  UART_ISR_RXBRK_INTF_Pos                  (6)
#define  UART_ISR_RXBRK_INTF_Msk                  (0x01U << UART_ISR_RXBRK_INTF_Pos)  /*!<*/
#define  UART_ISR_TXBRK_INTF_Pos                  (7)
#define  UART_ISR_TXBRK_INTF_Msk                  (0x01U << UART_ISR_TXBRK_INTF_Pos)  /*!<*/
#define  UART_ISR_RXB8_INTF_Pos                   (8)
#define  UART_ISR_RXB8_INTF_Msk                   (0x01U << UART_ISR_RXB8_INTF_Pos)   /*!<*/
#define  UART_ISR_RXIDLE_INTF_Pos                 (9)
#define  UART_ISR_RXIDLE_INTF_Msk                 (0x01U << UART_ISR_RXIDLE_INTF_Pos) /*!<*/
#define  UART_ISR_ABREND_INTF_Pos                 (10)
#define  UART_ISR_ABREND_INTF_Msk                 (0x01U << UART_ISR_ABREND_INTF_Pos) /*!<*/
#define  UART_ISR_ABRERR_INTF_Pos                 (11)
#define  UART_ISR_ABRERR_INTF_Msk                 (0x01U << UART_ISR_ABRERR_INTF_Pos) /*!<*/

/**
  * @brief UART_IER Register Bit Definition
  */
#define  UART_IER_TX_IEN_Pos                      (0)
#define  UART_IER_TX_IEN_Msk                      (0x01U << UART_IER_TX_IEN_Pos)     /*!<*/
#define  UART_IER_RX_IEN_Pos                      (1)
#define  UART_IER_RX_IEN_Msk                      (0x01U << UART_IER_RX_IEN_Pos)     /*!<*/
#define  UART_IER_TXC_IEN_Pos                     (2)
#define  UART_IER_TXC_IEN_Msk                     (0x01U << UART_IER_TXC_IEN_Pos)    /*!<*/
#define  UART_IER_RXOERR_IEN_Pos                  (3)
#define  UART_IER_RXOERR_IEN_Msk                  (0x01U << UART_IER_RXOERR_IEN_Pos) /*!<*/
#define  UART_IER_RXPERR_IEN_Pos                  (4)
#define  UART_IER_RXPERR_IEN_Msk                  (0x01U << UART_IER_RXPERR_IEN_Pos) /*!<*/
#define  UART_IER_RXFERR_IEN_Pos                  (5)
#define  UART_IER_RXFERR_IEN_Msk                  (0x01U << UART_IER_RXFERR_IEN_Pos) /*!<*/
#define  UART_IER_RXBRK_IEN_Pos                   (6)
#define  UART_IER_RXBRK_IEN_Msk                   (0x01U << UART_IER_RXBRK_IEN_Pos)  /*!<*/
#define  UART_IER_TXBRK_IEN_Pos                   (7)
#define  UART_IER_TXBRK_IEN_Msk                   (0x01U << UART_IER_TXBRK_IEN_Pos)  /*!<*/
#define  UART_IER_RXB8_IEN_Pos                    (8)
#define  UART_IER_RXB8_IEN_Msk                    (0x01U << UART_IER_RXB8_IEN_Pos)   /*!<*/
#define  UART_IER_RXIDLE_IEN_Pos                  (9)
#define  UART_IER_RXIDLE_IEN_Msk                  (0x01U << UART_IER_RXIDLE_IEN_Pos) /*!<*/
#define  UART_IER_ABREND_IEN_Pos                  (10)
#define  UART_IER_ABREND_IEN_Msk                  (0x01U << UART_IER_ABREND_IEN_Pos) /*!<*/
#define  UART_IER_ABRERR_IEN_Pos                  (11)
#define  UART_IER_ABRERR_IEN_Msk                  (0x01U << UART_IER_ABRERR_IEN_Pos) /*!<*/

/**
  * @brief UART_ICR Register Bit Definition
  */
#define  UART_ICR_TX_ICLR_Pos                     (0)
#define  UART_ICR_TX_ICLR_Msk                     (0x01U << UART_ICR_TX_ICLR_Pos)     /*!<*/
#define  UART_ICR_RX_ICLR_Pos                     (1)
#define  UART_ICR_RX_ICLR_Msk                     (0x01U << UART_ICR_RX_ICLR_Pos)     /*!<*/
#define  UART_ICR_TXC_ICLR_Pos                    (2)
#define  UART_ICR_TXC_ICLR_Msk                    (0x01U << UART_ICR_TXC_ICLR_Pos)    /*!<*/
#define  UART_ICR_RXOERR_ICLR_Pos                 (3)
#define  UART_ICR_RXOERR_ICLR_Msk                 (0x01U << UART_ICR_RXOERR_ICLR_Pos) /*!<*/
#define  UART_ICR_RXPERR_ICLR_Pos                 (4)
#define  UART_ICR_RXPERR_ICLR_Msk                 (0x01U << UART_ICR_RXPERR_ICLR_Pos) /*!<*/
#define  UART_ICR_RXFERR_ICLR_Pos                 (5)
#define  UART_ICR_RXFERR_ICLR_Msk                 (0x01U << UART_ICR_RXFERR_ICLR_Pos) /*!<*/
#define  UART_ICR_RXBRK_ICLR_Pos                  (6)
#define  UART_ICR_RXBRK_ICLR_Msk                  (0x01U << UART_ICR_RXBRK_ICLR_Pos)  /*!<*/
#define  UART_ICR_TXBRK_ICLR_Pos                  (7)
#define  UART_ICR_TXBRK_ICLR_Msk                  (0x01U << UART_ICR_TXBRK_ICLR_Pos)  /*!<*/
#define  UART_ICR_RXB8_ICLR_Pos                   (8)
#define  UART_ICR_RXB8_ICLR_Msk                   (0x01U << UART_ICR_RXB8_ICLR_Pos)   /*!<*/
#define  UART_ICR_RXIDLE_ICLR_Pos                 (9)
#define  UART_ICR_RXIDLE_ICLR_Msk                 (0x01U << UART_ICR_RXIDLE_ICLR_Pos) /*!<*/
#define  UART_ICR_ABREND_ICLR_Pos                 (10)
#define  UART_ICR_ABREND_ICLR_Msk                 (0x01U << UART_ICR_ABREND_ICLR_Pos) /*!<*/
#define  UART_ICR_ABRERR_ICLR_Pos                 (11)
#define  UART_ICR_ABRERR_ICLR_Msk                 (0x01U << UART_ICR_ABRERR_ICLR_Pos) /*!<*/

/**
  * @brief UART_GCR Register Bit Definition
  */
#define  UART_GCR_UARTEN_Pos                      (0)
#define  UART_GCR_UARTEN_Msk                      (0x01U << UART_GCR_UARTEN_Pos)     /*!<*/
#define  UART_GCR_DMAMODE_Pos                     (1)
#define  UART_GCR_DMAMODE_Msk                     (0x01U << UART_GCR_DMAMODE_Pos)    /*!<*/
#define  UART_GCR_AUTOFLOWEN_Pos                  (2)
#define  UART_GCR_AUTOFLOWEN_Msk                  (0x01U << UART_GCR_AUTOFLOWEN_Pos) /*!<*/
#define  UART_GCR_RXEN_Pos                        (3)
#define  UART_GCR_RXEN_Msk                        (0x01U << UART_GCR_RXEN_Pos)       /*!<*/
#define  UART_GCR_TXEN_Pos                        (4)
#define  UART_GCR_TXEN_Msk                        (0x01U << UART_GCR_TXEN_Pos)       /*!<*/
#define  UART_GCR_SELB8_Pos                       (7)
#define  UART_GCR_SELB8_Msk                       (0x01U << UART_GCR_SELB8_Pos)      /*!<*/
#define  UART_GCR_SWAP_Pos                        (8)
#define  UART_GCR_SWAP_Msk                        (0x01U << UART_GCR_SWAP_Pos)       /*!<*/
#define  UART_GCR_RXTOG_Pos                       (9)
#define  UART_GCR_RXTOG_Msk                       (0x01U << UART_GCR_RXTOG_Pos)      /*!<*/
#define  UART_GCR_TXTOG_Pos                       (10)
#define  UART_GCR_TXTOG_Msk                       (0x01U << UART_GCR_TXTOG_Pos)      /*!<*/

/**
  * @brief UART_CCR Register Bit Definition
  */
#define  UART_CCR_PEN_Pos                         (0)
#define  UART_CCR_PEN_Msk                         (0x01U << UART_CCR_PEN_Pos)   /*!<*/
#define  UART_CCR_PSEL_Pos                        (1)
#define  UART_CCR_PSEL_Msk                        (0x01U << UART_CCR_PSEL_Pos)  /*!<*/
#define  UART_CCR_SPB0_Pos                        (2)
#define  UART_CCR_SPB0_Msk                        (0x01U << UART_CCR_SPB0_Pos)  /*!<*/
#define  UART_CCR_BRK_Pos                         (3)
#define  UART_CCR_BRK_Msk                         (0x01U << UART_CCR_BRK_Pos)   /*!<*/
#define  UART_CCR_CHAR_Pos                        (4)
#define  UART_CCR_CHAR_Msk                        (0x03U << UART_CCR_CHAR_Pos)  /*!<*/
#define  UART_CCR_SPB1_Pos                        (6)
#define  UART_CCR_SPB1_Msk                        (0x01U << UART_CCR_SPB1_Pos)  /*!<*/
#define  UART_CCR_B8RXD_Pos                       (7)
#define  UART_CCR_B8RXD_Msk                       (0x01U << UART_CCR_B8RXD_Pos) /*!<*/
#define  UART_CCR_B8TXD_Pos                       (8)
#define  UART_CCR_B8TXD_Msk                       (0x01U << UART_CCR_B8TXD_Pos) /*!<*/
#define  UART_CCR_B8POL_Pos                       (9)
#define  UART_CCR_B8POL_Msk                       (0x01U << UART_CCR_B8POL_Pos) /*!<*/
#define  UART_CCR_B8TOG_Pos                       (10)
#define  UART_CCR_B8TOG_Msk                       (0x01U << UART_CCR_B8TOG_Pos) /*!<*/
#define  UART_CCR_B8EN_Pos                        (11)
#define  UART_CCR_B8EN_Msk                        (0x01U << UART_CCR_B8EN_Pos)  /*!<*/
#define  UART_CCR_RWU_Pos                         (12)
#define  UART_CCR_RWU_Msk                         (0x01U << UART_CCR_RWU_Pos)   /*!<*/
#define  UART_CCR_WAKE_Pos                        (13)
#define  UART_CCR_WAKE_Msk                        (0x01U << UART_CCR_WAKE_Pos)  /*!<*/
#define  UART_CCR_LIN_Pos                         (14)
#define  UART_CCR_LIN_Msk                         (0x01U << UART_CCR_LIN_Pos)   /*!<*/

/**
  * @brief UART_BRR Register Bit Definition
  */
#define  UART_BRR_DIV_MANTISSA_Pos                (0)
#define  UART_BRR_DIV_MANTISSA_Msk                (0xFFFFU << UART_BRR_DIV_MANTISSA_Pos) /*!<*/

/**
  * @brief UART_FRA Register Bit Definition
  */
#define  UART_FRA_DIV_FRACTION_Pos                (0)
#define  UART_FRA_DIV_FRACTION_Msk                (0x0FU << UART_FRA_DIV_FRACTION_Pos) /*!<*/

/**
  * @brief UART_RXADDR Register Bit Definition
  */
#define  UART_RXADDR_RXADDR_Pos                   (0)
#define  UART_RXADDR_RXADDR_Msk                   (0xFFU << UART_RXADDR_RXADDR_Pos) /*!<*/

/**
  * @brief UART_RXMASK Register Bit Definition
  */
#define  UART_RXMASK_RXMASK_Pos                   (0)
#define  UART_RXMASK_RXMASK_Msk                   (0xFFU << UART_RXMASK_RXMASK_Pos) /*!<*/

/**
  * @brief UART_SCR Register Bit Definition
  */
#define  UART_SCR_SCEN_Pos                        (0)
#define  UART_SCR_SCEN_Msk                        (0x01U << UART_SCR_SCEN_Pos)   /*!<*/
#define  UART_SCR_SCAEN_Pos                       (1)
#define  UART_SCR_SCAEN_Msk                       (0x01U << UART_SCR_SCAEN_Pos)  /*!<*/
#define  UART_SCR_NACK_Pos                        (2)
#define  UART_SCR_NACK_Msk                        (0x01U << UART_SCR_NACK_Pos)   /*!<*/
#define  UART_SCR_SCFCNT_Pos                      (4)
#define  UART_SCR_SCFCNT_Msk                      (0xFFU << UART_SCR_SCFCNT_Pos) /*!<*/
#define  UART_SCR_HDSEL_Pos                       (12)
#define  UART_SCR_HDSEL_Msk                       (0x01U << UART_SCR_HDSEL_Pos)  /*!<*/

/**
  * @brief UART_IDLR Register Bit Definition
  */
#define  UART_IDLR_IDLR_Pos                       (0)
#define  UART_IDLR_IDLR_Msk                       (0xFFFFU << UART_IDLR_IDLR_Pos) /*!<*/

/**
  * @brief UART_ABRCR Register Bit Definition
  */
#define  UART_ABRCR_ABREN_Pos                     (0)
#define  UART_ABRCR_ABREN_Msk                     (0x01U << UART_ABRCR_ABREN_Pos)       /*!<*/
#define  UART_ABRCR_ABR_BITCNT_Pos                (1)
#define  UART_ABRCR_ABR_BITCNT_Msk                (0x03U << UART_ABRCR_ABR_BITCNT_Pos)  /*!<*/
#define  UART_ABRCR_FORMER_EDGE_Pos               (3)
#define  UART_ABRCR_FORMER_EDGE_Msk               (0x01U << UART_ABRCR_FORMER_EDGE_Pos) /*!<*/
#define  UART_ABRCR_LATTER_EDGE_Pos               (4)
#define  UART_ABRCR_LATTER_EDGE_Msk               (0x01U << UART_ABRCR_LATTER_EDGE_Pos) /*!<*/

/**
  * @brief UART_IRDA Register Bit Definition
  */
#define  UART_IRDA_SIREN_Pos                      (0)
#define  UART_IRDA_SIREN_Msk                      (0x01U << UART_IRDA_SIREN_Pos)   /*!<*/
#define  UART_IRDA_SIRLP_Pos                      (1)
#define  UART_IRDA_SIRLP_Msk                      (0x01U << UART_IRDA_SIRLP_Pos)   /*!<*/
#define  UART_IRDA_PSC_REG_Pos                    (8)
#define  UART_IRDA_PSC_REG_Msk                    (0xFFU << UART_IRDA_PSC_REG_Pos) /*!<*/

#endif

