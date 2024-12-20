/***********************************************************************************************************************
    @file     reg_dac.h
    @author   VV TEAM
    @brief    This flie contains all the DAC's register and its field definition.
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

#ifndef __REG_DAC_H
#define __REG_DAC_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief DAC Base Address Definition
  */
#define  DAC_BASE                                  0x40007400 /*!<Base Address: 0x40007400*/

/**
  * @brief DAC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                  /*!<DAC DAC control register                       offset: 0x00*/
    __IO uint32_t SWTRIGR;             /*!<DAC DAC software trigger register              offset: 0x04*/
    __IO uint32_t DHR12R1;             /*!<DAC DAC channel 1 12-bit right-aligned data holding register offset: 0x08*/
    __IO uint32_t DHR12L1;             /*!<DAC DAC channel 1 12-bit left-aligned data holding register offset: 0x0C*/
    __IO uint32_t DHR8R1;              /*!<DAC DAC channel 1 8-bit right-aligned data holding register offset: 0x10*/
    __IO uint32_t DHR12R2;             /*!<DAC DAC channel 2 12-bit right-aligned data holding register offset: 0x14*/
    __IO uint32_t DHR12L2;             /*!<DAC DAC channel 2 12-bit left-aligned data holding register offset: 0x18*/
    __IO uint32_t DHR8R2;              /*!<DAC DAC channel 2 8-bit right-aligned data holding register offset: 0x1C*/
    __IO uint32_t DHR12RD;             /*!<DAC Dual DAC 12-bit right-aligned data holding register offset: 0x20*/
    __IO uint32_t DHR12LD;             /*!<DAC Dual DAC 12-bit left-aligned data holding register offset: 0x24*/
    __IO uint32_t DHR8RD;              /*!<DAC Dual DAC 8-bit right-aligned data holding register offset: 0x28*/
    __IO uint32_t DOR1;                /*!<DAC DAC channel 1 data output register         offset: 0x2C*/
    __IO uint32_t DOR2;                /*!<DAC DAC channel 2 data output register         offset: 0x30*/
} DAC_TypeDef;

/**
  * @brief DAC type pointer Definition
  */
#define DAC                                       ((DAC_TypeDef *)DAC_BASE)

/**
  * @brief DAC_CR Register Bit Definition
  */
#define  DAC_CR_EN1_Pos                           (0)
#define  DAC_CR_EN1_Msk                           (0x01U << DAC_CR_EN1_Pos)     /*!<*/
#define  DAC_CR_BOFF1_Pos                         (1)
#define  DAC_CR_BOFF1_Msk                         (0x01U << DAC_CR_BOFF1_Pos)   /*!<*/
#define  DAC_CR_TEN1_Pos                          (2)
#define  DAC_CR_TEN1_Msk                          (0x01U << DAC_CR_TEN1_Pos)    /*!<*/
#define  DAC_CR_WAVE1_Pos                         (6)
#define  DAC_CR_WAVE1_Msk                         (0x03U << DAC_CR_WAVE1_Pos)   /*!<*/
#define  DAC_CR_MAMP1_Pos                         (8)
#define  DAC_CR_MAMP1_Msk                         (0x0FU << DAC_CR_MAMP1_Pos)   /*!<*/
#define  DAC_CR_DMA_EN1_Pos                       (12)
#define  DAC_CR_DMA_EN1_Msk                       (0x01U << DAC_CR_DMA_EN1_Pos) /*!<*/
#define  DAC_CR_OE_EN1_Pos                        (13)
#define  DAC_CR_OE_EN1_Msk                        (0x01U << DAC_CR_OE_EN1_Pos)  /*!<*/
#define  DAC_CR_EN2_Pos                           (16)
#define  DAC_CR_EN2_Msk                           (0x01U << DAC_CR_EN2_Pos)     /*!<*/
#define  DAC_CR_BOFF2_Pos                         (17)
#define  DAC_CR_BOFF2_Msk                         (0x01U << DAC_CR_BOFF2_Pos)   /*!<*/
#define  DAC_CR_TEN2_Pos                          (18)
#define  DAC_CR_TEN2_Msk                          (0x01U << DAC_CR_TEN2_Pos)    /*!<*/
#define  DAC_CR_WAVE2_Pos                         (22)
#define  DAC_CR_WAVE2_Msk                         (0x03U << DAC_CR_WAVE2_Pos)   /*!<*/
#define  DAC_CR_MAMP2_Pos                         (24)
#define  DAC_CR_MAMP2_Msk                         (0x0FU << DAC_CR_MAMP2_Pos)   /*!<*/
#define  DAC_CR_DMA_EN2_Pos                       (28)
#define  DAC_CR_DMA_EN2_Msk                       (0x01U << DAC_CR_DMA_EN2_Pos) /*!<*/
#define  DAC_CR_OE_EN2_Pos                        (29)
#define  DAC_CR_OE_EN2_Msk                        (0x01U << DAC_CR_OE_EN2_Pos)  /*!<*/

/**
  * @brief DAC_SWTRIGR Register Bit Definition
  */
#define  DAC_SWTRIGR_SW_TRIG1_Pos                 (0)
#define  DAC_SWTRIGR_SW_TRIG1_Msk                 (0x01U << DAC_SWTRIGR_SW_TRIG1_Pos) /*!<*/
#define  DAC_SWTRIGR_SW_TRIG2_Pos                 (1)
#define  DAC_SWTRIGR_SW_TRIG2_Msk                 (0x01U << DAC_SWTRIGR_SW_TRIG2_Pos) /*!<*/

/**
  * @brief DAC_DHR12R1 Register Bit Definition
  */
#define  DAC_DHR12R1_DACC1DHR_Pos                 (0)
#define  DAC_DHR12R1_DACC1DHR_Msk                 (0x0FFFU << DAC_DHR12R1_DACC1DHR_Pos) /*!<*/

/**
  * @brief DAC_DHR12L1 Register Bit Definition
  */
#define  DAC_DHR12L1_DACC1DHR_Pos                 (4)
#define  DAC_DHR12L1_DACC1DHR_Msk                 (0x0FFFU << DAC_DHR12L1_DACC1DHR_Pos) /*!<*/

/**
  * @brief DAC_DHR8R1 Register Bit Definition
  */
#define  DAC_DHR8R1_DACC1DHR_Pos                  (0)
#define  DAC_DHR8R1_DACC1DHR_Msk                  (0xFFU << DAC_DHR8R1_DACC1DHR_Pos) /*!<*/

/**
  * @brief DAC_DHR12R2 Register Bit Definition
  */
#define  DAC_DHR12R2_DACC2DHR_Pos                 (0)
#define  DAC_DHR12R2_DACC2DHR_Msk                 (0x0FFFU << DAC_DHR12R2_DACC2DHR_Pos) /*!<*/

/**
  * @brief DAC_DHR12L2 Register Bit Definition
  */
#define  DAC_DHR12L2_DACC2DHR_Pos                 (4)
#define  DAC_DHR12L2_DACC2DHR_Msk                 (0x0FFFU << DAC_DHR12L2_DACC2DHR_Pos) /*!<*/

/**
  * @brief DAC_DHR8R2 Register Bit Definition
  */
#define  DAC_DHR8R2_DACC2DHR_Pos                  (0)
#define  DAC_DHR8R2_DACC2DHR_Msk                  (0xFFU << DAC_DHR8R2_DACC2DHR_Pos) /*!<*/

/**
  * @brief DAC_DHR12RD Register Bit Definition
  */
#define  DAC_DHR12RD_DACC1DHR_Pos                 (0)
#define  DAC_DHR12RD_DACC1DHR_Msk                 (0x0FFFU << DAC_DHR12RD_DACC1DHR_Pos) /*!<*/
#define  DAC_DHR12RD_DACC2DHR_Pos                 (16)
#define  DAC_DHR12RD_DACC2DHR_Msk                 (0x0FFFU << DAC_DHR12RD_DACC2DHR_Pos) /*!<*/

/**
  * @brief DAC_DHR12LD Register Bit Definition
  */
#define  DAC_DHR12LD_DACC1DHR_Pos                 (4)
#define  DAC_DHR12LD_DACC1DHR_Msk                 (0x0FFFU << DAC_DHR12LD_DACC1DHR_Pos) /*!<*/
#define  DAC_DHR12LD_DACC2DHR_Pos                 (20)
#define  DAC_DHR12LD_DACC2DHR_Msk                 (0x0FFFU << DAC_DHR12LD_DACC2DHR_Pos) /*!<*/

/**
  * @brief DAC_DHR8RD Register Bit Definition
  */
#define  DAC_DHR8RD_DACC1DHR_Pos                  (0)
#define  DAC_DHR8RD_DACC1DHR_Msk                  (0xFFU << DAC_DHR8RD_DACC1DHR_Pos) /*!<*/
#define  DAC_DHR8RD_DACC2DHR_Pos                  (8)
#define  DAC_DHR8RD_DACC2DHR_Msk                  (0xFFU << DAC_DHR8RD_DACC2DHR_Pos) /*!<*/

/**
  * @brief DAC_DOR1 Register Bit Definition
  */
#define  DAC_DOR1_DACC1DOR_Pos                    (0)
#define  DAC_DOR1_DACC1DOR_Msk                    (0x0FFFU << DAC_DOR1_DACC1DOR_Pos) /*!<*/

/**
  * @brief DAC_DOR2 Register Bit Definition
  */
#define  DAC_DOR2_DACC2DOR_Pos                    (0)
#define  DAC_DOR2_DACC2DOR_Msk                    (0x0FFFU << DAC_DOR2_DACC2DOR_Pos) /*!<*/

#endif

