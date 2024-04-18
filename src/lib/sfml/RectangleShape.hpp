/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** RectangleShape
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

namespace Graphic {
    class RectangleShape {
        public:
            RectangleShape();
            ~RectangleShape();

            void setColor(const sf::Color &color);

            void setPosition(const sf::Vector2f &position);

            void draw(sf::RenderWindow &window);

        private:
            sf::RectangleShape _rectangleShape;
    };
}
