#include <world/World.h>

World::World() {
    /*
    ActorSystem system;

    ActorRef firstActor = system.create("testActor", []() { return make_unique<TestActor>(); });

    ActorRef firstActorRef = system.actorOf("testActor");

    Message message;

    auto i = 10;

    //firstActor.send(message);

    tirstActorRef.send(message);
    */
}

void ActorWorld::start() {
    ActorRef firstActor = actorSystem->create("testActor", []() { return make_unique<TestActor>(); });
    cout << "created new actor " << endl;
    
    Message message;

    firstActor.send(message);
}

void ActorWorld::stop() {
    
}