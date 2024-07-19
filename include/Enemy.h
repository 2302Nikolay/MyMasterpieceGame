#pragma once

#include <vector>

#include "./Engine/Character.h"

class Player;

class Enemy : public Character
{
private:
    Player* m_target_player;
    int     m_speed;
    int     m_distance_view = 100;
public:
    Enemy(sf::Texture& texture, sf::Vector2f start_pos, float health, Player* target_player);
    ~Enemy();
    void Update(float time) override;
    void setEnemyTexture(float time);
    void moveToPlayer(sf::Vector2f player_pos, float time);
    bool isPlayerInView(sf::Vector2f player_pos, float distance, float view_angle);
    void updateDirection(const sf::Vector2f& direction_to_player);
    void checkColision(Player* player);
};