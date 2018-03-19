#version 330 core

in vec3 fragmentColor;
out vec4 FragColor;

void main() {
    // FragColor = vec4(floor(fragmentColor.x * 10), floor(fragmentColor.y * 10), floor(fragmentColor.z * 10), 1.0f);
    FragColor = vec4(fragmentColor, 1.0f);
    // FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}

