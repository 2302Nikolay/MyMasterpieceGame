#pragma once
#include <vector>
#include "./Engine/Character.h"
#include "./Player.h"

class Enemy : public Character
{
private:
    Player* m_target_player;
public:
    Enemy(sf::Texture& texture, sf::Vector2f start_pos, float health, Player* target_player);
    ~Enemy();
    void Update(float time);
    void setEnemyTexture(int xs, int ys, int x, int y);
    void moveToPlayer(sf::Vector2f player_pos, float time);    
    //void moveToPlayer(sf::Vector2f& player_position);
};
