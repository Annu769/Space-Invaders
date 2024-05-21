#include"../Header/ServiceLocator.h"


 ServiceLocator::ServiceLocator()
{
	 graphicService = nullptr;
	 eventService = nullptr;
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
 }
 void ServiceLocator::clearALlService()
 {
	 delete(graphicService);
	 delete(eventService);
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
 }
 void ServiceLocator::Update()
 {
	 graphicService->update();
	 eventService->update();
 }
 void ServiceLocator::render()
 {
	 graphicService->render();
 }
 GraphicService* ServiceLocator::getGraphicService()
 {
	 return graphicService;
 }
 EventService* ServiceLocator::getEventService()
 {
	 return eventService;
 }