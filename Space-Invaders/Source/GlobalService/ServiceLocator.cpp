#include"../../Header/Global/ServiceLocator.h"
namespace Global
{
	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		eventService = nullptr;
		playerService = nullptr;
		timeService = nullptr;
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

	}
	void ServiceLocator::clearALlService()
	{
		delete(graphicService);
		delete(eventService);
		delete(playerService);
		delete(timeService);
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
	}
	void ServiceLocator::Update()
	{
		graphicService->update();
		eventService->update();
		playerService->update();
		timeService->update();
	}
	void ServiceLocator::render()
	{
		graphicService->render();
		playerService->render();
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

}
