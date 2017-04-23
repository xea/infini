#include <engine/rendering/ElementBuffer.h>

ElementBuffer::ElementBuffer() {
	glGenBuffers(1, &bufferId);
}

void ElementBuffer::bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
}

void ElementBuffer::setIndices(std::shared_ptr<std::vector<GLuint>> indices) {
	GLuint *data = indices->data();

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data) * indices->size(), data, GL_STATIC_DRAW);
}