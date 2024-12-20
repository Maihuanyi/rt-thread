/***********************************************************************************************************************
    @file     hal_usbfs.c
    @author   FD TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2024> <MindMotion></center></h2>

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
#define _HAL_USBFS_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_usbfs.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup USBFS_HAL
  * @{
  */

/** @addtogroup USBFS_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the USB peripheral registers to their
  *         default reset values.
  * @param  usbfs: Select the USB peripheral.
  * @retval None.
  */
void USBFS_DeInit(USB_FS_TypeDef * usbfs)
{
    if (usbfs == USB_FS)
    {
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_USB_FS, ENABLE);
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_USB_FS, DISABLE);
    }
}

/**
  * @brief  Set the USB buffer descriptor table address.
  * @param  usbfs: select the USB peripheral.
  * @param  addr: USB buffer descriptor table address.
  * @retval None.
  */
void USBFS_SetBufDespTableAddr(USB_FS_TypeDef * usbfs, uint32_t addr)
{
    MODIFY_REG(usbfs->BDTPAGE1, USB_FS_BDTPAGE1_BDT_BA_Msk, (addr >> 9u) <<USB_FS_BDTPAGE1_BDT_BA_Pos);
    MODIFY_REG(usbfs->BDTPAGE2, USB_FS_BDTPAGE2_BDT_BA_Msk, (addr >> 16u)<<USB_FS_BDTPAGE2_BDT_BA_Pos);
    MODIFY_REG(usbfs->BDTPAGE3, USB_FS_BDTPAGE3_BDT_BA_Msk, (addr >> 24u)<<USB_FS_BDTPAGE3_BDT_BA_Pos);
}

/**
  * @brief  Initialize the USB module according to the specified parameters.
  * @param  usbfs: select the USBx peripheral.
  * @param  init: Pointer to the initialization structure.
  * @retval None.
  */
void USBFS_InitDevice(USB_FS_TypeDef * usbfs, USBFS_Device_Init_Type *init)
{
    if ( NULL == init &&
        (uint32_t)(init->BufDespTable_Addr) % 512u != 0u)
    {
        return;
    }

    USBFS_SetBufDespTableAddr(usbfs, init->BufDespTable_Addr);

    /* disable host mode. */
    usbfs->CTL &= ~USB_FS_CTL_HOST_MODE_EN_Msk;

    /* disable D+ & D- pulldown resistors. */
    usbfs->OTGCTRL &= ~USB_FS_OTGCTRL_OTG_EN_Msk;
}

/**
  * @brief  Initialize the USB module according to the specified parameters.
  * @param  usbfs: select the USBx peripheral.
  * @param  init: Pointer to the initialization structure.
  * @retval None.
  */
void USBFS_InitHost(USB_FS_TypeDef * usbfs, USBFS_Host_Init_Type * init)
{
    if ( NULL == init
        &&(uint32_t)(init->BufDespTable_Addr) % 512u != 0u)
    {
        return;
    }

    USBFS_SetBufDespTableAddr(usbfs, init->BufDespTable_Addr); /* set bdt addr. */
    usbfs->CTL |= USB_FS_CTL_HOST_MODE_EN_Msk; /* enable host mode. */
    usbfs->SOFTHLD = init->SofThreshold; /* set SOF threshold. */

    if (init->NakRetry)
    {
        usbfs->EPCTL[0] &= ~USB_FS_EPCTL_RETRY_DIS_Msk;
    }
    else
    {
        usbfs->EPCTL[0] |=  USB_FS_EPCTL_RETRY_DIS_Msk;
    }

    /* enable D+ & D- pulldown resistors. */
    usbfs->OTGCTRL |= (USB_FS_OTGCTRL_DM_LOW_Msk | USB_FS_OTGCTRL_DP_LOW_Msk | USB_FS_OTGCTRL_OTG_EN_Msk);
}

/**
  * @brief  Enables or disables the specified USB peripheral.
  * @param  usbfs: select the USB peripheral.
  * @param  state: new state of the USB peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void USBFS_Cmd(USB_FS_TypeDef * usbfs, FunctionalState state)
{
    (state) ?                                        \
    (usbfs->CTL |= USB_FS_CTL_USB_EN_Msk) :        \
    (usbfs->CTL &= ~USB_FS_CTL_USB_EN_Msk);
}

/**
  * @brief  Enables or disables all USB interrupts.
  * @param  usbfs: Select the USB_FS peripheral.
  * @param  interrupts: specifies the USB interrupt sources to be enabled or disabled.
  * @arg    USBFS_IT_RESET: USB bus reset.
  * @arg    USBFS_IT_ERROR: Error happend.
  * @arg    USBFS_IT_SOFTOK: Recv a SOF_Tok.
  * @arg    USBFS_IT_TOKENDONE: Token done.
  * @arg    USBFS_IT_SLEEP: Sleep.
  * @arg    USBFS_IT_RESUME: Resume.
  * @arg    USBFS_IT_ATTACH: Attach.
  * @arg    USBFS_IT_STALL: Stall.
  * @param  state: new state of the specified USB interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void USBFS_ITConfig(USB_FS_TypeDef * usbfs, uint32_t interrupt, FunctionalState state)
{
    (state) ?                      \
    (usbfs->INTENB |= interrupt) : \
    (usbfs->INTENB &= ~interrupt);
}

/**
  * @brief  Checks whether the specified USB's interrupt has occurred or not.
  * @param  usbfs: select the USB peripheral.
  * @param  interrupt: specifies the USB interrupt source to check.
  * @retval The new state of interrupt (SET or RESET).
  */
ITStatus USBFS_GetITStatus(USB_FS_TypeDef * usbfs, uint32_t interrupt)
{
    ITStatus ret = RESET;

    if (USBFS_IT_RESET == interrupt)
    {
        ret = ((usbfs->INTSTAT & USBFS_IT_RESET) ? SET : RESET);
    }
    else if (USBFS_IT_ERROR == interrupt)
    {
        ret = ((usbfs->INTSTAT & USBFS_IT_ERROR) ? SET : RESET);
    }
    else if (USBFS_IT_SOFTOK == interrupt)
    {
        ret = ((usbfs->INTSTAT & USBFS_IT_SOFTOK) ? SET : RESET);
    }
    else if (USBFS_IT_TOKENDONE == interrupt)
    {
        ret = ((usbfs->INTSTAT & USBFS_IT_TOKENDONE) ? SET : RESET);
    }
    else if (USBFS_IT_SLEEP == interrupt)
    {
        ret = ((usbfs->INTSTAT & USBFS_IT_SLEEP) ? SET : RESET);
    }
    else if (USBFS_IT_RESUME == interrupt)
    {
        ret = ((usbfs->INTSTAT & USBFS_IT_RESUME) ? SET : RESET);
    }
    else if (USBFS_IT_ATTACH == interrupt)
    {
        ret = ((usbfs->INTSTAT & USBFS_IT_ATTACH) ? SET : RESET);
    }
    else if (USBFS_IT_STALL == interrupt)
    {
        ret = ((usbfs->INTSTAT & USBFS_IT_STALL) ? SET : RESET);
    }

    return (ret);
}

/**
  * @brief  Get all enabled USBFS's interrupts status.
  * @param  usbfs: select the USB peripheral.
  * @retval The enabled USBFS's interrupts status.
  */
uint32_t USBFS_GetEnabledITStatus(USB_FS_TypeDef * usbfs)
{
    return usbfs->INTENB & usbfs->INTSTAT;
}

/**
  * @brief  Clears the USBFS's interrupt pending bits.
  * @param  usbfs: select the USB peripheral.
  * @param  interrupt: specifies the USB interrupt pending bit to clear.
  * @arg    USBFS_IT_RESET: USB bus reset.
  * @arg    USBFS_IT_ERROR: Error happend.
  * @arg    USBFS_IT_SOFTOK: Recv a SOF_Tok.
  * @arg    USBFS_IT_TOKENDONE: Token done.
  * @arg    USBFS_IT_SLEEP: Sleep.
  * @arg    USBFS_IT_RESUME: Resume.
  * @arg    USBFS_IT_ATTACH: Attach.
  * @arg    USBFS_IT_STALL: Stall.
  * @retval None.
  */
void USBFS_ClearITPendingBit(USB_FS_TypeDef * usbfs, uint32_t interrupt)
{
    usbfs->INTSTAT = interrupt;
}

/**
  * @brief  Enables or disables error interrupts of USB interrupts.
  * @param  usbfs: Select the USB_FS peripheral.
  * @param  interrupts: specifies the USB error interrupt sources to be enabled or disabled.
  * @arg    USBFS_IT_ERR_PID: PID check error.
  * @arg    USBFS_IT_ERR_CRC5: CRC5 check failed.
  * @arg    USBFS_IT_ERR_EOF: EOF Error.
  * @arg    USBFS_IT_ERR_CRC16: CRC16 check failed.
  * @arg    USBFS_IT_ERR_DFN8: Data not 8bit.
  * @arg    USBFS_IT_ERR_BTO: BTO error.
  * @arg    USBFS_IT_ERR_DMA: DMA error.
  * @arg    USBFS_IT_ERR_BTS: Bit stuff error.
  * @param  state: new state of the specified USB interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void USBFS_ErrITConfig(USB_FS_TypeDef * usbfs, uint32_t interrupt, FunctionalState state)
{
    (state) ?                      \
    (usbfs->ERRENB |= interrupt) : \
    (usbfs->ERRENB &= ~interrupt);
}

/**
  * @brief  Checks whether the specified USB's error interrupt has occurred or not.
  * @param  usbfs: select the USB peripheral.
  * @param  interrupt: specifies the USB eeror interrupt source to check.
  * @retval The new state of interrupt (SET or RESET).
  */
ITStatus USBFS_GetErrITStatus(USB_FS_TypeDef * usbfs, uint32_t interrupt)
{
    ITStatus ret = RESET;

    if (USBFS_IT_ERR_PID == interrupt)
    {
        ret = ((usbfs->ERRSTAT & USBFS_IT_ERR_PID) ? SET : RESET);
    }
    else if (USBFS_IT_ERR_CRC5 == interrupt)
    {
        ret = ((usbfs->ERRSTAT & USBFS_IT_ERR_CRC5) ? SET : RESET);
    }
    else if (USBFS_IT_ERR_EOF == interrupt)
    {
        ret = ((usbfs->ERRSTAT & USBFS_IT_ERR_EOF) ? SET : RESET);
    }
    else if (USBFS_IT_ERR_CRC16 == interrupt)
    {
        ret = ((usbfs->ERRSTAT & USBFS_IT_ERR_CRC16) ? SET : RESET);
    }
    else if (USBFS_IT_ERR_DFN8 == interrupt)
    {
        ret = ((usbfs->ERRSTAT & USBFS_IT_ERR_DFN8) ? SET : RESET);
    }
    else if (USBFS_IT_ERR_BTO == interrupt)
    {
        ret = ((usbfs->ERRSTAT & USBFS_IT_ERR_BTO) ? SET : RESET);
    }
    else if (USBFS_IT_ERR_DMA == interrupt)
    {
        ret = ((usbfs->ERRSTAT & USBFS_IT_ERR_DMA) ? SET : RESET);
    }
    else if (USBFS_IT_ERR_BTS == interrupt)
    {
        ret = ((usbfs->ERRSTAT & USBFS_IT_ERR_BTS) ? SET : RESET);
    }

    return (ret);
}

/**
  * @brief  Clears the USB's error interrupt pending bits.
  * @param  usbfs: select the USB peripheral.
  * @param  interrupt: specifies the USB interrupt pending bit to clear.
  * @arg    USBFS_IT_ERR_PID: PID check error.
  * @arg    USBFS_IT_ERR_CRC5: CRC5 check failed.
  * @arg    USBFS_IT_ERR_EOF: EOF Error.
  * @arg    USBFS_IT_ERR_CRC16: CRC16 check failed.
  * @arg    USBFS_IT_ERR_DFN8: Data not 8bit.
  * @arg    USBFS_IT_ERR_BTO: BTO error.
  * @arg    USBFS_IT_ERR_DMA: DMA error.
  * @arg    USBFS_IT_ERR_BTS: Bit stuff error.
  * @retval None.
  */
void USBFS_ClearErrITPendingBit(USB_FS_TypeDef * usbfs, uint32_t interrupt)
{
    usbfs->ERRSTAT = interrupt;

}

/**
  * @brief  Enables or disables the USB BufDesp ODD_EVEN Reset, and make only even BufDesp can be used.
  * @param  usbfs: select the USB peripheral.
  * @param  state: new state of the USB BufDesp.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void USBFS_OddEvenResetCmd(USB_FS_TypeDef * usbfs, FunctionalState state)
{
    (state) ?                                  \
    (usbfs->CTL |= USB_FS_CTL_ODD_RST_Msk) : \
    (usbfs->CTL &= ~USB_FS_CTL_ODD_RST_Msk);
}

/**
  * @brief  Enables or disables the USB Resume signal.
  * @param  usbfs: select the USB peripheral.
  * @param  state: new state of the USB Resume signal.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void USBFS_ResumeSignalCmd(USB_FS_TypeDef * usbfs, FunctionalState state)
{
    (state) ?                                 \
    (usbfs->CTL |= USB_FS_CTL_RESUME_Msk) : \
    (usbfs->CTL &= ~USB_FS_CTL_RESUME_Msk);
}

/**
  * @brief  Enables or disables the USB Suspend.
  * @param  usbfs: select the USB peripheral.
  * @param  state: new state of the USB Suspend.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void USBFS_SuspendCmd(USB_FS_TypeDef * usbfs, FunctionalState state)
{
    (state) ?                                              \
    (usbfs->CTL |= USB_FS_CTL_TXDSUSPENDTOKENBUSY_Msk) : \
    (usbfs->CTL &= ~USB_FS_CTL_TXDSUSPENDTOKENBUSY_Msk);
}

/**
  * @brief  Set Device address.
  *         This address is distribute by host.
  * @param  usbfs: select the USB peripheral.
  * @param  addr: the device address.
  * @retval None.
  */
void USBFS_SetDeviceAddr(USB_FS_TypeDef * usbfs, uint8_t addr)
{
    usbfs->ADDR = ( (usbfs->ADDR & ~USB_FS_ADDR_ADDR_Msk)
                               | (addr & USB_FS_ADDR_ADDR_Msk) )
                               ;
}

/**
  * @brief  Get Device address.
  * @param  usbfs: select the USB peripheral.
  * @retval The device address.
  */
uint8_t USBFS_GetDeviceAddr(USB_FS_TypeDef * usbfs)
{
    return usbfs->ADDR & USB_FS_ADDR_ADDR_Msk;
}

/**
  * @brief  Get Device address.
  * @param  usbfs: select the USB peripheral.
  * @retval The BufDespTable address.
  */
uint32_t  USBFS_GetBufDespTableAddr(USB_FS_TypeDef * usbfs)
{
    return (uint32_t)
        ( ( (usbfs->BDTPAGE1 >> USB_FS_BDTPAGE1_BDT_BA_Pos) << 9u )
        | ( (usbfs->BDTPAGE2 >> USB_FS_BDTPAGE2_BDT_BA_Pos) << 16u)
        | ( (usbfs->BDTPAGE3 >> USB_FS_BDTPAGE3_BDT_BA_Pos) << 24u)
        );
}

/**
  * @brief  Get the USB Frame Number.
  * @param  usbfs: select the USB peripheral.
  * @retval The USB Frame Number.
  */
uint32_t USBFS_GetFrameNumber(USB_FS_TypeDef * usbfs)
{
    return (usbfs->FRMNUML) | (usbfs->FRMNUMH << 8u);
}

/**
  * @brief  Get BufDesp after USB_INT_TOKENDONE interrupt happened and before clear USB_INT_TOKENDONE interrupt status.
  * @param  usbfs: select the USB peripheral.
  * @retval BufDesp address.
  */
USBFS_BufDesp_Type * USBFS_GetBufDesp(USB_FS_TypeDef * usbfs)
{
    USBFS_BufDespTable_Type *bdt = (USBFS_BufDespTable_Type *)USBFS_GetBufDespTableAddr(usbfs);
    return &bdt->Index[usbfs->STAT >> 2];
}

/**
  * @brief  Get Token Pid from BufDesp before the BufDesp Reset.
  * @param  usbfs: select the USB peripheral.
  * @retval Token Pid.
  */
USBFS_TokenPid_Type USBFS_BufDesp_GetTokenPid(USBFS_BufDesp_Type * bd)
{
    return (USBFS_TokenPid_Type)bd->TOK_PID;
}

/**
  * @brief  Get packet addr from BufDesp before the BufDesp Reset.
  * @param  bd: BufDesp addr.
  * @retval Packet addrress.
  */
uint32_t USBFS_BufDesp_GetPacketAddr(USBFS_BufDesp_Type * bd)
{
    return bd->ADDR;
}

/**
  * @brief  Get packet size from BufDesp before the BufDesp Reset.
  * @param  bd: BufDesp addr.
  * @retval Packet size.
  */
uint32_t USBFS_BufDesp_GetPacketSize(USBFS_BufDesp_Type * bd)
{
    return bd->BC;
}

/**
  * @brief  Get packet size from BufDesp before the BufDesp Reset.
  * @param  bd: BufDesp addr.
  * @retval Packet size.
  */
void USBFS_BufDesp_Reset(USBFS_BufDesp_Type * bd)
{
    bd->HEAD = 0u;
}

/**
  * @brief  Get EndPoint index after USB_INT_TOKENDONE interrupt happened and before clear USB_INT_TOKENDONE interrupt status.
  * @param  usbfs: select the USB peripheral.
  * @retval EndPoint index.
  */
uint32_t USBFS_GetEndPointIndex(USB_FS_TypeDef * usbfs)
{
    return (usbfs->STAT & USB_FS_STAT_ENDP_Msk) >> USB_FS_STAT_ENDP_Pos;
}

/**
  * @brief  Get Xfer Direction after USB_INT_TOKENDONE interrupt happened and before clear USB_INT_TOKENDONE interrupt status.
  * @param  usbfs: select the USB peripheral.
  * @retval Packet size.
  */
USBFS_Direction_Type USBFS_GetXferDirection(USB_FS_TypeDef * usbfs)
{
    return (USBFS_Direction_Type)( (usbfs->STAT & USB_FS_STAT_TX_Msk) >> USB_FS_STAT_TX_Pos);
}

/**
  * @brief  Get BufDesp OddEven after USB_INT_TOKENDONE interrupt happened and before clear USB_INT_TOKENDONE interrupt status.
  * @param  usbfs: select the USB peripheral.
  * @retval BufDesp OddEven.
  */
USBFS_BufDesp_OddEven_Type USBFS_GetBufDespOddEven(USB_FS_TypeDef * usbfs)
{
    return (USBFS_BufDesp_OddEven_Type)( (usbfs->STAT & USB_FS_STAT_ODD_Msk) >> USB_FS_STAT_ODD_Pos );
}

/**
  * @brief  Enables or disables the specified USB the end point.
  * @param  usbfs: select the USB peripheral.
  * @param  mode:  End point mode.
  * @param  state: new state of the USB peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void USBFS_EndPointCmd(USB_FS_TypeDef * usbfs, uint32_t index, USBFS_EndPointMode_Type mode, FunctionalState state)
{
    if (DISABLE == state)
    {
        usbfs->EPCTL[index] &= ~ (USB_FS_EPCTL_EP_TX_EN_Msk | USB_FS_EPCTL_EP_RX_EN_Msk| USB_FS_EPCTL_EP_CTL_DIS_Msk |USB_FS_EPCTL_EP_HSHK_Msk);
        USBFS_BufDespTable_Type * bdt = (USBFS_BufDespTable_Type * )USBFS_GetBufDespTableAddr(usbfs);
        bdt->Table[index][0u][0u].HEAD = 0u;
        bdt->Table[index][0u][1u].HEAD = 0u;
        bdt->Table[index][1u][0u].HEAD = 0u;
        bdt->Table[index][1u][1u].HEAD = 0u;
        return;
    }
    if (USBFS_EndPointMode_Control == mode)
    {
        usbfs->EPCTL[index] &= ~ (USB_FS_EPCTL_EP_TX_EN_Msk | USB_FS_EPCTL_EP_RX_EN_Msk| USB_FS_EPCTL_EP_CTL_DIS_Msk |USB_FS_EPCTL_EP_HSHK_Msk);
        usbfs->EPCTL[index] |= (USB_FS_EPCTL_EP_TX_EN_Msk | USB_FS_EPCTL_EP_RX_EN_Msk| USB_FS_EPCTL_EP_HSHK_Msk);
    }
    else if (USBFS_EndPointMode_Bulk == mode)
    {
        usbfs->EPCTL[index] |= (USB_FS_EPCTL_EP_TX_EN_Msk | USB_FS_EPCTL_EP_RX_EN_Msk| USB_FS_EPCTL_EP_CTL_DIS_Msk | USB_FS_EPCTL_EP_HSHK_Msk);
    }
    else if (USBFS_EndPointMode_Interrupt == mode)
    {
        usbfs->EPCTL[index] |= (USB_FS_EPCTL_EP_TX_EN_Msk | USB_FS_EPCTL_EP_RX_EN_Msk| USB_FS_EPCTL_EP_CTL_DIS_Msk | USB_FS_EPCTL_EP_HSHK_Msk);
    }
    else if (USBFS_EndPointMode_Isochronous == mode)
    {
        usbfs->EPCTL[index] &= ~ (USB_FS_EPCTL_EP_TX_EN_Msk | USB_FS_EPCTL_EP_RX_EN_Msk| USB_FS_EPCTL_EP_CTL_DIS_Msk |USB_FS_EPCTL_EP_HSHK_Msk);
        usbfs->EPCTL[index] |= (USB_FS_EPCTL_EP_TX_EN_Msk | USB_FS_EPCTL_EP_RX_EN_Msk| USB_FS_EPCTL_EP_CTL_DIS_Msk);
    }
}

/**
  * @brief  Enables or disables Stall EndPoint n.
  * @param  usbfs: select the USB peripheral.
  * @param  state: new state of the USB EndPoint stall.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void USBFS_EndPointStallCmd(USB_FS_TypeDef * usbfs, FunctionalState state)
{
    uint32_t i = 0;
    
    USBFS_BufDespTable_Type * bdt = (USBFS_BufDespTable_Type * )USBFS_GetBufDespTableAddr(usbfs);
    for (i = 0; i < USBFS_BDT_EP_NUM; i++)
    {
        if (ENABLE == state)
        {
            usbfs->EPCTL[i] |= USB_FS_EPCTL_EP_STALL_Msk;
            bdt->Table[i][USBFS_BufDesp_OddEven_Odd ][USBFS_Direction_IN ].BDT_STALL = 1u;
            bdt->Table[i][USBFS_BufDesp_OddEven_Odd ][USBFS_Direction_OUT].BDT_STALL = 1u;
            bdt->Table[i][USBFS_BufDesp_OddEven_Even][USBFS_Direction_IN ].BDT_STALL = 1u;
            bdt->Table[i][USBFS_BufDesp_OddEven_Even][USBFS_Direction_OUT].BDT_STALL = 1u;
        }
        else
        {
            usbfs->EPCTL[i] &= ~USB_FS_EPCTL_EP_STALL_Msk;
            bdt->Table[i][USBFS_BufDesp_OddEven_Odd ][USBFS_Direction_IN ].BDT_STALL = 0u;
            bdt->Table[i][USBFS_BufDesp_OddEven_Odd ][USBFS_Direction_IN ].OWN       = 0u;
            bdt->Table[i][USBFS_BufDesp_OddEven_Odd ][USBFS_Direction_OUT].BDT_STALL = 0u;
            bdt->Table[i][USBFS_BufDesp_OddEven_Odd ][USBFS_Direction_OUT].OWN       = 0u;
            bdt->Table[i][USBFS_BufDesp_OddEven_Even][USBFS_Direction_IN ].BDT_STALL = 0u;
            bdt->Table[i][USBFS_BufDesp_OddEven_Even][USBFS_Direction_IN ].OWN       = 0u;
            bdt->Table[i][USBFS_BufDesp_OddEven_Even][USBFS_Direction_OUT].BDT_STALL = 0u;
            bdt->Table[i][USBFS_BufDesp_OddEven_Even][USBFS_Direction_OUT].OWN       = 0u;
        }
    }
}

/**
  * @brief  Get Enabled EndPoint stall status.
  * @param  usbfs: select the USB peripheral.
  * @param  ep_mask: new state of the USB EndPoint stall.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval stall status mask codes.
  */
uint32_t USBFS_GetEndPointStallStatus(USB_FS_TypeDef * usbfs, uint32_t ep_mask)
{
    uint32_t status = 0u;
    uint32_t i = 0u;

    for(i = 0u; i < USBFS_BDT_EP_NUM; i++)
    {
        if (0 != (usbfs->EPCTL[i] & USB_FS_EPCTL_EP_STALL_Msk) )
        {
            status |= 1u << i;
        }
    }
    return status;
}

/**
  * @brief  Transmits a Data through the USB peripheral.
  * @param  bd: The USB Buffer Descriptor.
  * @param  data_n: DATAn packet, n equal 0 or 1.
  * @param  data_addr: the address of data.
  * @param  len: Data length.
  * @retval 'SUCCESS': BufDesp can be xfer data, 'ERROR': BufDesp is busy.
  */
ErrorStatus USBFS_BufDesp_Xfer(USBFS_BufDesp_Type * bd, uint32_t data_n, uint8_t * data_addr, uint32_t len)
{
    if (1u == bd->OWN)
    {
        return ERROR;
    }
    bd->ADDR = (uint32_t)data_addr;
    bd->DATA = data_n;
    bd->BC   = len;
    bd->OWN  = 1u;
    return SUCCESS;
}

/**
  * @brief  Check whether BufDesp is busy.
  * @param  bd: The USB Buffer Descriptor.
  * @retval 'SET':  BufDesp is busy, 'RESET': BufDesp is not busy.
  */
FlagStatus USBFS_BufDesp_IsBusy(USBFS_BufDesp_Type * bd)
{
    if (1u == bd->OWN)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/**
  * @brief  Enable or disable USB low speed in host mode.
  * @param  usbfs: select the USB peripheral.
  * @param  state: the status of USB Low Speed mode.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void USBFS_LowSpeedCmd(USB_FS_TypeDef * usbfs, FunctionalState state)
{
    if (state)
    {
        usbfs->ADDR |= USB_FS_ADDR_LS_EN_Msk;
        usbfs->EPCTL[0] |= USB_FS_EPCTL_HOST_WO_HUB_Msk;
    }
    else
    {
        usbfs->ADDR &= ~USB_FS_ADDR_LS_EN_Msk;
        usbfs->EPCTL[0] &= ~USB_FS_EPCTL_HOST_WO_HUB_Msk;
    }
}

/**
  * @brief  Set the token of transmit data in host mode.
  * @param  usbfs: select the USB peripheral.
  * @param  ep_num: The device endpoint number, the available range would be 0 ~ 15.
  * @param  token_pid: The token pid.
  * @retval None.
  */
bool USBFS_SetToken(USB_FS_TypeDef * usbfs, uint32_t ep_num, USBFS_TokenPid_Type token_pid)
{
    if (0 != (usbfs->CTL & USB_FS_CTL_TXDSUSPENDTOKENBUSY_Msk) )
    {
        return false;
    }
    usbfs->TOKEN = (ep_num&USB_FS_TOKEN_TOKEN_ENDPT_Msk) | ((token_pid<<USB_FS_TOKEN_TOKEN_PID_Pos)&USB_FS_TOKEN_TOKEN_PID_Msk);
    return true;
}

/**
  * @brief  Enable or disable the USB Bus Reset.
  * This function can only be used in host mode.
  * The USB Bus Reset Signal is keep SE0 signal for more than 10ms.
  * Enable this function to start make USB Bus keep SE0 signal.
  * After 10ms, disable this function, complete the USB Bus Reset Signal.
  * @param  usbfs: select the USB peripheral.
  * @param  ep_num: The device endpoint number, the available range would be 0 ~ 15.
  * @param  token_pid: The token pid.
  * @retval None.
  */
void USBFS_BusResetCmd(USB_FS_TypeDef * usbfs, FunctionalState state)
{
    if (state)
    {
        usbfs->CTL |= USB_FS_CTL_RESET_Msk;
    }
    else
    {
        usbfs->CTL &= ~USB_FS_CTL_RESET_Msk;
    }
}

/**
  * @brief Get the USB bus signal status.
  * @param  usbfs: select the USB peripheral.
  * @retval the USB bus signal status.
  */
USBFS_BusSignalStatus_Type USBFS_GetBusSignalStatus(USB_FS_TypeDef * usbfs)
{
    if ( 0 == (usbfs->CTL & USB_FS_CTL_JSTATE_Msk) && 0 != (usbfs->CTL & USB_FS_CTL_SE0_Msk) )
    {
        return USBFS_BusSignalStatus_SE0;
    }
    else if ( 0 != (usbfs->CTL & USB_FS_CTL_JSTATE_Msk) && 0 == (usbfs->CTL & USB_FS_CTL_SE0_Msk) )
    {
        return USBFS_BusSignalStatus_J;
    }
    else
    {
        return USBFS_BusSignalStatus_Other;
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
