#ifndef XA_OBJECTFACTORY_H
#define XA_OBJECTFACTORY_H

#include <core/Logger.h>
#include <rendering/View.h>
#include <rendering/GLFWView.h>
#include <rendering/Renderer.h>
#include <rendering/GL42Renderer.h>

/**
 * It's reponsibility is to create basic classes necessary to run a demo
 */
class ObjectFactory {

private:

	/**
	 * Logger instance for logging (wow)
	 */
	static Logger *logger;

	/**
	 * No-argument constructor is set to private in order to prevent instantiation
	 */
	ObjectFactory();

public:

	/**
	 * Creates and returns a new View object.
	 * 
	 * The actual implementation is chosen based on the running system
	 * Returns a null-pointer if the instance could not be created.
	 */
	static View *getView();

	/**
	 * Creates and returns a new instance of the specifed type of View
	 *
	 * Returns a null-pointer if the instance could not be created.
	 */
	static View *getView(ViewType type);

	/**
	 * Creates and returns a new Renderer object.
	 * 
	 * The actual impelmentation is chosen based on the best matching profile.
	 * Returns a null-pointer if the instance could not be created.
	 */
	static Renderer *getRenderer();

	/**
	 * Creates and returns a new instance of the specified type of renderer.
	 *
	 * Returns a null-pointer if the instance could not be created.
	 */
	static Renderer *getRenderer(RendererType type);

};

#endif // XA_OBJECTFACTORY_H