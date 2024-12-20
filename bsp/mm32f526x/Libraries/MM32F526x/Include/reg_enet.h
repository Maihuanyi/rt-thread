/***********************************************************************************************************************
    @file     reg_enet.h
    @author   VV TEAM
    @brief    This flie contains all the ENET's register and its field definition.
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

#ifndef __REG_ENET_H
#define __REG_ENET_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief IWDG Base Address Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_BASE                        (AHB1PERIPH_BASE + 0x8000) ///< Base Address: 0x40028000

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH Register Structure Definition
////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    __IO uint32_t MACCR;               ///< configuration register                         offset 0x0000

    union
    {
        __IO uint32_t MACAFR;          ///< frame filter register                          offset 0x0004
        __IO uint32_t MACFFR;
    };

    __IO uint32_t MACHTHR;             ///< Hash list high register                        offset 0x0008
    __IO uint32_t MACHTLR;             ///< Hash list low register                         offset 0x000C

    union
    {
        __IO uint32_t MACSMIAR;        ///< MII address register                           offset 0x0010
        __IO uint32_t MACMIIAR;
    };
    union
    {
        __IO uint32_t MACSMIDR;        ///< MII data register                              offset 0x0014
        __IO uint32_t MACMIIDR;
    };

    __IO uint32_t MACFCR;              ///< flow control register                          offset 0x0018

    union
    {
        __IO uint32_t MACVLTRR;        ///< VLAN label register                            offset 0x001C
        __IO uint32_t MACVLANTR;
    };

    __IO uint32_t RESERVED0x0020[1];   ///< Reserved                                       offset 0x0020
    __IO uint32_t MACSR;               ///< MAC Status Register                            offset 0x0024

    union
    {
        __IO uint32_t PMTRWFR;         ///< MAC Remote Wakeup Frame FilterRegister         offset 0x0028
        __IO uint32_t MACRWUFFR;
    };
    union
    {
        __IO uint32_t PMTCR;           ///< MAC PMT Control Register                       offset 0x002C
        __IO uint32_t MACPMTCSR;
    };

    __IO uint32_t RESERVED0x0030[2];   ///< Reserved                                       offset 0x0030 ~ 0x0034
    __IO uint32_t MACISR;              ///< MAC Interrupt Status Register                  offset 0x0038
    __IO uint32_t MACIMR;              ///< MAC Interrupt Mask Register                    offset 0x003C
    __IO uint32_t MACA0HR;             ///< address 0 high register                        offset 0x0040
    __IO uint32_t MACA0LR;             ///< address 0 low register                         offset 0x0044
    __IO uint32_t MACA1HR;             ///< address 1 high register                        offset 0x0048
    __IO uint32_t MACA1LR;             ///< address 1 low register                         offset 0x004C
    __IO uint32_t MACA2HR;             ///< address 2 high register                        offset 0x0050
    __IO uint32_t MACA2LR;             ///< address 2 low register                         offset 0x0054
    __IO uint32_t MACA3HR;             ///< address 3 high register                        offset 0x0058
    __IO uint32_t MACA3LR;             ///< address 3 low register                         offset 0x005C
    __IO uint32_t MACA4HR;             ///< address 4 high register                        offset 0x0060
    __IO uint32_t MACA4LR;             ///< address 4 low register                         offset 0x0064
    __IO uint32_t MACA5HR;             ///< address 5 high register                        offset 0x0068
    __IO uint32_t MACA5LR;             ///< address 5 low register                         offset 0x006C
    __IO uint32_t RESERVED0x0070[36];  ///< Reserved                                       offset 0x0070 ~ 0x00FC
    __IO uint32_t MMCCR;               ///< MMC controls registers                         offset 0x0100

    union
    {
        __IO uint32_t MMCRSR;          ///< MMC Receive Status Register                    offset 0x0104
        __IO uint32_t MMCRSIR;
    };
    union
    {
        __IO uint32_t MMCTSR;          ///< MMC Transmit Status Register                   offset 0x0108
        __IO uint32_t MMCTSIR;
    };
    union
    {
        __IO uint32_t MMCRIR;          ///< MMC Receive Interrupt Register                 offset 0x010C
        __IO uint32_t MMCRIMR;
    };
    union
    {
        __IO uint32_t MMCTIR;          ///< MMC Transmit Interrupt Register                offset 0x0110
        __IO uint32_t MMCTIMR;
    };

    __IO uint32_t RESERVED0x0114[14];  ///< Reserved                                       offset 0x0114 ~ 0x0148

    union
    {
        __IO uint32_t MMCTGSCR;        ///< MMC Receive Interrupt Register                 offset 0x014C
        __IO uint32_t MMCTGFSCCR;      ///< A good frame counter register that MMC sends after a single conflict
    };
    union
    {
        __IO uint32_t MMCTGMCR;        ///< MMC Transmit Interrupt Register                 offset 0x0150
        __IO uint32_t MMCTGFMSCCR;     ///< A good frame counter register that MMC sends after multiple collisions
    };

    __IO uint32_t RESERVED0x0154[5];   ///< Reserved                                        offset 0x0154 ~ 0x0164

    union
    {
        __IO uint32_t MMCTGR;          ///< MMC Transfer Good Frame Counter Register        offset 0x0168
        __IO uint32_t MMCTGFCR;
    };

    __IO uint32_t RESERVED0x016C[10];  ///< Reserved                                        offset 0x016C ~ 0x0190

    union
    {
        __IO uint32_t MMCRCRCER;       ///< MMC Receive CRC Error Frame Counter Register    offset 0x0194
        __IO uint32_t MMCRFCECR;
    };
    union
    {
        __IO uint32_t MMCRALIER;       ///< MMC Receive Align Error Frame Counter Register  offset 0x0198
        __IO uint32_t MMCRFAECR;
    };

    __IO uint32_t RESERVED0x019C[10];  ///< Reserved                                        offset 0x019C ~ 0x01C0

    union
    {
        __IO uint32_t MMCRUGR;         ///< MMC Transmit Interrupt Register                 offset 0x01C4
        __IO uint32_t MMCRGUFCR;
    };

    __IO uint32_t RESERVED0x01C8[239]; ///< Reserved                                        offset 0x01C8 ~ 0x0580
    __IO uint32_t MACVLTTR;            ///< MAC VLAN TAG Transmit Register                  offset 0x0584
    __IO uint32_t MACVLHTR;            ///< MAC VLAN HASH Table Register                    offset 0x0588
    __IO uint32_t RESERVED0x058C[69];  ///< Reserved                                        offset 0x058C ~ 0x069C
    __IO uint32_t PTPCR;               ///< PTP Control Register                            offset 0x0700
    __IO uint32_t PTPNSAR;             ///< PTP Nanosecond Addend Register                  offset 0x0704
    __IO uint32_t PTPSBSR;             ///< PTP Nanosecond Addend Register                  offset 0x0708
    __IO uint32_t PTPSNSR;             ///< PTP System Nanosecond Register                  offset 0x070C
    __IO uint32_t PTPUBSR;             ///< PTP Update Base Second Register                 offset 0x0710
    __IO uint32_t PTPUNSR;             ///< PTP Update Nanosecond Register                  offset 0x0714
    __IO uint32_t PTPBSAR;             ///< PTP Basic Addend Register                       offset 0x0718
    __IO uint32_t PTPTBSR0;            ///< PTP Basic Addend Register                       offset 0x071C
    __IO uint32_t PTPTNSR0;            ///< Automatic negotiation of broadcast registers    offset 0x0720
    __IO uint32_t RESERVED0x0724[1];   ///< Reserved                                        offset 0x0724
    __IO uint32_t PTPSR;               ///< Automatic negotiation of broadcast registers    offset 0x0728
    __IO uint32_t PTPPPSR;             ///< Automatic negotiation of the status register    offset 0x072C
    __IO uint32_t RESERVED0x0730[20];  ///< Reserved                                        offset 0x0730 ~ 0x077C
    __IO uint32_t PTPTBSR1;            ///< Automatic negotiation of broadcast registers    offset 0x0780
    __IO uint32_t PTPTNSR1;            ///< Automatic negotiation of the status register    offset 0x0784
    __IO uint32_t RESERVED0x0788[542]; ///< Reserved                                        offset 0x0788 ~ 0x0FFC

    union
    {
        __IO uint32_t DMABSR;          ///< Bus mode register                               offset 0x1000
        __IO uint32_t DMABMR;
    };
    union
    {
        __IO uint32_t DMATXPDR;        ///< DMA sends the polling request register          offset 0x1004
        __IO uint32_t DMATPDR;
    };
    union
    {
        __IO uint32_t DMARXPDR;        ///< DMA receives the polling request register       offset 0x1008
        __IO uint32_t DMARPDR;
    };
    union
    {
        __IO uint32_t DMARXDSAR;       ///< DMA receives a list of descriptor addresses     offset 0x100C
        __IO uint32_t DMARDLAR;
    };
    union
    {
        __IO uint32_t DMATXDSAR;       ///< DMA sends the descriptor list address           offset 0x1010
        __IO uint32_t DMATDLAR;
    };

    __IO uint32_t DMASR;               ///< DMA status register                             offset 0x1014

    union
    {
        __IO uint32_t DMAMDR;          ///< DMA working mode register                       offset 0x1018
        __IO uint32_t DMAOMR;
    };
    union
    {
        __IO uint32_t DMAIR;           ///< DMA interrupt enablement register               offset 0x101C
        __IO uint32_t DMAIER;
    };
    union
    {
        __IO uint32_t DMAFLCR;         ///< DMA lost frames and cache overflow counter registers offset 0x1020
        __IO uint32_t DMAMFBOCR;
    };
    union
    {
        __IO uint32_t DMAWDTR;         ///< DMA interrupt enablement register               offset 0x1024
        __IO uint32_t DMARSWTR;
    };

    __IO uint32_t RESERVED0x1028[8];   ///< DMA interrupt enablement register               offset 0x1028 ~ 0x1044

    union
    {
        __IO uint32_t DMACURTXDSAR;    ///< DMA lost frames and cache overflow counter registers    offset 0x1048
        __IO uint32_t DMACHTDR;
    };
    union
    {
        __IO uint32_t DMACURRXDSAR;    ///< DMA interrupt enablement register               offset 0x104C
        __IO uint32_t DMACHRDR;
    };
    union
    {
        __IO uint32_t DMACURTXBFAR;    ///< DMA lost frames and cache overflow counter registers     offset 0x1050
        __IO uint32_t DMACHTBAR;
    };
    union
    {
        __IO uint32_t DMACURRXBFAR;    ///< DMA interrupt enablement register               offset 0x1054
        __IO uint32_t DMACHRBAR;
    };
} ETH_TypeDef;

#define ETH                                    ((ETH_TypeDef *)ETH_BASE)

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACCR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACCR_SAIRC_Pos                    (28)
#define ETH_MACCR_SAIRC                        (0x07U << ETH_MACCR_SAIRC_Pos) //< SA Insert Replace Control
#define ETH_MACCR_CST_Pos                      (25)
#define ETH_MACCR_CST                          (0x01U << ETH_MACCR_CST_Pos)   //< CRC Strip
#define ETH_MACCR_WTD_Pos                      (23)
#define ETH_MACCR_WTD                          (0x01U << ETH_MACCR_WTD_Pos)   ///< Watchdog disable
#define ETH_MACCR_JAB_Pos                      (22)
#define ETH_MACCR_JAB                          (0x01U << ETH_MACCR_JAB_Pos)   ///< Jabber disable
#define ETH_MACCR_IFG_Pos                      (17)                           ///< Inter-frame gap
#define ETH_MACCR_IFG_96Bit                    (0x00U << ETH_MACCR_IFG_Pos)   ///< Minimum IFG between frames during transmission is 96Bit
#define ETH_MACCR_IFG_88Bit                    (0x01U << ETH_MACCR_IFG_Pos)   ///< Minimum IFG between frames during transmission is 88Bit
#define ETH_MACCR_IFG_80Bit                    (0x02U << ETH_MACCR_IFG_Pos)   ///< Minimum IFG between frames during transmission is 80Bit
#define ETH_MACCR_IFG_72Bit                    (0x03U << ETH_MACCR_IFG_Pos)   ///< Minimum IFG between frames during transmission is 72Bit
#define ETH_MACCR_IFG_64Bit                    (0x04U << ETH_MACCR_IFG_Pos)   ///< Minimum IFG between frames during transmission is 64Bit
#define ETH_MACCR_IFG_56Bit                    (0x05U << ETH_MACCR_IFG_Pos)   ///< Minimum IFG between frames during transmission is 56Bit
#define ETH_MACCR_IFG_48Bit                    (0x06U << ETH_MACCR_IFG_Pos)   ///< Minimum IFG between frames during transmission is 48Bit
#define ETH_MACCR_IFG_40Bit                    (0x07U << ETH_MACCR_IFG_Pos)   ///< Minimum IFG between frames during transmission is 40Bit
#define ETH_MACCR_MCRS_Pos                     (16)
#define ETH_MACCR_MCRS                         (0x01U << ETH_MACCR_MCRS_Pos)  ///< Mask Carrier Sense
#define ETH_MACCR_RDIS_Pos                     (13)
#define ETH_MACCR_RDIS                         (0x01U << ETH_MACCR_RDIS_Pos)  ///< Receive disable
#define ETH_MACCR_LM_Pos                       (12)
#define ETH_MACCR_LM                           (0x01U << ETH_MACCR_LM_Pos)    ///< loopback mode
#define ETH_MACCR_DM_Pos                       (11)
#define ETH_MACCR_DM                           (0x01U << ETH_MACCR_DM_Pos)    ///< Duplex mode
#define ETH_MACCR_IPCO_Pos                     (10)
#define ETH_MACCR_IPCO                         (0x01U << ETH_MACCR_IPCO_Pos)  ///< IP Checksum offload
#define ETH_MACCR_RETY_Pos                     (9)
#define ETH_MACCR_RETY                         (0x01U << ETH_MACCR_RETY_Pos)  ///< Retry Transfer
#define ETH_MACCR_APCS_Pos                     (7)
#define ETH_MACCR_APCS                         (0x01U << ETH_MACCR_APCS_Pos)  ///< Automatic CRC/PAD Strip
#define ETH_MACCR_BL_Pos                       (5)                            ///< Back-off limit: random integer number (r) of slot time delays before rescheduling a transmission attempt during retries after a collision: 0 =< r <2^k
#define ETH_MACCR_BL                           (0x03U << ETH_MACCR_BL_Pos)
#define ETH_MACCR_BL_10                        (0x00U << ETH_MACCR_BL_Pos)    ///< k = min (n, 10)
#define ETH_MACCR_BL_8                         (0x01U << ETH_MACCR_BL_Pos)    ///< k = min (n, 8)
#define ETH_MACCR_BL_4                         (0x02U << ETH_MACCR_BL_Pos)    ///< k = min (n, 4)
#define ETH_MACCR_BL_1                         (0x03U << ETH_MACCR_BL_Pos)    ///< k = min (n, 1)
#define ETH_MACCR_DLYC_Pos                     (4)
#define ETH_MACCR_DLYC                         (0x01U << ETH_MACCR_DLYC_Pos)  ///< Delay Check
#define ETH_MACCR_TE_Pos                       (3)
#define ETH_MACCR_TE                           (0x01U << ETH_MACCR_TE_Pos)    ///< Transmitter enable
#define ETH_MACCR_RE_Pos                       (2)
#define ETH_MACCR_RE                           (0x01U << ETH_MACCR_RE_Pos)    ///< Receiver enable

//legacy define
#define ETH_MACCR_WD_Pos                       ETH_MACCR_WTD_Pos
#define ETH_MACCR_WD                           ETH_MACCR_WTD
#define ETH_MACCR_JD_Pos                       ETH_MACCR_JAB_Pos
#define ETH_MACCR_JD                           ETH_MACCR_JAB
#define ETH_MACCR_ROD_Pos                      ETH_MACCR_RDIS_Pos
#define ETH_MACCR_ROD                          ETH_MACCR_RDIS
#define ETH_MACCR_RD_Pos                       ETH_MACCR_RETY_Pos
#define ETH_MACCR_RD                           ETH_MACCR_RETY
#define ETH_MACCR_DC_Pos                       ETH_MACCR_DLYC_Pos
#define ETH_MACCR_DC                           ETH_MACCR_DLYC

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACFFR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACFFR_RALL_Pos                    (31)
#define ETH_MACFFR_RALL                        (0x01U << ETH_MACFFR_RALL_Pos) ///< Receive all
#define ETH_MACFFR_DNTU_Pos                    (21)
#define ETH_MACFFR_DNTU                        (0x01U << ETH_MACFFR_DNTU_Pos) ///< Dropped no-TCP/UDP
#define ETH_MACFFR_VLTF_Pos                    (16)
#define ETH_MACFFR_VLTF                        (0x01U << ETH_MACFFR_VLTF_Pos) ///< VLAN TAG Filter
#define ETH_MACFFR_HPF_Pos                     (10)
#define ETH_MACFFR_HPF                         (0x01U << ETH_MACFFR_HPF_Pos)  ///< Hash/Perfect Filter
#define ETH_MACFFR_SAF_Pos                     (9)
#define ETH_MACFFR_SAF                         (0x01U << ETH_MACFFR_SAF_Pos)  ///< Source address filter enable
#define ETH_MACFFR_SAIF_Pos                    (8)
#define ETH_MACFFR_SAIF                        (0x01U << ETH_MACFFR_SAIF_Pos) ///< SA inverse filtering
#define ETH_MACFFR_PCF_Pos                     (6)
#define ETH_MACFFR_PCF                         (0x03U << ETH_MACFFR_PCF_Pos)  ///< Pass control frames: 3 cases
#define ETH_MACFFR_PCF_BlockAll                (0x01U << ETH_MACFFR_PCF_Pos)  ///< MAC filters all control frames from reaching the application
#define ETH_MACFFR_PCF_ForwardAll              (0x02U << ETH_MACFFR_PCF_Pos)  ///< MAC forwards all control frames to application even if they fail the Address Filter
#define ETH_MACFFR_PCF_ForwardPassedAddrFilter (0x03U << ETH_MACFFR_PCF_Pos)  ///< MAC forwards control frames that pass the Address Filter.
#define ETH_MACFFR_BCF_Pos                     (5)
#define ETH_MACFFR_BCF                         (0x01U << ETH_MACFFR_BCF_Pos)  ///< Broadcast frame disable
#define ETH_MACFFR_MCF_Pos                     (4)
#define ETH_MACFFR_MCF                         (0x01U << ETH_MACFFR_MCF_Pos)  ///< Multicast Frame Filter
#define ETH_MACFFR_DAIF_Pos                    (3)
#define ETH_MACFFR_DAIF                        (0x01U << ETH_MACFFR_DAIF_Pos) ///< DA Inverse filtering
#define ETH_MACFFR_HM_Pos                      (2)
#define ETH_MACFFR_HM                          (0x01U << ETH_MACFFR_HM_Pos)   ///< Hash multicast
#define ETH_MACFFR_HU_Pos                      (1)
#define ETH_MACFFR_HU                          (0x01U << ETH_MACFFR_HU_Pos)   ///< Hash unicast
#define ETH_MACFFR_PM_Pos                      (0)
#define ETH_MACFFR_PM                          (0x01U << ETH_MACFFR_PM_Pos)   ///< Promiscuous mode

//legacy define
#define ETH_MACFFR_RA_Pos                      ETH_MACFFR_RALL_Pos
#define ETH_MACFFR_RA                          ETH_MACFFR_RALL
#define ETH_MACFFR_BFD_Pos                     ETH_MACFFR_BCF_Pos
#define ETH_MACFFR_BFD                         ETH_MACFFR_BCF
#define ETH_MACFFR_PAM_Pos                     ETH_MACFFR_MCF_Pos
#define ETH_MACFFR_PAM                         ETH_MACFFR_MCF

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACHTHR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACHTHR_MACHTABH                   (0xFFFFFFFFU) ///< Hash table high
//legacy define
#define ETH_MACHTHR_HTH                        ETH_MACHTHR_MACHTABH

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACHTLR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACHTLR_MACHTABL                   (0xFFFFFFFFU) ///< Hash table low
//legacy define
#define ETH_MACHTLR_HTL                        ETH_MACHTLR_MACHTABL

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACMIIAR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACMIIAR_SMIADD_Pos                (11)
#define ETH_MACMIIAR_SMIADD                    (0x1FU << ETH_MACMIIAR_SMIADD_Pos) ///< SMI Address
#define ETH_MACMIIAR_SMIREG_Pos                (6)
#define ETH_MACMIIAR_SMIREG                    (0x1FU << ETH_MACMIIAR_SMIREG_Pos) ///< SMI Reg
#define ETH_MACMIIAR_SMICLK_Pos                (2)
#define ETH_MACMIIAR_SMICLK                    (0x07U << ETH_MACMIIAR_SMICLK_Pos) ///< SMI Clock
#define ETH_MACMIIAR_SMICLK_Div42              (0x00U << ETH_MACMIIAR_SMICLK_Pos) ///< HCLK:60-100 MHz; MDC clock= HCLK/42
#define ETH_MACMIIAR_SMICLK_Div62              (0x01U << ETH_MACMIIAR_SMICLK_Pos) ///< HCLK:100-150 MHz; MDC clock= HCLK/62
#define ETH_MACMIIAR_SMICLK_Div16              (0x02U << ETH_MACMIIAR_SMICLK_Pos) ///< HCLK:20-35 MHz; MDC clock= HCLK/16
#define ETH_MACMIIAR_SMICLK_Div26              (0x03U << ETH_MACMIIAR_SMICLK_Pos) ///< HCLK:35-60 MHz; MDC clock= HCLK/26

#define ETH_MACMIIAR_SMIWR_Pos                 (1)
#define ETH_MACMIIAR_SMIWR                     (0x01U << ETH_MACMIIAR_SMIWR_Pos)  ///< SMI Write
#define ETH_MACMIIAR_SMIBY_Pos                 (0)
#define ETH_MACMIIAR_SMIBY                     (0x01U << ETH_MACMIIAR_SMIBY_Pos)  ///< SMI Busy

//legacy define
#define ETH_MACMIIAR_PA_Pos                    ETH_MACMIIAR_SMIADD_Pos
#define ETH_MACMIIAR_PA                        ETH_MACMIIAR_SMIADD
#define ETH_MACMIIAR_MR_Pos                    ETH_MACMIIAR_SMIREG_Pos
#define ETH_MACMIIAR_MR                        ETH_MACMIIAR_SMIREG
#define ETH_MACMIIAR_CR_Pos                    ETH_MACMIIAR_SMICLK_Pos
#define ETH_MACMIIAR_CR                        ETH_MACMIIAR_SMICLK
#define ETH_MACMIIAR_CR_Div42                  ETH_MACMIIAR_SMICLK_Div42
#define ETH_MACMIIAR_CR_Div62                  ETH_MACMIIAR_SMICLK_Div62
#define ETH_MACMIIAR_CR_Div16                  ETH_MACMIIAR_SMICLK_Div16
#define ETH_MACMIIAR_CR_Div26                  ETH_MACMIIAR_SMICLK_Div26
#define ETH_MACMIIAR_MW_Pos                    ETH_MACMIIAR_SMIWR_Pos
#define ETH_MACMIIAR_MW                        ETH_MACMIIAR_SMIWR
#define ETH_MACMIIAR_MB_Pos                    ETH_MACMIIAR_SMIBY_Pos
#define ETH_MACMIIAR_MB                        ETH_MACMIIAR_SMIBY

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACMIIDR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACMIIDR_SMIDATA                   (0x0000FFFFU) ///< SMI Data: read/write data from/to PHY
//legacy define
#define ETH_MACMIIDR_MD                        ETH_MACMIIDR_SMIDATA

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACFCR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACFCR_PSET_Pos                    (16)
#define ETH_MACFCR_PSET                        ((uint32_t)0xFFFF << ETH_MACFCR_PSET_Pos) ///< Pause Time Setting
#define ETH_MACFCR_DZQP_Pos                    (7)
#define ETH_MACFCR_DZQP                        ((uint32_t)0xFFFF << ETH_MACFCR_DZQP_Pos) ///< Disable Zero-Quanta Pause Frame
#define ETH_MACFCR_PLT_Pos                     (4)
#define ETH_MACFCR_PLT                         (0x03U << ETH_MACFCR_PLT_Pos)             ///< Pause low threshold: 4 cases
#define ETH_MACFCR_PLT_Minus4                  (0x00U << ETH_MACFCR_PLT_Pos)             ///< Pause time minus 4 slot times
#define ETH_MACFCR_PLT_Minus28                 (0x01U << ETH_MACFCR_PLT_Pos)             ///< Pause time minus 28 slot times
#define ETH_MACFCR_PLT_Minus144                (0x02U << ETH_MACFCR_PLT_Pos)             ///< Pause time minus 144 slot times
#define ETH_MACFCR_PLT_Minus256                (0x03U << ETH_MACFCR_PLT_Pos)             ///< Pause time minus 256 slot times
#define ETH_MACFCR_UPF_Pos                     (3)
#define ETH_MACFCR_UPF                         (0x01U << ETH_MACFCR_UPF_Pos)             ///< Unicast Pause Frame
#define ETH_MACFCR_FRE_Pos                     (2)
#define ETH_MACFCR_FRE                         (0x01U << ETH_MACFCR_FRE_Pos)             ///< Flow Control Receive Enable
#define ETH_MACFCR_FTE_Pos                     (1)
#define ETH_MACFCR_FTE                         (0x01U << ETH_MACFCR_FTE_Pos)             ///< Transmit flow control enable
#define ETH_MACFCR_FCBBPA_Pos                  (0)
#define ETH_MACFCR_FCBBPA                      (0x01U << ETH_MACFCR_FCBBPA_Pos)          ///< Flow control busy/backpressure activate

//legacy define
#define ETH_MACFCR_PT_Pos                      ETH_MACFCR_PSET_Pos
#define ETH_MACFCR_PT                          ETH_MACFCR_PSET
#define ETH_MACFCR_UPFD_Pos                    ETH_MACFCR_UPF_Pos
#define ETH_MACFCR_UPFD                        ETH_MACFCR_UPF
#define ETH_MACFCR_RFCE_Pos                    ETH_MACFCR_FRE_Pos
#define ETH_MACFCR_RFCE                        ETH_MACFCR_FRE
#define ETH_MACFCR_TFCE_Pos                    ETH_MACFCR_FTE_Pos
#define ETH_MACFCR_TFCE                        ETH_MACFCR_FTE

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACVLTRR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACVLTRR_VTHM_Pos                  (19)
#define ETH_MACVLTRR_VTHM                      (0x01U << ETH_MACVLTRR_VTHM_Pos)    ///< VLAN TAG Hash Mode
#define ETH_MACVLTRR_VTIM_Pos                  (17)
#define ETH_MACVLTRR_VTIM                      (0x01U << ETH_MACVLTRR_VTIM_Pos)    ///< VLAN TAG Inverse Mode
#define ETH_MACVLTRR_VTSEL_Pos                 (16)
#define ETH_MACVLTRR_VTSEL                     (0x01U << ETH_MACVLTRR_VTSEL_Pos)   ///< VLAN TAG Filter Tag Value
#define ETH_MACVLTRR_VLFLT_Pos                 (0)
#define ETH_MACVLTRR_VLFLT                     (0xFFFFU << ETH_MACVLTRR_VLFLT_Pos) ///< VLAN TAG Filter Tag Valu

//legacy define
#define ETH_MACVLANTR_VLANTI_Pos               ETH_MACVLTRR_VLFLT_Pos
#define ETH_MACVLANTR_VLANTI                   ETH_MACVLTRR_VLFLT

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PMTRWFR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PMTRWFR_RTWKFLT                    (0xFFFFFFFFU) ///< Remote-Wakeup Filter Value
//legacy define
#define ETH_MACRWUFFR_D                        ETH_PMTRWFR_RTWKFLT

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PMTCR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PMTCR_RTWKFR_Pos                   (31)
#define ETH_PMTCR_RTWKFR                       (0x01U << ETH_PMTCR_RTWKFR_Pos) ///< Remote-Wakeup Filter Value
#define ETH_PMTCR_RTWKPT_Pos                   (24)
#define ETH_PMTCR_RTWKPT                       (0x07U << ETH_PMTCR_RTWKPT_Pos) ///< Remote-Wakeup Filter Point
#define ETH_PMTCR_RTWKTR_Pos                   (10)
#define ETH_PMTCR_RTWKTR                       (0x01U << ETH_PMTCR_RTWKTR_Pos) ///< Remote-Wakeup Frame Transfer & Receive Enable
#define ETH_PMTCR_GLUB_Pos                     (9)
#define ETH_PMTCR_GLUB                         (0x01U << ETH_PMTCR_GLUB_Pos)   ///< Global Unicast
#define ETH_PMTCR_WKFR_Pos                     (6)
#define ETH_PMTCR_WKFR                         (0x01U << ETH_PMTCR_WKFR_Pos)   ///< Remote-Wakeup Frame Receive Status
#define ETH_PMTCR_MPFR_Pos                     (5)
#define ETH_PMTCR_MPFR                         (0x01U << ETH_PMTCR_MPFR_Pos)   ///< Magic-Packet Frame Receive Status
#define ETH_PMTCR_WKEN_Pos                     (2)
#define ETH_PMTCR_WKEN                         (0x01U << ETH_PMTCR_WKEN_Pos)   ///< Magic-Packet Frame Receive Enable
#define ETH_PMTCR_MPEN_Pos                     (1)
#define ETH_PMTCR_MPEN                         (0x01U << ETH_PMTCR_MPEN_Pos)   ///< Magic-Packet Frame Receive Status
#define ETH_PMTCR_PWDN_Pos                     (0)
#define ETH_PMTCR_PWDN                         (0x01U << ETH_PMTCR_PWDN_Pos)   ///< Power Down Mode

//legacy define
#define ETH_MACPMTCSR_WFFRPR_Pos               ETH_PMTCR_RTWKFR_Pos
#define ETH_MACPMTCSR_WFFRPR                   ETH_PMTCR_RTWKFR
#define ETH_MACPMTCSR_GU_Pos                   ETH_PMTCR_GLUB_Pos
#define ETH_MACPMTCSR_GU                       ETH_PMTCR_GLUB
#define ETH_MACPMTCSR_WFR_Pos                  ETH_PMTCR_WKFR_Pos
#define ETH_MACPMTCSR_WFR                      ETH_PMTCR_WKFR
#define ETH_MACPMTCSR_MPR_Pos                  ETH_PMTCR_MPFR_Pos
#define ETH_MACPMTCSR_MPR                      ETH_PMTCR_MPFR
#define ETH_MACPMTCSR_WFE_Pos                  ETH_PMTCR_WKEN_Pos
#define ETH_MACPMTCSR_WFE                      ETH_PMTCR_WKEN
#define ETH_MACPMTCSR_MPE_Pos                  ETH_PMTCR_MPEN_Pos
#define ETH_MACPMTCSR_MPE                      ETH_PMTCR_MPEN
#define ETH_MACPMTCSR_PD_Pos                   ETH_PMTCR_PWDN_Pos
#define ETH_MACPMTCSR_PD                       ETH_PMTCR_PWDN

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACSR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACSR_TXFF_Pos                     (25)
#define ETH_MACSR_TXFF                         (0x01U << ETH_MACSR_TXFF_Pos)  ///< TxFIFO Full
#define ETH_MACSR_TXFNE_Pos                    (24)
#define ETH_MACSR_TXFNE                        (0x01U << ETH_MACSR_TXFNE_Pos) ///< Global Unicast
#define ETH_MACSR_TXFWA_Pos                    (22)
#define ETH_MACSR_TXFWA                        (0x01U << ETH_MACSR_TXFWA_Pos) ///< TxFIFO Write Active
#define ETH_MACSR_TXFRS_Pos                    (20)
#define ETH_MACSR_TXFRS                        (0x03U << ETH_MACSR_TXFRS_Pos) ///< TxFIFO Read Status
#define ETH_MACSR_TXFRS_0                      (0x00U << ETH_MACSR_TXFRS_Pos) ///< Idle state
#define ETH_MACSR_TXFRS_1                      (0x01U << ETH_MACSR_TXFRS_Pos) ///< Read state
#define ETH_MACSR_TXFRS_2                      (0x02U << ETH_MACSR_TXFRS_Pos) ///< Waiting for Tx status from MAC transmitter
#define ETH_MACSR_TXFRS_3                      (0x03U << ETH_MACSR_TXFRS_Pos) ///< Writing the received Tx status or flushing the TxFIFO

#define ETH_MACSR_MTP_Pos                      (19)
#define ETH_MACSR_MTP                          (0x01U << ETH_MACSR_MTP_Pos)   ///< MAC Transmitter in Pause
#define ETH_MACSR_MTS_Pos                      (17)
#define ETH_MACSR_MTS                          (0x03U << ETH_MACSR_MTS_Pos)   ///< MAC Transfer Status
#define ETH_MACSR_MTS_0                        (0x00U << ETH_MACSR_MTS_Pos)   ///< Idle state
#define ETH_MACSR_MTS_1                        (0x01U << ETH_MACSR_MTS_Pos)   ///< Waiting for status of previous frame or IFG backoff period to be over
#define ETH_MACSR_MTS_2                        (0x02U << ETH_MACSR_MTS_Pos)   ///< Generating and transmitting a pause control frame (in full duplex mode)
#define ETH_MACSR_MTS_3                        (0x03U << ETH_MACSR_MTS_Pos)   ///< Transferring input frame for transmission
#define ETH_MACSR_MTE_Pos                      (16)
#define ETH_MACSR_MTE                          (0x01U << ETH_MACSR_MTE_Pos)   ///< MAC MII Transfer Engine Status

#define ETH_MACSR_RXFL_Pos                     (8)
#define ETH_MACSR_RXFL                         (0x01U << ETH_MACSR_RXFL_Pos)  ///< RxFIFO Fill Level
#define ETH_MACSR_RXFL_0                       (0x00U << ETH_MACSR_RXFL_Pos)  ///< RxFIFO empty
#define ETH_MACSR_RXFL_1                       (0x01U << ETH_MACSR_RXFL_Pos)  ///< RxFIFO fill-level below flow-control, de-activate threshold
#define ETH_MACSR_RXFL_2                       (0x02U << ETH_MACSR_RXFL_Pos)  ///< RxFIFO fill-level above flow-control, activate threshold
#define ETH_MACSR_RXFL_3                       (0x03U << ETH_MACSR_RXFL_Pos)  ///< RxFIFO full

#define ETH_MACSR_RXFRS_Pos                    (5)
#define ETH_MACSR_RXFRS                        (0x03U << ETH_MACSR_RXFRS_Pos) ///< RxFIFO Read Status
#define ETH_MACSR_RXFRS_0                      (0x00U << ETH_MACSR_RXFRS_Pos) ///< Idle state
#define ETH_MACSR_RXFRS_1                      (0x01U << ETH_MACSR_RXFRS_Pos) ///< Reading frame data
#define ETH_MACSR_RXFRS_2                      (0x02U << ETH_MACSR_RXFRS_Pos) ///< Reading frame status or time-stamp
#define ETH_MACSR_RXFRS_3                      (0x03U << ETH_MACSR_RXFRS_Pos) ///< Flushing the frame data and status

#define ETH_MACSR_RXFWA_Pos                    (4)
#define ETH_MACSR_RXFWA                        (0x01U << ETH_MACSR_RXFWA_Pos) ///< RxFIFO Write Active

#define ETH_MACSR_MRS_Pos                      (1)
#define ETH_MACSR_MRS                          (0x03U << ETH_MACSR_MRS_Pos)   ///< MAC Receive Status
#define ETH_MACSR_MRS_0                        (0x00U << ETH_MACSR_MRS_Pos)   ///< Idle
#define ETH_MACSR_MRS_1                        (0x01U << ETH_MACSR_MRS_Pos)   ///< FIFO write controller in the MAC receiver is operating
#define ETH_MACSR_MRS_2                        (0x02U << ETH_MACSR_MRS_Pos)   ///< FIFO read controller in the MAC receiver is operating
#define ETH_MACSR_MRS_3                        (0x03U << ETH_MACSR_MRS_Pos)   ///< FIFO read and write controllers in the MAC receiver are operating
#define ETH_MACSR_MRE_Pos                      (0)
#define ETH_MACSR_MRE                          (0x01U << ETH_MACSR_MRE_Pos)   ///< MAC MII Receive Engine Status

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACISR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACISR_PTPIS_Pos                   (9)
#define ETH_MACISR_PTPIS                       (0x01U << ETH_MACISR_PTPIS_Pos)   ///< PTP Interrupt Status
#define ETH_MACISR_MMCTXIS_Pos                 (6)
#define ETH_MACISR_MMCTXIS                     (0x01U << ETH_MACISR_MMCTXIS_Pos) ///< MMC Transfer Interrupt Status
#define ETH_MACISR_MMCRXIS_Pos                 (5)
#define ETH_MACISR_MMCRXIS                     (0x01U << ETH_MACISR_MMCRXIS_Pos) ///< MMC Transfer Interrupt Status
#define ETH_MACISR_MMCIS_Pos                   (4)
#define ETH_MACISR_MMCIS                       (0x01U << ETH_MACISR_MMCIS_Pos)   ///< MMC Interrupt Status
#define ETH_MACISR_PMTIS_Pos                   (3)
#define ETH_MACISR_PMTIS                       (0x01U << ETH_MACISR_PMTIS_Pos)   ///< PMT Interrupt Status

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACIMR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACIMR_PTPIM_Pos                   (9)
#define ETH_MACIMR_PTPIM                       (0x01U << ETH_MACIMR_PTPIM_Pos) ///< PTP Interrupt Mask
#define ETH_MACIMR_PMTIM_Pos                   (3)
#define ETH_MACIMR_PMTIM                       (0x01U << ETH_MACIMR_PMTIM_Pos) ///< PMT Interrupt Mask

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA0HR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA0HR_MACADDH                    ((uint32_t)0x0000FFFF) ///< MAC Address Filter Address Value High
//legacy define
#define ETH_MACA0HR_MACA0H                     ETH_MACA0HR_MACADDH

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA0LR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA0LR_MACADDL                    ((uint32_t)0xFFFFFFFF) ///< MAC Address Filter Address Value Low
//legacy define
#define ETH_MACA0LR_MACA0L                     ETH_MACA0LR_MACADDL

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA1HR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA1HR_ADDE_Pos                   (31)
#define ETH_MACA1HR_ADDE                       (0x01U << ETH_MACA1HR_ADDE_Pos)      ///< Address Filter Enable
#define ETH_MACA1HR_SELE_Pos                   (30)
#define ETH_MACA1HR_SELE                       (0x01U << ETH_MACA1HR_SELE_Pos)      ///< SA/DA Filter Select Enable
#define ETH_MACA1HR_MBYTEC_Pos                 (24)
#define ETH_MACA1HR_MBYTEC                     (0x3FU << ETH_MACA1HR_MBYTEC_Pos)    ///< Mask Byte Control
#define ETH_MACA1HR_MBYTEC_29_BIT              (0x20U << ETH_MACA1HR_MBYTEC_Pos)    ///< Mask MACADDH[15:8] bits
#define ETH_MACA1HR_MBYTEC_28_BIT              (0x10U << ETH_MACA1HR_MBYTEC_Pos)    ///< Mask MACADDH[7:0] bits
#define ETH_MACA1HR_MBYTEC_27_BIT              (0x08U << ETH_MACA1HR_MBYTEC_Pos)    ///< Mask MACADDH[7:0] bits
#define ETH_MACA1HR_MBYTEC_26_BIT              (0x04U << ETH_MACA1HR_MBYTEC_Pos)    ///< Mask MACADDL[23:16] bits
#define ETH_MACA1HR_MBYTEC_25_BIT              (0x02U << ETH_MACA1HR_MBYTEC_Pos)    ///< Mask MACADDL[15:8] bits
#define ETH_MACA1HR_MBYTEC_24_BIT              (0x01U << ETH_MACA1HR_MBYTEC_Pos)    ///< Mask MACADDL[7:0] bits
#define ETH_MACA1HR_MACADDH_Pos                (0)
#define ETH_MACA1HR_MACADDH                    (0xFFFFU << ETH_MACA1HR_MACADDH_Pos) ///< MAC Address Filter Address Value High

//legacy define
#define ETH_MACA1HR_AE_Pos                     ETH_MACA1HR_ADDE_Pos
#define ETH_MACA1HR_AE                         ETH_MACA1HR_ADDE
#define ETH_MACA1HR_SA_Pos                     ETH_MACA1HR_SELE_Pos
#define ETH_MACA1HR_SA                         ETH_MACA1HR_SELE
#define ETH_MACA1HR_MBC_Pos                    ETH_MACA1HR_MBYTEC_Pos
#define ETH_MACA1HR_MBC                        ETH_MACA1HR_MBYTEC
#define ETH_MACA1HR_MBC_HBits15_8              ETH_MACA1HR_MBYTEC_29_BIT
#define ETH_MACA1HR_MBC_HBits7_0               ETH_MACA1HR_MBYTEC_28_BIT
#define ETH_MACA1HR_MBC_LBits31_24             ETH_MACA1HR_MBYTEC_27_BIT
#define ETH_MACA1HR_MBC_LBits23_16             ETH_MACA1HR_MBYTEC_26_BIT
#define ETH_MACA1HR_MBC_LBits15_8              ETH_MACA1HR_MBYTEC_25_BIT
#define ETH_MACA1HR_MBC_LBits7_0               ETH_MACA1HR_MBYTEC_24_BIT
#define ETH_MACA1HR_MACA1H_Pos                 ETH_MACA1HR_MACADDH_Pos
#define ETH_MACA1HR_MACA1H                     ETH_MACA1HR_MACADDH

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA1LR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA1LR_MACADDL                    ((uint32_t)0xFFFFFFFF) ///< MAC Address Filter Address Value Low
//legacy define
#define ETH_MACA1LR_MACA1L                     ETH_MACA1LR_MACADDL

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA2HR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA2HR_ADDE_Pos                   (31)
#define ETH_MACA2HR_ADDE                       (0x01U << ETH_MACA2HR_ADDE_Pos)      ///< Address Filter Enable
#define ETH_MACA2HR_SELE_Pos                   (30)
#define ETH_MACA2HR_SELE                       (0x01U << ETH_MACA2HR_SELE_Pos)      ///< SA/DA Filter Select Enable
#define ETH_MACA2HR_MBYTEC_Pos                 (24)
#define ETH_MACA2HR_MBYTEC                     (0x3FU << ETH_MACA2HR_MBYTEC_Pos)    ///< Mask Byte Control
#define ETH_MACA2HR_MBYTEC_29_BIT              (0x20U << ETH_MACA2HR_MBYTEC_Pos)    ///< Mask MACADDH[15:8] bits
#define ETH_MACA2HR_MBYTEC_28_BIT              (0x10U << ETH_MACA2HR_MBYTEC_Pos)    ///< Mask MACADDH[7:0] bits
#define ETH_MACA2HR_MBYTEC_27_BIT              (0x08U << ETH_MACA2HR_MBYTEC_Pos)    ///< Mask MACADDH[7:0] bits
#define ETH_MACA2HR_MBYTEC_26_BIT              (0x04U << ETH_MACA2HR_MBYTEC_Pos)    ///< Mask MACADDL[23:16] bits
#define ETH_MACA2HR_MBYTEC_25_BIT              (0x02U << ETH_MACA2HR_MBYTEC_Pos)    ///< Mask MACADDL[15:8] bits
#define ETH_MACA2HR_MBYTEC_24_BIT              (0x01U << ETH_MACA2HR_MBYTEC_Pos)    ///< Mask MACADDL[7:0] bits
#define ETH_MACA2HR_MACADDH_Pos                (0)
#define ETH_MACA2HR_MACADDH                    (0xFFFFU << ETH_MACA2HR_MACADDH_Pos) ///< MAC Address Filter Address Value High

//legacy define
#define ETH_MACA2HR_AE_Pos                     ETH_MACA2HR_ADDE_Pos
#define ETH_MACA2HR_AE                         ETH_MACA2HR_ADDE
#define ETH_MACA2HR_SA_Pos                     ETH_MACA2HR_SELE_Pos
#define ETH_MACA2HR_SA                         ETH_MACA2HR_SELE
#define ETH_MACA2HR_MBC_Pos                    ETH_MACA2HR_MBYTEC_Pos
#define ETH_MACA2HR_MBC                        ETH_MACA2HR_MBYTEC
#define ETH_MACA2HR_MBC_HBits15_8              ETH_MACA2HR_MBYTEC_29_BIT
#define ETH_MACA2HR_MBC_HBits7_0               ETH_MACA2HR_MBYTEC_28_BIT
#define ETH_MACA2HR_MBC_LBits31_24             ETH_MACA2HR_MBYTEC_27_BIT
#define ETH_MACA2HR_MBC_LBits23_16             ETH_MACA2HR_MBYTEC_26_BIT
#define ETH_MACA2HR_MBC_LBits15_8              ETH_MACA2HR_MBYTEC_25_BIT
#define ETH_MACA2HR_MBC_LBits7_0               ETH_MACA2HR_MBYTEC_24_BIT
#define ETH_MACA2HR_MACA2H_Pos                 ETH_MACA2HR_MACADDH_Pos
#define ETH_MACA2HR_MACA2H                     ETH_MACA2HR_MACADDH

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA2LR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA2LR_MACADDL                    ((uint32_t)0xFFFFFFFF) ///< MAC Address Filter Address Value Low
//legacy define
#define ETH_MACA2LR_MACA2L                     ETH_MACA2LR_MACADDL

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA3HR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA3HR_ADDE_Pos                   (31)
#define ETH_MACA3HR_ADDE                       (0x01U << ETH_MACA3HR_ADDE_Pos)      ///< Address Filter Enable
#define ETH_MACA3HR_SELE_Pos                   (30)
#define ETH_MACA3HR_SELE                       (0x01U << ETH_MACA3HR_SELE_Pos)      ///< SA/DA Filter Select Enable
#define ETH_MACA3HR_MBYTEC_Pos                 (24)
#define ETH_MACA3HR_MBYTEC                     (0x3FU << ETH_MACA3HR_MBYTEC_Pos)    ///< Mask Byte Control
#define ETH_MACA3HR_MBYTEC_29_BIT              (0x20U << ETH_MACA3HR_MBYTEC_Pos)    ///< Mask MACADDH[15:8] bits
#define ETH_MACA3HR_MBYTEC_28_BIT              (0x10U << ETH_MACA3HR_MBYTEC_Pos)    ///< Mask MACADDH[7:0] bits
#define ETH_MACA3HR_MBYTEC_27_BIT              (0x08U << ETH_MACA3HR_MBYTEC_Pos)    ///< Mask MACADDH[7:0] bits
#define ETH_MACA3HR_MBYTEC_26_BIT              (0x04U << ETH_MACA3HR_MBYTEC_Pos)    ///< Mask MACADDL[23:16] bits
#define ETH_MACA3HR_MBYTEC_25_BIT              (0x02U << ETH_MACA3HR_MBYTEC_Pos)    ///< Mask MACADDL[15:8] bits
#define ETH_MACA3HR_MBYTEC_24_BIT              (0x01U << ETH_MACA3HR_MBYTEC_Pos)    ///< Mask MACADDL[7:0] bits
#define ETH_MACA3HR_MACADDH_Pos                (0)
#define ETH_MACA3HR_MACADDH                    (0xFFFFU << ETH_MACA3HR_MACADDH_Pos) ///< MAC Address Filter Address Value High

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA3LR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA3LR_MACADDL                    ((uint32_t)0xFFFFFFFF) ///< MAC Address Filter Address Value Low

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA4HR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA4HR_ADDE_Pos                   (31)
#define ETH_MACA4HR_ADDE                       (0x01U << ETH_MACA4HR_ADDE_Pos)      ///< Address Filter Enable
#define ETH_MACA4HR_SELE_Pos                   (30)
#define ETH_MACA4HR_SELE                       (0x01U << ETH_MACA4HR_SELE_Pos)      ///< SA/DA Filter Select Enable
#define ETH_MACA4HR_MBYTEC_Pos                 (24)
#define ETH_MACA4HR_MBYTEC                     (0x3FU << ETH_MACA4HR_MBYTEC_Pos)    ///< Mask Byte Control
#define ETH_MACA4HR_MBYTEC_29_BIT              (0x20U << ETH_MACA4HR_MBYTEC_Pos)    ///< Mask MACADDH[15:8] bits
#define ETH_MACA4HR_MBYTEC_28_BIT              (0x10U << ETH_MACA4HR_MBYTEC_Pos)    ///< Mask MACADDH[7:0] bits
#define ETH_MACA4HR_MBYTEC_27_BIT              (0x08U << ETH_MACA4HR_MBYTEC_Pos)    ///< Mask MACADDH[7:0] bits
#define ETH_MACA4HR_MBYTEC_26_BIT              (0x04U << ETH_MACA4HR_MBYTEC_Pos)    ///< Mask MACADDL[23:16] bits
#define ETH_MACA4HR_MBYTEC_25_BIT              (0x02U << ETH_MACA4HR_MBYTEC_Pos)    ///< Mask MACADDL[15:8] bits
#define ETH_MACA4HR_MBYTEC_24_BIT              (0x01U << ETH_MACA4HR_MBYTEC_Pos)    ///< Mask MACADDL[7:0] bits
#define ETH_MACA4HR_MACADDH_Pos                (0)
#define ETH_MACA4HR_MACADDH                    (0xFFFFU << ETH_MACA4HR_MACADDH_Pos) ///< MAC Address Filter Address Value High

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA4LR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA4LR_MACADDL                    ((uint32_t)0xFFFFFFFF) ///< MAC Address Filter Address Value Low

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA5HR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA5HR_ADDE_Pos                   (31)
#define ETH_MACA5HR_ADDE                       (0x01U << ETH_MACA5HR_ADDE_Pos)      ///< Address Filter Enable
#define ETH_MACA5HR_SELE_Pos                   (30)
#define ETH_MACA5HR_SELE                       (0x01U << ETH_MACA5HR_SELE_Pos)      ///< SA/DA Filter Select Enable
#define ETH_MACA5HR_MBYTEC_Pos                 (24)
#define ETH_MACA5HR_MBYTEC                     (0x3FU << ETH_MACA5HR_MBYTEC_Pos)    ///< Mask Byte Control
#define ETH_MACA5HR_MBYTEC_29_BIT              (0x20U << ETH_MACA5HR_MBYTEC_Pos)    ///< Mask MACADDH[15:8] bits
#define ETH_MACA5HR_MBYTEC_28_BIT              (0x10U << ETH_MACA5HR_MBYTEC_Pos)    ///< Mask MACADDH[7:0] bits
#define ETH_MACA5HR_MBYTEC_27_BIT              (0x08U << ETH_MACA5HR_MBYTEC_Pos)    ///< Mask MACADDH[7:0] bits
#define ETH_MACA5HR_MBYTEC_26_BIT              (0x04U << ETH_MACA5HR_MBYTEC_Pos)    ///< Mask MACADDL[23:16] bits
#define ETH_MACA5HR_MBYTEC_25_BIT              (0x02U << ETH_MACA5HR_MBYTEC_Pos)    ///< Mask MACADDL[15:8] bits
#define ETH_MACA5HR_MBYTEC_24_BIT              (0x01U << ETH_MACA5HR_MBYTEC_Pos)    ///< Mask MACADDL[7:0] bits
#define ETH_MACA5HR_MACADDH_Pos                (0)
#define ETH_MACA5HR_MACADDH                    (0xFFFFU << ETH_MACA5HR_MACADDH_Pos) ///< MAC Address Filter Address Value High
////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MACA5LR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACA5LR_MACADDL                    ((uint32_t)0xFFFFFFFF) ///< MAC Address Filter Address Value Low

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_ENET_MACVLTTR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACVLTTR_VLANS_Pos                 (18)
#define ETH_MACVLTTR_VLANS                     (0x01U << ETH_MACVLTTR_VLANS_Pos)   ///< VLAN Select
#define ETH_MACVLTTR_VLANC_Pos                 (16)
#define ETH_MACVLTTR_VLANC                     (0x01U << ETH_MACVLTTR_VLANC_Pos)   ///< VLAN Control
#define ETH_MACVLTTR_VLANC_0                   (0x00U << ETH_MACVLTTR_VLANC_Pos)   ///< Send directly without other actions
#define ETH_MACVLTTR_VLANC_1                   (0x01U << ETH_MACVLTTR_VLANC_Pos)   ///< Remove the TYPE field and the tag field from the VLAN frame
#define ETH_MACVLTTR_VLANC_2                   (0x02U << ETH_MACVLTTR_VLANC_Pos)   ///< Insert the value of the VLANV bit of this register as a tag field
#define ETH_MACVLTTR_VLANC_3                   (0x03U << ETH_MACVLTTR_VLANC_Pos)   ///< Replace the tag field in the original frame
#define ETH_MACVLTTR_VLANV_Pos                 (0)
#define ETH_MACVLTTR_VLANV                     (0xFFFFU << ETH_MACVLTTR_VLANV_Pos) ///< VLAN Value

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_ENET_MACVLHTR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MACVLHTR_VLHTAB_Pos                (0)
#define ETH_MACVLHTR_VLHTAB                    (0xFFFFU << ETH_MACVLHTR_VLHTAB_Pos) ///< VLAN Hash Table Value

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCCR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCCR_MCFHP                        ((uint32_t)0x00000020)       ///< MMC counter Full-Half preset
#define ETH_MMCCR_MCP                          ((uint32_t)0x00000010)       ///< MMC counter preset
#define ETH_MMCCR_MCF                          ((uint32_t)0x00000008)       ///< MMC Counter Freeze
#define ETH_MMCCR_ROR_Pos                      (2)
#define ETH_MMCCR_ROR                          (0x01U << ETH_MMCCR_ROR_Pos) ///< Reset on Read
#define ETH_MMCCR_CSR_Pos                      (1)
#define ETH_MMCCR_CSR                          (0x01U << ETH_MMCCR_CSR_Pos) ///< Counter Stop Rollover
#define ETH_MMCCR_CR_Pos                       (0)
#define ETH_MMCCR_CR                           (0x01U << ETH_MMCCR_CR_Pos)  ///< Counters Reset

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCRIR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCRIR_RGUF_Pos                    (17)
#define ETH_MMCRIR_RGUFS                       (0x01U << ETH_MMCRIR_RGUF_Pos)  ///< Set when Rx good unicast frames counter reaches half the maximum value
#define ETH_MMCRIR_RFAES_Pos                   (6)
#define ETH_MMCRIR_RFAES                       (0x01U << ETH_MMCRIR_RFAES_Pos) ///< Set when Rx alignment error counter reaches half the maximum value
#define ETH_MMCRIR_RFCES_Pos                   (5)
#define ETH_MMCRIR_RFCES                       (0x01U << ETH_MMCRIR_RFCES_Pos) ///< Set when Rx crc error counter reaches half the maximum value

//legacy define
#define ETH_MMCRIMR_RGUFM_Pos                  ETH_MMCRIR_RGUF_Pos
#define ETH_MMCRIMR_RGUFM                      ETH_MMCRIR_RGUFS
#define ETH_MMCRIMR_RFAEM_Pos                  ETH_MMCRIR_RFAES_Pos
#define ETH_MMCRIMR_RFAEM                      ETH_MMCRIR_RFAES
#define ETH_MMCRIMR_RFCEM_Pos                  ETH_MMCRIR_RFCES_Pos
#define ETH_MMCRIMR_RFCEM                      ETH_MMCRIR_RFCES

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCTIR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCTIR_TGFS_Pos                    (21)
#define ETH_MMCTIR_TGFS                        (0x01U << ETH_MMCTIR_TGFS_Pos)    ///< Set when Tx good frame count counter reaches half the maximum value
#define ETH_MMCTIR_TGFMSCS_Pos                 (15)
#define ETH_MMCTIR_TGFMSCS                     (0x01U << ETH_MMCTIR_TGFMSCS_Pos) ///< Set when Tx good multi col counter reaches half the maximum value
#define ETH_MMCTIR_TGFSCS_Pos                  (14)
#define ETH_MMCTIR_TGFSCS                      (0x01U << ETH_MMCTIR_TGFSCS_Pos)  ///< Set when Tx good single col counter reaches half the maximum value

//legacy define
#define ETH_MMCTIMR_TGFM_Pos                   ETH_MMCTIR_TGFS_Pos
#define ETH_MMCTIMR_TGFM                       ETH_MMCTIR_TGFS
#define ETH_MMCTIMR_TGFMSCM_Pos                ETH_MMCTIR_TGFMSCS_Pos
#define ETH_MMCTIMR_TGFMSCM                    ETH_MMCTIR_TGFMSCS
#define ETH_MMCTIMR_TGFSCM_Pos                 ETH_MMCTIR_TGFSCS_Pos
#define ETH_MMCTIMR_TGFSCM                     ETH_MMCTIR_TGFSCS

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCTGSCR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCTGSCR_TGSC                      (0xFFFFFFFFU) ///< Transfer Good Frame after Single-Collision
//legacy define
#define ETH_MMCTGFSCCR_TGFSCC                  ETH_MMCTGSCR_TGSC

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCTGMCR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCTGMCR_TGMC                      (0xFFFFFFFFU) ///< Transfer Good Frame after Multi-Collision
//legacy define
#define ETH_MMCTGFMSCCR_TGFMSCC                ETH_MMCTGMCR_TGMC

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCTGR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCTGR_MMCTG                       (0xFFFFFFFFU) ///< MMC Transfer Good Frame
//legacy define
#define ETH_MMCTGFCR_TGFC                      ETH_MMCTGR_MMCTG

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCRCRCER Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCRCRCER_RCRCE                    (0xFFFFFFFFU) ///< MMC Receive CRC Error Frame
//legacy define
#define ETH_MMCRFCECR_RFCEC                    ETH_MMCRCRCER_RCRCE

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCRALIER Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCRALIER_RALIE                    (0xFFFFFFFFU) ///< MMC Receive Align Error Frame
//legacy define
#define ETH_MMCRFAECR_RFAEC                    ETH_MMCRALIER_RALIE

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCRUGR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCRUGR_MMCRUG                     (0xFFFFFFFFU << ETH_MMCRUGR_MMCRUG_Pos) ///< MMC Receive Unicast Good Frame
//legacy define
#define ETH_MMCRGUFCR_RGUFC                    ETH_MMCRUGR_MMCRUG

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMABSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMABSR_TXPR_Pos                    (27)
#define ETH_DMABSR_TXPR                        (0x01U << ETH_DMABSR_TXPR_Pos) ///< Transfer Priority
#define ETH_DMABSR_MBST_Pos                    (26)
#define ETH_DMABSR_MBST                        (0x01U << ETH_DMABSR_MBST_Pos) ///< Mixed Burst
#define ETH_DMABSR_AAL_Pos                     (25)
#define ETH_DMABSR_AAL                         (0x01U << ETH_DMABSR_AAL_Pos)  ///< Address Align
#define ETH_DMABSR_MPBL_Pos                    (24)
#define ETH_DMABSR_MPBL                        (0x01U << ETH_DMABSR_MPBL_Pos) ///< Multiple PBL Mode
#define ETH_DMABSR_SPBL_Pos                    (23)
#define ETH_DMABSR_SPBL                        (0x01U << ETH_DMABSR_SPBL_Pos) ///< Separate PBL Mode
#define ETH_DMABSR_RPBL_Pos                    (17)
#define ETH_DMABSR_RPBL                        (0x3FU << ETH_DMABSR_RPBL_Pos) ///< Receive Programmable Burst Length
#define ETH_DMABSR_FBST_Pos                    (16)
#define ETH_DMABSR_FBST                        (0x01U << ETH_DMABSR_FBST_Pos) ///< Fixed Burst

#define ETH_DMABSR_FTPR_Pos                    (14)
#define ETH_DMABSR_FTPR                        (0x03U << ETH_DMABSR_FTPR_Pos) ///< Fixed Transfer Priority Ratio
#define ETH_DMABSR_FTPR_1_1                    (0x00U << ETH_DMABSR_FTPR_Pos) ///< 1:1
#define ETH_DMABSR_FTPR_2_1                    (0x01U << ETH_DMABSR_FTPR_Pos) ///< 2:1
#define ETH_DMABSR_FTPR_3_1                    (0x02U << ETH_DMABSR_FTPR_Pos) ///< 3:1
#define ETH_DMABSR_FTPR_4_1                    (0x03U << ETH_DMABSR_FTPR_Pos) ///< 4:1

#define ETH_DMABSR_TPBL_Pos                    (8)
#define ETH_DMABSR_TPBL                        (0x3FU << ETH_DMABSR_TPBL_Pos) ///< Transfer Programmable Burst Length
#define ETH_DMABSR_TPBL_1Beat                  (0x01U << ETH_DMABSR_TPBL_Pos) ///< maximum number of beats to be transferred in one TxDMA (or both) transaction is 1
#define ETH_DMABSR_TPBL_2Beat                  (0x02U << ETH_DMABSR_TPBL_Pos) ///< maximum number of beats to be transferred in one TxDMA (or both) transaction is 2
#define ETH_DMABSR_TPBL_4Beat                  (0x04U << ETH_DMABSR_TPBL_Pos) ///< maximum number of beats to be transferred in one TxDMA (or both) transaction is 4
#define ETH_DMABSR_TPBL_8Beat                  (0x08U << ETH_DMABSR_TPBL_Pos) ///< maximum number of beats to be transferred in one TxDMA (or both) transaction is 8
#define ETH_DMABSR_TPBL_16Beat                 (0x10U << ETH_DMABSR_TPBL_Pos) ///< maximum number of beats to be transferred in one TxDMA (or both) transaction is 16
#define ETH_DMABSR_TPBL_32Beat                 (0x20U << ETH_DMABSR_TPBL_Pos) ///< maximum number of beats to be transferred in one TxDMA (or both) transaction is 32
#define ETH_DMABSR_DSEN_Pos                    (7)
#define ETH_DMABSR_DSEN                        (0x01U << ETH_DMABSR_DSEN_Pos) ///< Advanced Descriptor Enable
#define ETH_DMABSR_DSL_Pos                     (2)
#define ETH_DMABSR_DSL                         (0x1FU << ETH_DMABSR_DSL_Pos)  ///< Descriptor Skip Length
#define ETH_DMABSR_DMAA_Pos                    (1)
#define ETH_DMABSR_DMAA                        (0x01U << ETH_DMABSR_DMAA_Pos) ///< DMA Arbiter
#define ETH_DMABSR_SR_Pos                      (0)
#define ETH_DMABSR_SR                          (0x01U << ETH_DMABSR_SR_Pos)   ///< Software Reset

//legacy define
#define ETH_DMABMR_FB_Pos                      ETH_DMABSR_FBST_Pos
#define ETH_DMABMR_FB                          ETH_DMABSR_FBST
#define ETH_DMABMR_RTPR_Pos                    ETH_DMABSR_FTPR_Pos
#define ETH_DMABMR_RTPR                        ETH_DMABSR_FTPR
#define ETH_DMABMR_RTPR_1_1                    ETH_DMABSR_FTPR_1_1
#define ETH_DMABMR_RTPR_2_1                    ETH_DMABSR_FTPR_2_1
#define ETH_DMABMR_RTPR_3_1                    ETH_DMABSR_FTPR_3_1
#define ETH_DMABMR_RTPR_4_1                    ETH_DMABSR_FTPR_4_1
#define ETH_DMABMR_PBL_Pos                     ETH_DMABSR_TPBL_Pos
#define ETH_DMABMR_PBL                         ETH_DMABSR_TPBL
#define ETH_DMABMR_PBL_1Beat                   ETH_DMABSR_TPBL_1Beat
#define ETH_DMABMR_PBL_2Beat                   ETH_DMABSR_TPBL_2Beat
#define ETH_DMABMR_PBL_4Beat                   ETH_DMABSR_TPBL_4Beat
#define ETH_DMABMR_PBL_8Beat                   ETH_DMABSR_TPBL_8Beat
#define ETH_DMABMR_PBL_16Beat                  ETH_DMABSR_TPBL_16Beat
#define ETH_DMABMR_PBL_32Beat                  ETH_DMABSR_TPBL_32Beat
#define ETH_DMABMR_DSL_Pos                     ETH_DMABSR_DSL_Pos
#define ETH_DMABMR_DSL                         ETH_DMABSR_DSL
#define ETH_DMABMR_DA_Pos                      ETH_DMABSR_DMAA_Pos
#define ETH_DMABMR_DA                          ETH_DMABSR_DMAA
#define ETH_DMABMR_SR_Pos                      ETH_DMABSR_SR_Pos
#define ETH_DMABMR_SR                          ETH_DMABSR_SR

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMATXPDR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMATXPDR_TXPD                      (0xFFFFFFFFU) ///< Transmit poll demand
//legacy define
#define ETH_DMATPDR_TPD                        ETH_DMATXPDR_TXPD

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMARXPDR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMARXPDR_RXPD                      (0xFFFFFFFFU) ///< Receive poll demand
//legacy define
#define ETH_DMARPDR_RPD                        ETH_DMARXPDR_RXPD

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMARXDSAR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMARXDSAR_RXDSA                    (0xFFFFFFFFU) ///< Receive Descriptor Address
//legacy define
#define ETH_DMARDLAR_SRL                       ETH_DMARXDSAR_RXDSA

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMATXDSAR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMATXDSAR_TXDSA                    (0xFFFFFFFFU) ///< Start of transmit list
//legacy define
#define ETH_DMATDLAR_STL                       ETH_DMATXDSAR_TXDSA

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMASR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMASR_PTPS_Pos                     (29)
#define ETH_DMASR_PTPS                         (0x01U << ETH_DMASR_PTPS_Pos) ///< PTP status
#define ETH_DMASR_PMTS_Pos                     (28)
#define ETH_DMASR_PMTS                         (0x01U << ETH_DMASR_PMTS_Pos) ///< PMT status
#define ETH_DMASR_MMCS_Pos                     (27)
#define ETH_DMASR_MMCS                         (0x01U << ETH_DMASR_MMCS_Pos) ///< MMC status
#define ETH_DMASR_LIS_Pos                      (26)
#define ETH_DMASR_LIS                          (0x01U << ETH_DMASR_LIS_Pos)  ///< GMAC Line interface Status
//???thy bit 26 is Reserved in UM
#define ETH_DMASR_EBS_Pos                      (23)
#define ETH_DMASR_EBS                          (0x07U << ETH_DMASR_EBS_Pos)  ///< Error bits status
#define ETH_DMASR_EBS_DescAccess               (0x04U << ETH_DMASR_EBS_Pos)  ///< Error bits 0-data buffer, 1-desc. access
#define ETH_DMASR_EBS_ReadTransf               (0x02U << ETH_DMASR_EBS_Pos)  ///< Error bits 0-write trnsf, 1-read transfr
#define ETH_DMASR_EBS_DataTransfTx             (0x01U << ETH_DMASR_EBS_Pos)  ///< Error bits 0-Rx DMA, 1-Tx DMA
#define ETH_DMASR_TPS_Pos                      (20)
#define ETH_DMASR_TPS                          (0x007U << ETH_DMASR_TPS_Pos) ///< Transmit process state
#define ETH_DMASR_TPS_Stopped                  (0x000U << ETH_DMASR_TPS_Pos) ///< Stopped - Reset or Stop Tx Command issued
#define ETH_DMASR_TPS_Fetching                 (0x001U << ETH_DMASR_TPS_Pos) ///< Running - fetching the Tx descriptor
#define ETH_DMASR_TPS_Waiting                  (0x002U << ETH_DMASR_TPS_Pos) ///< Running - waiting for status
#define ETH_DMASR_TPS_Reading                  (0x003U << ETH_DMASR_TPS_Pos) ///< Running - reading the data from host memory
#define ETH_DMASR_TPS_Suspended                (0x006U << ETH_DMASR_TPS_Pos) ///< Suspended - Tx Descriptor unavailabe
#define ETH_DMASR_TPS_Closing                  (0x007U << ETH_DMASR_TPS_Pos) ///< Running - closing Rx descriptor
#define ETH_DMASR_RPS_Pos                      (17)
#define ETH_DMASR_RPS                          (0x07U << ETH_DMASR_RPS_Pos)  ///< Receive process state
#define ETH_DMASR_RPS_Stopped                  (0x00U << ETH_DMASR_RPS_Pos)  ///< Stopped - Reset or Stop Rx Command issued
#define ETH_DMASR_RPS_Fetching                 (0x01U << ETH_DMASR_RPS_Pos)  ///< Running - fetching the Rx descriptor
#define ETH_DMASR_RPS_Waiting                  (0x03U << ETH_DMASR_RPS_Pos)  ///< Running - waiting for packet
#define ETH_DMASR_RPS_Suspended                (0x04U << ETH_DMASR_RPS_Pos)  ///< Suspended - Rx Descriptor unavailable
#define ETH_DMASR_RPS_Closing                  (0x05U << ETH_DMASR_RPS_Pos)  ///< Running - closing descriptor
#define ETH_DMASR_RPS_Queuing                  (0x07U << ETH_DMASR_RPS_Pos)  ///< Running - queuing the recieve frame into host memory
#define ETH_DMASR_NIS_Pos                      (16)
#define ETH_DMASR_NIS                          (0x01U << ETH_DMASR_NIS_Pos)  ///< Normal interrupt summary
#define ETH_DMASR_AIS_Pos                      (15)
#define ETH_DMASR_AIS                          (0x01U << ETH_DMASR_AIS_Pos)  ///< Abnormal interrupt summary
#define ETH_DMASR_ERS_Pos                      (14)
#define ETH_DMASR_ERS                          (0x01U << ETH_DMASR_ERS_Pos)  ///< Early receive status
#define ETH_DMASR_FBES_Pos                     (13)
#define ETH_DMASR_FBES                         (0x01U << ETH_DMASR_FBES_Pos) ///< Fatal bus error status
#define ETH_DMASR_ETS_Pos                      (10)
#define ETH_DMASR_ETS                          (0x01U << ETH_DMASR_ETS_Pos)  ///< Early transmit status
#define ETH_DMASR_RWTS_Pos                     (9)
#define ETH_DMASR_RWTS                         (0x01U << ETH_DMASR_RWTS_Pos) ///< Receive watchdog timeout status
#define ETH_DMASR_RPSS_Pos                     (8)
#define ETH_DMASR_RPSS                         (0x01U << ETH_DMASR_RPSS_Pos) ///< Receive process stopped status
#define ETH_DMASR_RBUS_Pos                     (7)
#define ETH_DMASR_RBUS                         (0x01U << ETH_DMASR_RBUS_Pos) ///< Receive buffer unavailable status
#define ETH_DMASR_RS_Pos                       (6)
#define ETH_DMASR_RS                           (0x01U << ETH_DMASR_RS_Pos)   ///< Receive status
#define ETH_DMASR_UNS_Pos                      (5)
#define ETH_DMASR_UNS                          (0x01U << ETH_DMASR_UNS_Pos)  ///< Transmit underflow status
#define ETH_DMASR_OVS_Pos                      (4)
#define ETH_DMASR_OVS                          (0x01U << ETH_DMASR_OVS_Pos)  ///< Receive overflow status
#define ETH_DMASR_TJTS_Pos                     (3)
#define ETH_DMASR_TJTS                         (0x01U << ETH_DMASR_TJTS_Pos) ///< Transmit jabber timeout status
#define ETH_DMASR_TBUS_Pos                     (2)
#define ETH_DMASR_TBUS                         (0x01U << ETH_DMASR_TBUS_Pos) ///< Transmit buffer unavailable status
#define ETH_DMASR_TPSS_Pos                     (1)
#define ETH_DMASR_TPSS                         (0x01U << ETH_DMASR_TPSS_Pos) ///< Transmit process stopped status
#define ETH_DMASR_TS_Pos                       (0)
#define ETH_DMASR_TS                           (0x01U << ETH_DMASR_TS_Pos)   ///< Transmit status

//legacy define
#define ETH_DMASR_TUS                          ETH_DMASR_UNS
#define ETH_DMASR_ROS                          ETH_DMASR_OVS

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMAMDR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMAMDR_DTCOE_Pos                   (26)
#define ETH_DMAMDR_DTCOE                       (0x01U << ETH_DMAMDR_DTCOE_Pos) ///< Drop of TCP/IP Checksum Error Frame
#define ETH_DMAMDR_RSF_Pos                     (25)
#define ETH_DMAMDR_RSF                         (0x01U << ETH_DMAMDR_RSF_Pos)   ///< Receive Store & Forward
#define ETH_DMAMDR_DFRF_Pos                    (24)
#define ETH_DMAMDR_DFRF                        (0x01U << ETH_DMAMDR_DFRF_Pos)  ///< Disable Flush of Receive Frame
#define ETH_DMAMDR_TSF_Pos                     (21)
#define ETH_DMAMDR_TSF                         (0x01U << ETH_DMAMDR_TSF_Pos)   ///< Transmit store and forward
#define ETH_DMAMDR_FTF_Pos                     (20)
#define ETH_DMAMDR_FTF                         (0x01U << ETH_DMAMDR_FTF_Pos)   ///< Flush transmit FIFO
#define ETH_DMAMDR_TTC_Pos                     (14)
#define ETH_DMAMDR_TTC                         (0x07U << ETH_DMAMDR_TTC_Pos)   ///< Transmit threshold control
#define ETH_DMAMDR_TTC_64Bytes                 (0x00U << ETH_DMAMDR_TTC_Pos)   ///< threshold level of the MTL Transmit FIFO is 64 Bytes
#define ETH_DMAMDR_TTC_128Bytes                (0x01U << ETH_DMAMDR_TTC_Pos)   ///< threshold level of the MTL Transmit FIFO is 128 Bytes
#define ETH_DMAMDR_TTC_192Bytes                (0x02U << ETH_DMAMDR_TTC_Pos)   ///< threshold level of the MTL Transmit FIFO is 192 Bytes
#define ETH_DMAMDR_TTC_256Bytes                (0x03U << ETH_DMAMDR_TTC_Pos)   ///< threshold level of the MTL Transmit FIFO is 256 Bytes
#define ETH_DMAMDR_TTC_40Bytes                 (0x04U << ETH_DMAMDR_TTC_Pos)   ///< threshold level of the MTL Transmit FIFO is 40 Bytes
#define ETH_DMAMDR_TTC_32Bytes                 (0x05U << ETH_DMAMDR_TTC_Pos)   ///< threshold level of the MTL Transmit FIFO is 32 Bytes
#define ETH_DMAMDR_TTC_24Bytes                 (0x06U << ETH_DMAMDR_TTC_Pos)   ///< threshold level of the MTL Transmit FIFO is 24 Bytes
#define ETH_DMAMDR_TTC_16Bytes                 (0x07U << ETH_DMAMDR_TTC_Pos)   ///< threshold level of the MTL Transmit FIFO is 16 Bytes
#define ETH_DMAMDR_ST_Pos                      (13)
#define ETH_DMAMDR_ST                          (0x01U << ETH_DMAMDR_ST_Pos)    ///< Start/stop transmission command
#define ETH_DMAMDR_FEF_Pos                     (7)
#define ETH_DMAMDR_FEF                         (0x01U << ETH_DMAMDR_FEF_Pos)   ///< Forward error frames
#define ETH_DMAMDR_FUGF_Pos                    (6)
#define ETH_DMAMDR_FUGF                        (0x01U << ETH_DMAMDR_FUGF_Pos)  ///< Forward undersized good frames
#define ETH_DMAMDR_DGF_Pos                     (5)
#define ETH_DMAMDR_DGF                         (0x01U << ETH_DMAMDR_DGF_Pos)   ///< Drop Giant Frame
#define ETH_DMAMDR_RTC_Pos                     (3)
#define ETH_DMAMDR_RTC                         (0x03U << ETH_DMAMDR_RTC_Pos)   ///< receive threshold control
#define ETH_DMAMDR_RTC_64Bytes                 (0x00U << ETH_DMAMDR_RTC_Pos)   ///< threshold level of the MTL Receive FIFO is 64 Bytes
#define ETH_DMAMDR_RTC_32Bytes                 (0x01U << ETH_DMAMDR_RTC_Pos)   ///< threshold level of the MTL Receive FIFO is 32 Bytes
#define ETH_DMAMDR_RTC_96Bytes                 (0x02U << ETH_DMAMDR_RTC_Pos)   ///< threshold level of the MTL Receive FIFO is 96 Bytes
#define ETH_DMAMDR_RTC_128Bytes                (0x03U << ETH_DMAMDR_RTC_Pos)   ///< threshold level of the MTL Receive FIFO is 128 Bytes
#define ETH_DMAMDR_OSF_Pos                     (2)
#define ETH_DMAMDR_OSF                         (0x01U << ETH_DMAMDR_OSF_Pos)   ///< operate on second frame
#define ETH_DMAMDR_SR_Pos                      (1)
#define ETH_DMAMDR_SR                          (0x01U << ETH_DMAMDR_SR_Pos)    ///< Start/stop receive

//legacy define
#define ETH_DMAOMR_TSF_Pos                     ETH_DMAMDR_TSF_Pos
#define ETH_DMAOMR_TSF                         ETH_DMAMDR_TSF
#define ETH_DMAOMR_FTF_Pos                     ETH_DMAMDR_FTF_Pos
#define ETH_DMAOMR_FTF                         ETH_DMAMDR_FTF
#define ETH_DMAOMR_TTC_Pos                     ETH_DMAMDR_TTC_Pos
#define ETH_DMAOMR_TTC                         ETH_DMAMDR_TTC
#define ETH_DMAOMR_TTC_64Bytes                 ETH_DMAMDR_TTC_64Bytes
#define ETH_DMAOMR_TTC_128Bytes                ETH_DMAMDR_TTC_128Bytes
#define ETH_DMAOMR_TTC_192Bytes                ETH_DMAMDR_TTC_192Bytes
#define ETH_DMAOMR_TTC_256Bytes                ETH_DMAMDR_TTC_256Bytes
#define ETH_DMAOMR_TTC_40Bytes                 ETH_DMAMDR_TTC_40Bytes
#define ETH_DMAOMR_TTC_32Bytes                 ETH_DMAMDR_TTC_32Bytes
#define ETH_DMAOMR_TTC_24Bytes                 ETH_DMAMDR_TTC_24Bytes
#define ETH_DMAOMR_TTC_16Bytes                 ETH_DMAMDR_TTC_16Bytes
#define ETH_DMAOMR_ST_Pos                      ETH_DMAMDR_ST_Pos
#define ETH_DMAOMR_ST                          ETH_DMAMDR_ST
#define ETH_DMAOMR_FEF_Pos                     ETH_DMAMDR_FEF_Pos
#define ETH_DMAOMR_FEF                         ETH_DMAMDR_FEF
#define ETH_DMAOMR_FUGF_Pos                    ETH_DMAMDR_FUGF_Pos
#define ETH_DMAOMR_FUGF                        ETH_DMAMDR_FUGF
#define ETH_DMAOMR_RTC_Pos                     ETH_DMAMDR_RTC_Pos
#define ETH_DMAOMR_RTC                         ETH_DMAMDR_RTC
#define ETH_DMAOMR_RTC_64Bytes                 ETH_DMAMDR_RTC_64Bytes
#define ETH_DMAOMR_RTC_32Bytes                 ETH_DMAMDR_RTC_32Bytes
#define ETH_DMAOMR_RTC_96Bytes                 ETH_DMAMDR_RTC_96Bytes
#define ETH_DMAOMR_RTC_128Bytes                ETH_DMAMDR_RTC_128Bytes
#define ETH_DMAOMR_OSF_Pos                     ETH_DMAMDR_OSF_Pos
#define ETH_DMAOMR_OSF                         ETH_DMAMDR_OSF
#define ETH_DMAOMR_SR_Pos                      ETH_DMAMDR_SR_Pos
#define ETH_DMAOMR_SR                          ETH_DMAMDR_SR

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMAIR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMAIR_NIE_Pos                      (16)
#define ETH_DMAIR_NIE                          (0x01U << ETH_DMAIR_NIE_Pos) ///< Normal interrupt summary enable
#define ETH_DMAIR_AIE_Pos                      (15)
#define ETH_DMAIR_AIE                          (0x01U << ETH_DMAIR_AIE_Pos) ///< Abnormal interrupt summary enable
#define ETH_DMAIR_ERE_Pos                      (14)
#define ETH_DMAIR_ERE                          (0x01U << ETH_DMAIR_ERE_Pos) ///< Early receive interrupt enable
#define ETH_DMAIR_FBE_Pos                      (13)
#define ETH_DMAIR_FBE                          (0x01U << ETH_DMAIR_FBE_Pos) ///< Fatal bus error interrupt enable
#define ETH_DMAIR_ETE_Pos                      (10)
#define ETH_DMAIR_ETE                          (0x01U << ETH_DMAIR_ETE_Pos) ///< Early transmit interrupt enable
#define ETH_DMAIR_RWE_Pos                      (9)
#define ETH_DMAIR_RWE                          (0x01U << ETH_DMAIR_RWE_Pos) ///< Receive watchdog timeout interrupt enable
#define ETH_DMAIR_RSE_Pos                      (8)
#define ETH_DMAIR_RSE                          (0x01U << ETH_DMAIR_RSE_Pos) ///< Receive process stopped interrupt enable
#define ETH_DMAIR_RUE_Pos                      (7)
#define ETH_DMAIR_RUE                          (0x01U << ETH_DMAIR_RUE_Pos) ///< Receive buffer unavailable interrupt enable
#define ETH_DMAIR_RCE_Pos                      (6)
#define ETH_DMAIR_RCE                          (0x01U << ETH_DMAIR_RCE_Pos) ///< Receive interrupt enable
#define ETH_DMAIR_UNE_Pos                      (5)
#define ETH_DMAIR_UNE                          (0x01U << ETH_DMAIR_UNE_Pos) ///< Transmit Underflow interrupt enable
#define ETH_DMAIR_OVE_Pos                      (4)
#define ETH_DMAIR_OVE                          (0x01U << ETH_DMAIR_OVE_Pos) ///< Receive Overflow interrupt enable
#define ETH_DMAIR_TJE_Pos                      (3)
#define ETH_DMAIR_TJE                          (0x01U << ETH_DMAIR_TJE_Pos) ///< Transmit jabber timeout interrupt enable
#define ETH_DMAIR_TUE_Pos                      (2)
#define ETH_DMAIR_TUE                          (0x01U << ETH_DMAIR_TUE_Pos) ///< Transmit buffer unavailable interrupt enable
#define ETH_DMAIR_TSE_Pos                      (1)
#define ETH_DMAIR_TSE                          (0x01U << ETH_DMAIR_TSE_Pos) ///< Transmit process stopped interrupt enable
#define ETH_DMAIR_TCE_Pos                      (0)
#define ETH_DMAIR_TCE                          (0x01U << ETH_DMAIR_TCE_Pos) ///< Transmit interrupt enable

//legacy define
#define ETH_DMAIER_NISE_Pos                    ETH_DMAIR_NIE_Pos
#define ETH_DMAIER_NISE                        ETH_DMAIR_NIE
#define ETH_DMAIER_AISE_Pos                    ETH_DMAIR_AIE_Pos
#define ETH_DMAIER_AISE                        ETH_DMAIR_AIE
#define ETH_DMAIER_ERIE_Pos                    ETH_DMAIR_ERE_Pos
#define ETH_DMAIER_ERIE                        ETH_DMAIR_ERE
#define ETH_DMAIER_FBEIE_Pos                   ETH_DMAIR_FBE_Pos
#define ETH_DMAIER_FBEIE                       ETH_DMAIR_FBE
#define ETH_DMAIER_ETIE_Pos                    ETH_DMAIR_ETE_Pos
#define ETH_DMAIER_ETIE                        ETH_DMAIR_ETE
#define ETH_DMAIER_RWTIE_Pos                   ETH_DMAIR_RWE_Pos
#define ETH_DMAIER_RWTIE                       ETH_DMAIR_RWE
#define ETH_DMAIER_RPSIE_Pos                   ETH_DMAIR_RSE_Pos
#define ETH_DMAIER_RPSIE                       ETH_DMAIR_RSE
#define ETH_DMAIER_RBUIE_Pos                   ETH_DMAIR_RUE_Pos
#define ETH_DMAIER_RBUIE                       ETH_DMAIR_RUE
#define ETH_DMAIER_RIE_Pos                     ETH_DMAIR_RCE_Pos
#define ETH_DMAIER_RIE                         ETH_DMAIR_RCE
#define ETH_DMAIER_TUIE_Pos                    ETH_DMAIR_UNE_Pos
#define ETH_DMAIER_TUIE                        ETH_DMAIR_UNE
#define ETH_DMAIER_ROIE_Pos                    ETH_DMAIR_OVE_Pos
#define ETH_DMAIER_ROIE                        ETH_DMAIR_OVE
#define ETH_DMAIER_TJTIE_Pos                   ETH_DMAIR_TJE_Pos
#define ETH_DMAIER_TJTIE                       ETH_DMAIR_TJE
#define ETH_DMAIER_TBUIE_Pos                   ETH_DMAIR_TUE_Pos
#define ETH_DMAIER_TBUIE                       ETH_DMAIR_TUE
#define ETH_DMAIER_TPSIE_Pos                   ETH_DMAIR_TSE_Pos
#define ETH_DMAIER_TPSIE                       ETH_DMAIR_TSE
#define ETH_DMAIER_TIE_Pos                     ETH_DMAIR_TCE_Pos
#define ETH_DMAIER_TIE                         ETH_DMAIR_TCE

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMAFLCR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMAFLCR_OVFF_Pos                   (28)
#define ETH_DMAFLCR_OVFF                       (0x01U << ETH_DMAFLCR_OVFF_Pos)   ///< OVF Count Overflow Flag

#define ETH_DMAFLCR_OVFC_Pos                   (17)
#define ETH_DMAFLCR_OVFC                       (0x7FFU << ETH_DMAFLCR_OVFC_Pos)  ///< OVF Count

#define ETH_DMAFLCR_BUAF_Pos                   (16)
#define ETH_DMAFLCR_BUAF                       (0x01U << ETH_DMAFLCR_BUAF_Pos)   ///< BUA Count Overflow Flag

#define ETH_DMAFLCR_BUAC_Pos                   (0)
#define ETH_DMAFLCR_BUAC                       (0xFFFFU << ETH_DMAFLCR_BUAC_Pos) ///< BUA Count Overflow Flag

//legacy define
#define ETH_DMAMFBOCR_OFOC_Pos                 ETH_DMAFLCR_OVFF_Pos
#define ETH_DMAMFBOCR_OFOC                     ETH_DMAFLCR_OVFF

#define ETH_DMAMFBOCR_MFA_Pos                  ETH_DMAFLCR_OVFC_Pos
#define ETH_DMAMFBOCR_MFA                      ETH_DMAFLCR_OVFC

#define ETH_DMAMFBOCR_OMFC_Pos                 ETH_DMAFLCR_BUAF_Pos
#define ETH_DMAMFBOCR_OMFC                     ETH_DMAFLCR_BUAF

#define ETH_DMAMFBOCR_MFC_Pos                  ETH_DMAFLCR_BUAC_Pos
#define ETH_DMAMFBOCR_MFC                      ETH_DMAFLCR_BUAC

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMAWDTR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMAWDTR_RIWT_Pos                   (0)
#define ETH_DMAWDTR_RIWT                       (0xFFU << ETH_DMAWDTR_RIWT_Pos) ///< Receive Interrupt Watchdog Timer Counter

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMACURTXDSAR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMACURTXDSAR_CURTXDSA              (0xFFFFFFFFU) ///< Current Transfer Descriptor Address
//legacy define
#define ETH_DMACHTDR_HTDAP                     ETH_DMACURTXDSAR_CURTXDSA

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMACURRXDSAR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMACURRXDSAR_CURRXDSA              (0xFFFFFFFFU) ///< Current Receive Descriptor Address
//legacy define
#define ETH_DMACHRDR_HRDAP                     ETH_DMACURRXDSAR_CURRXDSA

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMACURTXBFAR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMACURTXBFAR_CURTXBFA              (0xFFFFFFFFU) ///< Current Transfer Buffer Address
//legacy define
#define ETH_DMACHTBAR_HTBAP                    ETH_DMACURTXBFAR_CURTXBFA

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_DMACURRXBFAR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_DMACURRXBFAR_CURRXBFA              (0xFFFFFFFFU) ///< Current Receive Buffer Address
//legacy define
#define ETH_DMACHRBAR_HRBAP                    ETH_DMACURRXBFAR_CURRXBFA

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPCR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPCR_PTPDAF_Pos                   (18)
#define ETH_PTPCR_PTPDAF                       (0x01U << ETH_PTPCR_PTPDAF_Pos)  ///< PTP DA Filter
#define ETH_PTPCR_PTPTYPS_Pos                  (14)
#define ETH_PTPCR_PTPTYPS                      (0x0FU << ETH_PTPCR_PTPTYPS_Pos) ///< PTP Message Type
#define ETH_PTPCR_PTPIPV4_Pos                  (13)
#define ETH_PTPCR_PTPIPV4                      (0xFFU << ETH_PTPCR_PTPIPV4_Pos) ///< PTP Over UDP-IPv4
#define ETH_PTPCR_PTPIPV6_Pos                  (12)
#define ETH_PTPCR_PTPIPV6                      (0xFFU << ETH_PTPCR_PTPIPV6_Pos) ///< PTP Over UDP-IPv6
#define ETH_PTPCR_PTPETH_Pos                   (11)
#define ETH_PTPCR_PTPETH                       (0xFFU << ETH_PTPCR_PTPETH_Pos)  ///< PTP Over Ethernet
#define ETH_PTPCR_PTPVER_Pos                   (10)
#define ETH_PTPCR_PTPVER                       (0xFFU << ETH_PTPCR_PTPVER_Pos)  ///< PTP Version
#define ETH_PTPCR_PTPNSS_Pos                   (9)
#define ETH_PTPCR_PTPNSS                       (0xFFU << ETH_PTPCR_PTPNSS_Pos)  ///< PTP Nanosecond Select
#define ETH_PTPCR_PTPEALL_Pos                  (8)
#define ETH_PTPCR_PTPEALL                      (0xFFU << ETH_PTPCR_PTPEALL_Pos) ///< PTP Timestamp Enable All
#define ETH_PTPCR_PTPADUP_Pos                  (5)
#define ETH_PTPCR_PTPADUP                      (0xFFU << ETH_PTPCR_PTPADUP_Pos) ///< PTP Addend Update
#define ETH_PTPCR_PTPINT_Pos                   (4)
#define ETH_PTPCR_PTPINT                       (0xFFU << ETH_PTPCR_PTPINT_Pos)  ///< PTP Interrupt Enable
#define ETH_PTPCR_PTPUP_Pos                    (3)
#define ETH_PTPCR_PTPUP                        (0xFFU << ETH_PTPCR_PTPUP_Pos)   ///< PTP Second/Nanosecond Update
#define ETH_PTPCR_PTPINI_Pos                   (2)
#define ETH_PTPCR_PTPINI                       (0xFFU << ETH_PTPCR_PTPINI_Pos)  ///< PTP Interrupt Enable
#define ETH_PTPCR_PTPCS_Pos                    (1)
#define ETH_PTPCR_PTPCS                        (0xFFU << ETH_PTPCR_PTPCS_Pos)   ///< PTP Addend Update
#define ETH_PTPCR_PTPEN_Pos                    (0)
#define ETH_PTPCR_PTPEN                        (0xFFU << ETH_PTPCR_PTPEN_Pos)   ///< PTP Interrupt Enable

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPNSAR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPNSAR_NSADD_Pos                  (0)
#define ETH_PTPNSAR_NSADD                      (0xFFU << ETH_PTPNSAR_NSADD_Pos) ///< Nanosecond Addend

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPSBSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPSBSR_SBSEC_Pos                  (0)
#define ETH_PTPSBSR_SBSEC                      (0xFFFFFFFFU << ETH_PTPNSAR_SBSEC_Pos) ///< System Base Second

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPSNSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPSNSR_SNSEC_Pos                  (0)
#define ETH_PTPSNSR_SNSEC                      (0x7FFFFFFFU << ETH_PTPSNSR_SNSEC_Pos) ///< System Nanosecond

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPUBSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPUBSR_UBSEC_Pos                  (0)
#define ETH_PTPUBSR_UBSEC                      (0xFFFFFFFFU << ETH_PTPUBSR_UBSEC_Pos) ///< Updata Base Second

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPUNSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPUNSR_UPNSEC_Pos                 (31)
#define ETH_PTPUNSR_UPNSEC                     (0x01U << ETH_PTPUNSR_UPNSEC_Pos)      ///< Update Nanosecond Select
#define ETH_PTPUNSR_UNSEC_Pos                  (0)
#define ETH_PTPUNSR_UNSEC                      (0x7FFFFFFFU << ETH_PTPUNSR_UNSEC_Pos) ///< Update Nanosecond

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPBSAR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPBSAR_BSADD_Pos                  (0)
#define ETH_PTPBSAR_BSADD                      (0xFFFFFFFFU << ETH_PTPBSAR_BSADD_Pos) ///< Base Addend

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPTBSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPTBSR_TBSEC_Pos                  (0)
#define ETH_PTPTBSR_TBSEC                      (0xFFFFFFFFU << ETH_PTPTBSR_TBSEC_Pos) ///< Target Base Second

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPTNSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPTNSR_TNSEC_Pos                  (0)
#define ETH_PTPTNSR_TNSEC                      (0x7FFFFFFFU << ETH_PTPTNSR_TNSEC_Pos) ///< target nanosecond
//legacy define
#define ETH_PTPTNSR_TBSEC_Pos                  ETH_PTPTNSR_TNSEC_Pos
#define ETH_PTPTNSR_TBSEC                      ETH_PTPTNSR_TNSEC

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPSR_TSER1_Pos                    (5)
#define ETH_PTPSR_TSER1                        (0x01U << ETH_PTPSR_TSER1_Pos) ///< Target Second Error 1
#define ETH_PTPSR_TSTA1_Pos                    (4)
#define ETH_PTPSR_TSTA1                        (0x01U << ETH_PTPSR_TSTA1_Pos) ///< Target Second Time Arrived 1
#define ETH_PTPSR_TSER0_Pos                    (3)
#define ETH_PTPSR_TSER0                        (0x01U << ETH_PTPSR_TSER0_Pos) ///< Target Second Error 0
#define ETH_PTPSR_TSTA0_Pos                    (1)
#define ETH_PTPSR_TSTA0                        (0x01U << ETH_PTPSR_TSTA0_Pos) ///< Target Second Time Arrived 0
#define ETH_PTPSR_TSOVF_Pos                    (0)
#define ETH_PTPSR_TSOVF                        (0x01U << ETH_PTPSR_TSOVF_Pos) ///< Timestamp Overflow

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_PTPPPSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_PTPPPSR_TTSEL1_Pos                 (13)
#define ETH_PTPPPSR_TTSEL1                     (0x03U << ETH_PTPPPSR_TTSEL1_Pos)  ///< Target Time Event Select 1
#define ETH_PTPPPSR_TTSEL1_0                   (0x00U << ETH_PTPPPSR_TTSEL1_Pos)  ///< register 0 (ENET_PTPTBSR0/ENET_PTPTNSR0) is only used for interrupt outputevents
#define ETH_PTPPPSR_TTSEL1_2                   (0x02U << ETH_PTPPPSR_TTSEL1_Pos)  ///< register 0 is used for interrupt output events and PPS0 single output event
#define ETH_PTPPPSR_TTSEL1_3                   (0x03U << ETH_PTPPPSR_TTSEL1_Pos)  ///< register 0(ENET_PTPTBSR0/ENET_PTPTNSR0) is only used for PPS0 single output event

#define ETH_PTPPPSR_PPSOUT1_Pos                (8)
#define ETH_PTPPPSR_PPSOUT1                    (0x07U << ETH_PTPPPSR_PPSOUT1_Pos) ///< PPS Output Control 1

#define ETH_PTPPPSR_TTSEL0_Pos                 (5)
#define ETH_PTPPPSR_TTSEL0                     (0x03U << ETH_PTPPPSR_TTSEL0_Pos)  ///< Target Time Event Select 0
#define ETH_PTPPPSR_TTSEL0_0                   (0x00U << ETH_PTPPPSR_TTSEL0_Pos)  ///< register 0 (ENET_PTPTBSR0/ENET_PTPTNSR0) is only used for interrupt outputevents
#define ETH_PTPPPSR_TTSEL0_2                   (0x02U << ETH_PTPPPSR_TTSEL0_Pos)  ///< register 0 is used for interrupt output events and PPS0 single output event
#define ETH_PTPPPSR_TTSEL0_3                   (0x03U << ETH_PTPPPSR_TTSEL0_Pos)  ///< register 0(ENET_PTPTBSR0/ENET_PTPTNSR0) is only used for PPS0 single output event
#define ETH_PTPPPSR_PPSOMD_Pos                 (4)
#define ETH_PTPPPSR_PPSOMD                     (0x01U << ETH_PTPPPSR_PPSOMD_Pos)  ///< PPS Output Mode
#define ETH_PTPPPSR_PPSOUT0_Pos                (0)
#define ETH_PTPPPSR_PPSOUT0                    (0x0FU << ETH_PTPPPSR_PPSOUT0_Pos) ///< PPS Output Control 0

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCCR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCCR_CPSEL_Pos                    (5)
#define ETH_MMCCR_CPSEL                        (0x01U << ETH_MMCCR_CPSEL_Pos) ///< Remote-Wakeup Filter Value
#define ETH_MMCCR_CPSET_Pos                    (4)
#define ETH_MMCCR_CPSET                        (0x01U << ETH_MMCCR_CPSET_Pos) ///< Counter Preset Setting
#define ETH_MMCCR_CFIX_Pos                     (3)
#define ETH_MMCCR_CFIX                         (0x01U << ETH_MMCCR_CFIX_Pos)  ///< Counter Fixed
#define ETH_MMCCR_CRRST_Pos                    (2)
#define ETH_MMCCR_CRRST                        (0x01U << ETH_MMCCR_CRRST_Pos) ///< Counter Reset after Read
#define ETH_MMCCR_COSR_Pos                     (1)
#define ETH_MMCCR_COSR                         (0x01U << ETH_MMCCR_COSR_Pos)  ///< Counter Overflow Stop Rollover
#define ETH_MMCCR_CRST_Pos                     (0)
#define ETH_MMCCR_CRST                         (0x01U << ETH_MMCCR_CRST_Pos)  ///< Counter Reset

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCRSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCRSR_RUGIS_Pos                   (17)
#define ETH_MMCRSR_RUGIS                       (0x01U << ETH_MMCRSR_RUGIS_Pos)   ///< Receive Unicast Good Frame Interrupt Status

#define ETH_MMCRSR_RALIEIS_Pos                 (6)
#define ETH_MMCRSR_RALIEIS                     (0x01U << ETH_MMCRSR_RALIEIS_Pos) ///< Receive Align Error Frame Interrupt Status
#define ETH_MMCRSR_RCRCEIS_Pos                 (5)
#define ETH_MMCRSR_RCRCEIS                     (0x01U << ETH_MMCRSR_RCRCEIS_Pos) ///< Receive CRC Error Frame Interrupt Status

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCTSR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCTSR_TAGIS_Pos                   (21)
#define ETH_MMCTSR_TAGIS                       (0x01U << ETH_MMCTSR_TAGIS_Pos)  ///< Transfer All Good Frame Interrupt Status

#define ETH_MMCTSR_TGMCIS_Pos                  (15)
#define ETH_MMCTSR_TGMCIS                      (0x01U << ETH_MMCTSR_TGMCIS_Pos) ///< Transfer Good Frame after Multi-Collision Interrupt Status
#define ETH_MMCTSR_TGSCIS_Pos                  (14)
#define ETH_MMCTSR_TGSCIS                      (0x01U << ETH_MMCTSR_TGSCIS_Pos) ///< Transfer Good Frame after Single-Collision Interrupt Status

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCRIR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCRIR_RUGIM_Pos                   (17)
#define ETH_MMCRIR_RUGIM                       (0x01U << ETH_MMCRIR_RUGIM_Pos)   ///< Receive Unicast Good Frame Interrupt Mask
#define ETH_MMCRIR_RALIEIM_Pos                 (6)
#define ETH_MMCRIR_RALIEIM                     (0x01U << ETH_MMCRIR_RALIEIM_Pos) ///< Receive Align Error Frame Interrupt Mask
#define ETH_MMCRIR_RCRCEIM_Pos                 (5)
#define ETH_MMCRIR_RCRCEIM                     (0x01U << ETH_MMCRIR_RCRCEIM_Pos) ///< Receive CRC Error Frame Interrupt Mask

////////////////////////////////////////////////////////////////////////////////
/// @brief ETH_MMCTIR Registers bits definition
////////////////////////////////////////////////////////////////////////////////
#define ETH_MMCTIR_TAGIM_Pos                   (21)
#define ETH_MMCTIR_TAGIM                       (0x01U << ETH_MMCTIR_TAGIM_Pos)  ///< Transfer All Good Frame Interrupt Mask
#define ETH_MMCTIR_TGMCIM_Pos                  (15)
#define ETH_MMCTIR_TGMCIM                      (0x01U << ETH_MMCTIR_TGMCIM_Pos) ///< Transfer Good Frame after Multi-Collision Interrupt Mask
#define ETH_MMCTIR_TGSCIM_Pos                  (14)
#define ETH_MMCTIR_TGSCIM                      (0x01U << ETH_MMCTIR_TGSCIM_Pos) ///< Transfer Good Frame after Single-Collision Interrupt Mask

/// @}

/// @}

/// @}

#endif

