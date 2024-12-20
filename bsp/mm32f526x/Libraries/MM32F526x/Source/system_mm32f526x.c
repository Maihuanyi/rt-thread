/***********************************************************************************************************************
    @file     system_mm32f5260.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
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

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"
#include "mpu_armv8.h"

/**
  * @}
  */

/*
 *  Only one of SYSCLK_HSI_XXMHz and SYSCLK_HSE_XXMHz can be defined at a time. 
 *  When HSI is used as the clock source, SYSCLK_HSI_XXMHz is used. 
 *  When HSE is used as the clock source, SYSCLK_HSE_XXMHz is used. 
 *  Whichever one is used, its value must be greater than or equal to 25 million. 
 *  If it is less than 25 million, HSI or HSE will be used as the system clock.    
 */
#define SYSCLK_HSI_XXMHz                120000000
//#define SYSCLK_HSI_XXMHz                96000000
//#define SYSCLK_HSI_XXMHz                72000000
//#define SYSCLK_HSI_XXMHz                48000000

//#define SYSCLK_HSE_XXMHz                120000000 
//#define SYSCLK_HSE_XXMHz                96000000 
//#define SYSCLK_HSE_XXMHz                72000000 
//#define SYSCLK_HSE_XXMHz                48000000 


#if defined (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz >= 25000000U)
    uint32_t SystemCoreClock = SYSCLK_HSI_XXMHz;
#elif defined (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz < 25000000U)
    uint32_t SystemCoreClock = HSI_VALUE;
#elif defined (SYSCLK_HSE_XXMHz) && (SYSCLK_HSE_XXMHz >= 25000000U)
    uint32_t SystemCoreClock = SYSCLK_HSE_XXMHz;
#elif defined (SYSCLK_HSE_XXMHz) && (SYSCLK_HSE_XXMHz < 25000000U)
    uint32_t SystemCoreClock = HSE_VALUE;
#endif

#define RCC_CFGR_HPRE_DIV1              (0x00U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV2              (0x08U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV4              (0x09U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV8              (0x0AU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV16             (0x0BU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV64             (0x0CU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV128            (0x0DU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV256            (0x0EU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV512            (0x0FU << RCC_CFGR_HPRE_Pos)

#define RCC_CFGR_PPRE1_DIV1             (0x00U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV2             (0x04U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV4             (0x05U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV8             (0x06U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV16            (0x07U << RCC_CFGR_PPRE1_Pos)

#define RCC_CFGR_PPRE2_DIV1             (0x00U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV2             (0x04U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV4             (0x05U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV8             (0x06U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV16            (0x07U << RCC_CFGR_PPRE2_Pos)

#define RCC_CFGR_SW_HSI                 (0x00U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSE                 (0x01U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_PLL1                (0x02U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_LSI                 (0x03U << RCC_CFGR_SW_Pos)

#define RCC_CFGR_SWS_HSI                (0x00U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSE                (0x01U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_PLL1               (0x02U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_LSI                (0x03U << RCC_CFGR_SWS_Pos)



typedef uint8_t MPU_ATTR_Table_t;

const MPU_ATTR_Table_t attrTable[] =
{
    //Attr 0
    ARM_MPU_ATTR(                                 /* Normal memory */
        ARM_MPU_ATTR_MEMORY_(0UL, 0UL, 1UL, 1UL), /* Outer Write-Through transient with read and write allocate */
        ARM_MPU_ATTR_MEMORY_(0UL, 0UL, 1UL, 1UL)  /* Inner Write-Through transient with read and write allocate */
        ),

    //Attr 1
    ARM_MPU_ATTR(                                 /* Normal memory */
        ARM_MPU_ATTR_MEMORY_(0UL, 1UL, 0UL, 0UL), /* Outer Outer non-cacheable */
        ARM_MPU_ATTR_MEMORY_(0UL, 1UL, 0UL, 0UL)  /* Inner Inner non-cacheable */
        ),

    //Attr 2
    ARM_MPU_ATTR(                                 /* Device memory */
        ARM_MPU_ATTR_MEMORY_(0UL, 0UL, 0UL, 0UL), /* Device memory */
        ARM_MPU_ATTR_MEMORY_(0UL, 0UL, 0UL, 0UL)  /* Device-nGnRnE */
        ),
};

const ARM_MPU_Region_t mpuTable[] =
{
    /*                     BASE          SH                RO   NP   XN                         LIMIT         ATTR  */
    { .RBAR = ARM_MPU_RBAR(0x08000000UL, ARM_MPU_SH_NON,   0UL, 1UL, 0UL), .RLAR = ARM_MPU_RLAR(0x080FFFFFUL, 0UL) },
    { .RBAR = ARM_MPU_RBAR(0x90000000UL, ARM_MPU_SH_OUTER, 0UL, 1UL, 0UL), .RLAR = ARM_MPU_RLAR(0x9FFFFFFFUL, 0UL) },
    { .RBAR = ARM_MPU_RBAR(0x30000000UL, ARM_MPU_SH_OUTER, 0UL, 1UL, 0UL), .RLAR = ARM_MPU_RLAR(0x3001FFFFUL, 1UL) },
};

/**
  * @brief  Load the given number of MPU regions from a table
  * @param  None
  * @retval None
  */
void MPU_Load_Attr(MPU_ATTR_Table_t const *table, uint32_t cnt)
{
    uint32_t offset;

    for (offset = 0; offset < cnt; offset++)
    {
        ARM_MPU_SetMemAttr(offset, table[offset]);
    }
}

/**
  * @brief  Set MPU Region
  * @param  None
  * @retval None
  */
void MPU_Config(void)
{
    /* Load Attribute Table */
    MPU_Load_Attr(attrTable, sizeof(attrTable) / sizeof(MPU_ATTR_Table_t));

    /* Load the given number of MPU regions from a table */
    ARM_MPU_Load(0, mpuTable, sizeof(mpuTable) / sizeof(ARM_MPU_Region_t));

    /* Enable MPU with all region definitions and background regions for privileged access. Exceptions are protected by MPU */
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk | MPU_CTRL_HFNMIENA_Msk);
}

/**
  * @brief  use to return the pll_div & pll_mul.
  * @param  pllclkSourceFrq : PLL1 source clock frquency;
  *         pllclkFrq : Target PLL1 clock frquency;
  *         pll_mul : PLL1 factor PLL1  Multiplication Factor
  *         pll_div : PLL1 factor PLL1 Divide Factor
  * @retval amount of error
  */
uint32_t AutoCalPllFactor(uint32_t pllclkSourceFrq, uint32_t pllclkFrq, uint8_t *pll_mul, uint8_t *pll_div)
{
    uint32_t mul_temp, div_temp, mul_max, div_max;
    uint32_t tempFrq = 0;
    uint32_t minDiff = pllclkFrq;
    uint8_t  flag    = 0;

    mul_max = RCC_PLL1CFGR_PLL1MUL_Msk >> RCC_PLL1CFGR_PLL1MUL_Pos;
    div_max = RCC_PLL1CFGR_PLL1DIV_Msk >> RCC_PLL1CFGR_PLL1DIV_Pos;

    for (div_temp = 1; div_temp <= div_max; div_temp += 2)
    {
        for (mul_temp = 0; mul_temp <= mul_max; mul_temp++)
        {
            tempFrq = pllclkSourceFrq / (div_temp + 1) * (mul_temp + 1);
            tempFrq = (tempFrq > pllclkFrq) ? (tempFrq - pllclkFrq) : (pllclkFrq - tempFrq);

            if (minDiff > tempFrq)
            {
                minDiff    = tempFrq;
                *pll_mul   = mul_temp;
                *pll_div   = div_temp;
            }

            if (minDiff == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag != 0)
        {
            break;
        }
    }

    return (minDiff);
}

/**
  * @brief  Configures the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers.
  * @param  None
  * @retval None
  */
static void SetSysClockToDefine(void)
{
    __IO uint32_t StartUpCounter = 0, ClkSrcStatus = 1;
    uint8_t pll_mul, pll_div;
    uint32_t temp = 0, i = 0;

#ifdef SYSCLK_HSE_XXMHz
    /* HSE Current Mode Select */
    RCC->CR &= ~RCC_CR_HSEIB_Msk;
    if(HSE_VALUE >= 12000000)
    {
        RCC->CR |= (0x03 << RCC_CR_HSEIB_Pos);
    }
    else 
    {
        RCC->CR |= (0x01 << RCC_CR_HSEIB_Pos);
    }

    /* Enable HSE */
    RCC->CR |= (0x01U << RCC_CR_HSEON_Pos);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSERDY_Msk;
        StartUpCounter++;
    }
    while ((ClkSrcStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSERDY_Msk) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }

    SystemCoreClock = SYSCLK_HSE_XXMHz;

    /* Config pll clock source*/
    RCC->PLL1CFGR |= (0x01U << RCC_PLL1CFGR_PLL1SRC_Pos);

    /* calculate PLL1 factor*/
    AutoCalPllFactor(HSE_VALUE, SystemCoreClock, &pll_mul, &pll_div);

    /* set PLL1 CP Current Control Signals */
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1_ICTRL_Msk;
    if(HSE_VALUE >= 8000000)
    {
        RCC->PLL1CFGR |= (0x03 << RCC_PLL1CFGR_PLL1_ICTRL_Pos);
    }
    else 
    {
        RCC->PLL1CFGR |= (0x01 << RCC_PLL1CFGR_PLL1_ICTRL_Pos);
    }
#else
    /* Enable HSI */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);

    /* Wait till HSI is ready and if Time out is reached exit */
    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSIRDY_Msk;
        StartUpCounter++;
    }
    while((ClkSrcStatus == 0) && (StartUpCounter != HSI_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSIRDY_Msk) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }

    SystemCoreClock = SYSCLK_HSI_XXMHz;

    /* Config pll clock source*/
    RCC->PLL1CFGR &= ~(0x01U << RCC_PLL1CFGR_PLL1SRC_Pos);

    /* calculate PLL1 factor*/
    AutoCalPllFactor(HSI_VALUE, SystemCoreClock, &pll_mul, &pll_div);

    /* set PLL1 CP Current Control Signals */
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1_ICTRL_Msk;
    if(HSI_VALUE >= 8000000)
    {
        RCC->PLL1CFGR |= (0x03 << RCC_PLL1CFGR_PLL1_ICTRL_Pos);
    }
    else 
    {
        RCC->PLL1CFGR |= (0x01 << RCC_PLL1CFGR_PLL1_ICTRL_Pos);
    }
#endif

    if (ClkSrcStatus == (uint32_t)0x01)
    {
        FLASH->ACR &= ~FLASH_ACR_LATENCY_Msk;
        FLASH->ACR |= (0x01U << FLASH_ACR_PRFTBE_Pos);
        temp = (SystemCoreClock - 1) / 24000000;

        if (temp > 4)
        {
            temp = 4;
        }

        FLASH->ACR |= temp;


        /* HCLK = SYSCLK/8 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV8;
        RCC->CFGR = temp;

        /* PCLK2 = HCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_PPRE2_Msk;
        temp     |= RCC_CFGR_PPRE2_DIV1;
        RCC->CFGR = temp;

        /* PCLK1 = HCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_PPRE1_Msk;
        temp     |= RCC_CFGR_PPRE1_DIV1;
        RCC->CFGR = temp;

#if defined (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz < 25000000U)
        /* Select HSI as system clock source */
        RCC->CFGR &= ~RCC_CFGR_SW_Msk;
        RCC->CFGR |= RCC_CFGR_SW_HSI;

#elif defined (SYSCLK_HSE_XXMHz) && (SYSCLK_HSE_XXMHz < 25000000U)
        /* Select HSE as system clock source */
        RCC->CFGR &= ~RCC_CFGR_SW_Msk;
        RCC->CFGR |= RCC_CFGR_SW_HSE;
#else
        /* configuration PLL1 */
        RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1MUL_Msk;
        RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1DIV_Msk;

        RCC->PLL1CFGR |= ((pll_mul << RCC_PLL1CFGR_PLL1MUL_Pos) | (pll_div << RCC_PLL1CFGR_PLL1DIV_Pos));

        /* Enable PLL1 */
        RCC->CR |= (0x01U << RCC_CR_PLL1ON_Pos);

        /* Wait till PLL1 is ready */
        while ((RCC->CR & RCC_CR_PLL1RDY_Msk) == 0)
        {
            __ASM("nop");                  /* __NOP(); */
        }

        /* Select PLL1 as system clock source */
        RCC->CFGR &= ~RCC_CFGR_SW_Msk;
        RCC->CFGR |= RCC_CFGR_SW_PLL1;

        /* Wait till PLL1 is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_PLL1)
        {
            __ASM("nop");                  /* __NOP(); */
        }
#endif


        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

        /* HCLK = SYSCLK/4 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV4;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

        /* HCLK = SYSCLK/2 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV2;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

        /* HCLK = SYSCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV1;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }
    }
    else
    {
        /* If HSE or HSI not ready within the given time, the program will stop here. 
           User can add here some code to deal with this error */       
        while(1);
    } 
}

/**
  * @brief  Setup the microcontroller system Initialize the Embedded Flash Interface,
  *         the PLL1 and update the SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
    /* MPU settings */
#if (defined (__ICACHE_PRESENT) && !defined (ICACHE_DISABLED)) || (defined (__DCACHE_PRESENT) && !defined (DCACHE_DISABLED))
    MPU_Config();
#endif

    /* FPU settings */
#if defined (__FPU_PRESENT) && !defined (FPU_DISABLED)
    SCB->CPACR |= ((3U << 10U * 2U) | (3U << 11U * 2U)); /* set CP10 and CP11 Full Access */
#endif

    /* ICACHE settings */
#if defined (__ICACHE_PRESENT) && !defined (ICACHE_DISABLED)
    SCB_EnableICache();
#endif

    /* DCACHE settings */
#if defined (__DCACHE_PRESENT) && !defined (DCACHE_DISABLED)
    SCB_EnableDCache();
#endif

    /* Set HSION bit */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);

    /* Reset SW, HPRE, PPRE1, PPRE2 and MCO bits */
    RCC->CFGR &= ~RCC_CFGR_SW_Msk;
    RCC->CFGR &= ~RCC_CFGR_HPRE_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE1_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE2_Msk;
    RCC->CFGR &= ~RCC_CFGR_MCO_Msk;

    /* Reset HSEON, CSSON and PLL1ON bits */
    RCC->CR &= ~RCC_CR_HSEON_Msk;
    RCC->CR &= ~RCC_CR_CSSON_Msk;
    RCC->CR &= ~RCC_CR_PLL1ON_Msk;

    /* Reset HSEBYP bit */
    RCC->CR &= ~RCC_CR_HSEBYP_Msk;

    /* Reset PLL1SRC, PLL1PDIV, PLL1MUL, PLL1DIV bits */
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1SRC_Msk;
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1MUL_Msk;
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1DIV_Msk;

    /* Disable all interrupts and clear pending bits */
    RCC->CIR = 0xFFFFFFFF; 
    RCC->CIR = 0; 

    /* Set VOS as 1.7V */
    RCC->APB1ENR |= (0x01 << RCC_APB1ENR_PWRDBG_Pos);
    PWR->CR1 |= (0x03 << PWR_CR1_VOS_Pos);


    /* Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers */
    /* Configure the Flash Latency cycles and enable prefetch buffer */
    SetSysClockToDefine();
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

