#ifndef XA_RENDERER_H
#define XA_RENDERER_H

#include <engine/rendering/Scene.h>
#include <engine/rendering/gl/ShaderProgram.h>
#include <engine/rendering/gl/Uniform.h>
#include <memory>

/**
 * Items of RenderMode represent various ways the rendering engine is capable of working in.
 */
enum class RenderMode : unsigned int {
    Wireframe,
    Fill
};

/**
 * Renderer instances are responsible for translating drawing requests to implementation-specific 
 * (eg. OpenGL) calls
 */
class Renderer {

public:

    /**
     * Clear the current screen using the defined clear colour.
     */
    virtual void clearScreen() = 0;

    /**
     * Select which render mode the next frame should be rendered in.
     */
    virtual void setRenderMode(RenderMode mode) = 0;

    virtual void useShaderProgram(std::shared_ptr<ShaderProgram> shaderProgram) = 0;

    /**
     * Render a whole scene onto the selected target view along with all the
     * render objects the scene contains
     */
    virtual void drawScene(std::shared_ptr<Scene> scene) = 0;

    virtual void updateView(std::shared_ptr<ViewState> view) = 0;

	virtual void limitFrameRate(float limit) = 0;

};

#endif // XA_RENDERER_H