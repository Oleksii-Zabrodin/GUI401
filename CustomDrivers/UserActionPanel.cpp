/*
 * UserActionPanel.cpp
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#include "UserActionPanel.h"
#include "UserEvent.h"


UserActionPanel::UserActionPanel() {
	upButton.delegate = this;
	downButton.delegate = this;
	leftButton.delegate = this;
	rightButton.delegate = this;

}

UserActionPanel::~UserActionPanel() {
	// TODO Auto-generated destructor stub
}

void UserActionPanel::handleInterrupt(uint16_t pin) {
	switch (pin) {
		case UP_BUTTON_PIN_Pin: upButton.handleInterrupt(); break;
	    case DOWN_BUTTON_PIN_Pin: downButton.handleInterrupt(); break;
	    case LEFT_BUTTON_PIN_Pin: leftButton.handleInterrupt(); break;
	    case RIGHT_BUTTON_PIN_Pin: rightButton.handleInterrupt(); break;
	    default: break;
	}
}

void UserActionPanel::onButtonDown(UserButton* sender) {
	if (!sender) { return; };
	if (!eventReciever) { return; };

	switch (sender->pin) {
		case UP_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Down, UserEventType::Up)); break;
		case DOWN_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Down, UserEventType::Down)); break;
		case LEFT_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Down, UserEventType::Left)); break;
		case RIGHT_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Down, UserEventType::Right)); break;
		default: break;
	}
}

void UserActionPanel::onButtonUp(UserButton* sender) {
	if (!sender) { return; };
	if (!eventReciever) { return; };

	switch (sender->pin) {
		case UP_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Up, UserEventType::Up)); break;
		case DOWN_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Up, UserEventType::Down)); break;
		case LEFT_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Up, UserEventType::Left)); break;
		case RIGHT_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Up, UserEventType::Right)); break;
		default: break;
	}
}

void UserActionPanel::onButtonLong(UserButton* sender) {
	if (!sender) { return; };
	if (!eventReciever) { return; };

	switch (sender->pin) {
		case UP_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Long, UserEventType::Up)); break;
		case DOWN_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Long, UserEventType::Down)); break;
		case LEFT_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Long, UserEventType::Left)); break;
		case RIGHT_BUTTON_PIN_Pin: eventReciever->handleEvent(this, UserEvent(UserEventState::Long, UserEventType::Right)); break;
		default: break;
	}
}


