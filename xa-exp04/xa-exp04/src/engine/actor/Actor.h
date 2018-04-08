#ifndef XA_ACTOR_H
#define XA_ACTOR_H

#include <list>
#include <memory>
#include <sstream>
#include <engine/actor/ActorContext.h>
#include <engine/actor/Inbox.h>
#include <engine/actor/Message.h>
#include <engine/logging/Logger.h>
#include <world/Object.h>

class ActorSystem;

using namespace std;

class Actor : public MessageProcessor {
friend class ActorContext;
friend class ActorSystem;
private:
    shared_ptr<ActorContext> actorContext;
    shared_ptr<Inbox> actorInbox;
    shared_ptr<list<shared_ptr<ActorRef>>> children;
protected:
    shared_ptr<ActorContext> context();
    shared_ptr<Inbox> inbox();
    virtual void receive(shared_ptr<Message> message) = 0;
    virtual string getDebugName() = 0;
public:
    shared_ptr<list<shared_ptr<ActorRef>>> getChildren();
    Actor();
};

class RenderActor : public Actor {
private:
    shared_ptr<Object> object;
public:
    RenderActor(shared_ptr<Object> object);
    void receive(shared_ptr<Message> message) override;
    string getDebugName() override;
};

#endif // XA_ACTOR_H
