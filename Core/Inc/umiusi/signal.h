#ifndef UMIUSI_NUCLEO_CUBE_SIGNAL_H
#define UMIUSI_NUCLEO_CUBE_SIGNAL_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/// SignalKind
enum SignalKind {
    SignalKindNone = 0,
    SignalKindUartInput,
};

/// SignalUartInputPayload
typedef char SignalUartInputPayload;

/// Signal
struct Signal {
    enum SignalKind kind;
    void* payload;
};

/// pollされているSignalを返す
struct Signal next_signal(void);

/// Signal APIの初期化
void signal_init(void);

/// UART入力のSignalをpollする
void signal_uart_input(SignalUartInputPayload* payload);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // UMIUSI_NUCLEO_CUBE_SIGNAL_H
