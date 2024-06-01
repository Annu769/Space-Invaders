#include"../../Header/Global/ServiceLocator.h"
namespace Global
{
	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		eventService = nullptr;
		playerService = nullptr;
		timeService = nullptr;
		uiService = nullptr;
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
		graphicService->initialize();
		eventService->initialize();
		playerService->initialize();
		timeService->initialize();
		uiService->initialize();
	}
	void ServiceLocator::Update()
	{
		graphicService->update();
		eventService->update();
		playerService->update();
		timeService->update();
		uiService->update();
	}
	void ServiceLocator::render()
	{
		graphicService->render();
		uiService->render();
		//playerService->render();
		
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
