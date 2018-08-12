#ifndef XA_RECEIVE_BUILDER_H
#define XA_RECEIVE_BUILDER_H

// Makes creating Receive instances more convenient by providing a fluent style API for defining message handlers
class ReceiveBuilder {
    using MessageHandler = std::function<void(std::unique_ptr<Message>)>;
public:
    // Builds the final Receive object that is capable of handling incoming messages in the context of the
    // appropriate actor.
    std::unique_ptr<Receive> build();
    // The returned pointer is intended to be used for chaining method calls, which is also the reason why
    // it's not returning a smart pointer instead of a raw one.
    ReceiveBuilder* match(MessageType msgType, MessageHandler handler);
private:
    std::vector<MessageMatcher> matchers;
};

ReceiveBuilder* ReceiveBuilder::match(MessageType msgType, ReceiveBuilder::MessageHandler handler) {
    matchers.push_back(MessageMatcher(msgType, handler));
    return this;
}

std::unique_ptr<Receive> ReceiveBuilder::build() {
    return std::make_unique<Receive>(matchers);
}

#endif // XA_RECEIVE_BUILDER_H
