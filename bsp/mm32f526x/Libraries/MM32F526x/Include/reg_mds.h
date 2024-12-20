/***********************************************************************************************************************
    @file     reg_mds.h
    @author   VV TEAM
    @brief    This flie contains all the MDS's register and its field definition.
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

#ifndef __REG_MDS_H
#define __REG_MDS_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief MDS Base Address Definition
  */
#define  MDS_BASE                                  0x4001FC00 /*!<Base Address: 0x4001FC00*/

/**
  * @brief MDS Register Structure Definition
  */
typedef struct
{
    __IO uint32_t TRIGCR[8];           /*!<MDS Trigger channel x control register         offset: 0x00*/
    __IO uint32_t RESERVED0x020[24];   /*!<                                               offset: 0x20~0x7c*/
    __IO uint32_t TRIG_CLUSEL[4];      /*!<MDS Trigger channel CLUx input select register offset: 0x80*/
    __IO uint32_t RESERVED0x090[12];   /*!<                                               offset: 0x90~0xbc*/
    __IO uint32_t TRIG_CLUCFG[4];      /*!<MDS Trigger channel CLUx configuration register offset: 0xC0*/
    __IO uint32_t RESERVED0x0D0[11];   /*!<                                               offset: 0xd0~0xf8*/
    __IO uint32_t SWTRIG;              /*!<MDS Software trigger control register          offset: 0xFC*/
    __IO uint32_t CONNCR[7];           /*!<MDS Connection channel x control register      offset: 0x100*/
    __IO uint32_t RESERVED0x11C[25];   /*!<                                               offset: 0x11c~0x17c*/
    __IO uint32_t CONN_CLUSEL[4];      /*!<MDS Connection channel CLUx input select register offset: 0x180*/
    __IO uint32_t RESERVED0x190[12];   /*!<                                               offset: 0x190~0x1bc*/
    __IO uint32_t CONN_CLUCFG[4];      /*!<MDS Connection channel CLUx configuration register offset: 0x1C0*/
} MDS_TypeDef;

/**
  * @brief MDS type pointer Definition
  */
#define MDS                                       ((MDS_TypeDef *)MDS_BASE)

/**
  * @brief MDS_TRIGCR Register Bit Definition
  */
#define  MDS_TRIGCR_TRGSEL_Pos                    (0)
#define  MDS_TRIGCR_TRGSEL_Msk                    (0x3FU << MDS_TRIGCR_TRGSEL_Pos)  /*!<*/
#define  MDS_TRIGCR_CLUEN_Pos                     (16)
#define  MDS_TRIGCR_CLUEN_Msk                     (0x01U << MDS_TRIGCR_CLUEN_Pos)   /*!<*/
#define  MDS_TRIGCR_CLUSEL_Pos                    (17)
#define  MDS_TRIGCR_CLUSEL_Msk                    (0x03U << MDS_TRIGCR_CLUSEL_Pos)  /*!<*/
#define  MDS_TRIGCR_EDGESEL_Pos                   (24)
#define  MDS_TRIGCR_EDGESEL_Msk                   (0x03U << MDS_TRIGCR_EDGESEL_Pos) /*!<*/

/**
  * @brief MDS_TRIG_CLUSEL Register Bit Definition
  */
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos           (0)
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Msk           (0x3FU << MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos) /*!<*/
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos           (8)
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Msk           (0x3FU << MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos) /*!<*/
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos           (16)
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Msk           (0x3FU << MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos) /*!<*/
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos           (24)
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Msk           (0x3FU << MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos) /*!<*/

/**
  * @brief MDS_TRIG_CLUCFG Register Bit Definition
  */
#define  MDS_TRIG_CLUCFG_CLUIN0_ED_Pos            (0)
#define  MDS_TRIG_CLUCFG_CLUIN0_ED_Msk            (0x03U << MDS_TRIG_CLUCFG_CLUIN0_ED_Pos) /*!<*/
#define  MDS_TRIG_CLUCFG_CLUIN1_ED_Pos            (8)
#define  MDS_TRIG_CLUCFG_CLUIN1_ED_Msk            (0x03U << MDS_TRIG_CLUCFG_CLUIN1_ED_Pos) /*!<*/
#define  MDS_TRIG_CLUCFG_CLUIN2_ED_Pos            (16)
#define  MDS_TRIG_CLUCFG_CLUIN2_ED_Msk            (0x03U << MDS_TRIG_CLUCFG_CLUIN2_ED_Pos) /*!<*/
#define  MDS_TRIG_CLUCFG_CLUIN3_ED_Pos            (24)
#define  MDS_TRIG_CLUCFG_CLUIN3_ED_Msk            (0x03U << MDS_TRIG_CLUCFG_CLUIN3_ED_Pos) /*!<*/

/**
  * @brief MDS_SWTRIG Register Bit Definition
  */
#define  MDS_SWTRIG_SW_TRIG_Pos                   (0)
#define  MDS_SWTRIG_SW_TRIG_Msk                   (0x01U << MDS_SWTRIG_SW_TRIG_Pos) /*!<*/

/**
  * @brief MDS_CONNCR Register Bit Definition
  */
#define  MDS_CONNCR_TRGSEL_Pos                    (0)
#define  MDS_CONNCR_TRGSEL_Msk                    (0x3FU << MDS_CONNCR_TRGSEL_Pos) /*!<*/
#define  MDS_CONNCR_CLUEN_Pos                     (16)
#define  MDS_CONNCR_CLUEN_Msk                     (0x01U << MDS_CONNCR_CLUEN_Pos)  /*!<*/
#define  MDS_CONNCR_CLUSEL_Pos                    (17)
#define  MDS_CONNCR_CLUSEL_Msk                    (0x03U << MDS_CONNCR_CLUSEL_Pos) /*!<*/

/**
  * @brief MDS_CONN_CLUSEL Register Bit Definition
  */
#define  MDS_CONN_CLUSEL_CLUIN0_SEL_Pos           (0)
#define  MDS_CONN_CLUSEL_CLUIN0_SEL_Msk           (0x3FU << MDS_CONN_CLUSEL_CLUIN0_SEL_Pos) /*!<*/
#define  MDS_CONN_CLUSEL_CLUIN1_SEL_Pos           (8)
#define  MDS_CONN_CLUSEL_CLUIN1_SEL_Msk           (0x3FU << MDS_CONN_CLUSEL_CLUIN1_SEL_Pos) /*!<*/
#define  MDS_CONN_CLUSEL_CLUIN2_SEL_Pos           (16)
#define  MDS_CONN_CLUSEL_CLUIN2_SEL_Msk           (0x3FU << MDS_CONN_CLUSEL_CLUIN2_SEL_Pos) /*!<*/
#define  MDS_CONN_CLUSEL_CLUIN3_SEL_Pos           (24)
#define  MDS_CONN_CLUSEL_CLUIN3_SEL_Msk           (0x3FU << MDS_CONN_CLUSEL_CLUIN3_SEL_Pos) /*!<*/

/**
  * @brief MDS_CONN_CLUCFG Register Bit Definition
  */
#define  MDS_CONN_CLUCFG_CLMODE_Pos               (0)
#define  MDS_CONN_CLUCFG_CLMODE_Msk               (0x03U << MDS_CONN_CLUCFG_CLMODE_Pos) /*!<*/
#define  MDS_CONN_CLUCFG_INV0_Pos                 (8)
#define  MDS_CONN_CLUCFG_INV0_Msk                 (0x01U << MDS_CONN_CLUCFG_INV0_Pos)   /*!<*/
#define  MDS_CONN_CLUCFG_INV1_Pos                 (9)
#define  MDS_CONN_CLUCFG_INV1_Msk                 (0x01U << MDS_CONN_CLUCFG_INV1_Pos)   /*!<*/
#define  MDS_CONN_CLUCFG_INV2_Pos                 (10)
#define  MDS_CONN_CLUCFG_INV2_Msk                 (0x01U << MDS_CONN_CLUCFG_INV2_Pos)   /*!<*/
#define  MDS_CONN_CLUCFG_INV3_Pos                 (11)
#define  MDS_CONN_CLUCFG_INV3_Msk                 (0x01U << MDS_CONN_CLUCFG_INV3_Pos)   /*!<*/

#endif

