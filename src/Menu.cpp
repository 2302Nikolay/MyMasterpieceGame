#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <ranges>

#include "../include/GUI/Menu.h"
#include "../include/GUI/Fonts.h"

Menu::Menu(sf::RenderWindow& window, sf::Font& font) : m_window(window)
{
    m_font = font;
    sf::Text text_label;
    sf::Text text_play;
    sf::Text text_options;
    sf::Text text_help;
    sf::Text text_about;
    float width = sf::VideoMode::getDesktopMode().width;
    float height = sf::VideoMode::getDesktopMode().height;
    InitText(text_label, width/100, height/100, "Test", 150, sf::Color(237, 147, 0), 3);
    InitText(text_play, width/30, height/4, "Start", 60);
    InitText(text_options, width/30, (height/4)+(height/4)/4, "Options", 60);
    InitText(text_help, width/30, (height/4)+((height/4)/4)*2, "Help", 60);
    InitText(text_about, width/30, (height/4)+((height/4)/4)*3, "About Us", 60);

    m_menu_items.push_back(text_label);
    m_menu_items.push_back(text_play);
    m_menu_items.push_back(text_options);
    m_menu_items.push_back(text_help);
    m_menu_items.push_back(text_about);

    for (auto& i : m_menu_items)
    {
        i.setFont(m_font);
    }
}

Menu::~Menu()
{}

void Menu::draw()
{
    for (auto& i : m_menu_items | std::views::drop(1))
    {
        if (isMouseOver(i))
        {
            i.setFillColor(sf::Color::Red);
        }
        else
        {
            i.setFillColor(sf::Color::White);
        }
        m_window.draw(i);
    }
    m_window.draw(m_menu_items[0]);
}

void Menu::InitText(sf::Text& text,
                    float xpos, 
                    float ypos, 
                    sf::String str, 
                    int size_font, 
                    sf::Color menu_text_color, 
                    int bord, 
                    sf::Color border_color)
{
    text.setCharacterSize(size_font);
    text.setPosition(xpos, ypos);
    text.setString(str);
    text.setFillColor(menu_text_color);
    text.setOutlineThickness(bord);
    text.setOutlineColor(border_color);
}

bool Menu::isMouseOver(sf::Text& text) 
{
    sf::FloatRect textBounds = text.getGlobalBounds();
    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

    return textBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

int Menu::handleMouseClick(sf::Event event) 
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
    {   
        for (size_t i = 0; i < m_menu_items.size(); ++i)
        {
            if (isMouseOver(m_menu_items[i])) 
            {
                return static_cast<int>(i);
            }
        }
    }
    return -1;
}