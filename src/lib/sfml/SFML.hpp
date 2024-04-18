/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SFML
*/

#pragma once

#include <cmath>
#include <random>
#include "../ADisplay.hpp"
#include "RectangleShape.hpp"
#include "Sprite.hpp"

namespace Graphic {
    class SFML : public ADisplay {
        public:
            SFML();
            ~SFML();

            void initWindow(float x, float y) override;

            void createEntity(std::string type, float x, float y, std::string path, char symbol) override;

            void setMap(std::vector<std::string> map) override;

            void clearWindow() override;

            void displayWindow() override;

            std::size_t getInput() override;

            void parseMap() override;

            void displayMap() override;

            void displayEntity(IEntity *entity) override;

            bool getCollision(IEntity &entity1, IEntity &entity2) override;

            bool closeWindow(int type) override;

            float getElapsedTime() override;

            void resetClock() override;

            void removeEntity(IEntity *entity) override;

        private:
            sf::RenderWindow _window;
            std::vector<RectangleShape> _rectangleMap;
            sf::Event _event;
            sf::Clock _time;
            bool _isPressed;
    };
}

extern "C" {
    Graphic::IDisplay* createInstance() {
        return new Graphic::SFML();
    }
}
