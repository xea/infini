#version 420 core

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout(location = 0) in vec3 vertexPosition_modelspace;

void main() {
	vec4 v = vec4(vertexPosition_modelspace, 1);
	mat4 mvp = projectionMatrix * viewMatrix * modelMatrix;

	gl_Position = mvp * v;
}