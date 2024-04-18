/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IDisplay
*/

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "IEntity.hpp"

namespace Graphic {
    class IDisplay {
        public:
            IDisplay() = default;
            ~IDisplay() = default;

            virtual void setGameName(std::string name) = 0;

            virtual void initWindow(float x, float y) = 0;

            virtual void createEntity(std::string type, float x, float y, std::string path, char symbol) = 0;

            virtual void setMap(std::vector<std::string> map) = 0;

            virtual bool closeWindow(int type) = 0;

            virtual void clearWindow() = 0;

            virtual void displayWindow() = 0;

            virtual std::vector<IEntity *> getEntity() = 0;

            virtual std::size_t getInput() = 0;

            virtual void parseMap() = 0;

            virtual void displayMap() = 0;

            virtual void displayEntity(IEntity *entity) = 0;

            virtual bool getCollision(IEntity &entity1, IEntity &entity2) = 0;

            virtual float getElapsedTime() = 0;

            virtual void removeEntity(IEntity *entity) = 0;

            virtual void resetClock() = 0;

        protected:
    };
}
