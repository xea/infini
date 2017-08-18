#version 330 core

layout (location = 0) in vec3 aPos;

out vec3 fragmentColor;

uniform mat4 transformation;

void main() {
    fragmentColor = aPos;
    gl_Position = transformation * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}

