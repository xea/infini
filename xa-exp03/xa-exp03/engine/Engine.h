#ifndef XA_ENGINE_H
#define XA_ENGINE_H

#include <engine/View.h>
#include <engine/GLFWView.h>
#include <engine/GL43Renderer.h>
#include <engine/rendering/Scene.h>

class Engine {

private:
	View *view;

public:

	Engine();
	void start();
	void stop();
};

#endif // XA_ENGINE_H