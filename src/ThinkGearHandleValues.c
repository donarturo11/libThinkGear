#include "ThinkGear.h"
#include <stdio.h>
void tgHandleValues( unsigned char extendedCodeLevel,
                                  unsigned char code,
                                  unsigned char valueLength,
                                  const unsigned char *value,
                                  void *customData)
{
    ThinkGear* tg = (ThinkGear*) customData;
    ThinkGearValues* values = tg->values;
    void* receiver = tg->receiver;
    //printf("CODE: 0x%X\n", code);
    if (extendedCodeLevel == 0){
        //if(code != PARSER_CODE_RAW_SIGNAL) printf("%#x\n",code);//, code, code, code);
        //std::cout << extendedCodeLevel;
        switch (code) {
            case PARSER_CODE_BATTERY:
                values->battery = value[0] & 0xff;
                tg->ops->onBattery(receiver, values);
                break;
            case PARSER_CODE_POOR_QUALITY:
                values->poorSignal = value[0] & 0xff;
                tg->ops->onPoorSignal(receiver, values);
                break;
            case PARSER_CODE_ATTENTION:
                values->attention = value[0] & 0xff;
                tg->ops->onAttention(receiver, values);
                break;
            case PARSER_CODE_MEDITATION:
                values->meditation = value[0] & 0xff;
                tg->ops->onMeditation(receiver, values);
                break;
            //case 0x16:
            //    tg.values.blinkStrength = value[0] & 0xff;
            //    tg.listener.onBlinkStrength(tg.values);
            case( 0xd4 ):
                 printf("Standby... autoconnecting\n");
                //if(tg.allowRawDataEvents)//ofNotifyEvent(tg.onConnecting, tg.values);
                //tg.device->writeByte((unsigned char) 0xc2); // what is this?
                break;
            case( 0xd0 ):
                printf("onReady");
                //tg.listener.onReady(tg.values);
                break;
            case( 0xd1 ):
                {
                    printf("Headset not found\n");
                    //tg.listener.onError(err);
                }
                break;
            case PARSER_CODE_RAW_SIGNAL:
                values->raw = (value[0] << 8) | value[1];
                tg->ops->onRaw(receiver, values);
                break;
            case PARSER_CODE_ASIC_EEG_POWER_INT:
                {
                    //
                    //131?
                    //eegPower[j] = ((unsigned long)packetData[++i] << 16) | ((unsigned long)packetData[++i] << 8) | (unsigned long)packetData[++i];

                    /*int v = 0;
                    for (int i = 0; i < 24; i+=3) {
                        v = (value[i] * 255 * 255) + (value[i + 1] * 255) + (value[i + 2]);
                        std::cout << "a: " << v;
                    }*/

                    int pos = 0;
                    values->eegDelta = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegTheta = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegLowAlpha = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegHighAlpha = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegLowBeta = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegHighBeta = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegLowGamma = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegHighGamma = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    tg->ops->onEeg(receiver, values);
                    break;
                }
            /* Other [CODE]s */
            default:
                printf( "EXCODE level: %d CODE: 0x%02X vLength: %d\n", extendedCodeLevel, code, valueLength );
                printf( "Data value(s):" );
                for( int i=0; i<valueLength; i++ ) printf( " %02X", value[i] & 0xFF );
                printf( "\n" );
                break;
        }
    }
}


ThinkGearCallbacks* ThinkGearCallbacks_init()
{
    ThinkGearCallbacks* ops;
    ops = NULL;
    ops = (ThinkGearCallbacks*) malloc(sizeof(ThinkGearCallbacks));
    return ops;
}
