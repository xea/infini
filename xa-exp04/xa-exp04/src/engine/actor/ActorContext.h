#ifndef XA_ACTOR_CONTEXT_H
#define XA_ACTOR_CONTEXT_H

#include <list>
#include <memory>
#include <string>
#include <engine/actor/ActorRef.h>
#include <engine/actor/ActorSelection.h>

using namespace std;

class ActorContext {
private:
    shared_ptr<list<shared_ptr<ActorRef>>> actorChildren;
public:
    ActorContext();
    //ActorContext(shared_ptr<list<ActorRef>> actorChildren);
    ActorContext(shared_ptr<list<shared_ptr<ActorRef>>> actorChildren);
    ActorSelection select(string selector);
};

#endif // XA_ACTOR_CONTEXT_H
