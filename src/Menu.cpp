#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <ranges>

#include "../include/GUI/Menu.h"
#include "../include/GUI/Fonts.h"


Menu::Menu(sf::RenderWindow& window, std::vector<std::string> element_names ,sf::Font& font) : m_window(window)
{
    m_font = font;
    m_menu_items = new std::vector<sf::Text>(element_names.size());
    float width = sf::VideoMode::getDesktopMode().width;
    float height = sf::VideoMode::getDesktopMode().height;

    for (size_t i = 0; i < m_menu_items->size(); ++i)
    {    
        m_name_menu_items.push_back(element_names[i]);
        (*m_menu_items)[i].setFont(m_font);
        if (i == 0)
            InitText((*m_menu_items)[i], width / 100, height / 100, m_name_menu_items[i], 150, sf::Color(237, 147, 0), 3);
        else
            InitText((*m_menu_items)[i], width/100, (height/3)+(height/3)/m_menu_items->size()*i, m_name_menu_items[i], 60);
    }
}

Menu::~Menu()
{
    delete m_menu_items;
}

void Menu::draw()
{
    for (auto& i : *m_menu_items | std::views::drop(1))
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
    m_window.draw((*m_menu_items)[0]);
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
    text.setFont(m_font);
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
        for (size_t i = 0; i < m_menu_items->size(); ++i)
        {
            if (isMouseOver((*m_menu_items)[i])) 
            {
                return static_cast<int>(i);
            }
        }
    }
    return -1;
}
