#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Menu
{	
public:
    sf::RenderWindow&           m_window;
    std::vector<sf::String>     m_name_menu_items;
    std::vector<sf::Text>*      m_menu_items;
    sf::Font                    m_font;
public:
    Menu(sf::RenderWindow& window, std::vector<std::string> element_names, sf::Font& font);
    ~Menu();
    void draw();
    void InitText(sf::Text& text, float xpos, float ypos, sf::String str, int size_font=150, 
    sf::Color menu_text_color = sf::Color::White, int bord = 0, sf::Color border_color = sf::Color::Black);
    bool isMouseOver(sf::Text& text);
    int handleMouseClick(sf::Event event);
};