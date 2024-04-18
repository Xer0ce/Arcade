/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-arcade-louis.huguet
** File description:
** Entity
*/

#include "Entity.hpp"

EntityNcurses::EntityNcurses(std::string type, float x, float y, std::string texturePath, char symbol)
{
    _type = type;
    _position = std::make_pair(x, y);
    _texturePath = texturePath;
    _symbol = symbol;
    _angle = 0;
    setDirection(2);
}

EntityNcurses::~EntityNcurses()
{
}

void EntityNcurses::setTexture(std::string &path)
{
    return;
}

void EntityNcurses::setPosition(float x, float y)
{
    _position = std::make_pair(x, y);
}

std::pair<float, float> EntityNcurses::getPosition()
{
    return _position;
}

void EntityNcurses::setSize(float x, float y)
{
}

char EntityNcurses::getSymbol()
{
    return _symbol;
}
