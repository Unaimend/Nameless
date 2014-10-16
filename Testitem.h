//
//  Testitem.h
//  Nameless
//
//  Created by Thomas Dost on 29.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Testitem__
#define __Nameless__Testitem__

#include <iostream>
#include "Item.h"
class Testitem : public Item
{
public:
    
    Testitem();
    void render(sf::RenderWindow *window) override;
    void update(double frametime);
   
  
    
private:


};

#endif /* defined(__Nameless__Testitem__) */
