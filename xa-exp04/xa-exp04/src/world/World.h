#ifndef XA_WORLD_H
#define XA_WORLD_H

#include <engine/actor/Actor.h>
#include <engine/actor/ActorSystem.h>
#include <engine/actor/Message.h>
#include <world/Physics.h>
#include <world/Object.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include <list>
#include <memory>
#include <thread>

using namespace std;

class World {
public:
    
    World();

    virtual void start() = 0;

    virtual void addObject(std::shared_ptr<Object> object) = 0;

    virtual void stop() = 0;
};

class PhysicsWorld : public World {
private:
	thread processThread;
	list<shared_ptr<Object>> objects;
public:
	void start() override;
	void stop() override;
    void addObject(std::shared_ptr<Object> object) override;
};

class ActorWorld : public World {
private:
    unique_ptr<ActorSystem> actorSystem { make_unique<ActorSystem>() };
    list<ActorRef> actors;
public:

    void start() override;

    void stop() override;

    void addObject(std::shared_ptr<Object> object) override;
};

#endif // XA_WORLD_H