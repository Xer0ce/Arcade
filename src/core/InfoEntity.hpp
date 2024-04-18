/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** infoEntity
*/

#pragma once

#include <string>

struct InfoEntity {
    std::string type;
    std::string texturePath;
    std::pair<float, float> position;
    std::size_t direction;
    float angle;
    char symbol;
};