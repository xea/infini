#ifndef XA_ACTORSYSTEM_H
#define XA_ACTORSYSTEM_H

#include <engine/concurrent/Actor.h>
#include <engine/concurrent/Executor.h>
#include <functional>
#include <map>
#include <memory>
#include <string>

using namespace std;

class ActorSystem {
private:
    map<string, unique_ptr<Actor>> actors;
    unique_ptr<Executor> executor;
public:
    ActorSystem();
    ActorRef actorOf(string actorId);
    ActorRef create(string actorId, function<unique_ptr<Actor>()> propsFunc);
};

#endif // XA_ACTORSYSTEM_H