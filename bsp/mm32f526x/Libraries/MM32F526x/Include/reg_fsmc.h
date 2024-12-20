/***********************************************************************************************************************
    @file     reg_fsmc.h
    @author   VV TEAM
    @brief    This flie contains all the FSMC's register and its field definition.
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

#ifndef __REG_FSMC_H
#define __REG_FSMC_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief FSMC Base Address Definition
  */
#define  FSMC_BASE                                 0xA0000000 /*!<Base Address: 0xA0000000*/

/**
  * @brief FSMC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t RESERVED0x000[21];   /*!<                                               offset: 0x0~0x50*/
    __IO uint32_t SMSKR0;              /*!<FSMC Memory mask register 0                    offset: 0x54*/
    __IO uint32_t SMSKR1;              /*!<FSMC Memory mask register 1                    offset: 0x58*/
    __IO uint32_t SMSKR2;              /*!<FSMC Memory mask register 2                    offset: 0x5C*/
    __IO uint32_t SMSKR3;              /*!<FSMC Memory mask register 3                    offset: 0x60*/
    __IO uint32_t RESERVED0x064[12];   /*!<                                               offset: 0x64~0x90*/
    __IO uint32_t SMTMGR_SET0;         /*!<FSMC Memory timing register 0                  offset: 0x94*/
    __IO uint32_t SMTMGR_SET1;         /*!<FSMC Memory timing register 1                  offset: 0x98*/
    __IO uint32_t SMTMGR_SET2;         /*!<FSMC Memory timing register 2                  offset: 0x9C*/
    __IO uint32_t RESERVED0x0A0[1];    /*!<                                               offset: 0xa0*/
    __IO uint32_t SMCTLR;              /*!<FSMC Memory control register                   offset: 0xA4*/
} FSMC_TypeDef;

/**
  * @brief FSMC type pointer Definition
  */
#define FSMC                                      ((FSMC_TypeDef *)FSMC_BASE)

/**
  * @brief FSMC_SMSKR0 Register Bit Definition
  */
#define  FSMC_SMSKR0_MEM_SIZE_Pos                 (0)
#define  FSMC_SMSKR0_MEM_SIZE_Msk                 (0x1FU << FSMC_SMSKR0_MEM_SIZE_Pos)   /*!<*/
#define  FSMC_SMSKR0_MEM_TYPE_Pos                 (5)
#define  FSMC_SMSKR0_MEM_TYPE_Msk                 (0x07U << FSMC_SMSKR0_MEM_TYPE_Pos)   /*!<*/
#define  FSMC_SMSKR0_REG_SELECT_Pos               (8)
#define  FSMC_SMSKR0_REG_SELECT_Msk               (0x07U << FSMC_SMSKR0_REG_SELECT_Pos) /*!<*/

/**
  * @brief FSMC_SMSKR1 Register Bit Definition
  */
#define  FSMC_SMSKR1_MEM_SIZE_Pos                 (0)
#define  FSMC_SMSKR1_MEM_SIZE_Msk                 (0x1FU << FSMC_SMSKR1_MEM_SIZE_Pos)   /*!<*/
#define  FSMC_SMSKR1_MEM_TYPE_Pos                 (5)
#define  FSMC_SMSKR1_MEM_TYPE_Msk                 (0x07U << FSMC_SMSKR1_MEM_TYPE_Pos)   /*!<*/
#define  FSMC_SMSKR1_REG_SELECT_Pos               (8)
#define  FSMC_SMSKR1_REG_SELECT_Msk               (0x07U << FSMC_SMSKR1_REG_SELECT_Pos) /*!<*/

/**
  * @brief FSMC_SMSKR2 Register Bit Definition
  */
#define  FSMC_SMSKR2_MEM_SIZE_Pos                 (0)
#define  FSMC_SMSKR2_MEM_SIZE_Msk                 (0x1FU << FSMC_SMSKR2_MEM_SIZE_Pos)   /*!<*/
#define  FSMC_SMSKR2_MEM_TYPE_Pos                 (5)
#define  FSMC_SMSKR2_MEM_TYPE_Msk                 (0x07U << FSMC_SMSKR2_MEM_TYPE_Pos)   /*!<*/
#define  FSMC_SMSKR2_REG_SELECT_Pos               (8)
#define  FSMC_SMSKR2_REG_SELECT_Msk               (0x07U << FSMC_SMSKR2_REG_SELECT_Pos) /*!<*/

/**
  * @brief FSMC_SMSKR3 Register Bit Definition
  */
#define  FSMC_SMSKR3_MEM_SIZE_Pos                 (0)
#define  FSMC_SMSKR3_MEM_SIZE_Msk                 (0x1FU << FSMC_SMSKR3_MEM_SIZE_Pos)   /*!<*/
#define  FSMC_SMSKR3_MEM_TYPE_Pos                 (5)
#define  FSMC_SMSKR3_MEM_TYPE_Msk                 (0x07U << FSMC_SMSKR3_MEM_TYPE_Pos)   /*!<*/
#define  FSMC_SMSKR3_REG_SELECT_Pos               (8)
#define  FSMC_SMSKR3_REG_SELECT_Msk               (0x07U << FSMC_SMSKR3_REG_SELECT_Pos) /*!<*/

/**
  * @brief FSMC_SMTMGR_SET0 Register Bit Definition
  */
#define  FSMC_SMTMGR_SET0_T_RC_Pos                (0)
#define  FSMC_SMTMGR_SET0_T_RC_Msk                (0x3FU << FSMC_SMTMGR_SET0_T_RC_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET0_T_AS_Pos                (6)
#define  FSMC_SMTMGR_SET0_T_AS_Msk                (0x03U << FSMC_SMTMGR_SET0_T_AS_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET0_T_WR_Pos                (8)
#define  FSMC_SMTMGR_SET0_T_WR_Msk                (0x03U << FSMC_SMTMGR_SET0_T_WR_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET0_T_WP_Pos                (10)
#define  FSMC_SMTMGR_SET0_T_WP_Msk                (0x3FU << FSMC_SMTMGR_SET0_T_WP_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET0_READY_MODE_Pos          (26)
#define  FSMC_SMTMGR_SET0_READY_MODE_Msk          (0x01U << FSMC_SMTMGR_SET0_READY_MODE_Pos)   /*!<*/
#define  FSMC_SMTMGR_SET0_SM_READ_PIPE_Pos        (28)
#define  FSMC_SMTMGR_SET0_SM_READ_PIPE_Msk        (0x03U << FSMC_SMTMGR_SET0_SM_READ_PIPE_Pos) /*!<*/

/**
  * @brief FSMC_SMTMGR_SET1 Register Bit Definition
  */
#define  FSMC_SMTMGR_SET1_T_RC_Pos                (0)
#define  FSMC_SMTMGR_SET1_T_RC_Msk                (0x3FU << FSMC_SMTMGR_SET1_T_RC_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET1_T_AS_Pos                (6)
#define  FSMC_SMTMGR_SET1_T_AS_Msk                (0x03U << FSMC_SMTMGR_SET1_T_AS_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET1_T_WR_Pos                (8)
#define  FSMC_SMTMGR_SET1_T_WR_Msk                (0x03U << FSMC_SMTMGR_SET1_T_WR_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET1_T_WP_Pos                (10)
#define  FSMC_SMTMGR_SET1_T_WP_Msk                (0x3FU << FSMC_SMTMGR_SET1_T_WP_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET1_READY_MODE_Pos          (26)
#define  FSMC_SMTMGR_SET1_READY_MODE_Msk          (0x01U << FSMC_SMTMGR_SET1_READY_MODE_Pos)   /*!<*/
#define  FSMC_SMTMGR_SET1_SM_READ_PIPE_Pos        (28)
#define  FSMC_SMTMGR_SET1_SM_READ_PIPE_Msk        (0x03U << FSMC_SMTMGR_SET1_SM_READ_PIPE_Pos) /*!<*/

/**
  * @brief FSMC_SMTMGR_SET2 Register Bit Definition
  */
#define  FSMC_SMTMGR_SET2_T_RC_Pos                (0)
#define  FSMC_SMTMGR_SET2_T_RC_Msk                (0x3FU << FSMC_SMTMGR_SET2_T_RC_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET2_T_AS_Pos                (6)
#define  FSMC_SMTMGR_SET2_T_AS_Msk                (0x03U << FSMC_SMTMGR_SET2_T_AS_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET2_T_WR_Pos                (8)
#define  FSMC_SMTMGR_SET2_T_WR_Msk                (0x03U << FSMC_SMTMGR_SET2_T_WR_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET2_T_WP_Pos                (10)
#define  FSMC_SMTMGR_SET2_T_WP_Msk                (0x3FU << FSMC_SMTMGR_SET2_T_WP_Pos)         /*!<*/
#define  FSMC_SMTMGR_SET2_READY_MODE_Pos          (26)
#define  FSMC_SMTMGR_SET2_READY_MODE_Msk          (0x01U << FSMC_SMTMGR_SET2_READY_MODE_Pos)   /*!<*/
#define  FSMC_SMTMGR_SET2_SM_READ_PIPE_Pos        (28)
#define  FSMC_SMTMGR_SET2_SM_READ_PIPE_Msk        (0x03U << FSMC_SMTMGR_SET2_SM_READ_PIPE_Pos) /*!<*/

/**
  * @brief FSMC_SMCTLR Register Bit Definition
  */
#define  FSMC_SMCTLR_FLASH_RP_Pos                 (0)
#define  FSMC_SMCTLR_FLASH_RP_Msk                 (0x01U << FSMC_SMCTLR_FLASH_RP_Pos) /*!<*/
#define  FSMC_SMCTLR_SM_DW0_Pos                   (7)
#define  FSMC_SMCTLR_SM_DW0_Msk                   (0x07U << FSMC_SMCTLR_SM_DW0_Pos)   /*!<*/
#define  FSMC_SMCTLR_SM_DW1_Pos                   (10)
#define  FSMC_SMCTLR_SM_DW1_Msk                   (0x07U << FSMC_SMCTLR_SM_DW1_Pos)   /*!<*/
#define  FSMC_SMCTLR_SM_DW2_Pos                   (13)
#define  FSMC_SMCTLR_SM_DW2_Msk                   (0x07U << FSMC_SMCTLR_SM_DW2_Pos)   /*!<*/

#endif

