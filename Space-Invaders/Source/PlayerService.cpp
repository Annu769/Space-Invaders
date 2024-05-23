#include"../Header/PlayerService.h"
#include"../Header/ServiceLocator.h"

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
	ProcessPalayerInput();
	playerSprite.setPosition(getPosition());
}
void PlayerService::render()
{
	gameWindow->draw(playerSprite);
}
void PlayerService::initializePlayerScript()
{
	if (playerTexture.loadFromFile(player_texture_path));
	{
		playerSprite.setTexture(playerTexture);
	}
}
void PlayerService::ProcessPalayerInput()
{
	EventService* GameEvent = ServiceLocator::getInstance()->getEventService();
	if (GameEvent->isKeyboardEvent())
	{
		if (GameEvent->pressedLeftKey())
		{
			Move(-1.0f * getMoveSpeed());
		}
		if (GameEvent->pressedRightKey())
		{
			Move(1.0f * getMoveSpeed());
		}
	}
	
}
void PlayerService::Move(float offsetX)
{
	position.x += offsetX;
}
sf::Vector2f PlayerService::getPosition()
{
	return position;
}
int PlayerService::getMoveSpeed()
{
	return movementSpeed;
}