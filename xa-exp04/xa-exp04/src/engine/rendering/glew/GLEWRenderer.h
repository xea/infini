#ifndef XA_GLEWRENDERER_H
#define XA_GLEWRENDERER_H

#include <GL/glew.h>
#include <engine/rendering/Renderer.h>
#include <engine/rendering/RenderObject.h>
#include <engine/rendering/gl/Uniform.h>
#include <engine/logging/Logger.h>
#include <memory>
#include <chrono>
#include <thread>
#include <tuple>

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
    UniformLocations uniformLocations;
    std::shared_ptr<ShaderProgram> shaderProgram;
    std::shared_ptr<ViewState> viewState;
    std::shared_ptr<ProjectionState> projectionState;
    std::chrono::system_clock::time_point lastFrame;
    unsigned int frameRateLimit;
    unsigned int frameMs;
    std::tuple<int, int> resolution;
protected:
    void drawObject(std::shared_ptr<RenderObject> object);
public:
    GLEWRenderer(std::tuple<int, int> resolution);

    void clearScreen() override;

    void setRenderMode(RenderMode mode) override;

    void drawScene(std::shared_ptr<Scene> scene) override;

    void useShaderProgram(std::shared_ptr<ShaderProgram> shaderProgram) override;

    void limitFrameRate(unsigned int limit);

    void applyFrameRateLimit();

    void updateView(std::shared_ptr<ViewState> view) override;
};

#endif // XA_GLEWRENDERER_H