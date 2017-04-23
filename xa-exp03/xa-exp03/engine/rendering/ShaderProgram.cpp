#include <engine/rendering/ShaderProgram.h>

ShaderProgram::ShaderProgram() {
	programId = glCreateProgram();
}

ShaderProgram::ShaderProgram(std::shared_ptr<ShaderSource> shaderSource) {
	programId = glCreateProgram();

	Shader vertexShader = Shader::createVertexShader(shaderSource);
	Shader fragmentShader = Shader::createFragmentShader(shaderSource);

	addShader(vertexShader);
	addShader(fragmentShader);

	// TODO linking may not be necessary here
	link();
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