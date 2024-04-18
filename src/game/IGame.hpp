/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGame
*/

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "../lib/IEntity.hpp"
#include "../core/InfoEntity.hpp"

namespace Game {
    class IGame {
        public:
            IGame() = default;
            ~IGame() = default;

            virtual std::size_t startGame() = 0;
            virtual void finishGame() = 0;

            virtual void setScore(std::size_t score) = 0;
            virtual std::size_t getScore() = 0;

            virtual void setLife(std::size_t life) = 0;
            virtual std::size_t getLife() = 0;

            virtual void setMap(std::vector<std::string> map) = 0;
            virtual std::vector<std::string> getMap() = 0;

            virtual void setMapPath(std::string mapPath) = 0;
            virtual std::string getMapPath() = 0;

            virtual void setPlayerName(std::string playerName) = 0;
            virtual std::string getPlayerName() = 0;

            virtual void setGameName(std::string gameName) = 0;
            virtual std::string getGameName() = 0;

            virtual std::vector<Graphic::IEntity *> getEntity() = 0;
            virtual void setEntity(std::vector<InfoEntity> entity) = 0;
    };
}
