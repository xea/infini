#include <world/Object.h>

Object::Object(std::shared_ptr<RenderObject> renderObject, double mass) {
    this->renderObject = renderObject;
    this->mass = mass;
    // testing code
    this->velocity = glm::vec3(0.0, 1.0, 0.0);
}

std::shared_ptr<RenderObject> Object::getRenderObject() {
    return this->renderObject;
}

void Object::update() {
    renderObject->translate(velocity.x, velocity.y, velocity.z);
}