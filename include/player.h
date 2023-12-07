#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>
#include "action.h"

namespace Player
{

    class Player : public sf::Drawable, public Action::ActionTarget<int>
    {
        public:
            Player(const Player&) = delete;
            Player& operator=(const Player&) = delete;

            Player();

            template<typename ... Args>
            void setPosition(Args&& ... args) {
                _shape.setPosition(std::forward<Args>(args)...);
            }

            void processEvents();
            void update(sf::Time deltaTime);

            enum PlayerInputs {Up,Left,Right};
            static void setDefaultInputs();
 

        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            
            sf::RectangleShape  _shape;
            sf::Vector2f        _velocity;
            
            bool _isMoving;
            int _rotation;

            static Action::ActionMap<int> _playerInputs;
    };

}

#endif