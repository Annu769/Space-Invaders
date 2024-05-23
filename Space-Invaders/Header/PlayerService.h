#pragma once
#include <SFML/Graphics.hpp>

class PlayerService
{
private:

	sf::Vector2f position = sf::Vector2f(400.0f, 300.0f);
	int health = 3;
	int playerScore = 0;
	int movementSpeed = 2;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	const sf::String player_texture_path = "asset/texture/player_ship.png";
	sf::RenderWindow* gameWindow;
	void initializePlayerScript();
	void ProcessPalayerInput();

public:
	PlayerService();
	~PlayerService();

	void initialize();
	void update();
	void render();
	void Move(float offsetX);
	int getMoveSpeed();
	sf::Vector2f getPosition();
};
	    
	        
	    
	  
