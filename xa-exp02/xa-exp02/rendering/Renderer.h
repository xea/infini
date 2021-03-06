#ifndef XA_RENDERER_H
#define XA_RENDERER_H

#include <rendering/Scene.h>

typedef const int RendererType;

/**
 * Defines a skeleton of rendering functions that must be implemented by subclasses.
 */
class Renderer {

protected:

	/**
	 * No-argument constructor set to protected in order to prevent instantiation. 
	 *
	 * Use ObjectFactory's getRenderer() methods instead.
	 */
	Renderer();

public:

	/**
	 * OpenGL 4.2 renderer
	 */
	static RendererType TYPE_GL42 = 0;

	/**
	 * Returns the major version number of this implementation
	 */
	virtual const int getMajorVersion() const = 0;

	/**
	 * Returs the minor version umber of this implementation
	 */
	virtual const int getMinorVersion() const = 0;

	/**
	 * Prepares the scene by setting the clear color and stuff
	 */
	virtual void prepareScene() = 0;

	/**
	 * Prepares the frame for rendering by clearing the window and stuff
	 */
	virtual void prepareFrame() = 0;

	/**
	 * Disposes the objects and settings that were created for this scene
	 */
	virtual void destroyScene() = 0;

	/**
	 * Draw the current frame
	 */
	virtual void drawScene(Scene& scene) = 0;
};

#endif // XA_RENDERER_H