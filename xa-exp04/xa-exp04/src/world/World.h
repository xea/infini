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
};

class ActorWorld : public World {
private:
    unique_ptr<ActorSystem> actorSystem { make_unique<ActorSystem>() };
public:
};

#endif // XA_WORLD_H