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

void Player::update(double frametime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        Sprites::PlayerSprite.move(-200*frametime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        Sprites::PlayerSprite.move(200*frametime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        Sprites::PlayerSprite.move(0, -200*frametime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        Sprites::PlayerSprite.move(0, 200*frametime);
    }

};