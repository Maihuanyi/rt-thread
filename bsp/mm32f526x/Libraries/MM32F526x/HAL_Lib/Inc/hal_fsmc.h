/***********************************************************************************************************************
    @file     hal_fsmc.h
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
#ifndef __HAL_FSMC_H
#define __HAL_FSMC_H

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/**  @addtogroup MM32_Hardware_Abstract_Layer
  *  @{
  */

/**  @defgroup FSMC_HAL
  *  @brief FSMC HAL modules
  * @{
  */

/**  @defgroup FSMC_Exported_Types
  *  @{
  */

#define FSMC_BANK1_ADDR                  (0x60000000UL + 0x00000000UL)
#define FSMC_BANK2_ADDR                  (0x60000000UL + 0x04000000UL)
#define FSMC_BANK3_ADDR                  (0x60000000UL + 0x08000000UL)
#define FSMC_BANK4_ADDR                  (0x60000000UL + 0x0c000000UL)

#define FSMC_Bank1                       ((uint32_t)0x00000000)
#define FSMC_Bank2                       ((uint32_t)0x00000001)
#define FSMC_Bank3                       ((uint32_t)0x00000002)
#define FSMC_Bank4                       ((uint32_t)0x00000003)

#define FSMC_Mode_6800                   ((uint32_t)0x40000000)
#define FSMC_Mode_8080                   ((uint32_t)0x20000000)
#define FSMC_Mode_NorFlash               ((uint32_t)0x00000000)

#define FSMC_MemType_SDRAM               ((uint32_t)0x0 << FSMC_SMSKR0_MEM_TYPE_Pos)
#define FSMC_MemType_NorSRAM             ((uint32_t)0x1 << FSMC_SMSKR0_MEM_TYPE_Pos)
#define FSMC_MemType_FLASH               ((uint32_t)0x2 << FSMC_SMSKR0_MEM_TYPE_Pos)
#define FSMC_MemType_RESERVED            ((uint32_t)0x3 << FSMC_SMSKR0_MEM_TYPE_Pos)

#define FSMC_AddrDataMUX                 ((uint32_t)0x00000000)
#define FSMC_AddrDataDeMUX               ((uint32_t)0x10000000)

#define FSMC_TimingRegSelect_0           ((uint32_t)(0x00U << FSMC_SMSKR0_REG_SELECT_Pos))
#define FSMC_TimingRegSelect_1           ((uint32_t)(0x01U << FSMC_SMSKR0_REG_SELECT_Pos))
#define FSMC_TimingRegSelect_2           ((uint32_t)(0x02U << FSMC_SMSKR0_REG_SELECT_Pos))

#define FSMC_MemSize_64KB                (0x01U << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 64KB    */
#define FSMC_MemSize_128KB               (0x02U << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 128KB   */
#define FSMC_MemSize_256KB               (0x03U << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 256KB   */
#define FSMC_MemSize_512KB               (0x04U << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 512KB   */
#define FSMC_MemSize_1MB                 (0x05U << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 1MB     */
#define FSMC_MemSize_2MB                 (0x06U << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 2MB     */
#define FSMC_MemSize_4MB                 (0x07U << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 4MB     */
#define FSMC_MemSize_8MB                 (0x08U << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 8MB     */
#define FSMC_MemSize_16MB                (0x09U << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 16MB    */
#define FSMC_MemSize_32MB                (0x0AU << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 32MB    */
#define FSMC_MemSize_64MB                (0x0BU << FSMC_SMSKR0_MEM_SIZE_Pos) /*!< external DEVICE size 64MB    */

#define FSMC_DataWidth_16bits            0x00                                /* 16bits */
#define FSMC_DataWidth_8bits             0x04                                /* 8bits */

typedef struct
{
    uint32_t FSMC_SMReadPipe;          //sm_read_pipe[1:0] The cycle of latching read data, that is, the cycle when ready_resp is pulled high
    uint32_t FSMC_ReadyMode;           //0: Internal FSMC 1: External DEVICE (ie from FSMC_NWAIT)
    uint32_t FSMC_WritePeriod;         //Write cycle
    uint32_t FSMC_WriteHoldTime;       //Address/data hold time during write operation
    uint32_t FSMC_AddrSetTime;         //Address establishment time
    uint32_t FSMC_ReadPeriod;          //Read cycle
} FSMC_TimingInitTypeDef;

typedef struct
{
    uint32_t                FSMC_Bank;
    uint32_t                FSMC_Mode;
    uint32_t                FSMC_AddrDataMode;
    uint32_t                FSMC_MemType;
    uint32_t                FSMC_MemSize;
    uint32_t                FSMC_MemoryDataWidth;
    uint32_t                FSMC_TimingRegSelect;
    FSMC_TimingInitTypeDef *FSMC_TimingStruct;
} FSMC_InitTypeDef;

void FSMC_DeInit(FSMC_TypeDef *fsmc);
void FSMC_TimingStructInit(FSMC_TimingInitTypeDef *init_struct);
void FSMC_StructInit(FSMC_InitTypeDef *init_struct);
void FSMC_Init(FSMC_InitTypeDef *init_struct);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif

