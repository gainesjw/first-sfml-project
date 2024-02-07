#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include "player.h"
#include "world.h"
#include "random.h"
#include "configuration.h"

namespace Game
{

    class Game
    {
        public:
            Game(const Game&) = delete;
            Game& operator=(const Game&) = delete;

            Game(int x=800, int y=600);
            
            void run(int minimumFPS);
            void initLevel();

        private:
            void processEvents();
            void update(sf::Time deltaTime);
            void render();
            void reset();

            World::World _world;
            sf::RenderWindow _window;

            sf::Time   _nextSaucer;
            sf::Text   _txt;
    };    

}

#endif