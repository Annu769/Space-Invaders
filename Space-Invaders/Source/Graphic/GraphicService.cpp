#include"../../Header/Graphic/GraphicService.h"
namespace Graphic {
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
		gameWindow->setVerticalSyncEnabled(true); // Enable VSync
		gameWindow->setFramerateLimit(frame_rate);
	}
	sf::RenderWindow* GraphicService::createGameWindow()
	{
		setVideoMode();
		return new sf::RenderWindow(*videoMode, gameWindowTitel, sf::Style::Fullscreen);
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
		if (gameWindow)
		{
			gameWindow->clear(windowColor);

			gameWindow->display();
		}
	}
	bool GraphicService::isGameWindowOpen()
	{
		return gameWindow && gameWindow->isOpen();
	}
	sf::RenderWindow* GraphicService::getGameWindow()
	{
		return gameWindow;
	}
	sf::Color GraphicService::getWindowColor()
	{
		return windowColor;
	}
}



