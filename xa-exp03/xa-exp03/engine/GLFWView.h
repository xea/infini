#ifndef XA_GLFWVIEW_H
#define XA_GLFWVIEW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <tuple>

#include <engine/View.h>
#include <engine/Renderer.h>

class GLFWView : public View {

private:
	GLFWwindow *window;

	std::tuple<int, int> resolution;

	void updateResolution();

protected:

	ViewResult initialiseGLFW();
	ViewResult initialiseGLEW();
	void terminate();

public:
	std::tuple<int, int> getResolution();

	ViewResult start();

	void stop();

	bool shouldClose();

	void swapBuffers();
};

#endif // XA_GLFWVIEW