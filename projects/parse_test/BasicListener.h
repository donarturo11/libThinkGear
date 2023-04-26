#ifndef BASICLISTENER_H
#define BASICLISTENER_H
#include <stdlib.h>
#include "ThinkGear.h"
void BasicListener_init(ThinkGearListener* listener);
void BasicListener_delete(ThinkGearListener* listener);

void BasicListener_onRaw(void* listener, ThinkGearValues* values);
void BasicListener_onBattery(void* listener, ThinkGearValues* values);
void BasicListener_onPoorSignal(void* listener, ThinkGearValues* values);
void BasicListener_onAttention(void* listener, ThinkGearValues* values);
void BasicListener_onMeditation(void* listener, ThinkGearValues* values);
void BasicListener_onEeg(void* listener, ThinkGearValues* values);
void BasicListener_onConnecting(void* listener, ThinkGearValues* values);
void BasicListener_onReady(void* listener, ThinkGearValues* values);
void BasicListener_onError(void* listener, int code);
void BasicListener_printValue(const char* name, unsigned int value);

#endif // BASICLISTENER_H
