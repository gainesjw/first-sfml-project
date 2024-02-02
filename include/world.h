#ifndef __WORLD_H__
#define __WORLD_H__

#include <SFML/Graphics.hpp>
#include "configuration.h"
#include "entity.h"
#include <list>
#include <memory>

namespace World
{
    class World : sf::Drawable
    {
        public:

        World(const World&) = delete;
        World& operator=(const World&) = delete;
        World(float x, float y);
        ~World();

        void add(Entity::Entity* entity);
        void clear();
        bool isCollide(const Entity::Entity& other);
        int size();

        void add(Configuration::Configuration::Sounds sound_id);

        const std::list<Entity::Entity*> getEntities() const;
        int getX() const;
        int getY() const;
        void update(sf::Time deltaTime);

        private:

        std::list<Entity::Entity*> _entities;
        std::list<Entity::Entity*> _entities_tmp;
        std::list<std::unique_ptr<sf::Sound>> _sounds;
        
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        const int _x;
        const int _y;
    };
}