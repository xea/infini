#ifndef XA_ACTOR_ACTOR_REF_H
#define XA_ACTOR_ACTOR_REF_H

#include <memory>
#include <engine/actor/Inbox.h>
#include <engine/actor/Message.h>

using namespace std;

class ActorRef {
protected:
    shared_ptr<Inbox> targetInbox;
public:
    ActorRef(shared_ptr<Inbox> targetInbox);
    void send(shared_ptr<Message> message);
    void forward();
};

#endif // XA_ACTOR_ACTOR_REF_H