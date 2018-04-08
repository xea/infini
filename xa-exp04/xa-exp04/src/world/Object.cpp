#include <world/Object.h>

Object::Object(std::shared_ptr<RenderObject> renderObject, double mass) {
    this->renderObject = renderObject;
    this->mass = mass;
	this->position = glm::vec3(0.0, 0.0, 0.0);
	this->rotation = glm::vec3(0.0, 0.0, 0.0);
    this->linearMomentum = glm::vec3(0.0, 0.0, 0.0);
	this->angularMomentum = glm::vec3(0.0, 0.0, 0.0);
}

std::shared_ptr<RenderObject> Object::getRenderObject() {
    return this->renderObject;
}

void Object::update(int32_t incrementMs) {
	if (incrementMs != 0) {
		auto linearIncrement = glm::vec3(linearMomentum.x / 1000.0 * incrementMs, linearMomentum.y / 1000 * incrementMs, linearMomentum.z / 1000 * incrementMs);
		auto angularIncrement = glm::vec3(angularMomentum.x / 1000.0 * incrementMs, angularMomentum.y / 1000 * incrementMs, angularMomentum.z / 1000 * incrementMs);

		position += linearIncrement;
		rotation += angularIncrement;

		renderObject->translate(linearIncrement.x, linearIncrement.y, linearIncrement.z);
		renderObject->rotate(angularIncrement.x, 1.0, 0.0, 0.0);
		renderObject->rotate(angularIncrement.y, 0.0, 1.0, 0.0);
		renderObject->rotate(angularIncrement.z, 0.0, 0.0, 1.0);
	}
}

double Object::distanceFrom(std::shared_ptr<Object> otherObject) {
	auto diff = otherObject->position - this->position;

	double distance = std::cbrt(std::pow(diff.x, 2) + std::pow(diff.y, 2) + std::pow(diff.z, 2));

	return distance;
}

void Object::addForce(glm::vec3 force) {
	linearMomentum += force;
}
