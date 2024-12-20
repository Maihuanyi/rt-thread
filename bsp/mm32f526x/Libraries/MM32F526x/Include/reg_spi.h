/***********************************************************************************************************************
    @file     reg_spi.h
    @author   VV TEAM
    @brief    This flie contains all the SPI's register and its field definition.
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

#ifndef __REG_SPI_H
#define __REG_SPI_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief SPI Base Address Definition
  */
#define  SPI1_BASE                                 0x40013000 /*!<Base Address: 0x40013000*/
#define  SPI2_BASE                                 0x40003800 /*!<Base Address: 0x40003800*/
#define  SPI3_BASE                                 0x40003C00 /*!<Base Address: 0x40003C00*/

/**
  * @brief SPI Register Structure Definition
  */
typedef struct
{
    __IO uint32_t TXREG;               /*!< SPI transmit data register,                    offset: 0x00 */
    __IO uint32_t RXREG;               /*!< SPI receive data register,                     offset: 0x04 */
    __IO uint32_t CSTAT;               /*!< SPI current state register,                    offset: 0x08 */
    __IO uint32_t INTSTAT;             /*!< SPI interruput state register,                 offset: 0x0C */
    __IO uint32_t INTEN;               /*!< SPI interruput enable register,                offset: 0x10 */
    __IO uint32_t INTCLR;              /*!< SPI interruput control register,               offset: 0x14 */
    __IO uint32_t GCTL;                /*!< SPI global control register,                   offset: 0x18 */
    __IO uint32_t CCTL;                /*!< SPI common control register,                   offset: 0x1C */
    __IO uint32_t SPBRG;               /*!< SPI baud rate control register,                offset: 0x20 */
    __IO uint32_t RXDNR;               /*!< SPI receive data number register,              offset: 0x24 */
    __IO uint32_t NSSR;                /*!< SPI chip select register,                      offset: 0x28 */
    __IO uint32_t EXTCTL;              /*!< SPI extand control register,                   offset: 0x2C */
    __IO uint32_t I2SCFGR;             /*!< I2S configuration register,                    offset: 0x30 */
} SPI_TypeDef;

/**
  * @brief SPI type pointer Definition
  */
#define SPI3                            ((SPI_TypeDef *)SPI3_BASE)
#define SPI2                            ((SPI_TypeDef *)SPI2_BASE)
#define SPI1                            ((SPI_TypeDef *)SPI1_BASE)

/**
  * @brief SPI_TXREG Register Bit Definition
  */
#define SPI_TXREG_TXREG_Pos             (0)
#define SPI_TXREG_TXREG_Msk             (0xFFFFFFFFU << SPI_TXREG_TXREG_Pos) /*!< Transmit data register */

/**
  * @brief SPI_RXREG Register Bit Definition
  */
#define SPI_RXREG_RXREG_Pos             (0)
#define SPI_RXREG_RXREG_Msk             (0xFFFFFFFFU << SPI_RXREG_RXREG_Pos) /*!< Receive data register */

/**
  * @brief SPI_CSTAT Register Bit Definition
  */
#define SPI_CSTAT_TXEPT_Pos             (0)
#define SPI_CSTAT_TXEPT                 (0x01U << SPI_CSTAT_TXEPT_Pos)       /*!< Transmitter empty bit */
#define SPI_CSTAT_RXAVL_Pos             (1)
#define SPI_CSTAT_RXAVL                 (0x01U << SPI_CSTAT_RXAVL_Pos)       /*!< Receive available byte data message */
#define SPI_CSTAT_TXFULL_Pos            (2)
#define SPI_CSTAT_TXFULL                (0x01U << SPI_CSTAT_TXFULL_Pos)      /*!< Transmitter FIFO full status bit */
#define SPI_CSTAT_RXAVL_4BYTE_Pos       (3)
#define SPI_CSTAT_RXAVL_4BYTE           (0x01U << SPI_CSTAT_RXAVL_4BYTE_Pos) /*!< Receive available 4 byte data message */
#define SPI_CSTAT_TXFADDR_Pos           (4)
#define SPI_CSTAT_TXFADDR               (0x0FU << SPI_CSTAT_TXFADDR_Pos)     /*!< Transmit FIFO address */
#define SPI_CSTAT_RXFADDR_Pos           (8)
#define SPI_CSTAT_RXFADDR               (0x0FU << SPI_CSTAT_RXFADDR_Pos)     /*!< Receive FIFO address */
#define SPI_CSTAT_BUSY_Pos              (12)
#define SPI_CSTAT_BUSY                  (0x01U << SPI_CSTAT_BUSY_Pos)        /*!< Data transfer flag */
#define SPI_CSTAT_CHSIDE_Pos            (13)
#define SPI_CSTAT_CHSIDE                (0x01U << SPI_CSTAT_CHSIDE_Pos)      /*!< transmission channel */

/**
  * @brief SPI_INTSTAT Register Bit Definition
  */
#define SPI_INTSTAT_TX_INTF_Pos         (0)
#define SPI_INTSTAT_TX_INTF             (0x01U << SPI_INTSTAT_TX_INTF_Pos)       /*!< Transmit FIFO available interrupt flag bit */
#define SPI_INTSTAT_RX_INTF_Pos         (1)
#define SPI_INTSTAT_RX_INTF             (0x01U << SPI_INTSTAT_RX_INTF_Pos)       /*!< Receive data available interrupt flag bit */
#define SPI_INTSTAT_UNDERRUN_INTF_Pos   (2)
#define SPI_INTSTAT_UNDERRUN_INTF       (0x01U << SPI_INTSTAT_UNDERRUN_INTF_Pos) /*!< SPI underrun interrupt flag bit */
#define SPI_INTSTAT_RXOERR_INTF_Pos     (3)
#define SPI_INTSTAT_RXOERR_INTF         (0x01U << SPI_INTSTAT_RXOERR_INTF_Pos)   /*!< Receive overrun error interrupt flag bit */
#define SPI_INTSTAT_RXMATCH_INTF_Pos    (4)
#define SPI_INTSTAT_RXMATCH_INTF        (0x01U << SPI_INTSTAT_RXMATCH_INTF_Pos)  /*!< Receive data match the RXDNR number, the receive process will be completed and generate the interrupt */
#define SPI_INTSTAT_RXFULL_INTF_Pos     (5)
#define SPI_INTSTAT_RXFULL_INTF         (0x01U << SPI_INTSTAT_RXFULL_INTF_Pos)   /*!< RX FIFO full interrupt flag bit */
#define SPI_INTSTAT_TXEPT_INTF_Pos      (6)
#define SPI_INTSTAT_TXEPT_INTF          (0x01U << SPI_INTSTAT_TXEPT_INTF_Pos)    /*!< Transmitter empty interrupt flag bit */
#define SPI_INTSTAT_FRE_INTF_Pos        (7)
#define SPI_INTSTAT_FRE_INTF            (0x01U << SPI_INTSTAT_FRE_INTF_Pos)      /*!< I2S frame transmission error flag bit */

/**
  * @brief SPI_INTEN Register Bit Definition
  */
#define SPI_INTEN_TX_IEN_Pos            (0)
#define SPI_INTEN_TX_IEN                (0x01U << SPI_INTEN_TX_IEN_Pos)       /*!< Transmit FIFO empty interrupt enable bit */
#define SPI_INTEN_RX_IEN_Pos            (1)
#define SPI_INTEN_RX_IEN                (0x01U << SPI_INTEN_RX_IEN_Pos)       /*!< Receive FIFO interrupt enable bit */
#define SPI_INTEN_UNDERRUN_IEN_Pos      (2)
#define SPI_INTEN_UNDERRUN_IEN          (0x01U << SPI_INTEN_UNDERRUN_IEN_Pos) /*!< Transmitter underrun interrupt enable bit */
#define SPI_INTEN_RXOERR_IEN_Pos        (3)
#define SPI_INTEN_RXOERR_IEN            (0x01U << SPI_INTEN_RXOERR_IEN_Pos)   /*!< Overrun error interrupt enable bit */
#define SPI_INTEN_RXMATCH_IEN_Pos       (4)
#define SPI_INTEN_RXMATCH_IEN           (0x01U << SPI_INTEN_RXMATCH_IEN_Pos)  /*!< Receive data complete interrupt enable bit */
#define SPI_INTEN_RXFULL_IEN_Pos        (5)
#define SPI_INTEN_RXFULL_IEN            (0x01U << SPI_INTEN_RXFULL_IEN_Pos)   /*!< Receive FIFO full interrupt enable bit */
#define SPI_INTEN_TXEPT_IEN_Pos         (6)
#define SPI_INTEN_TXEPT_IEN             (0x01U << SPI_INTEN_TXEPT_IEN_Pos)    /*!< Transmit empty interrupt enable bit */
#define SPI_INTEN_FRE_IEN_Pos           (7)
#define SPI_INTEN_FRE_IEN               (0x01U << SPI_INTEN_FRE_IEN_Pos)      /*!< I2S frame transmission interrupt enable bit */

/**
  * @brief SPI_INTCLR Register Bit Definition
  */
#define SPI_INTCLR_TX_ICLR_Pos          (0)
#define SPI_INTCLR_TX_ICLR              (0x01U << SPI_INTCLR_TX_ICLR_Pos)       /*!< Transmitter FIFO empty interrupt clear bit */
#define SPI_INTCLR_RX_ICLR_Pos          (1)
#define SPI_INTCLR_RX_ICLR              (0x01U << SPI_INTCLR_RX_ICLR_Pos)       /*!< Receive interrupt clear bit */
#define SPI_INTCLR_UNDERRUN_ICLR_Pos    (2)
#define SPI_INTCLR_UNDERRUN_ICLR        (0x01U << SPI_INTCLR_UNDERRUN_ICLR_Pos) /*!< Transmitter underrun interrupt clear bit */
#define SPI_INTCLR_RXOERR_ICLR_Pos      (3)
#define SPI_INTCLR_RXOERR_ICLR          (0x01U << SPI_INTCLR_RXOERR_ICLR_Pos)   /*!< Overrun error interrupt clear bit */
#define SPI_INTCLR_RXMATCH_ICLR_Pos     (4)
#define SPI_INTCLR_RXMATCH_ICLR         (0x01U << SPI_INTCLR_RXMATCH_ICLR_Pos)  /*!< Receive completed interrupt clear bit */
#define SPI_INTCLR_RXFULL_ICLR_Pos      (5)
#define SPI_INTCLR_RXFULL_ICLR          (0x01U << SPI_INTCLR_RXFULL_ICLR_Pos)   /*!< Receiver buffer full interrupt clear bit */
#define SPI_INTCLR_TXEPT_ICLR_Pos       (6)
#define SPI_INTCLR_TXEPT_ICLR           (0x01U << SPI_INTCLR_TXEPT_ICLR_Pos)    /*!< Transmitter empty interrupt clear bit */
#define SPI_INTCLR_FRE_ICLR_Pos         (7)
#define SPI_INTCLR_FRE_ICLR             (0x01U << SPI_INTCLR_FRE_ICLR_Pos)      /*!< I2S frame transmission interrupt clear bit */

/**
  * @brief SPI_GCTL Register Bit Definition
  */
#define SPI_GCTL_SPIEN_Pos              (0)
#define SPI_GCTL_SPIEN_Msk              (0x01U << SPI_GCTL_SPIEN_Pos)   /*!< SPI select bit */
#define SPI_GCTL_INTEN_Pos              (1)
#define SPI_GCTL_INTEN_Msk              (0x01U << SPI_GCTL_INTEN_Pos)   /*!< SPI interrupt enable bit */
#define SPI_GCTL_MODE_Pos               (2)
#define SPI_GCTL_MODE_Msk               (0x01U << SPI_GCTL_MODE_Pos)    /*!< Master mode bit */
#define SPI_GCTL_TXEN_Pos               (3)
#define SPI_GCTL_TXEN_Msk               (0x01U << SPI_GCTL_TXEN_Pos)    /*!< Transmit enable bit */
#define SPI_GCTL_RXEN_Pos               (4)
#define SPI_GCTL_RXEN_Msk               (0x01U << SPI_GCTL_RXEN_Pos)    /*!< Receive enable bit */

#define SPI_GCTL_DMAMODE_Pos            (9)
#define SPI_GCTL_DMAMODE_Msk            (0x01U << SPI_GCTL_DMAMODE_Pos) /*!< DMA access mode enable */
#define SPI_GCTL_NSS_Pos                (10)
#define SPI_GCTL_NSS_Msk                (0x01U << SPI_GCTL_NSS_Pos)     /*!< NSS select signal that from software or hardware */
#define SPI_GCTL_DW8_32_Pos             (11)
#define SPI_GCTL_DW8_32_Msk             (0x01U << SPI_GCTL_DW8_32_Pos)  /*!< Valid byte or double-word data select signal */

#define SPI_GCTL_PAD_SEL_Pos            (13)
#define SPI_GCTL_PAD_SEL_Msk            (0x1FU << SPI_GCTL_PAD_SEL_Pos) /*!< Bus mapping transformation */

/**
  * @brief SPI_CCTL Register Bit Definition
  */
#define SPI_CCTL_CPHA_Pos               (0)
#define SPI_CCTL_CPHA_Msk               (0x01U << SPI_CCTL_CPHA_Pos)     /*!< Clock phase select bit */
#define SPI_CCTL_CPOL_Pos               (1)
#define SPI_CCTL_CPOL_Msk               (0x01U << SPI_CCTL_CPOL_Pos)     /*!< Clock polarity select bit */
#define SPI_CCTL_LSBFE_Pos              (2)
#define SPI_CCTL_LSBFE_Msk              (0x01U << SPI_CCTL_LSBFE_Pos)    /*!< LSI first enable bit */
#define SPI_CCTL_SPILEN_Pos             (3)
#define SPI_CCTL_SPILEN_Msk             (0x01U << SPI_CCTL_SPILEN_Pos)   /*!< SPI character length bit */
#define SPI_CCTL_RXEDGE_Pos             (4)
#define SPI_CCTL_RXEDGE_Msk             (0x01U << SPI_CCTL_RXEDGE_Pos)   /*!< Receive data edge select */
#define SPI_CCTL_TXEDGE_Pos             (5)
#define SPI_CCTL_TXEDGE_Msk             (0x01U << SPI_CCTL_TXEDGE_Pos)   /*!< Transmit data edge select */
#define SPI_CCTL_CPHASEL_Pos            (6)
#define SPI_CCTL_CPHASEL_Msk            (0x01U << SPI_CCTL_CPHASEL)      /*!< CPHA polarity select */
#define SPI_CCTL_TISEL_Pos              (7)
#define SPI_CCTL_TISEL_Msk              (0x01U << SPI_CCTL_TISEL_Pos)    /*!<  High speed slave mode */
#define SPI_CCTL_MRDECHG_Pos            (8)
#define SPI_CCTL_MRDECHG_Msk            (0x07U << SPI_CCTL_MRDECHG_Pos)  /*!< Receive data edge change */
#define SPI_CCTL_MRDECHG_0              (0x00U << SPI_CCTL_MRDECHG_Pos)  /*!< The sampling point moves back SPBRG/2 mclk cycles*/
#define SPI_CCTL_MRDECHG_1              (0x01U << SPI_CCTL_MRDECHG_Pos)  /*!< The sampling point moves back SPBRG 1 mclk cycles*/
#define SPI_CCTL_MRDECHG_2              (0x02U << SPI_CCTL_MRDECHG_Pos)  /*!< The sampling point moves back SPBRG 2 mclk cycles */
#define SPI_CCTL_MRDECHG_3              (0x03U << SPI_CCTL_MRDECHG_Pos)  /*!< The sampling point moves back SPBRG 3 mclk cycles */
#define SPI_CCTL_MRDECHG_4              (0x04U << SPI_CCTL_MRDECHG_Pos)  /*!< The sampling point moves back SPBRG 4 mclk cycles */
/**
  * @brief SPI_SPBRG Register Bit Definition
  */
#define SPI_SPBRG_SPBRG_Pos             (0)
#define SPI_SPBRG_SPBRG_Msk             (0xFFFFU << SPI_SPBRG_SPBRG_Pos) /*!< SPI baud rate control register for baud rate */

/**
  * @brief SPI_RXDNR Register Bit Definition
  */
#define SPI_RXDNR_RXDNR_Pos             (0)
#define SPI_RXDNR_RXDNR_Msk             (0xFFFFU << SPI_RXDNR_RXDNR_Pos) /*!< The register is used to hold a count of to be received bytes in next receive process */

/**
  * @brief SPI_NSSR Register Bit Definition
  */
#define SPI_NSSR_NSS_Pos                (0)
#define SPI_NSSR_NSS_Msk                (0x01U << SPI_NSSR_NSS_Pos) /*!< Chip select output signal in Master mode */

/**
  * @brief SPI_EXTCTL Register Bit Definition
  */
#define SPI_EXTCTL_EXTLEN_Pos           (0)
#define SPI_EXTCTL_EXTLEN_Msk           (0x1FU << SPI_EXTCTL_EXTLEN_Pos) /*!< control SPI data length */
#define SPI_EXTCTL_EXTLEN_0             (0x01U << SPI_EXTCTL_EXTLEN_Pos) /*!< Bit 0 */
#define SPI_EXTCTL_EXTLEN_1             (0x02U << SPI_EXTCTL_EXTLEN_Pos) /*!< Bit 1 */
#define SPI_EXTCTL_EXTLEN_2             (0x04U << SPI_EXTCTL_EXTLEN_Pos) /*!< Bit 2 */
#define SPI_EXTCTL_EXTLEN_3             (0x08U << SPI_EXTCTL_EXTLEN_Pos) /*!< Bit 3 */
#define SPI_EXTCTL_EXTLEN_4             (0x10U << SPI_EXTCTL_EXTLEN_Pos) /*!< Bit 4 */

/**
  * @brief I2S_CFGR Register Bit Definition
  */
#define SPI_I2SCFGR_CHLEN_Pos           (0)
#define SPI_I2SCFGR_CHLEN_Msk           (0x01U << SPI_I2SCFGR_CHLEN_Pos) /*!<  Vocal tract length */
#define SPI_I2SCFGR_DATLEN_Pos          (1)
#define SPI_I2SCFGR_DATLEN_Msk          (0x03U << SPI_I2SCFGR_DATLEN_Pos)

#define SPI_I2SCFGR_I2SSTD_Pos          (4)
#define SPI_I2SCFGR_I2SSTD_Msk          (0x03U << SPI_I2SCFGR_I2SSTD_Pos)

#define SPI_I2SCFGR_PCMSYNC_Pos         (6)
#define SPI_I2SCFGR_PCMSYNC_Msk         (0x01U << SPI_I2SCFGR_PCMSYNC_Pos) /*!<  PCM frame synchronization mode */
#define SPI_I2SCFGR_SPI_I2S_Pos         (10)
#define SPI_I2SCFGR_SPI_I2S_Msk         (0x01U << SPI_I2SCFGR_SPI_I2S_Pos) /*!<  SPI/I2S module function selection */
#define SPI_I2SCFGR_MCKOE_Pos           (11)
#define SPI_I2SCFGR_MCKOE_Msk           (0x01U << SPI_I2SCFGR_MCKOE_Pos)   /*!<  I2S master clock output enable */
#define SPI_I2SCFGR_MCKSEL_Pos          (12)
#define SPI_I2SCFGR_MCKSEL_Msk          (0x01U << SPI_I2SCFGR_MCKSEL_Pos)  /*!<  MCK output signal selection */
#define SPI_I2SCFGR_HDSEL_Pos           (13)
#define SPI_I2SCFGR_HDSEL_Msk           (0x01U << SPI_I2SCFGR_HDSEL_Pos)   /*!<  I2S full duplex, half duplex options */

#define SPI_I2SCFGR_I2SDIV_Pos          (16)
#define SPI_I2SCFGR_I2SDIV_Msk          (0x1FFU << SPI_I2SCFGR_I2SDIV_Pos) /*!<  The frequency division */

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
#endif
/*----------------------------------------------------------------------------*/

