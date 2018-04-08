#include <engine/actor/ActorSystem.h>

ActorSystem::ActorSystem() {
    executor = make_unique<Executor>();
}

ActorRef ActorSystem::actorOf(string name, function<shared_ptr<Actor>()> propsFunction) {
    auto rootPath = make_shared<RootActorPath>();
    return actorOf(name, rootPath, propsFunction);
}

ActorRef ActorSystem::actorOf(string name, shared_ptr<ActorPath> parentPath, function<shared_ptr<Actor>()> propsFunction) {
    auto newActor = propsFunction();
    auto newInbox = make_shared<Inbox>(newActor);
    auto newContext = make_shared<ActorContext>(newActor->getChildren());
    
    newActor->actorContext = newContext;

    ActorRef newRef(newInbox);

    executor->watch(newInbox);

    return newRef;
}
