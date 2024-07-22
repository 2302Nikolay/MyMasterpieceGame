#pragma once

#include "./Player.h"

class Camera
{
    private:
        sf::View    m_camera;
        Player*     m_player;     
    public:
        Camera(Player* player);
        sf::View& getCamera();
        sf::Vector2f getPosition() const;
        sf::Vector2f getSize() const;

        void updateCamera();
};