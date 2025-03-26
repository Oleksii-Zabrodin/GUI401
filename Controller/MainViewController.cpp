/*
 * MainViewController.cpp
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#include "MainViewController.h"
#include "ui_controls.h"
#include "UserEvent.h"
#include "../../Auxiliary/CustomAuxiliary.h"
#include <string>
#include <stdlib.h>
#include <string.h>

#define kChannelLinesCount 2

static int compareCnannelsByRSSI(const void *a, const void *b) {
    return ((*(VideoChannel*)a).rssi - (*(VideoChannel*)b).rssi);
}

MainViewController::MainViewController(u8g2_t& u8g2): u8g2(u8g2) {
	VideoChannel unsortedChannels[10] = {
				VideoChannel(5865, -1, 1, 1, 1),
				VideoChannel(5880, 2, 1, 1, 1),
				VideoChannel(5771, -3, 1, 1, 1),
				VideoChannel(5695, 4, 1, 1, 1),
				VideoChannel(5413, 6, 1, 1, 1),
				VideoChannel(5079, 5, 1, 1, 1),
				VideoChannel(4995, -7, 1, 1, 1),
				VideoChannel(5959, 8, 1, 1, 1),
				VideoChannel(6001, 19, 1, 1, 1),
				VideoChannel(6183, 10, 1, 1, 1)
	};

	size_t n = sizeof(unsortedChannels) / sizeof(unsortedChannels[0]);
	qsort(unsortedChannels, n, sizeof(VideoChannel), compareCnannelsByRSSI);
	memcpy(channels, unsortedChannels, mini(sizeof(unsortedChannels), sizeof(channels)));
};

 void MainViewController::handleEvent(EventSender* eventSender, UserEvent userEvent) {
	 if (userEvent.state == UserEventState::Long) {
		 if (userEvent.type == UserEventType::Left) {
			 soundEnabled = false;
			 isUpdated = false;
	 	 }
	 	 else if (userEvent.type == UserEventType::Right) {
	 		 soundEnabled = true;
	 	 	 isUpdated = false;
	 	 }
	 }
	 else if (userEvent.state == UserEventState::Up) {
	 	 	 if (userEvent.type == UserEventType::Up) {
	 	 		 selectedItem = boundi(0, selectedItem - 1, channelCount - 1);
	 	 		 if (selectedItem < currentOffset) {
	 	 			currentOffset = maxi(0, selectedItem);
	 	 		 }

	 	 	 	 isUpdated = false;
	 	 	 }
	 	 	 else if (userEvent.type == UserEventType::Down) {
	 	 		 selectedItem = boundi(0, selectedItem + 1, channelCount - 1);
	 	 		 if ((currentOffset + kChannelLinesCount - 1) < selectedItem) {
	 	 			 currentOffset = boundi(0, selectedItem - kChannelLinesCount + 1, maxi(0, channelCount - kChannelLinesCount + 1));
	 	 		 }

	 	 	 	 isUpdated = false;
	 	 	 }
	 	 }
 }

 void MainViewController::update() {
	 if (isUpdated) { return; };
	 isUpdated = true;

	 u8g2_ClearBuffer(&u8g2);
	 this->drawMainScreen(&u8g2, 50, soundEnabled, false, false, true);
	 u8g2_SendBuffer(&u8g2);
 }

 void MainViewController::drawMainScreen(u8g2_t *u8g2, int batteryLevel, bool soundEnabled, bool isScanning, bool alertState, bool dBmMode) {
   const uint8_t listStartY = 19;
   const uint8_t itemHeight = 8;
   uint8_t y = listStartY;


   u8g2_SetDrawColor(u8g2, 1);
   drawBatteryIndicator(u8g2, 108, 0, batteryLevel);
   drawSoundIcon(u8g2, 88, 0, soundEnabled);
   u8g2_SetFont(u8g2, u8g2_font_6x12_t_cyrillic);

   if (isScanning) {
     u8g2_SetDrawColor(u8g2, 1);
     u8g2_DrawBox(u8g2, 0, y - itemHeight-2, 128, itemHeight+1);
     u8g2_SetDrawColor(u8g2, 0);
     u8g2_DrawUTF8(u8g2, 1, 17, "Сканування...");
   } else {
     u8g2_SetDrawColor(u8g2, 1);
     u8g2_DrawUTF8(u8g2, 1, 17, "Обраний канал:");
   }

   y = y - 1;

   for (int i = currentOffset; i < channelCount && i < currentOffset + kChannelLinesCount; i++) {
     if(channels[i].frequency > 0) {
       y += itemHeight;
       char channelName[24] = {0};
       getChannelName(channels[i].frequency, channels[i].receiver, channelName);
       int rssi = channels[i].rssi; //convertRSSIToDBm(channels[i].rssi, batteryVoltage, channels[i].receiver);
       if (selectedItem == i) {
    	   u8g2_SetDrawColor(u8g2, 1);
    	   u8g2_DrawBox(u8g2, 1, y - itemHeight, 128, itemHeight);
    	   u8g2_SetDrawColor(u8g2, 0);
       } else {
    	   u8g2_SetDrawColor(u8g2, 1);
       }

       char printBuffer[24] = {0};
       if(dBmMode){
    	   snprintf(printBuffer, sizeof(printBuffer), "%i %s S:%ddBm", channels[i].frequency, channelName, rssi);
           u8g2_DrawStr(u8g2, 0, y, printBuffer);
       } else {
    	   snprintf(printBuffer, sizeof(printBuffer), "%i %s", channels[i].frequency, channelName);
           u8g2_DrawStr(u8g2, 0, y, printBuffer);
    	   drawSignalStrengthIndicator(u8g2, 64, y - itemHeight, rssi, (selectedItem == i + 1) ? true : false);
       }
     }
   }

   if (alertState) {
 	  drawAlertIcon(u8g2, 0, 51);
   }
 }
