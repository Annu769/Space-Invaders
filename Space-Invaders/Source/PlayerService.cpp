#include"../Header/PlayerService.h"
#include"../Header/ServiceLocator.h"
#include <iostream>

PlayerService::PlayerService()
{
	gameWindow = nullptr;
}
PlayerService :: ~PlayerService() = default;

void PlayerService::initialize()
{
	gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerScript();
}
void PlayerService::update()
{
	
	playerSprite.setPosition(getPosition());
	ProcessPalayerInput();
}
void PlayerService::render()
{
	playerSprite.setPosition(getPosition());  // Update position before rendering
	gameWindow->draw(playerSprite);
}
void PlayerService::initializePlayerScript()
{
	if (playerTexture.loadFromFile(player_texture_path)) {
		playerSprite.setTexture(playerTexture);
	}
	else {
		std::cout << "Failed to load player texture from path: " << player_texture_path.toAnsiString() << std::endl;
	}
}
void PlayerService::ProcessPalayerInput()
{
	EventService* GameEvent = ServiceLocator::getInstance()->getEventService();
	float deltatime = ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	if (GameEvent->isKeyboardEvent())
	{
		if (GameEvent->pressedLeftKey())
		{
			Moveleft(deltatime);
		}
		if (GameEvent->pressedRightKey())
		{
			MoveRight(deltatime);
		}
	}
	
}
 
sf::Vector2f PlayerService::getPosition()
{
	return position;
}
void PlayerService::Moveleft(float deltaTIme)
{
	position.x -= movementSpeed * deltaTIme;

}
void PlayerService::MoveRight(float deltaTIme)
{
	position.x += movementSpeed * deltaTIme;
}