#include "GLFWView.h"

ViewResult GLFWView::start() {
	ViewResult status = initialiseGLFW();

	if (status == ViewResult::NoError) {
		status = initialiseGLEW();
	}

	return ViewResult::NoError;
}

void GLFWView::stop() {
	terminate();
}

ViewResult GLFWView::initialiseGLFW() {
	if (!glfwInit()) {
		return ViewResult::InitialisationFailed;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(640, 480, "Window title", NULL, NULL);

	ViewResult result = ViewResult::NoError;

	if (!window) {
		result = ViewResult::WindowCreationError;
		terminate();
	} else {
		glfwMakeContextCurrent(window);
	}

	return result;
}

ViewResult GLFWView::initialiseGLEW() {
	GLenum initResult = glewInit();

	if (GLEW_OK != initResult) {
		return ViewResult::InitialisationFailed;
	}

	return ViewResult::NoError;
}

void GLFWView::terminate() {
	glfwTerminate();
}

bool GLFWView::shouldClose() {
	bool shouldClose = false;

	if (glfwWindowShouldClose(window)) {
		shouldClose = true;
	}

	return shouldClose;
}

void GLFWView::swapBuffers() {
	glfwPollEvents();
	glfwSwapBuffers(window);
}

std::tuple<int, int> GLFWView::getResolution() {
	return resolution;
}

void GLFWView::updateResolution() {
	int width, height;

	glfwGetFramebufferSize(window, &width, &height);

	resolution = std::make_tuple(width, height);
}

void GLFWView::setRenderer(std::unique_ptr<Renderer> renderer) {
	this->renderer = std::move(renderer);
}