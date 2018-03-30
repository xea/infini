#ifndef XA_PHYSICS_H
#define XA_PHYSICS_H

#include <engine/concurrent/Actor.h>
#include <engine/concurrent/Message.h>

class Physics : public Actor {

public:
    void receive(Message message) override;
};

#endif // XA_PHYSICS_H