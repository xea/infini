#ifndef XA_MESSAGE_MATCHER_H
#define XA_MESSAGE_MATCHER_H

// An instance of a MessageMatcher is responsible for processing a single message type within a single behaviour.
class MessageMatcher {
    using MessageHandler = std::function<void(std::unique_ptr<Message>)>;
public:
    MessageMatcher(MessageType messageType, MessageHandler handler) : messageType(messageType), handler(handler) {};
    bool accepts(MessageType messageType);
    void accept(std::unique_ptr<Message> message);
private:
    MessageType messageType;
    MessageHandler handler;
};

bool MessageMatcher::accepts(MessageType messageType) {
    return messageType == this->messageType;
}

void MessageMatcher::accept(std::unique_ptr<Message> message) {
    handler(std::move(message));
}


#endif // XA_MESSAGE_MATCHER_H
