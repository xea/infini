#ifndef XA_ENGINE_H
#define XA_ENGINE_H

#include <iostream>
#include "world\World.h"
#include "script\Script.h"
#include "ObjectFactory.h"
#include "..\rendering\View.h"
#include "..\rendering\Renderer.h"

/**
 * 
 */
class Engine {

private:

	/**
	 * The view implementation that handles creating window'n'stuff.
	 */
	View *view;

	/**
	 * Renderer implementation 
	 */
	Renderer *renderer;

	/**
	 * Indicates if the engine can continue running, i.e. the user didn't
	 * stopped the program explicitly.
	 */
	bool mayContinue();

public:

	Engine();

	/**
	 * Starts the graphics engine that ususally opens a new window and 
	 * starts rendering the scene based on the associated World object
	 */
	void start();

	void stop();

};

#endif // XA_ENGINE_H