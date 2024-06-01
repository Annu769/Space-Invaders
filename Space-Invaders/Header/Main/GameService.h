#pragma once
#include<SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"
namespace Main
{
	enum GameState
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY,
	};
	using namespace Global;
	class GameService
	{
	private:
		static GameState current_state;
		ServiceLocator* serviceLocator;
		sf::RenderWindow* gameWindow;

		void Initialize();

		void Destroy();

	public:
		GameService();

		~GameService();

		void Ignite();

		void Update();

		void Render();

		bool isRunning();
		static void setGameState(GameState new_state);
		static GameState getGameState();
		void showMainMenu();

	};
}
