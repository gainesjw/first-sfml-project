#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include "action.h"
#include "resourcemanager.h"

namespace Configuration 
{
    class Configuration
    {
        public:
            Configuration() = delete;
            Configuration(const Configuration&) = delete;
            Configuration& operator=(const Configuration&) = delete;

            enum Textures : int {Player};
            static ResourceManager::ResourceManager<sf::Texture, int> textures;

            enum PlayerInputs : int {Up,Left,Right};
            static Action::ActionMap<int> player_inputs;

            static void initialize();

        private:
            static void initTextures();
            static void initPlayerInputs();
    };
}

#endif