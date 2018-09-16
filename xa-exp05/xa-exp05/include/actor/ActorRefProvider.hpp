#ifndef XA_ACTOR_REF_PROVIDER
#define XA_ACTOR_REF_PROVIDER

class ActorRefProvider {
public:
    virtual void init(std::shared_ptr<ActorSystem> system, std::shared_ptr<Dispatcher> dispatcher) = 0;
    virtual std::shared_ptr<ActorRef> rootGuardian() = 0;
    virtual std::shared_ptr<ActorRefWithCell> guardian() = 0;
    virtual std::shared_ptr<ActorRef> deadLetters() = 0;
};

class LocalActorRefProvider : public ActorRefProvider {
public:
    LocalActorRefProvider() noexcept;
    void init(std::shared_ptr<ActorSystem> system, std::shared_ptr<Dispatcher> dispatcher) override;
    std::shared_ptr<ActorRef> rootGuardian() override;
    std::shared_ptr<ActorRefWithCell> guardian() override;
    std::shared_ptr<ActorRef> deadLetters() override;
private:
    std::shared_ptr<ActorRef> _rootGuardian;
    std::shared_ptr<ActorRefWithCell> _guardian;
    std::shared_ptr<ActorRef> _deadLetters;
};

LocalActorRefProvider::LocalActorRefProvider() noexcept {
}

void LocalActorRefProvider::init(std::shared_ptr<ActorSystem> system, std::shared_ptr<Dispatcher> dispatcher) {
    auto rootPath = std::make_shared<RootActorPath>();
    
    std::shared_ptr<ActorCell> rootCell = std::make_shared<ActorCell>(system, dispatcher);
    rootCell->assignActor([]() { return std::make_unique<Guardian>(); });
    std::shared_ptr<ActorRefWithCell> rootRef = std::make_shared<LocalActorRef>(rootPath, rootCell);
    
    // the root guardian has no supervisor at the moment
    rootCell->updateRefs(rootRef, nullptr);
    
    _rootGuardian = rootRef;
    
    
    
    auto userGuardianPath = std::make_shared<ChildActorPath>(rootPath, "user");
    std::shared_ptr<ActorCell> userGuardianCell = std::make_shared<ActorCell>(system, dispatcher);
    userGuardianCell->assignActor([]() { return std::make_unique<Guardian>(); });
    std::shared_ptr<ActorRefWithCell> userGuardianRef = std::make_shared<LocalActorRef>(userGuardianPath, userGuardianCell);
    userGuardianCell->updateRefs(userGuardianRef, rootRef);
    
    rootRef->getActorCell()->attachChild(userGuardianRef);
    _guardian = userGuardianRef;
    
}

std::shared_ptr<ActorRef> LocalActorRefProvider::rootGuardian() {
    return _rootGuardian;
}

std::shared_ptr<ActorRefWithCell> LocalActorRefProvider::guardian() {
    return _guardian;
}

std::shared_ptr<ActorRef> LocalActorRefProvider::deadLetters() {
    return _deadLetters;
}

#endif // XA_ACTOR_REF_PROVIDER
