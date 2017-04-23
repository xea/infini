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
/*
std::vector<GLfloat> Triangle::getVertices() {
	return std::vector<GLfloat>({
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	});
}

std::vector<GLuint> Triangle::getIndices() {
	return std::vector<GLuint>({
		0, 1, 2
	});
}

std::vector<GLfloat> Square::getVertices() {
	return std::vector<GLfloat>({
		-0.5f, -0.5f, 0.0f, // bottom left
	    -0.5f,  0.5f, 0.0f, // top left
		 0.5f,  0.5f, 0.0f, // top right
		 0.5f, -0.5f, 0.0f, // bottom right
	});
}

std::vector<GLuint> Square::getIndices() {
	return std::vector<GLuint>({
		0, 1, 3,
		1, 2, 3
	});
}
*/