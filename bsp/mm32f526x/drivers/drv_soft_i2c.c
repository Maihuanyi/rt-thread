/*
 * Copyright (c) 2024, Chasel
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-01-06     Chasel       first commit
 */

#include "drv_soft_i2c.h"

#if defined(BSP_USING_I2C1) || defined(BSP_USING_I2C2)


static const struct mm32_soft_i2c_config soft_i2c_config[] =
{
#ifdef BSP_USING_I2C1
    I2C1_BUS_CONFIG,
#endif
#ifdef BSP_USING_I2C2
    I2C2_BUS_CONFIG,
#endif
};

static struct mm32_i2c i2c_obj[sizeof(soft_i2c_config) / sizeof(soft_i2c_config[0])];

/**
 * This function initializes the i2c pin.
 *
 * @param mm32 i2c dirver class.
 */
static void mm32_i2c_gpio_init(struct mm32_i2c *i2c)
{
    struct mm32_soft_i2c_config* cfg = (struct mm32_soft_i2c_config*)i2c->ops.data;

    rt_pin_mode(cfg->scl, PIN_MODE_OUTPUT_OD);
    rt_pin_mode(cfg->sda, PIN_MODE_OUTPUT_OD);

    rt_pin_write(cfg->scl, PIN_HIGH);
    rt_pin_write(cfg->sda, PIN_HIGH);
}

static void mm32_i2c_pin_init(void)
{
    rt_size_t obj_num = sizeof(i2c_obj) / sizeof(struct mm32_i2c);

    for(rt_size_t i = 0; i < obj_num; i++)
    {
        mm32_i2c_gpio_init(&i2c_obj[i]);
    }
}

/**
 * This function sets the sda pin.
 *
 * @param mm32 config class.
 * @param The sda pin state.
 */
static void mm32_set_sda(void *data, rt_int32_t state)
{
    struct mm32_soft_i2c_config* cfg = (struct mm32_soft_i2c_config*)data;
    if (state)
    {
        rt_pin_write(cfg->sda, PIN_HIGH);
    }
    else
    {
        rt_pin_write(cfg->sda, PIN_LOW);
    }
}

/**
 * This function sets the scl pin.
 *
 * @param mm32 config class.
 * @param The scl pin state.
 */
static void mm32_set_scl(void *data, rt_int32_t state)
{
    struct mm32_soft_i2c_config* cfg = (struct mm32_soft_i2c_config*)data;
    if (state)
    {
        rt_pin_write(cfg->scl, PIN_HIGH);
    }
    else
    {
        rt_pin_write(cfg->scl, PIN_LOW);
    }
}

/**
 * This function gets the sda pin state.
 *
 * @param The sda pin state.
 */
static rt_int32_t mm32_get_sda(void *data)
{
    struct mm32_soft_i2c_config* cfg = (struct mm32_soft_i2c_config*)data;
    return rt_pin_read(cfg->sda);
}

/**
 * This function gets the scl pin state.
 *
 * @param The scl pin state.
 */
static rt_int32_t mm32_get_scl(void *data)
{
    struct mm32_soft_i2c_config* cfg = (struct mm32_soft_i2c_config*)data;
    return rt_pin_read(cfg->scl);
}

static const struct rt_i2c_bit_ops mm32_bit_ops_default =
{
    .data     = RT_NULL,
    .pin_init = mm32_i2c_pin_init,
    .set_sda  = mm32_set_sda,
    .set_scl  = mm32_set_scl,
    .get_sda  = mm32_get_sda,
    .get_scl  = mm32_get_scl,
    .udelay   = rt_hw_us_delay,
    .delay_us = 1,
    .timeout  = 100,
    .i2c_pin_init_flag = RT_FALSE
};

/**
 * if i2c is locked, this function will unlock it
 *
 * @param mm32 config class
 *
 * @return RT_EOK indicates successful unlock.
 */
static rt_err_t mm32_i2c_bus_unlock(const struct mm32_soft_i2c_config *cfg)
{
    rt_int32_t i = 0;

    if (PIN_LOW == rt_pin_read(cfg->sda))
    {
        while (i++ < 9)
        {
            rt_pin_write(cfg->scl, PIN_HIGH);
            rt_hw_us_delay(100);
            rt_pin_write(cfg->scl, PIN_LOW);
            rt_hw_us_delay(100);
        }
    }
    if (PIN_LOW == rt_pin_read(cfg->sda))
    {
        return -RT_ERROR;
    }

    return RT_EOK;
}

/* I2C initialization function */
int rt_hw_i2c_init(void)
{
    rt_err_t result;

    for (rt_size_t i = 0; i < sizeof(i2c_obj) / sizeof(struct mm32_i2c); i++)
    {
        i2c_obj[i].ops = mm32_bit_ops_default;
        i2c_obj[i].ops.data = (void*)&soft_i2c_config[i];
        i2c_obj[i].i2c_bus.priv = &i2c_obj[i].ops;
        result = rt_i2c_bit_add_bus(&i2c_obj[i].i2c_bus, soft_i2c_config[i].bus_name);
        RT_ASSERT(result == RT_EOK);
        mm32_i2c_bus_unlock(&soft_i2c_config[i]);
    }

    return RT_EOK;
}
INIT_BOARD_EXPORT(rt_hw_i2c_init);

#endif /* defined(BSP_USING_I2C1) || defined(BSP_USING_I2C2) */
