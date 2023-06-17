#include "tg_dummylistener.h"
#include <stdlib.h>

void tg_dummylistener_init(tg_listener_t* self)
{
    self->receiver = NULL;
    tg_listener_signals* signals = &(self->signals);
    signals->onRaw=tg_dummylistener_onRaw;
    signals->onBattery=tg_dummylistener_onBattery;
    signals->onPoorSignal=tg_dummylistener_onPoorSignal;
    signals->onAttention=tg_dummylistener_onAttention;
    signals->onMeditation=tg_dummylistener_onMeditation;
    signals->onEeg=tg_dummylistener_onEeg;
    signals->onConnecting=tg_dummylistener_onConnecting;
    signals->onReady=tg_dummylistener_onReady;
    signals->onError=tg_dummylistener_onError;
}

void tg_dummylistener_onRaw(tg_listener_t *self, short value) {}
void tg_dummylistener_onBattery(void *self, unsigned char value) {}
void tg_dummylistener_onBlinkStrength(void *self, unsigned char value) {}
void tg_dummylistener_onPoorSignal(void *self, unsigned char value) {}
void tg_dummylistener_onAttention(void *self, unsigned char value) {}
void tg_dummylistener_onMeditation(void *self, unsigned char value) {}
void tg_dummylistener_onEeg(void *self, tg_eegint_t values) {}
void tg_dummylistener_onConnecting(void *self, unsigned char value) {}
void tg_dummylistener_onReady(void *self, unsigned char value) {}
void tg_dummylistener_onMessage(void *self, tg_message_t msg) {}
void tg_dummylistener_printValue(const char* name, unsigned int value) {}
