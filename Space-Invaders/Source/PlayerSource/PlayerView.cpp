#include"../../Header/Player/PlayerView.h"
#include"../../Header//Global/ServiceLocator.h"
PlayerView::PlayerView()
{

}
PlayerView::~PlayerView()
{

}
void PlayerView::initialize(PlayerController *_playerController)
{
	playerController = _playerController;
	gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerScript();
}
void PlayerView::update()
{
	sf::Vector2f playerPosition = playerController->getPlayerPosition();
	playerSprite.setPosition(round(playerPosition.x), round(playerPosition.y));
}
void PlayerView::render()
{

	gameWindow->draw(playerSprite); 
	gameWindow->display();
}
void PlayerView::initializePlayerScript()
{
	if (playerTexture.loadFromFile(player_texture_path))
	{
		playerSprite.setTexture(playerTexture);
		scaleSprite();
	}
	
}
void PlayerView::scaleSprite()
{
	static_cast<float>(player_sprite_width) / playerSprite.getTexture()->getSize().x;
	static_cast<float>(player_sprite_Height) / playerSprite.getTexture()->getSize().y;

}