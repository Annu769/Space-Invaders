#pragma once
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/Event.hpp>
namespace Event
{
	class EventService
	{
	private:
		sf::Event gameEvent;
		sf::RenderWindow* gameWindow;
		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuitGame();
	public:

		EventService();

		~EventService();

		void initialize();

		void update();

		void processEvents();

		// while window is open we will check for events
		bool pressedEscapeKey();

		bool isKeyboardEvent();
		bool pressedLeftKey();
		bool pressedRightKey();

	};
}
