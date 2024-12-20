/***********************************************************************************************************************
    @file     reg_wwdg.h
    @author   VV TEAM
    @brief    This flie contains all the WWDG's register and its field definition.
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

#ifndef __REG_WWDG_H
#define __REG_WWDG_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief WWDG Base Address Definition
  */
#define  WWDG_BASE                                 0x40002C00 /*!<Base Address: 0x40002C00*/

/**
  * @brief WWDG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                  /*!<WWDG Control register                          offset: 0x00*/
    __IO uint32_t CFGR;                /*!<WWDG Configuration register                    offset: 0x04*/
    __IO uint32_t SR;                  /*!<WWDG Status register                           offset: 0x08*/
} WWDG_TypeDef;

/**
  * @brief WWDG type pointer Definition
  */
#define WWDG                                      ((WWDG_TypeDef *)WWDG_BASE)

/**
  * @brief WWDG_CR Register Bit Definition
  */
#define  WWDG_CR_T_Pos                            (0)
#define  WWDG_CR_T_Msk                            (0x7FU << WWDG_CR_T_Pos)    /*!<*/
#define  WWDG_CR_WDGA_Pos                         (7)
#define  WWDG_CR_WDGA_Msk                         (0x01U << WWDG_CR_WDGA_Pos) /*!<*/

/**
  * @brief WWDG_CFGR Register Bit Definition
  */
#define  WWDG_CFGR_W_Pos                          (0)
#define  WWDG_CFGR_W_Msk                          (0x7FU << WWDG_CFGR_W_Pos)     /*!<*/
#define  WWDG_CFGR_WDGTB_Pos                      (7)
#define  WWDG_CFGR_WDGTB_Msk                      (0x03U << WWDG_CFGR_WDGTB_Pos) /*!<*/
#define  WWDG_CFGR_EWI_Pos                        (9)
#define  WWDG_CFGR_EWI_Msk                        (0x01U << WWDG_CFGR_EWI_Pos)   /*!<*/

/**
  * @brief WWDG_SR Register Bit Definition
  */
#define  WWDG_SR_EWIF_Pos                         (0)
#define  WWDG_SR_EWIF_Msk                         (0x01U << WWDG_SR_EWIF_Pos) /*!<*/

#endif

