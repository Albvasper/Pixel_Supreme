#include "../../include/primitives/Circle.h"
#include "../../include/Logging.h"

Circle::Circle() {
}

Circle::Circle(int _radius, float x, float y, Platform* _platform) {
	platform = _platform;
	radius = _radius;
	position.first = x;
	position.second = y;
	renderer = platform->renderer;
}

void Circle::DrawCircle() {
	if (radius >= 0) {
		int x = 0;
		int y = 0;
		int p;
		x = 0;
		y = radius;
		p = (5 / 4) - radius;
		for (int i = 0; x <= y; i++) {
			if (p <= 0) {
				x = x + 1;
				y = y;
				p = p + 2 * x + 3;
			}
			else if (p > 0) {
				x = x + 1;
				y = y - 1;
				p = 2 * x - 2 * y + 5 + p;
			}
			SDL_RenderDrawPoint(renderer, x + position.first, y + position.second);
			SDL_RenderDrawPoint(renderer, x + position.first, -y + position.second);
			SDL_RenderDrawPoint(renderer, -x + position.first, y + position.second);
			SDL_RenderDrawPoint(renderer, -x + position.first, -y + position.second);
			SDL_RenderDrawPoint(renderer, y + position.first, x + position.second);
			SDL_RenderDrawPoint(renderer, y + position.first, -x + position.second);
			SDL_RenderDrawPoint(renderer, -y + position.first, x + position.second);
			SDL_RenderDrawPoint(renderer, -y + position.first, -x + position.second);
		}
	}
	else {
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Warning("Circle radius needs to be 0 or above.", "Primitive");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Warning("El radio del circulo tiene que ser mayor a 0", "Primitiva");
		}
	}
}

void Circle::Render() {
	SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0xf0, 0xff);
	DrawCircle();
}

Circle::~Circle() {
}
