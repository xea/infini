#include <xa-exp03.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	Engine engine;

	engine.init();

	engine.start();

	engine.stop();

	return EXIT_SUCCESS;
}

void messageBox(std::wstring& title, std::wstring& message) {
	int msgboxID = MessageBox(NULL,
		(LPCWSTR)message.c_str(),
		(LPCWSTR)title.c_str(),
		MB_ICONWARNING | MB_OK
	);
}