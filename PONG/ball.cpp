#include "Ball.h"


Ball::Ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

sf::FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
    return ballShape;
}

float Ball::getXVelocity()
{
    return xVelocity;
}

void Ball::hitSides(int i)
{
    if (i == 1) {
        xVelocity = -.3f;
        yVelocity = -.2f;
    }
    else {
        xVelocity = .3f;
        yVelocity = .2f;
    }
    position.x = 512;
    position.y = 393;
}

void Ball::reset() {
    position.x = 512;
    position.y = 393;

    xVelocity = .214831f;
    yVelocity = -.153716f;
}

void Ball::reboundBat()
{
    xVelocity = -xVelocity;
    xVelocity = xVelocity * 1.132832;
    yVelocity = yVelocity * 1.098376;

}

void Ball::hitBottomOrTop()
{
    yVelocity = -yVelocity;
}

void Ball::update()
{
    // Aktualizacja pozycji
    position.y += yVelocity;
    position.x += xVelocity;

    // Przesuwa do pozycji
    ballShape.setPosition(position);
}