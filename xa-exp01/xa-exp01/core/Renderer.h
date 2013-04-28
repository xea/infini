#ifndef XA_RENDERER_H
#define XA_RENDERER_H

typedef const int RendererType;

/**
 * Defines a skeleton of rendering functions that must be implemented by subclasses.
 */
class Renderer {

protected:

	/**
	 * No-argument constructor set to private in order to prevent instantiation. 
	 *
	 * Use ObjectFactory's getRenderer() methods instead.
	 */
	Renderer();

public:

	/**
	 * OpenGL 4.2 type renderer
	 */
	static RendererType TYPE_GL42 = 0;

	/**
	 * Returns the major version number of this implementation
	 */
	virtual const int getMajorVersion() = 0;

	/**
	 * Returs the minor version umber of this implementation
	 */
	virtual const int getMinorVersion() = 0;
};

#endif // XA_RENDERER_H