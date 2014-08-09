//
//  MagicSystem.h
//  Nameless
//
//  Created by Thomas Dost on 09.08.14.
//  Copyright (c) 2014 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__MagicSystem__
#define __Nameless__MagicSystem__

#include <iostream>
#include "Player.h"
#include "Enemy.h"
class MagicSystem
{
public:
    MagicSystem(Player &player);
    ~MagicSystem();
    void render();
    void update();
    void cast();
protected:
private:
    Player *pPlayer;
    

};
#endif /* defined(__Nameless__MagicSystem__) */
