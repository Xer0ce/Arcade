/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"

namespace Core {
    Arcade::Arcade(std::string libName)
    {
        _libName = libName;
        _gameName = "lib/arcade_snake.so";
        _mapPath = "map/map_snake";
        _dlOpenerGame = std::make_unique<DLopener>();
        _dlOpenerLib = std::make_unique<DLopener>();

        _listGame.push_back(std::make_pair("./lib/arcade_pacman.so", "./map/map_pacman"));
        _listGame.push_back(std::make_pair("./lib/arcade_snake.so", "./map/map_snake"));

        _listLib.push_back("lib/arcade_sfml.so");
        _listLib.push_back("lib/arcade_ncurses.so");
        _listLib.push_back("lib/arcade_sdl2.so");
    }

    Arcade::~Arcade()
    {
        _dlOpenerGame->clearLib();
        _dlOpenerLib->clearLib();
    }

    bool Arcade::start()
    {
        startMenu();
        return true;
    }

    bool Arcade::startMenu()
    {
        _dlOpenerLib->clearLib();
        _dlOpenerLib->setLib("lib/arcade_ncurses.so");
        _dlOpenerLib->loadLib(1, nullptr);

        _dlOpenerGame->clearLib();
        _dlOpenerGame->setLib("./lib/arcade_menu.so");
        _dlOpenerGame->loadLib(0, _dlOpenerLib->getDisplay());

        openMap("map/map_menu");
        _dlOpenerGame->getGame()->startGame();

        _playerName = _dlOpenerGame->getGame()->getPlayerName();
        _gameName = _dlOpenerGame->getGame()->getGameName();
        _mapPath = _dlOpenerGame->getGame()->getMapPath();

        startGame();

        return true;

    }

    bool Arcade::startGame()
    {
        _dlOpenerLib->clearLib();
        _dlOpenerLib->setLib(_libName);
        _dlOpenerLib->loadLib(1, nullptr);

        _dlOpenerGame->clearLib();
        _dlOpenerGame->setLib(_gameName);
        _dlOpenerGame->loadLib(0, _dlOpenerLib->getDisplay());

        openMap(_mapPath);

        std::size_t retVal = -10;

        while (retVal != 0)  {
            retVal = _dlOpenerGame->getGame()->startGame();
            if (retVal == 100) {
                for (auto lib = _listLib.begin(); lib != _listLib.end(); lib++) {
                    if (*lib == _libName) {
                        lib++;
                        if (lib == _listLib.end())
                            lib = _listLib.begin();

                        _libName = *lib;

                        auto entity = _dlOpenerGame->getGame()->getEntity();

                        std::size_t score = _dlOpenerGame->getGame()->getScore();
                        std::string playerName = _dlOpenerGame->getGame()->getPlayerName();
                        std::size_t life = _dlOpenerGame->getGame()->getLife();
                        std::vector<InfoEntity> infoEntity;

                        for (auto it : entity) {
                            infoEntity.push_back({
                                it->getType(),
                                it->getTexturePath(),
                                it->getPosition(),
                                it->getDirection(),
                                it->getRotation(),
                                it->getSymbol()
                            });
                        }

                        _dlOpenerLib->clearLib();
                        _dlOpenerLib->setLib(_libName);
                        _dlOpenerLib->loadLib(1, nullptr);

                        _dlOpenerGame->clearLib();
                        _dlOpenerGame->setLib(_gameName);
                        _dlOpenerGame->loadLib(0, _dlOpenerLib->getDisplay());

                        openMap(_mapPath);
                        _dlOpenerGame->getGame()->setEntity(infoEntity);
                        _dlOpenerGame->getGame()->setScore(score);
                        _dlOpenerGame->getGame()->setPlayerName(playerName);
                        _dlOpenerGame->getGame()->setLife(life);
                    }
                }
            } else if (retVal == 101) {
                for (auto lib = _listGame.begin(); lib != _listGame.end(); lib++) {
                    if (lib->first == _gameName) {
                        lib++;
                        if (lib == _listGame.end())
                            lib = _listGame.begin();


                        _gameName = lib->first;
                        _mapPath = lib->second;

                        _dlOpenerLib->clearLib();
                        _dlOpenerLib->setLib(_libName);
                        _dlOpenerLib->loadLib(1, nullptr);

                        _dlOpenerGame->clearLib();
                        _dlOpenerGame->setLib(_gameName);
                        _dlOpenerGame->loadLib(0, _dlOpenerLib->getDisplay());

                        openMap(_mapPath);
                    }
                }
            } else if (retVal == 103) {
                startMenu();
                return true;
            }
        }
        return true;
    }

    void Arcade::reloadToMenu()
    {
    }

    void Arcade::openMap(std::string path)
    {
        std::ifstream file(path);
        if (!file) {
            std::cerr << "Unable to open file\n";
            return;
        }

        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
        _dlOpenerGame->getGame()->setMap(lines);
    }
}
