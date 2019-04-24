#include <engine/concurrent/ActorSelection.h>

ActorSelection::ActorSelection(list<ActorRef> actors) {
    this->actors = actors;
}

list<ActorRef> ActorSelection::all() {
    list<ActorRef> reflist;

    return reflist;
}
