#include "xa-exp01.h"

bool mayContinue();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	View *view = ObjectFactory::getView(View::TYPE_GLFW);
	Renderer *renderer = ObjectFactory::getRenderer(Renderer::TYPE_GL42);

	view->initialize(renderer);
	
	bool running = true;

	renderer->prepareScene();

	while (running) {
		renderer->prepareFrame();

		renderer->drawScene();

		running = mayContinue();
	}

	view->destroy();

	delete renderer;
	delete view;

	return 0;
}

bool mayContinue() {
	return !(glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED));
}