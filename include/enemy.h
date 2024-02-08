#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "entity.h"

namespace Enemy 
{
    class Enemy : public Entity::Entity
    {
        public:
            Enemy(const Enemy&) = delete;
            Enemy& operator=(const Enemy&) = delete;

            Enemy(Configuration::Configuration::Textures tex_id, World::World& _world);

            virtual int getPoints() const = 0;
            virtual void onDestroy();
    }
}

#endif