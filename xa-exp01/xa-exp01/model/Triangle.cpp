#include "Triangle.h"

float Triangle::objectVertices[9] = {
	-0.5f, -0.3f, 0.0f,
	-0.5f,  0.5f, 0.0f,
	 0.2f,  0.5f, 0.0f
};

Triangle::Triangle() {
}

Triangle::~Triangle() {
}

float *Triangle::vertices() {
	return objectVertices;
}

int Triangle::verticesCount() {
	return (sizeof(objectVertices) / sizeof(float)) / 3;
}