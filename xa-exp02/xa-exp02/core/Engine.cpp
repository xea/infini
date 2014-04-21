#include "Engine.h"

Engine::Engine() {
}

void Engine::start() {
	view = ObjectFactory::getView(View::TYPE_GLFW);
	renderer = ObjectFactory::getRenderer(Renderer::TYPE_GL42);

	view->initialize(*renderer);
	renderer->prepareScene();

	bool running = true;

	while (running) {
		renderer->prepareFrame();
		renderer->drawScene();

		running = mayContinue();
	}
}


bool Engine::mayContinue() {
	return !(glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED));
}


void Engine::stop() {
	renderer->destroyScene();
	view->destroy();

	delete renderer;
	delete view;
}
