#include "ThinkGearReceiver.h"
#include "TGReceiverNotify.h"
#include <iostream>
namespace libThinkGear {
ThinkGearReceiver::ThinkGearReceiver()
{
    std::cout << "ThinkGearReceiver c-tor\n";
    tg = ThinkGear_init();
    TGReceiver_init(tg, this);
}

ThinkGearReceiver::~ThinkGearReceiver()
{
    std::cout << "ThinkGearReceiver d-tor\n";
}

void ThinkGearReceiver::readByte(char byte)
{
    ThinkGear_readByte(tg, byte);
}


} // namespace libThinkGear
