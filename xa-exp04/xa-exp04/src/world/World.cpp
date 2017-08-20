#include <world/World.h>

World::World() {
    ActorSystem system;

    ActorRef firstActor = system.actorOf("testActor");

    Message message;

    firstActor.send(message);
}