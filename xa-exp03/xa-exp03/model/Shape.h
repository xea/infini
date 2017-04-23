#ifndef XA_SHAPE_H
#define XA_SHAPE_H

#include <memory>
#include <vector>

#include <GL/glew.h>

class Shape {
public:
	virtual std::shared_ptr<std::vector<GLfloat>> getVertices() = 0;

	virtual std::shared_ptr<std::vector<GLuint>> getIndices() = 0;
};

class Triangle : public Shape {
private:
public:
	std::shared_ptr<std::vector<GLfloat>> getVertices();

	std::shared_ptr<std::vector<GLuint>> getIndices();

};

class Square : public Shape {
private:
public:
	std::shared_ptr<std::vector<GLfloat>> getVertices();

	std::shared_ptr<std::vector<GLuint>> getIndices();

};

#endif // XA_SHAPE_H