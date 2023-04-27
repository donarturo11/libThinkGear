#ifndef DUMMYLISTENER_H
#define DUMMYLISTENER_H
#include "ThinkGear.h"
void DummyCallbacks_init(ThinkGearCallbacks* ops);
void DummyCallbacks_delete(ThinkGearCallbacks* ops);
void DummyCallbacks_onRaw(void* receiver, ThinkGearValues* values);
void DummyCallbacks_onBattery(void* receiver, ThinkGearValues* values);
void DummyCallbacks_onPoorSignal(void* receiver, ThinkGearValues* values);
void DummyCallbacks_onAttention(void* receiver, ThinkGearValues* values);
void DummyCallbacks_onMeditation(void* receiver, ThinkGearValues* values);
void DummyCallbacks_onEeg(void* receiver, ThinkGearValues* values);
void DummyCallbacks_onConnecting(void* receiver, ThinkGearValues* values);
void DummyCallbacks_onReady(void* receiver, ThinkGearValues* values);
void DummyCallbacks_onError(void* receiver, int code);
void DummyCallbacks_printValue(const char* name, unsigned int value);
#endif // DUMMYLISTENER_H
