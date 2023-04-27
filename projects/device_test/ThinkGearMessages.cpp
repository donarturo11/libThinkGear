#include "ThinkGearMessages.h"
#include <iostream>
using namespace std;
ThinkGearMessages::ThinkGearMessages()
{
    
}

ThinkGearMessages::~ThinkGearMessages()
{
    
}

void ThinkGearMessages::displayValue(std::string name, int value)
{
    cout << name << "\t\t" << value << endl;
}

void ThinkGearMessages::displayEeg(ThinkGearValues* values)
{
    cout << "======= EEG Values: ===========\n";
    displayValue("Eeg delta", values->eegDelta);
    displayValue("Eeg theta", values->eegTheta);
    displayValue("Eeg Low Alpha", values->eegLowAlpha);
    displayValue("Eeg High Alpha", values->eegHighAlpha);
    displayValue("Eeg Low Beta", values->eegLowBeta);
    displayValue("Eeg High Beta", values->eegHighBeta);
    displayValue("Eeg Low Gamma", values->eegLowGamma);
    displayValue("Eeg High Gamma", values->eegHighGamma);
    cout << "===============================\n";
}

