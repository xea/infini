#ifndef XA_CUBE_H
#define XA_CUBE_H

#include <rendering/RenderObject.h>

class Cube : public RenderObject {

private:

	static float objectVertices[];

	static float vertexColors[];

public:

	Cube();

	~Cube();

	float *vertices();

	int verticesCount();

	float *colors();

	int colorsCount();

	GLenum drawMode();

};

#endif // XA_CUBE_H