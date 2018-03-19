#ifndef XA_RENDEROBJECT_H
#define XA_RENDEROBJECT_H

#include <engine/rendering/Mesh.h>
#include <engine/rendering/gl/Uniform.h>
#include <memory>
#include <vector>

using namespace std;

/**
 * Represents an object that can be displayed on the screen
 */
class RenderObject {

protected:
    Uniform uniform;

public:
    virtual void bind(UniformLocations uniformLocations) = 0;

    virtual void draw() = 0;

    virtual void unbind() = 0;

    virtual std::shared_ptr<Mesh> getMesh() = 0;
    
    virtual void translate(float distance, float x, float y, float z) = 0;

	virtual void rotate(float angle, float x, float y, float z) = 0;
};

#endif // XA_RENDEROBJECT_H