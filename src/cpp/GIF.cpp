#include "../include/GIF.h"
#include "SDL.h"

GIF::GIF() {
}

GIF::GIF(const char* path, int _frames, short _speed) {
	frames = _frames;
	speed = _speed;
}

void GIF::LoadSpriteSheet(std::string name) {
}

GIF::~GIF() {
}
