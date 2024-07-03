#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include<iostream>
namespace Event
{
	using namespace Global;
	EventService::EventService()
		: gameWindow(nullptr)  
	{
		
	}
	EventService :: ~EventService() = default;

	void EventService::initialize()
	{
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		if (gameWindow == nullptr)
		{
			std::cout << "Failed to get game window from GraphicService" << std::endl;
		}
	}
	void EventService::update()
	{
		updateMouseButtonsState(left_mouse_button_state, sf::Mouse::Left);
		updateMouseButtonsState(right_mouse_button_state, sf::Mouse::Right);
		updateKeyboardButtonsState(left_arrow_button_state, sf::Keyboard::Left);
		updateKeyboardButtonsState(right_arrow_button_state, sf::Keyboard::Right);
		updateKeyboardButtonsState(A_button_state, sf::Keyboard::A);
		updateKeyboardButtonsState(D_button_state, sf::Keyboard::D);
	}
	void EventService::processEvents()
	{
		if (isGameWindowOpen())
		{
			while (gameWindow->pollEvent(gameEvent))
			{
				if (gameWindowWasClosed() || hasQuitGame())
				{
					gameWindow->close();
				}
			}
		}
	}
	bool EventService::hasQuitGame()
	{
		return (isKeyboardEvent() && pressedEscapeKey());
	}
	bool EventService::isKeyboardEvent() { return gameEvent.type == sf::Event::KeyPressed; }

	bool EventService::pressedEscapeKey() { return gameEvent.key.code == sf::Keyboard::Escape; }

	bool EventService::isGameWindowOpen() { return gameWindow && gameWindow->isOpen(); }

	bool EventService::gameWindowWasClosed() { return gameEvent.type == sf::Event::Closed; }
	/*bool EventService::pressedLeftKey()
	{
		return gameEvent.key.code == sf::Keyboard::Left;
	}
	bool EventService::pressedRightKey()
	{
		return gameEvent.key.code == sf::Keyboard::Right;
		
	}
	bool EventService::pressedLeftMouseButton()
	{
		return gameEvent.type == sf::Event::MouseButtonPressed && gameEvent.mouseButton.button == sf::Mouse::Left;
	}

	bool EventService::pressedRightMouseButton()
	{
		return gameEvent.type == sf::Event::MouseButtonPressed && gameEvent.mouseButton.button == sf::Mouse::Right;
	}*/
	void EventService::updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button)
	{
		if (sf::Mouse::isButtonPressed(mouse_button))
		{
			switch (current_button_state)
			{
			case ButtonState::RELEASED:
				current_button_state = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				current_button_state = ButtonState::HELD;
				break;
			}
		}
		else
		{
			current_button_state = ButtonState::RELEASED;
		}
	}

	void EventService::updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button)
	{
		if (sf::Keyboard::isKeyPressed(keyboard_button))
		{
			switch (current_button_state)
			{
			case ButtonState::RELEASED:
				current_button_state = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				current_button_state = ButtonState::HELD;
				break;
			}
		}
		else
		{
			current_button_state = ButtonState::RELEASED;
		}
	}

	bool EventService::pressedLeftKey() { return left_arrow_button_state == ButtonState::HELD; }

	bool EventService::pressedRightKey() { return right_arrow_button_state == ButtonState::HELD; }

	bool EventService::pressedAKey() { return A_button_state == ButtonState::HELD; }

	bool EventService::pressedDKey() { return D_button_state == ButtonState::HELD; }

	bool EventService::pressedLeftMouseButton() { return left_mouse_button_state == ButtonState::PRESSED; }

	bool EventService::pressedRightMouseButton() { return right_mouse_button_state == ButtonState::PRESSED; }
}
