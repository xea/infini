#include <engine/actor/ActorSystem.h>

ActorSystem::ActorSystem() {
}

ActorRef ActorSystem::actorOf(string name, function<unique_ptr<Actor>()> propsFunction) {
    auto rootPath = make_shared<RootActorPath>();
    return actorOf(name, rootPath, propsFunction);
}

ActorRef ActorSystem::actorOf(string name, shared_ptr<ActorPath> parentPath, function<unique_ptr<Actor>()> propsFunction) {
    auto newActor = propsFunction();
    auto newContext = make_shared<ActorContext>();
    auto newInbox = newActor->inbox();
    
    newActor->actorContext = newContext;

    ActorRef newRef(newInbox);

    return newRef;
}
