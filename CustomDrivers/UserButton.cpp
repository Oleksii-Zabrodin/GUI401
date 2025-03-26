/*
 * UserButton.cpp
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#include "UserButton.h"
#include <UserEvent.h>

#define DEBOUNCE_TIME_MS 50
#define LONG_PRESS_TIME_MS 1000  // (1 секунда)

void UserButton::handleInterrupt() {
	if (!delegate) { return; };

	uint32_t currentTime = HAL_GetTick();
	if ((currentTime - lastActionTime) < DEBOUNCE_TIME_MS) {
		lastActionTime = currentTime;
		return;
	}

	bool isPressed = HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_RESET;
	if (isPressed) {
		delegate->onButtonDown(this);
	}
	else {
		bool isLong = LONG_PRESS_TIME_MS < (currentTime - lastActionTime);
		if (isLong) {
			delegate->onButtonLong(this);
		}
		else {
			delegate->onButtonUp(this);
		}
	}

	lastActionTime = currentTime;
}
