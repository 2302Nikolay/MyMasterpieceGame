#pragma once
#include "Engine/Character.h"
#include "./Enemy.h"

class PlayerController;

class Player : public Character
{
    private:
        PlayerController*   m_controller;
        sf::View           m_player_camera;
    public:
        Player() = delete;
        Player(sf::Texture& texture, sf::Vector2f start_pos, float health);
        ~Player();

        void Update(float time) override;

        void setState(State state);

        void updatePlayerTexture(float time);

        void setPlayerTexture(int xs, int ys, int x, int y);

        sf::View& getPlayerCamera();
};