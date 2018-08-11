#ifndef XA_ACTOR_CONTEXT_H
#define XA_ACTOR_CONTEXT_H

// The actor context is the view of the actor system from the actor.
class ActorContext : public ActorRefFactory {
public:
    virtual std::shared_ptr<ActorRef> parent() = 0;
    virtual std::shared_ptr<ActorRef> sender() = 0;
    virtual std::shared_ptr<ActorRef> self() = 0;
    // Returns all the child actors supervised by this one.
    virtual std::vector<std::shared_ptr<ActorRef>> children() = 0;
    // Returns the child with the given name, provided it exists.
    virtual std::shared_ptr<ActorRef> child(std::string name) = 0;
    virtual void sendMessage(std::unique_ptr<Envelope> message) = 0;
    virtual std::shared_ptr<ActorSelection> actorSelection(std::string selector) = 0;
    
    // TODO: 
    // become(Receive)
    // unbecome()
};

#endif // XA_ACTOR_CONTEXT_H
