#pragma once

#include <vector>

#include "./Engine/Character.h"
#include "./Player.h"

class Enemy : public Character
{
private:
    Player* m_target_player;
    int m_speed;
public:
    Enemy(sf::Texture& texture, sf::Vector2f start_pos, float health, Player* target_player);
    ~Enemy();
    void Update(float time);
    void setEnemyTexture(float time);
    void moveToPlayer(sf::Vector2f player_pos, float time);
    bool isPlayerInView(sf::Vector2f player_pos, float distance, float view_angle);
    void updateDirection(const sf::Vector2f& direction_to_player);
};