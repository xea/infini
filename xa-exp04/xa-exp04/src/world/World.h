#ifndef XA_WORLD_H
#define XA_WORLD_H

#include <engine/concurrent/ActorSystem.h>
#include <engine/concurrent/Message.h>
#include <world/Object.h>
#include <vector>
#include <memory>

using namespace std;

class World {
public:
    
    World();

    virtual void start() = 0;

    virtual void addObject(std::shared_ptr<Object> object) = 0;

    virtual void stop() = 0;
};

class ActorWorld : public World {
private:
    unique_ptr<ActorSystem> actorSystem { make_unique<ActorSystem>() };
public:

    void start() override;

    void stop() override;

    void addObject(std::shared_ptr<Object> object) override;
};

#endif // XA_WORLD_H