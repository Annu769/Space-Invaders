#include "../Header/EventService.h"
#include"../Header/GameService.h"
#include"../Header/GraphicService.h"

EventService::EventService()
{
	gameWindow = nullptr;
}
EventService :: ~EventService() = default;

void EventService::initialize()
{
	gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
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

//control click on the SFML functions to see what they do internally
bool EventService::pressedEscapeKey() { return gameEvent.key.code == sf::Keyboard::Escape; }

bool EventService::isGameWindowOpen() { return gameWindow != nullptr; }

bool EventService::gameWindowWasClosed() { return gameEvent.type == sf::Event::Closed; }

