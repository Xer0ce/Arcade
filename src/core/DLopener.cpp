/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLopener
*/

#include "DLopener.hpp"

namespace Core {
    DLopener::DLopener()
        : _handleGame(nullptr), _handleLib(nullptr)
    {
    }

    DLopener::~DLopener()
    {
        clearLib();
        if (_game)
            _game.reset();
        if (_display)
            _display.reset();
    }

    void DLopener::loadLib(std::size_t type, Graphic::IDisplay *display)
    {
        if (type == 0)
            _handleGame = dlopen(_libName.c_str(), RTLD_LAZY);
        else
            _handleLib = dlopen(_libName.c_str(), RTLD_LAZY);

        if (type == 0 && !_handleGame) {
            std::cerr << "Impossible d'ouvrir la librairie : " << dlerror() << std::endl;
            exit(84);
        } else if (type == 1 && !_handleLib) {
            std::cerr << "Impossible d'ouvrir la librairie : " << dlerror() << std::endl;
            exit(84);
        }

        Game::IGame* (*createInstanceGame)(Graphic::IDisplay *) = nullptr;
        Graphic::IDisplay* (*createInstanceDisplay)() = nullptr;

        if (type == 0)
            createInstanceGame = (Game::IGame* (*)(Graphic::IDisplay *))dlsym(_handleGame, "createInstance");
        else
            createInstanceDisplay = (Graphic::IDisplay* (*)())dlsym(_handleLib, "createInstance");

        if ((!createInstanceDisplay && type == 1 ) || (!createInstanceGame && type == 0)) {
            std::cerr << "Impossible de trouver la fonction de création de l'instance : " << dlerror() << std::endl;
            if (type == 0)
                dlclose(_handleGame);
            else
                dlclose(_handleLib);
            exit(84);
        }

        if (type == 0) {
            _game = std::unique_ptr<Game::IGame>(createInstanceGame(display));
        } else
            _display = std::unique_ptr<Graphic::IDisplay>(createInstanceDisplay());
    }

    void DLopener::clearLib() {
        if (_handleGame) {
            dlclose(_handleGame);
            _handleGame = nullptr;
        }
        if (_handleLib) {
            dlclose(_handleLib);
            _handleLib = nullptr;
        }
    }

    void DLopener::setLib(std::string libName)
    {
        _libName = libName;
    }

    Game::IGame* DLopener::getGame()
    {
        return _game.get();
    }

    Graphic::IDisplay* DLopener::getDisplay()
    {
        return _display.get();
    }
}
