#include "../include/GameStateManager.h"
#include "../include/Logging.h"
#include <windows.h>

GameStateManager::GameStateManager() {
	if (Logging::Get()->CheckLang() == "ENG") {
		Logging::Get()->Section("START");
		Logging::Get()->Info("Initializing...", "GameStateManager");
	}
	else if (Logging::Get()->CheckLang() == "ESP") {
		Logging::Get()->Section("INICIO");
		Logging::Get()->Info("Inicializando...", "AdminDeEstados");
	}
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
				if (Logging::Get()->CheckLang() == "ENG") {
					Logging::Get()->Error("There are no states in the stack!", "GameStateManager");
				}
				else if (Logging::Get()->CheckLang() == "ESP") {
					Logging::Get()->Error("No hay estados en la pila!", "AdminDeEstados");
				}
				throw std::exception("ERROR");
			}
			else {
				//Print success once
				if (success == true) {
					if (Logging::Get()->CheckLang() == "ENG") {
						Logging::Get()->Info("Game loop executed successfully.", "GameStateManager");
					}
					else if (Logging::Get()->CheckLang() == "ESP") {
						Logging::Get()->Info("Bucle de juego ejecutado con exito.", "AdminDeEstados");
					}
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
			if (success == true) {
				if (Logging::Get()->CheckLang() == "ENG") {
					Logging::Get()->Error("Critical error, the engine is closing...", "GameStateManager");
				}
				else if (Logging::Get()->CheckLang() == "ESP") {
					Logging::Get()->Error("Error critico, cerrando engine...", "AdminDeEstados");
				}
				success = false;
			}
			Logging::Get()->Save();
			//Quit the gameloop
			break;
		}
	}
}

void GameStateManager::SetState(GameState* state) {
	if (Logging::Get()->CheckLang() == "ENG") {
		Logging::Get()->Info("Setting new state...", "GameStateManager");
	}
	else if (Logging::Get()->CheckLang() == "ESP") {
		Logging::Get()->Info("Configurando nuevo estado...", "AdminDeEstados");
	}
	//Initialize current state
	state->Init(platform, this);
	//Push the state to the states stack
	states.push(state);
}

void GameStateManager::RealaseState() {
	//Take the state that is at the top of the stack
	auto state = states.first->data;
	//Close the current state
	if (Logging::Get()->CheckLang() == "ENG") {
		Logging::Get()->Info("Closing current state...", "GameStateManager");
	}
	else if (Logging::Get()->CheckLang() == "ESP") {
		Logging::Get()->Info("Cerrando el estado acutal...", "AdminDeEstados");
	}
	state->Close();
	//Pop it from the stack
	states.pop();
}

GameStateManager::~GameStateManager() {
}