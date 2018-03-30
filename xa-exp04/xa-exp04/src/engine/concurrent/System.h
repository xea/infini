#ifndef XA_SYSTEM_H
#define XA_SYSTEM_H

#include <engine/concurrent/ActorRef.h>

class System {
public:
    virtual ActorRef actorOf(string actorId) = 0;
};

#endif // XA_SYSTEM_H