#include <engine/concurrent/ActorRef.h>

ActorRef::ActorRef(shared_ptr<Inbox> targetInbox) {
    this->targetInbox = targetInbox;
}

void ActorRef::send(Message message) {
    targetInbox->submit(message);
}

