#include "ThinkGear.h"
#include "DummyCallbacks.h"
#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif
ThinkGear* ThinkGear_init()
{
    ThinkGear *tg = NULL;
    tg = (ThinkGear*) malloc(sizeof(ThinkGear));
    tg->parser = (ThinkGearStreamParser*) malloc(sizeof(ThinkGearStreamParser));
    tg->values = (ThinkGearValues*) malloc(sizeof(ThinkGearValues));
    tg->ops = (ThinkGearCallbacks*) malloc (sizeof(ThinkGearCallbacks));
    DummyCallbacks_init(tg->ops);
    THINKGEAR_initParser(tg->parser, PARSER_TYPE_PACKETS, tgHandleValues, tg);
    return tg;
}

void ThinkGear_delete(ThinkGear *tg)
{
    free(tg->ops);
    free(tg->parser);
    free(tg->values);
    free(tg); 
}

void ThinkGear_readByte(ThinkGear *tg, unsigned char c)
{
    THINKGEAR_parseByte(tg->parser, c);
}
void ThinkGear_readBytes(ThinkGear *tg, const unsigned char* data, unsigned int length)
{
    for (int i=0; i<length; i++) {
        THINKGEAR_parseByte(tg->parser, data[i]);
    }
}

#ifdef __cplusplus
} // extern "C"
#endif

