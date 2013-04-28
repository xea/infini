#include "xa-exp01.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	View *view = ObjectFactory::getView(View::TYPE_GLFW);
	Renderer *renderer = ObjectFactory::getRenderer(Renderer::TYPE_GL42);

	view->initialize(renderer);
	view->destroy();

	delete renderer;
	delete view;

	return 0;
}