#include "../include/Menu.h"
#include<iostream>
#include "../include/Logging.h"

Menu::Menu() {
}

void Menu::Init(Platform* platform, GameStateManager* manager) {
	Logging::Get()->Info("Initializing..","State");
	this->platform = platform;
	this->manager = manager;
}

void Menu::Draw() {
	platform->RenderClear();
	platform->RenderPresent();
}

bool Menu::Input(int keyInput) {
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

void Menu::Update() {
}

void Menu::Close() {
}

Menu::~Menu() {
}