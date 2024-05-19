#include"../Space-Invaders/Header/GameService.h"
#include <iostream>
//#include <SFML/Graphics.hpp>

using namespace std;

//class Player 
//{
//private:
//   
//    sf::Vector2f playerPosition = sf::Vector2f(400.0f,300.0f);
//    int health =3;
//    int playerScore = 0;
//    int movementSpeed = 2;
//   
//public:
//    sf::Texture playerTexture;
//    sf::Sprite playerSprite;
//    int GetHealth()
//    {
//        return health;
//    }
//    int GetScore()
//    {
//        return playerScore;
//    }
//    int GetMovementSpeed()
//    {
//        return movementSpeed;
//    }
//    sf::Vector2f GetPlayerPosition()
//    {
//        return playerPosition;
//    }
//    void TakeDmage()
//    {
//
//    }
//    void Move(float offsetX)
//    {
//        playerPosition.x += offsetX;
//    }
//    void ShootBullet()
//    {
//
//    }
//};
//
  int main() {

	  GameService gameService;

	  gameService.Ignite();

	  while (gameService.isRunning())
	  {
		  gameService.Update();
		  gameService.Render();
	  }
//    Player player;
//    // Define the video mode (dimensions)
//    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));
//
//    // Create a window object with specific dimensions and a title
//    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");
//    player.playerTexture.loadFromFile("assets/textures/player_ship.png");
//    player.playerSprite.setTexture(player.playerTexture);
//    player.playerSprite.setScale(0.5, 0.5);
//    // Game loop to keep the window open
//    while (window->isOpen()) {
//        sf::Event event;
//       
//        while (window->pollEvent(event)) {
//            // Check for window closure
//
//            if (event.type == sf::Event::Closed)
//                window->close();
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//        {
//            player.Move(-1.0f * player.GetMovementSpeed());
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//        {
//            player.Move(1.0f * player.GetMovementSpeed());
//        }
//        // Clear the window
//        window->clear(sf::Color::Black);
//      
//        player.playerSprite.setPosition(player.GetPlayerPosition());
//       
//        window->draw(player.playerSprite);
//        window->display();
//    }
//
//    return 0;
  }