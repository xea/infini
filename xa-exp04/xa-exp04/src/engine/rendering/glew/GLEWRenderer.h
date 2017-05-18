#ifndef XA_GLEWRENDERER_H
#define XA_GLEWRENDERER_H

#include <GL/glew.h>
#include <engine/rendering/Renderer.h>

#ifdef _MSC_VER

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

#endif // _MSC_VER

/**
 * Renderer implementation that relies on the cross-platform GLEW library
 */
class GLEWRenderer : public Renderer {
protected:
public:
    GLEWRenderer();

    void clearScreen() override;

    void setRenderMode(RenderMode mode) override;

    void drawScene(Scene& scene) override;
};

#endif // XA_GLEWRENDERER_H