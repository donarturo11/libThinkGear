#include "ThinkGearMonitor.h"
#include <iostream>

ThinkGearMonitor::ThinkGearMonitor()
{

}

ThinkGearMonitor::~ThinkGearMonitor()
{
    
}

void ThinkGearMonitor::onRaw(ThinkGearValues* values)
{
    msg.displayValue("Raw", values->raw);
}

void ThinkGearMonitor::onBattery(ThinkGearValues* values)
{
    msg.displayValue("Battery", values->battery);
}

void ThinkGearMonitor::onPoorSignal(ThinkGearValues* values)
{
    msg.displayValue("Poor signal", values->poorSignal);
}

void ThinkGearMonitor::onAttention(ThinkGearValues* values)
{
    msg.displayValue("Attention: ", values->attention);
}

void ThinkGearMonitor::onMeditation(ThinkGearValues* values)
{
    msg.displayValue("On meditation", values->meditation);
}

void ThinkGearMonitor::onEeg(ThinkGearValues* values)
{
    msg.displayEeg(values);
}

void ThinkGearMonitor::onConnecting(ThinkGearValues* values)
{

}

void ThinkGearMonitor::onReady(ThinkGearValues* values)
{

}

void ThinkGearMonitor::onError(int code)
{

}
