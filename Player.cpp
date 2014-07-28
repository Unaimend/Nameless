#include "Player.h"

Player::Player(sf::Vector2f playerPosition)
{
    mPlayerPositionX = playerPosition.x;
    mPlayerPositionY = playerPosition.y;
    Sprites::PlayerSprite.setPosition(mPlayerPositionX, mPlayerPositionY);

};

void Player::render(sf::RenderWindow *window)
{
    window->draw(Sprites::PlayerSprite);
};