#pragma once
#include <SFML/Graphics.hpp>

namespace textures
{
    static sf::Texture player_texture;
    static sf::Texture background_texture;        

    static void setBackTextures()
    {
        background_texture.loadFromFile("../Assets/grass.png");
    }

    static void setTextures()
    {
        player_texture.loadFromFile("../Assets/sprite2.png");
    }
} 
