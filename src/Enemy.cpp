#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "../include/Enemy.h"
#include "../include/Player.h"

Enemy::Enemy(sf::Texture& texture, sf::Vector2f start_pos, float health, Player* target_player)
{
    m_pos = start_pos;
    m_health = health;
    m_sprite.setTexture(texture);
    m_size = sf::Vector2f(40.0, 40.0);
    m_target_player = target_player;
    setEnemyTexture(40, 80, 40, 40);
}

Enemy::~Enemy(){}

void Enemy::setEnemyTexture(int xs, int ys, int x, int y)
{
    m_sprite.setTextureRect(sf::IntRect(xs,ys,x,y));
}

void Enemy::Update(float time)
{
    //setEnemyTexture(40, 80, 40, 40);
    moveToPlayer(m_target_player->getPosition(), time);
    m_sprite.setPosition(m_pos);
}

void Enemy::moveToPlayer(sf::Vector2f player_pos, float time)
{
    sf::Vector2f update_pos = this->getPosition();
    
    float distance = sqrt((player_pos.x - update_pos.x)*(player_pos.x - update_pos.x) + (player_pos.y - update_pos.y)*(player_pos.y - update_pos.y));//считаем дистанцию (длину от точки персонажа до точки игрока)
			
			if (distance > 2){//этим условием убираем дергание во время конечной позиции спрайта
 
				update_pos.x += 0.1*(time/5)*(player_pos.x - update_pos.x) / distance;//идем по иксу с помощью вектора нормал, time/5 здесь для того чтобы скорость была меньше скорости игрока
				update_pos.y += 0.1*(time/5)*(player_pos.y - update_pos.y) / distance;//идем по игреку так же
			}

    this->setPosition(update_pos);
}