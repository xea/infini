#include "xa-exp02.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	Engine engine;
	World world;

	DemoScript demoScript;
	Script *gravityScript = new Gravity();

	engine.setDirector(demoScript);
	world.attachScript(demoScript);
	world.attachScript(*gravityScript);
	world.start();

	engine.start();

	world.stop();
	engine.stop();

	return 0;
}

void messageBox(std::wstring& title, std::wstring& message) {
	int msgboxID = MessageBox(NULL,
		(LPCWSTR)message.c_str(),
		(LPCWSTR)title.c_str(),
		MB_ICONWARNING | MB_OK 
	);
}