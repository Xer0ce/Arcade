/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-arcade-louis.huguet
** File description:
** Entity
*/

#pragma once

#include "../AEntity.hpp"

class EntityNcurses : public Graphic::AEntity {
    public:
        EntityNcurses(std::string type, float x, float y, std::string texturePath, char symbol);
        ~EntityNcurses();

        virtual void setTexture(std::string &path) override;
        virtual void setPosition(float x, float y) override;
        virtual std::pair<float, float> getPosition() override;
        virtual void setSize(float x, float y) override;
        char getSymbol();
    private:
        char _symbol;
};
