#include <world/Object.h>

Object::Object(std::shared_ptr<RenderObject> renderObject, double mass) {
    this->renderObject = renderObject;
    this->mass = mass;
}

std::shared_ptr<RenderObject> Object::getRenderObject() {
    return this->renderObject;
}
