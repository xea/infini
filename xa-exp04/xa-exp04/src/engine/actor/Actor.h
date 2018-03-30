#ifndef XA_ACTOR_H
#define XA_ACTOR_H

#include <memory>
#include <world/Object.h>

class Actor {
    
};

class RenderActor : public Actor {
private:
    std::shared_ptr<Object> object;
public:
    RenderActor(std::shared_ptr<Object> object);
};

#endif // XA_ACTOR_H