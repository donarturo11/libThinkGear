#ifndef THINKGEARMONITOR_H
#define THINKGEARMONITOR_H
#include "ThinkGearListener.h"
#include "ThinkGearMessages.h"

class ThinkGearMonitor : public libThinkGear::ThinkGearListener
{
public:
    ThinkGearMonitor();
    ~ThinkGearMonitor();
    void onRaw(ThinkGearValues* values);
    void onBattery(ThinkGearValues* values);
    void onPoorSignal(ThinkGearValues* values);
    void onAttention(ThinkGearValues* values);
    void onMeditation(ThinkGearValues* values);
    void onEeg(ThinkGearValues* values);
    void onConnecting(ThinkGearValues* values);
    void onReady(ThinkGearValues* values);
    void onError(int code);
private:
    ThinkGearMessages msg;
};

#endif // THINKGEARMONITOR_H
