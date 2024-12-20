/***********************************************************************************************************************
    @file     reg_usb_fs.h
    @author   VV TEAM
    @brief    This flie contains all the USB_FS's register and its field definition.
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

#ifndef __REG_USB_FS_H
#define __REG_USB_FS_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief USB_FS Base Address Definition
  */
#define  USB_FS_BASE                               0x50000000 /*!<Base Address: 0x50000000*/

/**
  * @brief USB_FS Register Structure Definition
  */
typedef struct
{
    __IO uint32_t RESERVED0x000[4];    /*!<                                               offset: 0x0~0xc*/
    __IO uint32_t OTGISTAT;            /*!<USB_FS OTG Interrupt Status Register           offset: 0x10*/
    __IO uint32_t OTGICTRL;            /*!<                                               offset: 0x14*/
    __IO uint32_t OTGSTAT;             /*!<USB_FS OTG Status Register                     offset: 0x18*/
    __IO uint32_t OTGCTRL;             /*!<USB_FS OTG Control Register                    offset: 0x1C*/
    __IO uint32_t RESERVED0x020[24];   /*!<                                               offset: 0x20~0x7c*/
    __IO uint32_t INTSTAT;             /*!<USB_FS Interrupt Status Register               offset: 0x80*/
    __IO uint32_t INTENB;              /*!<USB_FS Interrupt Enable Register               offset: 0x84*/
    __IO uint32_t ERRSTAT;             /*!<USB_FS Error Interrupt Status Register         offset: 0x88*/
    __IO uint32_t ERRENB;              /*!<USB_FS Error Interrupt Enable Register         offset: 0x8C*/
    __IO uint32_t STAT;                /*!<USB_FS Status Register                         offset: 0x90*/
    __IO uint32_t CTL;                 /*!<USB_FS Control Register                        offset: 0x94*/
    __IO uint32_t ADDR;                /*!<USB_FS Address Register                        offset: 0x98*/
    __IO uint32_t BDTPAGE1;            /*!<USB_FS BDT Page Register 1                     offset: 0x9C*/
    __IO uint32_t FRMNUML;             /*!<USB_FS Low Frame Number Register               offset: 0xA0*/
    __IO uint32_t FRMNUMH;             /*!<USB_FS High Frame Number Register              offset: 0xA4*/
    __IO uint32_t TOKEN;               /*!<USB_FS Token Register                          offset: 0xA8*/
    __IO uint32_t SOFTHLD;             /*!<USB_FS SOF Threshold Register                  offset: 0xAC*/
    __IO uint32_t BDTPAGE2;            /*!<USB_FS BDT Page Register 2                     offset: 0xB0*/
    __IO uint32_t BDTPAGE3;            /*!<USB_FS BDT Page Register 3                     offset: 0xB4*/
    __IO uint32_t RESERVED0x0B8[2];    /*!<                                               offset: 0xb8~0xbc*/
    __IO uint32_t EPCTL[16];           /*!<USB_FS Endpoint Control Register x             offset: 0xC0*/
    __IO uint32_t USBCTRL;             /*!<USB_FS USB Control Register                    offset: 0x100*/
} USB_FS_TypeDef;

/**
  * @brief USB_FS type pointer Definition
  */
#define USB_FS                                    ((USB_FS_TypeDef *)USB_FS_BASE)

/**
  * @brief USB_FS_OTGISTAT Register Bit Definition
  */
#define  USB_FS_OTGISTAT_A_VBUS_VLD_CHG_Pos       (0)
#define  USB_FS_OTGISTAT_A_VBUS_VLD_CHG_Msk       (0x01U << USB_FS_OTGISTAT_A_VBUS_VLD_CHG_Pos) /*!<*/
#define  USB_FS_OTGISTAT_B_SESS_END_CHG_Pos       (2)
#define  USB_FS_OTGISTAT_B_SESS_END_CHG_Msk       (0x01U << USB_FS_OTGISTAT_B_SESS_END_CHG_Pos) /*!<*/
#define  USB_FS_OTGISTAT_SESS_VLD_CHG_Pos         (3)
#define  USB_FS_OTGISTAT_SESS_VLD_CHG_Msk         (0x01U << USB_FS_OTGISTAT_SESS_VLD_CHG_Pos)   /*!<*/
#define  USB_FS_OTGISTAT_LINE_STATE_CHG_Pos       (5)
#define  USB_FS_OTGISTAT_LINE_STATE_CHG_Msk       (0x01U << USB_FS_OTGISTAT_LINE_STATE_CHG_Pos) /*!<*/
#define  USB_FS_OTGISTAT_1_MSEC_Pos               (6)
#define  USB_FS_OTGISTAT_1_MSEC_Msk               (0x01U << USB_FS_OTGISTAT_1_MSEC_Pos)         /*!<*/
#define  USB_FS_OTGISTAT_ID_CHG_Pos               (7)
#define  USB_FS_OTGISTAT_ID_CHG_Msk               (0x01U << USB_FS_OTGISTAT_ID_CHG_Pos)         /*!<*/

/**
  * @brief OTG_FS_OTG_ICTRL Register Bit Definition
  */
#define OTG_FS_OTGICTRL_A_VBUS_VLD_EN_Pos         (0)
#define OTG_FS_OTGICTRL_A_VBUS_VLD_EN_Msk         (0x01U << OTG_FS_OTG_ICTRL_A_VBUS_VLD_EN_Pos)
#define OTG_FS_OTGICTRL_B_SESS_END_EN_Pos         (2)
#define OTG_FS_OTGICTRL_B_SESS_END_EN_Msk         (0x01U << OTG_FS_OTG_ICTRL_B_SESS_END_EN_Pos)
#define OTG_FS_OTGICTRL_SESS_VLD_EN_Pos           (3)
#define OTG_FS_OTGICTRL_SESS_VLD_EN_Msk           (0x01U << OTG_FS_OTG_ICTRL_SESS_VLD_EN_Pos)
#define OTG_FS_OTGICTRL_LINE_STATE_EN_Pos         (5)
#define OTG_FS_OTGICTRL_LINE_STATE_EN_Msk         (0x01U << OTG_FS_OTG_ICTRL_LINE_STATE_EN_Pos)
#define OTG_FS_OTGICTRL_1_MSEC_EN_Pos             (6)
#define OTG_FS_OTGICTRL_1_MSEC_EN_Msk             (0x01U << OTG_FS_OTG_ICTRL_1_MSEC_EN_Pos)
#define OTG_FS_OTGICTRL_ID_EN_Pos                 (7)
#define OTG_FS_OTGICTRL_ID_EN_Msk                 (0x01U << OTG_FS_OTG_ICTRL_ID_EN_Pos)

/**
  * @brief USB_FS_OTGSTAT Register Bit Definition
  */
#define  USB_FS_OTGSTAT_A_VBUS_VLD_Pos            (0)
#define  USB_FS_OTGSTAT_A_VBUS_VLD_Msk            (0x01U << USB_FS_OTGSTAT_A_VBUS_VLD_Pos)       /*!<*/
#define  USB_FS_OTGSTAT_B_SESS_END_Pos            (2)
#define  USB_FS_OTGSTAT_B_SESS_END_Msk            (0x01U << USB_FS_OTGSTAT_B_SESS_END_Pos)       /*!<*/
#define  USB_FS_OTGSTAT_SESS_VLD_Pos              (3)
#define  USB_FS_OTGSTAT_SESS_VLD_Msk              (0x01U << USB_FS_OTGSTAT_SESS_VLD_Pos)         /*!<*/
#define  USB_FS_OTGSTAT_LINESTATE_STABLE_Pos      (5)
#define  USB_FS_OTGSTAT_LINESTATE_STABLE_Msk      (0x01U << USB_FS_OTGSTAT_LINESTATE_STABLE_Pos) /*!<*/
#define  USB_FS_OTGSTAT_ID_Pos                    (7)
#define  USB_FS_OTGSTAT_ID_Msk                    (0x01U << USB_FS_OTGSTAT_ID_Pos)               /*!<*/

/**
  * @brief USB_FS_OTGCTRL Register Bit Definition
  */
#define  USB_FS_OTGCTRL_VBUS_DSCHG_Pos            (0)
#define  USB_FS_OTGCTRL_VBUS_DSCHG_Msk            (0x01U << USB_FS_OTGCTRL_VBUS_DSCHG_Pos) /*!<*/
#define  USB_FS_OTGCTRL_VBUS_CHG_Pos              (1)
#define  USB_FS_OTGCTRL_VBUS_CHG_Msk              (0x01U << USB_FS_OTGCTRL_VBUS_CHG_Pos)   /*!<*/
#define  USB_FS_OTGCTRL_OTG_EN_Pos                (2)
#define  USB_FS_OTGCTRL_OTG_EN_Msk                (0x01U << USB_FS_OTGCTRL_OTG_EN_Pos)     /*!<*/
#define  USB_FS_OTGCTRL_VBUS_ON_Pos               (3)
#define  USB_FS_OTGCTRL_VBUS_ON_Msk               (0x01U << USB_FS_OTGCTRL_VBUS_ON_Pos)    /*!<*/
#define  USB_FS_OTGCTRL_DM_LOW_Pos                (4)
#define  USB_FS_OTGCTRL_DM_LOW_Msk                (0x01U << USB_FS_OTGCTRL_DM_LOW_Pos)     /*!<*/
#define  USB_FS_OTGCTRL_DP_LOW_Pos                (5)
#define  USB_FS_OTGCTRL_DP_LOW_Msk                (0x01U << USB_FS_OTGCTRL_DP_LOW_Pos)     /*!<*/
#define  USB_FS_OTGCTRL_DM_HIGH_Pos               (6)
#define  USB_FS_OTGCTRL_DM_HIGH_Msk               (0x01U << USB_FS_OTGCTRL_DM_HIGH_Pos)    /*!<*/
#define  USB_FS_OTGCTRL_DP_HIGH_Pos               (7)
#define  USB_FS_OTGCTRL_DP_HIGH_Msk               (0x01U << USB_FS_OTGCTRL_DP_HIGH_Pos)    /*!<*/

/**
  * @brief USB_FS_INTSTAT Register Bit Definition
  */
#define  USB_FS_INTSTAT_USB_RST_Pos               (0)
#define  USB_FS_INTSTAT_USB_RST_Msk               (0x01U << USB_FS_INTSTAT_USB_RST_Pos) /*!<*/
#define  USB_FS_INTSTAT_ERROR_Pos                 (1)
#define  USB_FS_INTSTAT_ERROR_Msk                 (0x01U << USB_FS_INTSTAT_ERROR_Pos)   /*!<*/
#define  USB_FS_INTSTAT_SOF_TOK_Pos               (2)
#define  USB_FS_INTSTAT_SOF_TOK_Msk               (0x01U << USB_FS_INTSTAT_SOF_TOK_Pos) /*!<*/
#define  USB_FS_INTSTAT_TOK_DNE_Pos               (3)
#define  USB_FS_INTSTAT_TOK_DNE_Msk               (0x01U << USB_FS_INTSTAT_TOK_DNE_Pos) /*!<*/
#define  USB_FS_INTSTAT_SLEEP_Pos                 (4)
#define  USB_FS_INTSTAT_SLEEP_Msk                 (0x01U << USB_FS_INTSTAT_SLEEP_Pos)   /*!<*/
#define  USB_FS_INTSTAT_RESUME_Pos                (5)
#define  USB_FS_INTSTAT_RESUME_Msk                (0x01U << USB_FS_INTSTAT_RESUME_Pos)  /*!<*/
#define  USB_FS_INTSTAT_ATTACH_Pos                (6)
#define  USB_FS_INTSTAT_ATTACH_Msk                (0x01U << USB_FS_INTSTAT_ATTACH_Pos)  /*!<*/
#define  USB_FS_INTSTAT_STALL_Pos                 (7)
#define  USB_FS_INTSTAT_STALL_Msk                 (0x01U << USB_FS_INTSTAT_STALL_Pos)   /*!<*/

/**
  * @brief USB_FS_INTENB Register Bit Definition
  */
#define  USB_FS_INTENB_USB_RST_Pos                (0)
#define  USB_FS_INTENB_USB_RST_Msk                (0x01U << USB_FS_INTENB_USB_RST_Pos) /*!<*/
#define  USB_FS_INTENB_ERROR_Pos                  (1)
#define  USB_FS_INTENB_ERROR_Msk                  (0x01U << USB_FS_INTENB_ERROR_Pos)   /*!<*/
#define  USB_FS_INTENB_SOF_TOK_Pos                (2)
#define  USB_FS_INTENB_SOF_TOK_Msk                (0x01U << USB_FS_INTENB_SOF_TOK_Pos) /*!<*/
#define  USB_FS_INTENB_TOK_DNE_Pos                (3)
#define  USB_FS_INTENB_TOK_DNE_Msk                (0x01U << USB_FS_INTENB_TOK_DNE_Pos) /*!<*/
#define  USB_FS_INTENB_SLEEP_Pos                  (4)
#define  USB_FS_INTENB_SLEEP_Msk                  (0x01U << USB_FS_INTENB_SLEEP_Pos)   /*!<*/
#define  USB_FS_INTENB_RESUME_Pos                 (5)
#define  USB_FS_INTENB_RESUME_Msk                 (0x01U << USB_FS_INTENB_RESUME_Pos)  /*!<*/
#define  USB_FS_INTENB_ATTACH_Pos                 (6)
#define  USB_FS_INTENB_ATTACH_Msk                 (0x01U << USB_FS_INTENB_ATTACH_Pos)  /*!<*/
#define  USB_FS_INTENB_STALL_Pos                  (7)
#define  USB_FS_INTENB_STALL_Msk                  (0x01U << USB_FS_INTENB_STALL_Pos)   /*!<*/

/**
  * @brief USB_FS_ERRSTAT Register Bit Definition
  */
#define  USB_FS_ERRSTAT_PID_ERR_Pos               (0)
#define  USB_FS_ERRSTAT_PID_ERR_Msk               (0x01U << USB_FS_ERRSTAT_PID_ERR_Pos) /*!<*/
#define  USB_FS_ERRSTAT_CRC5EOF_Pos               (1)
#define  USB_FS_ERRSTAT_CRC5EOF_Msk               (0x01U << USB_FS_ERRSTAT_CRC5EOF_Pos) /*!<*/
#define  USB_FS_ERRSTAT_CRC16_Pos                 (2)
#define  USB_FS_ERRSTAT_CRC16_Msk                 (0x01U << USB_FS_ERRSTAT_CRC16_Pos)   /*!<*/
#define  USB_FS_ERRSTAT_DFN8_Pos                  (3)
#define  USB_FS_ERRSTAT_DFN8_Msk                  (0x01U << USB_FS_ERRSTAT_DFN8_Pos)    /*!<*/
#define  USB_FS_ERRSTAT_BTO_ERR_Pos               (4)
#define  USB_FS_ERRSTAT_BTO_ERR_Msk               (0x01U << USB_FS_ERRSTAT_BTO_ERR_Pos) /*!<*/
#define  USB_FS_ERRSTAT_DMA_ERR_Pos               (5)
#define  USB_FS_ERRSTAT_DMA_ERR_Msk               (0x01U << USB_FS_ERRSTAT_DMA_ERR_Pos) /*!<*/
#define  USB_FS_ERRSTAT_BTS_ERR_Pos               (7)
#define  USB_FS_ERRSTAT_BTS_ERR_Msk               (0x01U << USB_FS_ERRSTAT_BTS_ERR_Pos) /*!<*/

/**
  * @brief USB_FS_ERRENB Register Bit Definition
  */
#define  USB_FS_ERRENB_PID_ERR_Pos                (0)
#define  USB_FS_ERRENB_PID_ERR_Msk                (0x01U << USB_FS_ERRENB_PID_ERR_Pos) /*!<*/
#define  USB_FS_ERRENB_CRC5EOF_Pos                (1)
#define  USB_FS_ERRENB_CRC5EOF_Msk                (0x01U << USB_FS_ERRENB_CRC5EOF_Pos) /*!<*/
#define  USB_FS_ERRENB_CRC16_Pos                  (2)
#define  USB_FS_ERRENB_CRC16_Msk                  (0x01U << USB_FS_ERRENB_CRC16_Pos)   /*!<*/
#define  USB_FS_ERRENB_DFN8_Pos                   (3)
#define  USB_FS_ERRENB_DFN8_Msk                   (0x01U << USB_FS_ERRENB_DFN8_Pos)    /*!<*/
#define  USB_FS_ERRENB_BTO_ERR_Pos                (4)
#define  USB_FS_ERRENB_BTO_ERR_Msk                (0x01U << USB_FS_ERRENB_BTO_ERR_Pos) /*!<*/
#define  USB_FS_ERRENB_DMA_ERR_Pos                (5)
#define  USB_FS_ERRENB_DMA_ERR_Msk                (0x01U << USB_FS_ERRENB_DMA_ERR_Pos) /*!<*/
#define  USB_FS_ERRENB_BTS_ERR_Pos                (7)
#define  USB_FS_ERRENB_BTS_ERR_Msk                (0x01U << USB_FS_ERRENB_BTS_ERR_Pos) /*!<*/

/**
  * @brief USB_FS_STAT Register Bit Definition
  */
#define  USB_FS_STAT_ODD_Pos                      (2)
#define  USB_FS_STAT_ODD_Msk                      (0x01U << USB_FS_STAT_ODD_Pos)  /*!<*/
#define  USB_FS_STAT_TX_Pos                       (3)
#define  USB_FS_STAT_TX_Msk                       (0x01U << USB_FS_STAT_TX_Pos)   /*!<*/
#define  USB_FS_STAT_ENDP_Pos                     (4)
#define  USB_FS_STAT_ENDP_Msk                     (0x0FU << USB_FS_STAT_ENDP_Pos) /*!<*/

/**
  * @brief USB_FS_CTL Register Bit Definition
  */
#define  USB_FS_CTL_USB_EN_Pos                    (0)
#define  USB_FS_CTL_USB_EN_Msk                    (0x01U << USB_FS_CTL_USB_EN_Pos)              /*!<*/
#define  USB_FS_CTL_ODD_RST_Pos                   (1)
#define  USB_FS_CTL_ODD_RST_Msk                   (0x01U << USB_FS_CTL_ODD_RST_Pos)             /*!<*/
#define  USB_FS_CTL_RESUME_Pos                    (2)
#define  USB_FS_CTL_RESUME_Msk                    (0x01U << USB_FS_CTL_RESUME_Pos)              /*!<*/
#define  USB_FS_CTL_HOST_MODE_EN_Pos              (3)
#define  USB_FS_CTL_HOST_MODE_EN_Msk              (0x01U << USB_FS_CTL_HOST_MODE_EN_Pos)        /*!<*/
#define  USB_FS_CTL_RESET_Pos                     (4)
#define  USB_FS_CTL_RESET_Msk                     (0x01U << USB_FS_CTL_RESET_Pos)               /*!<*/
#define  USB_FS_CTL_TXDSUSPENDTOKENBUSY_Pos       (5)
#define  USB_FS_CTL_TXDSUSPENDTOKENBUSY_Msk       (0x01U << USB_FS_CTL_TXDSUSPENDTOKENBUSY_Pos) /*!<*/
#define  USB_FS_CTL_SE0_Pos                       (6)
#define  USB_FS_CTL_SE0_Msk                       (0x01U << USB_FS_CTL_SE0_Pos)                 /*!<*/
#define  USB_FS_CTL_JSTATE_Pos                    (7)
#define  USB_FS_CTL_JSTATE_Msk                    (0x01U << USB_FS_CTL_JSTATE_Pos)              /*!<*/

/**
  * @brief USB_FS_ADDR Register Bit Definition
  */
#define  USB_FS_ADDR_ADDR_Pos                     (0)
#define  USB_FS_ADDR_ADDR_Msk                     (0x7FU << USB_FS_ADDR_ADDR_Pos)  /*!<*/
#define  USB_FS_ADDR_LS_EN_Pos                    (7)
#define  USB_FS_ADDR_LS_EN_Msk                    (0x01U << USB_FS_ADDR_LS_EN_Pos) /*!<*/

/**
  * @brief USB_FS_BDTPAGE1 Register Bit Definition
  */
#define  USB_FS_BDTPAGE1_BDT_BA_Pos               (1)
#define  USB_FS_BDTPAGE1_BDT_BA_Msk               (0x7FU << USB_FS_BDTPAGE1_BDT_BA_Pos) /*!<*/

/**
  * @brief USB_FS_FRMNUML Register Bit Definition
  */
#define  USB_FS_FRMNUML_FRM_Pos                   (0)
#define  USB_FS_FRMNUML_FRM_Msk                   (0xFFU << USB_FS_FRMNUML_FRM_Pos) /*!<*/

/**
  * @brief USB_FS_FRMNUMH Register Bit Definition
  */
#define  USB_FS_FRMNUMH_FRM_Pos                   (0)
#define  USB_FS_FRMNUMH_FRM_Msk                   (0x07U << USB_FS_FRMNUMH_FRM_Pos) /*!<*/

/**
  * @brief USB_FS_TOKEN Register Bit Definition
  */
#define  USB_FS_TOKEN_TOKEN_ENDPT_Pos             (0)
#define  USB_FS_TOKEN_TOKEN_ENDPT_Msk             (0x0FU << USB_FS_TOKEN_TOKEN_ENDPT_Pos) /*!<*/
#define  USB_FS_TOKEN_TOKEN_PID_Pos               (4)
#define  USB_FS_TOKEN_TOKEN_PID_Msk               (0x0FU << USB_FS_TOKEN_TOKEN_PID_Pos)   /*!<*/

/**
  * @brief USB_FS_SOFTHLD Register Bit Definition
  */
#define  USB_FS_SOFTHLD_CNT_Pos                   (0)
#define  USB_FS_SOFTHLD_CNT_Msk                   (0xFFU << USB_FS_SOFTHLD_CNT_Pos) /*!<*/

/**
  * @brief USB_FS_BDTPAGE2 Register Bit Definition
  */
#define  USB_FS_BDTPAGE2_BDT_BA_Pos               (0)
#define  USB_FS_BDTPAGE2_BDT_BA_Msk               (0xFFU << USB_FS_BDTPAGE2_BDT_BA_Pos) /*!<*/

/**
  * @brief USB_FS_BDTPAGE3 Register Bit Definition
  */
#define  USB_FS_BDTPAGE3_BDT_BA_Pos               (0)
#define  USB_FS_BDTPAGE3_BDT_BA_Msk               (0xFFU << USB_FS_BDTPAGE3_BDT_BA_Pos) /*!<*/

/**
  * @brief USB_FS_EPCTL Register Bit Definition
  */
#define  USB_FS_EPCTL_EP_HSHK_Pos                 (0)
#define  USB_FS_EPCTL_EP_HSHK_Msk                 (0x01U << USB_FS_EPCTL_EP_HSHK_Pos)     /*!<*/
#define  USB_FS_EPCTL_EP_STALL_Pos                (1)
#define  USB_FS_EPCTL_EP_STALL_Msk                (0x01U << USB_FS_EPCTL_EP_STALL_Pos)    /*!<*/
#define  USB_FS_EPCTL_EP_TX_EN_Pos                (2)
#define  USB_FS_EPCTL_EP_TX_EN_Msk                (0x01U << USB_FS_EPCTL_EP_TX_EN_Pos)    /*!<*/
#define  USB_FS_EPCTL_EP_RX_EN_Pos                (3)
#define  USB_FS_EPCTL_EP_RX_EN_Msk                (0x01U << USB_FS_EPCTL_EP_RX_EN_Pos)    /*!<*/
#define  USB_FS_EPCTL_EP_CTL_DIS_Pos              (4)
#define  USB_FS_EPCTL_EP_CTL_DIS_Msk              (0x01U << USB_FS_EPCTL_EP_CTL_DIS_Pos)  /*!<*/
#define  USB_FS_EPCTL_RETRY_DIS_Pos               (6)
#define  USB_FS_EPCTL_RETRY_DIS_Msk               (0x01U << USB_FS_EPCTL_RETRY_DIS_Pos)   /*!<*/
#define  USB_FS_EPCTL_HOST_WO_HUB_Pos             (7)
#define  USB_FS_EPCTL_HOST_WO_HUB_Msk             (0x01U << USB_FS_EPCTL_HOST_WO_HUB_Pos) /*!<*/

/**
  * @brief USB_FS_USBCTRL Register Bit Definition
  */
#define  USB_FS_USBCTRL_SUSPE_Pos                 (7)
#define  USB_FS_USBCTRL_SUSPE_Msk                 (0x01U << USB_FS_USBCTRL_SUSPE_Pos) /*!<*/

#endif

