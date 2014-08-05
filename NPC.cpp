
#include "NPC.h"
NPC::NPC( Player player, sf::Sprite sprite, float xpos, float ypos, std::string text, std::string text2, std::string text3, std::string name)
{
    
    mNPCtext  = text;
    mNpcText1 = text;
    mNpcText2 = text2;
    mNpcText3 = text3;
    mPlayer = player;
    mNpcPosX = xpos;
    mNpcPosY = ypos;
    mNpcSprite = sprite;
    
    mNpcSprite.setPosition(mNpcPosX, mNpcPosY);
    mNpcSprite.setOrigin(mNpcSprite.getScale().x/2, mNpcSprite.getScale().y/2);
    NpcDialog = new DialogSystem(mNPCtext, mNpcSprite.getPosition().x, mNpcSprite.getPosition().y - 10,100);
};

void NPC::render(sf::RenderWindow *window)
{   //std::cout << mNpc.getPosition().x - mPlayer.getPlayerSpritePosX()<< std::endl;
    //std::cout << mNpc.getPosition().y - mPlayer.getPlayerSpritePosY()<< std::endl;
    
    
    if (((mNpcSprite.getPosition().x - mPlayer.getPlayerSpritePosX() < 75 && mNpcSprite.getPosition().x - mPlayer.getPlayerSpritePosX() > -75) && ((mNpcSprite.getPosition().y - mPlayer.getPlayerSpritePosY() < 75) && mNpcSprite.getPosition().y - mPlayer.getPlayerSpritePosY() > -75)) && mShowDialog == true )  {
        NpcDialog->render(window);
    }
    
    window->draw(mNpcSprite);
};



void NPC::setEvent(sf::Event event)
{
    mEvent = event;
    if (mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
        if (mShowDialog == true) {
            mShowDialog = false;
        }
        else
        {
            mShowDialog = true;
        }
    }
    if (mNpcSprite.getPosition().x - mPlayer.getPlayerSpritePosX() > 75 ||  mNpcSprite.getPosition().x - mPlayer.getPlayerSpritePosX() < -75 || mNpcSprite.getPosition().y - mPlayer.getPlayerSpritePosY() > 75 || mNpcSprite.getPosition().y - mPlayer.getPlayerSpritePosY() < -75) {
        mShowDialog = false;
    }
    
    if (mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && mNPCtext == mNpcText1 && mNpcText1 != "0")
    {
        NpcDialog->setText(mNpcText1);
        mNPCtext = mNpcText2;
        
        
    }
    else if (mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && mNPCtext == mNpcText2 && mNpcText2 != "0")
    {
        NpcDialog->setText(mNpcText2);
        mNPCtext = mNpcText3;
        
        if (mNpcText3 == "0") {
            mNPCtext = mNpcText1;
        }
        
    }
    else if (mEvent.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && mNPCtext == mNpcText3 && mNpcText3 != "0")
    {
        NpcDialog->setText(mNpcText3);
        mNPCtext = mNpcText1;
        
    }
    
};

void NPC::update()
{
    NpcDialog->update();
};