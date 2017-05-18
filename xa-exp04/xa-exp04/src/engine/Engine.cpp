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

    Scene scene = director.getScene();

    while (true) {
        renderer->clearScreen();
        renderer->drawScene(scene);

        view->swapBuffers();
    }
}