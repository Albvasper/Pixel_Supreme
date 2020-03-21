#include <iostream>
#include <string>
#include "../include/Game.h"
#include "../include/Logging.h"
#include "../include/LuaScript.h"

Game::Game() {
}

void Game::Init(Platform* platform, GameStateManager* manager) {
	if (Logging::Get()->CheckLang() == "ENG") {
		Logging::Get()->Info("Initializing..","State");
	}
	else if (Logging::Get()->CheckLang() == "ESP"){
		Logging::Get()->Info("Inicializando..", "Estado");
	}
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
		if (Logging::Get()->CheckLang() == "ENG") {
			Logging::Get()->Info("Quiting state.", "State");
			Logging::Get()->Info("Quiting game loop.", "GameStateManager");
			Logging::Get()->Info("Quiting engine.", "GameStateManager");
			Logging::Get()->Section("END");
		}
		else if (Logging::Get()->CheckLang() == "ESP") {
			Logging::Get()->Info("Saliendo del estado acutal.", "Estado");
			Logging::Get()->Info("Saliendo del game loop.", "AdminDeEstados");
			Logging::Get()->Info("Cerrando Pixel Supreme.", "AdminDeEstados");
			Logging::Get()->Section("FIN");
		}
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