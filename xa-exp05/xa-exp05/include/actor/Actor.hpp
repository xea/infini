#ifndef XA_ACTOR_H
#define XA_ACTOR_H

#include "ContextStack.hpp"

class Actor {
private:
protected:
    std::shared_ptr<ActorContext> context;
public:
    Actor() : context(nullptr) {
        context = contextStack.top();
        contextStack.pop();
    }
    
    Actor(std::shared_ptr<ActorContext> context) : context(context) {};
    
    virtual std::unique_ptr<Receive> createReceive() = 0;
    // preStart
    // stop
};

#endif // XA_ACTOR_H
