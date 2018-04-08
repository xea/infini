#ifndef XA_ACTOR_ACTOR_SYSTEM_H
#define XA_ACTOR_ACTOR_SYSTEM_H

#include <functional>
#include <string>
#include <list>
#include <engine/actor/Actor.h>
#include <engine/actor/ActorContext.h>
#include <engine/actor/ActorPath.h>
#include <engine/actor/ActorRef.h>
#include <engine/actor/ActorSelection.h>
#include <engine/actor/Executor.h>
#include <engine/actor/Scheduler.h>

using namespace std;

class ActorSystem {
private:
    unique_ptr<Executor> executor;
public:
    ActorSystem();
    ActorSelection select(string selector);
    ActorRef actorOf(string name, function<shared_ptr<Actor>()> propsFunction);
    ActorRef actorOf(string name, std::shared_ptr<ActorPath> parentPath, function<shared_ptr<Actor>()> propsFunction);
    // TODO actorOf(propsfunction) (anonymous actor)
    // TODO
    Scheduler scheduler();
    // TODO uptime
};

#endif // XA_ACTOR_ACTOR_SYSTEM_H