#include "Engine.h"

Engine::Engine() {
}

void Engine::start() {
	Scene *scene = &(director->currentScene());
	
	view = ObjectFactory::getView(View::TYPE_GLFW);
	renderer = ObjectFactory::getRenderer(Renderer::TYPE_GL42);

	const bool initialized = view->initialize(*renderer);

	renderer->prepareScene();

	bool running = true;

	while (running) {
		director->update();
		renderer->prepareFrame();
		renderer->drawScene(*scene);
		view->swapBuffers();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));

		running = mayContinue();
	}
}


bool Engine::mayContinue() {
	return !view->isClosing();
}


void Engine::stop() {
	renderer->destroyScene();
	view->destroy();

	delete renderer;
	delete view;
}

void Engine::setDirector(Director& director) {
	this->director = &director;
}
