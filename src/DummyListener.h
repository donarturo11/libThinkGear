#ifndef DUMMYLISTENER_H
#define DUMMYLISTENER_H
#include "ThinkGear.h"
void DummyListener_init(ThinkGearListener* listener);
void DummyListener_delete(ThinkGearListener* listener);
void DummyListener_onRaw(void* receiver, ThinkGearValues* values);
void DummyListener_onBattery(void* receiver, ThinkGearValues* values);
void DummyListener_onPoorSignal(void* receiver, ThinkGearValues* values);
void DummyListener_onAttention(void* receiver, ThinkGearValues* values);
void DummyListener_onMeditation(void* receiver, ThinkGearValues* values);
void DummyListener_onEeg(void* receiver, ThinkGearValues* values);
void DummyListener_onConnecting(void* receiver, ThinkGearValues* values);
void DummyListener_onReady(void* receiver, ThinkGearValues* values);
void DummyListener_onError(void* receiver, int code);
void DummyListener_printValue(const char* name, unsigned int value);
#endif // DUMMYLISTENER_H
