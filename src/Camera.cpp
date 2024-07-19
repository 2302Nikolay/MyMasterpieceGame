#include "../include/Camera.h"
#include "../include/Engine/Constants.h"

Camera::Camera(Player* player)
{
    m_player = player;
    m_camera = sf::View(sf::FloatRect(0.0f, 0.0f, WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
}

sf::View& Camera::getCamera()
{
    return m_camera;
}

void Camera::updateCamera()
{
    sf::Vector2f camera_center = m_player->getPosition();

    if (camera_center.x < WINDOW_WIDTH / 4)
        camera_center.x = WINDOW_WIDTH / 4;
    if (camera_center.x > 1280 - WINDOW_WIDTH / 4)
        camera_center.x = 1280 - WINDOW_WIDTH / 4;
    if (camera_center.y < WINDOW_HEIGHT / 4)
        camera_center.y = WINDOW_HEIGHT / 4;
    if (camera_center.y > 720 - WINDOW_HEIGHT / 4)
        camera_center.y = 720 - WINDOW_HEIGHT / 4;
    m_camera.setCenter(camera_center);
    m_camera.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
}