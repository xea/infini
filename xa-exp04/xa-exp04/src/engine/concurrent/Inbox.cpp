#include <engine/concurrent/Inbox.h>

Inbox::Inbox(function<void(Message)> messageProcessor)  {
    processor = messageProcessor;
}

void Inbox::submit(Message message) {
    inboundMessages.push_back(message);
}

Message Inbox::nextMessage() {
    auto message = inboundMessages.front();
    inboundMessages.pop_front();

    return message;
}

unsigned int Inbox::getMessageCount() {
    return inboundMessages.size();
}

void Inbox::processMessage(Message message) {
    processor(message);
}