/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** EntitySDL
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include "../AEntity.hpp"

class EntitySDL : public Graphic::AEntity {
    public:
        EntitySDL(std::string type, float x, float y, std::string texturePath, char symbol, SDL_Renderer *renderer);
        ~EntitySDL();

        void setTexture(std::string &path) override;
        void setPosition(float x, float y) override;
        std::pair<float, float> getPosition() override;
        void setSize(float x, float y) override;
        void setRotation(float angle) override;

        SDL_Texture* getTexture();
        SDL_Rect *getRect();
        float getAngle() { return _angle; }

    private:
        SDL_Renderer *_renderer;
        SDL_Rect *_rect;
        SDL_Texture* _texture = nullptr;
};