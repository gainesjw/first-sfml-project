#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include "player.h"
#include "world.h"

namespace Game
{

    class Game
    {
    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();

        World::World _world;
        Player::Player  _player;

    public:
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;

        Game(int x=800, y=600);
        
        void run(int minimumFPS);

    };    

}

#endif