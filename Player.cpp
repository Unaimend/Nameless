#include "Player.h"
#include "math.h"

Player::Player()
{
    pPlayerAnimation = new Animation(*Sprites::pPlayerSprite, 32 ,32);
    mMagica         = 100;
    mIsGoingDown    = pPlayerAnimation->getIsGoingDown();
    mIsGoingUp      = pPlayerAnimation->getIsGoingUp();
    mIsGoingLeft    = pPlayerAnimation->getIsGoingLeft();
    mIsGoingRight   = pPlayerAnimation->getIsGoingRight();
    
    Sprites::pPlayerSprite->setPosition(mPlayerPositionX, mPlayerPositionY);
    
    //mFont.loadFromFile("sansation.ttf");
    //mEnduranceText.setFont(mFont);
    mEnduranceText.setCharacterSize(20);
    mEnduranceText.setPosition(20, 60);
    mEnduranceText.setColor(sf::Color::Green);
    
   // mLifeText.setFont(mFont);
    mLifeText.setCharacterSize(20);
    mLifeText.setPosition(20,20);
    mLifeText.setColor(sf::Color::Red);
    
    mMagicaText.setPosition(20, 40);
    mMagicaText.setCharacterSize(20);
    mMagicaText.setColor(sf::Color::Blue);
    //mMagicaText.setFont(mFont);

    mMousRec.setOutlineColor(sf::Color::Black);
    mMousRec.setSize(sf::Vector2f(25,25));
    mInventory.setInventoryPos(sf::Vector2f(300,500));
    mMousRec.setOrigin(mMousRec.getSize().x/2,mMousRec.getSize().y/2);
    
    mTestShape.setPosition(pPlayerAnimation->getAnimationSpritePosX(), pPlayerAnimation->getAnimationSpritePosY());
    mTestShape.setSize(sf::Vector2f(5,5));
    mTestShape.setOrigin(5/2, 5/2);
    
};

Player::~Player()
{
    
};
void Player::render(sf::RenderWindow *window)
{
    mMousePos = sf::Mouse::getPosition(*window);
    mRealMousePos = window->mapPixelToCoords(mMousePos);
    mTarXDistance = mRealMousePos.x-pPlayerAnimation->getAnimationSpritePosX();
    
    mTarYDistance = mRealMousePos.y-pPlayerAnimation->getAnimationSpritePosY();
    mPlayTarDistance = sqrtf(mTarXDistance*mTarXDistance+mTarYDistance*mTarYDistance);
    
    mView.setSize(sf::Vector2f(mResX, mResY));
    mView.setViewport(sf::FloatRect(0.0f, 0, 1.0f, 1.0f));
    mView.zoom(0.25);
    mFixed.setSize(sf::Vector2f(mResX, mResY));
    window->setView(mView);
    pPlayerAnimation->render(window);
    window->draw(mTestShape);
    window->setView(mFixed);

    window->draw(mEnduranceText);
    window->draw(mLifeText);
    window->draw(mMagicaText);
    mInventory.render(window);
    window->setView(mView);
};

void Player::fixrender(sf::RenderWindow &window)
{
   
    
   
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        mShoot = true;
        mCalc = true;
    }
    if (mCalc) {
        mXmovement = mTarXDistance/mPlayTarDistance;
        mYmovement = mTarYDistance/mPlayTarDistance;
        
        mCalc = false;
    }
    
    
    
    if (mShoot == true) {
         mTestShape.move(mXmovement, mYmovement);
    }
    else
    {
        mTestShape.setPosition(pPlayerAnimation->getAnimationSpritePosX(), pPlayerAnimation->getAnimationSpritePosY());
    }
  
    window.draw(mMousRec);
};

void Player::update(double frametime)
{
    mEnduranceString    = std::to_string(mEndurance);
    mEnduranceText.setString(mEnduranceString);
    mLifeString         = std::to_string(mLife);
    mLifeText.setString(mLifeString);
    mMagicaString       = std::to_string(mMagica);
    mMagicaText.setString(mMagicaString);
    mInventory.update();
    mFrametime = frametime;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) )
    {
        mIsStanding = false;
    }
    else
    {
        mIsStanding = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && mEndurance > 0 && !mIsStanding )
    {
        if (mEnduranceCLock.getElapsedTime().asSeconds() > 0.2)
        {
            mEndurance =  mEndurance - 1;
            mEnduranceCLock.restart();
        }
    }
    if (mIsStanding) {
        mEnduranceCLock.getElapsedTime().asSeconds();
        if (mEnduranceCLock.getElapsedTime().asSeconds() > 0.2 && mEndurance < 100)
        {
            mEndurance =  mEndurance + 1;
                       mEnduranceCLock.restart();
        }
    }
    

    pPlayerAnimation->move(mFrametime, mEndurance);
    
    
    mIsGoingDown    = pPlayerAnimation->getIsGoingDown();
    mIsGoingUp      = pPlayerAnimation->getIsGoingUp();
    mIsGoingLeft    = pPlayerAnimation->getIsGoingLeft();
    mIsGoingRight   = pPlayerAnimation->getIsGoingRight();
    
    
    mView.setCenter(pPlayerAnimation->getSprite().getPosition().x, pPlayerAnimation->getSprite().getPosition().y);
    mFixed.setCenter(mResX/2, mResY/2  );
};

void Player::eventHandling(sf::Event event)
{
    mEvent = event;
    if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::I) {
        
        if (mShowInventory == true) {
            mInventory.setInvVisibility(false);
            mShowInventory = false;
        }
        else
        {
            mInventory.setInvVisibility(true);
            mShowInventory = true;
        }
    }
};

