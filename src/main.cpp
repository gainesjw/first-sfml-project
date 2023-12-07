#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"

int main()
{

    Player::Player::setDefaultInputs();

    Game::Game Game;
    Game.run(30);


}