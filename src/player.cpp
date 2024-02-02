#include "player.h"

namespace Player
{
    Player::Player(World& world) :  Entity::Entity(Configuration::Configuration::textures::Player, world)
                        ,Action::ActionTarget(Configuration::Configuration::player_inputs
                        ,_isMoving(false)
                        ,_rotation(0)
    {

        bind(Configuration::Configuration::PlayerInputs::Up,[this](const sf::Event&){
            _isMoving = true;
        });

        bind(Configuration::Configuration::PlayerInputs::Left,[this](const sf::Event&){
            _rotation -= 1;
        });

        bind(Configuration::Configuration::PlayerInputs::Right,[this](const sf::Event&){
            _rotation += 1;
        });

        bind(Configuration::Configuration::PlayerInputs::Shoot,[this](const sf::Event&){
             shoot();
         });

        bind(Configuration::Configuration::PlayerInputs::Hyperspace,[this](const sf::Event&){
             goToHyperspace();
         });
    }

    void Player::update(sf::Time deltaTime)
    {
        float seconds = deltaTime.asSeconds();
        if(_rotation != 0)
        {
            float angle = _rotation * 180 * seconds;
            _sprite.rotate(angle);
        }
        if(_isMoving)
        {
            float angle = _sprite.getRotation() / 180 * M_PI - M_PI / 2;
            _velocity += sf::Vector2f(std::cos(angle),std::sin(angle)) * 60.f * seconds;
        }
        _sprite.move(seconds * _velocity);
    }

    void Player::processEvents()
    {
        _isMoving = false;
        _rotation = 0;
        Action::ActionTarget<int>::processEvents();
    }
}