#include <engine/GL43Renderer.h>

void GL43Renderer::clearScreen() {
	glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void GL43Renderer::drawScene(std::shared_ptr<Scene> scene) {
	for (auto& object : scene->getObjects()) {
		drawObject(object);
	}

	glBindVertexArray(0);
}

void GL43Renderer::drawObject(std::shared_ptr<RenderObject> object) {
	object->vertexArray.bind();

	GLsizei count = object->shape->getIndices()->size();

	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);

	object->vertexArray.unbind();
}

void GL43Renderer::setRenderMode(RenderMode mode) {
	switch (mode) {
	case RenderMode::Wireframe:
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case RenderMode::Fill:
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	}
}