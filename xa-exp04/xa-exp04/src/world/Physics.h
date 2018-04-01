#ifndef XA_PHYSICS_H
#define XA_PHYSICS_H

#include <engine/actor/Actor.h>

class Physics : public Actor {
protected:
    void receive(std::shared_ptr<Message> message) override;
};

#endif // XA_PHYSICS_H