#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "include/Engine/Constants.h"
#include "include/Textures.h"
#include "include/Player.h"
#include "include/Enemy.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "GGAME");

    textures::setTextures();
    textures::setBackTextures();

    srand(static_cast<unsigned>(time(0)));

    Player* player = new Player(textures::player_texture, sf::Vector2f(PLAYER_START_X, PLAYER_START_Y), PLAYER_START_HP);
    std::vector<Enemy*> enemyes;

    for (int i{0}; i<10; ++i)
    {
        const float rx{static_cast<float>(rand())/(static_cast<float>(RAND_MAX/1200))};
        const float ry{static_cast<float>(rand())/(static_cast<float>(RAND_MAX/700))};
        enemyes.push_back(new Enemy(textures::player_texture, sf::Vector2f(rx, ry), PLAYER_START_HP, player));
    }


    sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1280, 720));
    background.setTexture(&textures::background_texture);
    background.setPosition(sf::Vector2f(0.0,0.0));
    
    sf::Clock clock;
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds(); 
        clock.restart();
        time /= 300;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.draw(background);
        window.draw(player->getSprite());
        for (auto en : enemyes)
        {
            en->Update(time);
            window.draw(en->getSprite());
            window.draw(en->getHpBar());
        }
        player->checkColision(enemyes);
        player->Update(time);
        window.draw(player->getHpBar());

        window.display();
    }

    delete player;
    for (auto en : enemyes) // так работает???
    {
        delete en;
    }
    return 0;
}