/*
 * UserAction.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#ifndef USERACTION_H_
#define USERACTION_H_

#include "Event.h"

enum class UserEventState { Down, Up, Long };
enum class UserEventType { Down, Up, Left, Right, Enter };

class UserEvent: public Event {
public:
	UserEvent(UserEventState state, UserEventType type): state(state), type(type) { };

	const UserEventState state;
	const UserEventType type;
	static const EventType eventType = EventType::UserEvent;
};

#endif /* USERACTION_H_ */
