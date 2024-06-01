#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include<iostream>
namespace Event
{
	using namespace Global;
	EventService::EventService()
		: gameWindow(nullptr)  // Initialize gameWindow to nullptr
	{
		// No need to initialize gameEvent, as it will be default-initialized
	}
	EventService :: ~EventService() = default;

	void EventService::initialize()
	{
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		if (gameWindow == nullptr)
		{
			std::cout << "Failed to get game window from GraphicService" << std::endl;
		}
	}
	void EventService::update()
	{
		//for later
	}
	void EventService::processEvents()
	{
		if (isGameWindowOpen())
		{
			while (gameWindow->pollEvent(gameEvent))
			{
				if (gameWindowWasClosed() || hasQuitGame())
				{
					gameWindow->close();
				}
			}
		}
	}
	bool EventService::hasQuitGame()
	{
		return (isKeyboardEvent() && pressedEscapeKey());
	}
	bool EventService::isKeyboardEvent() { return gameEvent.type == sf::Event::KeyPressed; }

	bool EventService::pressedEscapeKey() { return gameEvent.key.code == sf::Keyboard::Escape; }

	bool EventService::isGameWindowOpen() { return gameWindow && gameWindow->isOpen(); }

	bool EventService::gameWindowWasClosed() { return gameEvent.type == sf::Event::Closed; }
	bool EventService::pressedLeftKey()
	{
		return gameEvent.key.code == sf::Keyboard::Left;
	}
	bool EventService::pressedRightKey()
	{
		return gameEvent.key.code == sf::Keyboard::Right;
	}


}
