#ifndef XA_ENGINE_H
#define XA_ENGINE_H

#include <engine/View.h>
#include <engine/GLFWView.h>
#include <engine/GL43Renderer.h>
#include <engine/rendering/Scene.h>
#include <memory>

class Engine {

private:
	std::unique_ptr<View> view;
	std::unique_ptr<Renderer> renderer;

public:

	Engine();
	void start();
	void stop();
};

#endif // XA_ENGINE_H