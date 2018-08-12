#ifndef XA_RECEIVE_H
#define XA_RECEIVE_H

#include <vector>
#include "MessageMatcher.hpp"

// A Receive instance represents a single behaviour in the behaviour stack for a given actor.
class Receive {
public:
    Receive(std::vector<MessageMatcher> matchers) : matchers(matchers) {};
    // Accepts a message for processing
    void onMessage(std::unique_ptr<Message> message);
private:
    std::vector<MessageMatcher> matchers;
};

void Receive::onMessage(std::unique_ptr<Message> message) {
    for (auto& matcher : matchers) {
        if (matcher.accepts(message->getMessageType())) {
            matcher.accept(std::move(message));
            break;
        }
    }
}

#endif // XA_RECEIVE_H
