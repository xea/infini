#ifndef XA_ACTOR_SELECTION_H
#define XA_ACTOR_SELECTION_H

#include <list>
#include <engine/concurrent/ActorRef.h>

class ActorSelection {
    list<ActorRef> actors;
public:
    ActorSelection(list<ActorRef> actors);
    list<ActorRef> all();
};

#endif // XA_ACTOR_SELECTION_H