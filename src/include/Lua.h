#pragma once

extern "C" {
	#include "../../deps/LUA/include/lua.h" 
	#include "../../deps/LUA/include/lauxlib.h" 
	#include "../../deps/LUA/include/lualib.h" 
}
#ifdef _WIN32
#pragma comment(lib, "../../deps/LUA/liblua53.a")
#endif // _WIN32