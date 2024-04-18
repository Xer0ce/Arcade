/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL
*/

#pragma once

#include <SDL2/SDL.h>
#include <algorithm>
#include <SDL2/SDL_ttf.h>
#include "EntitySDL.hpp"
#include "../ADisplay.hpp"

namespace Graphic {
    class SDL : public ADisplay {
        public:
            SDL();
            ~SDL();

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
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            SDL_Event _event;
            Uint32 _start_time;

            std::vector<IEntity *> _rectangleMap;
    };
}

extern "C" {
    Graphic::IDisplay* createInstance() {
        return new Graphic::SDL();
    }
}

