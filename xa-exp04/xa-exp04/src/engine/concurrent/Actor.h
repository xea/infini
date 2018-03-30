#ifndef XA_ACTOR_H
#define XA_ACTOR_H

#include <engine/concurrent/ActorContext.h>
#include <engine/concurrent/Inbox.h>
#include <engine/concurrent/Message.h>
#include <memory>

// temporary includes
#include <iostream>
#include <thread>
#include <list>

using namespace std;

class Actor {
private:
    shared_ptr<Inbox> inbox;
    shared_ptr<ActorContext> localContext;
protected:
    Actor(shared_ptr<ActorContext> context);
    shared_ptr<ActorContext> context();
    
public:
    virtual void receive(Message message) = 0;
    shared_ptr<Inbox> getInbox();
};

/*
class TestActor : public Actor {
private:
    unsigned int counter{0};
public:
    void receive(Message message) override;
};

class Scheduler : public Actor {
public:
    Scheduler(list<function<void()>> taskList);
    void receive(Message message) override;
};
*/

#endif // XA_ACTOR_H