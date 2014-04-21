#ifndef XA_DEMOSCRIPT_H
#define XA_DEMOSCRIPT_H

#include "script\Script.h"

class DemoScript : public Script {

private:

	ScriptingInterface *scriptingInterface;

public:

	void run();

	void onStart();

	void setScriptingInterface(ScriptingInterface& scriptingInterface);

};

#endif // XA_DEMOSCRIPT_H