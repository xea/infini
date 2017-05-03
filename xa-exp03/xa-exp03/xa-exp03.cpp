#include <xa-exp03.h>

int MAIN {
	Engine engine;

	engine.start();

	engine.stop();

	return EXIT_SUCCESS;
}

void messageBox(std::wstring& title, std::wstring& message) {
#ifdef _WIN32
	int msgboxID = MessageBox(NULL,
		(LPCWSTR)message.c_str(),
		(LPCWSTR)title.c_str(),
		MB_ICONWARNING | MB_OK
	);
#endif
}
