/*
 * Copyright (c) 2025, Chasel
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-01-06     Chasel       first version
 */

#ifndef __DRV_I2C__
#define __DRV_I2C__

#include <rtthread.h>
#include <rthw.h>
#include <rtdevice.h>

/* mm32 config class */
struct mm32_soft_i2c_config
{
    rt_uint8_t scl;
    rt_uint8_t sda;
    const char *bus_name;
};
/* mm32 i2c dirver class */
struct mm32_i2c
{
    struct rt_i2c_bit_ops ops;
    struct rt_i2c_bus_device i2c_bus;
};

#ifdef BSP_USING_I2C1
#define I2C1_BUS_CONFIG                                  \
    {                                                    \
        .scl = BSP_I2C1_SCL_PIN,                         \
        .sda = BSP_I2C1_SDA_PIN,                         \
        .bus_name = "i2c1",                              \
    }
#endif

#ifdef BSP_USING_I2C2
#define I2C2_BUS_CONFIG                                  \
    {                                                    \
        .scl = BSP_I2C2_SCL_PIN,                         \
        .sda = BSP_I2C2_SDA_PIN,                         \
        .bus_name = "i2c2",                              \
    }
#endif

int rt_hw_i2c_init(void);

#endif
