#ifndef THINKGEARRECEIVER_H
#define THINKGEARRECEIVER_H

#include "ThinkGear.h"
#include <vector>
#define BUFFERSIZE 512

class ThinkGearReceiver {
public:
    ThinkGearReceiver();
    ~ThinkGearReceiver();
    void readByte(char byte);
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
    ThinkGear *tg;
    unsigned char buffer[BUFFERSIZE];
};

#endif // THINKGEARRECEIVER_H
