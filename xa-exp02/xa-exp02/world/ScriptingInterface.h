#ifndef XA_SCRIPTING_INTERFACE
#define XA_SCRIPTING_INTERFACE

#include <list>
#include <core/Entity.h>

/**
 * Provides functions for scripts via they can modify the world state
 * externally
 */
class ScriptingInterface {

public: 

	/**
	 * Add a new entity to the world
	 */
	virtual bool add(Entity& entity) = 0;

	/**
	 * Returns with a list of registered entities
	 */
	virtual std::list<Entity *> listEntities() = 0;
};

#endif // XA_SCRIPTING_INTERFACE