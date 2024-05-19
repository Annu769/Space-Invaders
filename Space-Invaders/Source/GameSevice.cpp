#include "../Header/GameService.h"
#include <iostream>

void GameService::Initialize()
{
	//... Get things running
}

void GameService::Destroy()
{
	//cleanup resources
}

GameService::GameService()
{
	//constructor
}

GameService::~GameService()
{
	//destructor
}

void GameService::Ignite()
{
	//starts the game
}

void GameService::Update()
{
	// Updates the game logic and game state.
}

void GameService::Render()
{
	// Renders each frame of the game.
}

bool GameService::isRunning()
{
	// Checks if the game is currently running.
	return false; //default return
}

