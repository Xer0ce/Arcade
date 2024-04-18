/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-arcade-louis.huguet
** File description:
** AEntity
*/

#include "AEntity.hpp"

namespace Graphic {
    AEntity::AEntity()
    {
    }

    AEntity::~AEntity()
    {
    }

    std::string AEntity::getType()
    {
        return _type;
    }

    void AEntity::setDirection(std::size_t direction)
    {
        _direction = direction;
    }

    std::size_t AEntity::getDirection()
    {
        return _direction;
    }

    void AEntity::setRotation(float angle)
    {
    }

    char AEntity::getSymbol()
    {
        return _symbol;
    }

    std::string AEntity::getTexturePath()
    {
        return _texturePath;
    }

    float AEntity::getRotation()
    {
        return _angle;
    }

    void AEntity::setText(std::string text)
    {
        _text = text;
    }

    std::string AEntity::getText()
    {
        return _text;
    }


    void AEntity::setType(std::string type)
    {
        _type = type;
    }

    void AEntity::setSymbol(char symbol)
    {
        _symbol = symbol;
    }
}
