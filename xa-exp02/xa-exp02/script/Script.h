#ifndef XA_SCRIPT_H
#define XA_SCRIPT_H

#include <world/ScriptingInterface.h>

class Script {

protected:

	ScriptingInterface *scriptingInterface;

public:

	Script();

	virtual void run() = 0;

	virtual void onStart() = 0;

	virtual void onUpdate() = 0;

	void setScriptingInterface(ScriptingInterface& scriptingInterface);
};

#endif // XA_SCRIPT_H
