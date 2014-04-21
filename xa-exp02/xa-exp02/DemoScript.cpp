#include "script\DemoScript.h"

void DemoScript::run() {
}

void DemoScript::onStart() {

	Entity *entity = new Entity();

	scriptingInterface->add(*entity);
}

void DemoScript::setScriptingInterface(ScriptingInterface& scriptingInterface) {
	this->scriptingInterface = &scriptingInterface;
}
