#ifndef __SAUCER_H__
#define __SAUCER_H__

#include "enemy.h"
#include "shoot.h"
#include <SFML/Graphics.hpp>

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

    class BigSaucer : public Saucer
    {
        public:
            BigSaucer(World& world);
            virtual int getPoints() const;
    };

    class SmallSaucer : public Saucer
    {
        public:
            SmallSaucer(World& World);
            virtual int getPoints() const;
            virtual void update(sf::Time deltaTime);

        private:
            sf::Time _timeSinceLastShoot;
    }
}

#endif