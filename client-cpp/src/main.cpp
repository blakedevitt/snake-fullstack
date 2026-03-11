#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
enum class Direction {
    Left, 
    Right,
    Up,
    Down
};

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Snake Test");

    sf::RectangleShape snakeHead(sf::Vector2f({20.f, 20.f}));
    sf::RectangleShape snakeBody(sf::Vector2f({20.f, 20.f}));
    snakeHead.setFillColor(sf::Color(0, 255, 0));
    snakeHead.setOutlineThickness(1.f);
    snakeHead.setOutlineColor(sf::Color::Black);

    snakeBody.setFillColor(sf::Color(0, 170, 0));
    snakeBody.setPosition({80.f, 100.f});
    float x = 100.f;
    float y = 100.f;
    float cellsize = 20.f;
    Direction direction = Direction::Right;

    sf::Clock clock;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && direction != Direction::Right) {
            direction = Direction::Left;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && direction != Direction::Left) {
            direction = Direction::Right;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && direction != Direction::Down) {
            direction = Direction::Up;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && direction != Direction::Up) {
            direction = Direction::Down;
        }
        
        if (clock.getElapsedTime().asSeconds() > 0.15f) {
            float oldX = x;
            float oldY = y;
            if (direction == Direction::Left && x > 0) {
                x -= cellsize;
            } else if (direction == Direction::Right && x < window.getSize().x - cellsize) {
                x += cellsize;
            } else if (direction == Direction::Up && y > 0) {
                y -= cellsize;
            } else if (direction == Direction::Down && y < window.getSize().y - cellsize) {
                y += cellsize;
            }
            snakeBody.setPosition({oldX, oldY});
            clock.restart();
        }
        snakeHead.setPosition({x, y});
        window.clear(sf::Color::Black);
        window.draw(snakeHead);
        window.draw(snakeBody);
        window.display();
    }

    return 0;
}