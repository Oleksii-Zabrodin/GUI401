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

class MainViewController: public ViewController, public EventReciever {
public:
	MainViewController(u8g2_t& u8g2): u8g2(u8g2) {};

	void update();
private:
	u8g2_t& u8g2;
	bool isUpdated = false;

	void handleEvent(EventSender* eventSender, UserEvent event);
	bool soundEnabled;
};

#endif /* MAINVIEWCONTROLLER_H_ */
