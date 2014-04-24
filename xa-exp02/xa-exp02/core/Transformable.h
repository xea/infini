#ifndef XA_TRANSFORMABLE_H
#define XA_TRANSFORMABLE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/**
 * Specifies transformation operations eg. rotate, scale, transform that 
 * subclasses must implement so that they can be externally positioned.
 */
class Transformable {

public:	

	/**
	 * Rotates this object based on the given rotation matrix.
	 * 
	 */
	virtual void rotate(glm::vec3 rotationMatrix) = 0;

	/**
	 * Translates this object based on the given translation matrix.
	 */
	virtual void translate(glm::vec3 translationMatrix) = 0;

	/**
	 * Scales this object based on the given scaling matrix.
	 */
	virtual void scale(glm::vec3 scalingMatrix) = 0;
};

#endif // XA_TRANSFORMABLE_H