#ifndef XA_ACTOR_H
#define XA_ACTOR_H

#include "ContextStack.hpp"

class Actor {
public:
    Actor() : context(nullptr) {
        context = contextStack.top();
        contextStack.pop();
    }
    
    Actor(std::shared_ptr<ActorContext> context) : context(context) {};
    
    virtual std::unique_ptr<Receive> createReceive() = 0;
    virtual void preStart();
    virtual void postStop();
protected:
    std::shared_ptr<ActorContext> context;
};

void Actor::preStart() {
    // By default, this method doesn't do anything. Subclasses may, however, provide an implementation
}

void Actor::postStop() {
    // By default, this method doesn't do anything. Subclasses may, however, provide an implementation
}

#endif // XA_ACTOR_H
