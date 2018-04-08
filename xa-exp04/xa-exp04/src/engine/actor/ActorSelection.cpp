#include <engine/actor/ActorSelection.h>

ActorSelection::ActorSelection(list<shared_ptr<ActorRef>> actors) {
    this->actors = actors;
}

void ActorSelection::send(shared_ptr<Message> message) {
    for (auto& actor : actors) {
        actor->send(message);
    }
}
