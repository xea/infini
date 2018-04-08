#ifndef XA_ACTOR_SELECTION_H
#define XA_ACTOR_SELECTION_H

#include <list>
#include <memory>
#include <engine/actor/ActorRef.h>
#include <engine/actor/Message.h>

using namespace std;

class ActorSelection {
private:
    list<shared_ptr<ActorRef>> actors;
public:
    ActorSelection(list<shared_ptr<ActorRef>> actors);
    // TODO 
    void forward();
    // TODO
    void send(shared_ptr<Message> message);
};

#endif // XA_ACTOR_SELECTION_H
