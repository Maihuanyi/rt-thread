/***********************************************************************************************************************
    @file     reg_qspi.h
    @author   VV TEAM
    @brief    This flie contains all the QSPI's register and its field definition.
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

#ifndef __REG_QSPI_H
#define __REG_QSPI_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief QSPI Base Address Definition
  */
#define  QSPI_BASE                                 0xA0001000 /*!<Base Address: 0xA0001000*/

/**
  * @brief QSPI Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                  /*!<QSPI Control register                          offset: 0x00*/
    __IO uint32_t SR;                  /*!<QSPI Status register                           offset: 0x04*/
    __IO uint32_t DMCR;                /*!<QSPI Direct mode control register              offset: 0x08*/
    __IO uint32_t IMCR;                /*!<QSPI Indirect mode control register            offset: 0x0C*/
    __IO uint32_t DABR;                /*!<QSPI Direct mode alternate bytes register      offset: 0x10*/
    __IO uint32_t IABR;                /*!<QSPI Indirect mode alternate bytes register    offset: 0x14*/
    __IO uint32_t IADR;                /*!<QSPI Indirect mode address register            offset: 0x18*/
    __IO uint32_t IDFR;                /*!<QSPI Indirect mode data FIFO register          offset: 0x1C*/
    __IO uint32_t IDLR;                /*!<QSPI Indirect mode data length register        offset: 0x20*/
    __IO uint32_t IWCR;                /*!<QSPI Indirect mode wait count register         offset: 0x24*/
    __IO uint32_t IDER;                /*!<QSPI Interrupt DMA enable register             offset: 0x28*/
} QSPI_TypeDef;

/**
  * @brief QSPI type pointer Definition
  */
#define QSPI                                      ((QSPI_TypeDef *)QSPI_BASE)

/**
  * @brief QSPI_CR Register Bit Definition
  */
#define  QSPI_CR_OPMODE_Pos                       (0)
#define  QSPI_CR_OPMODE_Msk                       (0x03U << QSPI_CR_OPMODE_Pos)  /*!<*/
#define  QSPI_CR_SCKMODE_Pos                      (4)
#define  QSPI_CR_SCKMODE_Msk                      (0x01U << QSPI_CR_SCKMODE_Pos) /*!<*/
#define  QSPI_CR_XIPMODE_Pos                      (5)
#define  QSPI_CR_XIPMODE_Msk                      (0x01U << QSPI_CR_XIPMODE_Pos) /*!<*/
#define  QSPI_CR_CSRHT_Pos                        (16)
#define  QSPI_CR_CSRHT_Msk                        (0x07U << QSPI_CR_CSRHT_Pos)   /*!<*/
#define  QSPI_CR_SCKDIV_Pos                       (24)
#define  QSPI_CR_SCKDIV_Msk                       (0x3FU << QSPI_CR_SCKDIV_Pos)  /*!<*/

/**
  * @brief QSPI_SR Register Bit Definition
  */
#define  QSPI_SR_CUROP_Pos                        (0)
#define  QSPI_SR_CUROP_Msk                        (0x03U << QSPI_SR_CUROP_Pos)  /*!<*/
#define  QSPI_SR_OPCRCF_Pos                       (2)
#define  QSPI_SR_OPCRCF_Msk                       (0x01U << QSPI_SR_OPCRCF_Pos) /*!<*/
#define  QSPI_SR_TCF_Pos                          (4)
#define  QSPI_SR_TCF_Msk                          (0x01U << QSPI_SR_TCF_Pos)    /*!<*/
#define  QSPI_SR_BUSY_Pos                         (5)
#define  QSPI_SR_BUSY_Msk                         (0x01U << QSPI_SR_BUSY_Pos)   /*!<*/
#define  QSPI_SR_XIPST_Pos                        (6)
#define  QSPI_SR_XIPST_Msk                        (0x01U << QSPI_SR_XIPST_Pos)  /*!<*/
#define  QSPI_SR_EMPTY_Pos                        (8)
#define  QSPI_SR_EMPTY_Msk                        (0x01U << QSPI_SR_EMPTY_Pos)  /*!<*/
#define  QSPI_SR_FULL_Pos                         (9)
#define  QSPI_SR_FULL_Msk                         (0x01U << QSPI_SR_FULL_Pos)   /*!<*/
#define  QSPI_SR_LEVEL_Pos                        (12)
#define  QSPI_SR_LEVEL_Msk                        (0x0FU << QSPI_SR_LEVEL_Pos)  /*!<*/
#define  QSPI_SR_DEPTH_Pos                        (24)
#define  QSPI_SR_DEPTH_Msk                        (0x0FU << QSPI_SR_DEPTH_Pos)  /*!<*/

/**
  * @brief QSPI_DMCR Register Bit Definition
  */
#define  QSPI_DMCR_INST_Pos                       (0)
#define  QSPI_DMCR_INST_Msk                       (0xFFU << QSPI_DMCR_INST_Pos)   /*!<*/
#define  QSPI_DMCR_IMODE_Pos                      (8)
#define  QSPI_DMCR_IMODE_Msk                      (0x03U << QSPI_DMCR_IMODE_Pos)  /*!<*/
#define  QSPI_DMCR_ADMODE_Pos                     (10)
#define  QSPI_DMCR_ADMODE_Msk                     (0x03U << QSPI_DMCR_ADMODE_Pos) /*!<*/
#define  QSPI_DMCR_ADSIZE_Pos                     (12)
#define  QSPI_DMCR_ADSIZE_Msk                     (0x03U << QSPI_DMCR_ADSIZE_Pos) /*!<*/
#define  QSPI_DMCR_ABMODE_Pos                     (14)
#define  QSPI_DMCR_ABMODE_Msk                     (0x03U << QSPI_DMCR_ABMODE_Pos) /*!<*/
#define  QSPI_DMCR_ABSIZE_Pos                     (16)
#define  QSPI_DMCR_ABSIZE_Msk                     (0x03U << QSPI_DMCR_ABSIZE_Pos) /*!<*/
#define  QSPI_DMCR_DMODE_Pos                      (18)
#define  QSPI_DMCR_DMODE_Msk                      (0x03U << QSPI_DMCR_DMODE_Pos)  /*!<*/
#define  QSPI_DMCR_DSIZE_Pos                      (20)
#define  QSPI_DMCR_DSIZE_Msk                      (0x03U << QSPI_DMCR_DSIZE_Pos)  /*!<*/
#define  QSPI_DMCR_RXDLY_Pos                      (22)
#define  QSPI_DMCR_RXDLY_Msk                      (0x03U << QSPI_DMCR_RXDLY_Pos)  /*!<*/
#define  QSPI_DMCR_NUMDC_Pos                      (24)
#define  QSPI_DMCR_NUMDC_Msk                      (0x1FU << QSPI_DMCR_NUMDC_Pos)  /*!<*/

/**
  * @brief QSPI_IMCR Register Bit Definition
  */
#define  QSPI_IMCR_INST_Pos                       (0)
#define  QSPI_IMCR_INST_Msk                       (0xFFU << QSPI_IMCR_INST_Pos)   /*!<*/
#define  QSPI_IMCR_IMODE_Pos                      (8)
#define  QSPI_IMCR_IMODE_Msk                      (0x03U << QSPI_IMCR_IMODE_Pos)  /*!<*/
#define  QSPI_IMCR_ADMODE_Pos                     (10)
#define  QSPI_IMCR_ADMODE_Msk                     (0x03U << QSPI_IMCR_ADMODE_Pos) /*!<*/
#define  QSPI_IMCR_ADSIZE_Pos                     (12)
#define  QSPI_IMCR_ADSIZE_Msk                     (0x03U << QSPI_IMCR_ADSIZE_Pos) /*!<*/
#define  QSPI_IMCR_ABMODE_Pos                     (14)
#define  QSPI_IMCR_ABMODE_Msk                     (0x03U << QSPI_IMCR_ABMODE_Pos) /*!<*/
#define  QSPI_IMCR_ABSIZE_Pos                     (16)
#define  QSPI_IMCR_ABSIZE_Msk                     (0x03U << QSPI_IMCR_ABSIZE_Pos) /*!<*/
#define  QSPI_IMCR_DMODE_Pos                      (18)
#define  QSPI_IMCR_DMODE_Msk                      (0x03U << QSPI_IMCR_DMODE_Pos)  /*!<*/
#define  QSPI_IMCR_DSIZE_Pos                      (20)
#define  QSPI_IMCR_DSIZE_Msk                      (0x03U << QSPI_IMCR_DSIZE_Pos)  /*!<*/
#define  QSPI_IMCR_RXDLY_Pos                      (22)
#define  QSPI_IMCR_RXDLY_Msk                      (0x03U << QSPI_IMCR_RXDLY_Pos)  /*!<*/
#define  QSPI_IMCR_NUMDC_Pos                      (24)
#define  QSPI_IMCR_NUMDC_Msk                      (0x1FU << QSPI_IMCR_NUMDC_Pos)  /*!<*/
#define  QSPI_IMCR_XIPIM_Pos                      (29)
#define  QSPI_IMCR_XIPIM_Msk                      (0x01U << QSPI_IMCR_XIPIM_Pos)  /*!<*/
#define  QSPI_IMCR_IDMODE_Pos                     (30)
#define  QSPI_IMCR_IDMODE_Msk                     (0x01U << QSPI_IMCR_IDMODE_Pos) /*!<*/

/**
  * @brief QSPI_DABR Register Bit Definition
  */
#define  QSPI_DABR_DALT_Pos                       (0)
#define  QSPI_DABR_DALT_Msk                       (0xFFFFFFFFU << QSPI_DABR_DALT_Pos) /*!<*/

/**
  * @brief QSPI_IABR Register Bit Definition
  */
#define  QSPI_IABR_IALT_Pos                       (0)
#define  QSPI_IABR_IALT_Msk                       (0xFFFFFFFFU << QSPI_IABR_IALT_Pos) /*!<*/

/**
  * @brief QSPI_IADR Register Bit Definition
  */
#define  QSPI_IADR_IADDR_Pos                      (0)
#define  QSPI_IADR_IADDR_Msk                      (0xFFFFFFFFU << QSPI_IADR_IADDR_Pos) /*!<*/

/**
  * @brief QSPI_IDFR Register Bit Definition
  */
#define  QSPI_IDFR_IDATA_Pos                      (0)
#define  QSPI_IDFR_IDATA_Msk                      (0xFFFFFFFFU << QSPI_IDFR_IDATA_Pos) /*!<*/

/**
  * @brief QSPI_IDLR Register Bit Definition
  */
#define  QSPI_IDLR_IDLEN_Pos                      (0)
#define  QSPI_IDLR_IDLEN_Msk                      (0x000FFFFFU << QSPI_IDLR_IDLEN_Pos) /*!<*/

/**
  * @brief QSPI_IWCR Register Bit Definition
  */
#define  QSPI_IWCR_IWCNT_Pos                      (0)
#define  QSPI_IWCR_IWCNT_Msk                      (0x3FFFFFFFU << QSPI_IWCR_IWCNT_Pos) /*!<*/

/**
  * @brief QSPI_IDER Register Bit Definition
  */
#define  QSPI_IDER_TCFINTEN_Pos                   (0)
#define  QSPI_IDER_TCFINTEN_Msk                   (0x01U << QSPI_IDER_TCFINTEN_Pos)   /*!<*/
#define  QSPI_IDER_EMPTYINTEN_Pos                 (6)
#define  QSPI_IDER_EMPTYINTEN_Msk                 (0x01U << QSPI_IDER_EMPTYINTEN_Pos) /*!<*/
#define  QSPI_IDER_FULLINTEN_Pos                  (7)
#define  QSPI_IDER_FULLINTEN_Msk                  (0x01U << QSPI_IDER_FULLINTEN_Pos)  /*!<*/
#define  QSPI_IDER_TCFDMAEN_Pos                   (8)
#define  QSPI_IDER_TCFDMAEN_Msk                   (0x01U << QSPI_IDER_TCFDMAEN_Pos)   /*!<*/
#define  QSPI_IDER_EMPTYDMAEN_Pos                 (14)
#define  QSPI_IDER_EMPTYDMAEN_Msk                 (0x01U << QSPI_IDER_EMPTYDMAEN_Pos) /*!<*/
#define  QSPI_IDER_FULLDMAEN_Pos                  (15)
#define  QSPI_IDER_FULLDMAEN_Msk                  (0x01U << QSPI_IDER_FULLDMAEN_Pos)  /*!<*/

#endif

