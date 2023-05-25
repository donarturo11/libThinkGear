#ifndef THINKGEARMESSAGES_H
#define THINKGEARMESSAGES_H
#include "ThinkGear.h"
#include <string>
using libThinkGear::ThinkGearValues;
class ThinkGearMessages
{
public:
    ThinkGearMessages();
    ~ThinkGearMessages();
    void displayValue(std::string name, int value);
    void displayEeg(ThinkGearValues* values);
};

#endif // THINKGEARMESSAGES_H
