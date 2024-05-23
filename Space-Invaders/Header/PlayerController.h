#pragma once
#include"../Header/PlayerModel.h"
#include"../Header/PlayerView.h"
#include"../Header/EventService.h"
class PlayerController
{
private:
	PlayerModel* playerModel;
	PlayerView* playerView;
	void playerProcesInput();
	void MoveLeft(float deltaTime);
	void MoveRight(float deltaTime);
public:
	PlayerController();
	~PlayerController();
	void initialize();
	void updare();
	void render();
	sf::Vector2f getPlayerPosition();
};
