#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>

namespace Player
{

    class Player : public sf::Drawable
    {
        public:
            Player(const Player&) = delete;
            Player& operator=(const Player&) = delete;
            Player();

        template<typename ... Args>
        void setPosition(Args&& ... args) {
            _shape.setPosition(std::forward<Args>(args)...);
        }

        void update(sf::Time deltaTime);
        bool isMoving;
        int rotation;

        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            sf::RectangleShape  _shape;
            sf::Vector2f        _velocity;

    };

}

#endif