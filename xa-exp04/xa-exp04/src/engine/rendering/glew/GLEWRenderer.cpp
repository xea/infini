#include <engine/rendering/glew/GLEWRenderer.h>

GLEWRenderer::GLEWRenderer(std::tuple<int, int> resolution) {
    logger = Logger::getInstance("GLEWRenderer"); 

    GLenum initResult = glewInit();

    if (GLEW_OK != initResult) {
        // TODO error handling
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    this->resolution = resolution;
    float aspectRatio = (float) get<0>(resolution) / (float) get<1>(resolution);
    projectionState = std::make_shared<ProjectionState>(45.0f, aspectRatio);
    viewState = std::make_shared<ViewState>();

	limitFrameRate(160);

    logger->info("Initialisation OK");
}

void GLEWRenderer::clearScreen() {
    // TODO make these values configurable
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
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

	// This isn't really needed due to vsync, unless to slow it down reaaaally
    applyFrameRateLimit();

	frameCount++;
}

void GLEWRenderer::drawObject(std::shared_ptr<RenderObject> renderObject) {
    renderObject->bind(uniformLocations);
    renderObject->draw();
    renderObject->unbind();
}

void GLEWRenderer::limitFrameRate(float limit) {
    this->frameRateLimit = limit;

    if (limit > 0) {
        this->frameMs = 1000 / (int) limit;
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

    if (frameCount % 100 == 0) {
        auto duration = chrono::duration_cast<chrono::milliseconds>(now - lastCheckPoint);

        double frameRate = duration.count() / 100.0;

        std::cout << "Frame time: " << frameRate << " ms" << std::endl;

        lastCheckPoint = now;
    }

	lastFrame = now;
}

void GLEWRenderer::updateView(std::shared_ptr<ViewState> view) {
	auto now = chrono::system_clock::now();

    viewState = view;

    float res[] = { (float) get<0>(resolution), (float) get<1>(resolution) };

    glUniformMatrix4fv(uniformLocations.view, 1, GL_FALSE, viewState->getValuePtr());
    glUniformMatrix4fv(uniformLocations.projection, 1, GL_FALSE, projectionState->getValuePtr());
    glUniform1i(uniformLocations.frameCount, frameCount);
    glUniform2fv(uniformLocations.resolution, 1, res);
    glUniform1f(uniformLocations.time, chrono::duration_cast<chrono::milliseconds>(now - startTime).count());
}
