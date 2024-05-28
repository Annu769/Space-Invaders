#pragma once

#include "../Header/GraphicService.h"
#include "../Header/EventService.h"
#include "../Header/PlayerService.h"
#include"../Header/TimeService.h"

// Service Locator Class summary this class manages access to various services in the application
class ServiceLocator
{
private:
    GraphicService* graphicService;
    EventService* eventService;
    PlayerService* playerService;
    TimeService* timeService;

    ServiceLocator();
    ~ServiceLocator();
    void createService();
    void clearALlService();


public:
    // Provide a method to access the unique ServiceLocator instance (object).
    static ServiceLocator* getInstance();

    // Public Methods:
    void initialize();
    void Update();
    void render();
    GraphicService* getGraphicService();
    EventService* getEventService();
    PlayerService* getPlayerService();
    TimeService* getTimeService();

};
