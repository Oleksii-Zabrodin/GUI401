/*
 * EventReciever.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#ifndef EVENTRECIEVER_H_
#define EVENTRECIEVER_H_

#include "UserEvent.h"
#include "EventSender.h"

class EventSender;
class EventReciever {
public:
	EventReciever();
	virtual ~EventReciever();

	virtual void handleEvent(EventSender* eventSender, UserEvent event) = 0;
};

#endif /* EVENTRECIEVER_H_ */
