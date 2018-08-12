#ifndef XA_LOCAL_ACTOR_REF_H
#define XA_LOCAL_ACTOR_REF_H

class LocalActorRef : public ActorRefWithCell {
private:
    std::shared_ptr<ActorPath> actorPath;
    std::shared_ptr<ActorCell> actorCell;
public:
    LocalActorRef(std::shared_ptr<ActorPath> actorPath, std::shared_ptr<ActorCell> actorCell) : actorPath(actorPath), actorCell(actorCell) {};
    void send(std::unique_ptr<Message> message) override;
    std::shared_ptr<ActorPath> getPath() override;
    std::shared_ptr<ActorCell> getActorCell() override;
};

void LocalActorRef::send(std::unique_ptr<Message> message) {
    // since ActorCell hasn't been defined at this point, we can't simply use it's methods so we have to downcast it to ActorContext
    std::shared_ptr<ActorContext> context = std::static_pointer_cast<ActorContext>(actorCell);
    std::unique_ptr<Envelope> envelope = std::make_unique<Envelope>(std::move(message), currentActor);
    
    context->sendMessage(std::move(envelope));
}

std::shared_ptr<ActorPath> LocalActorRef::getPath() {
    return actorPath;
}

std::shared_ptr<ActorCell> LocalActorRef::getActorCell() {
    return actorCell;
}


#endif // XA_LOCAL_ACTOR_REF_H
