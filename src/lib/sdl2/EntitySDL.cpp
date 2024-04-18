/*
** EPITECH PROJECT, 2024
** $
** File description:
** EntitySDL
*/

#include "EntitySDL.hpp"

EntitySDL::EntitySDL(std::string type, float x, float y, std::string texturePath, char symbol, SDL_Renderer *renderer)
{
    _type = type;
    _renderer = renderer;
    _rect = new SDL_Rect();
    _rect->x = x * 32;
    _rect->y = y * 32;
    _rect->w = 32;
    _rect->h = 32;
    _direction = 2;
    _angle = 0;
    _symbol = symbol;
    setTexture(texturePath);
}

EntitySDL::~EntitySDL()
{
    SDL_DestroyTexture(_texture);
    delete _rect;
}

void EntitySDL::setTexture(std::string &path)
{
    _texture = IMG_LoadTexture(_renderer, path.c_str());
    _texturePath = path;
}

void EntitySDL::setPosition(float x, float y)
{
    _rect->x = x * 32;
    _rect->y = y * 32;
    _position = std::make_pair(x, y);
}

std::pair<float, float> EntitySDL::getPosition()
{
    return std::make_pair(_rect->x / 32, _rect->y / 32);
}

void EntitySDL::setSize(float x, float y)
{
    _rect->w = x;
    _rect->h = y;
}

SDL_Texture *EntitySDL::getTexture()
{
    return _texture;
}

void EntitySDL::setRotation(float angle)
{
    _angle = angle;
}

SDL_Rect *EntitySDL::getRect()
{
    return _rect;
}
