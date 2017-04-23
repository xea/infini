#include <engine/Engine.h>

void Engine::init() {
	view = new GLFWView();
	view->setRenderer(std::make_unique<GL43Renderer>());
}

void Engine::start() {
	view->start();

	while (!view->shouldClose()) {
		view->swapBuffers();
	}
}

void Engine::stop() {
	view->stop();

	delete view;
}