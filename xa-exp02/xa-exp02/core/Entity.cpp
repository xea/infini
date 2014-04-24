#include <core/Entity.h>

void Entity::rotate(glm::vec3 rotationMatrix) {
	renderObject().rotate(rotationMatrix);
}

void Entity::translate(glm::vec3 translationMatrix) {
	renderObject().rotate(translationMatrix);
}

void Entity::scale(glm::vec3 scalingMatrix) {
	renderObject().scale(scalingMatrix);
}
