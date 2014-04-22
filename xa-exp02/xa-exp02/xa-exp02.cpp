#include "xa-exp02.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	Engine engine;
	World world;

	DemoScript demoScript;

	engine.setDirector(demoScript);
	world.attachScript(demoScript);
	world.start();

	engine.start();

	world.stop();
	engine.stop();

	return 0;
}