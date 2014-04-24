#ifndef XA_OBJECT_RENDER_OBJECT_H
#define XA_OBJECT_RENDER_OBJECT_H

#include <gl/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <core/Transformable.h>

/**
 * The base class for every object that can be rendered on a scene.
 *
 * Defines the skeleton for transformation methods of the implementing objects
 */
class RenderObject : public Transformable {

protected:

	unsigned int vaoID[1]; // Our Vertex Array Object
	unsigned int vboID[1]; // Our Vertex Buffer Object

	glm::mat4 modelMatrix;

public:

	/**
	 * Virtual destructor for destructing the object (surprise, surprise)
	 */
	virtual ~RenderObject() = 0;

	/**
	 * Returns an array containing the vertices of the given object described
	 * by it's x,y,z coordinates
	 */
	virtual float *vertices() = 0;

	/**
	 * Returns a value indicating the number of vertices used to described
	 * this object
	 */
	virtual int verticesCount() = 0;

	/**
	 * Returns an array containing the color attributes for each of the vertices
	 */
	virtual float *colors() = 0;

	/**
	 * Returns how many color attributes are stored in the color attribute array
	 */
	virtual int colorsCount() = 0;

	/**
	 * Rotates this object based on the given rotation matrix.
	 * 
	 */
	void rotate(glm::vec3 rotationMatrix);

	/**
	 * Translates this object based on the given translation matrix.
	 */
	void translate(glm::vec3 translationMatrix);

	/**
	 * Scales this object based on the given scaling matrix.
	 */
	void scale(glm::vec3 scalingMatrix);

	/**
	 * Returns the model matrix holding the objects position, rotation, scaling data
	 *
	 * This method may be deprecated in the future.
	 */
	glm::mat4 getModelMatrix();

	/**
	 * It tells which OpenGL draw mode should be used to draw the vertices of this
	 * object
	 */
	virtual GLenum drawMode();

	void unifiedColor(glm::vec4 newColor);
};

#endif // XA_OBJECT_RENDER_OBJECT_H