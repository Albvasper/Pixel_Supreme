#pragma once
#include "Primitive.h"
#include "../Platform.h"

class Rect : public Primitive {

	private:
		int width;
		int height;
		Platform* platform;

	public:
		SDL_Rect rect;
		SDL_Surface* surface;
		Rect();
		Rect(float x, float y, int _width, int _height, Platform* _platform);
		void Render() override;
		~Rect();

};

