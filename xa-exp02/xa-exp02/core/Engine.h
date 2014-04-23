#ifndef XA_ENGINE_H
#define XA_ENGINE_H

#include <chrono>
#include <iostream>

#include <core/ObjectFactory.h>
#include <rendering/View.h>
#include <rendering/Renderer.h>
#include <script/Director.h>
#include <script/Script.h>
#include <world/World.h>

/**
 * It is responsible for displaying visual objects on the screen, handling
 * user inputs and dispatching user interactions.
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

	/**
	 * Initalizing constructor
	 */
	Engine();

	/**
	 * Starts the graphics engine that ususally opens a new window and 
	 * starts rendering the scene based on the associated World object
	 */
	void start();

	/**
	 * Stops the engine and closes the application window if it was 
	 * already open. 
	 *
	 * Note that it doesn't terminate all threads.
	 */
	void stop();

	/**
	 * Sets the current director on this engine. 
	 */	
	void setDirector(Director& director);

};

#endif // XA_ENGINE_H