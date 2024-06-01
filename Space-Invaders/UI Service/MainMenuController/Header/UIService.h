#pragma once
#include"../../UI Service/MainMenuController/Header/MainMenuController.h"

namespace UI
{
	using namespace MainMenu;
	class UIService
	{
	private:
		MainMenuController* main_menu_controller;

		void createControllers();
		void initializeControllers();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
	};
}
