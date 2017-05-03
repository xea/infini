#ifndef XA_UNIFORM_H
#define XA_UNIFORM_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>

class Uniforms {
private:

};

class Uniform {
public:
	virtual void bind(GLint location) = 0;
};

class UniformMatrix4f : public Uniform {
public:

	void bind(GLint location);
};

#endif // XA_UNIFORM_H
