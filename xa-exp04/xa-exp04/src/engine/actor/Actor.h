#ifndef XA_ACTOR_H
#define XA_ACTOR_H

#include <memory>
#include <engine/actor/ActorContext.h>
#include <engine/actor/Inbox.h>
#include <engine/actor/Message.h>
#include <world/Object.h>

class ActorSystem;

class Actor {
friend class ActorSystem;
private:
    std::shared_ptr<ActorContext> actorContext;
    std::shared_ptr<Inbox> actorInbox;
protected:
    std::shared_ptr<ActorContext> context();
    std::shared_ptr<Inbox> inbox();
    virtual void receive(std::shared_ptr<Message> message) = 0;
public:
    Actor();
};

class RenderActor : public Actor {
private:
    std::shared_ptr<Object> object;
public:
    RenderActor(std::shared_ptr<Object> object);
    void receive(std::shared_ptr<Message> message) override;
};

#endif // XA_ACTOR_H