#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/TIme/TimeService.h"
#include "../../Header/Event/EventService.h"
namespace Global
{
    using namespace Event;
    using namespace Graphic;
    using namespace Time;
    using namespace Player;

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

}
