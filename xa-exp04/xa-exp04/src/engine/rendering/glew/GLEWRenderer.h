#ifndef XA_GLEWRENDERER_H
#define XA_GLEWRENDERER_H

#include <GL/glew.h>
#include <engine/rendering/Renderer.h>
#include <engine/rendering/RenderObject.h>
#include <engine/logging/Logger.h>

#ifdef _MSC_VER

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

#endif // _MSC_VER

/**
 * Renderer implementation that relies on the cross-platform GLEW library
 */
class GLEWRenderer : public Renderer {
private:
    std::shared_ptr<Logger> logger;
protected:
    void drawObject(std::shared_ptr<RenderObject> object);
public:
    GLEWRenderer();

    void clearScreen() override;

    void setRenderMode(RenderMode mode) override;

    void drawScene(Scene& scene) override;

};

#endif // XA_GLEWRENDERER_H