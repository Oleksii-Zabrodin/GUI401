/*
 * VideoChannel.c
 *
 *  Created on: Mar 21, 2025
 *      Author: lex
 */


#include "VideoChannel.h"
#include <string>

const uint16_t SM137R_Channel_channelTable[9][5] __attribute__((section(".rodata"))) = {
    {0, 0, 0 ,1, 1080},  // A1 / B1 (1080 MHz / 1560 MHz)
    {0, 0, 1 ,1, 1120},  // A2 / B2 (1120 MHz / 1600 MHz)
    {0, 1, 0 ,1, 1160},  // A3 / B3 (1160 MHz / 1640 MHz)
    {0, 1, 1 ,1, 1200},  // A4 / B4 (1200 MHz / 1680 MHz)
    {1, 0, 0 ,1, 1240},  // A5 / B5 (1240 MHz / 1738 MHz)
    {1, 0, 0 ,0, 1258},  // B1 / B1 (1080 MHz / 1560 MHz)
    {1, 0, 1 ,1, 1280},  // A6 / B6 (1280 MHz / 1760 MHz)
    {1, 1, 0 ,1, 1320},  // A7 / B7 (1320 MHz / 1800 MHz)
    {1, 1, 1 ,1, 1360}  // A8 / B8 (1360 MHz / 1840 MHz)
};

const uint16_t channelFreqTable[] __attribute__((section(".rodata"))) = {
    5865, 5845, 5825, 5805, 5785, 5765, 5745, 5725, // A
    5733, 5752, 5771, 5791, 5809, 5828, 5847, 5867, // B
    5705, 5685, 5665, 5645, 5885, 5905, 5925, 5945, // E
    5741, 5761, 5781, 5801, 5821, 5841, 5861, 5879, // F
    5657, 5695, 5731, 5769, 5806, 5843, 5880, 5917, // C (R)
    5659, 5695, 5735, 5769, 5805, 5877, 5915, 5839, // DJI V1/25 Mbs
    5695, 5771, 5879, 5839, // DJI V1/50 Mbs
    5669, 5705, 5767, 5803, 5839, 5876, 5911, // DJI O3 10/20 MTu (14/25 Mbs)
    5677, 5795, 5901, // DJI O3 40 MTu (50 Mbs)
    5657, 5695, 5731, 5769, 5807, 5843, 5881, 5917, // Walksnail race mode
    5657, 5695, 5731, 5769, 5805, 5879, 5914, 5839, // Walksnail 25 Mbs
    5695, 5771, 5877, 5837, // Walksnail 50 Mbs
    5657, 5695, 5731, 5769, 5807, 5843, 5891, 5917, // HDZero (FCC)
    5732, 5769, 5807, 5843, // HDZero (CE)
    5362, 5399, 5436, 5473, 5510, 5547, 5584, 5621, // D
    5325, 5347, 5366, 5383, 5401, 5420, 5437, 5455, // U
    5473, 5491, 5509, 5525, 5545, 5563, 5581, 5601, // O
    5333, 5373, 5413, 5453, 5493, 5533, 5573, 5613, // L
    5653, 5693, 5733, 5773, 5813, 5853, 5893, 5933, // H
    4991, 5021, 5049, 5079, 5109, 5139, 5171, 5201, // X
    4867, 4883, 4921, 4958, 4995, 5032, 5069, 5099, // J
    5959, 5979, 5999, 6019, 6039, 6059, 6079, 6101, // K
    6001, 6027, 6053, 6079, 6105, 6131, 6157, 6183  // Z
};

const uint16_t Band_A[8] = 					{ 5865, 5845, 5825, 5805, 5785, 5765, 5745, 5725 }; // A
const uint16_t Band_B[8] = 					{ 5733, 5752, 5771, 5791, 5809, 5828, 5847, 5867 }; // B
const uint16_t Band_E[8] = 					{ 5705, 5685, 5665, 5645, 5885, 5905, 5925, 5945 }; // E
const uint16_t Band_F[8] = 					{ 5741, 5761, 5781, 5801, 5821, 5841, 5861, 5879 }; // F
const uint16_t Band_C[8] = 					{ 5657, 5695, 5731, 5769, 5806, 5843, 5880, 5917 }; // C (R)
const uint16_t Band_DJI_V1_25[8] = 			{ 5659, 5695, 5735, 5769, 5805, 5877, 5915, 5839 }; // DJI V1/25 Mbs
const uint16_t Band_DJI_V1_50[4] = 			{ 5695, 5771, 5879, 5839 }; // DJI V1/50 Mbs
const uint16_t Band_DJI_O3_10[7] = 			{ 5669, 5705, 5767, 5803, 5839, 5876, 5911 }; // DJI O3 10/20 MTu (14/25 Mbs)
const uint16_t Band_DJI_O3_40[3] = 			{ 5677, 5795, 5901 }; // DJI O3 40 MTu (50 Mbs)
const uint16_t Band_Walksnail_race_mode[8] ={ 5657, 5695, 5731, 5769, 5807, 5843, 5881, 5917 }; // Walksnail race mode
const uint16_t Band_Walksnail_25[8] = 		{ 5657, 5695, 5731, 5769, 5805, 5879, 5914, 5839 }; // Walksnail 25 Mbs
const uint16_t Band_Walksnail_50[4] = 		{ 5695, 5771, 5877, 5837 }; // Walksnail 50 Mbs
const uint16_t Band_HDZero_FCC[8] = 		{ 5657, 5695, 5731, 5769, 5807, 5843, 5891, 5917 }; // HDZero (FCC)
const uint16_t Band_HDZero_CE[4] = 			{ 5732, 5769, 5807, 5843 }; // HDZero (CE)
const uint16_t Band_D[8] = 					{ 5362, 5399, 5436, 5473, 5510, 5547, 5584, 5621 }; // D
const uint16_t Band_U[8] = 					{ 5325, 5347, 5366, 5383, 5401, 5420, 5437, 5455 }; // U
const uint16_t Band_O[8] = 					{ 5473, 5491, 5509, 5525, 5545, 5563, 5581, 5601 }; // O
const uint16_t Band_I[8] = 					{ 5333, 5373, 5413, 5453, 5493, 5533, 5573, 5613 }; // L
const uint16_t Band_H[8] = 					{ 5653, 5693, 5733, 5773, 5813, 5853, 5893, 5933 }; // H
const uint16_t Band_X[8] = 					{ 4991, 5021, 5049, 5079, 5109, 5139, 5171, 5201 }; // X
const uint16_t Band_J[8] = 					{ 4867, 4883, 4921, 4958, 4995, 5032, 5069, 5099 }; // J
const uint16_t Band_K[8] = 					{ 5959, 5979, 5999, 6019, 6039, 6059, 6079, 6101 }; // K
const uint16_t Band_Z[8] = 					{ 6001, 6027, 6053, 6079, 6105, 6131, 6157, 6183 };  // Z

void getChannelName(uint16_t frequency, int receiver, char printBuffer[24]) {
//  if (receiver == 1) {
    for (uint8_t i = 0; i < 137; i++) {
      if (channelFreqTable[i] == frequency) {
        char band = 'A' + (i / 8); // определяем бенд (A, B, E, F, ...)
        uint8_t channel = (i % 8) + 1; // номер канала в бенде
        snprintf(printBuffer, sizeof(printBuffer), " CH\:%c %i", band, channel);
        return;
      }
    }
//  } else {
//    for (uint8_t i = 0; i < 8; i++) {
//      if (channelTable[i].freq == frequency) {
//        snprintf(printBuffer, sizeof(printBuffer), " CH:A%i", i + 1);
//        return;
//      }
//    }
//  }

  printBuffer = " CH:--";
  return;
}

