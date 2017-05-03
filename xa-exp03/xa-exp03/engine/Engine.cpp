#include <engine/Engine.h>

#include <cstdio>

Engine::Engine() {
	view = std::make_unique<GLFWView>();
	renderer = std::make_unique<GL43Renderer>();
}

void Engine::start() {
	view->start();

	ShaderProgram shaderProgram(std::make_shared<DefaultShaderSource>());

	// TODO clean this up a bit
	std::shared_ptr<Scene> scene = std::make_shared<Scene>();

	std::shared_ptr<RenderObject> square = std::make_shared<RenderObject>(std::make_unique<Square>());
	std::shared_ptr<RenderObject> triangle = std::make_shared<RenderObject>(std::make_unique<Triangle>());
	square->prepare();
	triangle->prepare();

	scene->add(square);
	scene->add(triangle);

    renderer->setRenderMode(RenderMode::Wireframe);
	
	while (!view->shouldClose()) {
		renderer->clearScreen();

		shaderProgram.use();

		renderer->drawScene(scene);

		view->swapBuffers();
	}
}

void Engine::stop() {
	view->stop();
}
