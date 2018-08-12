#ifndef XA_ACTOR_SYSTEM_H
#define XA_ACTOR_SYSTEM_H

// An actor system is a collective space that links individual actors together.
class ActorSystem : public ActorRefFactory, public std::enable_shared_from_this<ActorSystem> {
private:
    std::string name;
    std::shared_ptr<RootActorPath> rootPath;
    std::shared_ptr<Dispatcher> _dispatcher;
    std::unique_ptr<ActorRefProvider> actorRefProvider;
    std::shared_ptr<ActorRefWithCell> _guardian;
public:
    ActorSystem(std::string name, std::shared_ptr<Dispatcher> dispatcher) : name(name), rootPath(std::make_shared<RootActorPath>()), _dispatcher(dispatcher), actorRefProvider(std::make_unique<LocalActorRefProvider>()) {};
    ActorSystem(std::string name) : ActorSystem(name, std::make_shared<Dispatcher>()) {};
    std::string& getName();
    std::shared_ptr<ActorRef> actorOf(std::function<std::unique_ptr<Actor>()> propsFunc, std::string name) override;
    std::shared_ptr<ActorRef> root() override;
    std::shared_ptr<ActorRefWithCell> guardian();
    std::shared_ptr<Dispatcher> dispatcher();
};

std::string& ActorSystem::getName() {
    return name;
}

std::shared_ptr<ActorRef> ActorSystem::actorOf(std::function<std::unique_ptr<Actor>()> propsFunc, std::string name) {
    /*
     std::shared_ptr<ActorCell> newCell = std::make_shared<ActorCell>(shared_from_this(), _dispatcher);
     newCell->assignActor(propsFunc);
     
     std::shared_ptr<ActorRef> newRef = std::make_shared<LocalActorRef>(std::make_shared<ChildActorPath>(actorRefProvider->guardian()->getPath(), name), newCell);
     
     newCell->updateRefs(newRef, actorRefProvider->guardian());
     
     std::static_pointer_cast<LocalActorRef>(actorRefProvider->guardian())->getActorCell()->attachChild(newRef);
     
     return newRef;
     */
    
    return guardian()->getActorCell()->actorOf(propsFunc, name);
}

std::shared_ptr<ActorRef> ActorSystem::root() {
    auto rootGuardian = actorRefProvider->rootGuardian();
    
    if (rootGuardian == nullptr) {
        actorRefProvider->init(shared_from_this(), _dispatcher);
        rootGuardian = actorRefProvider->rootGuardian();
    }
    
    return rootGuardian;
}

std::shared_ptr<ActorRefWithCell> ActorSystem::guardian() {
    if (_guardian == nullptr) {
        actorRefProvider->init(shared_from_this(), _dispatcher);
        _guardian = actorRefProvider->guardian();
    }
    
    return _guardian;
}


std::shared_ptr<Dispatcher> ActorSystem::dispatcher() {
    return _dispatcher;
}

#endif // XA_ACTOR_SYSTEM_H
