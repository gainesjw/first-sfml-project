#include "enemy.h"
#include "random.h"

namespace Enemy
{
    Enemy::Enemy(Configuration::Configuration::Textures tex_id, World::World& _world) : Entity::Entity(tex_id, _world)
    {
        float angle = Random::random(0.f, 2.f * M_PI);
        _impulse = sf::Vector2f(std::cos(angle), std::sin(angle));
    }

    void Enemy::onDestroy()
    {
        Entity::onDestroy();
        Configuration::Configuration::addScore(getPoints());
    }
}