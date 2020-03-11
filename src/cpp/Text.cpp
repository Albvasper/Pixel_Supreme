#include "../include/Text.h"
#include <iostream>
#include <fstream> 
#include <exception>
#include <windows.h>	

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
		std::cout << e.what() << '\n';
	}
	if (!font) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
		std::cout << "failed to load font" << std::endl;
	}
	auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);
	if (!text_surface) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
		std::cout << "failed to create text surface" << std::endl;
	}
	auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (!text_texture) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
		std::cout << "Failed to create text texture" << std::endl;;
	}

	TTF_CloseFont(font);
	font = NULL;
	SDL_FreeSurface(text_surface);
	return text_texture;
}

Text::~Text() {
}