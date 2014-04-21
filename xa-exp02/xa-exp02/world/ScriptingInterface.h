#ifndef XA_SCRIPTING_INTERFACE
#define XA_SCRIPTING_INTERFACE

#include "../core/Entity.h"

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

};

#endif // XA_SCRIPTING_INTERFACE