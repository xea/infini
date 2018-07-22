#pragma once

#ifndef XA_MESSAGE_H
#define XA_MESSAGE_H

#include <cstdint>

// MessageType acts as a discriminator value for messages when the static type of the message object can't tell the
// exact message type. It is also used in message matching in order to find the right message handling functions.
enum class MessageType : uint32_t {
	// Message type telling actors to terminate themselves permanently
	POISON_PILL,
};

// Message is a base definition of any object that may be send between actors in the actor system. Message instances
// are expected to be immutable.
class Message {
public:
	virtual const MessageType getMessageType() = 0;
};

// When a poison pill is sent to an actor, it should immediately stop it's children and itself as well, permanently. 
// Child actors should also be stopped by forwarding a poison pill message to them.
class PoisonPill : public Message {
public:
	const MessageType getMessageType() override;
};

const MessageType PoisonPill::getMessageType() {
	return MessageType::POISON_PILL;
}


#endif // XA_MESSAGE_H