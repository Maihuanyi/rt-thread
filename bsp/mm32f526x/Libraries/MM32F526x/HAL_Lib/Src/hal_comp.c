/***********************************************************************************************************************
    @file     hal_comp.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE COMP FIRMWARE FUNCTIONS.
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
#define _HAL_COMP_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_comp.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup COMP_HAL
  * @{
  */

/** @addtogroup COMP_Exported_Functions
  * @{
  */


/**
  * @brief  Deinitializes COMP peripheral registers to their default reset values.
  * @param  comp_x: select the COMP peripheral.
  *         This parameter can be one of the following values:
  *         COMP1, COMP2, COMP3.
  * @retval None.
  */
void COMP_DeInit(uint8_t comp_x)
{
    if(comp_x == COMP1)
    {
        COMP->COMP1CSR = 0x00000000;
    }
    else if(comp_x == COMP2)
    {
        COMP->COMP2CSR = 0x00000000;
    }
    else if(comp_x == COMP3)
    {
        COMP->COMP3CSR = 0x00000000;
    }  
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to an COMP_InitTypeDef structure which will
  *         be initialized.
  * @retval None.
  */
void COMP_StructInit(COMP_InitTypeDef *init_struct)
{
    init_struct->COMP_Invert         = COMP_InvertingInput_1;
    init_struct->COMP_NonInvert      = COMP_NonInvertingInput_1;
    init_struct->COMP_Output         = COMP_Output_None;
    init_struct->COMP_OutputPol      = COMP_Pol_NonInvertedOut;
    init_struct->COMP_Hysteresis     = COMP_Hysteresis_No;
    init_struct->COMP_Mode           = COMP_Mode_LowPower;
    init_struct->COMP_OutAnaSel      = COMP_AnalogOutput_Sync;
    init_struct->COMP_OFLT           = COMP_Filter_4_Period; /*!< to adjust the speed/consumption. */
}

/**
  * @brief  Initializes the COMP peripheral according to the specified in the COMP_InitStruct.
  * @param  comp_x: select the COMP peripheral.
  *         This parameter can be one of the following values:
  *         COMP1, COMP2, COMP3.
  * @param  init_struct: pointer to an COMP_InitTypeDef structure that
  *         contains the configuration information for the specified COMP
  *         peripheral.
  *         - Invert specifies the inverting input of COMP
  *         - NonInvert specifies the non inverting input of COMP
  *         - Output connect COMP output to selected timer input 
  *           (Input capture / Output Compare Reference Clear / Break Input)
  *         - COMP_OutputPol select output polarity
  *         - COMP_Hysteresis configures COMP hysteresis value
  *         - COMP_Mode configures COMP power mode
  * @retval None.
  */
void COMP_Init(uint8_t comp_x, COMP_InitTypeDef *init_struct)
{
    if(comp_x == COMP1)
    {
        MODIFY_REG(COMP->COMP1CSR, (COMP_CSR_INM_SEL_Msk |                              \
                                        COMP_CSR_INP_SEL_Msk |                              \
                                        COMP_CSR_OUT_SEL_Msk |                              \
                                        COMP_CSR_POL_Msk |                                  \
                                        COMP_CSR_HYST_Msk |                                 \
                                        COMP_CSR_MODE_Msk |                                 \
                                        COMP_CSR_OUT_ANA_SEL_Msk |                          \
                                        COMP_CSR_OFLT_Msk), (init_struct->COMP_Invert |     \
                                                            init_struct->COMP_NonInvert |  \
                                                            init_struct->COMP_Output |     \
                                                            init_struct->COMP_OutputPol |  \
                                                            init_struct->COMP_Hysteresis | \
                                                            init_struct->COMP_Mode |       \
                                                            init_struct->COMP_OutAnaSel |  \
                                                            init_struct->COMP_OFLT));
    }
    else if(comp_x == COMP2)
    {
        MODIFY_REG(COMP->COMP2CSR, (COMP_CSR_INM_SEL_Msk |                              \
                                        COMP_CSR_INP_SEL_Msk |                              \
                                        COMP_CSR_OUT_SEL_Msk |                              \
                                        COMP_CSR_POL_Msk |                                  \
                                        COMP_CSR_HYST_Msk |                                 \
                                        COMP_CSR_MODE_Msk |                                 \
                                        COMP_CSR_OUT_ANA_SEL_Msk |                          \
                                        COMP_CSR_OFLT_Msk), (init_struct->COMP_Invert |     \
                                                            init_struct->COMP_NonInvert |  \
                                                            init_struct->COMP_Output |     \
                                                            init_struct->COMP_OutputPol |  \
                                                            init_struct->COMP_Hysteresis | \
                                                            init_struct->COMP_Mode |       \
                                                            init_struct->COMP_OutAnaSel |  \
                                                            init_struct->COMP_OFLT));
    }
    else if(comp_x == COMP3)
    {
        MODIFY_REG(COMP->COMP3CSR, (COMP_CSR_INM_SEL_Msk |                              \
                                        COMP_CSR_INP_SEL_Msk |                              \
                                        COMP_CSR_OUT_SEL_Msk |                              \
                                        COMP_CSR_POL_Msk |                                  \
                                        COMP_CSR_HYST_Msk |                                 \
                                        COMP_CSR_MODE_Msk |                                 \
                                        COMP_CSR_OUT_ANA_SEL_Msk |                          \
                                        COMP_CSR_OFLT_Msk), (init_struct->COMP_Invert |     \
                                                            init_struct->COMP_NonInvert |  \
                                                            init_struct->COMP_Output |     \
                                                            init_struct->COMP_OutputPol |  \
                                                            init_struct->COMP_Hysteresis | \
                                                            init_struct->COMP_Mode |       \
                                                            init_struct->COMP_OutAnaSel |  \
                                                            init_struct->COMP_OFLT));
    }  
}

/**
  * @brief  Enable or disable the COMP peripheral.
  * @param  comp_x: select the COMP peripheral.
  *         This parameter can be one of the following values:
  *         COMP1, COMP2, COMP3.
  * @param  state: new state of the COMP peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  *         When enabled, the comparator compares the non inverting input with
  *         the inverting input and the comparison result is available on
  *         comparator output.
  *         When disabled, the comparator doesn't perform comparison and the
  *         output level is low.
  * @retval None.
  */
void COMP_Cmd(uint8_t comp_x, FunctionalState state)
{
    if(comp_x == COMP1)
    {
        (state) ?                                        \
        (COMP->COMP1CSR |= (0x01U << COMP_CSR_EN_Pos)) : \
        (COMP->COMP1CSR &= ~(0x01U << COMP_CSR_EN_Pos));
    }
    else if(comp_x == COMP2)
    {
        (state) ?                                        \
        (COMP->COMP2CSR |= (0x01U << COMP_CSR_EN_Pos)) : \
        (COMP->COMP2CSR &= ~(0x01U << COMP_CSR_EN_Pos));
    }
    else if(comp_x == COMP3)
    {
        (state) ?                                        \
        (COMP->COMP3CSR |= (0x01U << COMP_CSR_EN_Pos)) : \
        (COMP->COMP3CSR &= ~(0x01U << COMP_CSR_EN_Pos));
    } 
}

/**
  * @brief  Select CRV source  and set CRV level.
  * @param  crv_source: Select source for CRV.
  *         @arg COMP_CRV_SRC_VREFINT
  *         @arg COMP_CRV_SRC_VDDA
  * @param  crv_level: Set level for CRV.
  *         This parameter can be one of the following values:
  * @arg   COMP_CRV_Sel_1_20
  * @arg   COMP_CRV_Sel_2_20
  * @arg   COMP_CRV_Sel_3_20
  * @arg   COMP_CRV_Sel_4_20
  * @arg   COMP_CRV_Sel_5_20
  * @arg   COMP_CRV_Sel_6_20
  * @arg   COMP_CRV_Sel_7_20
  * @arg   COMP_CRV_Sel_8_20
  * @arg   COMP_CRV_Sel_9_20
  * @arg   COMP_CRV_Sel_10_20
  * @arg   COMP_CRV_Sel_11_20
  * @arg   COMP_CRV_Sel_12_20
  * @arg   COMP_CRV_Sel_13_20
  * @arg   COMP_CRV_Sel_14_20
  * @arg   COMP_CRV_Sel_15_20
  * @arg   COMP_CRV_Sel_16_20
  * @retval None.
  */
void COMP_SetCrv(uint32_t crv_source, uint32_t crv_level)
{
    MODIFY_REG(COMP->CRV, COMP_CRV_CRV_SEL_Msk, crv_level << COMP_CRV_CRV_SEL_Pos);
    MODIFY_REG(COMP->CRV, COMP_CRV_CRV_SRC_Msk, crv_source);
}

/**
  * @brief  Enable or disable the COMP register.
  * @param  state: new state of the COMP peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void COMP_CrvCmd(FunctionalState state)
{
    (state) ?                                       \
    (COMP->CRV |= (0x01U << COMP_CRV_CRV_EN_Pos)) : \
    (COMP->CRV &= ~(0x01U << COMP_CRV_CRV_EN_Pos));
}

/**
  * @brief  Return the output level (high or low) of the selected comparator.
  *         The output level depends on the selected polarity.
  *         If the polarity is not inverted:
  *           - Comparator output is low when the non-inverting input is at a
  *           lower voltage than the inverting input
  *           - Comparator output is high when the non-inverting input is at a
  *           higher voltage than the inverting input
  *         If the polarity is inverted:
  *           - Comparator output is high when the non-inverting input is at a
  *           lower voltage than the inverting input
  *           - Comparator output is low when the non-inverting input is at a
  *           higher voltage than the inverting input
  * @param  comp_x: select the COMP peripheral.
  *         This parameter can be one of the following values:
  *         COMP1, COMP2, COMP3.
  * @retval  The selected comparator output level: low or high.
  */
uint32_t COMP_GetOutputLevel(uint8_t comp_x)
{
    uint32_t ret; 
    if(comp_x == COMP1)
    {
        ret = COMP->COMP1CSR & COMP_CSR_OUT_Msk;
    }
    else if(comp_x == COMP2)
    {
        ret = COMP->COMP2CSR & COMP_CSR_OUT_Msk;
    }
    else if(comp_x == COMP3)
    {
        ret = COMP->COMP3CSR & COMP_CSR_OUT_Msk;
    }
    return ((ret) ? COMP_OutputLevel_High : COMP_OutputLevel_Low);
}

/**
  * @brief  Lock the selected comparator configuration.
  * @param  comp_x: select the COMP peripheral.
  *         This parameter can be one of the following values:
  *         COMP1, COMP2, COMP3.
  * @retval None.
  */
void COMP_LockConfig(uint8_t comp_x)
{
    if(comp_x == COMP1)
    {
        COMP->COMP1CSR |= (0x01U << COMP_CSR_LOCK_Pos);
    }
    else if(comp_x == COMP2)
    {
        COMP->COMP2CSR |= (0x01U << COMP_CSR_LOCK_Pos);
    }
    else if(comp_x == COMP3)
    {
        COMP->COMP3CSR |= (0x01U << COMP_CSR_LOCK_Pos);
    } 
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  poll_init_struct: pointer to an COMP_POLL_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void COMP_PollStructInit(COMP_POLL_InitTypeDef *poll_init_struct)
{
    poll_init_struct->COMP_Poll_Ch     = COMP_POLL_1_2;
    poll_init_struct->COMP_Poll_Fixn   = COMP_POLL_INPUT_FIXN;
    poll_init_struct->COMP_Poll_Period = COMP_POLL_WAIT_1;
}

/**
  * @brief  Initializes the COMP peripheral with polling function.
  * @param  comp_x: select the COMP peripheral.
  *         This parameter can be one of the following values:
  *         COMP1, COMP2, COMP3.
  * @param  pointer to an COMP_POLL_InitTypeDef structure.
  * @retval None.
  */
void COMP_PollInit(uint8_t comp_x, COMP_POLL_InitTypeDef *poll_init_struct)
{
    if(comp_x == COMP1)
    {
        MODIFY_REG(COMP->COMP1POLL, (COMP_POLL_POLL_CH_Msk | COMP_POLL_FIXN_Msk | COMP_POLL_PERIOD_Msk),
                (poll_init_struct->COMP_Poll_Period | poll_init_struct->COMP_Poll_Ch | poll_init_struct->COMP_Poll_Fixn));
    }
    else if(comp_x == COMP2)
    {
        MODIFY_REG(COMP->COMP2POLL, (COMP_POLL_POLL_CH_Msk | COMP_POLL_FIXN_Msk | COMP_POLL_PERIOD_Msk),
                (poll_init_struct->COMP_Poll_Period | poll_init_struct->COMP_Poll_Ch | poll_init_struct->COMP_Poll_Fixn));
    }
    else if(comp_x == COMP3)
    {
        MODIFY_REG(COMP->COMP3POLL, (COMP_POLL_POLL_CH_Msk | COMP_POLL_FIXN_Msk | COMP_POLL_PERIOD_Msk),
                (poll_init_struct->COMP_Poll_Period | poll_init_struct->COMP_Poll_Ch | poll_init_struct->COMP_Poll_Fixn));
    }  
}

/**
  * @brief  Enable or disable the COMP polling function.
  * @param  comp_x: select the COMP peripheral.
  *         This parameter can be one of the following values:
  *         COMP1, COMP2, COMP3.
  * @param  state: new state of the COMP polling function.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void COMP_PollCmd(uint8_t comp_x, FunctionalState state)
{
    if(comp_x == COMP1)
    {
        (state) ?                                               \
        (COMP->COMP1POLL |= (0x01U << COMP_POLL_POLL_EN_Pos)) : \
        (COMP->COMP1POLL &= ~(0x01U << COMP_POLL_POLL_EN_Pos));
    }
    else if(comp_x == COMP2)
    {
        (state) ?                                               \
        (COMP->COMP2POLL |= (0x01U << COMP_POLL_POLL_EN_Pos)) : \
        (COMP->COMP2POLL &= ~(0x01U << COMP_POLL_POLL_EN_Pos));
    }
    else if(comp_x == COMP3)
    {
        (state) ?                                               \
        (COMP->COMP3POLL |= (0x01U << COMP_POLL_POLL_EN_Pos)) : \
        (COMP->COMP3POLL &= ~(0x01U << COMP_POLL_POLL_EN_Pos));
    }  
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

