<<<<<<< Updated upstream
#include"../../Header/Main/GameService.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
  int main() {

	  GameService* gameService = new GameService();

	  gameService->Ignite();

	  while (gameService->isRunning())
	  {
		  gameService->Update();
		  gameService->Render();
		 
	  }
      delete gameService;
      return 0;
  }
=======
#include <SFML/Graphics.hpp>

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
        window->clear(sf::Color::Blue);

        // Draw your content here...

        // Display what was drawn
        window->display();
    }

    return 0;
}
>>>>>>> Stashed changes
