#ifndef __SHOOT_H__
#define __SHOOT_H__

#include "entity.h"
#include "player.h"

namespace Shoot
{
    class Shoot : public Entity::Entity
    {
        public:
            Shoot(const Shoot&) = delete;
            Shoot& operator=(const Shoot&) = delete;

            using Entity::Entity;

            virtual void update(sf::Time deltaTime);

        protected:
            sf::Time  _duration;
    };

    class ShootPlayer : public Shoot
    {
        public:
            ShootPlayer(const ShootPlayer&) = delete;
            ShootPlayer& operator=(const ShootPlayer&) = delete;

            ShootPlayer(Player::Player& from);
            virtual bool isCollide(const Entity::Entity& other);
    };

    class SmallSaucer;
    class ShootSaucer : public Shoot
    {
        public:
            ShootSaucer(const ShootSaucer&) = delete;
            ShootSaucer& operator=(const ShootSaucer&) = delete;

            ShootSaucer(SmallSaucer& from);
            virtual bool isCollide(const Entity::Entity& other) const;
    };
}

#endif