#ifndef XA_PHYSICS_H
#define XA_PHYSICS_H

#include <string>
#include <engine/actor/Actor.h>
#include <engine/logging/Logger.h>

class Physics : public Actor {
protected:
    void receive(std::shared_ptr<Message> message) override;
    std::string getDebugName() override;
};

#endif // XA_PHYSICS_H