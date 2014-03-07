#include "xa-exp02.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	Engine engine;
	World world;
	
	Object testDummy;

	DemoScript demoScript;



	engine.loadScript(demoScript);

	engine.start();
	world.start();

	world.add(testDummy);

	world.stop();
	engine.stop();

	return 0;
}