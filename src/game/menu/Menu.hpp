/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#pragma once

#include "../AGame.hpp"

namespace Game {
    class Menu : public AGame {
        public:
            Menu(Graphic::IDisplay *display);
            ~Menu();

            std::size_t startGame() override;
            void displayEntity();
            void MoveEntity();
            void endGame();
            void createEntities();
    };
}

extern "C" {
    Game::IGame* createInstance(Graphic::IDisplay *display) {
        return new Game::Menu(display);
    }
}
