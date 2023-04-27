#include "TGReceiverNotify.h"
namespace libThinkGear {
void TGReceiver_init(ThinkGear* tg, void* receiver)
{
    tg->receiver=receiver;
    tg->listener->onRaw=notifyRaw;
    tg->listener->onBattery=notifyBattery;
    tg->listener->onPoorSignal=notifyPoorSignal;
    tg->listener->onAttention=notifyAttention;
    tg->listener->onMeditation=notifyMeditation;
    tg->listener->onEeg=notifyEeg;
    tg->listener->onConnecting=notifyConnecting;
    tg->listener->onReady=notifyReady;
    tg->listener->onError=notifyError;
}

void TGReceiver_notify(void* receiver, TGRecMemFn func, ThinkGearValues* values)
{
    ThinkGearReceiver* tgr = reinterpret_cast<ThinkGearReceiver*>(receiver);
    (tgr->*func)(values);
}

void notifyRaw(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearReceiver::onRaw, values);
}

void notifyBattery(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearReceiver::onBattery, values);
}

void notifyPoorSignal(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearReceiver::onPoorSignal, values);
}

void notifyAttention(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearReceiver::onAttention, values);
}

void notifyMeditation(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearReceiver::onMeditation, values);
}

void notifyEeg(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearReceiver::onEeg, values);
}

void notifyConnecting(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearReceiver::onConnecting, values);
}

void notifyReady(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearReceiver::onReady, values);
}

void notifyError(void* receiver, int code)
{
    ThinkGearReceiver* tgr = reinterpret_cast<ThinkGearReceiver*>(receiver);
    tgr->onError(code);
}

} // namespace TGReceiverNotify
