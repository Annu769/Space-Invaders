#pragma once
#include <SFML/Graphics.hpp>
enum class PlayerState;
class PlayerView;
class PlayerModel;

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
