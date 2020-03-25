#include "../include/LuaScript.h"
#include "../include/Logging.h"
#include <iostream>

LuaScript::LuaScript() {
}

bool LuaScript::CheckLua(lua_State*L, int r) {
    if (r != LUA_OK) {
        std::string errormsg = lua_tostring(L, -1);
        Logging::Get()->Error(errormsg, "LuaScript");
        return false;
    }
    return true;
}

void LuaScript::RunScript() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    if (CheckLua(L, luaL_dofile(L, "C:\\Users\\alber\\Desktop\\Pixel_Supreme\\src\\LUA\\Scripts\\Player.lua"))) {
        lua_getglobal(L, "x");
        if (lua_isnumber(L, -1)) {
            x = (float)lua_tonumber(L, -1);
        }
        lua_getglobal(L, "y");
        if (lua_isnumber(L, -1)) {
            y = (float)lua_tonumber(L, -1);
        }
    }
    lua_close(L);
}

LuaScript::~LuaScript() {
}
