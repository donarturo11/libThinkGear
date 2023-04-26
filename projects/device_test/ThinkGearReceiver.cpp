#include "ThinkGearReceiver.h"
#include "TGReceiverNotify.h"
#include <iostream>

ThinkGearReceiver::ThinkGearReceiver()
{
    std::cout << "SimpleThinkGear c-tor\n";
    tg = ThinkGear_init();
    TGReceiverNotify::TGReceiver_init(tg, this);
}

ThinkGearReceiver::~ThinkGearReceiver()
{
    std::cout << "SimpleThinkGear d-tor\n";
}

void ThinkGearReceiver::readByte(char byte)
{
    ThinkGear_readByte(tg, byte);
}

void ThinkGearReceiver::onRaw(ThinkGearValues* values)
{
    
}

void ThinkGearReceiver::onBattery(ThinkGearValues* values)
{
    
}

void ThinkGearReceiver::onPoorSignal(ThinkGearValues* values)
{
    
}

void ThinkGearReceiver::onAttention(ThinkGearValues* values)
{
    
}

void ThinkGearReceiver::onMeditation(ThinkGearValues* values)
{
    
}

void ThinkGearReceiver::onEeg(ThinkGearValues* values)
{
    
}

void ThinkGearReceiver::onConnecting(ThinkGearValues* values)
{
    
}

void ThinkGearReceiver::onReady(ThinkGearValues* values)
{
    
}

void ThinkGearReceiver::onError(int code)
{
    
}
