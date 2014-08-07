#include "Player.h"

Player::Player(sf::Vector2f playerPosition, double resX, double resY)
{
    
    pPlayerAnimation = new Animation(*Sprites::pPlayerSprite, 32 ,32);
    
    mPlayerPositionX = playerPosition.x;
    mPlayerPositionY = playerPosition.y;
    mResX = resX;
    mResY = resY;
    Sprites::pPlayerSprite->setPosition(mPlayerPositionX, mPlayerPositionY);
    mView.setSize(sf::Vector2f(mResX, mResY));
    mView.setViewport(sf::FloatRect(0.0f, 0, 1.0f, 1.0f));
    mView.zoom(0.5);
    mView.zoom(0.5);
    mFixed.setSize(sf::Vector2f(mResX, mResY));
    mView.setViewport(sf::FloatRect(0.0f, 0, 1.0f, 1.0f));
    Sprites::InventorySprite.setPosition(300,500 );
    Sprites::InventorySprite.setScale(3, 3);
    
    mFont.loadFromFile("sansation.ttf");
    mEnduranceText.setFont(mFont);
    mEnduranceText.setCharacterSize(20);
    mEnduranceText.setPosition(20, 60);
    mEnduranceText.setColor(sf::Color::Green);
    
    mLifeText.setFont(mFont);
    mLifeText.setCharacterSize(20);
    mLifeText.setPosition(20,20);
    mLifeText.setColor(sf::Color::Red);
    
    mMagicaText.setPosition(20, 40);
    mMagicaText.setCharacterSize(20);
    mMagicaText.setColor(sf::Color::Blue);
    mMagicaText.setFont(mFont);
    
 
    
};

Player::~Player()
{
    
};
void Player::render(sf::RenderWindow *window)
{
    window->setView(mView);
    pPlayerAnimation->render(window);
    window->setView(mFixed);
    window->draw(mEnduranceText);
    window->draw(mLifeText);
    window->draw(mMagicaText);
    if (mShowInventory == true)
        window->draw(Sprites::InventorySprite);
    window->setView(mView);
};

void Player::update(double frametime)
{
    
    mEnduranceString = std::to_string(mEndurance);
    mEnduranceText.setString(mEnduranceString);
    mLifeString = std::to_string(mLife);
    mLifeText.setString(mLifeString);
    mMagicaString = std::to_string(mMagica);
    mMagicaText.setString(mMagicaString);
    mFrametime = frametime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) )
    {
        mIsStanding = false;
    }
    else
    {
        mIsStanding = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && mEndurance > 0)
    {
        
        if (mEnduranceCLock.getElapsedTime().asSeconds() > 1)
        {
            mEndurance =  mEndurance - 5;
            mEnduranceCLock.restart();
        }
    }
    if (mIsStanding) {
        mEnduranceCLock.getElapsedTime().asSeconds();
        if (mEnduranceCLock.getElapsedTime().asSeconds() > 1 && mEndurance < 100)
        {
            mEndurance =  mEndurance + 5;
                       mEnduranceCLock.restart();
        }
    }
    
  
    
    pPlayerAnimation->move(mFrametime, mEndurance);
  
    

    
    mView.setCenter(pPlayerAnimation->getSprite().getPosition().x, pPlayerAnimation->getSprite().getPosition().y);
    mFixed.setCenter(mResX/2, mResY/2  );
};

void Player::setEvent(sf::Event event)
{
    mEvent = event;
    if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::I) {
        if (mShowInventory == true) {
            mShowInventory = false;
        }
        else
        {
            mShowInventory = true;
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        
    }
};

