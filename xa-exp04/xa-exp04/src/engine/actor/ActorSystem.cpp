#include <engine/actor/ActorSystem.h>

ActorSystem::ActorSystem() {
}

ActorRef ActorSystem::actorOf(string name, function<unique_ptr<Actor>()> propsFunction) {
    auto newActor = propsFunction();

    ActorRef newRef;

    return newRef;
}
