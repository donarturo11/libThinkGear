#ifndef THINKGEARLISTENER_H
#define THINKGEARLISTENER_H
#include <list>
#include "ThinkGear.h"
namespace libThinkGear {

class ThinkGearListener
{
public:
    virtual void onRaw(ThinkGearValues* values)=0;
    virtual void onBattery(ThinkGearValues* values)=0;
    virtual void onPoorSignal(ThinkGearValues* values)=0;
    virtual void onAttention(ThinkGearValues* values)=0;
    virtual void onMeditation(ThinkGearValues* values)=0;
    virtual void onEeg(ThinkGearValues* values)=0;
    virtual void onConnecting(ThinkGearValues* values)=0;
    virtual void onReady(ThinkGearValues* values)=0;
    virtual void onError(int code)=0;
};

typedef void (ThinkGearListener::*TGListenerMemFn)(ThinkGearValues*);
typedef std::list<ThinkGearListener*> ThinkGearListenerList;

} // namespace libThinkGear 


#endif // THINKGEARLISTENER_H
