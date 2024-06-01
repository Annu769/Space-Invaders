#include "../../UI Service/MainMenuController/Header/MainMenuController.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Event/EventService.h"
#include"../../Header/Main/GameService.h"
#include"../../Header/Graphic/GraphicService.h"


namespace UI
{
	
	namespace MainMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Event;
		using namespace Graphic;
		MainMenuController::MainMenuController()
		{
			gameWindow = nullptr;
		}
		MainMenuController:: ~MainMenuController()
		{

		}
		void MainMenuController::initialize()
		{
			gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		}
		void MainMenuController::render()
		{

		}
		void MainMenuController::update()
		{

		}

	}
}