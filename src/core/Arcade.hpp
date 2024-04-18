/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#pragma once

#include <iostream>
#include <memory>
#include <dlfcn.h>
#include <fstream>
#include "../game/IGame.hpp"
#include "../lib/IDisplay.hpp"
#include "DLopener.hpp"
#include "InfoEntity.hpp"

namespace Core {
    class Arcade {
        public:
            Arcade(std::string libName);
            ~Arcade();

            bool start();
            bool startMenu();
            bool startGame();
            void reloadToMenu();
            void openMap(std::string path);

        private:
            std::string _gameName;
            std::string _playerName;
            std::string _mapPath;

            std::string _libName;

            std::unique_ptr<DLopener> _dlOpenerGame;
            std::unique_ptr<DLopener> _dlOpenerLib;

            std::vector<std::pair<std::string, std::string>> _listGame;
            std::vector<std::string> _listLib;
    };
}
