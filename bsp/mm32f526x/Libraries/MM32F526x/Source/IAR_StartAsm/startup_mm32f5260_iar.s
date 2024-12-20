;/***********************************************************************************************************************
;    @file     startup_mm32f5270_iar.s
;    @author   VV TEAM
;    @brief    CMSIS Core Device Startup File 
;  **********************************************************************************************************************
;    @attention
;
;    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>
;
;      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
;    following conditions are met:
;    1. Redistributions of source code must retain the above copyright notice,
;       this list of conditions and the following disclaimer.
;    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
;       the following disclaimer in the documentation and/or other materials provided with the distribution.
;    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
;       promote products derived from this software without specific prior written permission.
;
;      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
;    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
;    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
;    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;  *********************************************************************************************************************/


                MODULE  ?cstartup

                                                                   ; Forward declaration of sections.
                SECTION CSTACK:DATA:NOROOT(3)                     
                                                                  
                SECTION .intvec:CODE:NOROOT(2)                    
                                                                  
                EXTERN  __iar_program_start                       
                EXTERN  SystemInit                                
                PUBLIC  __vector_table                            
                PUBLIC  __vector_table_0x1c                       
                PUBLIC  __Vectors                                 
                PUBLIC  __Vectors_End                             
                PUBLIC  __Vectors_Size                            
                                                                  
                DATA                                              
__vector_table                                                    
                DCD     sfe(CSTACK)                                ;       Top of Stack                    |   0 0x0000
                DCD     Reset_Handler                              ;       Reset Handler                   |   1 0x0004
                DCD     NMI_Handler                                ; -14   NMI Handler                     |   2 0x0008
                DCD     HardFault_Handler                          ; -13   Hard Fault Handler              |   3 0x000C
                DCD     MemManage_Handler                          ; -12   MPU Fault Handler               |   4 0x0010
                DCD     BusFault_Handler                           ; -11   Bus Fault Handler               |   5 0x0014
                DCD     UsageFault_Handler                         ; -10   Usage Fault Handler             |   6 0x0018
__vector_table_0x1c                                               
                DCD     0                                          ;  -9   Reserved                        |   7 0x001C
                DCD     0                                          ;  -8   Reserved                        |   8 0x0020
                DCD     0                                          ;  -7   Reserved                        |   9 0x0024
                DCD     0                                          ;  -6   Reserved                        |  10 0x0028
                DCD     SVCall_Handler                             ;  -5   SVCall Handler                  |  11 0x002C
                DCD     DebugMon_Handler                           ;  -4   Debug Monitor Handler           |  12 0x0030
                DCD     0                                          ;  -3   Reserved                        |  13 0x0034
                DCD     PendSV_Handler                             ;  -2   PendSV Handler                  |  14 0x0038
                DCD     SysTick_Handler                            ;  -1   SysTick Handler                 |  15 0x003C
                                                                  
                ; External Interrupts                             
                DCD     WWDG_IWDG_IRQHandler                       ;   0   WWDG_IWDG through EXTI 21       |  16 0x0040
                DCD     PVD_IRQHandler                             ;   1   PVD through EXTI 16             |  17 0x0044
                DCD     BKP_TAMPER_IRQHandler                      ;   2   BKP Tamper                      |  18 0x0048
                DCD     RTC_IRQHandler                             ;   3   RTC                             |  19 0x004C
                DCD     FLASH_IRQHandler                           ;   4   Flash                           |  20 0x0050
                DCD     RCC_CRS_IRQHandler                         ;   5   RCC                             |  21 0x0054
                DCD     EXTI0_IRQHandler                           ;   6   EXTI Line 0                     |  22 0x0058
                DCD     EXTI1_IRQHandler                           ;   7   EXTI Line 1                     |  23 0x005C
                DCD     EXTI2_IRQHandler                           ;   8   EXTI Line 2                     |  24 0x0060
                DCD     EXTI3_IRQHandler                           ;   9   EXTI Line 3                     |  25 0x0064
                DCD     EXTI4_IRQHandler                           ;  10   EXTI Line 4                     |  26 0x0068
                DCD     DMA1_CH1_IRQHandler                        ;  11   DMA1 Channel 1                  |  27 0x006C
                DCD     DMA1_CH2_IRQHandler                        ;  12   DMA1 Channel 2                  |  28 0x0070
                DCD     DMA1_CH3_IRQHandler                        ;  13   DMA1 Channel 3                  |  29 0x0074
                DCD     DMA1_CH4_IRQHandler                        ;  14   DMA1 Channel 4                  |  30 0x0078
                DCD     DMA1_CH5_IRQHandler                        ;  15   DMA1 Channel 5                  |  31 0x007C
                DCD     DMA1_CH6_IRQHandler                        ;  16   DMA1 Channel 6                  |  32 0x0080
                DCD     DMA1_CH7_IRQHandler                        ;  17   DMA1 Channel 7                  |  33 0x0084
                DCD     ADC1_2_IRQHandler                          ;  18   ADC1 and ADC2                   |  34 0x0088
                DCD     0                                          ;  19   Reserved                        |  35 0x008C
                DCD     DMA1_CH8_IRQHandler                        ;  20   DMA1 Channel 8                  |  36 0x0090
                DCD     FlexCAN1_IRQHandler                        ;  21   FlexCAN1                        |  37 0x0094
                DCD     0                                          ;  22   Reserved                        |  38 0x0098
                DCD     EXTI9_5_IRQHandler                         ;  23   EXTI Line 9..5                  |  39 0x009C
                DCD     TIM1_BRK_IRQHandler                        ;  24   TIM1 Break                      |  40 0x00A0
                DCD     TIM1_UP_IRQHandler                         ;  25   TIM1 Update                     |  41 0x00A4
                DCD     TIM1_TRG_COM_IRQHandler                    ;  26   TIM1 Trigger and Commutation    |  42 0x00A8
                DCD     TIM1_CC_IRQHandler                         ;  27   TIM1 Capture Compare            |  43 0x00AC
                DCD     TIM2_IRQHandler                            ;  28   TIM2                            |  44 0x00B0
                DCD     TIM3_IRQHandler                            ;  29   TIM3                            |  45 0x00B4
                DCD     TIM4_IRQHandler                            ;  30   TIM4                            |  46 0x00B8
                DCD     I2C1_IRQHandler                            ;  31   I2C1 Event                      |  47 0x00BC
                DCD     0                                          ;  32   Reserved                        |  48 0x00C0
                DCD     I2C2_IRQHandler                            ;  33   I2C2 Event                      |  49 0x00C4
                DCD     0                                          ;  34   Reserved                        |  50 0x00C8
                DCD     SPI1_IRQHandler                            ;  35   SPI1                            |  51 0x00CC
                DCD     SPI2_IRQHandler                            ;  36   SPI2                            |  52 0x00D0
                DCD     UART1_IRQHandler                           ;  37   UART1                           |  53 0x00D4
                DCD     UART2_IRQHandler                           ;  38   UART2                           |  54 0x00D8
                DCD     UART3_IRQHandler                           ;  39   UART3                           |  55 0x00DC
                DCD     EXTI15_10_IRQHandler                       ;  40   EXTI Line 15..10                |  56 0x00E0
                DCD     RTC_ALR_IRQHandler                         ;  41   RTC Alarm through EXTI 17       |  57 0x00E4
                DCD     USB_WKUP_IRQHandler                        ;  42   USB OTG FS Wakeup thru EXTI 18  |  58 0x00E8
                DCD     TIM8_BRK_IRQHandler                        ;  43   TIM8 Break                      |  59 0x00EC
                DCD     TIM8_UP_IRQHandler                         ;  44   TIM8 Update                     |  60 0x00F0
                DCD     TIM8_TRG_COM_IRQHandler                    ;  45   TIM8 Trigger and Commutation    |  61 0x00F4
                DCD     TIM8_CC_IRQHandler                         ;  46   TIM8 Capture Compare            |  62 0x00F8
                DCD     0                                          ;  47   Reserved                        |  63 0x00FC
                DCD     0                                          ;  48   Reserved                        |  64 0x0100
                DCD     0                                          ;  49   Reserved                        |  65 0x0104
                DCD     TIM5_IRQHandler                            ;  50   TIM5                            |  66 0x0108
                DCD     SPI3_IRQHandler                            ;  51   SPI3                            |  67 0x010C
                DCD     UART4_IRQHandler                           ;  52   UART4                           |  68 0x0110
                DCD     UART5_IRQHandler                           ;  53   UART5                           |  69 0x0114
                DCD     TIM6_IRQHandler                            ;  54   TIM6                            |  70 0x0118
                DCD     TIM7_IRQHandler                            ;  55   TIM7                            |  71 0x011C
                DCD     DMA2_CH1_IRQHandler                        ;  56   DMA2 Channel 1                  |  72 0x0120
                DCD     DMA2_CH2_IRQHandler                        ;  57   DMA2 Channel 2                  |  73 0x0124
                DCD     DMA2_CH3_IRQHandler                        ;  58   DMA2 Channel 3                  |  74 0x0128
                DCD     DMA2_CH4_IRQHandler                        ;  59   DMA2 Channel 4                  |  75 0x012C
                DCD     DMA2_CH5_IRQHandler                        ;  60   DMA2 Channel 5                  |  76 0x0130
                DCD     ENET_IRQHandler                            ;  61   ENET                            |  77 0x0134
                DCD     ENET_WKUP_IRQHandler                       ;  62   ENET_WKUP                       |  78 0x0138
                DCD     0                                          ;  63   Reserved                        |  79 0x013C
                DCD     COMP_IRQHandler                            ;  64   COMP1,COMP2                     |  80 0x0140
                DCD     FlexCAN2_IRQHandler                        ;  65   FlexCAN2                        |  81 0x0144
                DCD     0                                          ;  66   Reserved                        |  82 0x0148
                DCD     USB_FS_IRQHandler                          ;  67   USB                             |  83 0x014C
                DCD     DMA2_CH6_IRQHandler                        ;  68   DMA2 Channel 6                  |  84 0x0150
                DCD     DMA2_CH7_IRQHandler                        ;  69   DMA2 Channel 7                  |  85 0x0154
                DCD     DMA2_CH8_IRQHandler                        ;  70   DMA2 Channel 8                  |  86 0x0158
                DCD     UART6_IRQHandler                           ;  71   UART6                           |  87 0x015C
                DCD     0                                          ;  72   Reserved                        |  88 0x0160
                DCD     0                                          ;  73   Reserved                        |  89 0x0164
                DCD     0                                          ;  74   Reserved                        |  90 0x0168
                DCD     0                                          ;  75   Reserved                        |  91 0x016C
                DCD     0                                          ;  76   Reserved                        |  92 0x0170
                DCD     0                                          ;  77   Reserved                        |  93 0x0174
                DCD     0                                          ;  78   Reserved                        |  94 0x0178
                DCD     0                                          ;  79   Reserved                        |  95 0x017C
                DCD     0                                          ;  80   Reserved                        |  96 0x0180
                DCD     0                                          ;  81   Reserved                        |  97 0x0184 
                DCD     UART7_IRQHandler                           ;  82   UART7                           |  98 0x0188
                DCD     0                                          ;  83   Reserved                        |  99 0x018C
                DCD     0                                          ;  84   Reserved                        | 100 0x0190
                DCD     0                                          ;  85   Reserved                        | 101 0x0194
                DCD     0                                          ;  86   Reserved                        | 102 0x0198
                DCD     0                                          ;  87   0                               | 103 0x019C
                DCD     0                                          ;  88   Reserved                        | 104 0x01A0
                DCD     0                                          ;  89   Reserved                        | 105 0x01A4
                DCD     0                                          ;  90   Reserved                        | 106 0x01A8
                DCD     0                                          ;  91   Reserved                        | 107 0x01AC
                DCD     0                                          ;  92   Reserved                        | 108 0x01B0
                DCD     0                                          ;  93   Reserved                        | 109 0x01B4
                DCD     0                                          ;  94   Reserved                        | 110 0x01B8
                DCD     QSPI_IRQHandler                            ;  95   QSPI                            | 111 0x01BC
                DCD     0                                          ;  96   Reserved                        | 112 0x01C0
                DCD     0                                          ;  97   Reserved                        | 113 0x01C4
                DCD     0                                          ;  98   Reserved                        | 114 0x01C8
                DCD     0                                          ;  99   Reserved                        | 115 0x01CC
                DCD     0                                          ; 100   Reserved                        | 116 0x01D0
                DCD     0                                          ; 101   Reserved                        | 117 0x01D4
                DCD     LPTIM_IRQHandler                           ; 102   LPTIM interrupt(EXTI22)         | 118 0x01D8
                DCD     0                                          ; 103   Reserved                        | 119 0x01DC
                DCD     LPUART_IRQHandler                          ; 104   LPUART interrupt(EXTI23)        | 120 0x01E0
                DCD     0                                          ; 105   Reserved                        | 121 0x01E4
                DCD     0                                          ; 106   Reserved                        | 122 0x01E8
                DCD     0                                          ; 107   Reserved                        | 123 0x01EC
                                                                  
                DS32    (370)                                      ; Interrupts 10 .. 480 are left out  
__Vectors_End

__Vectors       EQU     __vector_table
__Vectors_Size  EQU     __Vectors_End - __Vectors



                THUMB

; Reset Handler

                PUBWEAK Reset_Handler
                SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__iar_program_start
                BX      R0


                PUBWEAK NMI_Handler
                PUBWEAK HardFault_Handler
                PUBWEAK MemManage_Handler
                PUBWEAK BusFault_Handler
                PUBWEAK UsageFault_Handler
                PUBWEAK SVCall_Handler
                PUBWEAK DebugMon_Handler
                PUBWEAK PendSV_Handler
                PUBWEAK SysTick_Handler
                PUBWEAK WWDG_IWDG_IRQHandler
                PUBWEAK PVD_IRQHandler
                PUBWEAK BKP_TAMPER_IRQHandler
                PUBWEAK RTC_IRQHandler
                PUBWEAK FLASH_IRQHandler
                PUBWEAK RCC_CRS_IRQHandler
                PUBWEAK EXTI0_IRQHandler
                PUBWEAK EXTI1_IRQHandler
                PUBWEAK EXTI2_IRQHandler
                PUBWEAK EXTI3_IRQHandler
                PUBWEAK EXTI4_IRQHandler
                PUBWEAK DMA1_CH1_IRQHandler
                PUBWEAK DMA1_CH2_IRQHandler
                PUBWEAK DMA1_CH3_IRQHandler
                PUBWEAK DMA1_CH4_IRQHandler
                PUBWEAK DMA1_CH5_IRQHandler
                PUBWEAK DMA1_CH6_IRQHandler
                PUBWEAK DMA1_CH7_IRQHandler
                PUBWEAK ADC1_2_IRQHandler
                PUBWEAK DMA1_CH8_IRQHandler
                PUBWEAK FlexCAN1_IRQHandler
                PUBWEAK EXTI9_5_IRQHandler
                PUBWEAK TIM1_BRK_IRQHandler
                PUBWEAK TIM1_UP_IRQHandler
                PUBWEAK TIM1_TRG_COM_IRQHandler
                PUBWEAK TIM1_CC_IRQHandler
                PUBWEAK TIM2_IRQHandler
                PUBWEAK TIM3_IRQHandler
                PUBWEAK TIM4_IRQHandler
                PUBWEAK I2C1_IRQHandler
                PUBWEAK I2C2_IRQHandler
                PUBWEAK SPI1_IRQHandler
                PUBWEAK SPI2_IRQHandler
                PUBWEAK UART1_IRQHandler
                PUBWEAK UART2_IRQHandler
                PUBWEAK UART3_IRQHandler
                PUBWEAK EXTI15_10_IRQHandler
                PUBWEAK RTC_ALR_IRQHandler
                PUBWEAK USB_WKUP_IRQHandler
                PUBWEAK TIM8_BRK_IRQHandler
                PUBWEAK TIM8_UP_IRQHandler
                PUBWEAK TIM8_TRG_COM_IRQHandler
                PUBWEAK TIM8_CC_IRQHandler
                PUBWEAK TIM5_IRQHandler
                PUBWEAK SPI3_IRQHandler
                PUBWEAK UART4_IRQHandler
				PUBWEAK UART5_IRQHandler
                PUBWEAK TIM6_IRQHandler
                PUBWEAK TIM7_IRQHandler
                PUBWEAK DMA2_CH1_IRQHandler
                PUBWEAK DMA2_CH2_IRQHandler
                PUBWEAK DMA2_CH3_IRQHandler
                PUBWEAK DMA2_CH4_IRQHandler
                PUBWEAK DMA2_CH5_IRQHandler
				PUBWEAK ENET_IRQHandler
			    PUBWEAK ENET_WKUP_IRQHandler
                PUBWEAK COMP_IRQHandler
                PUBWEAK FlexCAN2_IRQHandler
                PUBWEAK USB_FS_IRQHandler
                PUBWEAK DMA2_CH6_IRQHandler
                PUBWEAK DMA2_CH7_IRQHandler
                PUBWEAK DMA2_CH8_IRQHandler
                PUBWEAK UART6_IRQHandler
                PUBWEAK UART7_IRQHandler
                PUBWEAK QSPI_IRQHandler
                PUBWEAK LPTIM_IRQHandler
                PUBWEAK LPUART_IRQHandler

                SECTION .text:CODE:REORDER:NOROOT(1)
				
				
NMI_Handler
HardFault_Handler
MemManage_Handler
BusFault_Handler
UsageFault_Handler
SVCall_Handler
DebugMon_Handler
PendSV_Handler
SysTick_Handler
WWDG_IWDG_IRQHandler
PVD_IRQHandler
BKP_TAMPER_IRQHandler
RTC_IRQHandler
FLASH_IRQHandler
RCC_CRS_IRQHandler
EXTI0_IRQHandler
EXTI1_IRQHandler
EXTI2_IRQHandler
EXTI3_IRQHandler
EXTI4_IRQHandler
DMA1_CH1_IRQHandler
DMA1_CH2_IRQHandler
DMA1_CH3_IRQHandler
DMA1_CH4_IRQHandler
DMA1_CH5_IRQHandler
DMA1_CH6_IRQHandler
DMA1_CH7_IRQHandler
ADC1_2_IRQHandler
DMA1_CH8_IRQHandler
FlexCAN1_IRQHandler
EXTI9_5_IRQHandler
TIM1_BRK_IRQHandler
TIM1_UP_IRQHandler
TIM1_TRG_COM_IRQHandler
TIM1_CC_IRQHandler
TIM2_IRQHandler
TIM3_IRQHandler
TIM4_IRQHandler
I2C1_IRQHandler
I2C2_IRQHandler
SPI1_IRQHandler
SPI2_IRQHandler
UART1_IRQHandler
UART2_IRQHandler
UART3_IRQHandler
EXTI15_10_IRQHandler
RTC_ALR_IRQHandler
USB_WKUP_IRQHandler
TIM8_BRK_IRQHandler
TIM8_UP_IRQHandler
TIM8_TRG_COM_IRQHandler
TIM8_CC_IRQHandler
TIM5_IRQHandler
SPI3_IRQHandler
UART4_IRQHandler
UART5_IRQHandler
TIM6_IRQHandler
TIM7_IRQHandler
DMA2_CH1_IRQHandler
DMA2_CH2_IRQHandler
DMA2_CH3_IRQHandler
DMA2_CH4_IRQHandler
DMA2_CH5_IRQHandler
ENET_IRQHandler
ENET_WKUP_IRQHandler
COMP_IRQHandler
FlexCAN2_IRQHandler
USB_FS_IRQHandler
DMA2_CH6_IRQHandler
DMA2_CH7_IRQHandler
DMA2_CH8_IRQHandler
UART6_IRQHandler
UART7_IRQHandler
QSPI_IRQHandler
LPTIM_IRQHandler
LPUART_IRQHandler

Default_Handler
                B       .
                END


