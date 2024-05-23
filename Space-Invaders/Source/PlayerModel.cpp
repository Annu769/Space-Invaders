#include"../Header/PlayerModel.h"
PlayerModel::PlayerModel()
{

}
PlayerModel::~PlayerModel()
{

}
void PlayerModel::initialize()
{
	reset();
}
void PlayerModel::reset()
{
	playerAliveState = PlayerState::Alive;
	position = initial_player_position;
	player_Score = 0;
}
void PlayerModel::setPlayerPosition(sf::Vector2f _position)
{
	position = _position;
}
void PlayerModel::setPlayerAlive(PlayerState isAlive)
{
	playerAliveState = isAlive;
}
PlayerState PlayerModel::getPlayerAlive()
{
	return playerAliveState;
}
sf::Vector2f PlayerModel::getPlayerPosition()
{
	return position;
}