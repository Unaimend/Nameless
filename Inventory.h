
#ifndef __Nameless__Inventory__
#define __Nameless__Inventory__

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Sprites.h"
class Inventory : Sprites
{
    
public:
    Inventory();
    void render(sf::RenderWindow *window);
    void update();

    
    void setInvVisibility(bool show){mShowInventory = show;};
    bool getInvVisibility(){return mShowInventory;};
    
    
    void setInventoryPos(sf::Vector2f position){mInventoryPosition.x = position.x; mInventoryPosition.y = position.y;};
    sf::Vector2f getInventoryPos(){return mInventoryPosition;};
    
private:
    bool mShowInventory = false;
    sf::Sprite mInventorySprite;
    sf::Vector2f mInventoryPosition;
  
};
#endif /* defined(__Nameless__Inventory__) */
