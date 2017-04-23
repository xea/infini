#ifndef XA_VERTEXBUFFER_H
#define XA_VERTEXBUFFER_H

#include <GL/glew.h>
#include <array>

class VertexBuffer {
private:
	GLuint bufferId;

protected:

public:
	VertexBuffer();
	~VertexBuffer();

	void bind();
	void setVertices();
};

#endif // XA_VERTEXBUFFER_H