#ifndef XA_SHADER_H
#define XA_SHADER_H

#include <GL/glew.h>
#include <memory>

#include <engine/rendering/ShaderSource.h>

enum class ShaderType : GLenum {
	VertexShader = GL_VERTEX_SHADER,
	FragmentShader = GL_FRAGMENT_SHADER,
	GeometryShader = GL_GEOMETRY_SHADER,
	ComputeShader = GL_COMPUTE_SHADER
};

class Shader {
private:
	void compile(std::string shaderCode);

public:
	GLuint shaderId;

	Shader(ShaderType type);

	static Shader createVertexShader(std::shared_ptr<ShaderSource> shaderSource);

	static Shader createFragmentShader(std::shared_ptr<ShaderSource> shaderSource);

	void destroy();
};

#endif // XA_SHADER_H