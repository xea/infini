#include <engine/actor/ActorContext.h>

ActorContext::ActorContext() {
//ActorContext::ActorContext(shared_ptr<list<ActorRef>> actorChildren) {
    this->actorChildren = actorChildren;
}

ActorContext::ActorContext(shared_ptr<list<shared_ptr<ActorRef>>> actorChildren) {
    this->actorChildren = actorChildren;
}

ActorSelection ActorContext::select(string selector) {
    list<shared_ptr<ActorRef>> children;
    
    for (auto& actor : *actorChildren) {
        children.push_back(actor);
    }


    ActorSelection selection(children);
    
    return selection;
}
