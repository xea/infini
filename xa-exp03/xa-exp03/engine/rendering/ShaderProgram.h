#ifndef XA_SHADERPROGRAM_H
#define XA_SHADERPROGRAM_H

#include <list>
#include <engine/rendering/Shader.h>
#include <engine/rendering/ShaderSource.h>
#include <engine/rendering/Uniform.h>

class ShaderProgram {
private:

	std::list<Shader> shaders;

	std::unique_ptr<Uniform> uniforms;

public:
	GLuint programId;

	ShaderProgram();

	ShaderProgram(std::shared_ptr<ShaderSource> shaderSource);

	void addShader(Shader shader);

	void bindUniforms(std::unique_ptr<Uniforms> uniforms);

	void link();

	void use();

	void destroy();
};

#endif // XA_SHADERPROGRAM_H