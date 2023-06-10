#ifndef THINKGEAR_H
#define THINKGEAR_H
#ifdef __cplusplus
extern "C" {
namespace libThinkGear {
#endif

typedef struct _ThinkGear ThinkGear;
typedef struct _ThinkGearValues ThinkGearValues;
typedef struct _ThinkGearCallbacks ThinkGearCallbacks;
typedef struct _ThinkGearStreamParser ThinkGearStreamParser;

typedef struct _ThinkGear {
    ThinkGearStreamParser* parser;
    ThinkGearValues* values;
    ThinkGearCallbacks *ops;
    void *receiver;
} ThinkGear;

typedef struct _ThinkGearValues {
    short raw;
    unsigned char battery;
    unsigned char poorSignal;
    unsigned char blinkStrength;
    unsigned char attention; // 50
    unsigned char meditation; // 30

    // "ASIC_EEG_POWER" units - dumb
    unsigned int eegDelta; // 100000 / 1500000 . 0.5-2.75hz
    unsigned int eegTheta; // 300000 / 600000 . 3.5-6.75hz
    unsigned int eegLowAlpha; // 2500 / 75000 . 7.5-9.25hz
    unsigned int eegHighAlpha; // 2500 / 150000 . 10-11.75hz
    unsigned int eegLowBeta; // 1500 / 60000 . 13-16.75hz
    unsigned int eegHighBeta; // 2500 / 60000 . 18-29.75hz
    unsigned int eegLowGamma; // 5000 / 300000 . 31-39.75hz
    unsigned int eegHighGamma; // 5000 / 300000 . 41-49.75hz
} ThinkGearValues;

typedef struct _ThinkGearCallbacks {
    void (*onRaw)(void* receiver, ThinkGearValues* values);
    void (*onBattery)(void* receiver, ThinkGearValues* values);
    void (*onPoorSignal)(void* receiver, ThinkGearValues* values);
    void (*onAttention)(void* receiver, ThinkGearValues* values);
    void (*onMeditation)(void* receiver, ThinkGearValues* values);
    void (*onEeg)(void* receiver, ThinkGearValues* values);
    void (*onConnecting)(void* receiver, ThinkGearValues* values);
    void (*onReady)(void* receiver, ThinkGearValues* values);
    void (*onError)(void* receiver, int code);
} ThinkGearCallbacks;

void tgHandleValues( unsigned char extendedCodeLevel, 
                                  unsigned char code, 
                                  unsigned char valueLength, 
                                  const unsigned char *value, 
                                  void *customData);

ThinkGear* ThinkGear_init();
void ThinkGear_delete(ThinkGear *tg);
void ThinkGear_readByte(ThinkGear *tg, unsigned char c);
void ThinkGear_readBytes(ThinkGear *tg, const unsigned char* c, unsigned int length);

ThinkGearCallbacks* ThinkGearCallbacks_init();


#ifdef __cplusplus
} // namespace libThinkGear
} // extern "C"
#endif

#endif //THINKGEAR_H
