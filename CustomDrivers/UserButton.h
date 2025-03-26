/*
 * UserButton.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#ifndef USERBUTTON_H_
#define USERBUTTON_H_

#include <cstdint>
#include "stm32f4xx_hal.h"

class UserButton;
class UserButtonDelegate {
public:
	virtual void onButtonDown(UserButton* sender) = 0;
	virtual void onButtonUp(UserButton* sender) = 0;
	virtual void onButtonLong(UserButton* sender) = 0;
};

class UserButton {
public:
	UserButton(uint16_t pin, GPIO_TypeDef* port): pin(pin), port(port) {}

	const uint16_t pin;
	void handleInterrupt();

	UserButtonDelegate* delegate;

private:
	uint32_t lastActionTime = 0;
	GPIO_TypeDef* port;
};

#endif /* USERBUTTON_H_ */
