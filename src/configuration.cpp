#include "configuration.h"

namespace Configuration
{
    ResourceManager::ResourceManager<sf::Texture, int> Configuration::textures;
    ResourceManager::ResourceManager<sf::Font, int> Configuration::fonts;
    ResourceManager::ResourceManager<sf::SoundBuffer, int> Configuration::sounds;
    ResourceManager::ResourceManager<sf::Music, int> Configuration::musics;

    Action::ActionMap<int> Configuration::player_inputs;
    int Configuration::level;
    int Configuration::lives;

    Player::Player* Configuration::Configuration::Player = nullptr;

    int Configuration::_score;
    sf::Text Configuration::_txt_score;
    sf::Sprite Configuration::_spr_life;

    void Configuration::initialize()
    {
        initTextures();
        initFonts();
        initSounds();
        initMusics();
        initPlayerInputs();

        Random::rand_init();
        _txt_score.setFont(fonts.get(Fonts::GUI));
        _txt_score.setCharacterSize(24);

        _spr_life.setTexture(textures.get(Textures::PlayerLife));

        musics.get(Musics::Theme).setLoop(true);
        musics.get(Musics::Theme).play();

        lives = level = _score = -1;
    }

    void Configuration::reset()
    {
        level = 1;
        lives = 3;

        _score = 0;
        _txt_score.setString("0");
    }

    bool Configuration::isGameOver()
    {
        return lives < 0;
    }

    void Configuration::addScore(int s)
    {
        int old_score = _score;
        _score += s*level;
        lives += _score/10000 - old_score/10000;
        _txt_score.setString(std::to_string(_score));
    }

    int Configuration::getScore()
    {
        return _score;
    }

    void Configuration::draw(sf::RenderTarget& target)
    {
        target.draw(_txt_score);
        for(int i = 0; i < lives; ++i)
        {
            _spr_life.setPosition(40*i, 40);
            target.draw(_spr_life);
        }
    }

    void Configuration::initTextures()
    {
        //player
        textures.load(Textures::Player,"media/Player/Ship.png");
        textures.load(Textures::PlayerLife,"media/Player/life.png");
        //saucers
        textures.load(Textures::BigSaucer,"media/Saucer/Big.png");
        textures.load(Textures::SmallSaucer,"media/Saucer/Small.png");
        //meteors
        textures.load(Textures::BigMeteor1,"media/Meteor/Big1.png");
        textures.load(Textures::BigMeteor2,"media/Meteor/Big2.png");
        textures.load(Textures::BigMeteor3,"media/Meteor/Big3.png");
        textures.load(Textures::BigMeteor4,"media/Meteor/Big4.png");

        textures.load(Textures::MediumMeteor1,"media/Meteor/Medium1.png");
        textures.load(Textures::MediumMeteor2,"media/Meteor/Medium2.png");

        textures.load(Textures::SmallMeteor1,"media/Meteor/Small1.png");
        textures.load(Textures::SmallMeteor2,"media/Meteor/Small2.png");
        textures.load(Textures::SmallMeteor3,"media/Meteor/Small3.png");
        textures.load(Textures::SmallMeteor4,"media/Meteor/Small4.png");
        //lasers
        textures.load(Textures::ShootPlayer,"media/Shoot/Player.png");
        textures.load(Textures::ShootSaucer,"media/Shoot/Saucer.png");
    }

    void Configuration::initFonts()
    {
        fonts.load(Fonts::GUI,"media/font/trs-million.ttf");
    }

    void Configuration::initSounds()
    {
        //laser
        sounds.load(Sounds::LaserPlayer,"media/sounds/laser1.ogg");
        sounds.load(Sounds::LaserEnemy,"media/sounds/laser2.ogg");
        //saucers
        sounds.load(Sounds::SaucerSpawn1,"media/sounds/spawn1.flac");
        sounds.load(Sounds::SaucerSpawn2,"media/sounds/spawn2.flac");
        // Boom
        sounds.load(Sounds::Boom,"media/sounds/boom.flac");
        sounds.load(Sounds::Boom2,"media/sounds/boom2.flac");
        // Explosion
        sounds.load(Sounds::Explosion1,"media/sounds/explosion1.flac");
        sounds.load(Sounds::Explosion2,"media/sounds/explosion2.flac");
        sounds.load(Sounds::Explosion3,"media/sounds/explosion3.flac");
        //others
        sounds.load(Sounds::Jump,"media/sounds/hyperspace.flac");
    }

    void Configuration::initMusics()
    {
        musics.load(Musics::Theme,"media/musics/theme.ogg");
    }

    void Configuration::initPlayerInputs()
    {
        player_inputs.map(PlayerInputs::Up, Action::Action(sf::Keyboard::Up));
        player_inputs.map(PlayerInputs::Right, Action::Action(sf::Keyboard::Right));
        player_inputs.map(PlayerInputs::Left, Action::Action(sf::Keyboard::Left));
        player_inputs.map(PlayerInputs::Hyperspace, Action::Action(sf::Keyboard::Down, Action::Action::Type::Released));
        player_inputs.map(PlayerInputs::Shoot, Action::Action(sf::Keyboard::Space));
    }
}