/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL
*/

#include "SDL.hpp"

namespace Graphic {
    SDL::SDL()
    {
        _nameLib = "SDL";
        SDL_Init(SDL_INIT_VIDEO);
        _event = SDL_Event();
        _start_time = SDL_GetTicks();
    }

    SDL::~SDL()
    {
        SDL_DestroyWindow(_window);
        SDL_DestroyRenderer(_renderer);
        SDL_Quit();

        for (auto entity : _entity)
            delete entity;
        for (auto rect : _rectangleMap)
            delete rect;
    }

    void SDL::initWindow(float x, float y)
    {
        _window = SDL_CreateWindow(
            (_gameName + " - " + _nameLib).c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            x * 32,
            y * 32,
            SDL_WINDOW_OPENGL
        );
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    }

    void SDL::createEntity(std::string type, float x, float y, std::string path, char symbol)
    {
        IEntity *entity = new EntitySDL(type, x, y, path, symbol, _renderer);
        _entity.push_back(entity);
    }

    void SDL::setMap(std::vector<std::string> map)
    {
        _map = map;
    }

    void SDL::clearWindow()
    {
        SDL_RenderClear(_renderer);
    }

    void SDL::displayWindow()
    {
        SDL_RenderPresent(_renderer);
    }

    std::size_t SDL::getInput()
    {
        while (SDL_PollEvent(&_event)) {
            if (_event.type == SDL_KEYDOWN) {
                if (_event.key.keysym.sym == SDLK_UP)
                    return 1;
                if (_event.key.keysym.sym == SDLK_DOWN)
                    return 3;
                if (_event.key.keysym.sym == SDLK_LEFT)
                    return 4;
                if (_event.key.keysym.sym == SDLK_RIGHT)
                    return 2;
                if (_event.key.keysym.sym == SDLK_l)
                    return 100;
                if (_event.key.keysym.sym == SDLK_g)
                    return 101;
                if (_event.key.keysym.sym == SDLK_e)
                    return 102;
                if (_event.key.keysym.sym == SDLK_m)
                    return 103;
            }
        }
        return 127;
    }

    void SDL::parseMap()
    {
        for (int i = 0; i < _map.size(); i++) {
            for (int j = 0; j < _map[i].size(); j++) {
                if (_map[i][j] == '1' || _map[i][j] == '2' || _map[i][j] == '3' || _map[i][j] == '4' || _map[i][j] == '5' || _map[i][j] == '6' || _map[i][j] == '7' || _map[i][j] == '8' || _map[i][j] == '-' || _map[i][j] == '|') {
                    IEntity *entity = new EntitySDL("wall", j, i, "assets/snake/wall.png", _map[i][j], _renderer);
                    _rectangleMap.push_back(entity);
                }
                if (_map[i][j] == '.' || _map[i][j] == ' ' || _map[i][j] == ';') {
                    IEntity *entity = new EntitySDL("1", j, i, "assets/snake/1.png", ' ', _renderer);
                    _rectangleMap.push_back(entity);
                }
                if (_map[i][j] == '_') {
                    IEntity *entity = new EntitySDL("2", j, i, "assets/snake/2.png", ' ', _renderer);
                    _rectangleMap.push_back(entity);
                }
            }
        }
    }

    void SDL::displayMap()
    {
        for (auto entity : _rectangleMap) {
            displayEntity(entity);
        }
    }

    void SDL::displayEntity(IEntity *entity)
    {
        auto entitySDL = dynamic_cast<EntitySDL *>(entity);
        SDL_RenderCopyEx(_renderer, entitySDL->getTexture(), NULL, entitySDL->getRect(), entitySDL->getAngle(), NULL, SDL_FLIP_NONE);
    }

    bool SDL::getCollision(IEntity &entity1, IEntity &entity2)
    {
        if (entity1.getPosition().first == entity2.getPosition().first && entity1.getPosition().second == entity2.getPosition().second)
            return true;
        else
            return false;
    }

    bool SDL::closeWindow(int type)
    {
        if (type == 1) {
            SDL_DestroyWindow(_window);
            return false;
        } else if (type == 0) {
            SDL_Event e;
            while (SDL_PeepEvents(&e, 1, SDL_GETEVENT, SDL_QUIT, SDL_QUIT) > 0) {
                if (e.type == SDL_QUIT) {
                    SDL_DestroyWindow(_window);
                    return true;
                }
            }
        }
        return false;
    }

    float SDL::getElapsedTime()
    {
        return (SDL_GetTicks() - _start_time) / 1000.0f;
    }

    void SDL::resetClock()
    {
        _start_time = SDL_GetTicks();
    }

    void SDL::removeEntity(IEntity *entity)
    {
        _entity.erase(std::remove(_entity.begin(), _entity.end(), entity), _entity.end());
    }
}
