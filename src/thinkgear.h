#ifndef THINKGEAR_H
#define THINKGEAR_H

#if defined(EXPORT)
  #if defined _WIN32 || defined __CYGWIN__
    #define THINKGEARAPI __declspec(dllexport)
  #else
    #define THINKGEARAPI __attribute__((visibility("default")))
  #endif
#else
  #define THINKGEARAPI //__declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
namespace libThinkGear {
#endif

typedef struct _thinkgear_t thinkgear_t;
typedef struct _tg_eegint_t tg_eegint_t;
typedef struct _tg_message_t tg_message_t;
typedef struct _tg_listener_t tg_listener_t;
typedef struct _tg_listener_signals tg_listener_signals;
typedef struct _ThinkGearStreamParser ThinkGearStreamParser;

typedef struct _thinkgear_t {
    ThinkGearStreamParser parser;
    tg_listener_t *listener;
} thinkgear_t;

typedef struct _tg_message_t {
    char code;
    char text[100];
} tg_message_t;

typedef struct _tg_eegint_t {
    // "ASIC_EEG_POWER" units - dumb
    unsigned int eegDelta; // 100000 / 1500000 . 0.5-2.75hz
    unsigned int eegTheta; // 300000 / 600000 . 3.5-6.75hz
    unsigned int eegLowAlpha; // 2500 / 75000 . 7.5-9.25hz
    unsigned int eegHighAlpha; // 2500 / 150000 . 10-11.75hz
    unsigned int eegLowBeta; // 1500 / 60000 . 13-16.75hz
    unsigned int eegHighBeta; // 2500 / 60000 . 18-29.75hz
    unsigned int eegLowGamma; // 5000 / 300000 . 31-39.75hz
    unsigned int eegHighGamma; // 5000 / 300000 . 41-49.75hz
} tg_eegint_t;

typedef struct _tg_listener_t {
    void *receiver;
    tglistener_signals signals;
} tg_listener_t;

typedef struct _tglistener_signals {
    void (*onRaw)(void *receiver, short value);
    void (*onBattery)(void *receiver, unsigned char value);
    void (*onBlinkStrength)(void *receiver, unsigned char value);
    void (*onPoorSignal)(void *receiver, unsigned char value);
    void (*onAttention)(void *receiver, unsigned char value);
    void (*onMeditation)(void *receiver, unsigned char value);
    void (*onEeg)(void *receiver, tg_eegint_t values);
    void (*onConnecting)(void *receiver, unsigned char value);
    void (*onReady)(void *receiver, unsigned char value);
    void (*onMessage)(void *receiver, tg_message_t msg);
} tglistener_signals;

void tgHandleValues( unsigned char extendedCodeLevel, 
                                  unsigned char code, 
                                  unsigned char valueLength, 
                                  const unsigned char *value, 
                                  void *customData);

THINKGEARAPI void thinkgear_init(thinkgear_t *self);
THINKGEARAPI void thinkgear_delete(thinkgear_t *self);
THINKGEARAPI void thinkgear_load(thinkgear_t *self, unsigned char c);
THINKGEARAPI void thinkgear_load_buffer(thinkgear_t *self, const unsigned char *c, unsigned int length);

THINKGEARAPI void tglistener_init(tg_listener_t *self);


#ifdef __cplusplus
} // namespace libThinkGear
} // extern "C"
#endif

#endif //THINKGEAR_H
