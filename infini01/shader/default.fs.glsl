#version 150

in vec3 v_normal;
in vec3 v_pos;
out vec4 color;

uniform vec3 u_light;

void main() {
    float brightness = dot(normalize(v_normal), normalize(u_light));
    vec3 dark_color = vec3(0.3 * v_pos.z, 0.0, 0.6 * v_pos.z);
    vec3 regular_color = vec3(0.0, 0.0, 1.0);

    color = vec4(mix(dark_color, regular_color, brightness), 1.0);
}
