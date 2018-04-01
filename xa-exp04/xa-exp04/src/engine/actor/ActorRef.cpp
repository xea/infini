#include <engine/actor/ActorRef.h>

ActorRef::ActorRef(shared_ptr<Inbox> targetInbox) {
    this->targetInbox = targetInbox;
}

void ActorRef::send(shared_ptr<Message> message) {
    targetInbox->submit(message);
}
