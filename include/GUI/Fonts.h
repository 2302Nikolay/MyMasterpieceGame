#pragma once

#include <SFML/Graphics.hpp>
#include <exception>

namespace fonts
{
    static sf::Font fontVideoType;

    static void loadFont()
    {
        if (!fontVideoType.loadFromFile("../Assets/fonts/videotype.otf"))
            throw std::runtime_error("Ошибка загрузки шрифта ../Assets/fonts/videotype.otf");
    }
}