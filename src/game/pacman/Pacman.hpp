/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#pragma once

#include "../AGame.hpp"
#include <cstdlib>
#include <ctime>

namespace Game {
    class Pacman : public AGame {
        public:
            Pacman(Graphic::IDisplay *display);
            ~Pacman();

            std::size_t startGame() override;
            void createSmallPacgums();
            bool isWall(std::pair <float, float> newpos);
            bool isIntersec(std::pair <float, float> newpos, std::size_t direction);
            std::pair <float, float> moveEyePos(std::pair <float, float> position, Graphic::IEntity *entity);
            void transformGhost(std::pair <float, float> position, Graphic::IEntity *entity);
            std::pair <float, float> setNewPosGhost(std::pair<float, float> newPos, Graphic::IEntity *entity);
            void checkColision(Graphic::IEntity *entity, Graphic::IEntity *entity2);
            void moveGhost();
            void movePlayer();
            void checkLose();
            void checkWin();
            void killGhost();
            void moveEye();
            void setScoreLife();
            void createEntity();

        private: 
            bool _canEat;
            bool _isSpawned;
            float _timeCanEat;
            float _gameTimer;
    };
}

extern "C" {
    Game::IGame* createInstance(Graphic::IDisplay *display) {
        return new Game::Pacman(display);
    }
}
