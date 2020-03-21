#include "SDL.h"
#include "../../include/GameStateManager.h"
#include "../../include/Game.h"

int main(int argc, char** argv) {
	//New game state manager called "manager"
	GameStateManager* manager = new GameStateManager();
	//Creates a new state called game that is the current state
	manager->SetState(new Game());
	manager->GameLoop();
	//When the program quits the game loop it deletes the manager
	delete manager;
	//End of program
	return 0;
}