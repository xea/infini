#include "ObjectFactory.h"

Logger * ObjectFactory::logger = Logger::getLogger("ObjectFactory");

View *ObjectFactory::getView() {
	View *view = ObjectFactory::getView(View::TYPE_GLFW);

	return view;
}

View *ObjectFactory::getView(ViewType type) {
	View *view = 0;

	switch(type) {
	case View::TYPE_GLFW:
#ifdef __glfw_h_
		logger->debug("Implementation found, initializing a new GLFW View");
		view = new GLFWView();
#endif // __glfw_h_
#ifdef _glfw3_h_
		logger->debug("GLFW3 Implementation found, initializing a new GLFW3 View");
		view = new GLFWView();
#endif // _glfw3_h
		break;
	}

	return view;
}

Renderer *ObjectFactory::getRenderer() {
	Renderer *renderer = getRenderer(Renderer::TYPE_GL42);

	return renderer;
}

Renderer *ObjectFactory::getRenderer(RendererType type) {
	Renderer *renderer = 0;

	switch (type) {
	case Renderer::TYPE_GL42:
		renderer = new GL42Renderer();
		break;
	}

	return renderer;
}