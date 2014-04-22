#include "script\DemoScript.h"

DemoScript::DemoScript() {
	scene = new Scene();
}

void DemoScript::run() {
}

void DemoScript::onStart() {
	
	Dog *dog = new Dog();

	scriptingInterface->add(*dog);
	scene->objects.push_back(&(dog->renderObject()));
}

void DemoScript::onUpdate() {
	for (RenderObject *currentObject : scene->objects) {
		currentObject->rotate(glm::vec3(1, 1, 0));
	}
}

void DemoScript::setScriptingInterface(ScriptingInterface& scriptingInterface) {
	this->scriptingInterface = &scriptingInterface;
}

Scene& DemoScript::currentScene() {
	return *scene;
}

void DemoScript::update() {
	onUpdate();
}