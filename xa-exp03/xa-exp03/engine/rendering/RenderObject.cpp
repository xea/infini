#include <engine/rendering/RenderObject.h>

RenderObject::RenderObject(std::shared_ptr<Shape> shape) {
	this->shape = std::move(shape);
}

void RenderObject::prepare() {
	vertexArray.bind();

	vertexBuffer.bind();
	vertexBuffer.setVertices(shape->getVertices());

	elementBuffer.bind();
	elementBuffer.setIndices(shape->getIndices());

	vertexArray.setAttributes();
	vertexBuffer.unbind();
	vertexArray.unbind();
}

std::shared_ptr<glm::mat4> RenderObject::getTransform() {
	return std::make_shared<glm::mat4>(this->transform);
}