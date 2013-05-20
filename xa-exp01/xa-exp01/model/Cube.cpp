#include "Cube.h"

float Cube::objectVertices[42] = {
	0, 0, 0,
	1, 0, 0,
	0, 1, 0,
	1, 1, 0,
	0, 1, 1,
	1, 1, 1,
	0, 0, 1,
	1, 0, 1,
	1, 1, 0,
	1, 0, 0,
	0, 0, 1,
	0, 0, 0,
	0, 1, 1,
	0, 1, 0
};

Cube::Cube() {
}

Cube::~Cube() {
}

float *Cube::vertices() {
	return objectVertices;
}

int Cube::verticesCount() {
	return (sizeof(objectVertices) / sizeof(float)) / 3;
}

GLenum Cube::drawMode() {
	return GL_TRIANGLE_STRIP;
}