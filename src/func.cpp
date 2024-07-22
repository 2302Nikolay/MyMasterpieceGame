#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

#include "../include/Engine/Constants.h"
#include "../include/Textures.h"
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/Camera.h"
#include "../include/GUI/Fonts.h"
#include "../include/GUI/Menu.h"
#include "../include/GUI/Minimap.h"

int startGame()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Level 1.test");

    textures::setTextures();
    textures::setBackTextures();
    textures::setGoblinTexture();

    srand(static_cast<unsigned>(time(0)));

    Player* player = new Player(textures::player_texture, sf::Vector2f(PLAYER_START_X, PLAYER_START_Y), PLAYER_START_HP);
    Camera playerCamera = Camera(player);

    std::vector<Enemy*> enemyes;
    for (size_t i{0}; i<10; ++i)
    {
        float rx{static_cast<float>(rand())/(static_cast<float>(RAND_MAX/1200))};
        float ry{static_cast<float>(rand())/(static_cast<float>(RAND_MAX/700))};
        enemyes.push_back(new Enemy(textures::goblin_texture, sf::Vector2f(rx, ry), PLAYER_START_HP, player));
    }

    MiniMap* miniMap = new MiniMap(player,playerCamera, enemyes);

    sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1280, 720));
    background.setTexture(&textures::background_texture);
    background.setPosition(sf::Vector2f(0.0,0.0));
    
    sf::Clock clock;
    while (window.isOpen()) 
    {
        float time = clock.getElapsedTime().asMicroseconds(); 
        clock.restart();
        time /= 300;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();
        window.draw(background);
        window.draw(player->getSprite());
        
        for (auto en : enemyes)
        {
            en->Update(time);
            window.draw(en->getSprite());
            window.draw(en->getHpBar());
        }
        player->Update(time);
        playerCamera.updateCamera();
        window.draw(player->getHpBar());
        window.setView(playerCamera.getCamera());
        miniMap->updateMiniMap(window);

        window.display();
    }

    delete player;
    for (auto en : enemyes) // так работает???
    {
        delete en;
    }
    return 0;
}

int mainMenu()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "TheLast");

    textures::setBackMenuTextures();

    sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
    background.setTexture(&textures::background_menu_texture);
    background.setPosition(sf::Vector2f(0.0,0.0));

    fonts::loadFont();

    Menu menu = Menu(window, {"Test", "Start", "Options", "Help", "About As"}, fonts::fontVideoType);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
            int handl = menu.handleMouseClick(event);
            switch (handl)
            {
            case 1 : 
            {
                window.close();
                startGame();
            };
                break;
            case 2 : std::cout << "options";
            default:
                break;
            }
        }

        window.draw(background);
        menu.draw();
        window.display();
    }

    return 0;
}