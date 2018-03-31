#include <engine/actor/Actor.h>

std::shared_ptr<ActorContext> Actor::context() {
    return this->actorContext;
}

RenderActor::RenderActor(std::shared_ptr<Object> object) {
    this->object = object;
}
