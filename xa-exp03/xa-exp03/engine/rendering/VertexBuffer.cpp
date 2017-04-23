#include <engine/rendering/VertexBuffer.h>

void VertexBuffer::create() {
	glGenBuffers(1, &bufferId);
}

void VertexBuffer::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
}

void VertexBuffer::setVertices() {
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	/*
	GL_STATIC_DRAW: the data will most likely not change at all or very rarely.
	GL_DYNAMIC_DRAW: the data is likely to change a lot.
	GL_STREAM_DRAW: the data will change every time it is drawn.
	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}