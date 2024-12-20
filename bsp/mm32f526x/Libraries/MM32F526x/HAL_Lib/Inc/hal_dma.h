/***********************************************************************************************************************
    @file     hal_dma.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE DMA
              FIRMWARE LIBRARY.
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
#ifndef __HAL_DMA_H
#define __HAL_DMA_H
#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup DMA_HAL
  * @brief DMA HAL modules
  * @{
  */

/** @defgroup DMA_Exported_Types
  * @{
  */

/**
  * @brief  DMA Init structure definition
  */
typedef struct
{
    uint32_t DMA_PeripheralBaseAddr;   /*!< the peripheral base address for DMA Channeln. */
    uint32_t DMA_MemoryBaseAddr;       /*!< the memory base address for DMA Channeln. */
    uint32_t DMA_DIR;                  /*!< the peripheral is the source or destination. */
    uint32_t DMA_BufferSize;           /*!< Specifies the buffer size, in data unit, of the Buffer size */
    uint32_t DMA_PeripheralInc;        /*!< Specifies whether the Peripheral address increment or not */
    uint32_t DMA_MemoryInc;            /*!< Specifies whether the memory address register is increment or not */
    uint32_t DMA_PeripheralDataSize;   /*!< Specifies the Peripheral data width. */
    uint32_t DMA_MemoryDataSize;       /*!< Specifies the Memory data width. */
    uint32_t DMA_Mode;                 /*!< Specifies the operation mode of the DMA Channeln  circular or normal mode. */
    uint32_t DMA_Priority;             /*!< Specifies the software priority for the DMA priority level */
    uint32_t DMA_M2M;                  /*!< Specifies if the DMA Channeln will be used in  memory-to-memory transfer. */
    uint32_t DMA_Auto_Reload;          /*!< Specifies the DMA Channeln support auto reload number of data to transfer or not */
} DMA_InitTypeDef;

/**
  * @brief DMA data transfer direction Enumerate definition
  */
#define DMA_DIR_PeripheralSRC               (0x00U << DMA_CCR_DIR_Pos)
#define DMA_DIR_PeripheralDST               (0x01U << DMA_CCR_DIR_Pos)

/**
  * @brief DMA peripheral incremented mode  definition
  */
#define DMA_PeripheralInc_Disable           (0x00U << DMA_CCR_PINC_Pos)
#define DMA_PeripheralInc_Enable            (0x01U << DMA_CCR_PINC_Pos)

/**
  * @brief DMA memory incremented mode definition
  */
#define DMA_MemoryInc_Disable               (0x00U << DMA_CCR_MINC_Pos)
#define DMA_MemoryInc_Enable                (0x01U << DMA_CCR_MINC_Pos)

/**
  * @brief DMA peripheral data size  definition
  */
#define DMA_PeripheralDataSize_Byte         (0x00U << DMA_CCR_PSIZE_Pos)
#define DMA_PeripheralDataSize_HalfWord     (0x01U << DMA_CCR_PSIZE_Pos)
#define DMA_PeripheralDataSize_Word         (0x02U << DMA_CCR_PSIZE_Pos)

/**
  * @brief DMA memory data size  definition
  */
#define DMA_MemoryDataSize_Byte             (0x00U << DMA_CCR_MSIZE_Pos)
#define DMA_MemoryDataSize_HalfWord         (0x01U << DMA_CCR_MSIZE_Pos)
#define DMA_MemoryDataSize_Word             (0x02U << DMA_CCR_MSIZE_Pos)

/**
  * @brief DMA circular normal mode definition
  */
#define DMA_Mode_Normal                     (0x00U << DMA_CCR_CIRC_Pos)
#define DMA_Mode_Circular                   (0x01U << DMA_CCR_CIRC_Pos)

/**
  * @brief DMA priority level definition
  */
#define DMA_Priority_Low                    (0x00U << DMA_CCR_PL_Pos)
#define DMA_Priority_Medium                 (0x01U << DMA_CCR_PL_Pos)
#define DMA_Priority_High                   (0x02U << DMA_CCR_PL_Pos)
#define DMA_Priority_VeryHigh               (0x03U << DMA_CCR_PL_Pos)

/**
  * @brief DMA memory to memory definition
  */
#define DMA_M2M_Disable                     (0x00U << DMA_CCR_MEM2MEM_Pos)
#define DMA_M2M_Enable                      (0x01U << DMA_CCR_MEM2MEM_Pos)

/**
  * @brief DMA auto reload definition
  */
#define DMA_Auto_Reload_Disable             (0x00U << DMA_CCR_ARE_Pos)
#define DMA_Auto_Reload_Enable              (0x01U << DMA_CCR_ARE_Pos)

/**
  * @brief DMA Interrupt Setting  definition
  */
#define DMA_IT_TC                           (0x01U << DMA_CCR_TCIE_Pos)
#define DMA_IT_HT                           (0x01U << DMA_CCR_HTIE_Pos)
#define DMA_IT_TE                           (0x01U << DMA_CCR_TEIE_Pos)

/**
  * @brief DMA interrupts definition
  */
#define DMA1_IT_GL1                         ((uint8_t)((1 << 5U) | DMA_ISR_GIF1_Pos))
#define DMA1_IT_TC1                         ((uint8_t)((1 << 5U) | DMA_ISR_TCIF1_Pos))
#define DMA1_IT_HT1                         ((uint8_t)((1 << 5U) | DMA_ISR_HTIF1_Pos))
#define DMA1_IT_TE1                         ((uint8_t)((1 << 5U) | DMA_ISR_TEIF1_Pos))
#define DMA1_IT_GL2                         ((uint8_t)((1 << 5U) | DMA_ISR_GIF2_Pos))
#define DMA1_IT_TC2                         ((uint8_t)((1 << 5U) | DMA_ISR_TCIF2_Pos))
#define DMA1_IT_HT2                         ((uint8_t)((1 << 5U) | DMA_ISR_HTIF2_Pos))
#define DMA1_IT_TE2                         ((uint8_t)((1 << 5U) | DMA_ISR_TEIF2_Pos))
#define DMA1_IT_GL3                         ((uint8_t)((1 << 5U) | DMA_ISR_GIF3_Pos))
#define DMA1_IT_TC3                         ((uint8_t)((1 << 5U) | DMA_ISR_TCIF3_Pos))
#define DMA1_IT_HT3                         ((uint8_t)((1 << 5U) | DMA_ISR_HTIF3_Pos))
#define DMA1_IT_TE3                         ((uint8_t)((1 << 5U) | DMA_ISR_TEIF3_Pos))
#define DMA1_IT_GL4                         ((uint8_t)((1 << 5U) | DMA_ISR_GIF4_Pos))
#define DMA1_IT_TC4                         ((uint8_t)((1 << 5U) | DMA_ISR_TCIF4_Pos))
#define DMA1_IT_HT4                         ((uint8_t)((1 << 5U) | DMA_ISR_HTIF4_Pos))
#define DMA1_IT_TE4                         ((uint8_t)((1 << 5U) | DMA_ISR_TEIF4_Pos))
#define DMA1_IT_GL5                         ((uint8_t)((1 << 5U) | DMA_ISR_GIF5_Pos))
#define DMA1_IT_TC5                         ((uint8_t)((1 << 5U) | DMA_ISR_TCIF5_Pos))
#define DMA1_IT_HT5                         ((uint8_t)((1 << 5U) | DMA_ISR_HTIF5_Pos))
#define DMA1_IT_TE5                         ((uint8_t)((1 << 5U) | DMA_ISR_TEIF5_Pos))
#define DMA1_IT_GL6                         ((uint8_t)((1 << 5U) | DMA_ISR_GIF6_Pos))
#define DMA1_IT_TC6                         ((uint8_t)((1 << 5U) | DMA_ISR_TCIF6_Pos))
#define DMA1_IT_HT6                         ((uint8_t)((1 << 5U) | DMA_ISR_HTIF6_Pos))
#define DMA1_IT_TE6                         ((uint8_t)((1 << 5U) | DMA_ISR_TEIF6_Pos))
#define DMA1_IT_GL7                         ((uint8_t)((1 << 5U) | DMA_ISR_GIF7_Pos))
#define DMA1_IT_TC7                         ((uint8_t)((1 << 5U) | DMA_ISR_TCIF7_Pos))
#define DMA1_IT_HT7                         ((uint8_t)((1 << 5U) | DMA_ISR_HTIF7_Pos))
#define DMA1_IT_TE7                         ((uint8_t)((1 << 5U) | DMA_ISR_TEIF7_Pos))
#define DMA1_IT_GL8                         ((uint8_t)((1 << 5U) | DMA_ISR_GIF8_Pos))
#define DMA1_IT_TC8                         ((uint8_t)((1 << 5U) | DMA_ISR_TCIF8_Pos))
#define DMA1_IT_HT8                         ((uint8_t)((1 << 5U) | DMA_ISR_HTIF8_Pos))
#define DMA1_IT_TE8                         ((uint8_t)((1 << 5U) | DMA_ISR_TEIF8_Pos))

#define DMA2_IT_GL1                         ((uint8_t)((2 << 5U) | DMA_ISR_GIF1_Pos))
#define DMA2_IT_TC1                         ((uint8_t)((2 << 5U) | DMA_ISR_TCIF1_Pos))
#define DMA2_IT_HT1                         ((uint8_t)((2 << 5U) | DMA_ISR_HTIF1_Pos))
#define DMA2_IT_TE1                         ((uint8_t)((2 << 5U) | DMA_ISR_TEIF1_Pos))
#define DMA2_IT_GL2                         ((uint8_t)((2 << 5U) | DMA_ISR_GIF2_Pos))
#define DMA2_IT_TC2                         ((uint8_t)((2 << 5U) | DMA_ISR_TCIF2_Pos))
#define DMA2_IT_HT2                         ((uint8_t)((2 << 5U) | DMA_ISR_HTIF2_Pos))
#define DMA2_IT_TE2                         ((uint8_t)((2 << 5U) | DMA_ISR_TEIF2_Pos))
#define DMA2_IT_GL3                         ((uint8_t)((2 << 5U) | DMA_ISR_GIF3_Pos))
#define DMA2_IT_TC3                         ((uint8_t)((2 << 5U) | DMA_ISR_TCIF3_Pos))
#define DMA2_IT_HT3                         ((uint8_t)((2 << 5U) | DMA_ISR_HTIF3_Pos))
#define DMA2_IT_TE3                         ((uint8_t)((2 << 5U) | DMA_ISR_TEIF3_Pos))
#define DMA2_IT_GL4                         ((uint8_t)((2 << 5U) | DMA_ISR_GIF4_Pos))
#define DMA2_IT_TC4                         ((uint8_t)((2 << 5U) | DMA_ISR_TCIF4_Pos))
#define DMA2_IT_HT4                         ((uint8_t)((2 << 5U) | DMA_ISR_HTIF4_Pos))
#define DMA2_IT_TE4                         ((uint8_t)((2 << 5U) | DMA_ISR_TEIF4_Pos))
#define DMA2_IT_GL5                         ((uint8_t)((2 << 5U) | DMA_ISR_GIF5_Pos))
#define DMA2_IT_TC5                         ((uint8_t)((2 << 5U) | DMA_ISR_TCIF5_Pos))
#define DMA2_IT_HT5                         ((uint8_t)((2 << 5U) | DMA_ISR_HTIF5_Pos))
#define DMA2_IT_TE5                         ((uint8_t)((2 << 5U) | DMA_ISR_TEIF5_Pos))
#define DMA2_IT_GL6                         ((uint8_t)((2 << 5U) | DMA_ISR_GIF6_Pos))
#define DMA2_IT_TC6                         ((uint8_t)((2 << 5U) | DMA_ISR_TCIF6_Pos))
#define DMA2_IT_HT6                         ((uint8_t)((2 << 5U) | DMA_ISR_HTIF6_Pos))
#define DMA2_IT_TE6                         ((uint8_t)((2 << 5U) | DMA_ISR_TEIF6_Pos))
#define DMA2_IT_GL7                         ((uint8_t)((2 << 5U) | DMA_ISR_GIF7_Pos))
#define DMA2_IT_TC7                         ((uint8_t)((2 << 5U) | DMA_ISR_TCIF7_Pos))
#define DMA2_IT_HT7                         ((uint8_t)((2 << 5U) | DMA_ISR_HTIF7_Pos))
#define DMA2_IT_TE7                         ((uint8_t)((2 << 5U) | DMA_ISR_TEIF7_Pos))
#define DMA2_IT_GL8                         ((uint8_t)((2 << 5U) | DMA_ISR_GIF8_Pos))
#define DMA2_IT_TC8                         ((uint8_t)((2 << 5U) | DMA_ISR_TCIF8_Pos))
#define DMA2_IT_HT8                         ((uint8_t)((2 << 5U) | DMA_ISR_HTIF8_Pos))
#define DMA2_IT_TE8                         ((uint8_t)((2 << 5U) | DMA_ISR_TEIF8_Pos))

/**
  * @brief DMA Flags definition
  */
#define DMA1_FLAG_GL1                       ((uint8_t)((1 << 5U) | DMA_ISR_GIF1_Pos))
#define DMA1_FLAG_TC1                       ((uint8_t)((1 << 5U) | DMA_ISR_TCIF1_Pos))
#define DMA1_FLAG_HT1                       ((uint8_t)((1 << 5U) | DMA_ISR_HTIF1_Pos))
#define DMA1_FLAG_TE1                       ((uint8_t)((1 << 5U) | DMA_ISR_TEIF1_Pos))
#define DMA1_FLAG_GL2                       ((uint8_t)((1 << 5U) | DMA_ISR_GIF2_Pos))
#define DMA1_FLAG_TC2                       ((uint8_t)((1 << 5U) | DMA_ISR_TCIF2_Pos))
#define DMA1_FLAG_HT2                       ((uint8_t)((1 << 5U) | DMA_ISR_HTIF2_Pos))
#define DMA1_FLAG_TE2                       ((uint8_t)((1 << 5U) | DMA_ISR_TEIF2_Pos))
#define DMA1_FLAG_GL3                       ((uint8_t)((1 << 5U) | DMA_ISR_GIF3_Pos))
#define DMA1_FLAG_TC3                       ((uint8_t)((1 << 5U) | DMA_ISR_TCIF3_Pos))
#define DMA1_FLAG_HT3                       ((uint8_t)((1 << 5U) | DMA_ISR_HTIF3_Pos))
#define DMA1_FLAG_TE3                       ((uint8_t)((1 << 5U) | DMA_ISR_TEIF3_Pos))
#define DMA1_FLAG_GL4                       ((uint8_t)((1 << 5U) | DMA_ISR_GIF4_Pos))
#define DMA1_FLAG_TC4                       ((uint8_t)((1 << 5U) | DMA_ISR_TCIF4_Pos))
#define DMA1_FLAG_HT4                       ((uint8_t)((1 << 5U) | DMA_ISR_HTIF4_Pos))
#define DMA1_FLAG_TE4                       ((uint8_t)((1 << 5U) | DMA_ISR_TEIF4_Pos))
#define DMA1_FLAG_GL5                       ((uint8_t)((1 << 5U) | DMA_ISR_GIF5_Pos))
#define DMA1_FLAG_TC5                       ((uint8_t)((1 << 5U) | DMA_ISR_TCIF5_Pos))
#define DMA1_FLAG_HT5                       ((uint8_t)((1 << 5U) | DMA_ISR_HTIF5_Pos))
#define DMA1_FLAG_TE5                       ((uint8_t)((1 << 5U) | DMA_ISR_TEIF5_Pos))
#define DMA1_FLAG_GL6                       ((uint8_t)((1 << 5U) | DMA_ISR_GIF6_Pos))
#define DMA1_FLAG_TC6                       ((uint8_t)((1 << 5U) | DMA_ISR_TCIF6_Pos))
#define DMA1_FLAG_HT6                       ((uint8_t)((1 << 5U) | DMA_ISR_HTIF6_Pos))
#define DMA1_FLAG_TE6                       ((uint8_t)((1 << 5U) | DMA_ISR_TEIF6_Pos))
#define DMA1_FLAG_GL7                       ((uint8_t)((1 << 5U) | DMA_ISR_GIF7_Pos))
#define DMA1_FLAG_TC7                       ((uint8_t)((1 << 5U) | DMA_ISR_TCIF7_Pos))
#define DMA1_FLAG_HT7                       ((uint8_t)((1 << 5U) | DMA_ISR_HTIF7_Pos))
#define DMA1_FLAG_TE7                       ((uint8_t)((1 << 5U) | DMA_ISR_TEIF7_Pos))
#define DMA1_FLAG_GL8                       ((uint8_t)((1 << 5U) | DMA_ISR_GIF8_Pos))
#define DMA1_FLAG_TC8                       ((uint8_t)((1 << 5U) | DMA_ISR_TCIF8_Pos))
#define DMA1_FLAG_HT8                       ((uint8_t)((1 << 5U) | DMA_ISR_HTIF8_Pos))
#define DMA1_FLAG_TE8                       ((uint8_t)((1 << 5U) | DMA_ISR_TEIF8_Pos))

#define DMA2_FLAG_GL1                       ((uint8_t)((2 << 5U) | DMA_ISR_GIF1_Pos))
#define DMA2_FLAG_TC1                       ((uint8_t)((2 << 5U) | DMA_ISR_TCIF1_Pos))
#define DMA2_FLAG_HT1                       ((uint8_t)((2 << 5U) | DMA_ISR_HTIF1_Pos))
#define DMA2_FLAG_TE1                       ((uint8_t)((2 << 5U) | DMA_ISR_TEIF1_Pos))
#define DMA2_FLAG_GL2                       ((uint8_t)((2 << 5U) | DMA_ISR_GIF2_Pos))
#define DMA2_FLAG_TC2                       ((uint8_t)((2 << 5U) | DMA_ISR_TCIF2_Pos))
#define DMA2_FLAG_HT2                       ((uint8_t)((2 << 5U) | DMA_ISR_HTIF2_Pos))
#define DMA2_FLAG_TE2                       ((uint8_t)((2 << 5U) | DMA_ISR_TEIF2_Pos))
#define DMA2_FLAG_GL3                       ((uint8_t)((2 << 5U) | DMA_ISR_GIF3_Pos))
#define DMA2_FLAG_TC3                       ((uint8_t)((2 << 5U) | DMA_ISR_TCIF3_Pos))
#define DMA2_FLAG_HT3                       ((uint8_t)((2 << 5U) | DMA_ISR_HTIF3_Pos))
#define DMA2_FLAG_TE3                       ((uint8_t)((2 << 5U) | DMA_ISR_TEIF3_Pos))
#define DMA2_FLAG_GL4                       ((uint8_t)((2 << 5U) | DMA_ISR_GIF4_Pos))
#define DMA2_FLAG_TC4                       ((uint8_t)((2 << 5U) | DMA_ISR_TCIF4_Pos))
#define DMA2_FLAG_HT4                       ((uint8_t)((2 << 5U) | DMA_ISR_HTIF4_Pos))
#define DMA2_FLAG_TE4                       ((uint8_t)((2 << 5U) | DMA_ISR_TEIF4_Pos))
#define DMA2_FLAG_GL5                       ((uint8_t)((2 << 5U) | DMA_ISR_GIF5_Pos))
#define DMA2_FLAG_TC5                       ((uint8_t)((2 << 5U) | DMA_ISR_TCIF5_Pos))
#define DMA2_FLAG_HT5                       ((uint8_t)((2 << 5U) | DMA_ISR_HTIF5_Pos))
#define DMA2_FLAG_TE5                       ((uint8_t)((2 << 5U) | DMA_ISR_TEIF5_Pos))
#define DMA2_FLAG_GL6                       ((uint8_t)((2 << 5U) | DMA_ISR_GIF6_Pos))
#define DMA2_FLAG_TC6                       ((uint8_t)((2 << 5U) | DMA_ISR_TCIF6_Pos))
#define DMA2_FLAG_HT6                       ((uint8_t)((2 << 5U) | DMA_ISR_HTIF6_Pos))
#define DMA2_FLAG_TE6                       ((uint8_t)((2 << 5U) | DMA_ISR_TEIF6_Pos))
#define DMA2_FLAG_GL7                       ((uint8_t)((2 << 5U) | DMA_ISR_GIF7_Pos))
#define DMA2_FLAG_TC7                       ((uint8_t)((2 << 5U) | DMA_ISR_TCIF7_Pos))
#define DMA2_FLAG_HT7                       ((uint8_t)((2 << 5U) | DMA_ISR_HTIF7_Pos))
#define DMA2_FLAG_TE7                       ((uint8_t)((2 << 5U) | DMA_ISR_TEIF7_Pos))
#define DMA2_FLAG_GL8                       ((uint8_t)((2 << 5U) | DMA_ISR_GIF8_Pos))
#define DMA2_FLAG_TC8                       ((uint8_t)((2 << 5U) | DMA_ISR_TCIF8_Pos))
#define DMA2_FLAG_HT8                       ((uint8_t)((2 << 5U) | DMA_ISR_HTIF8_Pos))
#define DMA2_FLAG_TE8                       ((uint8_t)((2 << 5U) | DMA_ISR_TEIF8_Pos))

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions
  * @{
  */
void DMA_DeInit(DMA_Channel_TypeDef *channel);
void DMA_Init(DMA_Channel_TypeDef *channel, DMA_InitTypeDef *init_struct);
void DMA_StructInit(DMA_InitTypeDef *init_struct);
void DMA_Cmd(DMA_Channel_TypeDef *channel, FunctionalState state);
void DMA_ITConfig(DMA_Channel_TypeDef *channel, uint32_t it, FunctionalState state);
void DMA_SetCurrDataCounter(DMA_Channel_TypeDef *channel, uint16_t length);
uint16_t DMA_GetCurrDataCounter(DMA_Channel_TypeDef *channel);

FlagStatus DMA_GetFlagStatus(uint32_t flag);
void DMA_ClearFlag(uint32_t flag);
ITStatus DMA_GetITStatus(uint32_t it);
void DMA_ClearITPendingBit(uint32_t it);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
#ifdef __cplusplus
}
#endif

/** --------------------------------------------------------------------------*/
#endif /* __HAL_DMA_H --------------------------------------------------------*/
/** --------------------------------------------------------------------------*/

