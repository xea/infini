#ifndef XA_GL42RENDERER_H
#define XA_GL42RENDERER_H

#include <GL/glew.h>
#include <GL/glfw.h>

#include "Renderer.h"

/**
 * An OpenGL 4.2 implementation for the Renderer interface
 */
class GL42Renderer : public Renderer {

public:
	/**
	 * OpenGL 4.2 Major version
	 */
	static const int MAJOR_VERSION = 4;

	/**
	 * OpenGL 4.2 Minor version
	 */
	static const int MINOR_VERSION = 2;

	inline const int getMajorVersion() { return GL42Renderer::MAJOR_VERSION; }

	inline const int getMinorVersion() { return GL42Renderer::MINOR_VERSION; }

	void prepareScene();

	void prepareFrame();

	void drawScene();
};

#endif // XA_GL42RENDERER_H