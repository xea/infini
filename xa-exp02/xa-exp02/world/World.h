#ifndef XA_WORLD_H
#define XA_WORLD_H

#include <list>
#include <thread>
#include "core\Entity.h"
#include "core\Logger.h"

/**
 * Container of all runtime entities.
 */
class World {

private:

	/**
	 * References to the contained entities
	 */
	std::list<Entity *> entities;

	static Logger *logger;

protected:

	void initialize();

public:

	/**
	 * Initializes and starts the simulation if it was in STATE_STOPPED.
	 *
	 * @returns true if it was in STATE_STOPPED otherwise false
	 */
	bool start();

	bool pause();

	bool resume();

	bool stop();

	/**
	 * Registers a new entity
	 *
	 * @returns false if the entity was already added, otherwise true
	 */
	bool add(Entity& entity);
};

#endif // XA_WORLD_H