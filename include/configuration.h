#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "random.h"
#include "action.h"
#include "resourcemanager.h"

namespace Player
{
    class Player;
}

namespace Configuration 
{
    class Configuration
    {
        public:
            Configuration() = delete;
            Configuration(const Configuration&) = delete;
            Configuration& operator=(const Configuration&) = delete;

            enum Textures : int 
            {Player,
            PlayerLife,
            BigSaucer,
            SmallSaucer,
            BigMeteor1,
            BigMeteor2,
            BigMeteor3,
            BigMeteor4,
            MediumMeteor1,
            MediumMeteor2,
            SmallMeteor1,
            SmallMeteor2,
            SmallMeteor3,
            SmallMeteor4,
            ShootPlayer,
            ShootSaucer,
            };
            static ResourceManager::ResourceManager<sf::Texture, int> textures;

            enum Fonts : int {GUI};
            static ResourceManager::ResourceManager<sf::Font, int> fonts;

            enum Musics : int {Theme};
            static ResourceManager::ResourceManager<sf::Music, int> musics;

            enum Sounds : int 
            {LaserPlayer,
            LaserEnemy,
            SaucerSpawn1,
            SaucerSpawn2,
            Boom,
            Boom2,
            Explosion1,
            Explosion3,
            Explosion2,
            Jump
            };
            static ResourceManager::ResourceManager<sf::SoundBuffer, int> sounds;

            enum PlayerInputs : int 
            {Up,
            Left,
            Right,
            Shoot,
            Hyperspace
            };
            static Action::ActionMap<int> player_inputs;

            static void initialize();
            static void reset();

            static bool isGameOver();

            static void addScore(int s);
            static int getScore();

            static Player::Player* player;
            static int level;
            static int lives;

            static void draw(sf::RenderTarget& target);

        private:
            static int _score;
            static sf::Text _txt_score;
            static sf::Sprite _spr_life;

            static void initTextures();
            static void initFonts();
            static void initSounds();
            static void initMusics();

            static void initPlayerInputs();
    };
}

#endif