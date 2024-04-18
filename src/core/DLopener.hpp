/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLopener
*/

#pragma once

#include <dlfcn.h>
#include "../game/IGame.hpp"
#include "../lib/IDisplay.hpp"

namespace Core {
    class DLopener {
        public:
            DLopener();
            ~DLopener();

            void loadLib(std::size_t type, Graphic::IDisplay *display);
            void clearLib();

            void setLib(std::string libName);

            Game::IGame *getGame();
            Graphic::IDisplay *getDisplay();

        private:

            void *_handleGame;
            void *_handleLib;

            std::string _libName;

            std::unique_ptr<Game::IGame> _game;
            std::unique_ptr<Graphic::IDisplay> _display;
    };
}
