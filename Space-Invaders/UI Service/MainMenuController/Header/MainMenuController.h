#pragma once
#include <SFML/Graphics.hpp>
namespace UI
{
	namespace MainMenu
	{
		class MainMenuController
		{
		private :
			sf::RenderWindow* gameWindow;
		public:
			MainMenuController();
			MainMenuController();
			void initialize();
			void render();
			void update();
		};
	}
}
