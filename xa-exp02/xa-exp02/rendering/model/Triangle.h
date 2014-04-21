#ifndef XA_OBJECT_TRIANGLE_H
#define XA_OBJECT_TRIANGLE_H

#include <rendering\RenderObject.h>

/**
 * Describes a simple triangle
 */
class Triangle : public RenderObject {

private:

	static float objectVertices[];

	static float vertexColors[];

public:

	Triangle();

	~Triangle();

	float *vertices();

	int verticesCount();

	float *colors();

	int colorsCount();
};

#endif // XA_OBJECT_TRIANGLE_H