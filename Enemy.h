#ifndef __Nameless__Enemy__
#define __Nameless__Enemy__

#include <iostream>
#include "SFML/Graphics.hpp"
#include <string>
#include "NpcAnimation.h"
//#include "Player.h"

class Enemy
{
public:
  
    Enemy();
    virtual ~Enemy();
    virtual void render(sf::RenderWindow *window);
    virtual void update(double frametime);
    void setSprite(sf::Sprite sprite){mEnemySprite = sprite;};
    void setLife(int life){mLife = life;};
    void setName(std::string name){mName = name;};
    //void setPlayer(Player player){mPlayer = player;};
    void setxPos(int xpos){mXpos = xpos;};
    void setyPos(int ypos){mYpos = ypos;};
    int getLife(){return mLife; };
    virtual sf::Sprite getSprite(){return  pAnimation->getSprite();};
    virtual sf::FloatRect getFloatRect(){return pAnimation->getEnemyBoundingBoxes();};
    
protected:
    std::string mLifeString;
    sf::Text test2;
    std::string mName;
    sf::Sprite  mEnemySprite;
    sf::Font    mFont;
    NpcAnimation *pAnimation;
    int         mXpos;
    int         mYpos;
    int         mLife;
    int         mMaxLeft;
    int         mMaxRigth;
    int         mMaxUp;
    int         mMaxDown;
    float       mAggrotime;
    float       mAggroRange;
    sf::RectangleShape mHitBox;
};
#endif /* defined(__Nameless__Enemy__) */
