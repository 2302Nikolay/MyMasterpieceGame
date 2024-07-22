#include <SFML/Graphics.hpp>
#include <vector>

#include "../include/GUI/Minimap.h"
#include "../include/Enemy.h"
#include "../include/Player.h"
#include "../include/Camera.h"

MiniMap::MiniMap(const Player* player,
                const Camera& camera,
                const std::vector<Enemy*>& characters):
    m_characters(characters), m_camera(camera), m_player(player)
{
    m_map.setSize(sf::Vector2f(128,72));
    m_map.setFillColor(sf::Color(0,74,222,100));
    m_map.setOutlineThickness(2);
    m_map.setOutlineColor(sf::Color(51,102,0));
    
    m_characters_points = std::vector<sf::RectangleShape>(characters.size());

    initPoints();
}

MiniMap::~MiniMap()
{}

void MiniMap::setColor()
{
    for (size_t i{0}; i<m_characters_points.size(); ++i)
    {
        m_characters_points[i].setSize(sf::Vector2f(5.0f,5.0f));
        
        switch (m_characters[i]->getType())
        {
        case CharacterType::enemy       : m_characters_points[i].setFillColor(sf::Color::Red);
            break;
        case CharacterType::friendly    : m_characters_points[i].setFillColor(sf::Color::Green);
            break;
        case CharacterType::neutral     : m_characters_points[i].setFillColor(sf::Color::Yellow);
            break;
        default                         : m_characters_points[i].setFillColor(sf::Color(64,64,64));
            break;
        }
    }
}

void MiniMap::initPoints()
{    
    m_player_point.setFillColor(sf::Color::Green);
    m_player_point.setSize(sf::Vector2f(5.0f, 5.0f));
    setColor();
}

void MiniMap::updateMiniMap(sf::RenderWindow& window)
{
    setColor();
    m_map.setPosition(m_camera.getPosition().x + m_camera.getSize().x / 2 - m_map.getSize().x - 10,
                            m_camera.getPosition().y + m_camera.getSize().y / 2 - m_map.getSize().y - 10);
    m_player_point.setPosition(m_map.getPosition().x + m_player->getPosition().x/10, m_map.getPosition().y + m_player->getPosition().y/10);

    window.draw(m_map);
    for (size_t i{0}; i<m_characters_points.size(); ++i)
    {
        m_characters_points[i].setPosition(m_map.getPosition().x + m_characters[i]->getPosition().x / 10,
                                   m_map.getPosition().y + m_characters[i]->getPosition().y / 10);
        
        window.draw(m_characters_points[i]);
    }
    window.draw(m_player_point);
}