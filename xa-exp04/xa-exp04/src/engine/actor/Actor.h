#ifndef XA_ACTOR_H
#define XA_ACTOR_H

#include <memory>
#include <engine/actor/ActorContext.h>
#include <world/Object.h>

class ActorSystem;

class Actor {
friend class ActorSystem;
private:
    std::shared_ptr<ActorContext> actorContext;
protected:
    std::shared_ptr<ActorContext> context();
public:
};

class RenderActor : public Actor {
private:
    std::shared_ptr<Object> object;
public:
    RenderActor(std::shared_ptr<Object> object);
};

#endif // XA_ACTOR_H