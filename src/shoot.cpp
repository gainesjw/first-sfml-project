#include "shoot.h"

namespace Shoot
{
    void Shoot::update(sf::Time deltaTime)
    {
        float seconds = deltaTime.asSeconds();
        _sprite.move(seconds * _impulse);
        _duration -= deltaTime;

        if(_duration < sf::Time::Zero)
            _alive = false;
    }

    ShootPlayer::ShootPlayer(Player::Player& from) : Shoot(Configuration::Configuration::Textures::ShootPlayer, from._world)
    {
        _duration = sf::seconds(5);

        float angle = from._sprite.getRotation() / 180 * M_PI - M_PI / 2;
        _impulse = sf::Vector2f(std::cos(angle), std::sin(angle)) * 500.f;

        setPosition(from.getPosition());
        _sprite.setRotation(from._sprite.getRotation());
        _world.add(Configuration::Configuration::Sounds::LaserPlayer);
    }
}