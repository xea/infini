#ifndef XA_SQUARE_H
#define XA_SQUARE_H

#include "RenderObject.h"

class Square : public RenderObject {
	
private:

	static float objectVertices[];

	static float vertexColors[];

public:

	Square();

	~Square();

	float *vertices();

	int verticesCount();

	float *colors();

	int colorsCount();
};

#endif // XA_SQUARE_H