#pragma once
#include <SFML/Graphics.hpp>

namespace textures
{
    static sf::Texture player_texture;
    static sf::Texture background_texture;
    static sf::Texture background_menu_texture;       

    static void setBackMenuTextures()
    {
        if (!background_menu_texture.loadFromFile("../Assets/main_menu.png"))
            exit(1); // и тут...
    }
    
    static void setBackTextures()
    {
        if (!background_texture.loadFromFile("../Assets/grass.png"))
            exit(1);// тут добавить обработку исключений
    }

    static void setTextures()
    {
        if (!player_texture.loadFromFile("../Assets/sprite2.png"))
            exit(1);// и тут 
    }

} 
