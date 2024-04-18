/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#include "Menu.hpp"

namespace Game {
    Menu::Menu(Graphic::IDisplay *display) : AGame(display)
    {
        if (!display) {
            std::cerr << "Display is null" << std::endl;
            exit(84);
        }
    }

    Menu::~Menu()
    {
    }

    void Menu::displayEntity()
    {
        for (auto entityPtr : _display->getEntity()) {
            _display->displayEntity(entityPtr);
        }
    }

    void Menu::MoveEntity()
    {
        for (auto entityPtr : _display->getEntity()) {
            switch (_input)
            {
                case 1:
                    if (entityPtr->getType() == "arrow")
                        if (entityPtr->getPosition().second == 10) {
                            entityPtr->setPosition(entityPtr->getPosition().first, (entityPtr->getPosition().second - 1));
                            break;
                        }
                        if (entityPtr->getPosition().second == 13) {
                            entityPtr->setPosition(entityPtr->getPosition().first, (entityPtr->getPosition().second - 3));
                            break;
                        }
                    break;
                case 3:
                    if (entityPtr->getType() == "arrow")
                        if (entityPtr->getPosition().second == 9) {
                            entityPtr->setPosition(entityPtr->getPosition().first, (entityPtr->getPosition().second + 1));
                            break;
                        }
                        if (entityPtr->getPosition().second == 10) {
                            entityPtr->setPosition(entityPtr->getPosition().first, (entityPtr->getPosition().second + 3));
                            break;
                        }
                    break;
                case 6:
                    if (entityPtr->getType() == "arrow") {
                        if (entityPtr->getPosition().second == 13) {
                            _life = 0;
                            return;
                        }
                        if (entityPtr->getPosition().second == 9) {
                            _gameName = "./lib/arcade_pacman.so";
                            _mapPath = "./map/map_pacman";
                        }
                        if (entityPtr->getPosition().second == 10) {
                            _gameName = "./lib/arcade_snake.so";
                            _mapPath = "./map/map_snake";
                        }
                    }
                    break;

                default:
                    break;
                }
        }
        _input = 0;
    }

    void Menu::createEntities()
    {
        _display->createEntity("arrow", 10, 9, "", '>');
        _display->createEntity("textbox", 5, 8, "", 't');
    }

    std::size_t Menu::startGame()
    {
        _display->initWindow(0, 0);
        _display->setMap(_map);
        createEntities();
        _life = 1;

        while (_life != 0)
        {
            _display->clearWindow();

            _display->displayMap();
            
            displayEntity();
            
            _input = _display->getInput();

            MoveEntity();

            _display->displayWindow();
        }

        _display->closeWindow(1);
        return 0;
    }
}
