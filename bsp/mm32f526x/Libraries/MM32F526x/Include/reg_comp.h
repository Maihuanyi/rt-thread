/***********************************************************************************************************************
    @file     reg_comp.h
    @author   VV TEAM
    @brief    This flie contains all the COMP's register and its field definition.
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

#ifndef __REG_COMP_H
#define __REG_COMP_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief COMP Base Address Definition
  */
#define  COMP_BASE                                 0x40014000 /*!<Base Address: 0x40014000*/

/**
  * @brief COMP Register Structure Definition
  */

typedef struct
{
    __IO uint32_t RESERVED0x00[3];    /*!<                                               offset: 0x00~0x08*/
    __IO uint32_t COMP1CSR;           /*!<COMP1 control status register                  offset: 0x0C*/
    __IO uint32_t COMP2CSR;           /*!<COMP2 control status register                  offset: 0x10*/
    __IO uint32_t RESERVED0x14[1];    /*!<                                               offset: 0x14*/
    __IO uint32_t CRV;                /*!<COMP CRV Register                              offset: 0x18*/
    __IO uint32_t COMP1POLL;          /*!<COMP1 polling register                         offset: 0x1C*/
    __IO uint32_t COMP2POLL;          /*!<COMP2 polling register                         offset: 0x20*/
    __IO uint32_t COMP3POLL;          /*!<COMP3 polling register                         offset: 0x24*/
    __IO uint32_t RESERVED0x28[2];    /*!<                                               offset: 0x28~0x2C*/
    __IO uint32_t COMP3CSR;           /*!<COMP3 control status register                  offset: 0x30*/
} COMP_TypeDef;

/**
  * @brief COMP type pointer Definition
  */
#define COMP                          ((COMP_TypeDef *)COMP_BASE)

/**
  * @brief COMP_CSR Register Bit Definition
  */
#define  COMP_CSR_EN_Pos                          (0)
#define  COMP_CSR_EN_Msk                          (0x01U << COMP_CSR_EN_Pos)          /*!<*/
#define  COMP_CSR_MODE_Pos                        (2)
#define  COMP_CSR_MODE_Msk                        (0x03U << COMP_CSR_MODE_Pos)        /*!<*/
#define  COMP_CSR_INM_SEL_Pos                     (4)
#define  COMP_CSR_INM_SEL_Msk                     (0x07U << COMP_CSR_INM_SEL_Pos)     /*!<*/
#define  COMP_CSR_INP_SEL_Pos                     (7)
#define  COMP_CSR_INP_SEL_Msk                     (0x03U << COMP_CSR_INP_SEL_Pos)     /*!<*/
#define  COMP_CSR_OUT_SEL_Pos                     (10)
#define  COMP_CSR_OUT_SEL_Msk                     (0x0FU << COMP_CSR_OUT_SEL_Pos)     /*!<*/
#define  COMP_CSR_POL_Pos                         (15)
#define  COMP_CSR_POL_Msk                         (0x01U << COMP_CSR_POL_Pos)         /*!<*/
#define  COMP_CSR_HYST_Pos                        (16)
#define  COMP_CSR_HYST_Msk                        (0x03U << COMP_CSR_HYST_Pos)        /*!<*/
#define  COMP_CSR_OFLT_Pos                        (18)
#define  COMP_CSR_OFLT_Msk                        (0x07U << COMP_CSR_OFLT_Pos)        /*!<*/
#define  COMP_CSR_WE_Pos                          (28)
#define  COMP_CSR_WE_Msk                          (0x01U << COMP_CSR_WE_Pos)          /*!<*/
#define  COMP_CSR_OUT_ANA_SEL_Pos                 (29)
#define  COMP_CSR_OUT_ANA_SEL_Msk                 (0x01U << COMP_CSR_OUT_ANA_SEL_Pos) /*!<*/
#define  COMP_CSR_OUT_Pos                         (30)
#define  COMP_CSR_OUT_Msk                         (0x01U << COMP_CSR_OUT_Pos)         /*!<*/
#define  COMP_CSR_LOCK_Pos                        (31)
#define  COMP_CSR_LOCK_Msk                        (0x01U << COMP_CSR_LOCK_Pos)        /*!<*/

/**
  * @brief COMP_CRV Register Bit Definition
  */
#define  COMP_CRV_CRV_SEL_Pos                     (0)
#define  COMP_CRV_CRV_SEL_Msk                     (0x0FU << COMP_CRV_CRV_SEL_Pos) /*!<*/
#define  COMP_CRV_CRV_EN_Pos                      (4)
#define  COMP_CRV_CRV_EN_Msk                      (0x01U << COMP_CRV_CRV_EN_Pos)  /*!<*/
#define  COMP_CRV_CRV_SRC_Pos                     (5)
#define  COMP_CRV_CRV_SRC_Msk                     (0x01U << COMP_CRV_CRV_SRC_Pos) /*!<*/

/**
  * @brief COMP_POLL Register Bit Definition
  */
#define  COMP_POLL_POLL_EN_Pos                    (0)
#define  COMP_POLL_POLL_EN_Msk                    (0x01U << COMP_POLL_POLL_EN_Pos) /*!<*/
#define  COMP_POLL_POLL_CH_Pos                    (1)
#define  COMP_POLL_POLL_CH_Msk                    (0x01U << COMP_POLL_POLL_CH_Pos) /*!<*/
#define  COMP_POLL_FIXN_Pos                       (2)
#define  COMP_POLL_FIXN_Msk                       (0x01U << COMP_POLL_FIXN_Pos)    /*!<*/
#define  COMP_POLL_PERIOD_Pos                     (4)
#define  COMP_POLL_PERIOD_Msk                     (0x07U << COMP_POLL_PERIOD_Pos)  /*!<*/
#define  COMP_POLL_POUT_Pos                       (8)
#define  COMP_POLL_POUT_Msk                       (0x07U << COMP_POLL_POUT_Pos)    /*!<*/

#endif

