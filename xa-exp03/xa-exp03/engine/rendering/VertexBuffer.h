#ifndef XA_VERTEXBUFFER_H
#define XA_VERTEXBUFFER_H

#include <GL/glew.h>
#include <memory>
#include <array>
#include <vector>

class VertexBuffer {
private:

protected:

public:
	GLuint bufferId;

	VertexBuffer();
	~VertexBuffer();

	void bind();
	void unbind();
	void setVertices(std::shared_ptr<std::vector<GLfloat>> vertices);
};

#endif // XA_VERTEXBUFFER_H