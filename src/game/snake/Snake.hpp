/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#pragma once

#include <random>
#include "../AGame.hpp"

namespace Game {
    class Snake : public AGame {
        public:
            Snake(Graphic::IDisplay *display);
            ~Snake();

            void initSnake();
            std::size_t closeWindow();
            void changeDirection();
            void move();
            void checkAppleCollision();
            void displayEntity();
            std::size_t startGame() override;
            int generateRandomNumber();
            void setScoreLife();

            void checkLoose();
    };
}

extern "C" {
    Game::IGame* createInstance(Graphic::IDisplay *display) {
        return new Game::Snake(display);
    }
}
