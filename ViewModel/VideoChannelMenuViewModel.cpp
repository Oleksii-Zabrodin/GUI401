/*
 * VideoChannelMenuViewModel.cpp
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#include "VideoChannelMenuViewModel.hpp"

uint8_t* VideoChannelMenuViewModel::getChannelName() {
//  if (videoChannel.receiver == 1) {
//
//    for (uint8_t i = 0; i < 137; i++) {
//      if (pgm_read_word(&channelFreqTable[i]) == videoChannel.frequency) {
//        char band = 'A' + (i / 8); // определяем бенд (A, B, E, F, ...)
//        uint8_t channel = (i % 8) + 1; // номер канала в бенде
//        return " CH:" + String(band) + String(channel);
//      }
//    }
//  } else {
//
//    for (uint8_t i = 0; i < 8; i++) {
//      if (channelTable[i].freq == videoChannel.frequency) {
//        return " CH:" + String('A') + String(i + 1);
//      }
//    }
//  }


  return (uint8_t*)" CH:--";
}


VideoChannelMenuViewModel::~VideoChannelMenuViewModel() {
	// TODO Auto-generated destructor stub
}

