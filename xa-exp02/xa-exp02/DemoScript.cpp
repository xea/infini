#include "script\DemoScript.h"

DemoScript::DemoScript() {
	scene = new Scene();
}

void DemoScript::run() {
}

void DemoScript::onStart() {
	
	Dog *dog = new Dog();
	dog->renderObject().unifiedColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	scene->entities.push_back(dog);
	scriptingInterface->add(*dog);
	for (int i = 0; i < 100; i++) {
		Cube *cube = new Cube();
		cube->scale(glm::vec3(0.1, 0.2, 0.1));
		cube->unifiedColor(glm::vec4((float)i / 100, (float)i / 200, 1.0, 1.0));
		cube->translate(glm::vec3(i / 10 - 10, i / 10 - 10, 0));

		scene->objects.push_back(cube);
		//scene->objects.push_back(&(dog->renderObject()));
	}
}

void DemoScript::onUpdate() {
	for (RenderObject *currentObject : scene->objects) {
		currentObject->rotate(glm::vec3(1, 1, 0));
	}
}


Scene& DemoScript::currentScene() {
	return *scene;
}

void DemoScript::update() {
	onUpdate();
}