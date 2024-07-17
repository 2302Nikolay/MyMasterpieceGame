#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <random>
#include "../include/Enemy.h"
#include "../include/Player.h"

Enemy::Enemy(sf::Texture& texture, sf::Vector2f start_pos, float health, Player* target_player)
{
    m_pos = start_pos;
    m_health = health;
    m_target_player = target_player;
    m_direction = static_cast<Direction>(rand() % 4);
    m_state = State::IDLE;
    m_sprite.setTexture(texture);
    m_size = sf::Vector2f(40.0f, 40.0f);
    m_speed = rand() % (15 - 5 + 1) + 5;
}

Enemy::~Enemy() {}

void Enemy::Update(float time)
{
    moveToPlayer(m_target_player->getPosition(), time);
    m_sprite.setPosition(m_pos);
    setEnemyTexture(time);
}

void Enemy::setEnemyTexture(float time)
{
    int direction_offset_y = 0;
    switch (m_direction)
    {
    case Direction::UP:
        direction_offset_y = 0;
        break;
    case Direction::DOWN:
        direction_offset_y = 80;
        break;
    case Direction::LEFT:
        direction_offset_y = 40;
        break;
    case Direction::RIGHT:
        direction_offset_y = 120;
        break;
    }

    if (m_state == State::CHASING)
    {
        m_frame += 0.001f * time;
        if (m_frame >= 4)
            m_frame -= 4;

        int frame_index = static_cast<int>(m_frame) * 40;
        m_sprite.setTextureRect(sf::IntRect(frame_index, direction_offset_y, 40, 40));
    }
    else if (m_state == State::IDLE)
    {
        m_sprite.setTextureRect(sf::IntRect(40, direction_offset_y, 40, 40));
    }
}

void Enemy::moveToPlayer(sf::Vector2f player_pos, float time)
{
    sf::Vector2f direction_to_player = player_pos - m_pos;
    float distance = std::sqrt(direction_to_player.x * direction_to_player.x +
                               direction_to_player.y * direction_to_player.y);

    if (m_state == State::IDLE && isPlayerInView(player_pos, distance, 60 * 3.14159265 / 180))
    {
        m_state = State::CHASING;
    }

    if (m_state == State::CHASING)
    {
        updateDirection(direction_to_player);
        m_pos += 0.1f * (time / m_speed) * direction_to_player / distance;
    }

    setPosition(m_pos);
}

void Enemy::updateDirection(const sf::Vector2f& direction_to_player)
{
    if (std::abs(direction_to_player.x) > std::abs(direction_to_player.y))
    {
        m_direction = (direction_to_player.x > 0) ? Direction::RIGHT : Direction::LEFT;
    }
    else
    {
        m_direction = (direction_to_player.y > 0) ? Direction::DOWN : Direction::UP;
    }
}

bool Enemy::isPlayerInView(sf::Vector2f player_pos, float distance, float view_angle)
{
    if (distance > 100) return false;

    sf::Vector2f direction_vector;
    switch (m_direction)
    {
    case Direction::UP:
        direction_vector = {0, -1};
        break;
    case Direction::DOWN:
        direction_vector = {0, 1};
        break;
    case Direction::LEFT:
        direction_vector = {-1, 0};
        break;
    case Direction::RIGHT:
        direction_vector = {1, 0};
        break;
    }

    sf::Vector2f to_player = player_pos - m_pos;

    float dot_product = direction_vector.x * to_player.x + direction_vector.y * to_player.y;
    float lengths_product = std::sqrt(direction_vector.x * direction_vector.x + direction_vector.y * direction_vector.y) *
                            std::sqrt(to_player.x * to_player.x + to_player.y * to_player.y);

    if (lengths_product == 0) return false;

    float cos_angle = dot_product / lengths_product;
    float angle = std::acos(cos_angle);

    float half_view_angle = view_angle / 2.0f;

    return angle <= half_view_angle;
}
