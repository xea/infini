#ifndef XA_SHADERPROGRAM_H
#define XA_SHADERPROGRAM_H

#include <list>
#include <engine/rendering/Shader.h>

class ShaderProgram {
private:
	GLuint programId;

	std::list<Shader> shaders;

public:
	ShaderProgram();

	void addShader(Shader shader);

	void link();

	void use();

	void destroy();
};

#endif // XA_SHADERPROGRAM_H