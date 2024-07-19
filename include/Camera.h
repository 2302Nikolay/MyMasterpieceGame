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

        void updateCamera();
};