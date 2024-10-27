#ifndef UMIUSI_NUCLEO_CUBE_GPIO_H
#define UMIUSI_NUCLEO_CUBE_GPIO_H

#include "stm32f3xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    GpioA,
    GpioB,
    GpioC,
    GpioD,
    GpioF,
} GpioPort;

void gpio_init(GpioPort port, uint16_t gpio_pin);

void gpio_toggle(GpioPort port, uint16_t gpio_pin);

void gpio_write(GpioPort port, uint16_t gpio_pin, GPIO_PinState state);

#ifdef __cplusplus
}
#endif

#endif
