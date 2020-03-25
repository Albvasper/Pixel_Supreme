#pragma once
#include "GameObject.h"
#include "SDL.h"
#include <iostream>
#include <string>
#include "Lua.h"

class Sprite  {

private:

	SDL_Texture* sprite;
	std::string name;
	unsigned short width;
	unsigned short height;

public:
	Sprite();
	//int Lua_HostFunction(lua_State* L);
	void LoadSprite(std::string name);
	SDL_Texture* GetTexture();
	int GetWidth();
	int GetHeight();
	~Sprite();
};

