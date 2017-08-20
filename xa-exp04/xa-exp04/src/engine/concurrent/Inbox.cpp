#include <engine/concurrent/Inbox.h>

void Inbox::submit(Message message) {
    inboundMessages.push_back(message);
}