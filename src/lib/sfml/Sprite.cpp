/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sprite
*/

#include "Sprite.hpp"

Sprite::Sprite(std::string type, float x, float y, std::string texturePath, char symbol)
{
    _type = type;
    _sprite.setOrigin(16, 16);
    _sprite.setPosition((x + 1) * 32 - 16, (y + 1) * 32 - 16);
    setDirection(2);
    setTexture(texturePath);
    _symbol = symbol;
}

Sprite::~Sprite()
{
}

void Sprite::setTexture(std::string &path)
{
    if (!path.empty()) {
        _texture.loadFromFile(path);
        _sprite.setTexture(_texture);
    }
    _texturePath = path;
}

void Sprite::setPosition(float x, float y)
{
    _sprite.setPosition((x + 1) * 32 - 16, (y + 1) * 32 - 16);
    _position = std::make_pair(x, y);
}

std::pair<float, float> Sprite::getPosition()
{
    return std::make_pair((_sprite.getPosition().x + 16) / 32 - 1, (_sprite.getPosition().y + 16) / 32 - 1);
}

void Sprite::setSize(float x, float y)
{
    _sprite.setScale(x, y);
}

sf::Sprite Sprite::getSprite()
{
    return _sprite;
}

void Sprite::setRotation(float angle)
{
    _sprite.setRotation(angle);
    _angle = angle;
}
