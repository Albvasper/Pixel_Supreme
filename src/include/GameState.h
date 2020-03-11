#pragma once
#include "Platform.h"

class Platform;
class GameStateManager;

class GameState {

	public:
		virtual void Init(Platform* platform, GameStateManager* manager) = 0;		//Method that initializes the game state 
		virtual void Draw() = 0;													//Method that draws on screen
		virtual bool Input(int keyInput) = 0;										//Methodthat recives key inputs
		virtual void Update() = 0;													//Update method
		virtual void Close() = 0;													//Close method
};