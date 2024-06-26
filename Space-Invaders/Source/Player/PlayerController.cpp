#include"../../Header/Player/PlayerController.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Player/PlayerModel.h"
#include<algorithm>
namespace Player
{
	using namespace Global;
	PlayerController::PlayerController()
	{
		playerModel = new PlayerModel();
		playerView = new PlayerView();

	}
	PlayerController:: ~PlayerController()
	{
		delete(playerModel);
		delete(playerView);
	}
	void PlayerController::playerProcesInput()
	{
		float deltatime = ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedLeftKey() || event_service->pressedAKey())
		{
			MoveLeft(deltatime);
		}

		if (event_service->pressedRightKey() || event_service->pressedDKey())
		{
			MoveRight(deltatime);
		}

	}
	void PlayerController::MoveLeft(float deltaTime) {
		sf::Vector2f currposition = playerModel->getPlayerPosition();
		currposition.x += playerModel->player_movement_speed * deltaTime;

		currposition.x = std::max(currposition.x, playerModel->left_most_position.x);
		playerModel->setPlayerPosition(currposition);
	}
	void PlayerController::MoveRight(float deltaTime)
	{

		sf::Vector2f currposition = playerModel->getPlayerPosition();
		currposition.x -= playerModel->player_movement_speed * deltaTime;

		currposition.x = std::max(currposition.x, playerModel->right_most_position.x);
		playerModel->setPlayerPosition(currposition);
	}


	void PlayerController::initialize()
	{
		playerModel->initialize();
		playerView->initialize(this);
	}
	void PlayerController::updare()
	{
		playerProcesInput();
		playerView->update();
	}
	void PlayerController::render()
	{
		playerView->render();
	}
	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return playerModel->getPlayerPosition();
	}
}
