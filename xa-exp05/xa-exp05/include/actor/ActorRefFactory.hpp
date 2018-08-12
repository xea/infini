#ifndef XA_ACTOR_REF_FACTORY_H
#define XA_ACTOR_REF_FACTORY_H

class Actor;

// An interface for providing references to newly created actors. It is only required by
// actor contexts and actor systems as only they are expected to be able to create actors.
class ActorRefFactory {
public:
    using PropsFunc = std::function<std::unique_ptr<Actor>()>;
    
    // Create a new actor using the provided props function with the supplied name. The
    // new actor will be created as a child of the current actor (which may be the user
    // guardian if the new actor was created through an actor system).
    virtual std::shared_ptr<ActorRef> actorOf(PropsFunc propsFunc, const std::string name) = 0;
    virtual std::shared_ptr<ActorRef> root() = 0;
};


#endif // XA_ACTOR_REF_FACTORY_H
