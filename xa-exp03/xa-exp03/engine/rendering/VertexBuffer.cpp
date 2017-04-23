#include <engine/rendering/VertexBuffer.h>

VertexBuffer::VertexBuffer() {
	glGenBuffers(1, &bufferId);
}

VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &bufferId);
}

// 2.
void VertexBuffer::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
}

void VertexBuffer::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// 3.
void VertexBuffer::setVertices(std::shared_ptr<std::vector<GLfloat>> vertices) {
	/*
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};
	*/

	GLfloat * data = vertices->data();

	/*
	GLfloat vertices[] = {
		0.5f,  0.5f, 0.0f, // top right
		0.5f, -0.5f, 0.0f, // bottom right
	   -0.5f, -0.5f, 0.0f, // bottom left
	   -0.5f,  0.5f, 0.0f, // top left
	};
	*/

	/*
	GL_STATIC_DRAW: the data will most likely not change at all or very rarely.
	GL_DYNAMIC_DRAW: the data is likely to change a lot.
	GL_STREAM_DRAW: the data will change every time it is drawn.
	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}
