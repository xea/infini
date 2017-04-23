#include <engine/Engine.h>

Engine::Engine() {
	view = new GLFWView();
	view->setRenderer(std::make_unique<GL43Renderer>());
}

void Engine::start() {
	view->start();

	Scene scene;

	scene.init();

	while (!view->shouldClose()) {
		view->clearScreen();

		scene.draw();

		view->swapBuffers();
	}
}

void Engine::stop() {
	view->stop();

	delete view;
}