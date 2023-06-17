#include "thinkgear.h"
#include "tg_dummylistener.h"
#include "ThinkGearStreamParser.h"
#include <stdio.h>
#ifdef __cplusplus
extern "C" {
namespace libThinkGear {
#endif
void thinkgear_init(thinkgear_t *self)
{
    tg_dummylistener_init(self->listener->signals);
    tg_parser_init(self->parser, PARSER_TYPE_PACKETS, tgHandleValues, self);
    return tg;
}

void thinkgear_delete(thinkgear_t *self)
{
    free(self); 
}

void thinkgear_load(thinkgear_t *self, unsigned char c)
{
    tg_parser_parseByte(self->parser, c);
}

void thinkgear_readBytes(thinkgear_t *self, const unsigned char* data, unsigned int length)
{
    for (int i=0; i<length; i++) {
        tg_parser_parseByte(self->parser, data[i]);
    }
}

#ifdef __cplusplus
} // namespace libThinkGear
} // extern "C"
#endif

