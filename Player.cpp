#include "Player.h"

Player::Player(sf::Vector2f playerPosition)
{
    mPlayerPositionX = playerPosition.x;
    mPlayerPositionY = playerPosition.y;
    Sprites::PlayerSprite.setPosition(mPlayerPositionX, mPlayerPositionY);
    mView.setSize(sf::Vector2f(1200, 800));
    mView.setViewport(sf::FloatRect(0.0f, 0, 1.0f, 1.0f));

};

void Player::render(sf::RenderWindow *window)
{
    window->setView(mView);
    window->draw(Sprites::PlayerSprite);
};

void Player::update(double frametime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        Sprites::PlayerSprite.move(-100*frametime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        Sprites::PlayerSprite.move(100*frametime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        Sprites::PlayerSprite.move(0, -100*frametime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        Sprites::PlayerSprite.move(0, 100*frametime);
    }
    
    mView.setCenter(sf::Vector2f(Sprites::PlayerSprite.getPosition().x, Sprites::PlayerSprite.getPosition().y));
};