/*
 * UserActionPanel.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */


#ifndef USERACTIONPANEL_H_
#define USERACTIONPANEL_H_

#include "EventSender.h"
#include <cstdint>
#include "UserButton.h"
#include "gpio.h"

class UserActionPanel: public EventSender, public UserButtonDelegate {
public:
	UserActionPanel();
	virtual ~UserActionPanel();

	void handleInterrupt(uint16_t pin);

private:
	UserButton upButton = UserButton(UP_BUTTON_PIN_Pin, UP_BUTTON_PIN_GPIO_Port);
	UserButton downButton = UserButton(DOWN_BUTTON_PIN_Pin, DOWN_BUTTON_PIN_GPIO_Port);
	UserButton leftButton = UserButton(LEFT_BUTTON_PIN_Pin, LEFT_BUTTON_PIN_GPIO_Port);
	UserButton rightButton = UserButton(RIGHT_BUTTON_PIN_Pin, RIGHT_BUTTON_PIN_GPIO_Port);

	virtual void onButtonDown(UserButton* sender);
	virtual void onButtonUp(UserButton* sender);
	virtual void onButtonLong(UserButton* sender);
};

#endif /* USERACTIONPANEL_H_ */
