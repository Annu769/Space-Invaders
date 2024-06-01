#include "../../Header/Main/GameService.h"
namespace Main
{
	using namespace Global;
	GameState GameService::current_state = GameState::BOOT;
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
		return serviceLocator->getGraphicService()->isGameWindowOpen();
	}
	void GameService::setGameState(GameState new_state) { current_state = new_state; }

	GameState GameService::getGameState() { return current_state; }

}

