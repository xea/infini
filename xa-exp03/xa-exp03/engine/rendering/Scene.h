#ifndef XA_SCENE_H
#define XA_SCENE_H

#include <engine/rendering/Shader.h>
#include <engine/rendering/ShaderProgram.h>
#include <engine/rendering/ShaderSource.h>
#include <engine/rendering/VertexArray.h>
#include <engine/rendering/VertexBuffer.h>

class Scene {
private:
	VertexArray vertexArray;
	VertexBuffer vertexBuffer;
	ShaderProgram shaderProgram;

public:

	void init();

	void preDraw();

	void draw();

	void postDraw();
};

#endif // XA_SCENE_H