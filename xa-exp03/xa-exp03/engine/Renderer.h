#ifndef XA_RENDERER_H
#define XA_RENDERER_H

#include <memory>
#include <model/Shape.h>
#include <engine/rendering/RenderObject.h>
#include <engine/rendering/Scene.h>
#include <engine/rendering/ShaderProgram.h>	

enum class RenderMode : unsigned int {
	Wireframe,
	Fill
};

class Renderer {

public:
	virtual void clearScreen() = 0;

	virtual void useShaderProgram(std::shared_ptr<ShaderProgram> program) = 0;

	virtual void drawScene(std::shared_ptr<Scene> scene) = 0;

	virtual void drawObject(std::shared_ptr<RenderObject> object) = 0;

	virtual void setRenderMode(RenderMode mode) = 0;
};

#endif // XA_RENDERER_H