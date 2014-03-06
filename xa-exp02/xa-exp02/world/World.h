#ifndef XA_WORLD_H
#define XA_WORLD_H

#include <list>
#include "core\Entity.h"

/**
 * Container of all runtime entities.
 */
class World {

private:

	/**
	 * References to the contained entities
	 */
	std::list<Entity&> entities;

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
};

#endif // XA_WORLD_H