/***********************************************************************************************************************
    @file     reg_adc.h
    @author   VV TEAM
    @brief    This flie contains all the ADC's register and its field definition.
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

#ifndef __REG_ADC_H
#define __REG_ADC_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief ADC Base Address Definition
  */
#define  ADC1_BASE                                 0x40012400 /*!<Base Address: 0x40012400*/
#define  ADC2_BASE                                 0x40012800 /*!<Base Address: 0x40012800*/

/**
  * @brief ADC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t ADDATA;              /*!<ADC Data Register                              offset: 0x00*/
    __IO uint32_t ADCFG;               /*!<ADC Configuration Register                     offset: 0x04*/
    __IO uint32_t ADCR;                /*!<ADC Control Register                           offset: 0x08*/
    __IO uint32_t ADCHS;               /*!<ADC Channel Selection Register                 offset: 0x0C*/
    __IO uint32_t ADCMPR;              /*!<ADC Analog Watchdog Compare Register           offset: 0x10*/
    __IO uint32_t ADSTA;               /*!<ADC Status Register                            offset: 0x14*/
    __IO uint32_t ADDR0;               /*!<ADC Channel Data Register                      offset: 0x18*/
    __IO uint32_t ADDR1;               /*!<ADC Channel Data Register                      offset: 0x1C*/
    __IO uint32_t ADDR2;               /*!<ADC Channel Data Register                      offset: 0x20*/
    __IO uint32_t ADDR3;               /*!<ADC Channel Data Register                      offset: 0x24*/
    __IO uint32_t ADDR4;               /*!<ADC Channel Data Register                      offset: 0x28*/
    __IO uint32_t ADDR5;               /*!<ADC Channel Data Register                      offset: 0x2C*/
    __IO uint32_t ADDR6;               /*!<ADC Channel Data Register                      offset: 0x30*/
    __IO uint32_t ADDR7;               /*!<ADC Channel Data Register                      offset: 0x34*/
    __IO uint32_t ADDR8;               /*!<ADC Channel Data Register                      offset: 0x38*/
    __IO uint32_t ADDR9;               /*!<ADC Channel Data Register                      offset: 0x3C*/
    __IO uint32_t ADDR10;              /*!<ADC Channel Data Register                      offset: 0x40*/
    __IO uint32_t ADDR11;              /*!<ADC Channel Data Register                      offset: 0x44*/
    __IO uint32_t ADDR12;              /*!<ADC Channel Data Register                      offset: 0x48*/
    __IO uint32_t ADDR13;              /*!<ADC Channel Data Register                      offset: 0x4C*/
    __IO uint32_t ADDR14;              /*!<ADC Channel Data Register                      offset: 0x50*/
    __IO uint32_t ADDR15;              /*!<ADC Channel Data Register                      offset: 0x54*/
    __IO uint32_t ADSTA_EXT;           /*!<ADC Extended State Register                    offset: 0x58*/
    __IO uint32_t CHANY0;              /*!<ADC Any Channel Selection Register 0           offset: 0x5C*/
    __IO uint32_t CHANY1;              /*!<ADC Any Channel Selection Register 1           offset: 0x60*/
    __IO uint32_t ANY_CFG;             /*!<ADC Any Channel Configuration Register         offset: 0x64*/
    __IO uint32_t ANY_CR;              /*!<ADC Any Channel Control Register               offset: 0x68*/
    __IO uint32_t ADCFG2;              /*!<ADC Configuration Register 2                   offset: 0x6C*/
    __IO uint32_t SMPR1;               /*!<ADC Sample Configuration Register 1            offset: 0x70*/
    __IO uint32_t SMPR2;               /*!<ADC Sample Configuration Register 2            offset: 0x74*/
    __IO uint32_t SMPR3;               /*!<ADC Sample Configuration Register 3            offset: 0x78*/
    __IO uint32_t JOFR0;               /*!<ADC Injected Channel Data Offset Register      offset: 0x7C*/
    __IO uint32_t JOFR1;               /*!<ADC Injected Channel Data Offset Register      offset: 0x80*/
    __IO uint32_t JOFR2;               /*!<ADC Injected Channel Data Offset Register      offset: 0x84*/
    __IO uint32_t JOFR3;               /*!<ADC Injected Channel Data Offset Register      offset: 0x88*/
    __IO uint32_t JSQR;                /*!<ADC Injected Sequence Register                 offset: 0x8C*/
    __IO uint32_t JADDATA;             /*!<ADC Injected Data Register                     offset: 0x90*/
    __IO uint32_t RESERVED0x094[7];    /*!<                                               offset: 0x94~0xAC*/
    __IO uint32_t JDR0;                /*!<ADC Injected Channel Data Register             offset: 0xB0*/
    __IO uint32_t JDR1;                /*!<ADC Injected Channel Data Register             offset: 0xB4*/
    __IO uint32_t JDR2;                /*!<ADC Injected Channel Data Register             offset: 0xB8*/
    __IO uint32_t JDR3;                /*!<ADC Injected Channel Data Register             offset: 0xBC*/
} ADC_TypeDef;

/**
  * @brief ADC type pointer Definition
  */
#define ADC1                                      ((ADC_TypeDef *)ADC1_BASE)
#define ADC2                                      ((ADC_TypeDef *)ADC2_BASE)

/**
  * @brief ADC_ADDATA Register Bit Definition
  */
#define  ADC_ADDATA_DATA_Pos                      (0)
#define  ADC_ADDATA_DATA_Msk                      (0xFFFFU << ADC_ADDATA_DATA_Pos)      /*!<*/
#define  ADC_ADDATA_CHANNELSELL_Pos               (16)
#define  ADC_ADDATA_CHANNELSELL_Msk               (0x0FU << ADC_ADDATA_CHANNELSELL_Pos) /*!<*/
#define  ADC_ADDATA_OVERRUN_Pos                   (20)
#define  ADC_ADDATA_OVERRUN_Msk                   (0x01U << ADC_ADDATA_OVERRUN_Pos)     /*!<*/
#define  ADC_ADDATA_VALID_Pos                     (21)
#define  ADC_ADDATA_VALID_Msk                     (0x01U << ADC_ADDATA_VALID_Pos)       /*!<*/
#define  ADC_ADDATA_CHANNELSELH_Pos               (22)
#define  ADC_ADDATA_CHANNELSELH_Msk               (0x01U << ADC_ADDATA_CHANNELSELH_Pos) /*!<*/

/**
  * @brief ADC_ADCFG Register Bit Definition
  */
#define  ADC_ADCFG_ADEN_Pos                       (0)
#define  ADC_ADCFG_ADEN_Msk                       (0x01U << ADC_ADCFG_ADEN_Pos)    /*!<*/
#define  ADC_ADCFG_AWDEN_Pos                      (1)
#define  ADC_ADCFG_AWDEN_Msk                      (0x01U << ADC_ADCFG_AWDEN_Pos)   /*!<*/
#define  ADC_ADCFG_TSEN_Pos                       (2)
#define  ADC_ADCFG_TSEN_Msk                       (0x01U << ADC_ADCFG_TSEN_Pos)    /*!<*/
#define  ADC_ADCFG_VSEN_Pos                       (3)
#define  ADC_ADCFG_VSEN_Msk                       (0x01U << ADC_ADCFG_VSEN_Pos)    /*!<*/
#define  ADC_ADCFG_RSLTCTL_Pos                    (7)
#define  ADC_ADCFG_RSLTCTL_Msk                    (0x07U << ADC_ADCFG_RSLTCTL_Pos) /*!<*/
#define  ADC_ADCFG_JAWDEN_Pos                     (16)
#define  ADC_ADCFG_JAWDEN_Msk                     (0x01U << ADC_ADCFG_JAWDEN_Pos)  /*!<*/

/**
  * @brief ADC_ADCR Register Bit Definition
  */
#define  ADC_ADCR_EOSIE_Pos                       (0)
#define  ADC_ADCR_EOSIE_Msk                       (0x01U << ADC_ADCR_EOSIE_Pos)    /*!<*/
#define  ADC_ADCR_AWDIE_Pos                       (1)
#define  ADC_ADCR_AWDIE_Msk                       (0x01U << ADC_ADCR_AWDIE_Pos)    /*!<*/
#define  ADC_ADCR_TRGEN_Pos                       (2)
#define  ADC_ADCR_TRGEN_Msk                       (0x01U << ADC_ADCR_TRGEN_Pos)    /*!<*/
#define  ADC_ADCR_DMAEN_Pos                       (3)
#define  ADC_ADCR_DMAEN_Msk                       (0x01U << ADC_ADCR_DMAEN_Pos)    /*!<*/
#define  ADC_ADCR_TRGSELL_Pos                     (4)
#define  ADC_ADCR_TRGSELL_Msk                     (0x07U << ADC_ADCR_TRGSELL_Pos)  /*!<*/
#define  ADC_ADCR_ADST_Pos                        (8)
#define  ADC_ADCR_ADST_Msk                        (0x01U << ADC_ADCR_ADST_Pos)     /*!<*/
#define  ADC_ADCR_ADMD_Pos                        (9)
#define  ADC_ADCR_ADMD_Msk                        (0x03U << ADC_ADCR_ADMD_Pos)     /*!<*/
#define  ADC_ADCR_ALIGN_Pos                       (11)
#define  ADC_ADCR_ALIGN_Msk                       (0x01U << ADC_ADCR_ALIGN_Pos)    /*!<*/
#define  ADC_ADCR_CMPCHL_Pos                      (12)
#define  ADC_ADCR_CMPCHL_Msk                      (0x0FU << ADC_ADCR_CMPCHL_Pos)   /*!<*/
#define  ADC_ADCR_SCANDIR_Pos                     (16)
#define  ADC_ADCR_SCANDIR_Msk                     (0x01U << ADC_ADCR_SCANDIR_Pos)  /*!<*/
#define  ADC_ADCR_TRGSELH_Pos                     (17)
#define  ADC_ADCR_TRGSELH_Msk                     (0x03U << ADC_ADCR_TRGSELH_Pos)  /*!<*/
#define  ADC_ADCR_TRGSHIFT_Pos                    (19)
#define  ADC_ADCR_TRGSHIFT_Msk                    (0x07U << ADC_ADCR_TRGSHIFT_Pos) /*!<*/
#define  ADC_ADCR_TRG_EDGE_Pos                    (24)
#define  ADC_ADCR_TRG_EDGE_Msk                    (0x03U << ADC_ADCR_TRG_EDGE_Pos) /*!<*/
#define  ADC_ADCR_EOSMPIE_Pos                     (26)
#define  ADC_ADCR_EOSMPIE_Msk                     (0x01U << ADC_ADCR_EOSMPIE_Pos)  /*!<*/
#define  ADC_ADCR_EOCIE_Pos                       (27)
#define  ADC_ADCR_EOCIE_Msk                       (0x01U << ADC_ADCR_EOCIE_Pos)    /*!<*/
#define  ADC_ADCR_CMPCHH_Pos                      (28)
#define  ADC_ADCR_CMPCHH_Msk                      (0x01U << ADC_ADCR_CMPCHH_Pos)   /*!<*/

/**
  * @brief ADC_ADCHS Register Bit Definition
  */
#define  ADC_ADCHS_CHEN0_Pos                      (0)
#define  ADC_ADCHS_CHEN0_Msk                      (0x01U << ADC_ADCHS_CHEN0_Pos)  /*!<*/
#define  ADC_ADCHS_CHEN1_Pos                      (1)
#define  ADC_ADCHS_CHEN1_Msk                      (0x01U << ADC_ADCHS_CHEN1_Pos)  /*!<*/
#define  ADC_ADCHS_CHEN2_Pos                      (2)
#define  ADC_ADCHS_CHEN2_Msk                      (0x01U << ADC_ADCHS_CHEN2_Pos)  /*!<*/
#define  ADC_ADCHS_CHEN3_Pos                      (3)
#define  ADC_ADCHS_CHEN3_Msk                      (0x01U << ADC_ADCHS_CHEN3_Pos)  /*!<*/
#define  ADC_ADCHS_CHEN4_Pos                      (4)
#define  ADC_ADCHS_CHEN4_Msk                      (0x01U << ADC_ADCHS_CHEN4_Pos)  /*!<*/
#define  ADC_ADCHS_CHEN5_Pos                      (5)
#define  ADC_ADCHS_CHEN5_Msk                      (0x01U << ADC_ADCHS_CHEN5_Pos)  /*!<*/
#define  ADC_ADCHS_CHEN6_Pos                      (6)
#define  ADC_ADCHS_CHEN6_Msk                      (0x01U << ADC_ADCHS_CHEN6_Pos)  /*!<*/
#define  ADC_ADCHS_CHEN7_Pos                      (7)
#define  ADC_ADCHS_CHEN7_Msk                      (0x01U << ADC_ADCHS_CHEN7_Pos)  /*!<*/
#define  ADC_ADCHS_CHEN8_Pos                      (8)
#define  ADC_ADCHS_CHEN8_Msk                      (0x01U << ADC_ADCHS_CHEN8_Pos)  /*!<*/
#define  ADC_ADCHS_CHEN9_Pos                      (9)
#define  ADC_ADCHS_CHEN9_Msk                      (0x01U << ADC_ADCHS_CHEN9_Pos)  /*!<*/
#define  ADC_ADCHS_CHEN10_Pos                     (10)
#define  ADC_ADCHS_CHEN10_Msk                     (0x01U << ADC_ADCHS_CHEN10_Pos) /*!<*/
#define  ADC_ADCHS_CHEN11_Pos                     (11)
#define  ADC_ADCHS_CHEN11_Msk                     (0x01U << ADC_ADCHS_CHEN11_Pos) /*!<*/
#define  ADC_ADCHS_CHEN12_Pos                     (12)
#define  ADC_ADCHS_CHEN12_Msk                     (0x01U << ADC_ADCHS_CHEN12_Pos) /*!<*/
#define  ADC_ADCHS_CHEN13_Pos                     (13)
#define  ADC_ADCHS_CHEN13_Msk                     (0x01U << ADC_ADCHS_CHEN13_Pos) /*!<*/
#define  ADC_ADCHS_CHEN14_Pos                     (14)
#define  ADC_ADCHS_CHEN14_Msk                     (0x01U << ADC_ADCHS_CHEN14_Pos) /*!<*/
#define  ADC_ADCHS_CHEN15_Pos                     (15)
#define  ADC_ADCHS_CHEN15_Msk                     (0x01U << ADC_ADCHS_CHEN15_Pos) /*!<*/

/**
  * @brief ADC_ADCMPR Register Bit Definition
  */
#define  ADC_ADCMPR_CMPLDATA_Pos                  (0)
#define  ADC_ADCMPR_CMPLDATA_Msk                  (0x0FFFU << ADC_ADCMPR_CMPLDATA_Pos) /*!<*/
#define  ADC_ADCMPR_CMPHDATA_Pos                  (16)
#define  ADC_ADCMPR_CMPHDATA_Msk                  (0x0FFFU << ADC_ADCMPR_CMPHDATA_Pos) /*!<*/

/**
  * @brief ADC_ADSTA Register Bit Definition
  */
#define  ADC_ADSTA_EOSIF_Pos                      (0)
#define  ADC_ADSTA_EOSIF_Msk                      (0x01U << ADC_ADSTA_EOSIF_Pos)     /*!<*/
#define  ADC_ADSTA_AWDIF_Pos                      (1)
#define  ADC_ADSTA_AWDIF_Msk                      (0x01U << ADC_ADSTA_AWDIF_Pos)     /*!<*/
#define  ADC_ADSTA_BUSY_Pos                       (2)
#define  ADC_ADSTA_BUSY_Msk                       (0x01U << ADC_ADSTA_BUSY_Pos)      /*!<*/
#define  ADC_ADSTA_CHANNELH_Pos                   (3)
#define  ADC_ADSTA_CHANNELH_Msk                   (0x01U << ADC_ADSTA_CHANNELH_Pos)  /*!<*/
#define  ADC_ADSTA_CHANNELL_Pos                   (4)
#define  ADC_ADSTA_CHANNELL_Msk                   (0x0FU << ADC_ADSTA_CHANNELL_Pos)  /*!<*/
#define  ADC_ADSTA_VALID_Pos                      (8)
#define  ADC_ADSTA_VALID_Msk                      (0x0FFFU << ADC_ADSTA_VALID_Pos)   /*!<*/
#define  ADC_ADSTA_OVERRUN_Pos                    (20)
#define  ADC_ADSTA_OVERRUN_Msk                    (0x0FFFU << ADC_ADSTA_OVERRUN_Pos) /*!<*/

/**
  * @brief ADC_ADDR Register Bit Definition
  */
#define  ADC_ADDR_DATA_Pos                        (0)
#define  ADC_ADDR_DATA_Msk                        (0xFFFFU << ADC_ADDR_DATA_Pos)  /*!<*/
#define  ADC_ADDR_OVERRUN_Pos                     (20)
#define  ADC_ADDR_OVERRUN_Msk                     (0x01U << ADC_ADDR_OVERRUN_Pos) /*!<*/
#define  ADC_ADDR_VALID_Pos                       (21)
#define  ADC_ADDR_VALID_Msk                       (0x01U << ADC_ADDR_VALID_Pos)   /*!<*/

/**
  * @brief ADC_ADSTA_EXT Register Bit Definition
  */
#define  ADC_ADSTA_EXT_VALID_Pos                  (0)
#define  ADC_ADSTA_EXT_VALID_Msk                  (0x0FU << ADC_ADSTA_EXT_VALID_Pos)    /*!<*/
#define  ADC_ADSTA_EXT_OVERRUN_Pos                (4)
#define  ADC_ADSTA_EXT_OVERRUN_Msk                (0x0FU << ADC_ADSTA_EXT_OVERRUN_Pos)  /*!<*/
#define  ADC_ADSTA_EXT_EOSMPIF_Pos                (16)
#define  ADC_ADSTA_EXT_EOSMPIF_Msk                (0x01U << ADC_ADSTA_EXT_EOSMPIF_Pos)  /*!<*/
#define  ADC_ADSTA_EXT_EOCIF_Pos                  (17)
#define  ADC_ADSTA_EXT_EOCIF_Msk                  (0x01U << ADC_ADSTA_EXT_EOCIF_Pos)    /*!<*/
#define  ADC_ADSTA_EXT_JEOSMPIF_Pos               (18)
#define  ADC_ADSTA_EXT_JEOSMPIF_Msk               (0x01U << ADC_ADSTA_EXT_JEOSMPIF_Pos) /*!<*/
#define  ADC_ADSTA_EXT_JEOCIF_Pos                 (19)
#define  ADC_ADSTA_EXT_JEOCIF_Msk                 (0x01U << ADC_ADSTA_EXT_JEOCIF_Pos)   /*!<*/
#define  ADC_ADSTA_EXT_JEOSIF_Pos                 (20)
#define  ADC_ADSTA_EXT_JEOSIF_Msk                 (0x01U << ADC_ADSTA_EXT_JEOSIF_Pos)   /*!<*/
#define  ADC_ADSTA_EXT_JBUSY_Pos                  (21)
#define  ADC_ADSTA_EXT_JBUSY_Msk                  (0x01U << ADC_ADSTA_EXT_JBUSY_Pos)    /*!<*/
#define  ADC_ADSTA_EXT_EOCALIF_Pos                (24)
#define  ADC_ADSTA_EXT_EOCALIF_Msk                (0x01U << ADC_ADSTA_EXT_EOCALIF_Pos)  /*!<*/
#define  ADC_ADSTA_EXT_CALBUSY_Pos                (25)
#define  ADC_ADSTA_EXT_CALBUSY_Msk                (0x01U << ADC_ADSTA_EXT_CALBUSY_Pos)  /*!<*/
#define  ADC_ADSTA_EXT_FREOCIF_Pos                (26)
#define  ADC_ADSTA_EXT_FREOCIF_Msk                (0x01U << ADC_ADSTA_EXT_FREOCIF_Pos)  /*!<*/

/**
  * @brief ADC_CHANY0 Register Bit Definition
  */
#define  ADC_CHANY0_CHANY_SELL0_Pos               (0)
#define  ADC_CHANY0_CHANY_SELL0_Msk               (0x0FU << ADC_CHANY0_CHANY_SELL0_Pos) /*!<*/
#define  ADC_CHANY0_CHANY_SELL1_Pos               (4)
#define  ADC_CHANY0_CHANY_SELL1_Msk               (0x0FU << ADC_CHANY0_CHANY_SELL1_Pos) /*!<*/
#define  ADC_CHANY0_CHANY_SELL2_Pos               (8)
#define  ADC_CHANY0_CHANY_SELL2_Msk               (0x0FU << ADC_CHANY0_CHANY_SELL2_Pos) /*!<*/
#define  ADC_CHANY0_CHANY_SELL3_Pos               (12)
#define  ADC_CHANY0_CHANY_SELL3_Msk               (0x0FU << ADC_CHANY0_CHANY_SELL3_Pos) /*!<*/
#define  ADC_CHANY0_CHANY_SELL4_Pos               (16)
#define  ADC_CHANY0_CHANY_SELL4_Msk               (0x0FU << ADC_CHANY0_CHANY_SELL4_Pos) /*!<*/
#define  ADC_CHANY0_CHANY_SELL5_Pos               (20)
#define  ADC_CHANY0_CHANY_SELL5_Msk               (0x0FU << ADC_CHANY0_CHANY_SELL5_Pos) /*!<*/
#define  ADC_CHANY0_CHANY_SELL6_Pos               (24)
#define  ADC_CHANY0_CHANY_SELL6_Msk               (0x0FU << ADC_CHANY0_CHANY_SELL6_Pos) /*!<*/
#define  ADC_CHANY0_CHANY_SELL7_Pos               (28)
#define  ADC_CHANY0_CHANY_SELL7_Msk               (0x0FU << ADC_CHANY0_CHANY_SELL7_Pos) /*!<*/

/**
  * @brief ADC_CHANY1 Register Bit Definition
  */
#define  ADC_CHANY1_CHANY_SELL8_Pos               (0)
#define  ADC_CHANY1_CHANY_SELL8_Msk               (0x0FU << ADC_CHANY1_CHANY_SELL8_Pos)  /*!<*/
#define  ADC_CHANY1_CHANY_SELL9_Pos               (4)
#define  ADC_CHANY1_CHANY_SELL9_Msk               (0x0FU << ADC_CHANY1_CHANY_SELL9_Pos)  /*!<*/
#define  ADC_CHANY1_CHANY_SELL10_Pos              (8)
#define  ADC_CHANY1_CHANY_SELL10_Msk              (0x0FU << ADC_CHANY1_CHANY_SELL10_Pos) /*!<*/
#define  ADC_CHANY1_CHANY_SELL11_Pos              (12)
#define  ADC_CHANY1_CHANY_SELL11_Msk              (0x0FU << ADC_CHANY1_CHANY_SELL11_Pos) /*!<*/
#define  ADC_CHANY1_CHANY_SELL12_Pos              (16)
#define  ADC_CHANY1_CHANY_SELL12_Msk              (0x0FU << ADC_CHANY1_CHANY_SELL12_Pos) /*!<*/
#define  ADC_CHANY1_CHANY_SELL13_Pos              (20)
#define  ADC_CHANY1_CHANY_SELL13_Msk              (0x0FU << ADC_CHANY1_CHANY_SELL13_Pos) /*!<*/
#define  ADC_CHANY1_CHANY_SELL14_Pos              (24)
#define  ADC_CHANY1_CHANY_SELL14_Msk              (0x0FU << ADC_CHANY1_CHANY_SELL14_Pos) /*!<*/
#define  ADC_CHANY1_CHANY_SELL15_Pos              (28)
#define  ADC_CHANY1_CHANY_SELL15_Msk              (0x0FU << ADC_CHANY1_CHANY_SELL15_Pos) /*!<*/

/**
  * @brief ADC_ANY_CFG Register Bit Definition
  */
#define  ADC_ANY_CFG_CHANY_NUM_Pos                (0)
#define  ADC_ANY_CFG_CHANY_NUM_Msk                (0x0FU << ADC_ANY_CFG_CHANY_NUM_Pos)    /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH0_Pos              (8)
#define  ADC_ANY_CFG_CHANY_SELH0_Msk              (0x01U << ADC_ANY_CFG_CHANY_SELH0_Pos)  /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH1_Pos              (9)
#define  ADC_ANY_CFG_CHANY_SELH1_Msk              (0x01U << ADC_ANY_CFG_CHANY_SELH1_Pos)  /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH2_Pos              (10)
#define  ADC_ANY_CFG_CHANY_SELH2_Msk              (0x01U << ADC_ANY_CFG_CHANY_SELH2_Pos)  /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH3_Pos              (11)
#define  ADC_ANY_CFG_CHANY_SELH3_Msk              (0x01U << ADC_ANY_CFG_CHANY_SELH3_Pos)  /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH4_Pos              (12)
#define  ADC_ANY_CFG_CHANY_SELH4_Msk              (0x01U << ADC_ANY_CFG_CHANY_SELH4_Pos)  /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH5_Pos              (13)
#define  ADC_ANY_CFG_CHANY_SELH5_Msk              (0x01U << ADC_ANY_CFG_CHANY_SELH5_Pos)  /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH6_Pos              (14)
#define  ADC_ANY_CFG_CHANY_SELH6_Msk              (0x01U << ADC_ANY_CFG_CHANY_SELH6_Pos)  /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH7_Pos              (15)
#define  ADC_ANY_CFG_CHANY_SELH7_Msk              (0x01U << ADC_ANY_CFG_CHANY_SELH7_Pos)  /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH8_Pos              (16)
#define  ADC_ANY_CFG_CHANY_SELH8_Msk              (0x01U << ADC_ANY_CFG_CHANY_SELH8_Pos)  /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH9_Pos              (17)
#define  ADC_ANY_CFG_CHANY_SELH9_Msk              (0x01U << ADC_ANY_CFG_CHANY_SELH9_Pos)  /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH10_Pos             (18)
#define  ADC_ANY_CFG_CHANY_SELH10_Msk             (0x01U << ADC_ANY_CFG_CHANY_SELH10_Pos) /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH11_Pos             (19)
#define  ADC_ANY_CFG_CHANY_SELH11_Msk             (0x01U << ADC_ANY_CFG_CHANY_SELH11_Pos) /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH12_Pos             (20)
#define  ADC_ANY_CFG_CHANY_SELH12_Msk             (0x01U << ADC_ANY_CFG_CHANY_SELH12_Pos) /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH13_Pos             (21)
#define  ADC_ANY_CFG_CHANY_SELH13_Msk             (0x01U << ADC_ANY_CFG_CHANY_SELH13_Pos) /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH14_Pos             (22)
#define  ADC_ANY_CFG_CHANY_SELH14_Msk             (0x01U << ADC_ANY_CFG_CHANY_SELH14_Pos) /*!<*/
#define  ADC_ANY_CFG_CHANY_SELH15_Pos             (23)
#define  ADC_ANY_CFG_CHANY_SELH15_Msk             (0x01U << ADC_ANY_CFG_CHANY_SELH15_Pos) /*!<*/

/**
  * @brief ADC_ANY_CR Register Bit Definition
  */
#define  ADC_ANY_CR_CHANY_MDEN_Pos                (0)
#define  ADC_ANY_CR_CHANY_MDEN_Msk                (0x01U << ADC_ANY_CR_CHANY_MDEN_Pos) /*!<*/
#define  ADC_ANY_CR_JCEN_Pos                      (1)
#define  ADC_ANY_CR_JCEN_Msk                      (0x01U << ADC_ANY_CR_JCEN_Pos)       /*!<*/
#define  ADC_ANY_CR_JEOSMPIE_Pos                  (2)
#define  ADC_ANY_CR_JEOSMPIE_Msk                  (0x01U << ADC_ANY_CR_JEOSMPIE_Pos)   /*!<*/
#define  ADC_ANY_CR_JEOCIE_Pos                    (3)
#define  ADC_ANY_CR_JEOCIE_Msk                    (0x01U << ADC_ANY_CR_JEOCIE_Pos)     /*!<*/
#define  ADC_ANY_CR_JEOSIE_Pos                    (4)
#define  ADC_ANY_CR_JEOSIE_Msk                    (0x01U << ADC_ANY_CR_JEOSIE_Pos)     /*!<*/
#define  ADC_ANY_CR_JAUTO_Pos                     (5)
#define  ADC_ANY_CR_JAUTO_Msk                     (0x01U << ADC_ANY_CR_JAUTO_Pos)      /*!<*/
#define  ADC_ANY_CR_JADST_Pos                     (6)
#define  ADC_ANY_CR_JADST_Msk                     (0x01U << ADC_ANY_CR_JADST_Pos)      /*!<*/
#define  ADC_ANY_CR_JTRGEN_Pos                    (7)
#define  ADC_ANY_CR_JTRGEN_Msk                    (0x01U << ADC_ANY_CR_JTRGEN_Pos)     /*!<*/
#define  ADC_ANY_CR_JTRGSEL_Pos                   (8)
#define  ADC_ANY_CR_JTRGSEL_Msk                   (0x1FU << ADC_ANY_CR_JTRGSEL_Pos)    /*!<*/
#define  ADC_ANY_CR_JTRGSHIFT_Pos                 (13)
#define  ADC_ANY_CR_JTRGSHIFT_Msk                 (0x07U << ADC_ANY_CR_JTRGSHIFT_Pos)  /*!<*/
#define  ADC_ANY_CR_JTRG_EDGE_Pos                 (16)
#define  ADC_ANY_CR_JTRG_EDGE_Msk                 (0x03U << ADC_ANY_CR_JTRG_EDGE_Pos)  /*!<*/
#define  ADC_ANY_CR_ADCAL_Pos                     (20)
#define  ADC_ANY_CR_ADCAL_Msk                     (0x01U << ADC_ANY_CR_ADCAL_Pos)      /*!<*/
#define  ADC_ANY_CR_EOCALIE_Pos                   (21)
#define  ADC_ANY_CR_EOCALIE_Msk                   (0x01U << ADC_ANY_CR_EOCALIE_Pos)    /*!<*/

/**
  * @brief ADC_ADCFG2 Register Bit Definition
  */
#define  ADC_ADCFG2_ADCCR_Pos                     (1)
#define  ADC_ADCFG2_ADCCR_Msk                     (0x01U << ADC_ADCFG2_ADCCR_Pos)   /*!<*/
#define  ADC_ADCFG2_ADCSREF_Pos                   (2)
#define  ADC_ADCFG2_ADCSREF_Msk                   (0x01U << ADC_ADCFG2_ADCSREF_Pos) /*!<*/
#define  ADC_ADCFG2_DC_Pos                        (4)
#define  ADC_ADCFG2_DC_Msk                        (0x1FU << ADC_ADCFG2_DC_Pos)      /*!<*/
#define  ADC_ADCFG2_PSDC_Pos                      (10)
#define  ADC_ADCFG2_PSDC_Msk                      (0x1FU << ADC_ADCFG2_PSDC_Pos)    /*!<*/
#define  ADC_ADCFG2_ROVSE_Pos                     (16)
#define  ADC_ADCFG2_ROVSE_Msk                     (0x01U << ADC_ADCFG2_ROVSE_Pos)   /*!<*/
#define  ADC_ADCFG2_JOVSE_Pos                     (17)
#define  ADC_ADCFG2_JOVSE_Msk                     (0x01U << ADC_ADCFG2_JOVSE_Pos)   /*!<*/
#define  ADC_ADCFG2_OVSR_Pos                      (18)
#define  ADC_ADCFG2_OVSR_Msk                      (0x07U << ADC_ADCFG2_OVSR_Pos)    /*!<*/
#define  ADC_ADCFG2_OVSS_Pos                      (21)
#define  ADC_ADCFG2_OVSS_Msk                      (0x0FU << ADC_ADCFG2_OVSS_Pos)    /*!<*/
#define  ADC_ADCFG2_TROVS_Pos                     (25)
#define  ADC_ADCFG2_TROVS_Msk                     (0x01U << ADC_ADCFG2_TROVS_Pos)   /*!<*/

/**
  * @brief ADC_SMPR1 Register Bit Definition
  */
#define  ADC_SMPR1_SAMP0_Pos                      (0)
#define  ADC_SMPR1_SAMP0_Msk                      (0x0FU << ADC_SMPR1_SAMP0_Pos) /*!<*/
#define  ADC_SMPR1_SAMP1_Pos                      (4)
#define  ADC_SMPR1_SAMP1_Msk                      (0x0FU << ADC_SMPR1_SAMP1_Pos) /*!<*/
#define  ADC_SMPR1_SAMP2_Pos                      (8)
#define  ADC_SMPR1_SAMP2_Msk                      (0x0FU << ADC_SMPR1_SAMP2_Pos) /*!<*/
#define  ADC_SMPR1_SAMP3_Pos                      (12)
#define  ADC_SMPR1_SAMP3_Msk                      (0x0FU << ADC_SMPR1_SAMP3_Pos) /*!<*/
#define  ADC_SMPR1_SAMP4_Pos                      (16)
#define  ADC_SMPR1_SAMP4_Msk                      (0x0FU << ADC_SMPR1_SAMP4_Pos) /*!<*/
#define  ADC_SMPR1_SAMP5_Pos                      (20)
#define  ADC_SMPR1_SAMP5_Msk                      (0x0FU << ADC_SMPR1_SAMP5_Pos) /*!<*/
#define  ADC_SMPR1_SAMP6_Pos                      (24)
#define  ADC_SMPR1_SAMP6_Msk                      (0x0FU << ADC_SMPR1_SAMP6_Pos) /*!<*/
#define  ADC_SMPR1_SAMP7_Pos                      (28)
#define  ADC_SMPR1_SAMP7_Msk                      (0x0FU << ADC_SMPR1_SAMP7_Pos) /*!<*/

/**
  * @brief ADC_SMPR2 Register Bit Definition
  */
#define  ADC_SMPR2_SAMP8_Pos                      (0)
#define  ADC_SMPR2_SAMP8_Msk                      (0x0FU << ADC_SMPR2_SAMP8_Pos)  /*!<*/
#define  ADC_SMPR2_SAMP9_Pos                      (4)
#define  ADC_SMPR2_SAMP9_Msk                      (0x0FU << ADC_SMPR2_SAMP9_Pos)  /*!<*/
#define  ADC_SMPR2_SAMP10_Pos                     (8)
#define  ADC_SMPR2_SAMP10_Msk                     (0x0FU << ADC_SMPR2_SAMP10_Pos) /*!<*/
#define  ADC_SMPR2_SAMP11_Pos                     (12)
#define  ADC_SMPR2_SAMP11_Msk                     (0x0FU << ADC_SMPR2_SAMP11_Pos) /*!<*/
#define  ADC_SMPR2_SAMP12_Pos                     (16)
#define  ADC_SMPR2_SAMP12_Msk                     (0x0FU << ADC_SMPR2_SAMP12_Pos) /*!<*/
#define  ADC_SMPR2_SAMP13_Pos                     (20)
#define  ADC_SMPR2_SAMP13_Msk                     (0x0FU << ADC_SMPR2_SAMP13_Pos) /*!<*/
#define  ADC_SMPR2_SAMP14_Pos                     (24)
#define  ADC_SMPR2_SAMP14_Msk                     (0x0FU << ADC_SMPR2_SAMP14_Pos) /*!<*/
#define  ADC_SMPR2_SAMP15_Pos                     (28)
#define  ADC_SMPR2_SAMP15_Msk                     (0x0FU << ADC_SMPR2_SAMP15_Pos) /*!<*/

/**
  * @brief ADC_SMPR3 Register Bit Definition
  */
#define  ADC_SMPR3_SAMP16_Pos                     (0)
#define  ADC_SMPR3_SAMP16_Msk                     (0x0FU << ADC_SMPR3_SAMP16_Pos) /*!<*/
#define  ADC_SMPR3_SAMP17_Pos                     (4)
#define  ADC_SMPR3_SAMP17_Msk                     (0x0FU << ADC_SMPR3_SAMP17_Pos) /*!<*/
#define  ADC_SMPR3_SAMP18_Pos                     (8)
#define  ADC_SMPR3_SAMP18_Msk                     (0x0FU << ADC_SMPR3_SAMP18_Pos) /*!<*/

/**
  * @brief ADC_JOFR Register Bit Definition
  */
#define  ADC_JOFR_JOFFSET_Pos                     (0)
#define  ADC_JOFR_JOFFSET_Msk                     (0x0FFFU << ADC_JOFR_JOFFSET_Pos) /*!<*/

/**
  * @brief ADC_JSQR Register Bit Definition
  */
#define  ADC_JSQR_JSQ0_Pos                        (0)
#define  ADC_JSQR_JSQ0_Msk                        (0x1FU << ADC_JSQR_JSQ0_Pos) /*!<*/
#define  ADC_JSQR_JSQ1_Pos                        (5)
#define  ADC_JSQR_JSQ1_Msk                        (0x1FU << ADC_JSQR_JSQ1_Pos) /*!<*/
#define  ADC_JSQR_JSQ2_Pos                        (10)
#define  ADC_JSQR_JSQ2_Msk                        (0x1FU << ADC_JSQR_JSQ2_Pos) /*!<*/
#define  ADC_JSQR_JSQ3_Pos                        (15)
#define  ADC_JSQR_JSQ3_Msk                        (0x1FU << ADC_JSQR_JSQ3_Pos) /*!<*/
#define  ADC_JSQR_JNUM_Pos                        (20)
#define  ADC_JSQR_JNUM_Msk                        (0x03U << ADC_JSQR_JNUM_Pos) /*!<*/

/**
  * @brief ADC_JADDATA Register Bit Definition
  */
#define  ADC_JADDATA_JDATA_Pos                    (0)
#define  ADC_JADDATA_JDATA_Msk                    (0xFFFFU << ADC_JADDATA_JDATA_Pos)     /*!<*/
#define  ADC_JADDATA_JCHANNELSEL_Pos              (16)
#define  ADC_JADDATA_JCHANNELSEL_Msk              (0x1FU << ADC_JADDATA_JCHANNELSEL_Pos) /*!<*/
#define  ADC_JADDATA_JOVERRUN_Pos                 (21)
#define  ADC_JADDATA_JOVERRUN_Msk                 (0x01U << ADC_JADDATA_JOVERRUN_Pos)    /*!<*/
#define  ADC_JADDATA_JVALID_Pos                   (22)
#define  ADC_JADDATA_JVALID_Msk                   (0x01U << ADC_JADDATA_JVALID_Pos)      /*!<*/

/**
  * @brief ADC_JDR Register Bit Definition
  */
#define  ADC_JDR_JDATA_Pos                        (0)
#define  ADC_JDR_JDATA_Msk                        (0xFFFFU << ADC_JDR_JDATA_Pos)  /*!<*/
#define  ADC_JDR_JOVERRUN_Pos                     (21)
#define  ADC_JDR_JOVERRUN_Msk                     (0x01U << ADC_JDR_JOVERRUN_Pos) /*!<*/
#define  ADC_JDR_JVALID_Pos                       (22)
#define  ADC_JDR_JVALID_Msk                       (0x01U << ADC_JDR_JVALID_Pos)   /*!<*/

#endif

