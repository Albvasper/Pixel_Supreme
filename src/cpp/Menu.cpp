#include "../include/Menu.h"
#include<iostream>

Menu::Menu() {
}

void Menu::Init(Platform* platform, GameStateManager* manager) {
	log = new Logging();
	log->Info("Initializing..","State");
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
		log->Info("Quiting state.", "State");
		log->Info("Quiting game loop.", "GameStateManager");
		log->Info("Quiting engine.", "GameStateManager");
		log->Section("END");
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