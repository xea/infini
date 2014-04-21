#ifndef XA_OBJECT_H
#define XA_OBJECT_H

#include "Entity.h"

/**
 * A representation of a physical object that has physical attributes
 * like weight, position, color, etc.
 */
class Object : public Entity {

protected:

	/**
	 * The weight of this object, measured in gramms
	 */
	double weight;

};

#endif // XA_OBJECT_H