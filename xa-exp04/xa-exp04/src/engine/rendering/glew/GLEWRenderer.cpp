#include <engine/rendering/glew/GLEWRenderer.h>

GLEWRenderer::GLEWRenderer() {
    logger = Logger::getInstance("GLEWRenderer"); 

    GLenum initResult = glewInit();

    if (GLEW_OK != initResult) {
        // TODO error handling
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    viewState = std::make_shared<ViewState>();
    projectionState = std::make_shared<ProjectionState>(45.0f, 1.6f);

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
    updateView(viewState, projectionState);

    // bind optional scene-specific shaders
    for (auto object : scene->getObjects()) {
        this->drawObject(object);
    }

    applyFrameRateLimit();
}

void GLEWRenderer::drawObject(std::shared_ptr<RenderObject> renderObject) {
    renderObject->bind(uniformLocations);
    // bind vertex array
    // bind uniforms

    // draw vertices
    renderObject->draw();

    // unbind vertex array
    renderObject->unbind();
}

void GLEWRenderer::limitFrameRate(unsigned int limit) {
    this->frameRateLimit = limit;

    if (limit > 0) {
        this->frameMs = 1000 / limit;
    }
}

void GLEWRenderer::applyFrameRateLimit() {
    std::this_thread::sleep_for(std::chrono::milliseconds(20));

}

void GLEWRenderer::updateView(std::shared_ptr<ViewState> view, std::shared_ptr<ProjectionState> projection) {
    viewState = view;
    projectionState = projection;

    glUniformMatrix4fv(uniformLocations.view, 1, GL_FALSE, view->getValuePtr());
    glUniformMatrix4fv(uniformLocations.projection, 1, GL_FALSE, projection->getValuePtr());
}
