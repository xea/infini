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

	virtual bool initialize(Renderer *renderer) = 0;

	virtual bool destroy() = 0;
};

#endif // XA_VIEW_H