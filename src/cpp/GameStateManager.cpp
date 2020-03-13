#include "../include/GameStateManager.h"
#include <windows.h>

GameStateManager::GameStateManager() {
	log->Section("START");
	log->Info("Initializing...", "GameStateManager");
	platform = new Platform("Pixel Supreme");
	log = new Logging();
}

void GameStateManager::GameLoop() {
	bool success = true;
	//Game loop
	while (true) {
		try {
			//if there are no states in the stack 
			if (states.getSize() == 0) {	
				//Throw an error
				log->Error("There are no states in the stack!", "GameStateManager");
				throw std::exception("ERROR");
			}
			else {
				//Print success once
				if (success == true) {
					log->Info("Game loop executed successfully.","GameStateManager");
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
			log->Error("Critical error, the engine is closing...", "GameStateManager");
			//Quit the gameloop
			break;
		}
	}
}

void GameStateManager::SetState(GameState* state) {
	log->Info("Setting new state...", "GameStateManager");
	//Initialize current state
	state->Init(platform, this);
	//Push the state to the states stack
	states.push(state);
}

void GameStateManager::RealaseState() {
	//Take the state that is at the top of the stack
	auto state = states.first->data;
	//Close the current state
	log->Info("Closing current state...", "GameStateManager");
	state->Close();
	//Pop it from the stack
	states.pop();
}

GameStateManager::~GameStateManager() {
}