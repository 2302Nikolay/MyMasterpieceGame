#include "../include/Engine/Character.h"

Character::~Character(){}

void Character::getDamage(float damage)
{
    //m_sprite.setColor(sf::Color::Red);
    m_health -= damage;
    m_sprite.setColor(sf::Color::Red); // Подсвечиваем спрайт красным
    m_damage_clock.restart(); // Перезапускаем часы
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
    float healthPercentage = m_health / 100.0f; // Предполагается, что максимальное здоровье = 100
    m_hpBar.setSize(sf::Vector2f(40.0f * healthPercentage, 5.0f));
    m_hpBar.setPosition(m_pos.x, m_pos.y - 10);
    //m_hpBar.setFillColor(healthPercentage > 0.5f ? sf::Color::Green : sf::Color::Red);
    if (m_type == CharacterType::friendly)
        m_hpBar.setFillColor(sf::Color::Cyan);
    if (m_type == CharacterType::enemy)
        m_hpBar.setFillColor(sf::Color::Red);
    if (m_type == CharacterType::neutral)
        m_hpBar.setFillColor(sf::Color::Yellow);
    if (m_type == CharacterType::player)
        m_hpBar.setFillColor(sf::Color::Green);
}