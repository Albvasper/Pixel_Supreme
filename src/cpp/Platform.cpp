#include "../include/Platform.h"
#include <iostream>
#include <string>

SDL_Renderer* Platform::renderer;

Platform::Platform(std::string name) {
	CSimpleIniA config;
	//config INI file path
	config.LoadFile("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\config.INI");
	
	//Window size
	width = std::stoi(config.GetValue("Resolution", "width", ""));
	height = std::stoi(config.GetValue("Resolution", "height", ""));

	//SDL window logic
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init";
		return;
	}
	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "CreateWindow";
		SDL_Quit();
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "CreateRenderer";
		SDL_Quit();
		return;
	}
}

void Platform::RenderClear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Platform::RenderPresent() {
	SDL_RenderPresent(renderer);
}

void Platform::RenderSprite(Sprite* sprite, int x, int y, float angle) {
	RenderTexture(sprite, x, y, angle);
}

void Platform::RenderTexture(Sprite* sprite, int x, int y, double a) {
	SDL_Rect srcrect;
	srcrect.x = x;
	srcrect.y = y;
	srcrect.w = sprite->GetWidth();
	srcrect.h = sprite->GetHeight();
	SDL_RenderCopyEx(renderer, sprite->GetTexture(), NULL, &srcrect, a, NULL, SDL_FLIP_NONE);
}

void Platform::CheckEvent(GameState* obj, bool (GameState::* f)(int)) {
	//New SDL event called "e"
	SDL_Event e;
	bool leftMouseButtonDown = false;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_KEYDOWN) {
			(obj->*f)(e.key.keysym.sym);
		}
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				leftMouseButtonDown = false;
				//std::cout << "arriba" << std::endl;
			}
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				leftMouseButtonDown = true;
			//	std::cout << "abajo" << std::endl;
			}
		}
	}
}

Platform::~Platform() {
}