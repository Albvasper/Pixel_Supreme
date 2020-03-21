#include "../include/Text.h"
#include <iostream>
#include <fstream> 
#include <exception>
#include <windows.h>	
#include "../include/Logging.h"

Text::Text(SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message_text, const SDL_Color& color) {
	TTF_Init();
	_text_texture = LoadFont(renderer, font_path, font_size, message_text, color);
	SDL_QueryTexture(_text_texture, nullptr, nullptr, &_text_rect.w, &_text_rect.h);
}

void Text::Display(int x, int y, SDL_Renderer* renderer) const {
	_text_rect.x = x;
	_text_rect.y = y;
	SDL_RenderCopy(renderer, _text_texture, nullptr, &_text_rect);
}

SDL_Texture* Text::LoadFont(SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message_text, const SDL_Color& color) {
	TTF_Font* font = NULL;
	try {
		font = TTF_OpenFont(font_path.c_str(), font_size);
	}
	catch (std::exception & e) {
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Warning(e.what(), "Text");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Warning(e.what(), "Texto");
		}
	}
	if (!font) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Warning("Failed to load font", "Text");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Warning("No se pudo cargar la tipografia", "Texto");
		}
	}
	auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);
	if (!text_surface) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Warning("Failed to create text surface", "Text");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Warning("No se pudo crear una superficie.", "Texto");
		}
	}
	auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (!text_texture) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Warning("Failed to create text texture", "Text");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Warning("No se pudo crear textura.", "Texto");
		}
	}

	TTF_CloseFont(font);
	font = NULL;
	SDL_FreeSurface(text_surface);
	return text_texture;
}

Text::~Text() {
}