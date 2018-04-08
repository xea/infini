#ifndef XA_OBJECT_H
#define XA_OBJECT_H

#include <cmath>
#include <cstdint>
#include <chrono>
#include <memory>
#include <glm/glm.hpp>
#include <engine/rendering/RenderObject.h>
#include <world/Object.h>

class World;

class Object {
private:
    std::shared_ptr<RenderObject> renderObject;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 linearMomentum;
    glm::vec3 angularMomentum;
    double mass;

public:
    Object(std::shared_ptr<RenderObject> renderObject, double mass);
    std::shared_ptr<RenderObject> getRenderObject();
    void update(int32_t incrementMs);
	void addForce(glm::vec3 force);
	double distanceFrom(std::shared_ptr<Object> object);
};

#endif // XA_OBJECT_H