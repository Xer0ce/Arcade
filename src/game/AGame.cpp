/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGame
*/

#include "AGame.hpp"

namespace Game {
    AGame::AGame(Graphic::IDisplay *display)
    {
        _display = display;
    }

    AGame::~AGame() {}

    void AGame::finishGame()
    {
    }

    void AGame::setScore(std::size_t score)
    {
        _score = score;
    }

    std::size_t AGame::getScore()
    {
        return _score;
    }

    void AGame::setLife(std::size_t life)
    {
        _life = life;
    }

    std::size_t AGame::getLife()
    {
        return _life;
    }

    void AGame::setMap(std::vector<std::string> map)
    {
        _map = map;
    }

    std::vector<std::string> AGame::getMap()
    {
        return _map;
    }

    void AGame::setPlayerName(std::string playerName)
    {
        _playerName = playerName;
    }

    std::string AGame::getPlayerName()
    {
        return _playerName;
    }

    void AGame::setGameName(std::string gameName)
    {
        _gameName = gameName;
    }

    void AGame::setMapPath(std::string mapPath)
    {
        _mapPath = mapPath;
    }

    std::string AGame::getMapPath()
    {
        return _mapPath;
    }

    std::string AGame::getGameName()
    {
        return _gameName;
    }

    std::vector<Graphic::IEntity *> AGame::getEntity()
    {
        return _display->getEntity();
    }

    void AGame::setEntity(std::vector<InfoEntity> entity)
    {
        _prevEntity = entity;
    }

    bool AGame::createEntityWithPrev()
    {
        if (!_prevEntity.empty()) {
            for (auto it : _prevEntity) {
                _display->createEntity(it.type, it.position.first, it.position.second, it.texturePath, it.symbol);

                auto entity = _display->getEntity().back();
                entity->setDirection(it.direction);
                entity->setRotation(it.angle);
            }

            return true;
        }
        return false;
    }
}
