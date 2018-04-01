#include <world/World.h>

World::World() {
}

void ActorWorld::start() {
    physicsRef = actorSystem->actorOf("physics", [](){ return make_unique<Physics>(); });

    auto messageType = ControlMessageType::Start;


    std::shared_ptr<Message> msg = std::make_shared<ControlMessage>(ControlMessageType::Start);

    physicsRef.send(msg);
    //physicsRef.send(make_unique<ControlMessage>(message));

    /*
    physics.send(Message::START);
    */

}

void ActorWorld::stop() {

}

void ActorWorld::addObject(std::shared_ptr<Object> object) {
    ActorRef newActor = actorSystem->actorOf("testActor", [object]() { return std::make_unique<RenderActor>(object); });

    actors.push_back(newActor);
}