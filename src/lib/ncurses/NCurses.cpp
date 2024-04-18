/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#include "NCurses.hpp"

namespace Graphic {
    NCurses::NCurses()
    {
        _nameLib = "NCurses";
        start = std::chrono::steady_clock::now();
    }

    NCurses::~NCurses()
    {
        for (auto entity : _entity)
            delete entity;
    }

    void NCurses::initWindow(float x, float y)
    {
        initscr();
        if (x > 0)
            nodelay(stdscr, TRUE);
    }

    void NCurses::createEntity(std::string type, float x, float y, std::string path, char symbol)
    {
        IEntity *newEntity = new EntityNcurses(type, x, y, path, symbol);
        _entity.push_back(newEntity);
    }

    void NCurses::setMap(std::vector<std::string> map)
    {
        _map = map;
    }

    void swhitchElem(std::size_t i, std::size_t j, std::string line)
    {
        switch (line[j]) {
            case '.':
                start_color();
                init_pair(1, COLOR_YELLOW, COLOR_BLACK);
                attron(COLOR_PAIR(1));
                mvaddch(i, j, '.');
                attroff(COLOR_PAIR(1));
                break;
            case ' ':
                mvaddch(i, j, ' ');
                break;
        }

    }

    void swhitchBorder(std::size_t i, std::size_t j, std::string line)
    {
        switch (line[j]) {
            case '-':
                mvaddch(i, j, ACS_HLINE);
                break;
            case '|':
                mvaddch(i, j, ACS_VLINE);
                break;
            case '1':
                mvaddch(i, j, ACS_ULCORNER);
                break;
            case '2':
                mvaddch(i, j, ACS_URCORNER);
                break;
            case '3':
                mvaddch(i, j, ACS_LLCORNER);
                break;
            case '4':
                mvaddch(i, j, ACS_LRCORNER);
                break;
            case '5':
                mvaddch(i, j, ACS_ULCORNER);
                break;
            case '6':
                mvaddch(i, j, ACS_URCORNER);
                break;
            case '7':
                mvaddch(i, j, ACS_LLCORNER);
                break;
            case '8':
                mvaddch(i, j, ACS_LRCORNER);
                break;

        }
    }

    void treatMap(std::size_t i, std::string line)
    {
        for (std::size_t j = 0; j < line.size(); j++) {
            if (isalpha(line[j])) {
                mvaddch(i, j, line[j]);
                continue;
            }
            swhitchBorder(i, j, line);
            swhitchElem(i, j, line);
        }
    }

    std::size_t NCurses::getInput()
    {
        keypad(stdscr, TRUE);
        int ch = 0;
        ch = getch();
        switch (ch) {
            case KEY_UP:
                return 1;
            case KEY_RIGHT:
                return 2;
            case KEY_DOWN:
                return 3;
            case KEY_LEFT:
                return 4;
            case 27:
                return 5;
            case 10:
                return 6;
            case 'l':
                return 100;
            case 'g':
                return 101;
            case 'e':
                return 102;
            case 'm':
                return 103;
            default:
                return 0;
        }
    }

    void NCurses::clearWindow()
    {
        werase(stdscr);
    }

    void NCurses::displayWindow()
    {
        wrefresh(stdscr);
    }

    bool NCurses::getCollision(IEntity &entity1, IEntity &entity2)
    {
        if (entity1.getPosition().first == entity2.getPosition().first && entity1.getPosition().second == entity2.getPosition().second)
            return true;
        else
            return false;
    }

    void NCurses::displayEntity(IEntity *entity)
    {
        if (entity->getType() == "textbox") {
            char output[256];
            if (_playerName == "") {
                curs_set(1);
                mvwgetstr(stdscr, entity->getPosition().first, entity->getPosition().second, output);
            } else {
                mvprintw(entity->getPosition().first, entity->getPosition().second, _playerName.c_str());
            }
            if (_playerName == "")
                _playerName = output;
            curs_set(0);
            return;
        }
        if (entity->getType() == "text") {
            mvprintw(entity->getPosition().second, entity->getPosition().first, entity->getText().c_str());
            return;
        }
        mvaddch(entity->getPosition().second, entity->getPosition().first, entity->getSymbol());
    }

    void NCurses::displayMap()
    {
        for (std::size_t i = 0; i != _map.size() ; i++) {
            treatMap(i, _map[i]);
        }
    }

    void NCurses::removeEntity(IEntity *entity)
    {
        _entity.erase(std::remove(_entity.begin(), _entity.end(), entity), _entity.end());
    }

    bool NCurses::closeWindow(int type)
    {
        if (type != 0) {
            endwin();
            return true;
        }
        return false;
    }

    float NCurses::getElapsedTime()
    {
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<float> elapsed = end - start;
        return elapsed.count();
    }

    void NCurses::resetClock()
    {
        start = std::chrono::steady_clock::now();
    }

}
