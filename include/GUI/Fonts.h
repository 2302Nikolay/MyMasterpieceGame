#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace fonts
{
    static sf::Font fontVideoType;

    static void loadFont()
    {
        if (!fontVideoType.loadFromFile("../Assets/fonts/videotype.otf"))
            std::cout << "loadFontError!!! << '\n"; // добавить исключение 
    }
}