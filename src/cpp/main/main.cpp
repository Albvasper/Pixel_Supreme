#include <iostream>
#include "SDL.h"
#include "../../include/GameStateManager.h"
#include "../../include/Menu.h"
#include "../../include/Logging.h"

int main(int argc, char** argv) {
	//New game state manager called "manager"
	GameStateManager* manager = new GameStateManager();
	//Creates a new state called menu that is the current state
	manager->SetState(new Menu());
	manager->GameLoop();
	//When the program quits the game loop it deletes the manager
	delete manager;
	//End of program
	return 0;
}
