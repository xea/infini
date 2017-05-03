#include <engine/rendering/ShaderSource.h>

std::string DefaultShaderSource::getVertexShader() {
	return R"(
#version 410 core
  
layout (location = 0) in vec3 position;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(position, 1.0f); //vec4(position.x, position.y, position.z, 1.0);
}

)";
}

std::string DefaultShaderSource::getFragmentShader() {
	return R"(
#version 410 core

out vec4 color;

void main()
{
    color = vec4(1.0f, 0.9f, 0.7f, 1.0f);
}
)";
}
