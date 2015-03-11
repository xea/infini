#include "script/DemoScript.h"

DemoScript::DemoScript() {
	scene = new Scene();
}

void DemoScript::run() {
}

void DemoScript::onStart() {
	
    /*
	Dog *dog = new Dog();
		
	scene->entities.push_back(dog);
	scriptingInterface->add(*dog);

	dog->translate(glm::vec3(1.0, 1.0, 0));
	dog->scale(glm::vec3(glm::vec3(0.5f, 0.5f, 0.5f)));
	dog->renderObject().unifiedColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	for (int i = 0; i < 1; i++) {
		Cube *cube = new Cube();
		
		cube->translate(glm::vec3(1, 0, 0));
		cube->scale(glm::vec3(0.1, 0.2, 0.1));
		//cube->unifiedColor(glm::vec4((float)i / 100, (float)i / 200, 1.0, 1.0));
		//cube->translate(glm::vec3(i / 10 - 1, i / 10 - 1, 0));
		//cube->translate(glm::vec3(i, 0, 0));

		scene->objects.push_back(cube);
	}
    */
}

void DemoScript::onUpdate() {
/*	for (RenderObject *currentObject : scene->objects) {
		currentObject->rotate(glm::vec3(0.001f, 0.000f, 0));
	}*/
}


Scene& DemoScript::currentScene() {
	return *scene;
}

void DemoScript::update() {
	onUpdate();
}
