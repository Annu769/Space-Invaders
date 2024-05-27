#include "../../Header/Main/GameService.h"
namespace Main
{
	using namespace Global;
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

	void GameService::Initialize()
	{
		serviceLocator = ServiceLocator::getInstance();
		serviceLocator->initialize();
		gameWindow = serviceLocator->getInstance()->getGraphicService()->getGameWindow();
	}

	void GameService::Destroy()
	{
		//cleanup resources
	}

	void GameService::Ignite()
	{
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

}

