#ifndef XA_OBJECT_TRIANGLE_H
#define XA_OBJECT_TRIANGLE_H

#include "RenderObject.h"

/**
 * Describes a simple triangle
 */
class Triangle : public RenderObject {

private:

	static float objectVertices[];

public:

	Triangle();

	~Triangle();

	float *vertices();

	int verticesCount();
};

#endif // XA_OBJECT_TRIANGLE_H