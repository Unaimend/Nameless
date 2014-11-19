
#include "NPC.h"
NPC::NPC( Player &player, sf::Sprite sprite, float xpos, float ypos, std::string text , std::string text2, std::string text3, std::string text4, std::string text5,std::string name, std::string welctext)
{
    
    mNPCtext    = text;
    mNpcText1   = text;
    mNpcText2   = text2;
    mNpcText3   = text3;
    mNpcText4   = text4;
    mNpcText5 = text5;
    mWelctText = welctext;
    mPlayer     = &player;
    mNpcPosX    = xpos;
    mNpcPosY    = ypos;
    mNpcSprite  = sprite;
    
    mNpcSprite.setPosition(mNpcPosX, mNpcPosY);
    mNpcSprite.setOrigin(mNpcSprite.getScale().x/2, mNpcSprite.getScale().y/2);
    
    NpcDialog = new DialogSystem(mNPCtext, mNpcSprite.getPosition().x, mNpcSprite.getPosition().y - 10,100);
};

void NPC::render(sf::RenderWindow *window)
{
    if (((mNpcSprite.getPosition().x - mPlayer->getPlayerSpritePosX() < 75 && mNpcSprite.getPosition().x - mPlayer->getPlayerSpritePosX() > -75) && ((mNpcSprite.getPosition().y - mPlayer->getPlayerSpritePosY() < 75) && mNpcSprite.getPosition().y - mPlayer->getPlayerSpritePosY() > -75)) && mShowDialog == true && mNPCtext != "0")
    {
        NpcDialog->render(window);
    }
    window->draw(mNpcSprite);
};

void NPC::nonfixrender(sf::RenderWindow *window)
{
    if (((mNpcSprite.getPosition().x - mPlayer->getPlayerSpritePosX() < 75 && mNpcSprite.getPosition().x - mPlayer->getPlayerSpritePosX() > -75) && ((mNpcSprite.getPosition().y - mPlayer->getPlayerSpritePosY() < 75) && mNpcSprite.getPosition().y - mPlayer->getPlayerSpritePosY() > -75)) && mShowAnswerBox == true)
    {
        NpcDialog->answerboxrender(window);
    }
    
};


void NPC::setEvent(sf::Event event)
{
    mEvent = event;
    
    if (mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E)
    {
        
        if (mShowDialog == true)
        {
            mShowDialog = false;
        }
        else
        {
            mShowDialog = true;
        }
        if (mShowAnswerBox == true)
        {
            mShowAnswerBox = false;
            mShowAnswerBox1 = false;
            mShowAnswerBox2 = false;
            mShowAnswerBox3 = false;
            mShowAnswerBox4 = false;
        }
        else
        {
            mShowAnswerBox = true;
            mShowAnswerBox1 = true;
            mShowAnswerBox2 = true;
            mShowAnswerBox3 = true;
            mShowAnswerBox4 = true;
        }
    }
    
    if (((mNpcSprite.getPosition().x - mPlayer->getPlayerSpritePosX() < 75 && mNpcSprite.getPosition().x - mPlayer->getPlayerSpritePosX() > -75) && ((mNpcSprite.getPosition().y - mPlayer->getPlayerSpritePosY() < 75) && mNpcSprite.getPosition().y - mPlayer->getPlayerSpritePosY() > -75)) && mShowDialog == true)
    {
        if (/*mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && mNPCtext == mNpcText1 &&*/ mNpcText1 != "0" && mSchonGetroffen == false)
        {
            NpcDialog->setText(mNpcText1);
            mSchonGetroffen = true;
            //mNPCtext = mNpcText2;
        }
        if (/*mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && mNPCtext == mNpcText2 &&*/ mNpcText2 != "0" && NpcDialog->getAnswer1() == true)
        {
            NpcDialog->setText(mNpcText2);
            mSchonGetroffen = true;
            mNPCtext = mNpcText3;
            if (mNpcText3 == "0")
            {
                mNPCtext = mNpcText1;
            }
        }
        if (/*mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && mNPCtext == mNpcText2 &&*/ mNpcText2 != "0" && NpcDialog->getAnswer2() == true)
        {
            NpcDialog->setText(mNpcText3);
            mSchonGetroffen = true;
            mNPCtext = mNpcText3;
            if (mNpcText3 == "0")
            {
                mNPCtext = mNpcText1;
            }
        }
        if (/*mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && mNPCtext == mNpcText2 &&*/ mNpcText2 != "0" && NpcDialog->getAnswer3() == true)
        {
            NpcDialog->setText(mNpcText4);
            mSchonGetroffen = true;
            mNPCtext = mNpcText4;
            if (mNpcText4 == "0")
            {
                mNPCtext = mNpcText1;
            }
        }
         if (/*mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && mNPCtext == mNpcText3 && */mNpcText3 != "0" && NpcDialog->getAnswer4() == true)
        {
            NpcDialog->setText(mNpcText5);
            mSchonGetroffen = true;
            mNPCtext = mNpcText1;
        }
    }
    
    if (mNpcSprite.getPosition().x - mPlayer->getPlayerSpritePosX() > 75 ||  mNpcSprite.getPosition().x - mPlayer->getPlayerSpritePosX() < -75 || mNpcSprite.getPosition().y - mPlayer->getPlayerSpritePosY() > 75 || mNpcSprite.getPosition().y - mPlayer->getPlayerSpritePosY() < -75)
    {
        mShowDialog = false;
        mShowAnswerBox = false;
        NpcDialog->setAnswer1(false);
        NpcDialog->setAnswer2(false);
        NpcDialog->setAnswer3(false);
        NpcDialog->setAnswer4(false);
        
        if (mSchonGetroffen == true) {
            NpcDialog->setText(mWelctText);
        }
    }
    
   };

void NPC::update(double frametime)
{
    NpcDialog->update();
//    
//    if (mNpcSprite.getPosition().y - 50 > mPlayer.getPlayerSpritePosY())
//    {
//      mNpcSprite.move(0, -150 * frametime);
//    }
//    if (mNpcSprite.getPosition().y + 50 < mPlayer.getPlayerSpritePosY() )
//    {
//        mNpcSprite.move(0, 150 * frametime);
//    }
//    if (mNpcSprite.getPosition().x + 50 < mPlayer.getPlayerSpritePosX() )
//    {
//        mNpcSprite.move(0, 150 * frametime);
//    }
    
};