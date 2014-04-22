#ifndef XA_ENGINE_H
#define XA_ENGINE_H

#include <iostream>
#include "world\World.h"
#include "script\Script.h"
#include "ObjectFactory.h"
#include "..\rendering\View.h"
#include "..\rendering\Renderer.h"
#include <script/Director.h>

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
	 * The director that governs the screen
	 */
	Director *director;

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

	/**
	 * Sets the current director on this engine
	 */	
	void setDirector(Director& director);

};

#endif // XA_ENGINE_H