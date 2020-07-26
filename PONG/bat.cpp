#include "Bat.h"


Bat::Bat(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    batShape.setSize(sf::Vector2f(7, 70));
    batShape.setPosition(position);
}

sf::FloatRect Bat::getPosition()
{
    return batShape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
    return batShape;
}

void Bat::reset() {
    position.y = 384;
}

void Bat::moveDown()
{
    position.y += batSpeed;
}

void Bat::moveUp()
{
    position.y -= batSpeed;
}

void Bat::update()
{
    batShape.setPosition(position);
}