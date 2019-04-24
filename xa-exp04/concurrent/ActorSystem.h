#ifndef XA_ACTORSYSTEM_H
#define XA_ACTORSYSTEM_H

#include <engine/concurrent/Actor.h>
#include <engine/concurrent/Executor.h>
#include <engine/concurrent/System.h>
#include <functional>
#include <map>
#include <memory>
#include <string>

using namespace std;

class ActorSystem : public System {
private:
    map<string, unique_ptr<Actor>> actors;
    unique_ptr<Executor> executor;
public:
    ActorSystem();
    ActorRef actorOf(string actorId) override;
    ActorRef create(string parentAnchor, string actorId, function<unique_ptr<Actor>()> propsFunc) override;
    ActorSelection select(string selector) override;
};

#endif // XA_ACTORSYSTEM_H