#include "script\DemoScript.h"

void DemoScript::run() {
}

void DemoScript::onStart() {

	Dog *dog = new Dog();

	scriptingInterface->add(*dog);
}

void DemoScript::setScriptingInterface(ScriptingInterface& scriptingInterface) {
	this->scriptingInterface = &scriptingInterface;
}
