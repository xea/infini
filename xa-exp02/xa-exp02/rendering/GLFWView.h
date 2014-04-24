#ifndef XA_GLFWVIEW_H
#define XA_GLFWVIEW_H

#include <GL/glew.h>
#include <GL/glfw3.h>

#include <core/Logger.h>
#include <rendering/View.h>

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

/**
 * The GLFW implementation of the base View class.
 * 
 * It uses the GLFW library for creating a GUI window.
 */
class GLFWView : public View {

private:

	/**
	 * Indicates if this view has been properly initialized or not
	 */
	bool initialized;

	/**
	 * A pointer to the renderer to be used to render the actual scene
	 */
	Renderer *renderer;

	Logger *logger;

protected:

	/**
	 * Initializes the GLFW subsystem
	 */
	bool initializeGLFW();

	/**
	 * Initializes the GLEW subsystem
	 */
	bool initializeGLEW();

	/**
	 * Shuts the GLFW subsystem down
	 */
	bool destroyGLFW();

	/**
	 * Shuts the GLEW subsystem down
	 */
	bool destroyGLEW();

	/**
	 * Pointer to the GLFW window
	 */
	GLFWwindow *glfwWindow;

public:

	GLFWView();

	/**
	 * Initializes a new View with the specified Renderer
	 */
	bool initialize(Renderer& renderer);

	/**
	 * Shuts down and destroys this View object
	 */
	bool destroy();

	void swapBuffers();

	bool isClosing();

};

#endif // XA_GLFWVIEW_H