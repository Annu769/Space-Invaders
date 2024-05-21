#include"../Header/ServiceLocator.h"
#include <iostream>

 ServiceLocator::ServiceLocator()
{
	 graphicService = nullptr;
}
 ServiceLocator:: ~ServiceLocator()
 {
	 clearALlService();
 }
 void ServiceLocator::createService()
 {
	 graphicService = new GraphicService();
 }
 void ServiceLocator::clearALlService()
 {
	 delete(graphicService);
	 graphicService = nullptr;
 }
 ServiceLocator *ServiceLocator::getInstance()
 {
	 static ServiceLocator instace;
	 return &instace;
 }
 void ServiceLocator::initialize()
 {
	 graphicService->initialize();
 }
 void ServiceLocator::Update()
 {
	 graphicService->update();
 }
 void ServiceLocator::render()
 {
	 graphicService->render();
 }
 GraphicService* ServiceLocator::getGraphicService()
 {
	 return graphicService;
 }