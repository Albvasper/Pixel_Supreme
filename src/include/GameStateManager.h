#pragma once
#include "GameState.h"
#include "Platform.h"
#include "Stack.h"
#include "Logging.h"

class GameState;

class GameStateManager {

	private:
		//std::stack<GameState*> states;		
		Stack<GameState*> states;			//Container that stores game states
		Platform* platform;					//Pointer to platform
		Logging* log;						//Pointer to logging object

	public:
		GameStateManager();					//Constructor
		void GameLoop();					//Method that is refreshed every frame
		void SetState(GameState* state);	//Method that sets the current state
		void RealaseState();				//Method that removes the state
		~GameStateManager();				//Destructor
};