#include <cmath>
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
    sf::Vector2f movement(0.0f, 0.0f);
    State newState = State::IDLE;
    Direction newDirection = player->getDirection();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= PLAYER_SPEED * time;
        newDirection = Direction::LEFT;
        newState = State::RUN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += PLAYER_SPEED * time;
        newDirection = Direction::RIGHT;
        newState = State::RUN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= PLAYER_SPEED * time;
        newDirection = Direction::UP;
        newState = State::RUN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += PLAYER_SPEED * time;
        newDirection = Direction::DOWN;
        newState = State::RUN;
    }

    // Нормализация при движении по диагонали
    if (movement.x != 0.0f && movement.y != 0.0f) {
        float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
        movement /= length;
        movement *= PLAYER_SPEED * time;
    }

    updated_pos += movement;

    player->setPosition(updated_pos);
    player->setState(newState);
    player->setDirection(newDirection);
}