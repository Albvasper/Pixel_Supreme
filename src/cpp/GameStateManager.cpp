#include "../include/GameStateManager.h"
#include "../include/Logging.h"
#include <windows.h>

GameStateManager::GameStateManager() {
	Logging::Get()->Section("START");
	Logging::Get()->Info("Initializing...", "GameStateManager");
	platform = new Platform("Pixel Supreme");
}

void GameStateManager::GameLoop() {
	bool success = true;
	//Game loop
	while (true) {
		try {
			//if there are no states in the stack 
			if (states.getSize() == 0) {	
				//Throw an error
				Logging::Get()->Error("There are no states in the stack!", "GameStateManager");
				throw std::exception("ERROR");
			}
			else {
				//Print success once
				if (success == true) {
					Logging::Get()->Info("Game loop executed successfully.","GameStateManager");
					success = false;
				}
				//Take the state that is on top of the stack
				auto state = states.first->data;
				//Check for an event
				platform->CheckEvent(state, &GameState::Input);
				//Update the current state
				state->Update();
				//Draw the current state
				state->Draw();
			}
		}
		catch (...) {
			//Error ocurred and close window
			Logging::Get()->Error("Critical error, the engine is closing...", "GameStateManager");
			Logging::Get()->Save();
			//Quit the gameloop
			break;
		}
	}
}

void GameStateManager::SetState(GameState* state) {
	Logging::Get()->Info("Setting new state...", "GameStateManager");
	//Initialize current state
	state->Init(platform, this);
	//Push the state to the states stack
	states.push(state);
}

void GameStateManager::RealaseState() {
	//Take the state that is at the top of the stack
	auto state = states.first->data;
	//Close the current state
	Logging::Get()->Info("Closing current state...", "GameStateManager");
	state->Close();
	//Pop it from the stack
	states.pop();
}

GameStateManager::~GameStateManager() {
}