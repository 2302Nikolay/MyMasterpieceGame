#pragma once
#include "Engine/Character.h"

class PlayerController;

enum class State
{
    IDLE,
    RUN
};

class Player : public Character
{
    private:
        State               m_state;
        PlayerController*   m_controller;
        float               m_frame;
        //static sf::Clock m_clockFrame;
        //static float m_time;

    public:
        Player() = delete;
        Player(sf::Texture& texture, sf::Vector2f start_pos, float health);
        ~Player();

        void Update(float time) override;

        void setState(State state);

        void updatePlayerTexture(float time);

        void setPlayerTexture(int xs, int ys, int x, int y);
};