#include <xa-exp03.h>
#include <cstdlib>

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
#else
int main(int argc, char **argv) {
#endif
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
