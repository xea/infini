#include "Triangle.h"

float Triangle::objectVertices[9] = {
	-0.5, -0.3, 0.0,
	-0.5,  0.5, 0.0,
	 0.2,  0.5, 0.0
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