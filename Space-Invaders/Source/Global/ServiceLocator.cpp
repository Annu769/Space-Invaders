#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Main/GameService.h"
namespace Global
{
	using namespace Main;
	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		eventService = nullptr;
		playerService = nullptr;
		timeService = nullptr;
		uiService = nullptr;
		enemy_Service = nullptr;
		createService();

	}
	ServiceLocator:: ~ServiceLocator()
	{
		clearALlService();
	}
	void ServiceLocator::createService()
	{
		graphicService = new GraphicService();
		eventService = new EventService();
		playerService = new PlayerService();
		timeService = new TimeService();
		uiService = new UIService();

	}
	void ServiceLocator::clearALlService()
	{
		delete(graphicService);
		delete(eventService);
		delete(playerService);
		delete(timeService);
		delete(uiService);
	}
	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instace;
		return &instace;
	}
	void ServiceLocator::initialize()

	{
		uiService->initialize();
		graphicService->initialize();
		eventService->initialize();
		playerService->initialize();
		enemy_Service->initialize();
		timeService->initialize();
		
	}
	void ServiceLocator::Update()
	{
		graphicService->update();
		timeService->update();
		eventService->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			playerService->update();
			enemy_Service->update();
		}
		uiService->update();
		
		
	}
	void ServiceLocator::render()
	{
		graphicService->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			playerService->render();
			uiService->render();
		}
		
		enemy_Service->render();
		
	}
	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphicService;
	}
	EventService* ServiceLocator::getEventService()
	{
		return eventService;
	}
	PlayerService* ServiceLocator::getPlayerService()
	{
		return playerService;
	}
	TimeService* ServiceLocator::getTimeService()
	{
		return timeService;
	}
	UIService* ServiceLocator:: getUIService()
	{
		return uiService;
	}

}
