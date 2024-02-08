#ifndef __SAUCER_H__
#define __SAUCER_H__

#include "enemy.h"

namespace Saucer
{
    class Saucer : public Enemy::Enemy
    {
        public:
            Saucer(const Saucer&) = delete;
            Saucer& operator=(const Saucer&) = delete;

            Using Enemy::Enemy;

            virtual bool isCollide(const Entity::Entity& other) const;

            static void newSaucer(World::World& _world);
            virtual void update(sf::Time deltaTime);
            virtual void onDestroy();
    };
}

#endif