#pragma once
#include <SFML/Graphics.hpp>
class GraphicService {
private:
	const std::string gameWindowTitel = "Outscal Present - Alien Invader";
	const int gameWindowWidth = 1280;
	const int gameWindowHeight = 720;
	const sf::Color windowColor = sf::Color::Black;
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
