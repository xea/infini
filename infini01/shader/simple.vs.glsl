#version 150

in vec3 position;
out vec3 v_pos;

uniform mat4 transform;

void main() {
    gl_Position = transform * vec4(position, 1.0);
    v_pos = gl_Position.xyz;
}
