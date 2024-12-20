/***********************************************************************************************************************
    @file     reg_dma.h
    @author   VV TEAM
    @brief    This flie contains all the DMA's register and its field definition.
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

#ifndef __REG_DMA_H
#define __REG_DMA_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief DMA Base Address Definition
  */
#define  DMA1_BASE                                 0x40020000            /*!<Base Address: 0x40020000*/
#define  DMA1_Channel1_BASE                        (DMA1_BASE + 0x0008U) /*!<Base Address: (DMA1_BASE    + 0x0008U)*/
#define  DMA1_Channel2_BASE                        (DMA1_BASE + 0x001CU) /*!<Base Address: (DMA1_BASE    + 0x001CU)*/
#define  DMA1_Channel3_BASE                        (DMA1_BASE + 0x0030U) /*!<Base Address: (DMA1_BASE    + 0x0030U)*/
#define  DMA1_Channel4_BASE                        (DMA1_BASE + 0x0044U) /*!<Base Address: (DMA1_BASE    + 0x0044U)*/
#define  DMA1_Channel5_BASE                        (DMA1_BASE + 0x0058U) /*!<Base Address: (DMA1_BASE    + 0x0058U)*/
#define  DMA1_Channel6_BASE                        (DMA1_BASE + 0x006CU) /*!<Base Address: (DMA1_BASE    + 0x006CU)*/
#define  DMA1_Channel7_BASE                        (DMA1_BASE + 0x0080U) /*!<Base Address: (DMA1_BASE    + 0x0080U)*/
#define  DMA1_Channel8_BASE                        (DMA1_BASE + 0x0094U) /*!<Base Address: (DMA1_BASE    + 0x0094U)*/
#define  DMA2_BASE                                 0x40020400            /*!<Base Address: 0x40020400*/
#define  DMA2_Channel1_BASE                        (DMA2_BASE + 0x0008U) /*!<Base Address: (DMA2_BASE    + 0x0008U)*/
#define  DMA2_Channel2_BASE                        (DMA2_BASE + 0x001CU) /*!<Base Address: (DMA2_BASE    + 0x001CU)*/
#define  DMA2_Channel3_BASE                        (DMA2_BASE + 0x0030U) /*!<Base Address: (DMA2_BASE    + 0x0030U)*/
#define  DMA2_Channel4_BASE                        (DMA2_BASE + 0x0044U) /*!<Base Address: (DMA2_BASE    + 0x0044U)*/
#define  DMA2_Channel5_BASE                        (DMA2_BASE + 0x0058U) /*!<Base Address: (DMA2_BASE    + 0x0058U)*/
#define  DMA2_Channel6_BASE                        (DMA2_BASE + 0x006CU) /*!<Base Address: (DMA2_BASE    + 0x006CU)*/
#define  DMA2_Channel7_BASE                        (DMA2_BASE + 0x0080U) /*!<Base Address: (DMA2_BASE    + 0x0080U)*/
#define  DMA2_Channel8_BASE                        (DMA2_BASE + 0x0094U) /*!<Base Address: (DMA2_BASE    + 0x0094U)*/

/**
  * @brief DMA Register Structure Definition
  */
typedef struct
{
    __IO uint32_t ISR;                 /*!<DMA DMA interrupt status register              offset: 0x00*/
    __IO uint32_t IFCR;                /*!<DMA DMA interrupt flag clear register          offset: 0x04*/
} DMA_TypeDef;

/**
  * @brief DMA_Channel Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CCR;                 /*!<DMA DMA channel x configuration register       offset: 0x00*/
    __IO uint32_t CNDTR;               /*!<DMA DMA channel x number of data register      offset: 0x04*/
    __IO uint32_t CPAR;                /*!<DMA DMA channel x peripheral address register  offset: 0x08*/
    __IO uint32_t CMAR;                /*!<DMA DMA channel x memory address register      offset: 0x0C*/
} DMA_Channel_TypeDef;

/**
  * @brief DMA type pointer Definition
  */
#define DMA1                                      ((DMA_TypeDef *)DMA1_BASE)
#define DMA1_Channel1                             ((DMA_Channel_TypeDef *)DMA1_Channel1_BASE)
#define DMA1_Channel2                             ((DMA_Channel_TypeDef *)DMA1_Channel2_BASE)
#define DMA1_Channel3                             ((DMA_Channel_TypeDef *)DMA1_Channel3_BASE)
#define DMA1_Channel4                             ((DMA_Channel_TypeDef *)DMA1_Channel4_BASE)
#define DMA1_Channel5                             ((DMA_Channel_TypeDef *)DMA1_Channel5_BASE)
#define DMA1_Channel6                             ((DMA_Channel_TypeDef *)DMA1_Channel6_BASE)
#define DMA1_Channel7                             ((DMA_Channel_TypeDef *)DMA1_Channel7_BASE)
#define DMA1_Channel8                             ((DMA_Channel_TypeDef *)DMA1_Channel8_BASE)
#define DMA2                                      ((DMA_TypeDef *)DMA2_BASE)
#define DMA2_Channel1                             ((DMA_Channel_TypeDef *)DMA2_Channel1_BASE)
#define DMA2_Channel2                             ((DMA_Channel_TypeDef *)DMA2_Channel2_BASE)
#define DMA2_Channel3                             ((DMA_Channel_TypeDef *)DMA2_Channel3_BASE)
#define DMA2_Channel4                             ((DMA_Channel_TypeDef *)DMA2_Channel4_BASE)
#define DMA2_Channel5                             ((DMA_Channel_TypeDef *)DMA2_Channel5_BASE)
#define DMA2_Channel6                             ((DMA_Channel_TypeDef *)DMA2_Channel6_BASE)
#define DMA2_Channel7                             ((DMA_Channel_TypeDef *)DMA2_Channel7_BASE)
#define DMA2_Channel8                             ((DMA_Channel_TypeDef *)DMA2_Channel8_BASE)

/**
  * @brief DMA_ISR Register Bit Definition
  */
#define  DMA_ISR_GIF1_Pos                         (0)
#define  DMA_ISR_GIF1_Msk                         (0x01U << DMA_ISR_GIF1_Pos)  /*!<*/
#define  DMA_ISR_TCIF1_Pos                        (1)
#define  DMA_ISR_TCIF1_Msk                        (0x01U << DMA_ISR_TCIF1_Pos) /*!<*/
#define  DMA_ISR_HTIF1_Pos                        (2)
#define  DMA_ISR_HTIF1_Msk                        (0x01U << DMA_ISR_HTIF1_Pos) /*!<*/
#define  DMA_ISR_TEIF1_Pos                        (3)
#define  DMA_ISR_TEIF1_Msk                        (0x01U << DMA_ISR_TEIF1_Pos) /*!<*/
#define  DMA_ISR_GIF2_Pos                         (4)
#define  DMA_ISR_GIF2_Msk                         (0x01U << DMA_ISR_GIF2_Pos)  /*!<*/
#define  DMA_ISR_TCIF2_Pos                        (5)
#define  DMA_ISR_TCIF2_Msk                        (0x01U << DMA_ISR_TCIF2_Pos) /*!<*/
#define  DMA_ISR_HTIF2_Pos                        (6)
#define  DMA_ISR_HTIF2_Msk                        (0x01U << DMA_ISR_HTIF2_Pos) /*!<*/
#define  DMA_ISR_TEIF2_Pos                        (7)
#define  DMA_ISR_TEIF2_Msk                        (0x01U << DMA_ISR_TEIF2_Pos) /*!<*/
#define  DMA_ISR_GIF3_Pos                         (8)
#define  DMA_ISR_GIF3_Msk                         (0x01U << DMA_ISR_GIF3_Pos)  /*!<*/
#define  DMA_ISR_TCIF3_Pos                        (9)
#define  DMA_ISR_TCIF3_Msk                        (0x01U << DMA_ISR_TCIF3_Pos) /*!<*/
#define  DMA_ISR_HTIF3_Pos                        (10)
#define  DMA_ISR_HTIF3_Msk                        (0x01U << DMA_ISR_HTIF3_Pos) /*!<*/
#define  DMA_ISR_TEIF3_Pos                        (11)
#define  DMA_ISR_TEIF3_Msk                        (0x01U << DMA_ISR_TEIF3_Pos) /*!<*/
#define  DMA_ISR_GIF4_Pos                         (12)
#define  DMA_ISR_GIF4_Msk                         (0x01U << DMA_ISR_GIF4_Pos)  /*!<*/
#define  DMA_ISR_TCIF4_Pos                        (13)
#define  DMA_ISR_TCIF4_Msk                        (0x01U << DMA_ISR_TCIF4_Pos) /*!<*/
#define  DMA_ISR_HTIF4_Pos                        (14)
#define  DMA_ISR_HTIF4_Msk                        (0x01U << DMA_ISR_HTIF4_Pos) /*!<*/
#define  DMA_ISR_TEIF4_Pos                        (15)
#define  DMA_ISR_TEIF4_Msk                        (0x01U << DMA_ISR_TEIF4_Pos) /*!<*/
#define  DMA_ISR_GIF5_Pos                         (16)
#define  DMA_ISR_GIF5_Msk                         (0x01U << DMA_ISR_GIF5_Pos)  /*!<*/
#define  DMA_ISR_TCIF5_Pos                        (17)
#define  DMA_ISR_TCIF5_Msk                        (0x01U << DMA_ISR_TCIF5_Pos) /*!<*/
#define  DMA_ISR_HTIF5_Pos                        (18)
#define  DMA_ISR_HTIF5_Msk                        (0x01U << DMA_ISR_HTIF5_Pos) /*!<*/
#define  DMA_ISR_TEIF5_Pos                        (19)
#define  DMA_ISR_TEIF5_Msk                        (0x01U << DMA_ISR_TEIF5_Pos) /*!<*/
#define  DMA_ISR_GIF6_Pos                         (20)
#define  DMA_ISR_GIF6_Msk                         (0x01U << DMA_ISR_GIF6_Pos)  /*!<*/
#define  DMA_ISR_TCIF6_Pos                        (21)
#define  DMA_ISR_TCIF6_Msk                        (0x01U << DMA_ISR_TCIF6_Pos) /*!<*/
#define  DMA_ISR_HTIF6_Pos                        (22)
#define  DMA_ISR_HTIF6_Msk                        (0x01U << DMA_ISR_HTIF6_Pos) /*!<*/
#define  DMA_ISR_TEIF6_Pos                        (23)
#define  DMA_ISR_TEIF6_Msk                        (0x01U << DMA_ISR_TEIF6_Pos) /*!<*/
#define  DMA_ISR_GIF7_Pos                         (24)
#define  DMA_ISR_GIF7_Msk                         (0x01U << DMA_ISR_GIF7_Pos)  /*!<*/
#define  DMA_ISR_TCIF7_Pos                        (25)
#define  DMA_ISR_TCIF7_Msk                        (0x01U << DMA_ISR_TCIF7_Pos) /*!<*/
#define  DMA_ISR_HTIF7_Pos                        (26)
#define  DMA_ISR_HTIF7_Msk                        (0x01U << DMA_ISR_HTIF7_Pos) /*!<*/
#define  DMA_ISR_TEIF7_Pos                        (27)
#define  DMA_ISR_TEIF7_Msk                        (0x01U << DMA_ISR_TEIF7_Pos) /*!<*/
#define  DMA_ISR_GIF8_Pos                         (28)
#define  DMA_ISR_GIF8_Msk                         (0x01U << DMA_ISR_GIF8_Pos)  /*!<*/
#define  DMA_ISR_TCIF8_Pos                        (29)
#define  DMA_ISR_TCIF8_Msk                        (0x01U << DMA_ISR_TCIF8_Pos) /*!<*/
#define  DMA_ISR_HTIF8_Pos                        (30)
#define  DMA_ISR_HTIF8_Msk                        (0x01U << DMA_ISR_HTIF8_Pos) /*!<*/
#define  DMA_ISR_TEIF8_Pos                        (31)
#define  DMA_ISR_TEIF8_Msk                        (0x01U << DMA_ISR_TEIF8_Pos) /*!<*/

/**
  * @brief DMA_IFCR Register Bit Definition
  */
#define  DMA_IFCR_CGIF1_Pos                       (0)
#define  DMA_IFCR_CGIF1_Msk                       (0x01U << DMA_IFCR_CGIF1_Pos)  /*!<*/
#define  DMA_IFCR_CTCIF1_Pos                      (1)
#define  DMA_IFCR_CTCIF1_Msk                      (0x01U << DMA_IFCR_CTCIF1_Pos) /*!<*/
#define  DMA_IFCR_CHTIF1_Pos                      (2)
#define  DMA_IFCR_CHTIF1_Msk                      (0x01U << DMA_IFCR_CHTIF1_Pos) /*!<*/
#define  DMA_IFCR_CTEIF1_Pos                      (3)
#define  DMA_IFCR_CTEIF1_Msk                      (0x01U << DMA_IFCR_CTEIF1_Pos) /*!<*/
#define  DMA_IFCR_CGIF2_Pos                       (4)
#define  DMA_IFCR_CGIF2_Msk                       (0x01U << DMA_IFCR_CGIF2_Pos)  /*!<*/
#define  DMA_IFCR_CTCIF2_Pos                      (5)
#define  DMA_IFCR_CTCIF2_Msk                      (0x01U << DMA_IFCR_CTCIF2_Pos) /*!<*/
#define  DMA_IFCR_CHTIF2_Pos                      (6)
#define  DMA_IFCR_CHTIF2_Msk                      (0x01U << DMA_IFCR_CHTIF2_Pos) /*!<*/
#define  DMA_IFCR_CTEIF2_Pos                      (7)
#define  DMA_IFCR_CTEIF2_Msk                      (0x01U << DMA_IFCR_CTEIF2_Pos) /*!<*/
#define  DMA_IFCR_CGIF3_Pos                       (8)
#define  DMA_IFCR_CGIF3_Msk                       (0x01U << DMA_IFCR_CGIF3_Pos)  /*!<*/
#define  DMA_IFCR_CTCIF3_Pos                      (9)
#define  DMA_IFCR_CTCIF3_Msk                      (0x01U << DMA_IFCR_CTCIF3_Pos) /*!<*/
#define  DMA_IFCR_CHTIF3_Pos                      (10)
#define  DMA_IFCR_CHTIF3_Msk                      (0x01U << DMA_IFCR_CHTIF3_Pos) /*!<*/
#define  DMA_IFCR_CTEIF3_Pos                      (11)
#define  DMA_IFCR_CTEIF3_Msk                      (0x01U << DMA_IFCR_CTEIF3_Pos) /*!<*/
#define  DMA_IFCR_CGIF4_Pos                       (12)
#define  DMA_IFCR_CGIF4_Msk                       (0x01U << DMA_IFCR_CGIF4_Pos)  /*!<*/
#define  DMA_IFCR_CTCIF4_Pos                      (13)
#define  DMA_IFCR_CTCIF4_Msk                      (0x01U << DMA_IFCR_CTCIF4_Pos) /*!<*/
#define  DMA_IFCR_CHTIF4_Pos                      (14)
#define  DMA_IFCR_CHTIF4_Msk                      (0x01U << DMA_IFCR_CHTIF4_Pos) /*!<*/
#define  DMA_IFCR_CTEIF4_Pos                      (15)
#define  DMA_IFCR_CTEIF4_Msk                      (0x01U << DMA_IFCR_CTEIF4_Pos) /*!<*/
#define  DMA_IFCR_CGIF5_Pos                       (16)
#define  DMA_IFCR_CGIF5_Msk                       (0x01U << DMA_IFCR_CGIF5_Pos)  /*!<*/
#define  DMA_IFCR_CTCIF5_Pos                      (17)
#define  DMA_IFCR_CTCIF5_Msk                      (0x01U << DMA_IFCR_CTCIF5_Pos) /*!<*/
#define  DMA_IFCR_CHTIF5_Pos                      (18)
#define  DMA_IFCR_CHTIF5_Msk                      (0x01U << DMA_IFCR_CHTIF5_Pos) /*!<*/
#define  DMA_IFCR_CTEIF5_Pos                      (19)
#define  DMA_IFCR_CTEIF5_Msk                      (0x01U << DMA_IFCR_CTEIF5_Pos) /*!<*/
#define  DMA_IFCR_CGIF6_Pos                       (20)
#define  DMA_IFCR_CGIF6_Msk                       (0x01U << DMA_IFCR_CGIF6_Pos)  /*!<*/
#define  DMA_IFCR_CTCIF6_Pos                      (21)
#define  DMA_IFCR_CTCIF6_Msk                      (0x01U << DMA_IFCR_CTCIF6_Pos) /*!<*/
#define  DMA_IFCR_CHTIF6_Pos                      (22)
#define  DMA_IFCR_CHTIF6_Msk                      (0x01U << DMA_IFCR_CHTIF6_Pos) /*!<*/
#define  DMA_IFCR_CTEIF6_Pos                      (23)
#define  DMA_IFCR_CTEIF6_Msk                      (0x01U << DMA_IFCR_CTEIF6_Pos) /*!<*/
#define  DMA_IFCR_CGIF7_Pos                       (24)
#define  DMA_IFCR_CGIF7_Msk                       (0x01U << DMA_IFCR_CGIF7_Pos)  /*!<*/
#define  DMA_IFCR_CTCIF7_Pos                      (25)
#define  DMA_IFCR_CTCIF7_Msk                      (0x01U << DMA_IFCR_CTCIF7_Pos) /*!<*/
#define  DMA_IFCR_CHTIF7_Pos                      (26)
#define  DMA_IFCR_CHTIF7_Msk                      (0x01U << DMA_IFCR_CHTIF7_Pos) /*!<*/
#define  DMA_IFCR_CTEIF7_Pos                      (27)
#define  DMA_IFCR_CTEIF7_Msk                      (0x01U << DMA_IFCR_CTEIF7_Pos) /*!<*/
#define  DMA_IFCR_CGIF8_Pos                       (28)
#define  DMA_IFCR_CGIF8_Msk                       (0x01U << DMA_IFCR_CGIF8_Pos)  /*!<*/
#define  DMA_IFCR_CTCIF8_Pos                      (29)
#define  DMA_IFCR_CTCIF8_Msk                      (0x01U << DMA_IFCR_CTCIF8_Pos) /*!<*/
#define  DMA_IFCR_CHTIF8_Pos                      (30)
#define  DMA_IFCR_CHTIF8_Msk                      (0x01U << DMA_IFCR_CHTIF8_Pos) /*!<*/
#define  DMA_IFCR_CTEIF8_Pos                      (31)
#define  DMA_IFCR_CTEIF8_Msk                      (0x01U << DMA_IFCR_CTEIF8_Pos) /*!<*/

/**
  * @brief DMA_CCR Register Bit Definition
  */
#define  DMA_CCR_EN_Pos                           (0)
#define  DMA_CCR_EN_Msk                           (0x01U << DMA_CCR_EN_Pos)      /*!<*/
#define  DMA_CCR_TCIE_Pos                         (1)
#define  DMA_CCR_TCIE_Msk                         (0x01U << DMA_CCR_TCIE_Pos)    /*!<*/
#define  DMA_CCR_HTIE_Pos                         (2)
#define  DMA_CCR_HTIE_Msk                         (0x01U << DMA_CCR_HTIE_Pos)    /*!<*/
#define  DMA_CCR_TEIE_Pos                         (3)
#define  DMA_CCR_TEIE_Msk                         (0x01U << DMA_CCR_TEIE_Pos)    /*!<*/
#define  DMA_CCR_DIR_Pos                          (4)
#define  DMA_CCR_DIR_Msk                          (0x01U << DMA_CCR_DIR_Pos)     /*!<*/
#define  DMA_CCR_CIRC_Pos                         (5)
#define  DMA_CCR_CIRC_Msk                         (0x01U << DMA_CCR_CIRC_Pos)    /*!<*/
#define  DMA_CCR_PINC_Pos                         (6)
#define  DMA_CCR_PINC_Msk                         (0x01U << DMA_CCR_PINC_Pos)    /*!<*/
#define  DMA_CCR_MINC_Pos                         (7)
#define  DMA_CCR_MINC_Msk                         (0x01U << DMA_CCR_MINC_Pos)    /*!<*/
#define  DMA_CCR_PSIZE_Pos                        (8)
#define  DMA_CCR_PSIZE_Msk                        (0x03U << DMA_CCR_PSIZE_Pos)   /*!<*/
#define  DMA_CCR_MSIZE_Pos                        (10)
#define  DMA_CCR_MSIZE_Msk                        (0x03U << DMA_CCR_MSIZE_Pos)   /*!<*/
#define  DMA_CCR_PL_Pos                           (12)
#define  DMA_CCR_PL_Msk                           (0x03U << DMA_CCR_PL_Pos)      /*!<*/
#define  DMA_CCR_MEM2MEM_Pos                      (14)
#define  DMA_CCR_MEM2MEM_Msk                      (0x01U << DMA_CCR_MEM2MEM_Pos) /*!<*/
#define  DMA_CCR_ARE_Pos                          (15)
#define  DMA_CCR_ARE_Msk                          (0x01U << DMA_CCR_ARE_Pos)     /*!<*/
#define  DMA_CCR_BURSTEN_Pos                      (16)
#define  DMA_CCR_BURSTEN_Msk                      (0x01U << DMA_CCR_BURSTEN_Pos) /*!<*/

/**
  * @brief DMA_CNDTR Register Bit Definition
  */
#define  DMA_CNDTR_NDT_Pos                        (0)
#define  DMA_CNDTR_NDT_Msk                        (0xFFFFU << DMA_CNDTR_NDT_Pos) /*!<*/

/**
  * @brief DMA_CPAR Register Bit Definition
  */
#define  DMA_CPAR_PA_Pos                          (0)
#define  DMA_CPAR_PA_Msk                          (0xFFFFFFFFU << DMA_CPAR_PA_Pos) /*!<*/

/**
  * @brief DMA_CMAR Register Bit Definition
  */
#define  DMA_CMAR_MA_Pos                          (0)
#define  DMA_CMAR_MA_Msk                          (0xFFFFFFFFU << DMA_CMAR_MA_Pos) /*!<*/

#endif

