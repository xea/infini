#include <engine/concurrent/Actor.h>

ActorRef::ActorRef(shared_ptr<Inbox> targetInbox) {
    this->targetInbox = targetInbox;
}

void ActorRef::send(Message message) {
    targetInbox->submit(message);
}

Actor::Actor() {
    inbox = make_shared<Inbox>([this](Message message) { this->receive(message); });
}

shared_ptr<Inbox> Actor::getInbox() {
    return inbox;
}

void TestActor::receive(Message message) {
    cout << "Received actor message yay" << endl;
}