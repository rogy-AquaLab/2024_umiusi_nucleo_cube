#include "umiusi/machine.h"

extern "C" {

struct Machine machine_init(void) {
    struct Machine machine;
    machine.state = MachineStateInitializing;
    return machine;
}

void machine_handle_signal(struct Machine* machine, struct Signal* signal) {
    switch (signal->kind) {
    case SignalKindUartInput: {
        const auto payload = static_cast<SignalUartInputPayload*>(signal->payload);
        // TODO: handle payload
    } break;
    default: break;
    }
}
}
