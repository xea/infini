#ifndef XA_OBJECT_RENDER_OBJECT_H
#define XA_OBJECT_RENDER_OBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/**
 * The base class for every object that can be rendered on a scene.
 *
 * Defines the skeleton for transformation methods of the implementing objects
 */
class RenderObject {

private:

public:

	/**
	 * Virtual destructor for destructing the object (surprise, surprise)
	 */
	virtual ~RenderObject() = 0;

	/**
	 * Rotates this object based on the given rotation matrix.
	 * 
	 */
	virtual void rotate(glm::vec3 rotationMatrix) = 0;

	virtual void translate(glm::vec3 translationMatrix) = 0;

	virtual void scale(glm::vec3 scalingMatrix) = 0;
};

#endif // XA_OBJECT_RENDER_OBJECT_H