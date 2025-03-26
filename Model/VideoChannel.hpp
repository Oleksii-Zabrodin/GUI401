/*
 * VideoChannel.h
 *
 *  Created on: Mar 21, 2025
 *      Author: lex
 */

#ifndef VIDEOCHANNEL_H_
#define VIDEOCHANNEL_H_

#include <stdint.h>

extern const uint16_t SM137R_Channel_channelTable[9][5];
extern const uint16_t channelFreqTable[];

struct VideoChannel {
    uint16_t frequency;
    uint16_t rssi;
    uint8_t lifetime;
    uint8_t receiver;
    uint8_t cyclesPresense;
};

#endif /* VIDEOCHANNEL_H_ */
