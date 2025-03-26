/*
 * MainViewController.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#ifndef MAINVIEWCONTROLLER_H_
#define MAINVIEWCONTROLLER_H_

#include "ViewController.h"
#include "u8g2.h"
#include <EventReciever.h>
#include "VideoChannel.h"

class MainViewController: public ViewController, public EventReciever {
public:
	MainViewController(u8g2_t& u8g2): u8g2(u8g2) {};

	void update();
private:
	u8g2_t& u8g2;
	bool isUpdated = false;

	void handleEvent(EventSender* eventSender, UserEvent event);
	bool soundEnabled;
	uint8_t currentOffset = 0;
	uint8_t channelCount = 10;
	uint8_t selectedItem = 0;
	VideoChannel channels[10] = {
			VideoChannel(5865, -1, 1, 1, 1),
			VideoChannel(5880, 2, 1, 1, 1),
			VideoChannel(5771, 3, 1, 1, 1),
			VideoChannel(5695, 4, 1, 1, 1),
			VideoChannel(5413, 5, 1, 1, 1),
			VideoChannel(5079, 6, 1, 1, 1),
			VideoChannel(4995, 7, 1, 1, 1),
			VideoChannel(5959, 8, 1, 1, 1),
			VideoChannel(6001, 9, 1, 1, 1),
			VideoChannel(6183, 10, 1, 1, 1),
	};
	void drawMainScreen(u8g2_t *u8g2, int batteryLevel, bool soundEnabled, bool isScanning, bool alertState, bool dBmMode);
};

#endif /* MAINVIEWCONTROLLER_H_ */
