#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Sprite.h"
#include "LuaScript.h"
#include <map>

class Game : public GameState {

	private:
		Platform* platform;														//Pointer to platform
		Sprite* background;														//Background image for the state
		GameStateManager* manager;												//Pointer to the manager
		std::map<int, GameObject> goHashMap;									//ID hash map
		LuaScript* lua;
		Sprite* sprite;

	public:
		Game();																	//Constructor
		void Init(Platform* platform, GameStateManager* manager) override;		//Method that initializes the state game
		void Draw() override;													//Method that draws on screen
		bool Input(int keyInput) override;										//Method that recives key inputs
		void Update() override;													//Method that updates the state
		void Close() override;													//Method that closes the state
		~Game();																//Destructor
};