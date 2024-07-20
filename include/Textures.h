#pragma once
#include <SFML/Graphics.hpp>
#include <stdexcept>

namespace textures
{
    static sf::Texture player_texture;
    static sf::Texture background_texture;
    static sf::Texture background_menu_texture;       

    static void setBackMenuTextures()
    {
        if (!background_menu_texture.loadFromFile("../Assets/main_menu.png"))
            throw std::runtime_error("Ошибка загрузки ../Assets/main_menu.png");
    }
    
    static void setBackTextures()
    {
        if (!background_texture.loadFromFile("../Assets/grass.png"))
            throw std::runtime_error("Ошибка загрузки ../Assets/grass.png");
    }

    static void setTextures()
    {
        if (!player_texture.loadFromFile("../Assets/sprite2.png"))
            throw std::runtime_error("Ошибка загрузки ../Assets/sprite2.png"); 
    }

} 
