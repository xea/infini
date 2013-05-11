#version 420 core

uniform mat4 uMVPMatrix;
uniform mat4 modelMatrix;

layout(location = 0) in vec3 vertexPosition_modelspace;

void main() {
	mat4 m = modelMatrix;
	vec4 v = vec4(vertexPosition_modelspace, 1);
	gl_Position = uMVPMatrix * v;
}