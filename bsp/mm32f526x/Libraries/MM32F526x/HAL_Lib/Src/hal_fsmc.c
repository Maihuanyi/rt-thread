/***********************************************************************************************************************
    @file     hal_fsmc.c
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#define _HAL_FSMC_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_fsmc.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup FSMC_HAL
  * @{
  */

/** @addtogroup FSMC_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the fsmc peripheral registers to their default reset values.
  * @param  uart: Select the UART or the UART peripheral.
  * @retval None.
  */
void FSMC_DeInit(FSMC_TypeDef *fsmc)
{
    RCC_AHBPeriphResetCmd(RCC_AHBPeriph_FSMC, ENABLE);
    RCC_AHBPeriphResetCmd(RCC_AHBPeriph_FSMC, DISABLE);
}

void FSMC_TimingStructInit(FSMC_TimingInitTypeDef *init_struct)
{
    init_struct->FSMC_SMReadPipe    = 0;
    init_struct->FSMC_ReadyMode     = 0;
    init_struct->FSMC_WritePeriod   = 10;
    init_struct->FSMC_WriteHoldTime = 30;
    init_struct->FSMC_AddrSetTime   = 3;
    init_struct->FSMC_ReadPeriod    = 30;
}

void FSMC_StructInit(FSMC_InitTypeDef *init_struct)
{
    init_struct->FSMC_Bank = FSMC_Bank1;
    init_struct->FSMC_Mode = FSMC_Mode_NorFlash;
    init_struct->FSMC_AddrDataMode = FSMC_AddrDataDeMUX;
    init_struct->FSMC_MemType = FSMC_MemType_NorSRAM;
    init_struct->FSMC_MemSize = FSMC_MemSize_64MB;
    init_struct->FSMC_MemoryDataWidth = FSMC_DataWidth_16bits;

    init_struct->FSMC_TimingRegSelect = FSMC_TimingRegSelect_0;
    FSMC_TimingStructInit(init_struct->FSMC_TimingStruct);
}

void FSMC_Init(FSMC_InitTypeDef *init_struct)
{
    uint32_t temp;

    MODIFY_REG(SYSCFG->CFGR1, (SYSCFG_CFGR1_FC_MODESEL_Msk | SYSCFG_CFGR1_FC_ODATAEN_Msk), (init_struct->FSMC_Mode | init_struct->FSMC_AddrDataMode));

    temp = (uint32_t)init_struct->FSMC_TimingRegSelect | \
           (uint32_t)init_struct->FSMC_MemSize |         \
           (uint32_t)init_struct->FSMC_MemType;

    if (init_struct->FSMC_Bank == FSMC_Bank1)
    {
        FSMC->SMSKR0 = temp;
    }
    else if (init_struct->FSMC_Bank == FSMC_Bank2)
    {
        FSMC->SMSKR1 = temp;
    }
    else if (init_struct->FSMC_Bank == FSMC_Bank3)
    {
        FSMC->SMSKR2 = temp;
    }
    else if (init_struct->FSMC_Bank == FSMC_Bank4)
    {
        FSMC->SMSKR3 = temp;
    }

    temp = (uint32_t)((init_struct->FSMC_TimingStruct->FSMC_SMReadPipe << FSMC_SMTMGR_SET0_SM_READ_PIPE_Pos) |
                      (init_struct->FSMC_TimingStruct->FSMC_ReadyMode << FSMC_SMTMGR_SET0_READY_MODE_Pos) |
                      (init_struct->FSMC_TimingStruct->FSMC_WritePeriod << FSMC_SMTMGR_SET0_T_WP_Pos) |
                      (init_struct->FSMC_TimingStruct->FSMC_WriteHoldTime << FSMC_SMTMGR_SET0_T_WR_Pos) |
                      (init_struct->FSMC_TimingStruct->FSMC_AddrSetTime << FSMC_SMTMGR_SET0_T_AS_Pos) |
                      (init_struct->FSMC_TimingStruct->FSMC_ReadPeriod << FSMC_SMTMGR_SET0_T_RC_Pos));

    if (init_struct->FSMC_TimingRegSelect == FSMC_TimingRegSelect_0)
    {
        FSMC->SMCTLR = ((init_struct->FSMC_MemoryDataWidth << FSMC_SMCTLR_SM_DW0_Pos) | 0x00000001);
        FSMC->SMTMGR_SET0 = temp;
    }
    else if (init_struct->FSMC_TimingRegSelect == FSMC_TimingRegSelect_1)
    {
        FSMC->SMCTLR = ((init_struct->FSMC_MemoryDataWidth << FSMC_SMCTLR_SM_DW1_Pos) | 0x00000001);
        FSMC->SMTMGR_SET1 = temp;
    }
    else if (init_struct->FSMC_TimingRegSelect == FSMC_TimingRegSelect_2)
    {
        FSMC->SMCTLR = ((init_struct->FSMC_MemoryDataWidth << FSMC_SMCTLR_SM_DW2_Pos) | 0x00000001);
        FSMC->SMTMGR_SET2 = temp;
    }
}

/**
  *  @}
  */

/**
  * @}
  */

/**
  *  @}
  */

