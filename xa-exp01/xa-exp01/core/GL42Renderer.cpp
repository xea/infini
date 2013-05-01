#include "GL42Renderer.h"

void GL42Renderer::prepareScene() {
	glClearColor(0.4f, 0.6f, 0.9f, 0.0f);
}

void GL42Renderer::prepareFrame() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void GL42Renderer::drawScene() {
	glfwSwapBuffers();
}