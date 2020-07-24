#pragma once
#include <SFML/Graphics.hpp>


class Ball
{
private:
    sf::Vector2f position;

    // Kwadrat
    sf::RectangleShape ballShape;

    float xVelocity = .214831f;
    float yVelocity = -.153716f;

public:
    Ball(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    float getXVelocity();

    void hitSides(int i);

    void reboundBat();

    void hitBottomOrTop();

    void update();

};