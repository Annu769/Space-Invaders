#pragma once
#include <SFML/Graphics.hpp>
namespace Graphic
{
	class GraphicService {
	private:
		const std::string gameWindowTitel = "Outscal Present - Alien Invader";
		const int gameWindowWidth = 1920;
		const int gameWindowHeight = 1080;
		const sf::Color windowColor = sf::Color::Black;
		const int frame_rate = 60;
		sf::VideoMode* videoMode;
		sf::RenderWindow* gameWindow;
		void setVideoMode();

		void onDestroy();

	public:
		GraphicService();

		~GraphicService();

		sf::RenderWindow* createGameWindow();

		void initialize();

		void update();

		void render();

		bool isGameWindowOpen();

		sf::RenderWindow* getGameWindow();

		sf::Color getWindowColor();
		
	};
}

