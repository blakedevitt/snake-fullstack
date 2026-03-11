#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Snake Test");

    sf::RectangleShape snakeHead(sf::Vector2f({20.f, 20.f}));
    snakeHead.setFillColor(sf::Color::Green);
    snakeHead.setPosition({100.f, 100.f});

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(snakeHead);
        window.display();
    }

    return 0;
}