#ifndef __Nameless__Item__
#define __Nameless__Item__

#include <iostream>
#include "SFML/Graphics.hpp"
class Item
{
protected:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    double xPos, yPos;
    std::string mName;
    
    
    virtual void render(sf::RenderWindow *window) = 0 ;
    virtual void update(double frametime) = 0 ;
    

};

#endif /* defined(__Nameless__Item__) */
