/*
 * MainViewController.cpp
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#include "MainViewController.h"
#include "ui_controls.h"
#include "UserEvent.h"

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
 }

 void MainViewController::update() {
	 if (isUpdated) { return; };
	 isUpdated = true;

	 u8g2_ClearBuffer(&u8g2);
	 drawMainScreen(&u8g2, 50, soundEnabled, true, false);
	 u8g2_SendBuffer(&u8g2);
 }
