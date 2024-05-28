#pragma once
#include <SFML/Graphics.hpp>

class PlayerService
{
private:

	sf::Vector2f position = sf::Vector2f(400.0f, 300.0f);
	int health = 3;
	int playerScore = 0;
	float movementSpeed = 500.0f;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	const sf::String player_texture_path = "assets/textures/player_ship.png";
	sf::RenderWindow* gameWindow;
	void initializePlayerScript();
	void ProcessPalayerInput();

public:
	PlayerService();
	~PlayerService();

	void initialize();
	void update();
	void render();
	
	sf::Vector2f getPosition();
	void Moveleft(float deltaTIme);
	void MoveRight(float deltaTIme);
};
	    
	        
	    
	  
