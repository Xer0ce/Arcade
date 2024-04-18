/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-arcade-louis.huguet
** File description:
** IEntity
*/

#pragma once

#include <iostream>
#include <memory>

namespace Graphic {
    class IEntity {
        public:
            IEntity() = default;
            ~IEntity() = default;

            virtual void setType(std::string type) = 0;
            virtual std::string getType() = 0;
            virtual void setDirection(std::size_t direction) = 0;
            virtual std::size_t getDirection() = 0;

            virtual void setTexture(std::string &path) = 0;
            virtual void setPosition(float x, float y) = 0;
            virtual std::pair<float, float> getPosition() = 0;
            virtual void setSize(float x, float y) = 0;
            virtual void setText(std::string text) = 0;
            virtual std::string getText() = 0;

            virtual void setRotation(float angle) = 0;
            virtual char getSymbol() = 0;
            virtual void setSymbol(char symbol) = 0;
            virtual std::string getTexturePath() = 0;
            virtual float getRotation() = 0;
    };
}
