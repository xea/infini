#ifndef XA_RENDEROBJECT_H
#define XA_RENDEROBJECT_H

#include <GL/glew.h>
#include <engine/rendering/VertexArray.h>
#include <engine/rendering/VertexBuffer.h>
#include <engine/rendering/ElementBuffer.h>
#include <engine/rendering/RenderState.h>
#include <model/Shape.h>

class RenderObject {

public:
	VertexArray vertexArray;
	VertexBuffer vertexBuffer;
	ElementBuffer elementBuffer;

	std::shared_ptr<Shape> shape;
	std::unique_ptr<RenderState> state;

	RenderObject(std::shared_ptr<Shape> shape);

	void prepare();
};


#endif // XA_RENDEROBJECT_H