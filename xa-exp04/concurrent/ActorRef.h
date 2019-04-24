#ifndef XA_ACTOR_REF_H
#define XA_ACTOR_REF_H

#include <engine/concurrent/Inbox.h>

class ActorRef {
private:
    shared_ptr<Inbox> targetInbox;
public:
    ActorRef(shared_ptr<Inbox> targetInbox);
    void send(Message message);
};

#endif // XA_ACTOR_REF_H