#include "game.h"

namespace Game
{
    Game::Game(int x, int y) : _window(sf::VideoMode(x, y),"project_001"), x(x), y(y) //, _player(150)
    {
            //_player.setFillColor(sf::Color::Blue);
            _player.setPosition(100, 100);
    }
    
    void Game::run(int minimum_frame_per_seconds)
    {
        sf::Clock clock;
        sf::Time timeSinceLastUpdate;
        sf::Time TimePerFrame = sf::seconds(1.f / minimum_frame_per_seconds);

        while (_window.isOpen())
        {
            processEvents();
            timeSinceLastUpdate = clock.restart();

            while (timeSinceLastUpdate > TimePerFrame)
            {
                timeSinceLastUpdate -= TimePerFrame;
                update(TimePerFrame);
            }

            update(timeSinceLastUpdate);
            render();
        }
    }

    void Game::processEvents() 
    {

        sf::Event event;

        while(_window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                _window.close();
            else if (event.type == sf::Event::KeyPressed) 
            {
                if (event.key.code == sf::Keyboard::Escape)
                    _window.close();
            }
        }
        _player.processEvents();
    }

    void Game::update(sf::Time deltaTime)
    {
        _player.update(deltaTime);
        sf::Vector2f player_pos = _player.getPosition();
        if(player_pos.x < 0)
        {
            player_pos.x = _x;
        }
    }

    void Game::render() {
        _window.clear();
        _window.draw(_player);
        _window.display();
    }

}