#include"../Header/PlayerView.h"
#include"../Header/ServiceLocator.h"
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
	playerSprite.setPosition(playerController->getPlayerPosition());
}
void PlayerView::render()
{
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