#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Player;
class Enemy;
class Camera;

class MiniMap
{
private:
    sf::RectangleShape                  m_map;
    sf::RectangleShape                  m_player_point;
    std::vector<sf::RectangleShape>     m_characters_points;
    const std::vector<Enemy*>&          m_characters;
    const Player*                       m_player;
    const Camera&                       m_camera;
public:
    MiniMap(const Player* player, const Camera& camera, const std::vector<Enemy*>& characters);
    ~MiniMap();

    void updateMiniMap(sf::RenderWindow& window);

private:
    void initPoints();
    void setColor();
};