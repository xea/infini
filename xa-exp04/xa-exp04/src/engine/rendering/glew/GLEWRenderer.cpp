#include <engine/rendering/glew/GLEWRenderer.h>

GLEWRenderer::GLEWRenderer(std::tuple<int, int> resolution) {
    logger = Logger::getInstance("GLEWRenderer"); 

    GLenum initResult = glewInit();

    if (GLEW_OK != initResult) {
        // TODO error handling
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    float aspectRatio = get<0>(resolution) / get<1>(resolution);
    projectionState = std::make_shared<ProjectionState>(45.0f, aspectRatio);
    viewState = std::make_shared<ViewState>();

	limitFrameRate(60);

    logger->info("Initialisation OK");
}

void GLEWRenderer::clearScreen() {
    // TODO make these values configurable
    glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void GLEWRenderer::setRenderMode(RenderMode mode) {
    logger->info("Setting render mode");

    switch (mode) {
    case RenderMode::Wireframe:
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        break;
    case RenderMode::Fill:
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        break;
    }
}

void GLEWRenderer::useShaderProgram(std::shared_ptr<ShaderProgram> shaderProgram) {
    this->shaderProgram = shaderProgram;

    uniformLocations = shaderProgram->use();
}

void GLEWRenderer::drawScene(std::shared_ptr<Scene> scene) {
    updateView(viewState);

    // bind optional scene-specific shaders
    for (auto object : scene->getObjects()) {
        this->drawObject(object);
    }

    applyFrameRateLimit();

	frameCount++;
}

void GLEWRenderer::drawObject(std::shared_ptr<RenderObject> renderObject) {
    renderObject->bind(uniformLocations);
    renderObject->draw();
    renderObject->unbind();
}

void GLEWRenderer::limitFrameRate(unsigned int limit) {
    this->frameRateLimit = limit;

    if (limit > 0) {
        this->frameMs = 1000 / limit;
    }

}

void GLEWRenderer::applyFrameRateLimit() {
	auto now = chrono::system_clock::now();

	auto duration = chrono::duration_cast<chrono::milliseconds>(now - lastFrame);

	if (duration.count() < frameMs) {
		auto sleepInterval = frameMs - duration.count();

		if (sleepInterval > 25) {
			this_thread::sleep_for(chrono::milliseconds(sleepInterval));
		}
	}

	lastFrame = now;
}

void GLEWRenderer::updateView(std::shared_ptr<ViewState> view) {
    viewState = view;

    glUniformMatrix4fv(uniformLocations.view, 1, GL_FALSE, viewState->getValuePtr());
    glUniformMatrix4fv(uniformLocations.projection, 1, GL_FALSE, projectionState->getValuePtr());
}
