/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#pragma once

#include "Entity.hpp"
#include "../ADisplay.hpp"
#include <ncurses.h>
#include <cctype>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>

namespace Graphic {
    class NCurses : public ADisplay {
        public:
            NCurses();
            ~NCurses();

            void initWindow(float x, float y) override;

            void createEntity(std::string type, float x, float y, std::string path, char symbol) override;

            void setMap(std::vector<std::string> map) override;

            void displayMap() override;

            void displayEntity(IEntity *entity) override;

            std::size_t getInput() override;

            void clearWindow() override;

            void displayWindow() override;

            bool getCollision(IEntity &entity1, IEntity &entity2) override;

            bool closeWindow(int type) override;

            void removeEntity(IEntity* entity) override;

            float getElapsedTime() override;

            void resetClock() override;

        private:
            std::chrono::time_point<std::chrono::steady_clock> start;
    };
}

extern "C" {
    Graphic::IDisplay* createInstance() {
        return new Graphic::NCurses();
    }
}