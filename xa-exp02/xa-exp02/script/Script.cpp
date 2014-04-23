#include "Script.h"

Script::Script() {
}

void Script::setScriptingInterface(ScriptingInterface& scriptingInterface) {
	this->scriptingInterface = &scriptingInterface;
}