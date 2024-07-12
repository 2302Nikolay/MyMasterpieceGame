#include "../include/Engine/PlayerController.h"
#include "../include/Player.h"
#include "../include/Engine/Constants.h"
#include "../include/Textures.h"

PlayerController* PlayerController::controller = nullptr;

PlayerController::~PlayerController()
{
    delete controller;
}

PlayerController* PlayerController::getPlayerController()
{
    if (!controller) 
    {
        controller = new PlayerController();
    }

    return controller;
}

void PlayerController::controllPlayer(Player* player, float time) 
{
    sf::Vector2f updated_pos = player->getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        updated_pos.x -= PLAYER_SPEED * time;
        player->setState(State::RUN);
        player->setDirection(Direction::LEFT);
        
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        updated_pos.x += PLAYER_SPEED * time;
        player->setState(State::RUN);
        player->setDirection(Direction::RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        updated_pos.y -= PLAYER_SPEED * time;
        player->setState(State::RUN);
        player->setDirection(Direction::UP);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        updated_pos.y += PLAYER_SPEED * time;
        player->setState(State::RUN);
        player->setDirection(Direction::DOWN);
    }

    player->setPosition(updated_pos);
}