#version 150

in vec3 position;
in vec3 normal;

out vec3 v_normal;
out vec3 v_pos;

uniform mat4 transform;

void main() {
    v_normal = transpose(inverse(mat3(transform))) * normal;
    gl_Position = transform * vec4(position, 1.0);
    v_pos = gl_Position.xyz;
}
