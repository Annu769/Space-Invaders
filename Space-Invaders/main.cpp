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
        window->clear(sf::Color::Black);
        sf::Texture texture;
        texture.loadFromFile("assets/textures/outscal_logo.png");
        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(texture);
        outscal_sprite.setPosition(200, 100); 
        outscal_sprite.setRotation(45); 
        outscal_sprite.setScale(0.5, 0.5);
        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("SFML is Awesome", font, 50);
        text.setFillColor(sf::Color::White);
        window->draw(text);
        window->draw(outscal_sprite);
        window->display();
    }

    return 0;
}