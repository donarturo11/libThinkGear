#include "thinkgear.h"
#include "ThinkGearStreamParser.h"
#include <stdio.h>
#include <stdlib.h>

uint32_t from_array(const unsigned char *value, int length) {
    int shift = (length-1) * 8;
    uint32_t val = 0;
    for (int i=0; i<length; i++) {
        val |= value[i] << shift;
        shift -= 8;
    }
    return val;
}


tg_eegint_t eeg_values(const unsigned char *value)
{
    tg_eegint_t eeg_vals;
    unsigned int *begin = &(eeg_vals.eegDelta);
    unsigned int *end = &(eeg_vals.eegHighGamma) + 1;
    unsigned int *it = begin;
    while (it != end) {
        *it = from_array(value, 3);
        it += 3;
    }
    return eeg_vals;
}

unsigned char to_uchar(uint32_t val) { return val & 0xFF; }
short to_short(uint32_t val) { return val & 0xFFFF; }

void tgHandleValues( unsigned char extendedCodeLevel,
                                  unsigned char code,
                                  unsigned char valueLength,
                                  const unsigned char *value,
                                  void *customData)
{
    thinkgear_t *tg = (thinkgear_t*) customData;
    tg_listener_t *listener = tg->listener;
    tg_listener_signals *signals = &(listener->signals);
    void *receiver = listener->receiver;
    uint32_t val = from_array(value, valueLength);
    //printf("CODE: 0x%X\n", code);
    if (extendedCodeLevel == 0){
        //if(code != PARSER_CODE_RAW_SIGNAL) printf("%#x\n",code);//, code, code, code);
        //std::cout << extendedCodeLevel;
        switch (code) {
            case PARSER_CODE_BATTERY:
                signals->onBattery(receiver, to_uchar(val));
                break;
            case PARSER_CODE_POOR_QUALITY:
                signals->onPoorSignal(receiver, to_uchar(val));
                break;
            case PARSER_CODE_ATTENTION:
                signals->onAttention(receiver, to_uchar(val));
                break;
            case PARSER_CODE_MEDITATION:
                signals->onMeditation(receiver, to_uchar(val));
                break;
            case 0x16:
                signals->onBlinkStrength(receiver, to_uchar(val));
                break;
            case( 0xd4 ):
                 //printf("Standby... autoconnecting\n");
                 tg_message_t msg;
                 msg.code = (0xd4);
                 msg.text("Standby... autoconnecting\0");
                 signals->onConnecting(receiver, 0xc2);
                 signals->onMessage(receiver, msg);
                //if(tg.allowRawDataEvents)//ofNotifyEvent(tg.onConnecting, tg.values);
                //tg.device->writeByte((unsigned char) 0xc2); // what is this?
                break;
            case( 0xd0 ):
                signals->onReady(receiver, to_uchar(val));
                break;
            case( 0xd1 ):
                {
                    //printf("Headset not found\0");
                    msg.code = (0xd1);
                    msg.text("Headset not found\0");
                    signals->onError(receiver, 0xd1);
                }
                break;
            case PARSER_CODE_RAW_SIGNAL:
                /* short raw = (value[0] << 8) | value[1]; */
                signals->onRaw(receiver, to_short(val));
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
                    /*
                    int pos = 0;
                    values->eegDelta = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegTheta = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegLowAlpha = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegHighAlpha = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegLowBeta = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegHighBeta = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegLowGamma = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    values->eegHighGamma = (value[pos] << 16) | (value[pos+1] << 8) | (value[pos+2]); pos += 3;
                    */ 
                    tg_eegint_t values = eeg_values(value);
                    signals->onEeg(receiver, values);
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

