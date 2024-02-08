#include "player.h"

namespace Player
{
    Player::Player(World::World& _world) :  Entity::Entity(Configuration::Configuration::Textures::Player, _world)
                        ,Action::ActionTarget(Configuration::Configuration::player_inputs)
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

    bool Player::isCollide(const Entity& other) const
    {
        if(dynamic_cast<const Configuration::Configuration::Textures::ShootPlayer*>(&other) == nullptr)
        {
            return Collision::Collision::circleTest(_sprite, other._sprite);
        }
        return false;
    }

    void Player::shoot()
    {
        if(_timeSinceLastShoot > sf::seconds(0.3))
        {
            _world.add(new Configuration::Configuration::Textures::ShootPlayer(*this));
            _timeSinceLastShoot = sf::Time::Zero;
        }
    }

    void Player::onDestroy()
    {
        Entity::onDestroy();
        Configuration::Configuration::player = nullptr;
        Configuration::Configuration::lives--;
        _world.add(Configuration::Configuration::Sounds::Boom);
    }

    void Player::goToHyperspace()
    {
        _impulse = sf::Vector2f(0, 0);
        setPosition(Random::random(0, _world.getX()), Random::random(0, _world.getY()));
        _world.add(Configuration::Configuration::Sounds::Jump);
    }

    void Player::update(sf::Time deltaTime)
    {
        float seconds = deltaTime.asSeconds();
        if(_rotation != 0)
        {
            float angle = _rotation * 250 * seconds;
            _sprite.rotate(angle);
        }
        if(_isMoving)
        {
            float angle = _sprite.getRotation() / 180 * M_PI - M_PI / 2;
            _impulse += sf::Vector2f(std::cos(angle),std::sin(angle)) * 300.f * seconds;
        }
        _sprite.move(seconds * _impulse);
    }

    void Player::processEvents()
    {
        _isMoving = false;
        _rotation = 0;
        Action::ActionTarget<int>::processEvents();
    }
}