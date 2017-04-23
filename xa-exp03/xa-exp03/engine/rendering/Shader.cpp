#include <engine/rendering/Shader.h>

Shader::Shader(ShaderType type) {
	shaderId = glCreateShader((GLenum) type);
}

Shader Shader::createVertexShader(std::shared_ptr<ShaderSource> shaderSource) {
	Shader shader(ShaderType::VertexShader);

	shader.compile(shaderSource->getVertexShader());

	return shader;
}

Shader Shader::createFragmentShader(std::shared_ptr<ShaderSource> shaderSource) {
	Shader shader(ShaderType::FragmentShader);

	shader.compile(shaderSource->getFragmentShader());

	return shader;
}

void Shader::compile(std::string shaderCode) {
	const char *rawCode = shaderCode.data();

	glShaderSource(shaderId, 1, &rawCode, NULL);
	glCompileShader(shaderId);
}

void Shader::destroy() {
	glDeleteShader(shaderId);
}