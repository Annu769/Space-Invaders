#pragma once
#include "../Header/GraphicService.h"
// Service Locator Class summary this class manages acces to various services in the application
class ServiceLocator
{
private:
	GraphicService* graphicService;
	ServiceLocator()
	{

	}
	~ServiceLocator()
	{

	}
	void createService()
	{

	}
	void clearALlService()
	{

	}
public:
	//public Methods:
	static ServiceLocator* getInstance()
	{
		//provide a method to acces the unique ServiceLocator instance (object ).
	}
	void initialize()
	{
		//Initializes the service locator.
	}
	void Update()
	{
		//Update all service
	}
	void render()
	{
		//render using the service.
	}
	GraphicService* getGraphicService()
	{

	}

};