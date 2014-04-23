#include <script/Gravity.h>

void Gravity::run() {
}

void Gravity::onStart() {
}

void Gravity::onUpdate() {
	std::list<Entity *> entities = scriptingInterface->listEntities();

	for (Entity *entity : entities) {
		entity->renderObject().translate(glm::vec3(0, -4, 0));
	}
}
