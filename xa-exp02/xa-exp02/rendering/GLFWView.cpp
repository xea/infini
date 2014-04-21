#include "GLFWView.h"

GLFWView::GLFWView() {
	initialized = false;
}

bool GLFWView::initialize(Renderer& renderer) {

	if (!initialized) {
		bool status = true;

		this->renderer = &renderer;

		status = status && initializeGLFW();
		status = status && initializeGLEW();

		initialized = status;
	}

	return initialized;
}

bool GLFWView::destroy() {

	bool status = true;

	status = status && destroyGLEW();
	status = status && destroyGLFW();
	
	return !initialized;
}

bool GLFWView::initializeGLFW() {
	bool success = false; 

	if (glfwInit()) {

		int majorVersion = renderer->getMajorVersion();
		int minorVersion = renderer->getMinorVersion();

		glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, majorVersion);
		glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, minorVersion);
		glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if(glfwOpenWindow( 1024, 768, 0,0,0,0, 32,0, GLFW_WINDOW )) {
			success = true;
		} else {
			glfwTerminate();
		}
	}

	return success;
}

bool GLFWView::initializeGLEW() {
	bool success = false;

	glewExperimental = GL_TRUE;
	if (glewInit() == GLEW_OK) {
		success = true;
	}

	return success;
}

bool GLFWView::destroyGLFW() {
	bool success = false;

	if (initialized) {
		glfwCloseWindow();

		success = true;
	}

	return success;
}

bool GLFWView::destroyGLEW() {
	return true;
}