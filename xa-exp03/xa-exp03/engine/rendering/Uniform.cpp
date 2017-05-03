#include <engine/rendering/Uniform.h>

void UniformMatrix4f::bind(GLint location) {
	glm::mat4 data;
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(data));
}
