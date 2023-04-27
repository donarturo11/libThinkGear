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

void TGReceiver_notify(void* receiver, TGListenerMemFn func, ThinkGearValues* values)
{
    ThinkGearReceiver* tgr = reinterpret_cast<ThinkGearReceiver*>(receiver);
    auto listeners = tgr->TGListeners();
    for (auto listener : listeners) {
        (listener->*func)(values);
    }
}

void notifyRaw(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearListener::onRaw, values);
}

void notifyBattery(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearListener::onBattery, values);
}

void notifyPoorSignal(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearListener::onPoorSignal, values);
}

void notifyAttention(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearListener::onAttention, values);
}

void notifyMeditation(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearListener::onMeditation, values);
}

void notifyEeg(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearListener::onEeg, values);
}

void notifyConnecting(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearListener::onConnecting, values);
}

void notifyReady(void* receiver, ThinkGearValues* values)
{
    TGReceiver_notify(receiver, &ThinkGearListener::onReady, values);
}

void notifyError(void* receiver, int code)
{
    //ThinkGearListener* tgr = reinterpret_cast<ThinkGearListener*>(receiver);
    //tgr->onError(code);
}

} // namespace TGReceiverNotify
