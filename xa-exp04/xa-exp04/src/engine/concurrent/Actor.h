#ifndef XA_ACTOR_H
#define XA_ACTOR_H

#include <engine/concurrent/Inbox.h>
#include <engine/concurrent/Message.h>
#include <memory>

// temporary includes
#include <iostream>

using namespace std;

class ActorRef {
private:
    shared_ptr<Inbox> targetInbox;
public:
    ActorRef(shared_ptr<Inbox> targetInbox);
    void send(Message message);
};

class Actor {
private:
    shared_ptr<Inbox> inbox;
protected:
    Actor();
    
public:
    virtual void receive(Message message) = 0;
    shared_ptr<Inbox> getInbox();
};

class TestActor : public Actor {
    void receive(Message message) override;
};

#endif // XA_ACTOR_H