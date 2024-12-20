/***********************************************************************************************************************
    @file     hal_usbfs.h
    @author   FD TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE UART
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
#ifndef __HAL_USBFS_H__
#define __HAL_USBFS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/*!
 * @brief USB BufDesp EndPoint number.
 */
#define USBFS_BDT_EP_NUM             16u  /*!< USB BufDesp EndPoint num. */

/*!
 * @brief USB BufDesp EndPoint direction number.
 */
#define USBFS_BDT_DIRECTION_NUM      2u  /*!< USB BufDesp EndPoint direction num. */

/*!
 * @brief  USB BufDesp EndPoint buffer number.
 */
#define USBFS_BDT_BUF_NUM            2u  /*!< USB BufDesp EndPoint buffer num. */

/**
  * @brief  USBFS interruput definition
  */
#define USBFS_IT_RESET               USB_FS_INTENB_USB_RST_Msk     /*!< USB Interrupt: USB bus reset.  */
#define USBFS_IT_ERROR               USB_FS_INTENB_ERROR_Msk       /*!< USB Interrupt: Error happend.  */
#define USBFS_IT_SOFTOK              USB_FS_INTENB_SOF_TOK_Msk     /*!< USB Interrupt: Recv a SOF_Tok. */
#define USBFS_IT_TOKENDONE           USB_FS_INTENB_TOK_DNE_Msk     /*!< USB Interrupt: Token done.     */
#define USBFS_IT_SLEEP               USB_FS_INTENB_SLEEP_Msk       /*!< USB Interrupt: Sleep.          */
#define USBFS_IT_RESUME              USB_FS_INTENB_RESUME_Msk      /*!< USB Interrupt: Resume.         */
#define USBFS_IT_ATTACH              USB_FS_INTENB_ATTACH_Msk      /*!< USB Interrupt: Attach.         */
#define USBFS_IT_STALL               USB_FS_INTENB_STALL_Msk       /*!< USB Interrupt: Stall.          */

/**
  * @brief  USBFS interruput error mask codes definition
  */
#define USBFS_IT_ERR_PID             USB_FS_ERRENB_PID_ERR_Msk     /*!< USB Error: PID check error.    */
#define USBFS_IT_ERR_CRC5            USB_FS_ERRENB_CRC5EOF_Msk     /*!< USB Error: CRC5 check failed.  */
#define USBFS_IT_ERR_EOF             USB_FS_ERRENB_CRC5EOF_Msk     /*!< USB Error: EOF Error.          */
#define USBFS_IT_ERR_CRC16           USB_FS_ERRENB_CRC16_Msk       /*!< USB Error: CRC16 check failed. */
#define USBFS_IT_ERR_DFN8            USB_FS_ERRENB_DFN8_Msk        /*!< USB Error: Data not 8bit.      */
#define USBFS_IT_ERR_BTO             USB_FS_ERRENB_BTO_ERR_Msk     /*!< USB Error: BTO error.          */
#define USBFS_IT_ERR_DMA             USB_FS_ERRENB_DMA_ERR_Msk     /*!< USB Error: DMA error.          */
#define USBFS_IT_ERR_BTS             USB_FS_ERRENB_BTS_ERR_Msk     /*!< USB Error: Bit stuff error.    */

/**
  * @brief  USBFS EndPoint mask codes
  */
#define USBFS_EP_0                   (1u << 0u )    /*!< EndPoint 0.  */
#define USBFS_EP_1                   (1u << 1u )    /*!< EndPoint 1.  */
#define USBFS_EP_2                   (1u << 2u )    /*!< EndPoint 2.  */
#define USBFS_EP_3                   (1u << 3u )    /*!< EndPoint 3.  */
#define USBFS_EP_4                   (1u << 4u )    /*!< EndPoint 4.  */
#define USBFS_EP_5                   (1u << 5u )    /*!< EndPoint 5.  */
#define USBFS_EP_6                   (1u << 6u )    /*!< EndPoint 6.  */
#define USBFS_EP_7                   (1u << 7u )    /*!< EndPoint 7.  */
#define USBFS_EP_8                   (1u << 8u )    /*!< EndPoint 8.  */
#define USBFS_EP_9                   (1u << 9u )    /*!< EndPoint 9.  */
#define USBFS_EP_10                  (1u << 10u)    /*!< EndPoint 10. */
#define USBFS_EP_11                  (1u << 11u)    /*!< EndPoint 11. */
#define USBFS_EP_12                  (1u << 12u)    /*!< EndPoint 12. */
#define USBFS_EP_13                  (1u << 13u)    /*!< EndPoint 13. */
#define USBFS_EP_14                  (1u << 14u)    /*!< EndPoint 14. */
#define USBFS_EP_15                  (1u << 15u)    /*!< EndPoint 15. */

/**
  * @brief USBFS TokenPid type.
  */
typedef enum
{
    USBFS_TokenPid_OUT   = 0x1u, /*!< USB Token Pid: OUT.   */
    USBFS_TokenPid_IN    = 0x9u, /*!< USB Token Pid: IN.    */
    USBFS_TokenPid_SETUP = 0xDu, /*!< USB Token Pid: SETUP. */
    USBFS_TokenPid_DATA0 = 0x03, /*!< USB Token Pid: DATA0. */
    USBFS_TokenPid_DATA1 = 0x0B, /*!< USB Token Pid: DATA1. */
    USBFS_TokenPid_ACK   = 0x02, /*!< USB Token Pid: ACK.   */
    USBFS_TokenPid_STALL = 0x0E, /*!< USB Token Pid: STALL. */
    USBFS_TokenPid_NAK   = 0x0A, /*!< USB Token Pid: NAK.   */
    USBFS_TokenPid_BUSTIMEOUT = 0x00, /*!< USB Token Pid: BUSTO. */
    USBFS_TokenPid_ERR   = 0x0f, /*!< USB Token Pid: ERR.   */
} USBFS_TokenPid_Type;

/**
  * @brief USBFS USB Direction type.
  */
typedef enum
{
    USBFS_Direction_OUT = 0x0u, /*!< USB Direstion: OUT.   */
    USBFS_Direction_IN  = 0x1u, /*!< USB Direstion: IN.    */
    USBFS_Direction_NULL,       /*!< USB Direstion: NULL.  */
} USBFS_Direction_Type;

/**
  * @brief USBFS BufDesp OddEven type.
  */
typedef enum
{
    USBFS_BufDesp_OddEven_Even = 0x0u, /*!< Buffer Descriptor OddEven: Even. */
    USBFS_BufDesp_OddEven_Odd  = 0x1u, /*!< Buffer Descriptor OddEven: Odd.  */
} USBFS_BufDesp_OddEven_Type;

/**
  * @brief USBFS EndPoint Mode.
  */
typedef enum
{
    USBFS_EndPointMode_Control     = 1u, /*!< USB EndPoint Mode: Control xfer.   */
    USBFS_EndPointMode_Bulk        = 2u, /*!< USB EndPoint Mode: Bulk xfer.      */
    USBFS_EndPointMode_Interrupt   = 3u, /*!< USB EndPoint Mode: Interrupt xfer. */
    USBFS_EndPointMode_Isochronous = 4u, /*!< USB EndPoint Mode: isoch xfer.     */
    USBFS_EndPointMode_NULL,             /*!< USB EndPoint Mode: NULL.           */
} USBFS_EndPointMode_Type;

/**
  * @brief USBFS bus signal status type..
  */
typedef enum
{
    USBFS_BusSignalStatus_Other    = 0u, /*!< USB Bus Signal Status: Other. */
    USBFS_BusSignalStatus_SE0      = 1u, /*!< USB Bus Signal Status: SE0.   */
    USBFS_BusSignalStatus_J        = 2u, /*!< USB Bus Signal Status: J.     */
} USBFS_BusSignalStatus_Type;

/**
  * @brief USB Device Init Structure definition.
  */
typedef struct
{
    uint32_t BufDespTable_Addr; /*!< BufDespTable addr. */
} USBFS_Device_Init_Type;

/**
  * @brief USB Host Init Structure definition.
  */
typedef struct
{
    uint32_t BufDespTable_Addr; /*!< BufDespTable addr. */
    uint32_t SofThreshold;      /*!< SOF threshold.
                                     This value will decide how long to stop sending new packets before sending the next SOF token
                                     to avoid conflicts between the packets being sent and the SOF token.
                                     The time of stop sending new packets is (SofThreshold / 12000)ms.
                                     The available range would be 0 ~ 255. */
    bool     NakRetry;          /*!< NAK retry. 
                                     'true' to allow xfer retry when received NAK until ACK is received. 
                                     'false' to not allow xfer retry when received NAK. */
} USBFS_Host_Init_Type;

/*!
 * @brief This type of structure instance is used to implement the buffer descriptor for USB.
 */
typedef struct
{
    union
    {
        uint32_t HEAD; /*!< Head. */
        struct
        {
            uint32_t RESERVED0  :2;  /*!< RESEVED. */
            uint32_t BDT_STALL  :1;  /*!< Stall. */
            uint32_t DTS        :1;  /*!< Data shift sync. */
            uint32_t NINC       :1;  /*!< DMA addr cannot increasing. */
            uint32_t KEEP       :1;  /*!< Keep BD held by USB. */
            uint32_t DATA       :1;  /*!< DATA0 or DATA1. */
            uint32_t OWN        :1;  /*!< Owner, 0 is CPU, 1 is USB. */
            uint32_t RESERVED1  :8;  /*!< RESEVED. */
            uint32_t BC         :10; /*!< Packet size. */
            uint32_t RESERVED2  :6;  /*!< RESEVED. */
        };
        struct
        {
            uint32_t RESERVED3  :2;  /*!< RESEVED. */
            uint32_t TOK_PID    :4;  /*!< Token pid. */
            uint32_t RESERVED4  :26; /*!< RESEVED. */
        };
    };
    uint32_t ADDR; /*!< Buffer addr. */
} USBFS_BufDesp_Type;

/*!
 * @brief This type of structure instance is used to implement the buffer descriptor table for USB.
 */
typedef union
{
    USBFS_BufDesp_Type Table[USBFS_BDT_EP_NUM][ USBFS_BDT_DIRECTION_NUM][ USBFS_BDT_BUF_NUM]; /*!< [EndPoint] [Direction] [Odd_Even]. */
    USBFS_BufDesp_Type Index[USBFS_BDT_EP_NUM * USBFS_BDT_DIRECTION_NUM * USBFS_BDT_BUF_NUM]; /*!< Index. */
} USBFS_BufDespTable_Type;

/** @defgroup USBFS_Exported_Functions
  * @{
  */
void USBFS_DeInit(USB_FS_TypeDef * usbfs);
void USBFS_InitDevice(USB_FS_TypeDef * usbfs, USBFS_Device_Init_Type * init);
void USBFS_InitHost(USB_FS_TypeDef * usbfs, USBFS_Host_Init_Type * init);
void USBFS_Cmd(USB_FS_TypeDef * usbfs, FunctionalState state);

void USBFS_ITConfig(USB_FS_TypeDef * usbfs, uint32_t interrupt, FunctionalState state);
ITStatus USBFS_GetITStatus(USB_FS_TypeDef * usbfs, uint32_t interrupt);
uint32_t USBFS_GetEnabledITStatus(USB_FS_TypeDef * usbfs);
void USBFS_ClearITPendingBit(USB_FS_TypeDef * usbfs, uint32_t interrupt);
void USBFS_ErrITConfig(USB_FS_TypeDef * usbfs, uint32_t interrupt, FunctionalState state);
ITStatus USBFS_GetErrITStatus(USB_FS_TypeDef * usbfs, uint32_t interrupt);
void USBFS_ClearErrITPendingBit(USB_FS_TypeDef * usbfs, uint32_t interrupt);

void USBFS_OddEvenResetCmd(USB_FS_TypeDef * usbfs, FunctionalState state);
void USBFS_ResumeSignalCmd(USB_FS_TypeDef * usbfs, FunctionalState state);
void USBFS_SuspendCmd(USB_FS_TypeDef * usbfs, FunctionalState state);

void USBFS_SetDeviceAddr(USB_FS_TypeDef * usbfs, uint8_t addr);
uint8_t USBFS_GetDeviceAddr(USB_FS_TypeDef * usbfs);
uint32_t USBFS_GetBufDespTableAddr(USB_FS_TypeDef * usbfs);
uint32_t USBFS_GetFrameNumber(USB_FS_TypeDef * usbfs);
USBFS_BufDesp_Type * USBFS_GetBufDesp(USB_FS_TypeDef * usbfs);
USBFS_TokenPid_Type USBFS_BufDesp_GetTokenPid(USBFS_BufDesp_Type * bd);
uint32_t USBFS_BufDesp_GetPacketAddr(USBFS_BufDesp_Type * bd);
uint32_t USBFS_BufDesp_GetPacketSize(USBFS_BufDesp_Type * bd);
void USBFS_BufDesp_Reset(USBFS_BufDesp_Type * bd);
uint32_t USBFS_GetEndPointIndex(USB_FS_TypeDef * usbfs);
USBFS_Direction_Type USBFS_GetXferDirection(USB_FS_TypeDef * usbfs);
USBFS_BufDesp_OddEven_Type USBFS_GetBufDespOddEven(USB_FS_TypeDef * usbfs);
void USBFS_EndPointCmd(USB_FS_TypeDef * usbfs, uint32_t index, USBFS_EndPointMode_Type mode, FunctionalState state);
void USBFS_EndPointStallCmd(USB_FS_TypeDef * usbfs, FunctionalState state);
FunctionalState USB_GetEndPointStallStatus(USB_FS_TypeDef * usbfs);
ErrorStatus USBFS_BufDesp_Xfer(USBFS_BufDesp_Type * bd, uint32_t data_n, uint8_t * data_addr, uint32_t len);
FlagStatus USBFS_BufDesp_IsBusy(USBFS_BufDesp_Type * bd);
void USBFS_LowSpeedCmd(USB_FS_TypeDef * usbfs, FunctionalState state);
bool USBFS_SetToken(USB_FS_TypeDef * usbfs, uint32_t ep_num, USBFS_TokenPid_Type token_pid);
void USBFS_BusResetCmd(USB_FS_TypeDef * usbfs, FunctionalState state);
USBFS_BusSignalStatus_Type USBFS_GetBusSignalStatus(USB_FS_TypeDef * usbfs);

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

/*----------------------------------------------------------------------------*/
#endif /* __HAL_USBFS_H ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
