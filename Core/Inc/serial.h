#ifndef UMIUSI_NUCLEO_CUBE_SERIAL_H
#define UMIUSI_NUCLEO_CUBE_SERIAL_H

#include "stm32f3xx_hal.h"

enum Signal {
    ON,
    OFF,
    TOGGLE,
    NONE
};

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void        uart_receive_dma(UART_HandleTypeDef* huart);
void        uart_rx_callback(UART_HandleTypeDef* huart);
enum Signal gen_signal(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // UMIUSI_NUCLEO_CUBE_SERIAL_H
