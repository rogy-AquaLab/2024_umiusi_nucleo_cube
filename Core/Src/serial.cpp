//
// Created by kh on 24/10/25.
//

#include "serial.h"

struct State {
    bool received;
    char buffer;

    State() : received(false), buffer(0) {}

    Signal gen_signal() {
        if (!this->received) {
            return NONE;
        }
        this->received = false;
        switch (this->buffer) {
        case '1': return ON;
        case '0': return OFF;
        case ' ': return TOGGLE;
        default:  return NONE;
        }
    }
};

static State state{};

extern "C" {
void uart_receive_dma(UART_HandleTypeDef* huart) {
    HAL_UART_Receive_DMA(huart, (uint8_t*)&state.buffer, 1);
}

void uart_rx_callback(UART_HandleTypeDef* huart) {
    state.received = true;
    uart_receive_dma(huart);
}

Signal gen_signal() {
    return state.gen_signal();
}
}
