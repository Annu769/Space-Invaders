#include"../Header/GraphicService.h"
GraphicService::GraphicService()
{
	gameWindow = nullptr;
	videoMode = nullptr;
}
GraphicService:: ~GraphicService()
{
	onDestroy();
}
void GraphicService::initialize()
{
	gameWindow = createGameWindow();
}
sf::RenderWindow* GraphicService::createGameWindow()
{
	setVideoMode();
	return new sf::RenderWindow(*videoMode, gameWindowTitel);
}
void GraphicService::setVideoMode()
{
	videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight,
		sf::VideoMode::getDesktopMode().bitsPerPixel);
}
void GraphicService::onDestroy()
{
	delete(videoMode);
	delete(gameWindow);
}
void GraphicService::update()
{

}
void GraphicService::render()
{

}
bool GraphicService::isGameWindowOpen()
{
	return gameWindow->isOpen();
}
sf::RenderWindow* GraphicService::getGameWindow()
{
	return gameWindow;
}
sf::Color GraphicService::getWindowColor()
{
	return windowColor;
}


