#ifndef XA_VERTEXBUFFER_H
#define XA_VERTEXBUFFER_H

#include <GL/glew.h>
#include <array>

class VertexBuffer {
private:
	GLuint bufferId;

protected:
	void create();
	void bind();
	void setVertices();

public:

};

#endif // XA_VERTEXBUFFER_H