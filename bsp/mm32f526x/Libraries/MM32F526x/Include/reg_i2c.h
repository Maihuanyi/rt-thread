/***********************************************************************************************************************
    @file     reg_i2c.h
    @author   VV TEAM
    @brief    This flie contains all the I2C's register and its field definition.
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

#ifndef __REG_I2C_H
#define __REG_I2C_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief I2C Base Address Definition
  */
#define  I2C1_BASE                                 0x40005400 /*!<Base Address: 0x40005400*/
#define  I2C2_BASE                                 0x40005800 /*!<Base Address: 0x40005800*/

/**
  * @brief I2C Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                  /*!<I2C Control Register                           offset: 0x00*/
    __IO uint32_t TAR;                 /*!<I2C Target Address Register                    offset: 0x04*/
    __IO uint32_t SAR;                 /*!<I2C Slave Address Register                     offset: 0x08*/
    __IO uint32_t RESERVED0x00C[1];    /*!<                                               offset: 0xc*/
    __IO uint32_t DR;                  /*!<I2C Data Command Register                      offset: 0x10*/
    __IO uint32_t SSHR;                /*!<I2C Standard Mode SCL High Count Register      offset: 0x14*/
    __IO uint32_t SSLR;                /*!<I2C Standard Mode SCL Low Count Register       offset: 0x18*/
    __IO uint32_t FSHR;                /*!<I2C Fast Mode/Fast Mode Plus SCL High Count Register offset: 0x1C*/
    __IO uint32_t FSLR;                /*!<I2C Fast Mode/Fast Mode Plus SCL Low Count Register offset: 0x20*/
    __IO uint32_t RESERVED0x024[2];    /*!<                                               offset: 0x24~0x28*/
    __IO uint32_t ISR;                 /*!<I2C Interrupt Status Register                  offset: 0x2C*/
    __IO uint32_t IMR;                 /*!<I2C Interrupt Mask Register                    offset: 0x30*/
    __IO uint32_t RAWISR;              /*!<I2C RAW Interrupt Status Register              offset: 0x34*/
    __IO uint32_t RXTLR;               /*!<I2C Receive Threshold Register                 offset: 0x38*/
    __IO uint32_t TXTLR;               /*!<I2C Transmit Threshold Register                offset: 0x3C*/
    __IO uint32_t ICR;                 /*!<I2C Combined and Independent Interrupt Clear Register offset: 0x40*/
    __IO uint32_t RX_UNDER;            /*!<I2C RX_UNDER Interrupt Clear Register          offset: 0x44*/
    __IO uint32_t RX_OVER;             /*!<I2C RX_OVER Interrupt Clear Register           offset: 0x48*/
    __IO uint32_t TX_OVER;             /*!<I2C TX_OVER Interrupt Clear Register           offset: 0x4C*/
    __IO uint32_t RD_REQ;              /*!<I2C RD_REQ Interrupt Clear Register            offset: 0x50*/
    __IO uint32_t TX_ABRT;             /*!<I2C TX_ABRT Interrupt Clear Register           offset: 0x54*/
    __IO uint32_t RX_DONE;             /*!<I2C RX_DONE Interrupt Clear Register           offset: 0x58*/
    __IO uint32_t ACTIV;               /*!<I2C ACTIVITY Interrupt Clear Register          offset: 0x5C*/
    __IO uint32_t STOP;                /*!<I2C STOP_DET Interrupt Clear Register          offset: 0x60*/
    __IO uint32_t START;               /*!<I2C START_DET Interrupt Clear Register         offset: 0x64*/
    __IO uint32_t GC;                  /*!<I2C GEN_CALL Interrupt Clear Register          offset: 0x68*/
    __IO uint32_t ENR;                 /*!<I2C Enable Register                            offset: 0x6C*/
    __IO uint32_t SR;                  /*!<I2C Status Register                            offset: 0x70*/
    __IO uint32_t TXFLR;               /*!<I2C Transmit FIFO Level Register               offset: 0x74*/
    __IO uint32_t RXFLR;               /*!<I2C Receive FIFO Level Register                offset: 0x78*/
    __IO uint32_t HOLD;                /*!<I2C SDA Hold Time Register                     offset: 0x7C*/
    __IO uint32_t TX_ABRT_SRC;         /*!<I2C Transfer Abort Source Register             offset: 0x80*/
    __IO uint32_t SLV_NACK;            /*!<I2C Slave Receive NACK Register                offset: 0x84*/
    __IO uint32_t DMA;                 /*!<I2C DMA Control Register                       offset: 0x88*/
    __IO uint32_t RESERVED0x08C[2];    /*!<                                               offset: 0x8c~0x90*/
    __IO uint32_t SETUP;               /*!<I2C SDA Setup Time Register                    offset: 0x94*/
    __IO uint32_t GCR;                 /*!<I2C General Call ACK Register                  offset: 0x98*/
    __IO uint32_t EN_SR;               /*!<I2C ENABLE Status Register                     offset: 0x9C*/
    __IO uint32_t SPKLEN;              /*!<I2C Filter Register                            offset: 0xA0*/
    __IO uint32_t RESERVED0x0A4[2];    /*!<                                               offset: 0xa4~0xa8*/
    __IO uint32_t SCL_TMO;             /*!<I2C SCL Low Timeout Register                   offset: 0xAC*/
    __IO uint32_t SDA_TMO;             /*!<I2C SDA Low Timeout Register                   offset: 0xB0*/
    __IO uint32_t SCL_STUCK;           /*!<I2C Clear SCL_STUCK Interrupt Register         offset: 0xB4*/
    __IO uint32_t RESERVED0x0B8[1];    /*!<                                               offset: 0xb8*/
    __IO uint32_t SMB_SEXT;            /*!<I2C SMBus Slave Device Clock Extension Timeout Register offset: 0xBC*/
    __IO uint32_t SMB_MEXT;            /*!<I2C SMBus Master Device Clock Extension Timeout Register offset: 0xC0*/
    __IO uint32_t SMB_IDLE;            /*!<I2C SMBus Bus Idle Count Register              offset: 0xC4*/
    __IO uint32_t SMB_ISR;             /*!<I2C SMBus Interrupt Status Register            offset: 0xC8*/
    __IO uint32_t SMB_IMR;             /*!<I2C SMBus Interrupt Mask Register              offset: 0xCC*/
    __IO uint32_t SMB_RAWISR;          /*!<I2C SMBus RAW Interrupt Register               offset: 0xD0*/
    __IO uint32_t SMB_ICR;             /*!<I2C SMBus Combinational and Independent Interrupt Clear Register offset: 0xD4*/
    __IO uint32_t OPT_SAR;             /*!<I2C Optional Slave Address Register            offset: 0xD8*/
    __IO uint32_t SMB_UDID_LSB;        /*!<I2C SMBus UDID LSB Register                    offset: 0xDC*/
    __IO uint32_t SMB_UDID_MSB0;       /*!<I2C SMBus UDID MSB Register 0                  offset: 0xE0*/
    __IO uint32_t SMB_UDID_MSB1;       /*!<I2C SMBus UDID MSB Register 1                  offset: 0xE4*/
    __IO uint32_t SMB_UDID_MSB2;       /*!<I2C SMBus UDID MSB Register 2                  offset: 0xE8*/
    __IO uint32_t SLVMASK;             /*!<I2C Slave Address Mask Register                offset: 0xEC*/
    __IO uint32_t SLVRCVADDR;          /*!<I2C Slave Address Receive Register             offset: 0xF0*/
} I2C_TypeDef;

/**
  * @brief I2C type pointer Definition
  */
#define I2C1                                      ((I2C_TypeDef *)I2C1_BASE)
#define I2C2                                      ((I2C_TypeDef *)I2C2_BASE)

/**
  * @brief I2C_CR Register Bit Definition
  */
#define  I2C_CR_MASTER_Pos                        (0)
#define  I2C_CR_MASTER_Msk                        (0x01U << I2C_CR_MASTER_Pos)           /*!<*/
#define  I2C_CR_SPEED_Pos                         (1)
#define  I2C_CR_SPEED_Msk                         (0x03U << I2C_CR_SPEED_Pos)            /*!<*/
#define  I2C_CR_SLAVE10_Pos                       (3)
#define  I2C_CR_SLAVE10_Msk                       (0x01U << I2C_CR_SLAVE10_Pos)          /*!<*/
#define  I2C_CR_MASTER10_Pos                      (4)
#define  I2C_CR_MASTER10_Msk                      (0x01U << I2C_CR_MASTER10_Pos)         /*!<*/
#define  I2C_CR_REPEN_Pos                         (5)
#define  I2C_CR_REPEN_Msk                         (0x01U << I2C_CR_REPEN_Pos)            /*!<*/
#define  I2C_CR_DISSLAVE_Pos                      (6)
#define  I2C_CR_DISSLAVE_Msk                      (0x01U << I2C_CR_DISSLAVE_Pos)         /*!<*/
#define  I2C_CR_STOPINT_Pos                       (7)
#define  I2C_CR_STOPINT_Msk                       (0x01U << I2C_CR_STOPINT_Pos)          /*!<*/
#define  I2C_CR_EMPINT_Pos                        (8)
#define  I2C_CR_EMPINT_Msk                        (0x01U << I2C_CR_EMPINT_Pos)           /*!<*/
#define  I2C_CR_STOP_Pos                          (9)
#define  I2C_CR_STOP_Msk                          (0x01U << I2C_CR_STOP_Pos)             /*!<*/
#define  I2C_CR_RESTART_Pos                       (10)
#define  I2C_CR_RESTART_Msk                       (0x01U << I2C_CR_RESTART_Pos)          /*!<*/
#define  I2C_CR_SLV_TX_ABRT_DIS_Pos               (11)
#define  I2C_CR_SLV_TX_ABRT_DIS_Msk               (0x01U << I2C_CR_SLV_TX_ABRT_DIS_Pos)  /*!<*/
#define  I2C_CR_PAD_SEL_Pos                       (12)
#define  I2C_CR_PAD_SEL_Msk                       (0x01U << I2C_CR_PAD_SEL_Pos)          /*!<*/
#define  I2C_CR_OPT_SAR_EN_Pos                    (16)
#define  I2C_CR_OPT_SAR_EN_Msk                    (0x01U << I2C_CR_OPT_SAR_EN_Pos)       /*!<*/
#define  I2C_CR_SMB_SLV_QC_EN_Pos                 (17)
#define  I2C_CR_SMB_SLV_QC_EN_Msk                 (0x01U << I2C_CR_SMB_SLV_QC_EN_Pos)    /*!<*/
#define  I2C_CR_SMB_ARP_EN_Pos                    (18)
#define  I2C_CR_SMB_ARP_EN_Msk                    (0x01U << I2C_CR_SMB_ARP_EN_Pos)       /*!<*/
#define  I2C_CR_SMB_PSA_EN_Pos                    (19)
#define  I2C_CR_SMB_PSA_EN_Msk                    (0x01U << I2C_CR_SMB_PSA_EN_Pos)       /*!<*/
#define  I2C_CR_STOP_DET_MST_ACT_Pos              (20)
#define  I2C_CR_STOP_DET_MST_ACT_Msk              (0x01U << I2C_CR_STOP_DET_MST_ACT_Pos) /*!<*/
#define  I2C_CR_BUS_CLR_Pos                       (21)
#define  I2C_CR_BUS_CLR_Msk                       (0x01U << I2C_CR_BUS_CLR_Pos)          /*!<*/
#define  I2C_CR_RX_FULL_HLD_Pos                   (22)
#define  I2C_CR_RX_FULL_HLD_Msk                   (0x01U << I2C_CR_RX_FULL_HLD_Pos)      /*!<*/

/**
  * @brief I2C_TAR Register Bit Definition
  */
#define  I2C_TAR_ADDR_Pos                         (0)
#define  I2C_TAR_ADDR_Msk                         (0x03FFU << I2C_TAR_ADDR_Pos)  /*!<*/
#define  I2C_TAR_GC_Pos                           (10)
#define  I2C_TAR_GC_Msk                           (0x01U << I2C_TAR_GC_Pos)      /*!<*/
#define  I2C_TAR_SPECIAL_Pos                      (11)
#define  I2C_TAR_SPECIAL_Msk                      (0x01U << I2C_TAR_SPECIAL_Pos) /*!<*/
#define  I2C_TAR_SMB_QC_Pos                       (16)
#define  I2C_TAR_SMB_QC_Msk                       (0x01U << I2C_TAR_SMB_QC_Pos)  /*!<*/

/**
  * @brief I2C_SAR Register Bit Definition
  */
#define  I2C_SAR_ADDR_Pos                         (0)
#define  I2C_SAR_ADDR_Msk                         (0x03FFU << I2C_SAR_ADDR_Pos) /*!<*/

/**
  * @brief I2C_DR Register Bit Definition
  */
#define  I2C_DR_DAT_Pos                           (0)
#define  I2C_DR_DAT_Msk                           (0xFFU << I2C_DR_DAT_Pos)        /*!<*/
#define  I2C_DR_CMD_Pos                           (8)
#define  I2C_DR_CMD_Msk                           (0x01U << I2C_DR_CMD_Pos)        /*!<*/
#define  I2C_DR_FIRST_DATA_Pos                    (11)
#define  I2C_DR_FIRST_DATA_Msk                    (0x01U << I2C_DR_FIRST_DATA_Pos) /*!<*/

/**
  * @brief I2C_SSHR Register Bit Definition
  */
#define  I2C_SSHR_CNT_Pos                         (0)
#define  I2C_SSHR_CNT_Msk                         (0xFFFFU << I2C_SSHR_CNT_Pos) /*!<*/

/**
  * @brief I2C_SSLR Register Bit Definition
  */
#define  I2C_SSLR_CNT_Pos                         (0)
#define  I2C_SSLR_CNT_Msk                         (0xFFFFU << I2C_SSLR_CNT_Pos) /*!<*/

/**
  * @brief I2C_FSHR Register Bit Definition
  */
#define  I2C_FSHR_CNT_Pos                         (0)
#define  I2C_FSHR_CNT_Msk                         (0xFFFFU << I2C_FSHR_CNT_Pos) /*!<*/

/**
  * @brief I2C_FSLR Register Bit Definition
  */
#define  I2C_FSLR_CNT_Pos                         (0)
#define  I2C_FSLR_CNT_Msk                         (0xFFFFU << I2C_FSLR_CNT_Pos) /*!<*/

/**
  * @brief I2C_ISR Register Bit Definition
  */
#define  I2C_ISR_R_RX_UNDER_Pos                   (0)
#define  I2C_ISR_R_RX_UNDER_Msk                   (0x01U << I2C_ISR_R_RX_UNDER_Pos)         /*!<*/
#define  I2C_ISR_R_RX_OVER_Pos                    (1)
#define  I2C_ISR_R_RX_OVER_Msk                    (0x01U << I2C_ISR_R_RX_OVER_Pos)          /*!<*/
#define  I2C_ISR_R_RX_FULL_Pos                    (2)
#define  I2C_ISR_R_RX_FULL_Msk                    (0x01U << I2C_ISR_R_RX_FULL_Pos)          /*!<*/
#define  I2C_ISR_R_TX_OVER_Pos                    (3)
#define  I2C_ISR_R_TX_OVER_Msk                    (0x01U << I2C_ISR_R_TX_OVER_Pos)          /*!<*/
#define  I2C_ISR_R_TX_EMPTY_Pos                   (4)
#define  I2C_ISR_R_TX_EMPTY_Msk                   (0x01U << I2C_ISR_R_TX_EMPTY_Pos)         /*!<*/
#define  I2C_ISR_R_RD_REQ_Pos                     (5)
#define  I2C_ISR_R_RD_REQ_Msk                     (0x01U << I2C_ISR_R_RD_REQ_Pos)           /*!<*/
#define  I2C_ISR_R_TX_ABRT_Pos                    (6)
#define  I2C_ISR_R_TX_ABRT_Msk                    (0x01U << I2C_ISR_R_TX_ABRT_Pos)          /*!<*/
#define  I2C_ISR_R_RX_DONE_Pos                    (7)
#define  I2C_ISR_R_RX_DONE_Msk                    (0x01U << I2C_ISR_R_RX_DONE_Pos)          /*!<*/
#define  I2C_ISR_R_ACTIV_Pos                      (8)
#define  I2C_ISR_R_ACTIV_Msk                      (0x01U << I2C_ISR_R_ACTIV_Pos)            /*!<*/
#define  I2C_ISR_R_STOP_Pos                       (9)
#define  I2C_ISR_R_STOP_Msk                       (0x01U << I2C_ISR_R_STOP_Pos)             /*!<*/
#define  I2C_ISR_R_START_Pos                      (10)
#define  I2C_ISR_R_START_Msk                      (0x01U << I2C_ISR_R_START_Pos)            /*!<*/
#define  I2C_ISR_R_GC_Pos                         (11)
#define  I2C_ISR_R_GC_Msk                         (0x01U << I2C_ISR_R_GC_Pos)               /*!<*/
#define  I2C_ISR_R_MST_ON_HOLD_Pos                (13)
#define  I2C_ISR_R_MST_ON_HOLD_Msk                (0x01U << I2C_ISR_R_MST_ON_HOLD_Pos)      /*!<*/
#define  I2C_ISR_R_SCL_STUCK_AT_LOW_Pos           (14)
#define  I2C_ISR_R_SCL_STUCK_AT_LOW_Msk           (0x01U << I2C_ISR_R_SCL_STUCK_AT_LOW_Pos) /*!<*/

/**
  * @brief I2C_IMR Register Bit Definition
  */
#define  I2C_IMR_M_RX_UNDER_Pos                   (0)
#define  I2C_IMR_M_RX_UNDER_Msk                   (0x01U << I2C_IMR_M_RX_UNDER_Pos)    /*!<*/
#define  I2C_IMR_M_RX_OVER_Pos                    (1)
#define  I2C_IMR_M_RX_OVER_Msk                    (0x01U << I2C_IMR_M_RX_OVER_Pos)     /*!<*/
#define  I2C_IMR_M_RX_FULL_Pos                    (2)
#define  I2C_IMR_M_RX_FULL_Msk                    (0x01U << I2C_IMR_M_RX_FULL_Pos)     /*!<*/
#define  I2C_IMR_M_TX_OVER_Pos                    (3)
#define  I2C_IMR_M_TX_OVER_Msk                    (0x01U << I2C_IMR_M_TX_OVER_Pos)     /*!<*/
#define  I2C_IMR_M_TX_EMPTY_Pos                   (4)
#define  I2C_IMR_M_TX_EMPTY_Msk                   (0x01U << I2C_IMR_M_TX_EMPTY_Pos)    /*!<*/
#define  I2C_IMR_M_RD_REQ_Pos                     (5)
#define  I2C_IMR_M_RD_REQ_Msk                     (0x01U << I2C_IMR_M_RD_REQ_Pos)      /*!<*/
#define  I2C_IMR_M_TX_ABRT_Pos                    (6)
#define  I2C_IMR_M_TX_ABRT_Msk                    (0x01U << I2C_IMR_M_TX_ABRT_Pos)     /*!<*/
#define  I2C_IMR_M_RX_DONE_Pos                    (7)
#define  I2C_IMR_M_RX_DONE_Msk                    (0x01U << I2C_IMR_M_RX_DONE_Pos)     /*!<*/
#define  I2C_IMR_M_ACTIV_Pos                      (8)
#define  I2C_IMR_M_ACTIV_Msk                      (0x01U << I2C_IMR_M_ACTIV_Pos)       /*!<*/
#define  I2C_IMR_M_STOP_Pos                       (9)
#define  I2C_IMR_M_STOP_Msk                       (0x01U << I2C_IMR_M_STOP_Pos)        /*!<*/
#define  I2C_IMR_M_START_Pos                      (10)
#define  I2C_IMR_M_START_Msk                      (0x01U << I2C_IMR_M_START_Pos)       /*!<*/
#define  I2C_IMR_M_GC_Pos                         (11)
#define  I2C_IMR_M_GC_Msk                         (0x01U << I2C_IMR_M_GC_Pos)          /*!<*/
#define  I2C_IMR_M_MST_ON_HOLD_Pos                (13)
#define  I2C_IMR_M_MST_ON_HOLD_Msk                (0x01U << I2C_IMR_M_MST_ON_HOLD_Pos) /*!<*/
#define  I2C_IMR_M_SCL_STUCK_Pos                  (14)
#define  I2C_IMR_M_SCL_STUCK_Msk                  (0x01U << I2C_IMR_M_SCL_STUCK_Pos)   /*!<*/

/**
  * @brief I2C_RAWISR Register Bit Definition
  */
#define  I2C_RAWISR_RX_UNDER_Pos                  (0)
#define  I2C_RAWISR_RX_UNDER_Msk                  (0x01U << I2C_RAWISR_RX_UNDER_Pos)    /*!<*/
#define  I2C_RAWISR_RX_OVER_Pos                   (1)
#define  I2C_RAWISR_RX_OVER_Msk                   (0x01U << I2C_RAWISR_RX_OVER_Pos)     /*!<*/
#define  I2C_RAWISR_RX_FULL_Pos                   (2)
#define  I2C_RAWISR_RX_FULL_Msk                   (0x01U << I2C_RAWISR_RX_FULL_Pos)     /*!<*/
#define  I2C_RAWISR_TX_OVER_Pos                   (3)
#define  I2C_RAWISR_TX_OVER_Msk                   (0x01U << I2C_RAWISR_TX_OVER_Pos)     /*!<*/
#define  I2C_RAWISR_TX_EMPTY_Pos                  (4)
#define  I2C_RAWISR_TX_EMPTY_Msk                  (0x01U << I2C_RAWISR_TX_EMPTY_Pos)    /*!<*/
#define  I2C_RAWISR_RD_REQ_Pos                    (5)
#define  I2C_RAWISR_RD_REQ_Msk                    (0x01U << I2C_RAWISR_RD_REQ_Pos)      /*!<*/
#define  I2C_RAWISR_TX_ABRT_Pos                   (6)
#define  I2C_RAWISR_TX_ABRT_Msk                   (0x01U << I2C_RAWISR_TX_ABRT_Pos)     /*!<*/
#define  I2C_RAWISR_RX_DONE_Pos                   (7)
#define  I2C_RAWISR_RX_DONE_Msk                   (0x01U << I2C_RAWISR_RX_DONE_Pos)     /*!<*/
#define  I2C_RAWISR_ACTIV_Pos                     (8)
#define  I2C_RAWISR_ACTIV_Msk                     (0x01U << I2C_RAWISR_ACTIV_Pos)       /*!<*/
#define  I2C_RAWISR_STOP_Pos                      (9)
#define  I2C_RAWISR_STOP_Msk                      (0x01U << I2C_RAWISR_STOP_Pos)        /*!<*/
#define  I2C_RAWISR_START_Pos                     (10)
#define  I2C_RAWISR_START_Msk                     (0x01U << I2C_RAWISR_START_Pos)       /*!<*/
#define  I2C_RAWISR_GC_Pos                        (11)
#define  I2C_RAWISR_GC_Msk                        (0x01U << I2C_RAWISR_GC_Pos)          /*!<*/
#define  I2C_RAWISR_MST_ON_HOLD_Pos               (13)
#define  I2C_RAWISR_MST_ON_HOLD_Msk               (0x01U << I2C_RAWISR_MST_ON_HOLD_Pos) /*!<*/
#define  I2C_RAWISR_SCL_STUCK_Pos                 (14)
#define  I2C_RAWISR_SCL_STUCK_Msk                 (0x01U << I2C_RAWISR_SCL_STUCK_Pos)   /*!<*/

/**
  * @brief I2C_RXTLR Register Bit Definition
  */
#define  I2C_RXTLR_TL_Pos                         (0)
#define  I2C_RXTLR_TL_Msk                         (0x03U << I2C_RXTLR_TL_Pos) /*!<*/

/**
  * @brief I2C_TXTLR Register Bit Definition
  */
#define  I2C_TXTLR_TL_Pos                         (0)
#define  I2C_TXTLR_TL_Msk                         (0x03U << I2C_TXTLR_TL_Pos) /*!<*/

/**
  * @brief I2C_ICR Register Bit Definition
  */
#define  I2C_ICR_ICR_Pos                          (0)
#define  I2C_ICR_ICR_Msk                          (0x01U << I2C_ICR_ICR_Pos) /*!<*/

/**
  * @brief I2C_RX_UNDER Register Bit Definition
  */
#define  I2C_RX_UNDER_RX_UNDER_Pos                (0)
#define  I2C_RX_UNDER_RX_UNDER_Msk                (0x01U << I2C_RX_UNDER_RX_UNDER_Pos) /*!<*/

/**
  * @brief I2C_RX_OVER Register Bit Definition
  */
#define  I2C_RX_OVER_RX_OVER_Pos                  (0)
#define  I2C_RX_OVER_RX_OVER_Msk                  (0x01U << I2C_RX_OVER_RX_OVER_Pos) /*!<*/

/**
  * @brief I2C_TX_OVER Register Bit Definition
  */
#define  I2C_TX_OVER_TX_OVER_Pos                  (0)
#define  I2C_TX_OVER_TX_OVER_Msk                  (0x01U << I2C_TX_OVER_TX_OVER_Pos) /*!<*/

/**
  * @brief I2C_RD_REQ Register Bit Definition
  */
#define  I2C_RD_REQ_RD_REQ_Pos                    (0)
#define  I2C_RD_REQ_RD_REQ_Msk                    (0x01U << I2C_RD_REQ_RD_REQ_Pos) /*!<*/

/**
  * @brief I2C_TX_ABRT Register Bit Definition
  */
#define  I2C_TX_ABRT_TX_ABRT_Pos                  (0)
#define  I2C_TX_ABRT_TX_ABRT_Msk                  (0x01U << I2C_TX_ABRT_TX_ABRT_Pos) /*!<*/

/**
  * @brief I2C_RX_DONE Register Bit Definition
  */
#define  I2C_RX_DONE_RX_DONE_Pos                  (0)
#define  I2C_RX_DONE_RX_DONE_Msk                  (0x01U << I2C_RX_DONE_RX_DONE_Pos) /*!<*/

/**
  * @brief I2C_ACTIV Register Bit Definition
  */
#define  I2C_ACTIV_ACTIV_Pos                      (0)
#define  I2C_ACTIV_ACTIV_Msk                      (0x01U << I2C_ACTIV_ACTIV_Pos) /*!<*/

/**
  * @brief I2C_STOP Register Bit Definition
  */
#define  I2C_STOP_STOP_Pos                        (0)
#define  I2C_STOP_STOP_Msk                        (0x01U << I2C_STOP_STOP_Pos) /*!<*/

/**
  * @brief I2C_START Register Bit Definition
  */
#define  I2C_START_START_Pos                      (0)
#define  I2C_START_START_Msk                      (0x01U << I2C_START_START_Pos) /*!<*/

/**
  * @brief I2C_GC Register Bit Definition
  */
#define  I2C_GC_GC_Pos                            (0)
#define  I2C_GC_GC_Msk                            (0x01U << I2C_GC_GC_Pos) /*!<*/

/**
  * @brief I2C_ENR Register Bit Definition
  */
#define  I2C_ENR_ENABLE_Pos                       (0)
#define  I2C_ENR_ENABLE_Msk                       (0x01U << I2C_ENR_ENABLE_Pos)       /*!<*/
#define  I2C_ENR_ABORT_Pos                        (1)
#define  I2C_ENR_ABORT_Msk                        (0x01U << I2C_ENR_ABORT_Pos)        /*!<*/
#define  I2C_ENR_TX_CMD_BLOCK_Pos                 (2)
#define  I2C_ENR_TX_CMD_BLOCK_Msk                 (0x01U << I2C_ENR_TX_CMD_BLOCK_Pos) /*!<*/
#define  I2C_ENR_SDA_RCV_EN_Pos                   (3)
#define  I2C_ENR_SDA_RCV_EN_Msk                   (0x01U << I2C_ENR_SDA_RCV_EN_Pos)   /*!<*/
#define  I2C_ENR_SMB_CLK_RST_Pos                  (16)
#define  I2C_ENR_SMB_CLK_RST_Msk                  (0x01U << I2C_ENR_SMB_CLK_RST_Pos)  /*!<*/
#define  I2C_ENR_SMB_ALT_EN_Pos                   (18)
#define  I2C_ENR_SMB_ALT_EN_Msk                   (0x01U << I2C_ENR_SMB_ALT_EN_Pos)   /*!<*/

/**
  * @brief I2C_SR Register Bit Definition
  */
#define  I2C_SR_ACTIV_Pos                         (0)
#define  I2C_SR_ACTIV_Msk                         (0x01U << I2C_SR_ACTIV_Pos)             /*!<*/
#define  I2C_SR_TFNF_Pos                          (1)
#define  I2C_SR_TFNF_Msk                          (0x01U << I2C_SR_TFNF_Pos)              /*!<*/
#define  I2C_SR_TFE_Pos                           (2)
#define  I2C_SR_TFE_Msk                           (0x01U << I2C_SR_TFE_Pos)               /*!<*/
#define  I2C_SR_RFNE_Pos                          (3)
#define  I2C_SR_RFNE_Msk                          (0x01U << I2C_SR_RFNE_Pos)              /*!<*/
#define  I2C_SR_RFF_Pos                           (4)
#define  I2C_SR_RFF_Msk                           (0x01U << I2C_SR_RFF_Pos)               /*!<*/
#define  I2C_SR_MST_ACTIV_Pos                     (5)
#define  I2C_SR_MST_ACTIV_Msk                     (0x01U << I2C_SR_MST_ACTIV_Pos)         /*!<*/
#define  I2C_SR_SLV_ACTIV_Pos                     (6)
#define  I2C_SR_SLV_ACTIV_Msk                     (0x01U << I2C_SR_SLV_ACTIV_Pos)         /*!<*/
#define  I2C_SR_MST_HOLD_TX_EMPTY_Pos             (7)
#define  I2C_SR_MST_HOLD_TX_EMPTY_Msk             (0x01U << I2C_SR_MST_HOLD_TX_EMPTY_Pos) /*!<*/
#define  I2C_SR_MST_HOLD_RX_FULL_Pos              (8)
#define  I2C_SR_MST_HOLD_RX_FULL_Msk              (0x01U << I2C_SR_MST_HOLD_RX_FULL_Pos)  /*!<*/
#define  I2C_SR_SLV_HOLD_TX_EMPTY_Pos             (9)
#define  I2C_SR_SLV_HOLD_TX_EMPTY_Msk             (0x01U << I2C_SR_SLV_HOLD_TX_EMPTY_Pos) /*!<*/
#define  I2C_SR_SLV_HOLD_RX_FULL_Pos              (10)
#define  I2C_SR_SLV_HOLD_RX_FULL_Msk              (0x01U << I2C_SR_SLV_HOLD_RX_FULL_Pos)  /*!<*/
#define  I2C_SR_SDA_NOT_RECOVERED_Pos             (11)
#define  I2C_SR_SDA_NOT_RECOVERED_Msk             (0x01U << I2C_SR_SDA_NOT_RECOVERED_Pos) /*!<*/
#define  I2C_SR_SMB_QC_Pos                        (16)
#define  I2C_SR_SMB_QC_Msk                        (0x01U << I2C_SR_SMB_QC_Pos)            /*!<*/
#define  I2C_SR_SMB_SLV_AV_Pos                    (17)
#define  I2C_SR_SMB_SLV_AV_Msk                    (0x01U << I2C_SR_SMB_SLV_AV_Pos)        /*!<*/
#define  I2C_SR_SMB_SLV_AR_Pos                    (18)
#define  I2C_SR_SMB_SLV_AR_Msk                    (0x01U << I2C_SR_SMB_SLV_AR_Pos)        /*!<*/
#define  I2C_SR_SMB_ALT_Pos                       (20)
#define  I2C_SR_SMB_ALT_Msk                       (0x01U << I2C_SR_SMB_ALT_Pos)           /*!<*/

/**
  * @brief I2C_TXFLR Register Bit Definition
  */
#define  I2C_TXFLR_CNT_Pos                        (0)
#define  I2C_TXFLR_CNT_Msk                        (0x07U << I2C_TXFLR_CNT_Pos) /*!<*/

/**
  * @brief I2C_RXFLR Register Bit Definition
  */
#define  I2C_RXFLR_CNT_Pos                        (0)
#define  I2C_RXFLR_CNT_Msk                        (0x07U << I2C_RXFLR_CNT_Pos) /*!<*/

/**
  * @brief I2C_HOLD Register Bit Definition
  */
#define  I2C_HOLD_TX_HOLD_Pos                     (0)
#define  I2C_HOLD_TX_HOLD_Msk                     (0xFFFFU << I2C_HOLD_TX_HOLD_Pos) /*!<*/
#define  I2C_HOLD_RX_HOLD_Pos                     (16)
#define  I2C_HOLD_RX_HOLD_Msk                     (0xFFU << I2C_HOLD_RX_HOLD_Pos)   /*!<*/

/**
  * @brief I2C_TX_ABRT_SRC Register Bit Definition
  */
#define  I2C_TX_ABRT_SRC_7ADDR_NOACK_Pos          (0)
#define  I2C_TX_ABRT_SRC_7ADDR_NOACK_Msk          (0x01U << I2C_TX_ABRT_SRC_7ADDR_NOACK_Pos)     /*!<*/
#define  I2C_TX_ABRT_SRC_10ADDR1_NOACK_Pos        (1)
#define  I2C_TX_ABRT_SRC_10ADDR1_NOACK_Msk        (0x01U << I2C_TX_ABRT_SRC_10ADDR1_NOACK_Pos)   /*!<*/
#define  I2C_TX_ABRT_SRC_10ADDR2_NOACK_Pos        (2)
#define  I2C_TX_ABRT_SRC_10ADDR2_NOACK_Msk        (0x01U << I2C_TX_ABRT_SRC_10ADDR2_NOACK_Pos)   /*!<*/
#define  I2C_TX_ABRT_SRC_TXDATA_NOACK_Pos         (3)
#define  I2C_TX_ABRT_SRC_TXDATA_NOACK_Msk         (0x01U << I2C_TX_ABRT_SRC_TXDATA_NOACK_Pos)    /*!<*/
#define  I2C_TX_ABRT_SRC_GC_NOACK_Pos             (4)
#define  I2C_TX_ABRT_SRC_GC_NOACK_Msk             (0x01U << I2C_TX_ABRT_SRC_GC_NOACK_Pos)        /*!<*/
#define  I2C_TX_ABRT_SRC_GC_READ_Pos              (5)
#define  I2C_TX_ABRT_SRC_GC_READ_Msk              (0x01U << I2C_TX_ABRT_SRC_GC_READ_Pos)         /*!<*/
#define  I2C_TX_ABRT_SRC_SBYTE_ACKDET_Pos         (7)
#define  I2C_TX_ABRT_SRC_SBYTE_ACKDET_Msk         (0x01U << I2C_TX_ABRT_SRC_SBYTE_ACKDET_Pos)    /*!<*/
#define  I2C_TX_ABRT_SRC_SBYTE_NORSTRT_Pos        (9)
#define  I2C_TX_ABRT_SRC_SBYTE_NORSTRT_Msk        (0x01U << I2C_TX_ABRT_SRC_SBYTE_NORSTRT_Pos)   /*!<*/
#define  I2C_TX_ABRT_SRC_10B_RD_NORSTRT_Pos       (10)
#define  I2C_TX_ABRT_SRC_10B_RD_NORSTRT_Msk       (0x01U << I2C_TX_ABRT_SRC_10B_RD_NORSTRT_Pos)  /*!<*/
#define  I2C_TX_ABRT_SRC_MST_DIS_Pos              (11)
#define  I2C_TX_ABRT_SRC_MST_DIS_Msk              (0x01U << I2C_TX_ABRT_SRC_MST_DIS_Pos)         /*!<*/
#define  I2C_TX_ABRT_SRC_LOST_Pos                 (12)
#define  I2C_TX_ABRT_SRC_LOST_Msk                 (0x01U << I2C_TX_ABRT_SRC_LOST_Pos)            /*!<*/
#define  I2C_TX_ABRT_SRC_SLVFLUSH_TXFIFO_Pos      (13)
#define  I2C_TX_ABRT_SRC_SLVFLUSH_TXFIFO_Msk      (0x01U << I2C_TX_ABRT_SRC_SLVFLUSH_TXFIFO_Pos) /*!<*/
#define  I2C_TX_ABRT_SRC_SLV_ARBLOST_Pos          (14)
#define  I2C_TX_ABRT_SRC_SLV_ARBLOST_Msk          (0x01U << I2C_TX_ABRT_SRC_SLV_ARBLOST_Pos)     /*!<*/
#define  I2C_TX_ABRT_SRC_SLVRD_INTX_Pos           (15)
#define  I2C_TX_ABRT_SRC_SLVRD_INTX_Msk           (0x01U << I2C_TX_ABRT_SRC_SLVRD_INTX_Pos)      /*!<*/
#define  I2C_TX_ABRT_SRC_USER_ABRT_Pos            (16)
#define  I2C_TX_ABRT_SRC_USER_ABRT_Msk            (0x01U << I2C_TX_ABRT_SRC_USER_ABRT_Pos)       /*!<*/
#define  I2C_TX_ABRT_SRC_SDA_LOW_Pos              (17)
#define  I2C_TX_ABRT_SRC_SDA_LOW_Msk              (0x01U << I2C_TX_ABRT_SRC_SDA_LOW_Pos)         /*!<*/
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos         (23)
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Msk         (0x01FFU << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos)  /*!<*/

/**
  * @brief I2C_SLV_NACK Register Bit Definition
  */
#define  I2C_SLV_NACK_NACK_Pos                    (0)
#define  I2C_SLV_NACK_NACK_Msk                    (0x01U << I2C_SLV_NACK_NACK_Pos) /*!<*/

/**
  * @brief I2C_DMA Register Bit Definition
  */
#define  I2C_DMA_RXEN_Pos                         (0)
#define  I2C_DMA_RXEN_Msk                         (0x01U << I2C_DMA_RXEN_Pos) /*!<*/
#define  I2C_DMA_TXEN_Pos                         (1)
#define  I2C_DMA_TXEN_Msk                         (0x01U << I2C_DMA_TXEN_Pos) /*!<*/

/**
  * @brief I2C_SETUP Register Bit Definition
  */
#define  I2C_SETUP_CNT_Pos                        (0)
#define  I2C_SETUP_CNT_Msk                        (0xFFU << I2C_SETUP_CNT_Pos) /*!<*/

/**
  * @brief I2C_GCR Register Bit Definition
  */
#define  I2C_GCR_GC_Pos                           (0)
#define  I2C_GCR_GC_Msk                           (0x01U << I2C_GCR_GC_Pos) /*!<*/

/**
  * @brief I2C_EN_SR Register Bit Definition
  */
#define  I2C_EN_SR_IC_EN_Pos                      (0)
#define  I2C_EN_SR_IC_EN_Msk                      (0x01U << I2C_EN_SR_IC_EN_Pos)              /*!<*/
#define  I2C_EN_SR_SLV_DIS_WHILE_BUSY_Pos         (1)
#define  I2C_EN_SR_SLV_DIS_WHILE_BUSY_Msk         (0x01U << I2C_EN_SR_SLV_DIS_WHILE_BUSY_Pos) /*!<*/
#define  I2C_EN_SR_SLV_RX_DATA_LOST_Pos           (2)
#define  I2C_EN_SR_SLV_RX_DATA_LOST_Msk           (0x01U << I2C_EN_SR_SLV_RX_DATA_LOST_Pos)   /*!<*/

/**
  * @brief I2C_SPKLEN Register Bit Definition
  */
#define  I2C_SPKLEN_SPKLEN_Pos                    (0)
#define  I2C_SPKLEN_SPKLEN_Msk                    (0xFFU << I2C_SPKLEN_SPKLEN_Pos) /*!<*/

/**
  * @brief I2C_SCL_TMO Register Bit Definition
  */
#define  I2C_SCL_TMO_SCL_TIMEOUT_Pos              (0)
#define  I2C_SCL_TMO_SCL_TIMEOUT_Msk              (0xFFFFFFFFU << I2C_SCL_TMO_SCL_TIMEOUT_Pos) /*!<*/

/**
  * @brief I2C_SDA_TMO Register Bit Definition
  */
#define  I2C_SDA_TMO_SDA_TIMEOUT_Pos              (0)
#define  I2C_SDA_TMO_SDA_TIMEOUT_Msk              (0xFFFFFFFFU << I2C_SDA_TMO_SDA_TIMEOUT_Pos) /*!<*/

/**
  * @brief I2C_SCL_STUCK Register Bit Definition
  */
#define  I2C_SCL_STUCK_SCL_STUCK_Pos              (0)
#define  I2C_SCL_STUCK_SCL_STUCK_Msk              (0x01U << I2C_SCL_STUCK_SCL_STUCK_Pos) /*!<*/

/**
  * @brief I2C_SMB_SEXT Register Bit Definition
  */
#define  I2C_SMB_SEXT_SMB_SEXT_Pos                (0)
#define  I2C_SMB_SEXT_SMB_SEXT_Msk                (0xFFFFFFFFU << I2C_SMB_SEXT_SMB_SEXT_Pos) /*!<*/

/**
  * @brief I2C_SMB_MEXT Register Bit Definition
  */
#define  I2C_SMB_MEXT_SMB_MEXT_Pos                (0)
#define  I2C_SMB_MEXT_SMB_MEXT_Msk                (0xFFFFFFFFU << I2C_SMB_MEXT_SMB_MEXT_Pos) /*!<*/

/**
  * @brief I2C_SMB_IDLE Register Bit Definition
  */
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Pos            (0)
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Msk            (0xFFFFU << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) /*!<*/

/**
  * @brief I2C_SMB_ISR Register Bit Definition
  */
#define  I2C_SMB_ISR_R_SLV_TMO_Pos                (0)
#define  I2C_SMB_ISR_R_SLV_TMO_Msk                (0x01U << I2C_SMB_ISR_R_SLV_TMO_Pos)    /*!<*/
#define  I2C_SMB_ISR_R_MST_TMO_Pos                (1)
#define  I2C_SMB_ISR_R_MST_TMO_Msk                (0x01U << I2C_SMB_ISR_R_MST_TMO_Pos)    /*!<*/
#define  I2C_SMB_ISR_R_ARP_QUICK_Pos              (2)
#define  I2C_SMB_ISR_R_ARP_QUICK_Msk              (0x01U << I2C_SMB_ISR_R_ARP_QUICK_Pos)  /*!<*/
#define  I2C_SMB_ISR_R_ARP_NOTIFY_Pos             (3)
#define  I2C_SMB_ISR_R_ARP_NOTIFY_Msk             (0x01U << I2C_SMB_ISR_R_ARP_NOTIFY_Pos) /*!<*/
#define  I2C_SMB_ISR_R_ARP_PRE_Pos                (4)
#define  I2C_SMB_ISR_R_ARP_PRE_Msk                (0x01U << I2C_SMB_ISR_R_ARP_PRE_Pos)    /*!<*/
#define  I2C_SMB_ISR_R_ARP_RST_Pos                (5)
#define  I2C_SMB_ISR_R_ARP_RST_Msk                (0x01U << I2C_SMB_ISR_R_ARP_RST_Pos)    /*!<*/
#define  I2C_SMB_ISR_R_ARP_UDID_Pos               (6)
#define  I2C_SMB_ISR_R_ARP_UDID_Msk               (0x01U << I2C_SMB_ISR_R_ARP_UDID_Pos)   /*!<*/
#define  I2C_SMB_ISR_R_ARP_ASSGN_Pos              (7)
#define  I2C_SMB_ISR_R_ARP_ASSGN_Msk              (0x01U << I2C_SMB_ISR_R_ARP_ASSGN_Pos)  /*!<*/
#define  I2C_SMB_ISR_R_PEC_NACK_Pos               (8)
#define  I2C_SMB_ISR_R_PEC_NACK_Msk               (0x01U << I2C_SMB_ISR_R_PEC_NACK_Pos)   /*!<*/
#define  I2C_SMB_ISR_R_SMB_ALT_Pos                (10)
#define  I2C_SMB_ISR_R_SMB_ALT_Msk                (0x01U << I2C_SMB_ISR_R_SMB_ALT_Pos)    /*!<*/

/**
  * @brief I2C_SMB_IMR Register Bit Definition
  */
#define  I2C_SMB_IMR_M_SLV_TMO_Pos                (0)
#define  I2C_SMB_IMR_M_SLV_TMO_Msk                (0x01U << I2C_SMB_IMR_M_SLV_TMO_Pos)    /*!<*/
#define  I2C_SMB_IMR_M_MST_TMO_Pos                (1)
#define  I2C_SMB_IMR_M_MST_TMO_Msk                (0x01U << I2C_SMB_IMR_M_MST_TMO_Pos)    /*!<*/
#define  I2C_SMB_IMR_M_ARP_QUICK_Pos              (2)
#define  I2C_SMB_IMR_M_ARP_QUICK_Msk              (0x01U << I2C_SMB_IMR_M_ARP_QUICK_Pos)  /*!<*/
#define  I2C_SMB_IMR_M_ARP_NOTIFY_Pos             (3)
#define  I2C_SMB_IMR_M_ARP_NOTIFY_Msk             (0x01U << I2C_SMB_IMR_M_ARP_NOTIFY_Pos) /*!<*/
#define  I2C_SMB_IMR_M_ARP_PRE_Pos                (4)
#define  I2C_SMB_IMR_M_ARP_PRE_Msk                (0x01U << I2C_SMB_IMR_M_ARP_PRE_Pos)    /*!<*/
#define  I2C_SMB_IMR_M_ARP_RST_Pos                (5)
#define  I2C_SMB_IMR_M_ARP_RST_Msk                (0x01U << I2C_SMB_IMR_M_ARP_RST_Pos)    /*!<*/
#define  I2C_SMB_IMR_M_ARP_UDID_Pos               (6)
#define  I2C_SMB_IMR_M_ARP_UDID_Msk               (0x01U << I2C_SMB_IMR_M_ARP_UDID_Pos)   /*!<*/
#define  I2C_SMB_IMR_M_ARP_ASSGN_Pos              (7)
#define  I2C_SMB_IMR_M_ARP_ASSGN_Msk              (0x01U << I2C_SMB_IMR_M_ARP_ASSGN_Pos)  /*!<*/
#define  I2C_SMB_IMR_M_PEC_NACK_Pos               (8)
#define  I2C_SMB_IMR_M_PEC_NACK_Msk               (0x01U << I2C_SMB_IMR_M_PEC_NACK_Pos)   /*!<*/
#define  I2C_SMB_IMR_M_SMB_ALT_Pos                (10)
#define  I2C_SMB_IMR_M_SMB_ALT_Msk                (0x01U << I2C_SMB_IMR_M_SMB_ALT_Pos)    /*!<*/

/**
  * @brief I2C_SMB_RAWISR Register Bit Definition
  */
#define  I2C_SMB_RAWISR_SLV_TMO_Pos               (0)
#define  I2C_SMB_RAWISR_SLV_TMO_Msk               (0x01U << I2C_SMB_RAWISR_SLV_TMO_Pos)    /*!<*/
#define  I2C_SMB_RAWISR_MST_TMO_Pos               (1)
#define  I2C_SMB_RAWISR_MST_TMO_Msk               (0x01U << I2C_SMB_RAWISR_MST_TMO_Pos)    /*!<*/
#define  I2C_SMB_RAWISR_ARP_QUICK_Pos             (2)
#define  I2C_SMB_RAWISR_ARP_QUICK_Msk             (0x01U << I2C_SMB_RAWISR_ARP_QUICK_Pos)  /*!<*/
#define  I2C_SMB_RAWISR_ARP_NOTIFY_Pos            (3)
#define  I2C_SMB_RAWISR_ARP_NOTIFY_Msk            (0x01U << I2C_SMB_RAWISR_ARP_NOTIFY_Pos) /*!<*/
#define  I2C_SMB_RAWISR_ARP_PRE_Pos               (4)
#define  I2C_SMB_RAWISR_ARP_PRE_Msk               (0x01U << I2C_SMB_RAWISR_ARP_PRE_Pos)    /*!<*/
#define  I2C_SMB_RAWISR_ARP_RST_Pos               (5)
#define  I2C_SMB_RAWISR_ARP_RST_Msk               (0x01U << I2C_SMB_RAWISR_ARP_RST_Pos)    /*!<*/
#define  I2C_SMB_RAWISR_ARP_UDID_Pos              (6)
#define  I2C_SMB_RAWISR_ARP_UDID_Msk              (0x01U << I2C_SMB_RAWISR_ARP_UDID_Pos)   /*!<*/
#define  I2C_SMB_RAWISR_ARP_ASSGN_Pos             (7)
#define  I2C_SMB_RAWISR_ARP_ASSGN_Msk             (0x01U << I2C_SMB_RAWISR_ARP_ASSGN_Pos)  /*!<*/
#define  I2C_SMB_RAWISR_PEC_NACK_Pos              (8)
#define  I2C_SMB_RAWISR_PEC_NACK_Msk              (0x01U << I2C_SMB_RAWISR_PEC_NACK_Pos)   /*!<*/
#define  I2C_SMB_RAWISR_SMB_ALT_Pos               (10)
#define  I2C_SMB_RAWISR_SMB_ALT_Msk               (0x01U << I2C_SMB_RAWISR_SMB_ALT_Pos)    /*!<*/

/**
  * @brief I2C_SMB_ICR Register Bit Definition
  */
#define  I2C_SMB_ICR_CLR_SLV_TMO_Pos              (0)
#define  I2C_SMB_ICR_CLR_SLV_TMO_Msk              (0x01U << I2C_SMB_ICR_CLR_SLV_TMO_Pos)    /*!<*/
#define  I2C_SMB_ICR_CLR_MST_TMO_Pos              (1)
#define  I2C_SMB_ICR_CLR_MST_TMO_Msk              (0x01U << I2C_SMB_ICR_CLR_MST_TMO_Pos)    /*!<*/
#define  I2C_SMB_ICR_CLR_ARP_QUICK_Pos            (2)
#define  I2C_SMB_ICR_CLR_ARP_QUICK_Msk            (0x01U << I2C_SMB_ICR_CLR_ARP_QUICK_Pos)  /*!<*/
#define  I2C_SMB_ICR_CLR_ARP_NOTIFY_Pos           (3)
#define  I2C_SMB_ICR_CLR_ARP_NOTIFY_Msk           (0x01U << I2C_SMB_ICR_CLR_ARP_NOTIFY_Pos) /*!<*/
#define  I2C_SMB_ICR_CLR_ARP_PRE_Pos              (4)
#define  I2C_SMB_ICR_CLR_ARP_PRE_Msk              (0x01U << I2C_SMB_ICR_CLR_ARP_PRE_Pos)    /*!<*/
#define  I2C_SMB_ICR_CLR_ARP_RST_Pos              (5)
#define  I2C_SMB_ICR_CLR_ARP_RST_Msk              (0x01U << I2C_SMB_ICR_CLR_ARP_RST_Pos)    /*!<*/
#define  I2C_SMB_ICR_CLR_ARP_UDID_Pos             (6)
#define  I2C_SMB_ICR_CLR_ARP_UDID_Msk             (0x01U << I2C_SMB_ICR_CLR_ARP_UDID_Pos)   /*!<*/
#define  I2C_SMB_ICR_CLR_ARP_ASSGN_Pos            (7)
#define  I2C_SMB_ICR_CLR_ARP_ASSGN_Msk            (0x01U << I2C_SMB_ICR_CLR_ARP_ASSGN_Pos)  /*!<*/
#define  I2C_SMB_ICR_CLR_PEC_NACK_Pos             (8)
#define  I2C_SMB_ICR_CLR_PEC_NACK_Msk             (0x01U << I2C_SMB_ICR_CLR_PEC_NACK_Pos)   /*!<*/
#define  I2C_SMB_ICR_CLR_SMB_ALT_Pos              (10)
#define  I2C_SMB_ICR_CLR_SMB_ALT_Msk              (0x01U << I2C_SMB_ICR_CLR_SMB_ALT_Pos)    /*!<*/

/**
  * @brief I2C_OPT_SAR Register Bit Definition
  */
#define  I2C_OPT_SAR_ADDR_Pos                     (0)
#define  I2C_OPT_SAR_ADDR_Msk                     (0x7FU << I2C_OPT_SAR_ADDR_Pos) /*!<*/

/**
  * @brief I2C_SMB_UDID_LSB Register Bit Definition
  */
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos        (0)
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Msk        (0xFFFFFFFFU << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) /*!<*/

/**
  * @brief I2C_SMB_UDID_MSB0 Register Bit Definition
  */
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos      (0)
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Msk      (0xFFFFFFFFU << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) /*!<*/

/**
  * @brief I2C_SMB_UDID_MSB1 Register Bit Definition
  */
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos      (0)
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Msk      (0xFFFFFFFFU << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) /*!<*/

/**
  * @brief I2C_SMB_UDID_MSB2 Register Bit Definition
  */
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos      (0)
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Msk      (0xFFFFFFFFU << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) /*!<*/

/**
  * @brief I2C_SLVMASK Register Bit Definition
  */
#define  I2C_SLVMASK_MASK_Pos                     (0)
#define  I2C_SLVMASK_MASK_Msk                     (0x03FFU << I2C_SLVMASK_MASK_Pos) /*!<*/

/**
  * @brief I2C_SLVRCVADDR Register Bit Definition
  */
#define  I2C_SLVRCVADDR_ADDR_Pos                  (0)
#define  I2C_SLVRCVADDR_ADDR_Msk                  (0x03FFU << I2C_SLVRCVADDR_ADDR_Pos) /*!<*/

#endif

