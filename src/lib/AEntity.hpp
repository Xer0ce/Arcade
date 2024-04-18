/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-arcade-louis.huguet
** File description:
** AEntity
*/

#pragma once

#include "IEntity.hpp"

namespace Graphic {
    class AEntity : public IEntity {
        public:
            AEntity();
            ~AEntity();

            void setType(std::string type) override;
            std::string getType() override;
            void setDirection(std::size_t direction) override;
            std::size_t getDirection() override;
            void setRotation(float angle) override;
            char getSymbol() override;
            std::string getTexturePath() override;
            float getRotation() override;
            void setSymbol(char symbol) override;
            void setText(std::string text) override;
            std::string getText() override;

        protected:
            std::string _type;
            std::string _texturePath;
            std::pair<float, float> _position;
            std::string _text;
            std::size_t _direction;
            float _angle;
            char _symbol;
    };
}
