#version 420 core

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;

out vec3 fragmentColor;

void main() {
	vec4 v = vec4(vertexPosition_modelspace, 1);
	mat4 mvp = projectionMatrix * viewMatrix * modelMatrix;

	fragmentColor = vertexColor;

	gl_Position = mvp * v;
}