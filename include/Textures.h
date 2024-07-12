#pragma once
#include <SFML/Graphics.hpp>

namespace textures
{
    static sf::Texture player_texture;
    static sf::Texture background_texture;        
    static sf::Image imgPlayer;

    static void setBackTextures()
    {
        background_texture.loadFromFile("../Assets/grass.png");
    }

    static void setTextures()
    {
        imgPlayer.loadFromFile("../Assets/sprite2.jpg");
        sf::Color color = imgPlayer.getPixel(0,0);
        imgPlayer.createMaskFromColor(color);
        player_texture.loadFromImage(imgPlayer);
    }
} 
