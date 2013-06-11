#include "xa-exp02.h"

#pragma comment(lib, "lua.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	Engine engine;

	engine.loadScript("test.lua");

	return 0;
}