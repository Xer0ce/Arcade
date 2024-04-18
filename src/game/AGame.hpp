/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGame
*/

#pragma once

#include "IGame.hpp"
#include "../lib/IDisplay.hpp"

namespace Game {
    class AGame : public IGame {
        public:
            AGame(Graphic::IDisplay *display);
            ~AGame();

            void finishGame() override;

            void setScore(std::size_t score) override;
            std::size_t getScore() override;

            void setLife(std::size_t life) override;
            std::size_t getLife() override;

            void setMap(std::vector<std::string> map) override;
            std::vector<std::string> getMap() override;

            void setMapPath(std::string mapPath) override;
            std::string getMapPath() override;

            void setPlayerName(std::string playerName) override;
            std::string getPlayerName() override;

            void setGameName(std::string gameName) override;
            std::string getGameName() override;

            std::vector<Graphic::IEntity *> getEntity() override;
            void setEntity(std::vector<InfoEntity> entity) override;

            bool createEntityWithPrev();

        protected:
            std::string _gameName;
            std::string _playerName;
            std::string _mapPath;

            std::size_t _score;
            std::size_t _input;

            std::vector<InfoEntity> _prevEntity;

            std::size_t _life;
            std::vector<std::string> _map;
            Graphic::IDisplay *_display;
    };
}
