#include "RenderObject.h"

RenderObject::~RenderObject() {
	modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));  
}

glm::mat4 RenderObject::getModelMatrix() {
	return modelMatrix;
}

void RenderObject::rotate(glm::vec3 rotationVector) {
	modelMatrix = glm::rotate(modelMatrix, 0.001f, rotationVector);
}

void RenderObject::translate(glm::vec3 translationVector) {
	modelMatrix = glm::translate(modelMatrix, translationVector);
}

void RenderObject::scale(glm::vec3 scalingVector) {
	modelMatrix = glm::scale(modelMatrix, scalingVector);
}

void RenderObject::unifiedColor(glm::vec4 newColor) {
	// Left empty as a default implementation	
}

GLenum RenderObject::drawMode() {
	return GL_TRIANGLES;
}