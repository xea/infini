#ifndef XA_ENGINE_H
#define XA_ENGINE_H

#include <iostream>
#include <lua\lua.hpp>

class Engine {

public:

	void stuff();

	bool loadScript(const std::string& scriptName);
};

#endif // XA_ENGINE_H