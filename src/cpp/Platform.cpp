#include "../include/Platform.h"
#include "../include/Logging.h"
#include <string>

SDL_Renderer* Platform::renderer;

Platform::Platform(std::string name) {
	CSimpleIniA config;
	Logging::Get()->Info("Loading Config file...", "Platform");
	//Try reading config.INI file
	try {
		//config INI file path
		config.LoadFile("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\doc\\config.INI");
		//Window size
		width = std::stoi(config.GetValue("Resolution", "width", ""));
		height = std::stoi(config.GetValue("Resolution", "height", ""));
		if (width == NULL || height == NULL) {
			throw std::exception("ERROR");
		}
		else {
			Logging::Get()->Info("Config file loaded successfully.", "Platform");
			Logging::Get()->Info("Config file read successfully.","Platform");
		}
	}
	catch (...) {
		//config.INI file was missing or resolution parameters were not found
		Logging::Get()->Error("Config file error.", "Platform");
		Logging::Get()->Save();
		exit(1);
	}

	Logging::Get()->Info("Initializing SDL...", "Platform");
	//SDL window logic
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		Logging::Get()->Error("SDL failed to initialize.","SDL/Platform");
		return;
	}
	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		Logging::Get()->Error("Failed to create window.","SDL/Platform");
		SDL_Quit();
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		Logging::Get()->Error("Failed to create renderer.","SDL/Platform");
		SDL_Quit();
		return;
	}
	Logging::Get()->Info("SDL initialized successfully.", "SDL/Platform");
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