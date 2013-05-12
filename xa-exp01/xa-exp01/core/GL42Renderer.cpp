#include "GL42Renderer.h"

void GL42Renderer::prepareScene() {
	glClearColor(0.4f, 0.6f, 0.9f, 0.0f);

	shaderProgram = new ShaderProgram();

	shaderProgram->loadShader("shaders/passthrough.vs", GL_VERTEX_SHADER);
	shaderProgram->loadShader("shaders/passthrough.fs", GL_FRAGMENT_SHADER);
	
	shaderProgram->link();
	shaderProgram->validate();
	
	projectionMatrix = glm::perspective(60.0f, (float)1024/ (float)768, 0.1f, 100.f);
}

void GL42Renderer::prepareFrame() {
	glViewport(0, 0, 1024, 768);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void GL42Renderer::drawScene() {
	shaderProgram->bind();

	viewMatrix = glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0));
	modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));  
	
	Triangle *triangle = new Triangle();

	drawObject(triangle);
	
	delete triangle;

	glfwSwapBuffers();
}

void GL42Renderer::destroyScene() {
	shaderProgram->unbind();
	delete shaderProgram;
}

void GL42Renderer::bindObject(RenderObject *object) {
	glGenVertexArrays(1, &vaoID[0]);
	glBindVertexArray(vaoID[0]);

	glGenBuffers(1, vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID[0]);
	glBufferData(GL_ARRAY_BUFFER, object->verticesCount() * 3 * sizeof(GLfloat), object->vertices(), GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint) 0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

float ffmod = 0.0f;

void GL42Renderer::drawObject(RenderObject *object) {
	bindObject(object);

	ffmod += 0.05f;

	//modelMatrix = glm::rotate(modelMatrix, ffmod * 10, glm::vec3(1,0,0));
	//modelMatrix = glm::translate(modelMatrix, glm::vec3(ffmod, 0, 0));

	glm::mat4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;

	int projectionMatrixLocation = glGetUniformLocation(shaderProgram->getId(), "projectionMatrix");
	int viewMatrixLocation = glGetUniformLocation(shaderProgram->getId(), "viewMatrix"); 
	int modelMatrixLocation = glGetUniformLocation(shaderProgram->getId(), "modelMatrix"); 
	int mvpMatrixLocation = glGetUniformLocation(shaderProgram->getId(), "uMVPMatrix");

	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]); 
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); 
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]); 
	glUniformMatrix4fv(mvpMatrixLocation, 1, GL_FALSE, &mvpMatrix[0][0]);

	glBindVertexArray(vaoID[0]);

	glDrawArrays(GL_TRIANGLES, 0, object->verticesCount());

	glBindVertexArray(0); // Unbind our Vertex Array Object

}