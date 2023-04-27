#include "TGReceiverNotify.h"
namespace libThinkGear {
void TGReceiver_init(ThinkGear* tg, void* receiver)
{
    tg->receiver=receiver;
    tg->ops->onRaw=notifyRaw;
    tg->ops->onBattery=notifyBattery;
    tg->ops->onPoorSignal=notifyPoorSignal;
    tg->ops->onAttention=notifyAttention;
    tg->ops->onMeditation=notifyMeditation;
    tg->ops->onEeg=notifyEeg;
    tg->ops->onConnecting=notifyConnecting;
    tg->ops->onReady=notifyReady;
    tg->ops->onError=notifyError;
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
