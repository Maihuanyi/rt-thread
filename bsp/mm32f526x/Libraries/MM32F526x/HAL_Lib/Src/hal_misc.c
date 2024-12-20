/***********************************************************************************************************************
    @file     hal_misc.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE MSIC FIRMWARE FUNCTIONS.
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
#define _HAL_MISC_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_misc.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup NVIC
  * @{
  */

/** @defgroup NVIC_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup NVIC_Private_Functions
  * @{
  */

/**
  * @brief  Configures the priority grouping: pre-emption priority and subpriority.
  * @param  NVIC_PriorityGroup: specifies the priority grouping bits length.
  *   This parameter can be one of the following values:
  *     @arg NVIC_PriorityGroup_0: 0 bits for pre-emption priority
  *                                4 bits for subpriority
  *     @arg NVIC_PriorityGroup_1: 1 bits for pre-emption priority
  *                                3 bits for subpriority
  *     @arg NVIC_PriorityGroup_2: 2 bits for pre-emption priority
  *                                2 bits for subpriority
  *     @arg NVIC_PriorityGroup_3: 3 bits for pre-emption priority
  *                                1 bits for subpriority
  *     @arg NVIC_PriorityGroup_4: 4 bits for pre-emption priority
  *                                0 bits for subpriority
  * @retval None
  */
void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup)
{
    /* Set the PRIGROUP[10:8] bits according to NVIC_PriorityGroup value */
    SCB->AIRCR = AIRCR_VECTKEY_MASK | NVIC_PriorityGroup;
}

/**
  * @brief  Initializes the NVIC peripheral according to the specified
  *         parameters in the NVIC_InitStruct.
  * @param  NVIC_InitStruct: pointer to a NVIC_InitTypeDef structure that contains
  *         the configuration information for the specified NVIC peripheral.
  * @retval None
  */
void NVIC_Init(NVIC_InitTypeDef *NVIC_InitStruct)
{
    uint32_t tmppriority = 0x00, tmppre = 0x00, tmpsub = 0x00;

    if (NVIC_InitStruct->NVIC_IRQChannelCmd != DISABLE)
    {
    /* Compute the Corresponding IRQ Priority --------------------------------*/    
    tmppriority = ((SCB->AIRCR) & (uint32_t)0x700)>> 0x08;
    tmppre = tmppriority + 1;
    tmpsub = 0xFF >> (0x07 - tmppriority);

    tmppriority = (uint32_t)NVIC_InitStruct->NVIC_IRQChannelPreemptionPriority << tmppre;
    tmppriority |=  NVIC_InitStruct->NVIC_IRQChannelSubPriority & tmpsub;
    tmppriority = tmppriority << 0x04;
        
    NVIC->IPR[NVIC_InitStruct->NVIC_IRQChannel] = tmppriority;
    
    /* Enable the Selected IRQ Channels --------------------------------------*/
    NVIC->ISER[NVIC_InitStruct->NVIC_IRQChannel >> 0x05] =
      (uint32_t)0x01 << (NVIC_InitStruct->NVIC_IRQChannel & (uint8_t)0x1F);
  }
  else
  {
    /* Disable the Selected IRQ Channels -------------------------------------*/
    NVIC->ICER[NVIC_InitStruct->NVIC_IRQChannel >> 0x05] =
      (uint32_t)0x01 << (NVIC_InitStruct->NVIC_IRQChannel & (uint8_t)0x1F);
  }
}

/**
  * @brief  Sets the vector table location and Offset.
  * @param  NVIC_VectTab: specifies if the vector table is in RAM or FLASH memory.
  *   This parameter can be one of the following values:
  *     @arg NVIC_VectTab_RAM
  *     @arg NVIC_VectTab_FLASH
  * @param  Offset: Vector Table base offset field. This value must be a multiple of 0x200.
  * @retval None
  */
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset)
{
    SCB->VTOR = NVIC_VectTab | (Offset & (uint32_t)0x1FFFFF80);
}

/**
  * @brief  SysTick clock source configuration.
  * @param  systick_clk_source
  *         This parameter can be any combination of the following values:
  *    @arg SysTick_CLKSource_EXTCLK
  *    @arg SysTick_CLKSource_HCLK
  * @retval None.
  */
void SysTick_CLKSourceConfig(uint32_t systick_clk_source)
{
    (systick_clk_source == SysTick_CLKSource_HCLK) ? \
    (SysTick->CTRL |= SysTick_CLKSource_HCLK) :      \
    (SysTick->CTRL &= ~SysTick_CLKSource_HCLK);
}

/**
  * @brief  System low power mode configuration.
  * @param  low_power_mode
  *         This parameter can be any combination of the following values:
  *    @arg NVIC_LP_SEVONPEND
  *    @arg NVIC_LP_SLEEPDEEP
  *    @arg NVIC_LP_SLEEPONEXIT
  * @param  state: new state of the low power mode.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void NVIC_SystemLPConfig(uint8_t low_power_mode, FunctionalState state)
{
    (state) ?                      \
    (SCB->SCR |= low_power_mode) : \
    (SCB->SCR &= ~(uint32_t)low_power_mode);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
