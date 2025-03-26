/*
 * ui_controls.c
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#include "ui_controls.h"
#include "resources.h"

void drawBatteryIndicator(u8g2_t *u8g2, int x, int y, uint8_t level) {
    u8g2_DrawFrame(u8g2, x, y, 16, 8);
    u8g2_DrawBox(u8g2, x + 16, y + 2, 2, 4);
    int fillWidth = (level * 14) / 100;
    if (fillWidth > 0) u8g2_DrawBox(u8g2, x + 1, y + 1, fillWidth, 6);
}

int constrain(int x, int a, int b) {
    return (x < a) ? ((a < b) ? a : b) : x;
}

void drawSignalStrengthIndicator(u8g2_t *u8g2, int x, int y, int dBm, bool isInverted) {

    dBm = constrain(dBm, -80, 5);

    int signalRange = 85;
    int shiftedDBm = dBm + 80;
    int fillPercentage = (shiftedDBm * 100) / signalRange;


    int fillWidth = (fillPercentage * 60) / 100;
    fillWidth = constrain(fillWidth, 0, 60);


    uint8_t currentColor = u8g2_GetDrawColor(u8g2);

    if (fillWidth > 0) {
        if (isInverted) {

            u8g2_SetDrawColor(u8g2, 0);
            u8g2_DrawFrame(u8g2, x, y, 64, 8);
            u8g2_DrawBox(u8g2, x + 1, y + 1, 60, 6);
            u8g2_SetDrawColor(u8g2, 1);
            u8g2_DrawBox(u8g2, x + 1, y + 1, fillWidth, 6);
        } else {

            u8g2_SetDrawColor(u8g2, 1);
            u8g2_DrawFrame(u8g2, x, y, 64, 8);
            u8g2_DrawBox(u8g2, x + 1, y + 1, fillWidth, 6);
        }
    }


    u8g2_SetDrawColor(u8g2, currentColor);
}

void drawSoundIcon(u8g2_t *u8g2, uint8_t x, uint8_t y, bool enabled) {
    if (enabled) {
        u8g2_DrawXBMP(u8g2, x, y, sound_off_image_width, sound_off_image_height, sound_off_image_bits);
    } else {
    	u8g2_DrawXBMP(u8g2, x, y, sound_on_image_width, sound_on_image_height, sound_on_image_bits);
    }
}

void drawAlertIcon(u8g2_t *u8g2, uint8_t x, uint8_t y) {
    u8g2_SetDrawColor(u8g2, 0);
    u8g2_DrawXBMP(u8g2, x, y, alert_width, alert_height, alert_bits);
}

void showSplashScreen(u8g2_t *u8g2) {
	u8g2_ClearBuffer(u8g2);
	u8g2_DrawXBMP(u8g2, 0, 0, logo_image_width, logo_image_height, logo_image_bits);
	u8g2_SendBuffer(u8g2);
}

void drawMainScreen(u8g2_t *u8g2, int batteryLevel, bool soundEnabled, bool isScanning, bool alertState) {
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

//  for (int i = currentOffset; i < channelCount && i < currentOffset + 4; i++) {
//    if(channels[i].frequency > 0) {
//      y += itemHeight;
//      String channelName = getChannelName(channels[i].frequency, channels[i].receiver);
//      int rssi = convertRSSIToDBm(channels[i].rssi, batteryVoltage, channels[i].receiver);
//      if (selectedItem == i + 1) {
//        u8g2.setDrawColor(1);
//        u8g2.drawBox(1, y - itemHeight, 128, itemHeight);
//        u8g2.setDrawColor(0);
//      } else {
//        u8g2.setDrawColor(1);
//      }
//
//      u8g2.setCursor(0, y);
//      u8g2.print(channels[i].frequency);
//      u8g2.print(channelName);
//      if(dBmMode){
//        u8g2.print(" S:");
//        u8g2.print(rssi);
//        u8g2.print("dBm");
//      } else {
//        drawSignalStrengthIndicator(u8g2, 64, y - itemHeight, rssi, (selectedItem == i + 1) ? true : false);
//      }
//
//    }
//
//  }

  if (alertState) {
	  drawAlertIcon(u8g2, 0, 51);
  }
}

