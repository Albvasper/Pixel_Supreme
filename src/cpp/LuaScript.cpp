#include "../include/LuaScript.h"
#include "../include/Logging.h"
#include <iostream>

LuaScript::LuaScript(const std::string& filename) {
    L = luaL_newstate();
    if (luaL_loadfile(L, filename.c_str()) || lua_pcall(L, 0, 0, 0)) {
        if (Logging::Get()->CheckLang() == "ENG") {
            Logging::Get()->Warning("Script not loaded.", filename);
        }
        else if (Logging::Get()->CheckLang() == "ESP") {
            Logging::Get()->Warning("No se pudo cargar script", filename);
        }
        L = 0;
    }
}

void LuaScript::printError(const std::string& variableName, const std::string& reason) {
    std::cout << "Error: can't get [" << variableName << "]. " << reason << std::endl;
    if (Logging::Get()->CheckLang() == "ENG") {
        Logging::Get()->Warning("Can't get [" + variableName + "]. " + reason, "LuaScript");
    }
    else if (Logging::Get()->CheckLang() == "ESP") {
        Logging::Get()->Warning("No se pudo acceder a [" + variableName + "]. " + reason, "LuaScript");
    }
}

LuaScript::~LuaScript() {
    if (L) lua_close(L);
}