#include "DummyListener.h"

void DummyListener_init(ThinkGearListener* listener)
{
    if (!listener)
        listener = ThinkGearListener_init();
    listener->onRaw=DummyListener_onRaw;
    listener->onBattery=DummyListener_onBattery;
    listener->onPoorSignal=DummyListener_onPoorSignal;
    listener->onAttention=DummyListener_onAttention;
    listener->onMeditation=DummyListener_onMeditation;
    listener->onEeg=DummyListener_onEeg;
    listener->onConnecting=DummyListener_onConnecting;
    listener->onReady=DummyListener_onReady;
    listener->onError=DummyListener_onError;
}
void DummyListener_delete(ThinkGearListener* listener)
{
    free(listener);
}
void DummyListener_onRaw(void* receiver, ThinkGearValues* values) {}
void DummyListener_onBattery(void* receiver, ThinkGearValues* values) {}
void DummyListener_onPoorSignal(void* receiver, ThinkGearValues* values) {}
void DummyListener_onAttention(void* receiver, ThinkGearValues* values) {}
void DummyListener_onMeditation(void* receiver, ThinkGearValues* values) {}
void DummyListener_onEeg(void* receiver, ThinkGearValues* values) {}
void DummyListener_onConnecting(void* receiver, ThinkGearValues* values) {}
void DummyListener_onReady(void* receiver, ThinkGearValues* values) {}
void DummyListener_onError(void* receiver, int code) {}
void DummyListener_printValue(const char* name, unsigned int value) {}
