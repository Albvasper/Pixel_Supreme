#pragma once
#include <string>
#include "SDL.h"
#include "GameState.h"
#include <iostream>
#include "Sprite.h"
#include "SimpleIni.h"

class GameState;

class Platform {

	private:
		int width;														//Width of the window 
		int height;														//Height of the window
		SDL_Window* window;												//Pointer to SDL window

	public:
		static SDL_Renderer* renderer;									//Pointer to the SDL renderer
		Platform(std::string name);										//Constructor that recives a name for the window
		void RenderClear();												//Method that clears the renderer
		void RenderSprite(Sprite* sprite, int x, int y, float angle);	//Method that renders an image
		void RenderTexture(Sprite* sprite, int x, int y, double a);
		void RenderPresent();											//Method that updates the screen with any rendering performed
		void CheckEvent(GameState* obj, bool (GameState::* f)(int));	//Method that always checks the events that are happening
		~Platform();													//Destructor
};