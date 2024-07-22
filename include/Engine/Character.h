#pragma once

#include <SFML/Graphics.hpp>

enum class Direction
{
    LEFT,
    RIGHT,
    DOWN,
    UP
};

enum class State
{
    IDLE,
    RUN,
    CHASING
};

enum class CharacterType
{
    player,
    enemy,
    friendly,
    neutral
};

class Character
{
    protected:
        float           m_frame;
        float           m_damage;
        State           m_state;
        float           m_health;
        float           m_speed;
        sf::Vector2f    m_size;
        sf::Vector2f    m_pos;
        sf::Sprite      m_sprite;
        Direction       m_direction = Direction::LEFT;
        sf::RectangleShape m_hpBar;
        CharacterType   m_type;
        sf::Clock       m_damage_clock;
        bool            m_is_damage = false;

    public:
        virtual ~Character();

        virtual void Update(float time) = 0;
        void getDamage(float damage);
        float takeDamage();

        void setPosition(sf::Vector2f& pos);
        void setDirection(Direction direction);
        void setHealth(float health);
        void setType(CharacterType);

        float getHP() const;
        sf::Vector2f getSize() const;
        sf::Vector2f getPosition() const;
        sf::Sprite getSprite() const;
        Direction getDirection() const;
        sf::RectangleShape& getHpBar();
        CharacterType getType() const;
};