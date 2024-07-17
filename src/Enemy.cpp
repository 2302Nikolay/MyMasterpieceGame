#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <random>

#include "../include/Enemy.h"
#include "../include/Player.h"

Enemy::Enemy(sf::Texture& texture, sf::Vector2f start_pos, float health, Player* target_player)
{
    m_state = State::IDLE;
    m_direction = static_cast<Direction>(rand()%4);
    m_pos = start_pos;
    m_health = health;
    m_sprite.setTexture(texture);
    m_size = sf::Vector2f(40.0, 40.0);
    m_target_player = target_player;
    setEnemyTexture();
    m_speed = rand() % (15-5+1)+5;

    std::cout << static_cast<int>(m_direction) << '\n';
}

Enemy::~Enemy(){}

void Enemy::Update(float time)
{
    checkDistanceToPlayer(m_target_player->getPosition(), time);
    if (m_state == State::RUN)
        moveToPlayer(m_target_player->getPosition(), time);
    m_sprite.setPosition(m_pos);
    setEnemyTexture();
}

void Enemy::setEnemyTexture()
{
    if (m_direction == Direction::UP)
    {
        m_sprite.setTextureRect(sf::IntRect(40,0,40,40));
    }
    else if (m_direction == Direction::DOWN)
    {
        m_sprite.setTextureRect(sf::IntRect(40,80,40,40));
    }
    else if (m_direction == Direction::LEFT)
    {
        m_sprite.setTextureRect(sf::IntRect(40,40,40,40));
    }
    else if (m_direction == Direction::RIGHT)
    {   
        m_sprite.setTextureRect(sf::IntRect(40,120,40,40));
    }
    //m_sprite.setTextureRect(sf::IntRect(xs,ys,x,y));
}

void Enemy::moveToPlayer(sf::Vector2f player_pos, float time)
{
    sf::Vector2f update_pos = this->getPosition();
    
    float distance = sqrt((player_pos.x - update_pos.x)*(player_pos.x - update_pos.x) + (player_pos.y - update_pos.y)*(player_pos.y - update_pos.y));//считаем дистанцию (длину от точки персонажа до точки игрока)
			
            if (distance > 2){//этим условием убираем дергание во время конечной позиции спрайта
 
				update_pos.x += 0.1*(time/m_speed)*(player_pos.x - update_pos.x) / distance;//идем по иксу с помощью вектора нормал, time/5 здесь для того чтобы скорость была меньше скорости игрока
				update_pos.y += 0.1*(time/m_speed)*(player_pos.y - update_pos.y) / distance;//идем по игреку так же
            }

    this->setPosition(update_pos);
}

void Enemy::checkDistanceToPlayer(sf::Vector2f player_cord, float time)
{
    float dx = abs(player_cord.x - m_pos.x);
    float dy = abs(player_cord.y - m_pos.y);
    float absd = dx*dx+dy*dy;
    if (absd <= 5000)
    {
        m_state = State::RUN;
    }
    /* else // Эта часть кода нужна, если мы хотим, чтобы мобы переставали преследовать игрока после выхода из зоны видимости
    {
        m_state = State::IDLE;
    } */
}
