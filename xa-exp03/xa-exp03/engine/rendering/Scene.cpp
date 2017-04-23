#include <engine/rendering/Scene.h>

void Scene::init() {
	vertexArray.bind();
	vertexBuffer.bind();
	vertexBuffer.setVertices();
	elementBuffer.bind();
	elementBuffer.setIndices();
	vertexArray.setAttributes();
	vertexArray.unbind();

	std::shared_ptr<DefaultShaderSource> source = std::make_shared<DefaultShaderSource>();
	Shader vertexShader = Shader::createVertexShader(source);
	Shader fragmentShader = Shader::createFragmentShader(source);

	shaderProgram.addShader(vertexShader);
	shaderProgram.addShader(fragmentShader);
	shaderProgram.link();
}

void Scene::preDraw() {
	vertexArray.bind();
	shaderProgram.use();
}

void Scene::draw() {
	preDraw();

	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	postDraw();
}

void Scene::postDraw() {
	vertexArray.unbind();
}