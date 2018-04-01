#include <engine/actor/Actor.h>

Actor::Actor() {
    // the default actor implementation's inbox will simply call receive() for each submitted message
    actorInbox = make_shared<Inbox>([this](std::shared_ptr<Message> message) { this->receive(message); });
}

std::shared_ptr<ActorContext> Actor::context() {
    return this->actorContext;
}

std::shared_ptr<Inbox> Actor::inbox() {
    return this->actorInbox;
}

RenderActor::RenderActor(std::shared_ptr<Object> object) {
    this->object = object;
}

void RenderActor::receive(std::shared_ptr<Message> message) {
    
}
