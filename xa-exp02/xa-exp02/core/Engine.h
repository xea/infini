#ifndef XA_ENGINE_H
#define XA_ENGINE_H

#include <iostream>
#include "world\World.h"
#include "script\Script.h"

/**
 * 
 */
class Engine {

public:

	Engine();

	void start();

	void stop();

	bool loadScript(Script& script);
};

#endif // XA_ENGINE_H