#ifndef XA_WORLD_H
#define XA_WORLD_H

#include <list>
#include <thread>
#include "core\Entity.h"
#include "core\Logger.h"
#include "script\Script.h"

/**
 * Contains all the runtim
 */
class World {

private:

	static Logger *logger;

	/**
	 * References to the contained entities
	 */
	std::list<Entity *> entities;

	thread* worldThread;

protected:

	void initialize();

	void run();

public:

	/**
	 * Initializes and starts the simulation if it was in STATE_STOPPED.
	 *
	 * @returns true if it was in STATE_STOPPED otherwise false
	 */
	bool start();

	/**
	 * Pauses the simulation of the world provided that it was running already.
	 *
	 * @returns true if the world ofject was in STATE_RUNNING, otherwise false
	 */
	bool pause();

	/**
	 * Resumes the world simulation if it was paused before.
	 * It doesn't do anything if it was running already.
	 *
	 * @returns true if the world was in STATE_PAUSED, otherwise false
	 */
	bool resume();

	bool stop();

	/**
	 * Registers a new entity
	 *
	 * @returns false if the entity was already added, otherwise true
	 */
	bool add(Entity& entity);

	void attachScript(Script& script);
};

#endif // XA_WORLD_H