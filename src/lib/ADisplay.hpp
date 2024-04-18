/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ADisplay
*/

#pragma once

#include <random>
#include <algorithm>
#include "IDisplay.hpp"

namespace Graphic {
    class ADisplay : public IDisplay {
        public:
            ADisplay();
            ~ADisplay();

            void setGameName(std::string name) override;

            int generateRandomNumber();
            void parseMap() override;
            std::vector<IEntity *> getEntity() override;

            bool closeWindow(int type) override;
            float getElapsedTime() override;
            void resetClock() override;
            void removeEntity(IEntity *entity) override;

        protected:
            std::string _nameWindow;
            std::string _nameLib;
            std::string _playerName;
            std::string _gameName;

            std::string _mapPath;
            std::size_t _score;

            std::size_t _life;
            std::size_t _direction;

            std::vector<IEntity *> _entity;

            std::vector<std::string> _map;
    };
}
