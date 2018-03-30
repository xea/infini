#ifndef XA_ACTOR_ACTOR_SYSTEM_H
#define XA_ACTOR_ACTOR_SYSTEM_H

#include <functional>
#include <string>
#include <engine/actor/Actor.h>
#include <engine/actor/ActorRef.h>
#include <engine/actor/ActorSelection.h>
#include <engine/actor/Scheduler.h>

using namespace std;

class ActorSystem {
private:

public:
    ActorSystem();
    ActorSelection select(string selector);
    // TODO name, propsfunction 
    ActorRef actorOf(string name, function<unique_ptr<Actor>()> propsFunction);
    // TODO actorOf(propsfunction) (anonymous actor)
    // TODO
    Scheduler scheduler();
    // TODO uptime
};

#endif // XA_ACTOR_ACTOR_SYSTEM_H