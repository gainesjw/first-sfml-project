#include "game.h"

namespace Game
{
    Game::Game(int x, int y) : _window(sf::VideoMode(x, y),"project_001"), _world(x, y)
    {
        _txt.setFont(Configuration::Configuration::fonts.get(Configuration::Configuration::Fonts::GUI));
        _txt.setCharacterSize(70);
        _txt.setString("Press any Key to start");

        sf::FloatRect size = _txt.getGlobalBounds();
        _txt.setOrigin(size.width/2,size.height/2);
        _txt.setPosition(x/2, y/2);
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

    void Game::initLevel()
    {
        int nb_meteors;
        switch(Configuration::Configuration::level)
        {
            case 1 : nb_meteors = 4; break;
            case 2 : nb_meteors = 5; break;
            case 3 : nb_meteors = 7; break;
            case 4 : nb_meteors = 9; break;
            default : nb_meteors = 11; break;
        }
        for(int i = 0; i<nb_meteors;++i)
        {
            Meteor* meteor = new BigMeteor(_world);
            do{
                meteor->setPosition(Random::random(0.f,(float)_world.getX()),Random::random(0.f,(float)_world.getY()));
            }while(_world.isCollide(*meteor));
            _world.add(meteor);
        }
    }

    void Game::processEvents() 
    {
        //to store the events
        sf::Event event;
        //events loop
        while(_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)//Close window
                _window.close();
            else if (event.type == sf::Event::KeyPressed) //keyboard input
            {
                if (event.key.code == sf::Keyboard::Escape)
                    _window.close();
            }

            if(Configuration::Configuration::isGameOver())
            {
                if (event.type == sf::Event::KeyPressed) //keyboard input
                    reset();
            }
            else
            {
                if(Configuration::Configuration::player != nullptr)
                    Configuration::Configuration::player->processEvent(event);
            }
        }
        if(not Configuration::Configuration::isGameOver() and Configuration::Configuration::player != nullptr)
            Configuration::Configuration::player->processEvents();
    }

    void Game::update(sf::Time deltaTime)
    {
        if(not Configuration::Configuration::isGameOver())
        {
            _world.update(deltaTime);
            if(Configuration::Configuration::player == nullptr)
            {
                Configuration::Configuration::player = new Player::Player(_world);
                Configuration::Configuration::player->setPosition(_world.getX()/2,_world.getY()/2);
                _world.add(Configuration::Configuration::player);
            }
            _nextSaucer -= deltaTime;

            if(_nextSaucer < sf::Time::Zero)
            {
                Saucer::newSaucer(_world);
                _nextSaucer = sf::seconds(Random::random(10.f,60.f - Configuration::Configuration::level*2));
            }

            if(_world.size() <= 1)
            {
                ++Configuration::Configuration::level;
                initLevel();
            }
        }
    }

    void Game::render()
    {
        //Clear screen
        _window.clear();

        //Draw
        if(Configuration::Configuration::isGameOver())
        {
            _window.draw(_txt);
        }
        else
        {
            _window.draw(_world);

            Configuration::Configuration::draw(_window);
        }

        //Update the window
        _window.display();
    }

    void Game::reset()
    {
        _nextSaucer = sf::seconds(Random::random(5.f, 6.f - Configuration::Configuration::level*2));
        _world.clear();
        Configuration::Configuration::player = nullptr;
        Configuration::Configuration::reset();
        initLevel();
    }

}