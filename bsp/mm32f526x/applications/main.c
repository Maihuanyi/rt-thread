/*
 * Copyright (c) 2017-2019, Chasel
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-01-06     Chasel       first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "hal_device.h"

/* defined the LED pin: PB15 */
#define LED_PIN    31

int main(void)
{
   int count = 1;
    /* set LED1 pin mode to output */
    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);

    while (count++) {
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }

    return RT_EOK;
}
