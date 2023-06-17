#ifndef TG_DUMMYLISTENER_H
#define TG_DUMMYLISTENER_H
#include "thinkgear.h"
void tg_dummylistener_init(tg_listener_signals* signals);
void tg_dummylistener_onRaw(void *self, short value);
void tg_dummylistener_onBattery(void *self, unsigned char value);
void tg_dummylistener_onBlinkStrength(void *self, unsigned char value);
void tg_dummylistener_onPoorSignal(void *self, unsigned char value);
void tg_dummylistener_onAttention(void *self, unsigned char value);
void tg_dummylistener_onMeditation(void *self, unsigned char value);
void tg_dummylistener_onEeg(void *self, tg_eegint_t values);
void tg_dummylistener_onConnecting(void *self, unsigned char value);
void tg_dummylistener_onReady(void *self, unsigned char value);
void tg_dummylistener_onMessage(void *self, tg_message_t msg);
void tg_dummylistener_printValue(const char* name, unsigned int value);
#endif // TG_DUMMYLISTENER_H
