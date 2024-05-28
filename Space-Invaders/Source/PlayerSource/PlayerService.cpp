#include"../../Header/Player/PlayerService.h"
#include "../../Header/PLayer/PlayerController.h"
#include <iostream>

PlayerService::PlayerService()
{

	player_controller = new PlayerController();
}
PlayerService :: ~PlayerService()
{

	delete(player_controller);
}

void PlayerService::initialize()
{

	player_controller->initialize();
}

void PlayerService::update()
{
	
	player_controller->updare();
}

void PlayerService::render()
{

	player_controller->render();
}
