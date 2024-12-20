/***********************************************************************************************************************
    @file     hal_rcc.c
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
#define _HAL_RCC_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_rcc.h"

uint8_t AHBPreTable[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9
};
uint8_t APBPreTable[] =
{
    0, 0, 0, 0, 1, 2, 3, 4
};

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup RCC_HAL
  * @{
  */

/** @addtogroup RCC_Exported_Functions
  * @{
  */

/**
  * @brief  Resets the RCC clock configuration to default state.
  * @param  None.
  * @retval None.
  */
void RCC_DeInit(void)
{
    /* Set HSION bit */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);

    /* Reset SW, HPRE, PPRE1, PPRE2 and MCO bits */
    RCC->CFGR &= ~RCC_CFGR_SW_Msk;
    RCC->CFGR &= ~RCC_CFGR_HPRE_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE1_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE2_Msk;
    RCC->CFGR &= ~RCC_CFGR_MCO_Msk;

    /* Reset HSEON, CSSON and PLLON bits */
    RCC->CR &= ~RCC_CR_HSEON_Msk;
    RCC->CR &= ~RCC_CR_CSSON_Msk;
    RCC->CR &= ~RCC_CR_PLL1ON_Msk;
    RCC->CR &= ~RCC_CR_PLL2ON_Msk;

    /* Reset HSEBYP bit */
    RCC->CR &= ~RCC_CR_HSEBYP_Msk;
}

/**
  * @brief  Configures the External High Speed oscillator (HSE).
  * @param  hsesource: specifies the new config of HSE.
  *         This parameter can be one of the following values:
  * @arg    RCC_HSE_OFF: HSE oscillator OFF
  * @arg    RCC_HSE_ON: HSE oscillator ON
  * @arg    RCC_HSE_Bypass: HSE oscillator bypassed with external clock
  * @retval None.
  */
void RCC_HSEConfig(uint32_t hsesource)
{
    RCC->CR &= ~(RCC_CR_HSEBYP_Msk | RCC_CR_HSEON_Msk);

    if (RCC_HSE_Bypass == hsesource)
    {
        RCC->CR |= (0x01U << RCC_CR_HSEBYP_Pos);
        RCC->CR |= (0x01U << RCC_CR_HSEON_Pos);
    }
    else if (RCC_HSE_ON == hsesource)
    {
        RCC->CR |= (0x01U << RCC_CR_HSEON_Pos);
    }
}

/**
  * @brief  Checks whether the specified RCC flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    RCC_FLAG_HSIRDY: HSI oscillator clock ready
  * @arg    RCC_FLAG_HSERDY: HSE oscillator clock ready
  * @arg    RCC_FLAG_PLL1RDY: PLL clock ready
  * @arg    RCC_FLAG_PLL2RDY: PLL clock ready
  * @arg    RCC_FLAG_LSERDY: LSE oscillator clock ready
  * @arg    RCC_FLAG_LSIRDY: LSI oscillator clock ready
  * @arg    RCC_FLAG_PINRST: Pin reset
  * @arg    RCC_FLAG_PORRST: POR/PDR reset
  * @arg    RCC_FLAG_SFTRST: Software reset
  * @arg    RCC_FLAG_IWDGRST: Independent Watchdog reset
  * @arg    RCC_FLAG_WWDGRST: Window Watchdog reset
  * @retval The new state of flag (SET or RESET).
  */
FlagStatus RCC_GetFlagStatus(uint8_t flag)
{
    uint32_t tmp = 0, i = 0;
    uint32_t statusreg = 0;

    tmp = flag >> 5;

    if (tmp == 1)                      /* The flag to check is in CR register */
    {
        statusreg = RCC->CR;
    }
    else if (tmp == 2)                 /* The flag to check is in BDCR register */
    {
        statusreg = RCC->BDCR;

        for (i = 0; i < 30000; i++)
        {
            __NOP();
        }
    }
    else                               /* The flag to check is in CSR register */
    {
        statusreg = RCC->CSR;
    }

    /* Get the flag position */
    tmp = flag & 0x1F;

    /* Return the flag status */
    return ((statusreg & ((uint32_t)1 << tmp)) ? SET : RESET);
}

/**
  * @brief  Waits for HSE start-up.
  * @param  None.
  * @retval An ErrorStatus enumuration value:
  *         - SUCCESS: HSE oscillator is stable and ready to use
  *         - ERROR: HSE oscillator not yet ready
  */
ErrorStatus RCC_WaitForHSEStartUp(void)
{
    uint32_t StartUpCounter = 0;
    FlagStatus HSEStatus    = RESET;

    do
    {
        HSEStatus = RCC_GetFlagStatus(RCC_FLAG_HSERDY);
        StartUpCounter++;
    }
    while((HSEStatus == RESET) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    return ((RCC_GetFlagStatus(RCC_FLAG_HSERDY) != RESET) ? SUCCESS : ERROR);
}

/**
  * @brief  Enables or disables the Internal High Speed oscillator (HSI).
  * @param  state: new state of the HSI.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_HSICmd(FunctionalState state)
{
    (state) ?                                  \
    (RCC->CR |= (0x01U << RCC_CR_HSION_Pos)) : \
    (RCC->CR &= ~(0x01U << RCC_CR_HSION_Pos));
}

/**
  * @brief  Configures the PLL1 clock source and multiplication factor.
  *   This function must be used only when the PLL is disabled.
  * @param pll1_src:
  *    @arg    RCC_PLL1Source_HSI
  *    @arg    RCC_PLL1Source_HSE
  * @param pll_pdiv: Pre-divide Factor
  * @param pll_mul: Multiplication Factor
  * @param pll_div: Divide Factor
  * @retval : None
  */
void RCC_PLL1Config(uint32_t pll_src, uint32_t pll_pdiv, uint32_t pll_mul, uint32_t pll_div)
{
    MODIFY_REG(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1MUL_Msk, pll_mul << RCC_PLL1CFGR_PLL1MUL_Pos);
    MODIFY_REG(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1DIV_Msk, pll_div << RCC_PLL1CFGR_PLL1DIV_Pos);
    MODIFY_REG(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1SRC_Msk, pll_src << RCC_PLL1CFGR_PLL1SRC_Pos);
}

/**
  * @brief  Configures the PLL2 clock source and multiplication factor.
  *   This function must be used only when the PLL is disabled.
  * @param pll_src:
  *    @arg    RCC_PLL2Source_HSI
  *    @arg    RCC_PLL2Source_HSE
  * @param pll_pdiv: Pre-divide Factor
  * @param pll_mul: Multiplication Factor
  * @param pll_div: Divide Factor
  * @retval : None
  */
void RCC_PLL2Config(uint32_t pll_src, uint32_t pll_pdiv, uint32_t pll_mul, uint32_t pll_div)
{
    MODIFY_REG(RCC->PLL2CFGR, RCC_PLL2CFGR_PLL2PDIV_Msk, pll_pdiv << RCC_PLL2CFGR_PLL2PDIV_Pos);
    MODIFY_REG(RCC->PLL2CFGR, RCC_PLL2CFGR_PLL2MUL_Msk, pll_mul << RCC_PLL2CFGR_PLL2MUL_Pos);
    MODIFY_REG(RCC->PLL2CFGR, RCC_PLL2CFGR_PLL2DIV_Msk, pll_div << RCC_PLL2CFGR_PLL2DIV_Pos);
    MODIFY_REG(RCC->PLL2CFGR, RCC_PLL2CFGR_PLL2SRC_Msk, pll_src << RCC_PLL2CFGR_PLL2SRC_Pos);
}

/**
  * @brief  Enables or disables the PLL1.
  *   The PLL can not be disabled if it is used as system clock.
  * @param  state: new state of the PLL1.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_PLL1Cmd(FunctionalState state)
{
    (state) ?                                   \
    (RCC->CR |= (0x01U << RCC_CR_PLL1ON_Pos)) : \
    (RCC->CR &= ~(0x01U << RCC_CR_PLL1ON_Pos));
}

/**
  * @brief  Enables or disables the PLL2.
  *   The PLL can not be disabled if it is used as system clock.
  * @param  state: new state of the PLL2.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_PLL2Cmd(FunctionalState state)
{
    (state) ?                                   \
    (RCC->CR |= (0x01U << RCC_CR_PLL2ON_Pos)) : \
    (RCC->CR &= ~(0x01U << RCC_CR_PLL2ON_Pos));
}

/**
  * @brief  Configures the system clock (SYSCLK).
  * @param  sys_clk_source: specifies the clock source used as system
  *         clock. This parameter can be one of the following values:
  *     @arg    RCC_SYSCLKSource_HSI: specifies HSI as system clock
  *     @arg    RCC_SYSCLKSource_HSE: specifies HSE as system clock
  *     @arg    RCC_SYSCLKSource_PLL1: specifies PLL as system clock
  *     @arg    RCC_SYSCLKSource_LSI: specifies LSI as system clock
  * @retval None.
  */
void RCC_SYSCLKConfig(uint32_t sys_clk_source)
{
    MODIFY_REG(RCC->CFGR, RCC_CFGR_SW_Msk, sys_clk_source);
}

/**
  * @brief  Returns the clock source used as system clock.
  * @param  None.
  * @retval The clock source used as system clock. The returned value can
  *         be one of the following:
  *         - 0x00: HSI used as system clock
  *         - 0x04: HSE used as system clock
  *         - 0x08: PLL1 used as system clock
  *         - 0x0C: LSI used as system clock
  */
uint8_t RCC_GetSYSCLKSource(void)
{
    return ((RCC->CFGR & RCC_CFGR_SWS_Msk));
}

/**
  * @brief  Configures the HSI clock.
  * @param  clk: defines the HSI clock divider.
  *         This parameter can be one of the following values:
  * @arg    RCC_HSI_Div1
  * @arg    RCC_HSI_Div2
  * @arg    RCC_HSI_Div4
  * @arg    RCC_HSI_Div8
  * @arg    RCC_HSI_Div16
  * @arg    RCC_HSI_Div32
  * @arg    RCC_HSI_Div64
  * @arg    RCC_HSI_Div128
  * @retval None.
  */
void RCC_HSIConfig(uint32_t clk)
{
    MODIFY_REG(RCC->CR, RCC_CR_HSIDIV_Msk, clk);
}

/**
  * @brief  Configures the AHB clock (hclk).
  * @param  sys_clk: defines the AHB clock divider. This clock is derived
  *                    from the system clock (SYSCLK).
  *         This parameter can be one of the following values:
  * @arg    RCC_SYSCLK_Div1: AHB clock = SYSCLK
  * @arg    RCC_SYSCLK_Div2: AHB clock = SYSCLK/2
  * @arg    RCC_SYSCLK_Div4: AHB clock = SYSCLK/4
  * @arg    RCC_SYSCLK_Div8: AHB clock = SYSCLK/8
  * @arg    RCC_SYSCLK_Div16: AHB clock = SYSCLK/16
  * @arg    RCC_SYSCLK_Div64: AHB clock = SYSCLK/64
  * @arg    RCC_SYSCLK_Div128: AHB clock = SYSCLK/128
  * @arg    RCC_SYSCLK_Div256: AHB clock = SYSCLK/256
  * @arg    RCC_SYSCLK_Div512: AHB clock = SYSCLK/512
  * @retval None.
  */
void RCC_HCLKConfig(uint32_t clk)
{
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE_Msk, clk);
}

/**
  * @brief  Configures the Low Speed APB clock (pclk1).
  * @param  hclk: defines the APB1 clock divider. This clock is derived from
  *                  the AHB clock (hclk).
  *         This parameter can be one of the following values:
  * @arg    RCC_HCLK_Div1: APB1 clock = hclk
  * @arg    RCC_HCLK_Div2: APB1 clock = hclk/2
  * @arg    RCC_HCLK_Div4: APB1 clock = hclk/4
  * @arg    RCC_HCLK_Div8: APB1 clock = hclk/8
  * @arg    RCC_HCLK_Div16: APB1 clock = hclk/16
  * @retval None.
  */
void RCC_PCLK1Config(uint32_t clk)
{
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1_Msk, clk << RCC_CFGR_PPRE1_Pos);
}

/**
  * @brief  Configures the High Speed APB clock (pclk2).
  * @param  hclk: defines the APB2 clock divider. This clock is derived from
  *                  the AHB clock (hclk).
  *         This parameter can be one of the following values:
  * @arg    RCC_HCLK_Div1: APB2 clock = hclk
  * @arg    RCC_HCLK_Div2: APB2 clock = hclk/2
  * @arg    RCC_HCLK_Div4: APB2 clock = hclk/4
  * @arg    RCC_HCLK_Div8: APB2 clock = hclk/8
  * @arg    RCC_HCLK_Div16: APB2 clock = hclk/16
  * @retval None.
  */
void RCC_PCLK2Config(uint32_t clk)
{
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2_Msk, clk << RCC_CFGR_PPRE2_Pos);
}

/**
  * @brief  Enables or disables the specified RCC interrupts.
  * @param  it: specifies the RCC interrupt sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  * @arg RCC_IT_LSIRDY: LSI ready interrupt
  * @arg RCC_IT_LSERDY: LSE ready interrupt
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_HSERDY: HSE ready interrupt
  * @arg RCC_IT_PLL1RDY: PLL1 ready interrupt
  * @arg RCC_IT_PLL2RDY: PLL2 ready interrupt
  * @param  state: new state of the specified RCC interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_ITConfig(uint8_t it, FunctionalState state)
{
    (state) ?                                    \
    (RCC->CIR |= (it << RCC_CIR_LSIRDYIE_Pos)) : \
    (RCC->CIR &= ~(it << RCC_CIR_LSIRDYIE_Pos));
}

/**
  * @brief  Checks whether the specified RCC interrupt has occurred or not.
  * @param  it: specifies the RCC interrupt source to check.
  *   This parameter can be one of the following values:
  * @arg RCC_IT_LSIRDY: LSI ready interrupt
  * @arg RCC_IT_LSERDY: LSE ready interrupt
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_HSERDY: HSE ready interrupt
  * @arg RCC_IT_PLL1RDY: PLL1 ready interrupt
  * @arg RCC_IT_PLL2RDY: PLL2 ready interrupt
  * @retval The new state of it (SET or RESET).
  */
ITStatus RCC_GetITStatus(uint8_t it)
{
    return ((ITStatus)(RCC->CIR & (it << RCC_CIR_LSIRDYF_Pos)));
}

/**
  * @brief  Clears the RCC interrupt pending bits.
  * @param  it: specifies the interrupt pending bit to clear.
  *   This parameter can be any combination of the following values:
  * @arg RCC_IT_LSIRDY: LSI ready interrupt
  * @arg RCC_IT_LSERDY: LSE ready interrupt
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_HSERDY: HSE ready interrupt
  * @arg RCC_IT_PLL1RDY: PLL1 ready interrupt
  * @arg RCC_IT_PLL2RDY: PLL2 ready interrupt
  * @retval None.
  */
void RCC_ClearITPendingBit(uint8_t it)
{
    RCC->CIR |= (it << RCC_CIR_LSIRDYC_Pos);
}

/**
  * @brief  Configures the External Low Speed oscillator (LSE).
  * @param  rcc_lse: specifies the new state of the LSE.
  *         This parameter can be one of the following values:
  * @arg    RCC_LSE_OFF: LSE oscillator OFF
  * @arg    RCC_LSE_ON: LSE oscillator ON
  * @arg    RCC_LSE_Bypass: LSE oscillator bypassed with external clock
  * @retval None.
  */
void RCC_LSEConfig(uint32_t rcc_lse)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0;

    tmpreg = RCC->BDCR;

    for (i = 0; i < 30000; i++)
    {
        __NOP();
    }

    tmpreg &= ~RCC_BDCR_LSEON_Msk;

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }

    tmpreg &= ~RCC_BDCR_LSEBYP_Msk;

    if (rcc_lse == RCC_LSE_Bypass)
    {
        tmpreg |= RCC_LSE_Bypass;
        tmpreg |= RCC_LSE_ON;
    }
    else
    {
        tmpreg |= rcc_lse;
    }

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Enables or disables the Internal Low Speed oscillator (LSI).
  *         LSI can not be disabled if the IWDG is running.
  * @param  state: new state of the LSI.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_LSICmd(FunctionalState state)
{
    (state) ?                                                                     \
    (RCC->CSR |= ((0x01U << RCC_CSR_LSION_Pos) | (0x01U << RCC_CSR_LSIOE_Pos))) : \
    (RCC->CSR &= ~((0x01U << RCC_CSR_LSION_Pos) | (0x01U << RCC_CSR_LSIOE_Pos)));
}

/**
  * @brief  Configures the RTC clock (RTCCLK).
  *         Once the RTC clock is selected it can be changed unless the
  *         Backup domain is reset.
  * @param  rtc_clk_src: specifies the RTC clock source.
  *         This parameter can be one of the following values:
  * @arg    RCC_RTCCLKSource_LSE: LSE selected as RTC clock
  * @arg    RCC_RTCCLKSource_LSI: LSI selected as RTC clock
  * @arg    RCC_RTCCLKSource_HSE_Div128: HSE clock divided by 128
  *         selected as RTC clock
  * @retval None.
  */
void RCC_RTCCLKConfig(uint32_t rtc_clk_src)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0;

    tmpreg = RCC->BDCR;

    for (i = 0; i < 30000; i++)
    {
        __NOP();
    }

    tmpreg |= rtc_clk_src;

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Enables or disables the RTC clock.
  *         This function must be used only after the RTC clock was
  *         selected using the RCC_RTCCLKConfig function.
  * @param  state: new state of the RTC clock.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_RTCCLKCmd(FunctionalState state)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0;

    tmpreg = RCC->BDCR;

    for (i = 0; i < 30000; i++)
    {
        __NOP();
    }

    (state) ?                                   \
    (tmpreg |= (0x01U << RCC_BDCR_RTCEN_Pos)) : \
    (tmpreg &= ~(0x01U << RCC_BDCR_RTCEN_Pos));

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Returns the frequency of different on chip clocks.
  * @param  clk: pointer to a RCC_ClocksTypeDef structure which
  *   will hold the clocks frequency.
  * @retval None.
  */
void RCC_GetClocksFreq(RCC_ClocksTypeDef *clk)
{
    uint32_t tmp = 0, pll_pdiv = 0, pll_mul = 0, pll_div = 0;
    uint8_t  divider = 0, pllsource = 0;

    /* Get SYSCLK source -------------------------------------------------------*/
    tmp = RCC->CFGR & RCC_CFGR_SWS_Msk;

    switch (tmp)
    {
        case 0x00:                     /* HSI used as system clock */
            divider = (uint8_t)((RCC->CR & RCC_CR_HSIDIV_Msk) >> RCC_CR_HSIDIV_Pos);
            clk->SYSCLK_Frequency = HSI_VALUE >> divider;
            break;

        case 0x04:                     /* HSE used as system clock */
            clk->SYSCLK_Frequency = HSE_VALUE;
            break;

        case 0x08:                     /* PLL1 used as system clock */
            pll_mul  = (RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1MUL_Msk) >> RCC_PLL1CFGR_PLL1MUL_Pos;
            pll_div  = (RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1DIV_Msk) >> RCC_PLL1CFGR_PLL1DIV_Pos;

            pllsource = (uint8_t)((RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1SRC_Msk) >> RCC_PLL1CFGR_PLL1SRC_Pos);

            if (pllsource == 0x00)     /* HSI oscillator clock as PLL1 clock entry */
            {
                divider = (uint8_t)((RCC->CR & RCC_CR_HSIDIV_Msk) >> RCC_CR_HSIDIV_Pos);

                clk->SYSCLK_Frequency = (HSI_VALUE >> divider) / (pll_pdiv + 1) / (pll_div + 1) * (pll_mul + 1);
            }
            else                       /* HSE selected as PLL1 clock entry */
            {
                clk->SYSCLK_Frequency = HSE_VALUE / (pll_pdiv + 1) / (pll_div + 1) * (pll_mul + 1);
            }

            break;

        case 0x0C:                     /* LSI used as system clock */
            clk->SYSCLK_Frequency = LSI_VALUE;
            break;

        default:
            clk->SYSCLK_Frequency = HSI_VALUE;
            break;
    }

    /* Compute HCLK, PCLK1, PCLK2 and ADCCLK clocks frequencies ----------------*/

    /* Get HCLK prescaler */
    tmp     = (RCC->CFGR & RCC_CFGR_HPRE_Msk) >> RCC_CFGR_HPRE_Pos;
    divider = AHBPreTable[tmp];
    /* HCLK clock frequency */
    clk->HCLK_Frequency = clk->SYSCLK_Frequency >> divider;

    /* Get PCLK1 prescaler */
    tmp     = (RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos;
    divider = APBPreTable[tmp];
    /* PCLK1 clock frequency */
    clk->PCLK1_Frequency = clk->HCLK_Frequency >> divider;

    /* Get PCLK2 prescaler */
    tmp     = (RCC->CFGR & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos;
    divider = APBPreTable[tmp];
    /* PCLK2 clock frequency */
    clk->PCLK2_Frequency = clk->HCLK_Frequency >> divider;
}

/**
  * @brief  Enables or disables the AHB peripheral clock.
  * @param  ahb_periph: specifies the AHB peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_AHBPeriph_GPIOA
  *   @arg RCC_AHBPeriph_GPIOB
  *   @arg RCC_AHBPeriph_GPIOC
  *   @arg RCC_AHBPeriph_GPIOD
  *   @arg RCC_AHBPeriph_GPIOE
  *   @arg RCC_AHBPeriph_GPIOF
  *   @arg RCC_AHBPeriph_GPIOG
  *   @arg RCC_AHBPeriph_GPIOH
  *   @arg RCC_AHBPeriph_GPIOI
  *   @arg RCC_AHBPeriph_CRC
  *   @arg RCC_AHBPeriph_CORDIC
  *   @arg RCC_AHBPeriph_DMA1
  *   @arg RCC_AHBPeriph_DMA2
  *   @arg RCC_AHBPeriph_USB_FS
  *   @arg RCC_AHBPeriph_FSMC
  *   @arg RCC_AHBPeriph_QSPI
  * @param  state: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_AHBPeriphClockCmd(uint32_t ahb_periph, FunctionalState state)
{
    (state) ?                     \
    (RCC->AHBENR |= ahb_periph) : \
    (RCC->AHBENR &= ~ahb_periph);
}

/**
  * @brief  Enables or disables the High Speed APB (APB2) peripheral clock.
  * @param  apb2_periph: specifies the APB2 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_APB2Periph_TIM1
  *   @arg RCC_APB2Periph_TIM8
  *   @arg RCC_APB2Periph_UART1
  *   @arg RCC_APB2Periph_UART6
  *   @arg RCC_APB2Periph_ADC1
  *   @arg RCC_APB2Periph_ADC2
  *   @arg RCC_APB2Periph_SPI1
  *   @arg RCC_APB2Periph_SYSCFG
  *   @arg RCC_APB2Periph_COMP
  *   @arg RCC_APB2Periph_FLEXCAN2
  *   @arg RCC_APB2Periph_MDS
  *   @arg RCC_APB2Periph_LPTIM
  *   @arg RCC_APB2Periph_LPUART
  * @param  state: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_APB2PeriphClockCmd(uint32_t apb2_periph, FunctionalState state)
{
    (state) ?                       \
    (RCC->APB2ENR |= apb2_periph) : \
    (RCC->APB2ENR &= ~apb2_periph);
}

/**
  * @brief  Enables or disables the Low Speed APB (APB1) peripheral clock.
  * @param  apb1_periph: specifies the APB1 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_APB1Periph_TIM2
  *   @arg RCC_APB1Periph_TIM3
  *   @arg RCC_APB1Periph_TIM4
  *   @arg RCC_APB1Periph_TIM5
  *   @arg RCC_APB1Periph_TIM6
  *   @arg RCC_APB1Periph_TIM7
  *   @arg RCC_APB1Periph_WWDG
  *   @arg RCC_APB1Periph_SPI2
  *   @arg RCC_APB1Periph_SPI3
  *   @arg RCC_APB1Periph_UART2
  *   @arg RCC_APB1Periph_UART3
  *   @arg RCC_APB1Periph_UART4
  *   @arg RCC_APB1Periph_UART5
  *   @arg RCC_APB1Periph_I2C1
  *   @arg RCC_APB1Periph_I2C2
  *   @arg RCC_APB1Periph_CRS
  *   @arg RCC_APB1Periph_FLEXCAN1
  *   @arg RCC_APB1Periph_BKP
  *   @arg RCC_APB1Periph_PWRDBG
  *   @arg RCC_APB1Periph_DAC
  *   @arg RCC_APB1Periph_UART7
  * @param  state: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_APB1PeriphClockCmd(uint32_t apb1_periph, FunctionalState state)
{
    (state) ?                       \
    (RCC->APB1ENR |= apb1_periph) : \
    (RCC->APB1ENR &= ~apb1_periph);
}

/**
  * @brief  Forces or releases the AHB peripheral  peripheral reset.
  * @param  ahb_periph: specifies the AHB peripheral
  *   This parameter can be any combination of the following values:
  *   @arg RCC_AHBPeriph_GPIOA
  *   @arg RCC_AHBPeriph_GPIOB
  *   @arg RCC_AHBPeriph_GPIOC
  *   @arg RCC_AHBPeriph_GPIOD
  *   @arg RCC_AHBPeriph_GPIOE
  *   @arg RCC_AHBPeriph_GPIOF
  *   @arg RCC_AHBPeriph_GPIOG
  *   @arg RCC_AHBPeriph_GPIOH
  *   @arg RCC_AHBPeriph_GPIOI
  *   @arg RCC_AHBPeriph_CRC
  *   @arg RCC_AHBPeriph_CORDIC
  *   @arg RCC_AHBPeriph_DMA1
  *   @arg RCC_AHBPeriph_DMA2
  *   @arg RCC_AHBPeriph_USB_FS
  *   @arg RCC_AHBPeriph_FSMC
  *   @arg RCC_AHBPeriph_QSPI
  * @param  state: new state of the specified peripheral reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_AHBPeriphResetCmd(uint32_t ahb_periph, FunctionalState state)
{
    (state) ?                      \
    (RCC->AHBRSTR |= ahb_periph) : \
    (RCC->AHBRSTR &= ~ahb_periph);
}

/**
  * @brief  Forces or releases High Speed APB (APB2) peripheral reset.
  * @param  apb2_periph: specifies the APB2 peripheral to reset.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_APB2Periph_TIM1
  *   @arg RCC_APB2Periph_TIM8
  *   @arg RCC_APB2Periph_UART1
  *   @arg RCC_APB2Periph_UART6
  *   @arg RCC_APB2Periph_ADC1
  *   @arg RCC_APB2Periph_ADC2
  *   @arg RCC_APB2Periph_SPI1
  *   @arg RCC_APB2Periph_SYSCFG
  *   @arg RCC_APB2Periph_COMP
  *   @arg RCC_APB2Periph_FLEXCAN2
  *   @arg RCC_APB2Periph_MDS
  *   @arg RCC_APB2Periph_LPTIM
  *   @arg RCC_APB2Periph_LPUART
  * @param  state: new state of the specified peripheral reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_APB2PeriphResetCmd(uint32_t apb2_periph, FunctionalState state)
{
    (state) ?                        \
    (RCC->APB2RSTR |= apb2_periph) : \
    (RCC->APB2RSTR &= ~apb2_periph);
}

/**
  * @brief  Forces or releases Low Speed APB (APB1) peripheral reset.
  * @param  apb1_periph: specifies the APB1 peripheral to reset.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_APB1Periph_TIM2
  *   @arg RCC_APB1Periph_TIM3
  *   @arg RCC_APB1Periph_TIM4
  *   @arg RCC_APB1Periph_TIM5
  *   @arg RCC_APB1Periph_TIM6
  *   @arg RCC_APB1Periph_TIM7
  *   @arg RCC_APB1Periph_WWDG
  *   @arg RCC_APB1Periph_SPI2
  *   @arg RCC_APB1Periph_SPI3
  *   @arg RCC_APB1Periph_UART2
  *   @arg RCC_APB1Periph_UART3
  *   @arg RCC_APB1Periph_UART4
  *   @arg RCC_APB1Periph_UART5
  *   @arg RCC_APB1Periph_I2C1
  *   @arg RCC_APB1Periph_I2C2
  *   @arg RCC_APB1Periph_CRS
  *   @arg RCC_APB1Periph_FLEXCAN1
  *   @arg RCC_APB1Periph_BKP
  *   @arg RCC_APB1Periph_PWRDBG
  *   @arg RCC_APB1Periph_DAC
  *   @arg RCC_APB1Periph_UART7
  * @param  state: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_APB1PeriphResetCmd(uint32_t apb1_periph, FunctionalState state)
{
    (state) ?                        \
    (RCC->APB1RSTR |= apb1_periph) : \
    (RCC->APB1RSTR &= ~apb1_periph);
}

/**
  * @brief  Enables or disables the Clock Security System.
  * @param  state: new state of the Clock Security System..
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_ClockSecuritySystemCmd(FunctionalState state)
{
    (state) ?                                  \
    (RCC->CR |= (0x01U << RCC_CR_CSSON_Pos)) : \
    (RCC->CR &= ~(0x01U << RCC_CR_CSSON_Pos));
}

/**
  * @brief  Selects the clock source to output on MCO pin.
  * @param  mco_src: specifies the clock source to output.
  *   This parameter can be one of the following values:
  * @arg RCC_MCO_NoClock
  * @arg RCC_MCO_LSI
  * @arg RCC_MCO_LSE
  * @arg RCC_MCO_SYSCLK
  * @arg RCC_MCO_HSI
  * @arg RCC_MCO_HSE
  * @arg RCC_MCO_PLL1
  * @arg RCC_MCO_PLL2
  * @retval None.
  */
void RCC_MCOConfig(uint32_t mco_src)
{
    MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO_Msk, mco_src);
}

/**
  * @brief  Configure the predivision coefficient of the MCO clock.
  * @param  pre_sel: Select MCO predivision coefficient.
  *   This parameter can be one of the following values:
  * @arg RCC_MCO_Div1
  * @arg RCC_MCO_Div2
  * @arg RCC_MCO_Div4
  * @arg RCC_MCO_Div8
  * @arg RCC_MCO_Div16
  * @arg RCC_MCO_Div64
  * @arg RCC_MCO_Div128
  * @arg RCC_MCO_Div256
  * @arg RCC_MCO_Div512
  * @retval None.
  */
void RCC_MCOPrescalerConfig(uint32_t pre_sel)
{
    MODIFY_REG(RCC->CFGR2, RCC_CFGR2_MCO_PRE_Msk, pre_sel);
}

/**
  * @brief  Clears the RCC reset flags.
  * @param  None.
  * @retval None.
  */
void RCC_ClearFlag(void)
{
    RCC->CSR |= (1 << RCC_CSR_RMVF_Pos);
}

/**
  * @brief  Forces or releases the Backup domain reset.
  * @param  state: new state of the Backup domain reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RCC_BackupResetCmd(FunctionalState state)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0;

    tmpreg = RCC->BDCR;

    for (i = 0; i < 30000; i++)
    {
        __NOP();
    }

    (state) ?                                   \
    (tmpreg |= (0x01U << RCC_BDCR_BDRST_Pos)) : \
    (tmpreg &= ~(0x01U << RCC_BDCR_BDRST_Pos));

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Configure the frequency division coefficient of APB1_HV output clock
  * @param  div_sel: Select the frequency division coefficient.
  *   This parameter can be one of the following values:
  * @arg RCC_APB1HV_OutputPre_Div1
  * @arg RCC_APB1HV_OutputPre_Div8
  * @arg RCC_APB1HV_OutputPre_Div10
  * @arg RCC_APB1HV_OutputPre_Div12
  * @arg RCC_APB1HV_OutputPre_Div14
  * @arg RCC_APB1HV_OutputPre_Div16
  * @arg RCC_APB1HV_OutputPre_Div18
  * @arg RCC_APB1HV_OutputPre_Div20
  * @arg RCC_APB1HV_OutputPre_Div22
  * @arg RCC_APB1HV_OutputPre_Div24
  * @arg RCC_APB1HV_OutputPre_Div26
  * @arg RCC_APB1HV_OutputPre_Div28
  * @arg RCC_APB1HV_OutputPre_Div30
  * @arg RCC_APB1HV_OutputPre_Div32
  * @retval None.
  */
void RCC_APB1HVOutputPreConfig(uint32_t div_sel)
{
    MODIFY_REG(RCC->CFGR2, RCC_CFGR2_APB1_CLK_HV_PRE_Msk, div_sel);
}

/**
  * @brief  Selects the TIMADV clock source.
  * @param  clk_sel: Select the specified clock source.
  *   This parameter can be one of the following values:
  * @arg RCC_TIMADVCLKSource_PCLK2
  * @arg RCC_TIMADVCLKSource_TIMADVCLK
  * @retval None.
  */
void RCC_TIMADVCLKConfig(uint32_t clk_sel)
{
    MODIFY_REG(RCC->CFGR2, RCC_CFGR2_TIMADV_CKSEL_Msk, clk_sel);
}

/**
  * @brief  Configure the frequency division coefficient of TIMADV clock.
  * @param  div_sel: Select the frequency division coefficient.
  *   This parameter can be one of the following values:
  * @arg RCC_TIMADVCLK_Div1
  * @arg RCC_TIMADVCLK_Div2
  * @arg RCC_TIMADVCLK_Div4
  * @arg RCC_TIMADVCLK_Div8
  * @arg RCC_TIMADVCLK_Div16
  * @retval None.
  */
void RCC_TIMADVPrescalerConfig(uint32_t div_sel)
{
    MODIFY_REG(RCC->CFGR2, RCC_CFGR2_TIMADV_PRE_Msk, div_sel);
}

/**
  * @brief  Enables or disables HSITRIM value use the CRS module as the source.
  * @param  state: new state of the Clock Security System..
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_HSITrimUseCrsModuleCmd(FunctionalState state)
{
    (state) ?                                               \
    (RCC->ICSCR |= (0x01U << RCC_ICSCR_TRIM_CRS_SEL_Pos)) : \
    (RCC->ICSCR &= ~(0x01U << RCC_ICSCR_TRIM_CRS_SEL_Pos));
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

