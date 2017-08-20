#ifndef XA_ENGINE_H
#define XA_ENGINE_H

#include <memory>

#include <engine/Config.h>
#include <engine/logging/Logger.h>
#include <engine/rendering/View.h>
#include <engine/rendering/Renderer.h>

#include <util/Result.h>

// TODO find a better place for these
#include <engine/rendering/Director.h>
#include <engine/rendering/gl/ShaderProgram.h>
#include <engine/rendering/gl/Uniform.h>

// TODO remove these two includes once initialisation has been designed properly

// note: GLEW has to come before GLFW otherwise it'll throw compile-time errors
#include <engine/rendering/glew/GLEWRenderer.h>
#include <engine/rendering/glfw/GLFWView.h>

#include <world/World.h>

using namespace std;

class Engine {
private:
    unique_ptr<View> view;
    unique_ptr<Renderer> renderer;
    shared_ptr<Logger> logger;

protected:
public:
    Engine();

    void start();
};

#endif // XA_ENGINE_H