#pragma once
#include <SFML/Graphics.hpp>


class Bat
{
private:
    sf::Vector2f position;

    // Prostok¹t
    sf::RectangleShape batShape;

    float batSpeed = .75f;

public:
    Bat(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    void moveDown();

    void moveUp();

    void update();

};