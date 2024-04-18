/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ADisplay
*/

#include "ADisplay.hpp"

namespace Graphic {
    ADisplay::ADisplay()
    {
    }

    ADisplay::~ADisplay()
    {
    }

    void ADisplay::setGameName(std::string name)
    {
        _gameName = name;
    }

    int ADisplay::generateRandomNumber()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(2, 17);
        return distrib(gen);
    }

    void ADisplay::parseMap()
    {
    }

    std::vector<IEntity *> ADisplay::getEntity()
    {
        return _entity;
    }

    bool ADisplay::closeWindow(int type)
    {
        return true;
    }

    float ADisplay::getElapsedTime()
    {
        return 0;
    }

    void ADisplay::resetClock()
    {
    }

    void ADisplay::removeEntity(IEntity *entity)
    {
        _entity.erase(std::remove(_entity.begin(), _entity.end(), entity), _entity.end());
    }
}
