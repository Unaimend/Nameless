#include "Animation.h"

Animation::Animation(sf::Sprite Spritesheet, int SpriteHeigth, int SpriteWidth)
{
    mSpriteSheet    = Spritesheet;
    mSubRect.left   = 32;
    mSubRect.top    = 64;
    mSubRect.width  = SpriteWidth;
    mSubRect.height = SpriteHeigth;
    mSprintSpeed    = 100;
    
    mSpriteSheet.setTextureRect(mSubRect);
    mCurrentSprite.setPosition(0, 0);
};


void Animation::move(double frametime, int &Endurance)
{   mClock.getElapsedTime().asSeconds();
    mLastXPos = mSpriteSheet.getPosition().x;
    mLastYPos = mSpriteSheet.getPosition().y;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && mSpriteSheet.getPosition().y > -16)
    {
        mSpriteSheet.move(0,-50*frametime);
     
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && Endurance > 0)
        {
            mSpriteSheet.move(0,-mSprintSpeed*frametime);
        }
        mSubRect.left = 32;
        mSubRect.top = 0;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.35f)
        {
            mSubRect.left = 0;
            mSubRect.top = 0;
            mSpriteSheet.setTextureRect(mSubRect);
        }
        if (mClock.getElapsedTime().asSeconds() > 0.7f)
        {
            mSubRect.left = 32;
            mSubRect.top = 0;
            mSpriteSheet.setTextureRect(mSubRect);
           
        }
        if (mClock.getElapsedTime().asSeconds() > 1.05f)
        {
            mSubRect.left = 64;
            mSubRect.top = 0;
            mSpriteSheet.setTextureRect(mSubRect);
        }
        if (mClock.getElapsedTime().asSeconds() > 1.4)
        {
             mClock.restart();
        }
       
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        mSpriteSheet.move(0,50*frametime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && Endurance > 0)
        {
            mSpriteSheet.move(0,mSprintSpeed*frametime);
        }
        mSubRect.left = 32;
        mSubRect.top = 64;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.35f)
        {
           
            mSubRect.left = 0;
            mSubRect.top = 64;
            mSpriteSheet.setTextureRect(mSubRect);
        }
        if (mClock.getElapsedTime().asSeconds() > 0.7f)
        {
            mSubRect.left = 32;
            mSubRect.top = 64;
            mSpriteSheet.setTextureRect(mSubRect);
        }
        if (mClock.getElapsedTime().asSeconds() > 1.05f)
        {
            mSubRect.left = 64;
            mSubRect.top = 64;
            mSpriteSheet.setTextureRect(mSubRect);
        }
        if (mClock.getElapsedTime().asSeconds() > 1.4f)
        {
            mClock.restart();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && mSpriteSheet.getPosition().x > 8)
    {
        mSpriteSheet.move(-50*frametime, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)&& Endurance > 0)
        {
            mSpriteSheet.move(-mSprintSpeed*frametime, 0);
        }
        mSubRect.left = 32;
        mSubRect.top = 96;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.35f)
        {
            mSubRect.left = 0;
            mSubRect.top = 96;
            mSpriteSheet.setTextureRect(mSubRect);
        
        }
        if (mClock.getElapsedTime().asSeconds() > 0.7f)
        {
            mSubRect.left = 32;
            mSubRect.top = 96;
            mSpriteSheet.setTextureRect(mSubRect);
        }
        if (mClock.getElapsedTime().asSeconds() > 1.05f)
        {
            mSubRect.left = 64;
            mSubRect.top = 96;
            mSpriteSheet.setTextureRect(mSubRect);
        }
        if (mClock.getElapsedTime().asSeconds() > 1.4f)
        {
            mClock.restart();
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        mSpriteSheet.move(50*frametime, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && Endurance > 0)
        {
            mSpriteSheet.move(mSprintSpeed*frametime, 0);
        }
        mSubRect.left = 32;
        mSubRect.top = 32;
        mSpriteSheet.setTextureRect(mSubRect);
        if (mClock.getElapsedTime().asSeconds() > 0.35f)
        {
            mSubRect.left = 0;
            mSubRect.top = 32;
            mSpriteSheet.setTextureRect(mSubRect);
           
        }
        if (mClock.getElapsedTime().asSeconds() > 0.75f)
        {
            mSubRect.left = 32;
            mSubRect.top = 32;
            mSpriteSheet.setTextureRect(mSubRect);
           // mClock.restart();
        }
        if (mClock.getElapsedTime().asSeconds() > 1.05f)
        {
            mSubRect.left = 64;
            mSubRect.top = 32;
            mSpriteSheet.setTextureRect(mSubRect);
        
        }
        if (mClock.getElapsedTime().asSeconds() > 1.4f)
        {
            mClock.restart();
        }
    }
    
    mCurrentXPos = mSpriteSheet.getPosition().x;
    mCurrentYPos = mSpriteSheet.getPosition().y;
    if (mCurrentXPos > mLastXPos)
    {
        mIsGoingRight = true;
    }
    else
    {
        mIsGoingRight = false;
    }
    
    if (mCurrentXPos < mLastXPos)
    {
        mIsGoingLeft = true;
    }
    else
    {
        mIsGoingLeft = false;
    }
    
    if (mCurrentYPos < mLastYPos)
    {
        mIsGoingUp = true;
    }
    else
    {
        mIsGoingUp = false;
    }
    
    if (mCurrentYPos > mLastYPos)
    {
        mIsGoingDown = true;
    }
    else
    {
        mIsGoingDown = false;
    }
};

void Animation::render(sf::RenderWindow *window)
{
    window->draw(mSpriteSheet);
};

void sprint()
{


};