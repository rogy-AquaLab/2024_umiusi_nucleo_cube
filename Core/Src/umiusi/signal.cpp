#include <array>

#include "umiusi/signal.h"

std::array<Signal, 1> pending_signals = {};

extern "C" {

struct Signal next_signal(void) {
    const auto signal = pending_signals[0];
    pending_signals[0] = Signal{ SignalKindNone, nullptr };
    return signal;
}

void signal_init(void) {
    pending_signals.fill(Signal{ SignalKindNone, nullptr });
}

void signal_uart_input(SignalUartInputPayload* payload) {
    pending_signals[0] = Signal{ SignalKindUartInput, payload };
}
}
