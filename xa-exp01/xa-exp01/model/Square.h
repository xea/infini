#ifndef XA_SQUARE_H
#define XA_SQUARE_H

#include "RenderObject.h"

class Square : public RenderObject {
	
private:

	static float objectVertices[];

public:

	Square();

	~Square();

	float *vertices();

	int verticesCount();

};

#endif // XA_SQUARE_H