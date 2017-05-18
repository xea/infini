#include <engine/rendering/glew/GLEWRenderer.h>

GLEWRenderer::GLEWRenderer() {
    GLenum initResult = glewInit();

    if (GLEW_OK != initResult) {
        // TODO error handling
    }
}

void GLEWRenderer::clearScreen() {
    // TODO make these values configurable
    glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void GLEWRenderer::setRenderMode(RenderMode mode) {
    switch (mode) {
    case RenderMode::Wireframe:
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        break;
    case RenderMode::Fill:
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        break;
    }
}

void GLEWRenderer::drawScene(Scene& scene) {
}
