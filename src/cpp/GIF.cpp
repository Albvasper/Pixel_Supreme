#include "../include/GIF.h"
#include "SDL.h"

GIF::GIF(const char* path, int _frames, short _speed) {
	frames = _frames;
	speed = _speed;
}

GIF::~GIF() {
}
