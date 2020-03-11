#pragma once
#include "GameObject.h"
#include <string>

class GIF : public GameObject {
	private:
		short speed;
		int frames;

	public:
		GIF();
		GIF(const char* path, int frames, short _speed);
		void LoadSpriteSheet(std::string name);
		~GIF();
};

