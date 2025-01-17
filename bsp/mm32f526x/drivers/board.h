/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-05     mazhiyuan   first version
 */

#ifndef __BOARD_H__
#define __BOARD_H__
#include <rtthread.h>
#include "hal_device.h"
#include "mm32_device.h"

#define SRAM_SIZE 0x1C000

#define SRAM_END (SRAM_BASE + SRAM_SIZE)
#ifdef __CC_ARM
    extern int Image$$RW_IRAM1$$ZI$$Limit;
    #define HEAP_BEGIN ((void *)&Image$$RW_IRAM1$$ZI$$Limit)
#elif __ICCARM__
    #pragma section = "HEAP"
    #define HEAP_BEGIN (__segment_end("HEAP"))
#else
    extern int __bss_end;
    #define HEAP_BEGIN ((void *)&__bss_end)
#endif
#define HEAP_END SRAM_END
#define HEAP_SIZE (HEAP_END - (rt_uint32_t)HEAP_BEGIN)
extern void rt_hw_board_init(void);
#endif
