/*
 * ui_controls.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#ifndef U8G2_UI_CONTROLS_H_
#define U8G2_UI_CONTROLS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "u8g2.h"

void drawBatteryIndicator(u8g2_t *u8g2, int x, int y, uint8_t level);
void drawSignalStrengthIndicator(u8g2_t *u8g2, int x, int y, int dBm, bool isInverted);
void drawSoundIcon(u8g2_t *u8g2, uint8_t x, uint8_t y, bool enabled);
void drawAlertIcon(u8g2_t *u8g2, uint8_t x, uint8_t y);
void showSplashScreen(u8g2_t *u8g2);

void drawMainScreen(u8g2_t *u8g2, int batteryLevel, bool soundEnabled, bool isScanning, bool alertState);

#ifdef __cplusplus
}
#endif

#endif /* U8G2_UI_CONTROLS_H_ */
