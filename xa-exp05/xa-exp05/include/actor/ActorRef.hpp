#pragma once

#ifndef XA_ACTOR_REF_H
#define XA_ACTOR_REF_H

#include <memory>
#include "ActorPath.hpp"
#include "Message.hpp"

// An ActorRef is a lightweight reference to an actor, that is identified by a path unique within the actor system.
// Messages are also send to actors through actor references which handles all the necesary encapsulation.
// Implementations of this abstract class may decide whether the referred actor is local to this actor system or is
// running on a remote system.
class ActorRef : public std::enable_shared_from_this<ActorRef> {
public:
	virtual void send(std::unique_ptr<Message> message) = 0;
	virtual std::shared_ptr<ActorPath> getPath() = 0;
private:
	bool terminated{ false };
};

class DeadLetterActorRef : public ActorRef {
public:
	DeadLetterActorRef(std::shared_ptr<ActorPath> path) : path(path) {};
	void send(std::unique_ptr<Message> message) override;
	std::shared_ptr<ActorPath> getPath() override;
private:
	std::shared_ptr<ActorPath> path;
};

void DeadLetterActorRef::send(std::unique_ptr<Message> message) {
	// TODO deliver message to the dead letter mailbox
}

std::shared_ptr<ActorPath> DeadLetterActorRef::getPath() {
	return path;
}

class NoSenderRef : public ActorRef {
public:
	NoSenderRef(std::shared_ptr<ActorPath> path) : path(path) {};
	void send(std::unique_ptr<Message> message) override {};
	std::shared_ptr<ActorPath> getPath() override { return path; };
private:
	std::shared_ptr<ActorPath> path;
};

#endif // XA_ACTOR_REF_H