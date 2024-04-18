/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** RectangleShape
*/

#include "RectangleShape.hpp"

namespace Graphic {
    RectangleShape::RectangleShape()
    {
        _rectangleShape.setSize(sf::Vector2f(32, 32));
    }

    RectangleShape::~RectangleShape()
    {
    }

    void RectangleShape::setColor(const sf::Color &color)
    {
        _rectangleShape.setFillColor(color);
    }

    void RectangleShape::setPosition(const sf::Vector2f &position)
    {
        _rectangleShape.setPosition(position);
    }

    void RectangleShape::draw(sf::RenderWindow &window)
    {
        window.draw(_rectangleShape);
    }
}
