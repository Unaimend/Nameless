#include "Item.h"


void Item::render(sf::RenderWindow *window)
{
    window->draw(mSprite);
    //std::cout << "FALSCHE RENDERFUNKTION" << std::endl;
};

void Item::update(double frametime)
{
    //std::cout << "FALSCHE UPDATE" << std::endl;
    
};