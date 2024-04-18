/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"

namespace Game {
    Snake::Snake(Graphic::IDisplay *display) : AGame(display)
    {
        _life = 1;
        _score = 0;
    }

    Snake::~Snake()
    {
    }

    void Snake::setScoreLife()
    {
        for (auto entity : _display->getEntity()) {
            if (entity->getType() == "text") {
                entity->setText("Score: " + std::to_string(_score));
            }
        }
    }

    void Snake::initSnake()
    {
        _display->setGameName("Snake");
        _display->setMap(_map);
        _display->initWindow(30, 30);
        _display->parseMap();

        if (!createEntityWithPrev()) {
            _display->createEntity("head", 7, 10, "assets/snake/head.png", 'P');
            _display->createEntity("apple", 15, 10, "assets/snake/apple.png", '@');
            _display->createEntity("body", 6, 10, "assets/snake/body.png", 'O');
            _display->createEntity("body", 5, 10, "assets/snake/body.png", 'O');
            _display->createEntity("text", 0, 0, "", 'T');
        }
    }

    std::size_t Snake::closeWindow()
    {
        if (_life == 0) {
            _display->closeWindow(1);
            return 0;
        }
        if (_display->closeWindow(0) == true)
            _life = 0;
        return 1;
    }

    void Snake::changeDirection()
    {
        for (auto entity : _display->getEntity()) {
            if (entity->getType() == "head") {
                if (_input == 1 && entity->getDirection() != 3) {
                    entity->setRotation(270);
                    entity->setDirection(1);
                }
                if (_input == 2 && entity->getDirection() != 4) {
                    entity->setRotation(0);
                    entity->setDirection(2);
                }
                if (_input == 3 && entity->getDirection() != 1) {
                    entity->setRotation(90);
                    entity->setDirection(3);
                }
                if (_input == 4 && entity->getDirection() != 2) {
                    entity->setRotation(180);
                    entity->setDirection(4);
                }
            }
        }
    }

    void Snake::move()
    {
        if (_display->getElapsedTime() > 0.15) {
            std::pair <float, float> prevPos, newPos;
            std::size_t prevDirection, newDirection;
            for (auto entity : _display->getEntity()) {
                if (entity->getType() == "head") {
                    prevPos = entity->getPosition();
                    prevDirection = entity->getDirection();
                    if (entity->getDirection() == 1) {
                        newPos = std::make_pair(entity->getPosition().first, entity->getPosition().second - 1);
                    } else if (entity->getDirection() == 2) {
                        newPos = std::make_pair(entity->getPosition().first + 1, entity->getPosition().second);
                    } else if (entity->getDirection() == 3) {
                        newPos = std::make_pair(entity->getPosition().first, entity->getPosition().second + 1);
                    } else if (entity->getDirection() == 4) {
                        newPos = std::make_pair(entity->getPosition().first - 1, entity->getPosition().second);
                    }
                    entity->setPosition(newPos.first, newPos.second);
                } else if (entity->getType() == "body") {
                    newPos = prevPos;
                    newDirection = prevDirection;
                    prevPos = entity->getPosition();
                    prevDirection = entity->getDirection();
                    entity->setPosition(newPos.first, newPos.second);
                    entity->setDirection(newDirection);
                    if (newDirection == 1) {
                        entity->setRotation(270);
                    } else if (newDirection == 2) {
                        entity->setRotation(0);
                    } else if (newDirection == 3) {
                        entity->setRotation(90);
                    } else if (newDirection == 4) {
                        entity->setRotation(180);
                    }
                }
            }
            _display->resetClock();
        }
    }

    void Snake::checkAppleCollision()
    {
        auto head = _display->getEntity()[0];
        auto apple = _display->getEntity()[1];
        if (_display->getCollision(*head, *apple)) {
            _display->createEntity("body", _display->getEntity().back()->getPosition().first, _display->getEntity().back()->getPosition().second, "assets/snake/body.png", 'O');
            apple->setPosition(generateRandomNumber(), generateRandomNumber());
            _score += 1;
        }
    }

    void Snake::displayEntity()
    {
        for (auto entity : _display->getEntity()) {
            _display->displayEntity(entity);
        }
    }

    std::size_t Snake::startGame()
    {
        initSnake();
        while (_life != 0) {
            if (closeWindow() == 0)
                return 0;

            _display->clearWindow();

            _display->displayMap();
            setScoreLife();

            displayEntity();

            _input = _display->getInput();

            // Check input for change lib, game and exit
            if (_input == 100) { // Key::L
                _display->closeWindow(1);
                return 100;
            } else if (_input == 101) { // Key::G
                _display->closeWindow(1);
                return 101;
            } else if (_input == 102) { // Key::E
                _display->closeWindow(1);
                return 0;
            } else if (_input == 103) { // Key::M
                _display->closeWindow(1);
                return 103;
            }

            changeDirection();
            move();

            checkAppleCollision();
            checkLoose();

            _display->displayWindow();
        }
        return 0;
    }

    int Snake::generateRandomNumber()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(2, 28);
        return distrib(gen);
    }

    void Snake::checkLoose()
    {
        auto head = _display->getEntity()[0];
        for (auto entity : _display->getEntity()) {
            if (entity->getType() == "body") {
                if (_display->getCollision(*head, *entity)) {
                    _display->closeWindow(1);
                    _life = 0;
                }
            }
        }
        if (head->getPosition().first < 1 || head->getPosition().first > 28 || head->getPosition().second < 1 || head->getPosition().second > 28) {
            _display->closeWindow(1);
            _life = 0;
        }
    }
}
