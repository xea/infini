#include "GL42Renderer.h"

void GL42Renderer::prepareScene() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	shaderProgram = new ShaderProgram();

	shaderProgram->loadShader("shaders/colors.vs", GL_VERTEX_SHADER);
	shaderProgram->loadShader("shaders/colors.fs", GL_FRAGMENT_SHADER);
	
	shaderProgram->link();
	shaderProgram->validate();
	
	prepareBuffers();

	Triangle *triangle = new Triangle();
	Square *square = new Square();
	Cube *cube = new Cube();
	Cube *cube2 = new Cube();
	Cube *cube3 = new Cube();
	Cube *cube4 = new Cube();

	cube->translate(glm::vec3(1.3, 0, 0));
	cube2->translate(glm::vec3(-1.3, 0, 0));
	cube3->translate(glm::vec3(0, -1.3, 0));
	cube4->translate(glm::vec3(-1.3, -1.3, 0));
	square->translate(glm::vec3(1.3, -1.3, 0));
	

	scene = new Scene();
	scene->objects.push_back(triangle);
	scene->objects.push_back(square);
	scene->objects.push_back(cube);
	scene->objects.push_back(cube2);
	scene->objects.push_back(cube3);
	scene->objects.push_back(cube4);

	projectionMatrix = glm::perspective(60.0f, (float) 1024 / (float) 768, 0.1f, 100.f);
	viewMatrix = glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0));

	shaderProgram->bind();
}

void GL42Renderer::prepareFrame() {
	glViewport(0, 0, 1024, 768);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void GL42Renderer::drawScene() {	

	for (auto& i : scene->objects) {
		drawObject(i);
	}
	
	glfwSwapBuffers();
}

void GL42Renderer::destroyScene() {
	shaderProgram->unbind();
	delete shaderProgram;

	std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

void GL42Renderer::bindObject(RenderObject *object) {
	glBindBuffer(GL_ARRAY_BUFFER, vboID[0]);
	glBufferData(GL_ARRAY_BUFFER, object->verticesCount() * 3 * sizeof(GLfloat), object->vertices(), GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint) 0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// DAFUQ - commenting out this makes the whole thing work: glBindVertexArray(0);
	glEnableVertexAttribArray(0);
	

	glBindBuffer(GL_ARRAY_BUFFER, vcoID[0]);
	glBufferData(GL_ARRAY_BUFFER, object->colorsCount() * 3 * sizeof(GLfloat), object->colors(), GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint) 1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	//glBindVertexArray(1);
	
}

float ffmod = 0.0f;

void GL42Renderer::drawObject(RenderObject *object) {
	bindObject(object);

	ffmod += 0.05f;

	object->rotate(glm::vec3(1, 1, 0));
	//object->translate(glm::vec3(0.01f, 0, 0));
	//object->scale(glm::vec3(1.0f, 1.0f, 1.0f));

	int projectionMatrixLocation = glGetUniformLocation(shaderProgram->getId(), "projectionMatrix");
	int viewMatrixLocation = glGetUniformLocation(shaderProgram->getId(), "viewMatrix"); 
	int modelMatrixLocation = glGetUniformLocation(shaderProgram->getId(), "modelMatrix"); 

	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]); 
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); 
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &object->getModelMatrix()[0][0]);

	glBindVertexArray(vaoID[0]);

	glDrawArrays(object->drawMode(), 0, object->verticesCount());

	glBindVertexArray(0); // Unbind our Vertex Array Object
}

void GL42Renderer::prepareBuffers() {	
	glGenVertexArrays(1, vaoID);
	glGenBuffers(1, vboID);
	glGenBuffers(1, vcoID);

	glBindVertexArray(vaoID[0]);
	
}