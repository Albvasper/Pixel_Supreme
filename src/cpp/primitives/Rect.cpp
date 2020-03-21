#include "../../include/primitives/Rect.h"

Rect::Rect() {
}

Rect::Rect(float x, float y, int _width, int _height, Platform* _platform) {
	platform = _platform;
	position.first = x;
	position.second = y;
	width = _width;
	height = _height;
	rect = {
		(int)position.first - width / 2, (int)position.second - height / 2, width, height
	};
}

void Rect::Render() {
	SDL_SetRenderDrawColor(platform->renderer, 0xff, 0x00, 0xff, 0xff);
	SDL_RenderFillRect(platform->renderer, &rect);
}

Rect::~Rect() {
}
