#ifndef XA_MESSAGE_HANDLER_H
#define XA_MESSAGE_HANDLER_H

// Message handler implementations are objects that can handle a message sent by an actor.
class MessageHandler {
public:
    virtual void invoke(std::unique_ptr<Envelope> envelope) = 0;
};

#endif // XA_MESSAGE_HANDLER_H
