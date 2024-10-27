#include "gpio.h"

class Gpio {
private:
    GPIO_TypeDef* port;

public:
    Gpio(GPIO_TypeDef* port) : port(port) {}

    static Gpio from(GpioPort port) {
        switch (port) {
        case GpioA: return Gpio{ GPIOA };
        case GpioB: return Gpio{ GPIOB };
        case GpioC: return Gpio{ GPIOC };
        case GpioD: return Gpio{ GPIOD };
        case GpioF: return Gpio{ GPIOF };
        }
    }

    void init(uint16_t pin) {
        /* GPIO Ports Clock Enable */
        if (this->port == GPIOA) {
            __HAL_RCC_GPIOA_CLK_ENABLE();
        } else if (this->port == GPIOB) {
            __HAL_RCC_GPIOB_CLK_ENABLE();
        } else if (this->port == GPIOD) {
            __HAL_RCC_GPIOD_CLK_ENABLE();
        } else if (this->port == GPIOF) {
            __HAL_RCC_GPIOF_CLK_ENABLE();
        }
        /*Configure GPIO pin Output Level */
        HAL_GPIO_WritePin(this->port, pin, GPIO_PIN_RESET);

        /*Configure GPIO pin : GPIO_PIN */
        GPIO_InitTypeDef gpio_init = {};
        gpio_init.Pin = pin;
        gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
        gpio_init.Pull = GPIO_NOPULL;
        gpio_init.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(this->port, &gpio_init);
    }

    void toggle(uint16_t pin) {
        HAL_GPIO_TogglePin(this->port, pin);
    }

    void write(uint16_t pin, GPIO_PinState state) {
        HAL_GPIO_WritePin(this->port, pin, state);
    }
};

extern "C" {
void gpio_init(GpioPort port, uint16_t gpio_pin) {
    Gpio::from(port).init(gpio_pin);
}

void gpio_toggle(GpioPort port, uint16_t gpio_pin) {
    Gpio::from(port).toggle(gpio_pin);
}

void gpio_write(GpioPort port, uint16_t gpio_pin, GPIO_PinState state) {
    Gpio::from(port).write(gpio_pin, state);
}
}
