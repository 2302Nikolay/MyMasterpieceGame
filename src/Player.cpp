#include <cmath>
#include <iostream>

#include "../include/Player.h"
#include "../include/Engine/PlayerController.h"
#include "../include/Textures.h"
#include "../include/Enemy.h"
#include "../include/Engine/Constants.h"

Player::Player(sf::Texture& texture, sf::Vector2f start_pos, float health)
{
    m_pos = start_pos;
    m_type = CharacterType::player;
    m_controller = PlayerController::getPlayerController();
    m_sprite.setTexture(texture); // Почему это работает, а m_sprite.setTexture(textures::player_texture); не работает???????
    m_size = sf::Vector2f(40.0f, 40.0f);
    setPlayerTexture(40, 80, 40, 40);
    setHealth(health);
}

Player::~Player(){}

void Player::Update(float time)
{
    if(m_is_damage && m_damage_clock.getElapsedTime().asSeconds() > 0.05f)
    {
        m_sprite.setColor(sf::Color::White);
        m_is_damage = false;
    }
    
    m_state = State::IDLE;
    m_controller -> controllPlayer(this, time);
    m_sprite.setPosition(m_pos);
    updatePlayerTexture(time);
    setHealth(m_health);
    m_hpBar.setPosition(m_pos.x, m_pos.y - 10);
}

void Player::setState(State state)
{
    m_state = state;
}

void Player::updatePlayerTexture(float time)
{
    if (m_direction == Direction::UP && m_state == State::RUN)
    {
        m_frame += 0.001*time;
        if (m_frame > 4)
            m_frame -= 4;
        m_sprite.setTextureRect(sf::IntRect(40 * int(m_frame),0,40,40));
    }
    else if (m_direction == Direction::DOWN && m_state == State::RUN)
    {
        m_frame += 0.001*time;
        if (m_frame > 4)
            m_frame -= 4;
        m_sprite.setTextureRect(sf::IntRect(40 * int(m_frame),80,40,40));
    }
    else if (m_direction == Direction::LEFT && m_state == State::RUN)
    {
        m_frame += 0.001*time;
        if (m_frame > 4)
            m_frame -= 4;
        m_sprite.setTextureRect(sf::IntRect(40 * int(m_frame),40,40,40));
    }
    else if (m_direction == Direction::RIGHT && m_state == State::RUN)
    {
        m_frame += 0.001*time;
        if (m_frame > 5)
            m_frame -= 4;
        m_sprite.setTextureRect(sf::IntRect(40 * int(m_frame),120,40,40));
    }
}

void Player::setPlayerTexture(int xs, int ys, int x, int y)
{
    m_sprite.setTextureRect(sf::IntRect(xs,ys,x,y));
}

sf::View& Player::getPlayerCamera()
{
    return m_player_camera;
}