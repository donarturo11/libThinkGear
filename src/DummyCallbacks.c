#include "DummyCallbacks.h"

void DummyCallbacks_init(ThinkGearCallbacks* ops)
{
    if (!ops)
        ops = ThinkGearCallbacks_init();
    ops->onRaw=DummyCallbacks_onRaw;
    ops->onBattery=DummyCallbacks_onBattery;
    ops->onPoorSignal=DummyCallbacks_onPoorSignal;
    ops->onAttention=DummyCallbacks_onAttention;
    ops->onMeditation=DummyCallbacks_onMeditation;
    ops->onEeg=DummyCallbacks_onEeg;
    ops->onConnecting=DummyCallbacks_onConnecting;
    ops->onReady=DummyCallbacks_onReady;
    ops->onError=DummyCallbacks_onError;
}
void DummyCallbacks_delete(ThinkGearCallbacks* ops)
{
    free(ops);
}
void DummyCallbacks_onRaw(void* receiver, ThinkGearValues* values) {}
void DummyCallbacks_onBattery(void* receiver, ThinkGearValues* values) {}
void DummyCallbacks_onPoorSignal(void* receiver, ThinkGearValues* values) {}
void DummyCallbacks_onAttention(void* receiver, ThinkGearValues* values) {}
void DummyCallbacks_onMeditation(void* receiver, ThinkGearValues* values) {}
void DummyCallbacks_onEeg(void* receiver, ThinkGearValues* values) {}
void DummyCallbacks_onConnecting(void* receiver, ThinkGearValues* values) {}
void DummyCallbacks_onReady(void* receiver, ThinkGearValues* values) {}
void DummyCallbacks_onError(void* receiver, int code) {}
void DummyCallbacks_printValue(const char* name, unsigned int value) {}
