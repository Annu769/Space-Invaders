#include"../Header/ServiceLocator.h"


 ServiceLocator::ServiceLocator()
{
	 graphicService = nullptr;
	 eventService = nullptr;
	 playerService = nullptr;
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
	 
 }
 void ServiceLocator::clearALlService()
 {
	 delete(graphicService);
	 delete(eventService);
	 delete(playerService);
 }
 ServiceLocator *ServiceLocator::getInstance()
 {
	 static ServiceLocator instace;
	 return &instace;
 }
 void ServiceLocator::initialize()
 {
	 graphicService->initialize();
	 eventService->initialize();
	 playerService->initialize();
 }
 void ServiceLocator::Update()
 {
	 graphicService->update();
	 eventService->update();
	 playerService->update();
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