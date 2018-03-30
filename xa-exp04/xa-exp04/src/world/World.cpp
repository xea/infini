#include <world/World.h>

World::World() {
}

void ActorWorld::start() {
    //ActorRef testActor = actorSystem->actorOf("testActor", []() { return make_unique<TestActor>(); });
    /*
    physics.send(Message::START);
    */

	/*l
    ActorRef firstActor = actorSystem->create("testActor", []() { return make_unique<TestActor>(); });
    Message message;

    for (int i = 0; i < 100000000; i++) {
        firstActor.send(message);
    }

   // ActorRef firstActorRef = system.actorOf("testActor");

	this_thread::sleep_for(10s);
	*/
}

void ActorWorld::stop() {

}

void ActorWorld::addObject(std::shared_ptr<Object> object) {
    ActorRef firstActor = actorSystem->actorOf("testActor", [object]() { return std::make_unique<RenderActor>(object); });
}