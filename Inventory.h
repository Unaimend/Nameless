
#ifndef __Nameless__Inventory__
#define __Nameless__Inventory__

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Sprites.h"
class Inventory : Sprites
{
    
public:
    Inventory();
    sf::Vector2f getInventoryPos(){return mInventoryPosition;};
    void render(sf::RenderWindow *window);
    void update();
    void setInvVisibility(bool show){mShowInventory = show;};
    void setInventoryPos(sf::Vector2f position){mInventoryPosition.x = position.x; mInventoryPosition.y = position.y;};
    bool getInvVisibility(){return mShowInventory;};
    
private:
    bool mShowInventory = false;
    sf::Sprite          mInventorySprite;
    sf::Vector2f        mInventoryPosition;
  
};
#endif /* defined(__Nameless__Inventory__) */
