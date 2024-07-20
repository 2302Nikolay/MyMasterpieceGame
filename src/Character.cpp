#include "../include/Engine/Character.h"

Character::~Character(){}

void Character::getDamage(float damage)
{
    m_health -= damage;
    m_sprite.setColor(sf::Color::Red); 
    m_damage_clock.restart();
    m_is_damage = true;
}

float Character::takeDamage()
{
    return m_damage;
}

void Character::setPosition(sf::Vector2f& pos)
{
    m_pos = pos;
}

void Character::setDirection(Direction direction)
{
    m_direction = direction;
}

float Character::getHP() const
{
    return m_health;
}

sf::Vector2f Character::getSize() const
{
    return m_size;
}

sf::Vector2f Character::getPosition() const
{
    return m_pos;
}

sf::Sprite Character::getSprite() const
{
    return m_sprite;
}

Direction Character::getDirection() const
{
    return m_direction;
}

sf::RectangleShape& Character::getHpBar()
{
    return m_hpBar;
}
void Character::setHealth(float health)
{
    m_health = health;
    float healthPercentage = m_health / 100.0f;
    m_hpBar.setSize(sf::Vector2f(40.0f * healthPercentage, 5.0f));
    m_hpBar.setPosition(m_pos.x, m_pos.y - 10);

    switch (m_type)
    {
    case CharacterType::friendly:
        m_hpBar.setFillColor(sf::Color::Cyan);
        break;
    case CharacterType::enemy:
        m_hpBar.setFillColor(sf::Color::Red);
        break;
    case CharacterType::neutral:
        m_hpBar.setFillColor(sf::Color::Yellow);
        break;
    case CharacterType::player:
        m_hpBar.setFillColor(sf::Color::Green);
        break;
    }
}

void Character::setType(CharacterType type)
{
    m_type = type;
}