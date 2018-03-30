#ifndef XA_SYSTEM_H
#define XA_SYSTEM_H

#include <engine/concurrent/ActorRef.h>

class Actor;

class System {
public:
    virtual ActorRef actorOf(string actorId) = 0;
    virtual ActorRef create(string actorId, function<unique_ptr<Actor>()> propsFunc) = 0;
};

#endif // XA_SYSTEM_H