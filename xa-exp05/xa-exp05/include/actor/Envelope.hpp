#ifndef XA_ACTOR_ENVELOPE_H
#define XA_ACTOR_ENVELOPE_H

// Envelopes wrap a message and a reference to the sender of the message together.
class Envelope {
public:
	std::shared_ptr<ActorRef> sender;
	std::unique_ptr<Message> message;
	Envelope(std::unique_ptr<Message> message, std::shared_ptr<ActorRef> sender) : sender(sender), message(std::move(message)) {};
};

#endif // XA_ACTOR_ENVELOPE_H
