#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Sprite.h"
class Menu : public GameState {

	private:
		Platform* platform;														//Pointer to platform
		Sprite* background;														//Background image for the state
		GameStateManager* manager;												//Pointer to the manager

	public:
		Menu();																	//Constructor
		void Init(Platform* platform, GameStateManager* manager) override;		//Method that initializes the state menu
		void Draw() override;													//Method that draws on screen
		bool Input(int keyInput) override;										//Method that recives key inputs
		void Update() override;													//Method that updates the state
		void Close() override;													//Method that closes the state
		~Menu();																//Destructor
};