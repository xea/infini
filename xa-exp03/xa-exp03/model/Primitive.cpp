#include <model/Shape.h>

std::shared_ptr<std::vector<GLfloat>> Triangle::getVertices() {
	std::vector<GLfloat> vertices({
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	});

	return std::make_shared<std::vector<GLfloat>>(vertices);
}

std::shared_ptr<std::vector<GLuint>> Triangle::getIndices() {
	std::vector<GLuint> indices({
		0, 1, 2
	});

	return std::make_shared<std::vector<GLuint>>(indices);
}


std::shared_ptr<std::vector<GLfloat>> Square::getVertices() {
	std::vector<GLfloat> vertices({
	 	 0.5f,  0.5f, 0.0f,  // Top Right
		 0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		-0.5f,  0.5f, 0.0f   // Top Left 
	});

	return std::make_shared<std::vector<GLfloat>>(vertices);
}

std::shared_ptr<std::vector<GLuint>> Square::getIndices() {
	std::vector<GLuint> indices({
		0, 1, 3,
		1, 2, 3
	});

	return std::make_shared<std::vector<GLuint>>(indices);
}

