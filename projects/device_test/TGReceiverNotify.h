#ifndef TGRECEIVERNOTIFY_H
#define TGRECEIVERNOTIFY_H
#include "ThinkGear.h"
#include "ThinkGearReceiver.h"
namespace libThinkGear {

typedef void (ThinkGearReceiver::*TGRecMemFn)(ThinkGearValues*);
void TGReceiver_init(ThinkGear* tg, void* receiver);
void TGReceiver_notify(void* receiver, TGRecMemFn func, ThinkGearValues* values);

void notifyRaw(void* receiver, ThinkGearValues* values);
void notifyBattery(void* receiver, ThinkGearValues* values);
void notifyPoorSignal(void* receiver, ThinkGearValues* values);
void notifyAttention(void* receiver, ThinkGearValues* values);
void notifyMeditation(void* receiver, ThinkGearValues* values);
void notifyEeg(void* receiver, ThinkGearValues* values);
void notifyConnecting(void* receiver, ThinkGearValues* values);
void notifyReady(void* receiver, ThinkGearValues* values);
void notifyError(void* receiver, int code);

} // namespace libThinkGear
#endif // TGRECEIVERNOTIFY_H
