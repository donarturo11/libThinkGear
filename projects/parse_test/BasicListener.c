#include "BasicListener.h"
#include <stdio.h>
void BasicListener_init(ThinkGearListener* listener)
{
    listener->onRaw=BasicListener_onRaw;
    listener->onBattery=BasicListener_onBattery;
    listener->onPoorSignal=BasicListener_onPoorSignal;
    listener->onAttention=BasicListener_onAttention;
    listener->onMeditation=BasicListener_onMeditation;
    listener->onEeg=BasicListener_onEeg;
    listener->onConnecting=BasicListener_onConnecting;
    listener->onReady=BasicListener_onReady;
    listener->onError=BasicListener_onError;
}

void BasicListener_delete(ThinkGearListener *listener)
{
    free(listener);
}

void BasicListener_onRaw(void* listener, ThinkGearValues* values)
{
    //BasicListener_printValue("Raw", values->raw);
}

void BasicListener_onBattery(void* listener, ThinkGearValues* values)
{
    //BasicListener_printValue("Battery", values->battery);
}

void BasicListener_onPoorSignal(void* listener, ThinkGearValues* values)
{
    //printf("Poor signal\n");
    BasicListener_printValue("Poor signal", values->poorSignal);
}

void BasicListener_onAttention(void* listener, ThinkGearValues* values)
{
    BasicListener_printValue("Attention: ", values->attention);
}

void BasicListener_onMeditation(void* listener, ThinkGearValues* values)
{
    BasicListener_printValue("On meditation", values->meditation);
}

void BasicListener_onEeg(void* listener, ThinkGearValues* values)
{
    printf("======= EEG Values: ===========\n");
    BasicListener_printValue("Eeg delta", values->eegDelta);
    BasicListener_printValue("Eeg theta", values->eegTheta);
    BasicListener_printValue("Eeg Low Alpha", values->eegLowAlpha);
    BasicListener_printValue("Eeg High Alpha", values->eegHighAlpha);
    BasicListener_printValue("Eeg Low Beta", values->eegLowBeta);
    BasicListener_printValue("Eeg High Beta", values->eegHighBeta);
    BasicListener_printValue("Eeg Low Gamma", values->eegLowGamma);
    BasicListener_printValue("Eeg High Gamma", values->eegHighGamma);
    printf("===============================\n");
}

void BasicListener_onConnecting(void* listener, ThinkGearValues* values)
{
    BasicListener_printValue("Connection", 0);
}

void BasicListener_onReady(void* listener, ThinkGearValues* values)
{

}

void BasicListener_onError(void* listener, int code)
{

}

void BasicListener_printValue(const char* name, unsigned int value)
{
    printf("%s: %i\n", name, value);
}
