#ifndef THINKGEARRECEIVER_H
#define THINKGEARRECEIVER_H

#include "ThinkGear.h"
#include "ThinkGearListener.h"
#include <vector>
#include <list>
#define BUFFERSIZE 512
namespace libThinkGear {
class ThinkGearReceiver {
public:
    ThinkGearReceiver();
    ~ThinkGearReceiver();
    void readByte(char byte);
    void addListener(ThinkGearListener* listener) { tgListeners.push_back(listener); }
    void removeListener(ThinkGearListener* listener) { std::erase(tgListeners, listener); }
    ThinkGearListenerList TGListeners() const { return tgListeners; }

private:
    ThinkGear *tg;
    unsigned char buffer[BUFFERSIZE];
    ThinkGearListenerList tgListeners;
};
} // namespace libThinkGear

#endif // THINKGEARRECEIVER_H
