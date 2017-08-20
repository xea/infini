#include <engine/concurrent/Actor.h>

ActorRef::ActorRef(shared_ptr<Inbox> targetInbox) {
    this->targetInbox = targetInbox;
}

void ActorRef::send(Message message) {
    targetInbox->submit(message);
}

Actor::Actor() {
    inbox = make_shared<Inbox>();
}

shared_ptr<Inbox> Actor::getInbox() {
    return inbox;
}