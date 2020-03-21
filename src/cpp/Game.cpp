#include <iostream>
#include <string>
#include "../include/Game.h"
#include "../include/Logging.h"
#include "../include/LuaScript.h"

Game::Game() {
}

void Game::Init(Platform* platform, GameStateManager* manager) {
	Logging::Get()->Info("Initializing..","State");
	this->platform = platform;
	this->manager = manager;
	/*LuaScript script("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\src\\LUA\\Scripts\\player.lua");
	std::string filename = script.get<std::string>("player.filename");
	int posX = script.get<int>("player.pos.X");*/
}

void Game::Draw() {
	platform->RenderClear();
	platform->RenderPresent();
}

bool Game::Input(int keyInput) {
	//If ESC is pressed
	if (keyInput == 27) {
		//Quit
		Logging::Get()->Info("Quiting state.", "State");
		Logging::Get()->Info("Quiting game loop.", "GameStateManager");
		Logging::Get()->Info("Quiting engine.", "GameStateManager");
		Logging::Get()->Section("END");
		Logging::Get()->Save();
		exit(1);
	}
	else {
		//manager->SetState(new Game());
	}
	return false;
}

void Game::Update() {
}

void Game::Close() {
}

Game::~Game() {
}