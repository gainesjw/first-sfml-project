#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include "player.h"

namespace Game
{

    class Game
    {
    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();

        sf::RenderWindow _window;
        Player::Player  _player;

    public:
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        Game();
        void run(int minimum_frame_per_seconds);

    };    

}

#endif