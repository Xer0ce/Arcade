/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"

namespace Game {
    Pacman::Pacman(Graphic::IDisplay *display)
        : AGame(display)
    {
        _life = 3;
        _score = 0;
    }

    Pacman::~Pacman()
    {
    }

    void Pacman::createSmallPacgums()
    {
        for (std::size_t i = 0; i < 27; i++) {
            for (std::size_t j = 0; j < 21; j++) {
                if (_map[i][j] == ';') {
                    _display->createEntity("smallpacgum", j, i, "assets/pacman/buble.png", '.');
                }
            }
        }
    }

    bool Pacman::isWall(std::pair <float, float> newpos)
    {
        switch (_map[newpos.second][newpos.first]) {
            case '-':
                return (true);
            case '|':
                return (true);
            case '5':
                return (true);
            case '6':
                return (true);
            case '7':
                return (true);
            case '8':
                return (true);
        }
        return (false);
    }


    bool Pacman::isIntersec(std::pair <float, float> newpos, std::size_t direction)
    {
        if (_map[newpos.second][newpos.first] == ';') {
                if (direction == 1 || direction == 3) {
                    if (_map[newpos.second][newpos.first - 1] == ';' || _map[newpos.second][newpos.first + 1] == ';')
                        return (true);
                }
                if (direction == 2 || direction == 4) {
                    if (_map[newpos.second - 1][newpos.first] == ';' || _map[newpos.second + 1][newpos.first] == ';')
                        return (true);
                }
        }
        if (_map[newpos.second][newpos.first] == ' ') {
                if (direction == 1 || direction == 3) {
                    if (_map[newpos.second][newpos.first - 1] == ' ' || _map[newpos.second][newpos.first + 1] == ' ')
                        return (true);
                }
                if (direction == 2 || direction == 4) {
                    if (_map[newpos.second - 1][newpos.first] == ' ' || _map[newpos.second + 1][newpos.first] == ' ')
                        return (true);
                }
        }
        return (false);
    }

    std::pair<float, float> Pacman::setNewPosGhost(std::pair<float, float> newPos, Graphic::IEntity *entity)
    {
        if (entity->getDirection() == 1) {
            newPos = std::make_pair(entity->getPosition().first, entity->getPosition().second - 1);
        } else if (entity->getDirection() == 2) {
            newPos = std::make_pair(entity->getPosition().first + 1, entity->getPosition().second);
        } else if (entity->getDirection() == 3) {
            newPos = std::make_pair(entity->getPosition().first, entity->getPosition().second + 1);
        } else if (entity->getDirection() == 4) {
            newPos = std::make_pair(entity->getPosition().first - 1, entity->getPosition().second);
        }
        return (newPos);
    }

    void Pacman::moveGhost()
    {
        for (auto entity : _display->getEntity()) {
            if (entity->getType() == "ghost") {
                std::pair <float, float> prevPos, newPos;

                prevPos = entity->getPosition();
                newPos = setNewPosGhost(newPos, entity);
                if (!isWall(newPos)) {
                    entity->setPosition(newPos.first, newPos.second);
                    if (isIntersec(newPos, entity->getDirection())) {
                        std::size_t random_number = rand() % 4 + 1;
                        entity->setDirection(random_number);
                    }
                } else {
                    std::size_t random_number = rand() % 4 + 1;

                    entity->setDirection(random_number);
                }
            }
        }
    }

    void Pacman::checkColision(Graphic::IEntity *entity, Graphic::IEntity *entity2)
    {
        if (_display->getCollision(*entity, *entity2)) {
            if (_canEat) {
                _score += 100;
                std::string text = "assets/pacman/eyeGhost.png";
                entity2->setTexture(text);
                entity2->setSymbol('e');
                entity2->setType("eye");
            } else {
                _life -= 1;
                if (_life != 0) {
                    entity->setPosition(10, 20);
                }
            }
        }
    }

    void Pacman::checkLose()
    {
        for (auto entity : _display->getEntity()) {
            if (entity->getType() == "pacman") {
                for (auto entity2 : _display->getEntity()) {
                    if (entity2->getType() == "ghost") {
                        checkColision(entity, entity2);
                    }
                }
            }
        }
    }

    void Pacman::checkWin()
    {
        std::size_t pacgumNb = 0;
        for (auto entity : _display->getEntity()) {
            if (entity->getType() == "pacgum") {
                pacgumNb++;
            }
            if (entity->getType() == "smallpacgum") {
                pacgumNb++;
            }
        }
        if (pacgumNb == 0) {
            _life = 0;
        }
    }

    std::pair <float, float> Pacman::moveEyePos(std::pair <float, float> position, Graphic::IEntity *entity)
    {
        if (position.first != 11 || position.second != 10) {
            if (position.first < 11) {
                position.first++;
            } else if (position.first > 11) {
                position.first--;
            }
            if (position.second < 10) {
                position.second++;
            } else if (position.second > 10) {
                position.second--;
            }
            entity->setPosition(position.first, position.second);
        }
        return (position);
    }

    void Pacman::transformGhost(std::pair <float, float> position, Graphic::IEntity *entity)
    {
        if (position.first == 11 && position.second == 10) {
            std::size_t randNb = rand() % 4 + 1;
            entity->setType("ghost");
            entity->setSymbol('G');
            std::string text = "assets/pacman/greenGhost.png";
            if (randNb == 1)
                text = "assets/pacman/blueGhost.png";
            if (randNb == 2)
                text = "assets/pacman/greenGhost.png";
            if (randNb == 3)
                text = "assets/pacman/redGhost.png";
            if (randNb == 4)
                text = "assets/pacman/pinkGhost.png";
            entity->setTexture(text);
        }
    }

    void Pacman::moveEye()
    {
        for (auto entity : _display->getEntity()) {
            if (entity->getType() == "eye") {
                std::pair <float, float> position = entity->getPosition();
                position = moveEyePos(position, entity);
                transformGhost(position, entity);
            }
        }
    }

    void Pacman::setScoreLife()
    {
        for (auto entity : _display->getEntity()) {
            if (entity->getType() == "text") {
                entity->setText("Score: " + std::to_string(_score) + " Life: " + std::to_string(_life));
            }
        }
    }

    void Pacman::createEntity()
    {
        if (!createEntityWithPrev()) {
            createSmallPacgums();
            _display->createEntity("pacman", 10, 20, "assets/pacman/pacman.png", 'P');
            _display->getEntity().back()->setDirection(0);
            _display->createEntity("ghost", 11, 12, "assets/pacman/blueGhost.png", 'G');
            _display->createEntity("ghost", 11, 12, "assets/pacman/greenGhost.png", 'G');
            _display->createEntity("ghost", 11, 12, "assets/pacman/redGhost.png", 'G');
            _display->createEntity("ghost", 11, 12, "assets/pacman/pinkGhost.png", 'G');
            _display->createEntity("pacgum", 1, 20, "assets/pacman/specialGum.png", 'O');
            _display->createEntity("pacgum", 1, 3, "assets/pacman/specialGum.png", 'O');
            _display->createEntity("pacgum", 19, 3, "assets/pacman/specialGum.png", 'O');
            _display->createEntity("pacgum", 19, 20, "assets/pacman/specialGum.png", 'O');
            _display->createEntity("text", 0, 0, "", 'T');
            _display->createEntity("portal", 0, 13, "", ' ');
            _display->createEntity("portal", 20, 13, "", ' ');
        }
    }

    std::size_t Pacman::startGame()
    {
        _display->setMap(_map);
        _display->setGameName("Pacman");
        _display->initWindow(21, 27);
        _display->parseMap();
        _canEat = false;
        _timeCanEat = 0.0f;
        _gameTimer = 0.0f;
        _isSpawned = false;
        srand(time(0));

        createEntity();

        while (_life != 0) {
            if (_life == 0) {
                _display->closeWindow(1);
                break;
            }
            if (_display->closeWindow(0) == true)
                _life = 0;

            _display->clearWindow();
            _display->displayMap();

            setScoreLife();
            for (auto entity : _display->getEntity()) {
                _display->displayEntity(entity);
            }

            _input = _display->getInput();

            if (_input == 100) {
                _display->closeWindow(1);
                return 100;
            } else if (_input == 101) {
                _display->closeWindow(1);
                return 101;
            } else if (_input == 102) {
                _display->closeWindow(1);
                return 0;
            } else if (_input == 103) {
                _display->closeWindow(1);
                return 103;
            }

            if (_canEat && (_gameTimer - _timeCanEat) > 1000.0f) {
                _canEat = false;
                for (auto entity : _display->getEntity()) {
                    if (entity->getType() == "ghost") {
                        std::size_t randNb = rand() % 4 + 1;
                        entity->setType("ghost");
                        entity->setSymbol('G');
                        std::string text = "assets/pacman/greenGhost.png";
                        if (randNb == 1)
                            text = "assets/pacman/blueGhost.png";
                        if (randNb == 2)
                            text = "assets/pacman/greenGhost.png";
                        if (randNb == 3)
                            text = "assets/pacman/redGhost.png";
                        if (randNb == 4)
                            text = "assets/pacman/pinkGhost.png";
                        entity->setTexture(text);
                        entity->setSymbol('G');
                    }
                }
            }

            for (auto entity : _display->getEntity()) {
                if (entity->getType() == "pacman") {
                    if (_input == 1) {
                        entity->setRotation(270);
                        entity->setDirection(1);
                    }
                    if (_input == 2) {
                        entity->setRotation(0);
                        entity->setDirection(2);
                    }
                    if (_input == 3) {
                        entity->setRotation(90);
                        entity->setDirection(3);
                    }
                    if (_input == 4) {
                        entity->setRotation(180);
                        entity->setDirection(4);
                    }
                }
            }

            _gameTimer += _display->getElapsedTime();

            if (!_isSpawned && _gameTimer > 1000.0f) {
                for (auto entity : _display->getEntity()) {
                    if (entity->getType() == "ghost" && entity->getPosition().second > 2) {
                        std::pair<float, float> pos = entity->getPosition();
                        entity->setPosition(pos.first, 10);
                        _isSpawned = true;
                    }
                }
            }

            if (_display->getElapsedTime() > 0.15) {
                std::pair <float, float> prevPos, newPos;
                for (auto entity : _display->getEntity()) {
                    if (entity->getType() == "pacman") {
                        prevPos = entity->getPosition();
                        if (entity->getDirection() == 1) {
                            newPos = std::make_pair(entity->getPosition().first, entity->getPosition().second - 1);
                        } else if (entity->getDirection() == 2) {
                            newPos = std::make_pair(entity->getPosition().first + 1, entity->getPosition().second);
                        } else if (entity->getDirection() == 3) {
                            newPos = std::make_pair(entity->getPosition().first, entity->getPosition().second + 1);
                        } else if (entity->getDirection() == 4) {
                            newPos = std::make_pair(entity->getPosition().first - 1, entity->getPosition().second);
                        }
                        if (!isWall(newPos)) {
                            entity->setPosition(newPos.first, newPos.second);
                        }
                    }
                }

                for (auto entity : _display->getEntity()) {
                    if (entity->getType() == "pacman") {
                        for (auto entity2 : _display->getEntity()) {
                            if (entity2->getType() == "smallpacgum" && _display->getCollision(*entity, *entity2)) {
                                _score += 1;
                                _display->removeEntity(entity2);
                            }
                            if (entity2->getType() == "pacgum" && _display->getCollision(*entity, *entity2)) {
                                _score += 10;
                                _canEat = true;
                                _display->removeEntity(entity2);
                                _timeCanEat = _gameTimer;
                                for (auto entity : _display->getEntity()) {
                                    if (entity->getType() == "ghost") {
                                        std::string text = "assets/pacman/eatGhost.png";
                                        entity->setTexture(text);
                                    }
                                }
                            }
                            if (entity2->getType() == "portal" && _display->getCollision(*entity, *entity2)) {
                                if (entity2->getPosition().first == 0) {
                                    entity->setPosition(19, 13);
                                } else {
                                    entity->setPosition(1, 13);
                                }
                            }
                        }
                    }
                }

                checkLose();
                moveGhost();
                moveEye();
                checkWin();
                _input = 0;
                _display->resetClock();
            }
            _display->displayWindow();
        }
        return 0;
    }
}
