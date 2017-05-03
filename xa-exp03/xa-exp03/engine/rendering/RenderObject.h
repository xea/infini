#ifndef XA_RENDEROBJECT_H
#define XA_RENDEROBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <engine/rendering/VertexArray.h>
#include <engine/rendering/VertexBuffer.h>
#include <engine/rendering/ElementBuffer.h>
#include <model/Shape.h>
#include <memory>

class RenderObject {
private:
	glm::mat4 transform;

public:
	VertexArray vertexArray;
	VertexBuffer vertexBuffer;
	ElementBuffer elementBuffer;

	std::shared_ptr<Shape> shape;

	RenderObject(std::shared_ptr<Shape> shape);

	void prepare();

	std::shared_ptr<glm::mat4> getTransform();

};


#endif // XA_RENDEROBJECT_H