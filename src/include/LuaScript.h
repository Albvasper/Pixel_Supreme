#include <string>
#include <vector>
#include "../include/Lua.h"
#include <string>

class LuaScript {
    private:
        lua_State* L;
        int level;
        bool CheckLua(lua_State* L, int r);

    public:
        float x;
        float y;
        LuaScript();
        void RunScript();
        ~LuaScript();
};