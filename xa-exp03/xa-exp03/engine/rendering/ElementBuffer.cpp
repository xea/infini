#include <engine/rendering/ElementBuffer.h>

ElementBuffer::ElementBuffer() {
	glGenBuffers(1, &bufferId);
}

void ElementBuffer::bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
}

void ElementBuffer::setIndices() {
	GLuint indices[] = {
		0, 1, 3, // First triangle
		1, 2, 3  // Second triangle
	};

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}