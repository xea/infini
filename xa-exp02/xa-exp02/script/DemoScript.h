#ifndef XA_DEMOSCRIPT_H
#define XA_DEMOSCRIPT_H

#include <chrono>
#include <script/Script.h>
#include <script/Director.h>
#include <rendering/Scene.h>
#include <world/ScriptingInterface.h>
#include <world/Dog.h>

class DemoScript : public Script, public Director {

private:

	Scene *scene;

public:

	DemoScript();

	void run();

	void onStart();

	void onUpdate();

	void setScriptingInterface(ScriptingInterface& scriptingInterface);

	void update();

	Scene& currentScene();

};

#endif // XA_DEMOSCRIPT_H