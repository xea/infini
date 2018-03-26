#ifndef XA_OBJECT_H
#define XA_OBJECT_H

#include <memory>
#include <glm/glm.hpp>
#include <engine/rendering/RenderObject.h>
#include <world/Object.h>

class Object {
private:
    std::shared_ptr<RenderObject> renderObject;
    glm::vec3 velocity;
    glm::vec3 rotation;
    double mass;

public:
    Object(std::shared_ptr<RenderObject> renderObject, double mass);
    std::shared_ptr<RenderObject> getRenderObject();
};

#endif // XA_OBJECT_H