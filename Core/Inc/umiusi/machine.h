#ifndef UMIUSI_NUCLEO_CUBE_MACHINE_H
#define UMIUSI_NUCLEO_CUBE_MACHINE_H

#include "umiusi/signal.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

enum MachineState {
    MachineStateInitializing = 0,
    MachineStatePending,
    MachineStateRunning,
};

struct Machine {
    enum MachineState state;
    // TODO: ADC DMA, PWM, UART TX, UART RX (with state)
};

struct Machine machine_init(void);

void machine_handle_signal(struct Machine* machine, struct Signal* signal);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // UMIUSI_NUCLEO_CUBE_MACHINE_H
