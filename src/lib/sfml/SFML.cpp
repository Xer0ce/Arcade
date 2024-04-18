/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SFML
*/

#include "SFML.hpp"

namespace Graphic {
    SFML::SFML()
    {
        _nameLib = "SFML";
        _isPressed = false;
    }

    SFML::~SFML()
    {
    }

    void SFML::initWindow(float x, float y)
    {
        _window.create(sf::VideoMode(x * 32, y * 32), _gameName + " - " + _nameLib);
    }

    void SFML::createEntity(std::string type, float x, float y, std::string path, char symbol)
    {
        IEntity *entity = new Sprite(type, x, y, path, symbol);
        _entity.push_back(entity);
    }

    void SFML::setMap(std::vector<std::string> map)
    {
        _map = map;
    }

    void SFML::clearWindow()
    {
        _window.clear();
    }

    void SFML::displayWindow()
    {
        _window.display();
    }

    std::size_t SFML::getInput()
    {
        if (_event.type == sf::Event::KeyPressed)
            _isPressed = true;


        if (_isPressed) {
            if (_event.key.code == sf::Keyboard::Up)
                return 1;
            if (_event.key.code == sf::Keyboard::Down)
                return 3;
            if (_event.key.code == sf::Keyboard::Left)
                return 4;
            if (_event.key.code == sf::Keyboard::Right)
                return 2;
            if (_event.key.code == sf::Keyboard::L)
                return 100;
            if (_event.key.code == sf::Keyboard::G)
                return 101;
            if (_event.key.code == sf::Keyboard::E)
                return 102;
            if (_event.key.code == sf::Keyboard::M)
                return 103;
        }
        if (_event.type == sf::Event::KeyReleased)
            _isPressed = false;
        return 127;
    }

    void SFML::parseMap()
    {
        for (int i = 0; i < _map.size(); i++) {
            for (int j = 0; j < _map[i].size(); j++) {
                if (_map[i][j] == '1' || _map[i][j] == '2' || _map[i][j] == '3' || _map[i][j] == '4' || _map[i][j] == '5' || _map[i][j] == '6' || _map[i][j] == '7' || _map[i][j] == '8' || _map[i][j] == '-' || _map[i][j] == '|') {
                    RectangleShape newRectangleShape;
                    newRectangleShape.setColor(sf::Color (84.8, 140.4, 45.6));
                    newRectangleShape.setPosition(sf::Vector2f(j * 32, i * 32));
                    _rectangleMap.push_back(newRectangleShape);
                }
                if (_map[i][j] == '.' || _map[i][j] == ' ' || _map[i][j] == ';') {
                    RectangleShape newRectangleShape;
                    newRectangleShape.setColor(sf::Color (172.1, 217.2, 80.6));
                    newRectangleShape.setPosition(sf::Vector2f(j * 32, i * 32));
                    _rectangleMap.push_back(newRectangleShape);
                }
                if (_map[i][j] == '_') {
                    RectangleShape newRectangleShape;
                    newRectangleShape.setColor(sf::Color (164.0, 211.3, 71.0));
                    newRectangleShape.setPosition(sf::Vector2f(j * 32, i * 32));
                    _rectangleMap.push_back(newRectangleShape);
                }
            }
        }
    }

    void SFML::displayMap()
    {
        for (int i = 0; i < _rectangleMap.size(); i++) {
            _rectangleMap[i].draw(_window);
        }
    }

    void SFML::displayEntity(IEntity *entity)
    {
        if (entity->getType() == "text") {
            sf::Text text;
            sf::Font font;
            font.loadFromFile("assets/arial.ttf");
            text.setFont(font);
            text.setString(entity->getText());
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::White);
            text.setPosition(entity->getPosition().first, entity->getPosition().second);
            _window.draw(text);
            return;
        }
        _window.draw(dynamic_cast<Sprite *>(entity)->getSprite());
    }

    bool SFML::getCollision(IEntity &entity1, IEntity &entity2)
    {
        if (entity1.getPosition().first == entity2.getPosition().first && entity1.getPosition().second == entity2.getPosition().second)
            return true;
        else
            return false;
    }

    bool SFML::closeWindow(int type)
    {
        if (type == 1)
            _window.close();
        else if (type == 0) {
            while (_window.pollEvent(_event)) {
                if (_event.type == sf::Event::Closed) {
                    _window.close();
                    return true;
                }
            }
        }
        return false;
    }

    float SFML::getElapsedTime()
    {
        return _time.getElapsedTime().asSeconds();
    }

    void SFML::resetClock()
    {
        _time.restart();
    }

    void SFML::removeEntity(IEntity *entity)
    {
        _entity.erase(std::remove(_entity.begin(), _entity.end(), entity), _entity.end());
    }
}
