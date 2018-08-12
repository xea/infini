#ifndef XA_INTERNAL_ACTOR_REF_H
#define XA_INTERNAL_ACTOR_REF_H

class InternalActorRef : public ActorRef {
private:
    std::shared_ptr<ActorPath> actorPath;
public:
    InternalActorRef(std::shared_ptr<ActorPath> actorPath) : actorPath(actorPath) {};
    void send(std::unique_ptr<Message> message) override;
    std::shared_ptr<ActorPath> getPath() override;
};

void InternalActorRef::send(std::unique_ptr<Message> message) {
    std::cout << "Internal handler" << std::endl;
    /*
     std::shared_ptr<ActorContext> context = std::static_pointer_cast<ActorContext>(actorCell);
     std::unique_ptr<Envelope> envelope = std::make_unique<Envelope>(std::move(message), context->sender());
     
     context->sendMessage(std::move(envelope));
     */
}

std::shared_ptr<ActorPath> InternalActorRef::getPath() {
    return actorPath;
}

#endif //  XA_INTERNAL_ACTOR_REF_H
