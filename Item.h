#ifndef __Nameless__Item__
#define __Nameless__Item__

#include <iostream>
#include "SFML/Graphics.hpp"
class Item
{
public:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    double xPos = 0, yPos = 0;
    std::string mName = "";
    bool isClicked = false;
    
    virtual void render(sf::RenderWindow *window) ;
    virtual void update(double frametime)  ;
    

};

#endif /* defined(__Nameless__Item__) */
