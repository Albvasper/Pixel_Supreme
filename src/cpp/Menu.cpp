#include "../include/Menu.h"
#include<iostream>

Menu::Menu() {
}

void Menu::Init(Platform* platform, GameStateManager* manager) {
	this->platform = platform;
	this->manager = manager;
}

void Menu::Draw() {
	platform->RenderClear();
	platform->RenderPresent();
}

bool Menu::Input(int keyInput) {
	//If ENTER is pressed
	if (keyInput == 27) {
		//Quit
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