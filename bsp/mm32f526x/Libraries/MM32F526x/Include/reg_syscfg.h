/***********************************************************************************************************************
    @file     reg_syscfg.h
    @author   VV TEAM
    @brief    This flie contains all the SYSCFG's register and its field definition.
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

#ifndef __REG_SYSCFG_H
#define __REG_SYSCFG_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"

/**
  * @brief SYSCFG Base Address Definition
  */
#define  SYSCFG_BASE                               0x40010000 /*!<Base Address: 0x40010000*/

/**
  * @brief SYSCFG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CFGR1;               /*!<SYSCFG SYSCFG configuration register 1         offset: 0x00*/
    __IO uint32_t RESERVED0x004[1];    /*!<                                               offset: 0x4*/
    __IO uint32_t EXTICR1;             /*!<SYSCFG SYSCFG external interrupt configuration register 1 offset: 0x08*/
    __IO uint32_t EXTICR2;             /*!<SYSCFG SYSCFG external interrupt configuration register 2 offset: 0x0C*/
    __IO uint32_t EXTICR3;             /*!<SYSCFG SYSCFG external interrupt configuration register 3 offset: 0x10*/
    __IO uint32_t EXTICR4;             /*!<SYSCFG SYSCFG external interrupt configuration register 4 offset: 0x14*/
    __IO uint32_t CFGR2;               /*!<SYSCFG SYSCFG configuration register 2         offset: 0x18*/
    __IO uint32_t PDETCSR;             /*!<SYSCFG SYSCFG power detection configuration status register offset: 0x1C*/
    __IO uint32_t VOSDLY;              /*!<SYSCFG SYSCFG voltage debugger output delay register offset: 0x20*/
    __IO uint32_t DMARMP;              /*!<SYSCFG SYSCFG DMA remap register               offset: 0x24*/
    __IO uint32_t BUS_PRI;             /*!<SYSCFG SYSCFG bus priority configuration register offset: 0x28*/
} SYSCFG_TypeDef;

/**
  * @brief SYSCFG type pointer Definition
  */
#define SYSCFG                                    ((SYSCFG_TypeDef *)SYSCFG_BASE)

/**
  * @brief SYSCFG_CFGR1 Register Bit Definition
  */
#define  SYSCFG_CFGR1_USB_FS_VBUS_OWDIS_Pos       (0)
#define  SYSCFG_CFGR1_USB_FS_VBUS_OWDIS_Msk       (0x01U << SYSCFG_CFGR1_USB_FS_VBUS_OWDIS_Pos) /*!<*/
#define  SYSCFG_CFGR1_USB_FS_IDOWDIS_Pos          (1)
#define  SYSCFG_CFGR1_USB_FS_IDOWDIS_Msk          (0x01U << SYSCFG_CFGR1_USB_FS_IDOWDIS_Pos)    /*!<*/
#define  SYSCFG_CFGR1_USB_FS_VBUS_OVR_Pos         (2)
#define  SYSCFG_CFGR1_USB_FS_VBUS_OVR_Msk         (0x01U << SYSCFG_CFGR1_USB_FS_VBUS_OVR_Pos)   /*!<*/
#define  SYSCFG_CFGR1_USB_FS_IDVOR_Pos            (3)
#define  SYSCFG_CFGR1_USB_FS_IDVOR_Msk            (0x01U << SYSCFG_CFGR1_USB_FS_IDVOR_Pos)      /*!<*/
#define  SYSCFG_CFGR1_CAN1_SPV_Pos                (16)
#define  SYSCFG_CFGR1_CAN1_SPV_Msk                (0x01U << SYSCFG_CFGR1_CAN1_SPV_Pos)          /*!<*/
#define  SYSCFG_CFGR1_CAN1_TEST_Pos               (17)
#define  SYSCFG_CFGR1_CAN1_TEST_Msk               (0x01U << SYSCFG_CFGR1_CAN1_TEST_Pos)         /*!<*/
#define  SYSCFG_CFGR1_CAN1_STOP_Pos               (18)
#define  SYSCFG_CFGR1_CAN1_STOP_Msk               (0x01U << SYSCFG_CFGR1_CAN1_STOP_Pos)         /*!<*/
#define  SYSCFG_CFGR1_CAN2_SPV_Pos                (19)
#define  SYSCFG_CFGR1_CAN2_SPV_Msk                (0x01U << SYSCFG_CFGR1_CAN2_SPV_Pos)          /*!<*/
#define  SYSCFG_CFGR1_CAN2_TEST_Pos               (20)
#define  SYSCFG_CFGR1_CAN2_TEST_Msk               (0x01U << SYSCFG_CFGR1_CAN2_TEST_Pos)         /*!<*/
#define  SYSCFG_CFGR1_CAN2_STOP_Pos               (21)
#define  SYSCFG_CFGR1_CAN2_STOP_Msk               (0x01U << SYSCFG_CFGR1_CAN2_STOP_Pos)         /*!<*/
#define  SYSCFG_CFGR1_FC_ODATAEN_Pos              (28)
#define  SYSCFG_CFGR1_FC_ODATAEN_Msk              (0x01U << SYSCFG_CFGR1_FC_ODATAEN_Pos)        /*!<*/
#define  SYSCFG_CFGR1_FC_MODESEL_Pos              (29)
#define  SYSCFG_CFGR1_FC_MODESEL_Msk              (0x03U << SYSCFG_CFGR1_FC_MODESEL_Pos)        /*!<*/

/**
  * @brief SYSCFG_EXTICR1 Register Bit Definition
  */
#define  SYSCFG_EXTICR1_EXTI0_Pos                 (0)
#define  SYSCFG_EXTICR1_EXTI0_Msk                 (0x0FU << SYSCFG_EXTICR1_EXTI0_Pos) /*!<*/
#define  SYSCFG_EXTICR1_EXTI1_Pos                 (4)
#define  SYSCFG_EXTICR1_EXTI1_Msk                 (0x0FU << SYSCFG_EXTICR1_EXTI1_Pos) /*!<*/
#define  SYSCFG_EXTICR1_EXTI2_Pos                 (8)
#define  SYSCFG_EXTICR1_EXTI2_Msk                 (0x0FU << SYSCFG_EXTICR1_EXTI2_Pos) /*!<*/
#define  SYSCFG_EXTICR1_EXTI3_Pos                 (12)
#define  SYSCFG_EXTICR1_EXTI3_Msk                 (0x0FU << SYSCFG_EXTICR1_EXTI3_Pos) /*!<*/

/**
  * @brief SYSCFG_EXTICR2 Register Bit Definition
  */
#define  SYSCFG_EXTICR2_EXTI4_Pos                 (0)
#define  SYSCFG_EXTICR2_EXTI4_Msk                 (0x0FU << SYSCFG_EXTICR2_EXTI4_Pos) /*!<*/
#define  SYSCFG_EXTICR2_EXTI5_Pos                 (4)
#define  SYSCFG_EXTICR2_EXTI5_Msk                 (0x0FU << SYSCFG_EXTICR2_EXTI5_Pos) /*!<*/
#define  SYSCFG_EXTICR2_EXTI6_Pos                 (8)
#define  SYSCFG_EXTICR2_EXTI6_Msk                 (0x0FU << SYSCFG_EXTICR2_EXTI6_Pos) /*!<*/
#define  SYSCFG_EXTICR2_EXTI7_Pos                 (12)
#define  SYSCFG_EXTICR2_EXTI7_Msk                 (0x0FU << SYSCFG_EXTICR2_EXTI7_Pos) /*!<*/

/**
  * @brief SYSCFG_EXTICR3 Register Bit Definition
  */
#define  SYSCFG_EXTICR3_EXTI8_Pos                 (0)
#define  SYSCFG_EXTICR3_EXTI8_Msk                 (0x0FU << SYSCFG_EXTICR3_EXTI8_Pos)  /*!<*/
#define  SYSCFG_EXTICR3_EXTI9_Pos                 (4)
#define  SYSCFG_EXTICR3_EXTI9_Msk                 (0x0FU << SYSCFG_EXTICR3_EXTI9_Pos)  /*!<*/
#define  SYSCFG_EXTICR3_EXTI10_Pos                (8)
#define  SYSCFG_EXTICR3_EXTI10_Msk                (0x0FU << SYSCFG_EXTICR3_EXTI10_Pos) /*!<*/
#define  SYSCFG_EXTICR3_EXTI11_Pos                (12)
#define  SYSCFG_EXTICR3_EXTI11_Msk                (0x0FU << SYSCFG_EXTICR3_EXTI11_Pos) /*!<*/

/**
  * @brief SYSCFG_EXTICR4 Register Bit Definition
  */
#define  SYSCFG_EXTICR4_EXTI12_Pos                (0)
#define  SYSCFG_EXTICR4_EXTI12_Msk                (0x0FU << SYSCFG_EXTICR4_EXTI12_Pos) /*!<*/
#define  SYSCFG_EXTICR4_EXTI13_Pos                (4)
#define  SYSCFG_EXTICR4_EXTI13_Msk                (0x0FU << SYSCFG_EXTICR4_EXTI13_Pos) /*!<*/
#define  SYSCFG_EXTICR4_EXTI14_Pos                (8)
#define  SYSCFG_EXTICR4_EXTI14_Msk                (0x0FU << SYSCFG_EXTICR4_EXTI14_Pos) /*!<*/
#define  SYSCFG_EXTICR4_EXTI15_Pos                (12)
#define  SYSCFG_EXTICR4_EXTI15_Msk                (0x0FU << SYSCFG_EXTICR4_EXTI15_Pos) /*!<*/

/**
  * @brief SYSCFG_CFGR2 Register Bit Definition
  */
#define  SYSCFG_CFGR2_I2C1_MODE_SEL_Pos           (16)
#define  SYSCFG_CFGR2_I2C1_MODE_SEL_Msk           (0x01U << SYSCFG_CFGR2_I2C1_MODE_SEL_Pos)     /*!<*/
#define  SYSCFG_CFGR2_I2C2_MODE_SEL_Pos           (17)
#define  SYSCFG_CFGR2_I2C2_MODE_SEL_Msk           (0x01U << SYSCFG_CFGR2_I2C2_MODE_SEL_Pos)     /*!<*/
#define  SYSCFG_CFGR2_ENET_MII_RMII_SEL_Pos       (20)
#define  SYSCFG_CFGR2_ENET_MII_RMII_SEL_Msk       (0x01U << SYSCFG_CFGR2_ENET_MII_RMII_SEL_Pos) /*!<*/
#define  SYSCFG_CFGR2_ENET_SPD_SEL_Pos            (21)
#define  SYSCFG_CFGR2_ENET_SPD_SEL_Msk            (0x01U << SYSCFG_CFGR2_ENET_SPD_SEL_Pos)      /*!<*/
#define  SYSCFG_CFGR2_QSPI_AUTOIDLE_EN_Pos        (25)
#define  SYSCFG_CFGR2_QSPI_AUTOIDLE_EN_Msk        (0x01U << SYSCFG_CFGR2_QSPI_AUTOIDLE_EN_Pos)  /*!<*/

/**
  * @brief SYSCFG_PDETCSR Register Bit Definition
  */
#define  SYSCFG_PDETCSR_PVDE_Pos                  (0)
#define  SYSCFG_PDETCSR_PVDE_Msk                  (0x01U << SYSCFG_PDETCSR_PVDE_Pos) /*!<*/
#define  SYSCFG_PDETCSR_PLS_Pos                   (1)
#define  SYSCFG_PDETCSR_PLS_Msk                   (0x0FU << SYSCFG_PDETCSR_PLS_Pos)  /*!<*/
#define  SYSCFG_PDETCSR_PVDO_Pos                  (5)
#define  SYSCFG_PDETCSR_PVDO_Msk                  (0x01U << SYSCFG_PDETCSR_PVDO_Pos) /*!<*/

/**
  * @brief SYSCFG_VOSDLY Register Bit Definition
  */
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Pos             (0)
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Msk             (0x03FFU << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) /*!<*/

/**
  * @brief SYSCFG_DMARMP Register Bit Definition
  */
#define  SYSCFG_DMARMP_TIM1_TRIG_RMP_Pos          (0)
#define  SYSCFG_DMARMP_TIM1_TRIG_RMP_Msk          (0x01U << SYSCFG_DMARMP_TIM1_TRIG_RMP_Pos) /*!<*/
#define  SYSCFG_DMARMP_TIM1_COM_RMP_Pos           (1)
#define  SYSCFG_DMARMP_TIM1_COM_RMP_Msk           (0x01U << SYSCFG_DMARMP_TIM1_COM_RMP_Pos)  /*!<*/
#define  SYSCFG_DMARMP_TIM2_UP_RMP_Pos            (2)
#define  SYSCFG_DMARMP_TIM2_UP_RMP_Msk            (0x03U << SYSCFG_DMARMP_TIM2_UP_RMP_Pos)   /*!<*/
#define  SYSCFG_DMARMP_TIM2_CC3_RMP_Pos           (4)
#define  SYSCFG_DMARMP_TIM2_CC3_RMP_Msk           (0x01U << SYSCFG_DMARMP_TIM2_CC3_RMP_Pos)  /*!<*/
#define  SYSCFG_DMARMP_TIM2_CC4_RMP_Pos           (5)
#define  SYSCFG_DMARMP_TIM2_CC4_RMP_Msk           (0x01U << SYSCFG_DMARMP_TIM2_CC4_RMP_Pos)  /*!<*/
#define  SYSCFG_DMARMP_TIM5_UP_RMP_Pos            (8)
#define  SYSCFG_DMARMP_TIM5_UP_RMP_Msk            (0x01U << SYSCFG_DMARMP_TIM5_UP_RMP_Pos)   /*!<*/
#define  SYSCFG_DMARMP_TIM6_UP_RMP_Pos            (10)
#define  SYSCFG_DMARMP_TIM6_UP_RMP_Msk            (0x01U << SYSCFG_DMARMP_TIM6_UP_RMP_Pos)   /*!<*/
#define  SYSCFG_DMARMP_TIM7_UP_RMP_Pos            (12)
#define  SYSCFG_DMARMP_TIM7_UP_RMP_Msk            (0x01U << SYSCFG_DMARMP_TIM7_UP_RMP_Pos)   /*!<*/
#define  SYSCFG_DMARMP_TIM8_TRIG_RMP_Pos          (13)
#define  SYSCFG_DMARMP_TIM8_TRIG_RMP_Msk          (0x01U << SYSCFG_DMARMP_TIM8_TRIG_RMP_Pos) /*!<*/
#define  SYSCFG_DMARMP_TIM8_UP_RMP_Pos            (14)
#define  SYSCFG_DMARMP_TIM8_UP_RMP_Msk            (0x01U << SYSCFG_DMARMP_TIM8_UP_RMP_Pos)   /*!<*/
#define  SYSCFG_DMARMP_TIM8_COM_RMP_Pos           (15)
#define  SYSCFG_DMARMP_TIM8_COM_RMP_Msk           (0x01U << SYSCFG_DMARMP_TIM8_COM_RMP_Pos)  /*!<*/
#define  SYSCFG_DMARMP_UART4_RX_RMP_Pos           (16)
#define  SYSCFG_DMARMP_UART4_RX_RMP_Msk           (0x01U << SYSCFG_DMARMP_UART4_RX_RMP_Pos)  /*!<*/
#define  SYSCFG_DMARMP_UART4_TX_RMP_Pos           (17)
#define  SYSCFG_DMARMP_UART4_TX_RMP_Msk           (0x01U << SYSCFG_DMARMP_UART4_TX_RMP_Pos)  /*!<*/
#define  SYSCFG_DMARMP_UART6_RX_RMP_Pos           (20)
#define  SYSCFG_DMARMP_UART6_RX_RMP_Msk           (0x01U << SYSCFG_DMARMP_UART6_RX_RMP_Pos)  /*!<*/
#define  SYSCFG_DMARMP_UART6_TX_RMP_Pos           (21)
#define  SYSCFG_DMARMP_UART6_TX_RMP_Msk           (0x01U << SYSCFG_DMARMP_UART6_TX_RMP_Pos)  /*!<*/
#define  SYSCFG_DMARMP_UART7_RX_TMP_Pos           (22)
#define  SYSCFG_DMARMP_UART7_RX_TMP_Msk           (0x01U << SYSCFG_DMARMP_UART7_RX_TMP_Pos)  /*!<*/
#define  SYSCFG_DMARMP_UART7_TX_RMP_Pos           (23)
#define  SYSCFG_DMARMP_UART7_TX_RMP_Msk           (0x01U << SYSCFG_DMARMP_UART7_TX_RMP_Pos)  /*!<*/
#define  SYSCFG_DMARMP_DAC_CH1_RMP_Pos            (28)
#define  SYSCFG_DMARMP_DAC_CH1_RMP_Msk            (0x01U << SYSCFG_DMARMP_DAC_CH1_RMP_Pos)   /*!<*/
#define  SYSCFG_DMARMP_DAC_CH2_RMP_Pos            (29)
#define  SYSCFG_DMARMP_DAC_CH2_RMP_Msk            (0x01U << SYSCFG_DMARMP_DAC_CH2_RMP_Pos)   /*!<*/

/**
  * @brief SYSCFG_BUS_PRI Register Bit Definition
  */
#define  SYSCFG_BUS_PRI_PRI_M1_Pos                (0)
#define  SYSCFG_BUS_PRI_PRI_M1_Msk                (0x07U << SYSCFG_BUS_PRI_PRI_M1_Pos) /*!<*/
#define  SYSCFG_BUS_PRI_PRI_M2_Pos                (3)
#define  SYSCFG_BUS_PRI_PRI_M2_Msk                (0x07U << SYSCFG_BUS_PRI_PRI_M2_Pos) /*!<*/
#define  SYSCFG_BUS_PRI_PRI_M3_Pos                (6)
#define  SYSCFG_BUS_PRI_PRI_M3_Msk                (0x07U << SYSCFG_BUS_PRI_PRI_M3_Pos) /*!<*/
#define  SYSCFG_BUS_PRI_PRI_M4_Pos                (9)
#define  SYSCFG_BUS_PRI_PRI_M4_Msk                (0x07U << SYSCFG_BUS_PRI_PRI_M4_Pos) /*!<*/
#define  SYSCFG_BUS_PRI_PRI_M5_Pos                (12)
#define  SYSCFG_BUS_PRI_PRI_M5_Msk                (0x07U << SYSCFG_BUS_PRI_PRI_M5_Pos) /*!<*/
#define  SYSCFG_BUS_PRI_PRI_M6_Pos                (15)
#define  SYSCFG_BUS_PRI_PRI_M6_Msk                (0x07U << SYSCFG_BUS_PRI_PRI_M6_Pos) /*!<*/

#endif

