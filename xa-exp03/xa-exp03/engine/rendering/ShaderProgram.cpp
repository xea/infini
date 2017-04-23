#include <engine/rendering/ShaderProgram.h>

ShaderProgram::ShaderProgram() {
	programId = glCreateProgram();
}

void ShaderProgram::addShader(Shader shader) {
	shaders.push_back(shader);
}

void ShaderProgram::link() {
	for (Shader& shader : shaders) {
		glAttachShader(programId, shader.shaderId);
	}

	glLinkProgram(programId);
}

void ShaderProgram::use() {
	glUseProgram(programId);
}

void ShaderProgram::destroy() {
	for (Shader& shader : shaders) {
		shader.destroy();
	}
}