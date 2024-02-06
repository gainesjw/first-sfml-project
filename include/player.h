#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>
#include "configuration.h"
#include "entity.h"
#include "random.h"

namespace Player
{

    class Player : public Entity::Entity,
                     public Action::ActionTarget<int>
    {
        public:
            Player(const Player&) = delete;
            Player& operator=(const Player&) = delete;

            Player(World::World& world);

            virtual bool isCollide(const Entity& other) const;
            virtual void update(sf::Time deltaTime);

            void processEvents();
            void shoot();
            void goToHyperspace();

            virtual void onDestroy();
 
        private:
            bool _isMoving;
            int _rotation;

            sf::Time _timeSinceLastShoot;
    };

}

#endif