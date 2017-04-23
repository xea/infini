#include <engine/rendering/VertexArray.h>

VertexArray::VertexArray() {
	glGenVertexArrays(1, &arrayId);
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &arrayId);
}

// 1.
void VertexArray::bind() {
	glBindVertexArray(arrayId);
}

// 4.
void VertexArray::setAttributes() {
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
}

// 4.
void VertexArray::unbind() {
	glBindVertexArray(0);
}