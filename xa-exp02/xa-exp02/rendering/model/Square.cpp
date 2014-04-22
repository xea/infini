#include <rendering/model/Square.h>

float Square::objectVertices[18] = {
	 0.0,  0.0, 0.0,
	 1.0,  0.0, 0.0,
	 1.0,  1.0, 0.0,
	 0.0,  1.0, 0.0,
	 1.0,  1.0, 0.0
};

float Square::vertexColors[18] = {
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

float *Square::colors() {
	return vertexColors;
}

int Square::colorsCount() {
	return (sizeof(vertexColors) / sizeof(float)) / 3;
}