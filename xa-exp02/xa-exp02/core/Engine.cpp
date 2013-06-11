#include "Engine.h"

bool Engine::loadScript(const std::string& scriptName) {
	int returnvalue = 0;

	lua_State *l = luaL_newstate();
	luaL_openlibs(l);

	lua_pushlightuserdata(l, this);
	lua_setglobal(l, "wtf");


	if (!luaL_dostring(l, "wtf:stuff()")) {
		lua_pcall(l, 0, 0, 0);
	} else {
		const char *error = lua_tostring(l, -1);
		std::cout << error;
	}

	//returnvalue = luaL_dofile(l, "script/test.lua");
	
	lua_close(l);
	return true;
}

void Engine::stuff() {
	int i = 0;

	i++;
}