#pragma once
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/Event.hpp>
namespace Event
{
	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED,
	};
	class EventService
	{
	private:
		ButtonState left_mouse_button_state;
		ButtonState right_mouse_button_state;
		ButtonState left_arrow_button_state;
		ButtonState right_arrow_button_state;
		ButtonState A_button_state;
		ButtonState D_button_state;
		sf::Event gameEvent;
		sf::RenderWindow* gameWindow;
		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuitGame();
		void updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);
		void updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button);
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
		bool pressedLeftMouseButton();
		bool pressedRightMouseButton();
		bool pressedAKey();
		bool pressedDKey();

	};
}
