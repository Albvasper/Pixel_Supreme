#include <fstream>  
#include "SDL.h"
#include "../../include/GameStateManager.h"
#include "../../include/Menu.h"

int main(int argc, char** argv) {
	//Create a log.txt file that stores all the logging
	std::ofstream logFile("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\doc\\LastLog.txt");
	logFile << "my text here!" << std::endl;
	logFile.close();
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