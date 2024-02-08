#ifndef __COLLISION_H__
#define __COLLISION_H__

#include <SFML/Graphics.hpp>

namespace Collision 
{
    class Collision
    {
        public:
            Collision() = delete;
            Collision(const Collision&) = delete;
            Collision& operator=(const Collision&) = delete;

            static bool circleTest(const sf::Sprite& first, const sf::Sprite& second);
    };
}

#endif