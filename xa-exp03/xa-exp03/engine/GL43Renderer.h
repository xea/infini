#ifndef XA_GL43RENDERER_H
#define XA_GL43RENDERER_H

#include <GL/glew.h>

#include <engine/Renderer.h>
#include <engine/rendering/RenderObject.h>
#include <engine/rendering/VertexBuffer.h>
#include <engine/rendering/ElementBuffer.h>
#include <engine/rendering/VertexArray.h>
#include <engine/rendering/ShaderProgram.h>
#include <engine/rendering/Shader.h>

#ifdef _MSC_VER

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

#endif // _MSC_VER

class GL43Renderer : public Renderer {
protected:
	std::shared_ptr<ShaderProgram> shaderProgram;

public:
	void clearScreen();

//	std::unique_ptr<RenderObject> bindShape(std::shared_ptr<Shape> shape);
	void useShaderProgram(std::shared_ptr<ShaderProgram> program);

	void drawScene(std::shared_ptr<Scene> scene);

	void drawObject(std::shared_ptr<RenderObject> object);

	void setRenderMode(RenderMode mode);
};

#endif // XA_GL43RENDERER_H