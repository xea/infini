#include "Engine.h"

Engine::Engine() {
}

void Engine::start() {
	Scene *scene = &(director->currentScene());
	
	view = ObjectFactory::getView(View::TYPE_GLFW);
	renderer = ObjectFactory::getRenderer(Renderer::TYPE_GL42);

	view->initialize(*renderer);
	renderer->prepareScene();

	bool running = true;

	

	while (running) {
		renderer->prepareFrame();
		renderer->drawScene(*scene);

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

void Engine::setDirector(Director& director) {
	this->director = &director;
}
