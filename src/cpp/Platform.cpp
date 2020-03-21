#include "../include/Platform.h"
#include "../include/Logging.h"
#include <string>

SDL_Renderer* Platform::renderer;

Platform::Platform(std::string name) {
	CSimpleIniA config;
	if (Logging::Get()->CheckLang() == "ENG") {
		Logging::Get()->Info("Loading Config file...", "Platform");
	}
	else if (Logging::Get()->CheckLang() == "ESP") {
		Logging::Get()->Info("Cargando archivo de configuracion...", "Plataforma");
	}
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
			if (Logging::Get()->CheckLang() == "ENG") {
				Logging::Get()->Info("Config file loaded successfully.", "Platform");
				Logging::Get()->Info("Config file read successfully.", "Platform");
			}
			else if (Logging::Get()->CheckLang() == "ESP") {
				Logging::Get()->Info("Configuracion cargada con exito.", "Plataforma");
				Logging::Get()->Info("Configuracion leia con exito.", "Plataforma");
			}
		}
	}
	catch (...) {
		//config.INI file was missing or resolution parameters were not found
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Error("Config file error.", "Platform");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Error("Error de configuracion", "Plataforma");
		}
		Logging::Get()->Save();
		exit(1);
	}
	try {
		memory = std::stoi(config.GetValue("Memory", "MB", ""));
		stackAllocator = new StackAllocator(1024 * 1024 * memory);
		if (memory == NULL) {
			throw std::exception("ERROR");
		}
		else {
			if (Logging::Get()->CheckLang() == "ENG") {
				Logging::Get()->Info("Memory assigned successfully.", "Platform");
			}
			else if (Logging::Get()->CheckLang() == "ESP") {
				Logging::Get()->Info("Memoria asignada con exito.", "Plataforma");
			}
		}
	}
	catch (...) {
		//config.INI file was missing or memory parameters were not found
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Error("Config file error.", "Platform");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Error("Error de configuracion", "Plataforma");
		}
		Logging::Get()->Save();
		exit(1);
	}
	if (Logging::Get()->CheckLang() == "ENG") {
		Logging::Get()->Info("Initializing SDL...", "Platform");
	}
	else if (Logging::Get()->CheckLang() == "ESP") {
		Logging::Get()->Info("Iniciando SDL...", "Plataforma");
	}
	//SDL window logic
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Error("SDL failed to initialize.", "SDL/Platform");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Error("SDL no se pudo iniciar.", "SDL/Plataforma");
		}
		return;
	}
	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Error("Failed to create window.", "SDL/Platform");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Error("No se pudo crear ventana.", "SDL/Plataforma");
		}
		SDL_Quit();
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Error("Failed to create renderer.", "SDL/Platform");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Error("No se pudo crear renderizador.", "SDL/Plataforma");
		}
		SDL_Quit();
		return;
	}
	if (Logging::Get()->CheckLang() == "ENG") {
		Logging::Get()->Info("SDL initialized successfully.", "SDL/Platform");
	}
	else if (Logging::Get()->CheckLang() == "ESP") {
		Logging::Get()->Info("SDL fue iniciado con exito.", "SDL/Plataforma");
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