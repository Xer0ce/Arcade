/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sprite
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <memory>
#include "../AEntity.hpp"

class Sprite : public Graphic::AEntity {
    public:
        Sprite(std::string type, float x, float y, std::string texturePath, char symbol);
        ~Sprite();

        void setTexture(std::string &path) override;
        void setPosition(float x, float y) override;
        std::pair<float, float> getPosition() override;
        void setSize(float x, float y) override;
        sf::Sprite getSprite();

        void setRotation(float angle) override;
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
};
