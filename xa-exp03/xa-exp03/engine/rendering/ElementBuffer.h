#ifndef XA_ELEMENTBUFFER_H
#define XA_ELEMENTBUFFER_H

#include <GL/glew.h>

#include <memory>
#include <vector>

class ElementBuffer {
private:

public:
	GLuint bufferId;

	ElementBuffer();

	void bind();
	void setIndices(std::shared_ptr<std::vector<GLuint>> indices);
};

#endif // XA_ELEMENTBUFFER_H
