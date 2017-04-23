#ifndef XA_ELEMENTBUFFER_H
#define XA_ELEMENTBUFFER_H

#include <GL/glew.h>

class ElementBuffer {
private:

	GLuint bufferId;
public:

	ElementBuffer();

	void bind();
	void setIndices();
};

#endif // XA_ELEMENTBUFFER_H
