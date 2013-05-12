#include "Square.h"

float Square::objectVertices[18] = {
	 0.0,  0.0, 0.0,
	 1.0,  0.0, 0.0,
	 1.0,  1.0, 0.0,
	 0.0,  1.0, 0.0,
	 1.0,  1.0, 0.0
};

Square::Square() {
}

Square::~Square() {
}

float *Square::vertices() {
	return objectVertices;
}

int Square::verticesCount() {
	return (sizeof(objectVertices) / sizeof(float)) / 3;
}