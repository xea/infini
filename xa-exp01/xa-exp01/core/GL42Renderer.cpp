#include "GL42Renderer.h"

void GL42Renderer::prepareScene() {
	glClearColor(0.4f, 0.6f, 0.9f, 0.0f);

	shaderProgram = new ShaderProgram();

	shaderProgram->loadShader("passthrough.vs", GL_VERTEX_SHADER);
	shaderProgram->loadShader("passthrough.fs", GL_FRAGMENT_SHADER);
	
	shaderProgram->link();
	shaderProgram->validate();
	shaderProgram->bind();

}

void GL42Renderer::prepareFrame() {
	glViewport(0, 0, 1024, 768);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void GL42Renderer::drawScene() {
	

	glfwSwapBuffers();
}

void GL42Renderer::destroyScene() {
	shaderProgram->unbind();
	delete shaderProgram;
}