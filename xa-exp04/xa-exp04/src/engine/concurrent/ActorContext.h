#ifndef XA_ACTOR_CONTEXT_H
#define XA_ACTOR_CONTEXT_H

#include <engine/concurrent/ActorRef.h>
#include <engine/concurrent/ActorSystem.h>

class ActorContext {
private:

public:
    ActorContext();
    //ActorRef actorOf(string actorId);
    void actorOf(string actorId);

};

#endif // XA_ACTOR_CONTEXT_H