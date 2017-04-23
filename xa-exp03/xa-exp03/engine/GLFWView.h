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

	std::unique_ptr<Renderer> renderer;

	std::tuple<int, int> resolution;

	void updateResolution();

protected:

	ViewResult initialiseGLFW();
	ViewResult initialiseGLEW();
	void terminate();

public:
	std::tuple<int, int> getResolution();

	void setRenderer(std::unique_ptr<Renderer> renderer);

	ViewResult start();

	void stop();

	void clearScreen();

	bool shouldClose();

	void swapBuffers();
};

#endif // XA_GLFWVIEW