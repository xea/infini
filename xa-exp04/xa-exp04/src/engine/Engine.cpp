#include <engine/Engine.h>

Engine::Engine() {
    logger = Logger::getInstance("Engine");

    // TODO configuration should probably not be instantiated here
    Config config;

    // TODO view and renderer should be refactored to be less hardcoded
    logger->debug("Initialising view");
    view = make_unique<GLFWView>(config.getResolution());

    logger->debug("Initialising renderer");
    renderer = make_unique<GLEWRenderer>();

    logger->debug("Engine initialised");
}

void Engine::start() {
    logger->info("Starting Engine");

    Director director;

    ShaderProgram shaderProgram = ShaderProgram::getDefault();

//    Result<int, float> r = Result<int, int>::ok(12);
 //   Result<float, float> r2 = r.map([](int i) -> float { return 0.0f; });

    Scene scene = director.getScene();

    shaderProgram.use();

    while (!view->closeRequested()) {
        renderer->clearScreen();
        renderer->drawScene(scene);

        view->swapBuffers();
    }

    logger->info("Close requested, shutting down");
}