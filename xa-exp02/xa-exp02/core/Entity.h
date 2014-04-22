#ifndef XA_ENTITY_H
#define XA_ENTITY_H

#include <rendering/RenderObject.h>

/**
 * A representation of an arbitrary entity in the world. It is not necessary
 * to be a physical thing. An entity could be something abstract as well.
 */
class Entity {

public:

	/**
	 * Returns the renderable presentation (the model) of this entity
	 */
	virtual RenderObject& renderObject() = 0;
};

#endif // XA_ENTITY_H