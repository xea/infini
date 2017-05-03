#ifndef XA_UNIFORM_H
#define XA_UNIFORM_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <memory>
#include <string>

class Uniforms {
private:

};

class Uniform {
public:
	virtual std::string& getName() = 0;
};

class UniformMatrix4f : public Uniform {
public:
	std::string& getName();

};

#endif // XA_UNIFORM_H
