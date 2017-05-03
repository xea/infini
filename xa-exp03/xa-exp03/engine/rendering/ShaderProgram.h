#ifndef XA_SHADERPROGRAM_H
#define XA_SHADERPROGRAM_H

#include <list>
#include <string>
#include <engine/rendering/Shader.h>
#include <engine/rendering/ShaderSource.h>
#include <engine/rendering/Uniform.h>
#include <glm/glm.hpp>

class ShaderProgram {
private:

	std::list<Shader> shaders;

public:
	GLuint programId;

	ShaderProgram();

	ShaderProgram(std::shared_ptr<ShaderSource> shaderSource);

	void addShader(Shader shader);

	void bindUniform(std::string& name, std::shared_ptr<Uniform> uniform);

	void link();

	void use();

	void destroy();
};

#endif // XA_SHADERPROGRAM_H