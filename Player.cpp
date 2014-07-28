#include "Player.h"

Player::Player(sf::Vector2f playerPosition, double resX, double resY)
{
    mPlayerPositionX = playerPosition.x;
    mPlayerPositionY = playerPosition.y;
    mResX = resX;
    mResY = resY;
    Sprites::PlayerSprite.setPosition(mPlayerPositionX, mPlayerPositionY);
    mView.setSize(sf::Vector2f(mResX, mResY));
    mView.setViewport(sf::FloatRect(0.0f, 0, 1.0f, 1.0f));
    mView.zoom(0.5);
    mView.zoom(0.5);
    mFixed.setSize(sf::Vector2f(mResX, mResY));
    mView.setViewport(sf::FloatRect(0.0f, 0, 1.0f, 1.0f));
    Sprites::InventorySprite.setPosition(0, 0);
    Sprites::InventorySprite.setScale(3, 3);

};

Player::~Player(){};
void Player::render(sf::RenderWindow *window)
{
    window->setView(mView);
    window->draw(Sprites::PlayerSprite);
    window->setView(mFixed);
    if (mShowInventory == true)
         window->draw(Sprites::InventorySprite);
    window->setView(mView);
};

void Player::update(double frametime)
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        Sprites::PlayerSprite.move(-100*frametime, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
            Sprites::PlayerSprite.move(-200*frametime, 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        Sprites::PlayerSprite.move(100*frametime, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
            Sprites::PlayerSprite.move(200*frametime, 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        Sprites::PlayerSprite.move(0, -100*frametime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
            Sprites::PlayerSprite.move(0, -200*frametime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        Sprites::PlayerSprite.move(0, 100*frametime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
            Sprites::PlayerSprite.move(0, 200*frametime);
        }
    }
    mView.setCenter(sf::Vector2f(Sprites::PlayerSprite.getPosition().x, Sprites::PlayerSprite.getPosition().y));
    mFixed.setCenter(mResX/2, mResY/2  );
};

void Player::setEvent(sf::Event event)
{
    mEvent = event;
    if (mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
        if (mShowInventory == true) {
            mShowInventory = false;
        }
        else
        {
            mShowInventory = true;
        }
    }

};