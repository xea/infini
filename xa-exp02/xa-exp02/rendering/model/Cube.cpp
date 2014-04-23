#include <rendering\model\Cube.h>

float Cube::objectVertices[66] = {
	 1,  1, -1, 
	 1, -1, -1,
	-1,  1, -1,
	-1, -1, -1, 
	-1, -1,  1, 
	 1, -1, -1,
	 1, -1,  1, 
	 1,  1,  1, 
	-1, -1,  1,
	-1,  1,  1, 
	-1,  1, -1, 
	 1,  1,  1,
	 1,  1, -1, 
	 1, -1, -1,
	 0,  1,  0, 
	 0, -1,  0, 
	-1, -1,  0, 
	-1,  1,  0,
	 0,  1,  0, 
	 0, -1,  0, 
	 1, -1,  0, 
	 1,  1,  0
};

float Cube::vertexColors[66] = {
	0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f
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

float *Cube::colors() {
	return vertexColors;
}

int Cube::colorsCount() {
	return (sizeof(vertexColors) / sizeof(float)) / 3;
}

GLenum Cube::drawMode() {
	return GL_TRIANGLE_STRIP;
}

void Cube::unifiedColor(glm::vec4 color) {
	int colorSize = sizeof(vertexColors) / sizeof(float) / 3;

	for (int i = 0; i < colorSize; i++) {
		vertexColors[i * 3] = color.x;
		vertexColors[i * 3 + 1] = color.y;
		vertexColors[i * 3 + 2] = color.z;
	}
}