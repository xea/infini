#include "GLFWView.h"

GLFWView::GLFWView() {
	initialized = false;
	logger = Logger::getLogger("GLFWView");
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
        printf("%d %d\n", majorVersion, minorVersion);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindow = glfwCreateWindow(1024, 768, "xa-exp02", NULL, NULL);

		if (!glfwWindow) {
			glfwTerminate();
		} else {
			success = true;
			glfwMakeContextCurrent(glfwWindow);
		}
	}

	return success;
}

bool GLFWView::initializeGLEW() {
	bool success = false;

	glewExperimental = GL_TRUE;
	GLenum result = glewInit();

	if (result == GLEW_OK) {
		success = true;
	} else {
		//glewGetErrorString(result);
		const char *errorMessage = (const char *) glewGetErrorString(result);
		std::string message(errorMessage);
		
		logger->error(message);
	}

	return success;
}

bool GLFWView::destroyGLFW() {
	bool success = false;

	if (initialized) {
		glfwDestroyWindow(glfwWindow);
		glfwTerminate();

		success = true;
	}

	return success;
}

bool GLFWView::destroyGLEW() {
	return true;
}

void GLFWView::swapBuffers() {
	glfwSwapBuffers(glfwWindow);
	glfwPollEvents();
}

bool GLFWView::isClosing() {
	const int keypress = glfwGetKey(glfwWindow, GLFW_KEY_ESCAPE);

	bool shouldClose = false;

	if (keypress == GLFW_PRESS) {
		glfwWindowShouldClose(glfwWindow);
		shouldClose = true;
	} 

	return shouldClose;
}
