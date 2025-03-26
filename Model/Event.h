/*
 * Event.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#ifndef EVENT_H_
#define EVENT_H_

enum class EventType {
	Event,
	UserEvent
};

class Event {
public:
	static const EventType eventType = EventType::Event;
};

#endif /* EVENT_H_ */
