/*
 * EventSender.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#ifndef EVENTSENDER_H_
#define EVENTSENDER_H_

#include "EventReciever.h"

class EventReciever;
class EventSender {
public:
	EventSender();
	virtual ~EventSender();

	EventReciever* eventReciever;
};

#endif /* EVENTSENDER_H_ */
