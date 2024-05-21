#include "../Header/GameService.h"
#include "../Header/GraphicService.h"

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
	serviceLocator = nullptr;
	gameWindow = __nullptr;

}

GameService::~GameService()
{
	//destructor
	Destroy();
}

void GameService::Ignite()
{
	serviceLocator = ServiceLocator::getInstance();
	Initialize();
}

void GameService::Update()
{
	serviceLocator->getEventService()->processEvents();
	serviceLocator->Update();

}

void GameService::Render()
{
	gameWindow->clear(serviceLocator->getGraphicService()->getWindowColor());
	serviceLocator->render();
	gameWindow->display();
}

bool GameService::isRunning()
{
	// Checks if the game is currently running.
	return serviceLocator->getGraphicService()->isGameWindowOpen();
}

