#pragma once
#include "Primitive.h"
#include "../Platform.h"

class Circle : public Primitive {

	private:
		int radius;
		void DrawCircle();
		Platform* platform;

	public:
		SDL_Renderer* renderer;
		Circle();
		Circle(int _radius, float x, float y, Platform* _platform);
		void Render() override;
		~Circle();
};

