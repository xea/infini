#ifndef XA_SCRIPT_H
#define XA_SCRIPT_H

#include <world\ScriptingInterface.h>

class Script {

public:

	Script();

	virtual void run() = 0;

	virtual void onStart() = 0;

	virtual void onUpdate() = 0;

	virtual void setScriptingInterface(ScriptingInterface& scriptingInterface) = 0;
};

#endif // XA_SCRIPT_H