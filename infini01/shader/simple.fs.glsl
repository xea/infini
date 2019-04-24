#version 150

in vec3 v_pos;
out vec4 color;


void main() {
    color = vec4(1.0, v_pos.y, v_pos.z, 1.0);
}
