#include <engine/Engine.h>

Engine::Engine() {
	view = std::make_unique<GLFWView>();
	renderer = std::make_unique<GL43Renderer>();
}

void Engine::start() {
	view->start();

	ShaderProgram shaderProgram(std::make_shared<DefaultShaderSource>());

	std::shared_ptr<Scene> scene = std::make_shared<Scene>();

	std::shared_ptr<RenderObject> sharedObject = std::make_shared<RenderObject>(std::make_unique<Square>());
	sharedObject->prepare();
	scene->add(sharedObject);
	
	while (!view->shouldClose()) {
		renderer->clearScreen();

		shaderProgram.use();

		//renderer->drawObject(sharedObject);
		renderer->drawScene(scene);

		view->swapBuffers();
	}
}

void Engine::stop() {
	view->stop();
}