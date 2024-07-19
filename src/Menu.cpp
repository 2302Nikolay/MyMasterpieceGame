#include <SFML/Graphics.hpp>
#include <string>

#include "../include/GUI/Menu.h"
#include "../include/GUI/Fonts.h"

Menu::Menu(sf::RenderWindow& window, sf::Font& font) : m_window(window)
{
    m_font = font;
    m_text_label.setFont(font);
    m_text_play.setFont(font);
    m_text_options.setFont(font);
    m_text_help.setFont(font);
    m_text_about.setFont(font);
    float width = sf::VideoMode::getDesktopMode().width;
    float height = sf::VideoMode::getDesktopMode().height;
    InitText(m_text_label, width/100, height/100, "Test", 150, sf::Color(237, 147, 0), 3);
    InitText(m_text_play, width/30, height/4, "Start", 60);
    InitText(m_text_options, width/30, (height/4)+(height/4)/4, "Options", 60);
    InitText(m_text_help, width/30, (height/4)+((height/4)/4)*2, "Help", 60);
    InitText(m_text_about, width/30, (height/4)+((height/4)/4)*3, "About Us", 60);
}

Menu::~Menu()
{}

void Menu::draw()
{
    // Обновление цветов текста в зависимости от позиции мыши
    if (isMouseOver(m_text_play)) 
    {
        m_text_play.setFillColor(sf::Color::Red);
    } 
    else 
    {
        m_text_play.setFillColor(sf::Color::White);
    }
    if (isMouseOver(m_text_options)) 
    {
        m_text_options.setFillColor(sf::Color::Red);
    } 
    else 
    {
        m_text_options.setFillColor(sf::Color::White);
    }
    if (isMouseOver(m_text_help)) 
    {
        m_text_help.setFillColor(sf::Color::Red);
    } 
    else 
    {
        m_text_help.setFillColor(sf::Color::White);
    }
    if (isMouseOver(m_text_about)) 
    {
        m_text_about.setFillColor(sf::Color::Red);
    } 
    else 
    {
        m_text_about.setFillColor(sf::Color::White);
    }

    m_window.draw(m_text_label);
    m_window.draw(m_text_play);
    m_window.draw(m_text_options);
    m_window.draw(m_text_help);
    m_window.draw(m_text_about);
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
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (isMouseOver(m_text_play)) 
        {
            return 0;
            std::cout << "Start Game" << std::endl;
        } 
        else if (isMouseOver(m_text_options)) 
        {
            return 1;
            std::cout << "Options" << std::endl;
        } 
        else if (isMouseOver(m_text_help)) 
        {
            return 2;
            std::cout << "Help" << std::endl;
        } 
        else if (isMouseOver(m_text_about)) 
        {
            return 3;
            std::cout << "About Us" << std::endl;
        }
    }
    return -1;
}