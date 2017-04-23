#ifndef XA_SHADERPROGRAM_H
#define XA_SHADERPROGRAM_H

#include <list>
#include <engine/rendering/Shader.h>
#include <engine/rendering/ShaderSource.h>

class ShaderProgram {
private:

	std::list<Shader> shaders;

public:
	GLuint programId;

	ShaderProgram();

	ShaderProgram(std::shared_ptr<ShaderSource> shaderSource);

	void addShader(Shader shader);

	void link();

	void use();

	void destroy();
};

#endif // XA_SHADERPROGRAM_H