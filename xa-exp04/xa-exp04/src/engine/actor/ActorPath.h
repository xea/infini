#ifndef XA_ACTOR_ACTOR_PATH_H
#define XA_ACTOR_ACTOR_PATH_H

#include <string>
#include <memory>


class ActorPath {
private:
    std::shared_ptr<ActorPath> parent;
    std::string name;
public:
    ActorPath(std::shared_ptr<ActorPath> parent, std::string name);
    std::string toString();
};

class RootActorPath : public ActorPath {
public:
    RootActorPath();
    std::string toString();
};

#endif // XA_ACTOR_ACTOR_PATH_H