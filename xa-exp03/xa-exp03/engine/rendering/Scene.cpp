#include <engine/rendering/Scene.h>

std::list<std::shared_ptr<RenderObject>> Scene::getObjects() {
	return objects;
}

void Scene::add(std::shared_ptr<RenderObject> object) {
	this->objects.push_back(std::move(object));
}
