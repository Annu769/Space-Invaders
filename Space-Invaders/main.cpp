#include <SFML/Graphics.hpp>

int main() {

    
    sf::VideoMode videoMode = *(new sf::VideoMode(1920,1080));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode.getFullscreenModes()[0], "My SFML Window",sf::Style::Fullscreen);
    window->setFramerateLimit(60);
    window->setPosition(sf::Vector2i(100, 100));
   

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