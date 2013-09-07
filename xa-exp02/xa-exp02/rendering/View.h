#ifndef XA_VIEW_H
#define XA_VIEW_H

#include "Renderer.h"

/**
 * For identifying the respective view types
 */
typedef unsigned int ViewType;

class View {

protected:

	/**
	 * No-argument constructor is set to protected in order to prevent unattended instantiation.
	 *
	 * Use ObjectFactory's getRenderer() methods instead.
	 */
	View();

public:

	/**
	 * GLFW implementation
	 */
	static const ViewType TYPE_GLFW = 0;
	
	/**
	 * Sets up a new view using the supplied Renderer object. 
	 *
	 * This method will only prepare the view, deferring the rendering task to the supplied Renderer.
	 */
	virtual bool initialize(Renderer &renderer) = 0;

	/**
	 * Closes this view making it unavailable for the clients. 
	 * This usually means closing the application window where it was visible.
	 */
	virtual bool destroy() = 0;
};

#endif // XA_VIEW_H