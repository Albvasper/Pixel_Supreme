#pragma once
#include "GameObject.h"
#include "SDL.h"
#include <iostream>
#include <string>

class Sprite : public GameObject {

private:
	SDL_Texture* sprite;
	std::string name;
	unsigned short width;
	unsigned short height;

public:
	Sprite();
	void LoadSprite(std::string name);
	SDL_Texture* GetTexture();
	int GetWidth();
	int GetHeight();
	~Sprite();
};

