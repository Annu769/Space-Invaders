#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class Player 
{
private:
   
    sf::Vector2f playerPosition = sf::Vector2f(200.0f,100.0f);
    int health =3;
    int playerScore = 0;
    int movementSpeed = 5;
public:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    int GetHealth()
    {
        return health;
    }
    int GetScore()
    {
        return playerScore;
    }
    int GetMovementSpeed()
    {
        return movementSpeed;
    }
    sf::Vector2f GetPlayerPosition()
    {
        return playerPosition;
    }
};

int main() {

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    // Game loop to keep the window open
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Clear the window
        window->clear(sf::Color::Black);

        Player player;
        cout<<"Player Health "<< player.GetHealth() << endl;
        cout << "Player Score " << player.GetScore() << endl;
        cout << "Player MovementSpeed " << player.GetMovementSpeed() << endl;
       
        
        window->display();
    }

    return 0;
}