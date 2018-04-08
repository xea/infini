#include <world/World.h>

World::World() {
}

void PhysicsWorld::start() {
	processThread = thread([this]() {
		while (true) {
			for (auto& object : objects) {
				// gravitational pull
				glm::vec3 gravity = glm::vec3(0.0f, -0.010f, 0.0f);

				for (auto& gobj : objects) {
					//auto force = 6.67408 * (object->mass * gobj->mass) / std::pow(object->distanceFrom(gobj), 2);

					
				}

				object->addForce(gravity);

				object->update(10);
			}

			this_thread::sleep_for(10ms);
		}
	});
}

void PhysicsWorld::stop() {
	if (processThread.joinable()) {
		processThread.join();
	}
}

void PhysicsWorld::addObject(std::shared_ptr<Object> object) {
	objects.push_back(object);
}

void ActorWorld::start() {
    auto physicsRef = actorSystem->actorOf("physics", [](){ return make_unique<Physics>(); });

    std::shared_ptr<Message> msg = std::make_shared<ControlMessage>(ControlMessageType::Start);

    physicsRef.send(msg);
}

void ActorWorld::stop() {
}

void ActorWorld::addObject(std::shared_ptr<Object> object) {
    ActorRef newActor = actorSystem->actorOf("testActor", [object]() { return std::make_unique<RenderActor>(object); });

    actors.push_back(newActor);
}