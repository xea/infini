#include <engine/actor/ActorPath.h>

ActorPath::ActorPath(std::shared_ptr<ActorPath> parent, std::string name) {
    this->parent = parent;
    this->name = name;
}

std::string ActorPath::toString() {
    std::string pathstr;

    //pathstr.append(parent->toString());
    pathstr.append(name);

    return pathstr;
}

RootActorPath::RootActorPath() : ActorPath(nullptr, "/") {
}