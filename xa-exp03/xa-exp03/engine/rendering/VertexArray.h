#ifndef XA_VERTEXARRAY_H
#define XA_VERTEXARRAY_H

#include <GL/glew.h>

class VertexArray {
private:
	GLuint arrayId;

public:
	VertexArray();
	~VertexArray();

	void bind();
	void setAttributes();
	void unbind();

};

#endif // XA_VERTEXARRAY_H