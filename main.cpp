#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "include/Engine/Constants.h"
#include "include/Textures.h"
#include "include/Player.h"
#include "include/Enemy.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Title");

    textures::setTextures();
    textures::setBackTextures();

    srand(static_cast<unsigned>(time(0)));

    Player* player = new Player(textures::player_texture, sf::Vector2f(PLAYER_START_X, PLAYER_START_Y), PLAYER_START_HP);
    Enemy* enemy = new Enemy(textures::player_texture, sf::Vector2f(2.0, 3.0), PLAYER_START_HP, player);


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

        player->Update(time);
        enemy->Update(time);

        //window.clear(sf::Color::White);

        window.draw(background);
        window.draw(player->getSprite());
        window.draw(enemy->getSprite());

        window.display();
    }

    delete player;
    delete enemy;
    return 0;
}